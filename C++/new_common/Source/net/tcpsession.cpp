#include "tcpsession.h"
#include "tcpserver.h"
#include "../utilities/task_thread_pool.h"
#include "../ssl/crypt.h"

struct compress_send_task : public task
{
	compress_send_task( const void* src, unsigned short l, tcp_session* s, int ti ) : len( l ), session( s ), thread_index( ti )
	{
		data = (char*)malloc( len );
		memcpy( data, src, len );
	}
	virtual void execute()
	{
		if( session->is_valid() )
			result = session->_compress_message( data, len, get_thread_index() );
	}

	virtual void end()
	{
		if( session->is_valid() && session->is_connected() )
			session->_send_message( result );
	}

	~compress_send_task()
	{
		free( data );
	}

	virtual int get_thread_index()
	{
		return thread_index;
	}

private:
	char* data;
	unsigned short len;
	message_t* result;
	tcp_session* session;
	int thread_index;
};

#ifdef _WIN32
typedef mt_buffer_mgr<8, MAX_MESSAGE_LEN> session_message_buffer_manager_t;
#else
typedef mt_buffer_mgr<2000, MAX_MESSAGE_LEN> session_message_buffer_manager_t;
#endif

typedef session_message_buffer_manager_t::buffer_type* compress_message_buffer_ptr_t;
session_message_buffer_manager_t* s_session_message_buffer_mgr = NULL;

struct optimized_compress_send_task : public task
{
	optimized_compress_send_task( const void* src, unsigned short l, tcp_session* s, int ti ) : len( l ), session( s ), thread_index( ti )
	{
		m_cmb_ptr = s_session_message_buffer_mgr->get_free_buffer();
		while( !m_cmb_ptr )
		{
			cpu_wait();
			m_cmb_ptr = s_session_message_buffer_mgr->get_free_buffer();
		}
		data = m_cmb_ptr->get_buff();
		memcpy( data, src, len );
	}
	virtual void execute()
	{
		if( session->is_valid() && session->is_connected() )
			result = session->_compress_message( data, len, get_thread_index() );
		m_cmb_ptr->release();
		m_cmb_ptr = NULL;
	}

	virtual void end()
	{
		if( session->is_valid() && session->is_connected() )
			session->_send_message( result );
	}

	~optimized_compress_send_task()
	{
		if( m_cmb_ptr )
			m_cmb_ptr->release();
	}

	virtual int get_thread_index()
	{
		return thread_index;
	}

private:
	compress_message_buffer_ptr_t m_cmb_ptr;
	char* data;
	unsigned short len;
	message_t* result;
	tcp_session* session;
	int thread_index;
};

//namespace net_global
//{
void net_global::init_memory_for_speed()
{
	if( !s_session_message_buffer_mgr )
		s_session_message_buffer_mgr = new session_message_buffer_manager_t;
}
void net_global::free_memory_for_speed()
{
	safe_delete( s_session_message_buffer_mgr );
}
//}

static const unsigned short COMPRESS_MASK = 1 << 15;

//static char s_compress_buffer[MAX_MESSAGE_LEN * 2];

typedef mt_buffer_mgr<20, MAX_MESSAGE_LEN> compression_buffer_manager_t;
typedef mt_auto_ptr<compression_buffer_manager_t::buffer_type*> compression_buffer_ptr_t;
compression_buffer_manager_t s_compression_buffer_mgr;


tcp_session::tcp_session( boost::asio::io_service& is ) :tcp_basesession(is)
{
#ifdef NET_FLOW_RATE_LOG
	m_compress_size = 0;
#endif


	m_message_basic_head_len = 12;
	m_message_head_len = 8;
	m_queue_message_limit_size = MAX_MESSAGE_LEN * 10;
	
}

tcp_session::~tcp_session()
{
	//_clear_send_msg();
}
//
//bool tcp_session::is_valid()
//{
//	return interlocked_read( &m_isvalid ) != 0;
//}
//
//void tcp_session::set_valid( bool b )
//{
//	interlocked_write( &m_isvalid, b ? 1 : 0 );
//}
//
//void tcp_session::on_accept( tcp_server* p )
//{
//	p->increase_connection_count();
//	m_isconnected = true;
//	m_last_action_time = (unsigned int)time( NULL );
//	m_father = p;
//	m_dsv.reset();
//	m_send_crypt_key = rand() % 255 + 1;
//	m_recv_crypt_key = m_send_crypt_key;
//	send_message( &m_send_crypt_key, 1 );
//	_read_next_message();
//	m_thread_index = p->generate_thread_index();
//
//	m_remote_ip_str = get_remote_address_string();
//	m_remote_ip_ui = get_remote_address_ui();
//	_record_action();
//}

//std::string tcp_session::get_remote_address_string() const
//{
//	if( m_remote_ip_str.length() )
//		return m_remote_ip_str;
//
//	try
//	{
//		return m_socket->remote_endpoint().address().to_string();
//	}
//	catch( ... )
//	{
//		return "";
//	}
//}
//
//unsigned int tcp_session::get_remote_address_ui() const
//{
//	if( m_remote_ip_ui )
//		return m_remote_ip_ui;
//
//	try
//	{
//		return m_socket->remote_endpoint().address().to_v4().to_ulong();
//	}
//	catch( ... )
//	{
//		return 0;
//	}
//}
//
//unsigned short tcp_session::get_remote_port() const
//{
//	try
//	{
//		return m_socket->remote_endpoint().port();
//	}
//	catch( ... )
//	{
//		return 0;
//	}
//}
//
//long tcp_session::get_not_sent_size()
//{
//	long n = 0;
//	{
//		boost::mutex::scoped_lock lock( m_mutex );
//		n = m_not_sent_size;
//	}
//	return n;
//}

void tcp_session::send_message( const void* data, unsigned short len )
{
	if( !is_valid() || !m_isconnected || !data || !len || len > MAX_MESSAGE_LEN - 1 || m_send_crypt_key == 0 )
		return;

	if( m_father )
	{
		int ti = 0;
		if( m_father->is_thread_task_transfer_id_mode() )
		{
			unsigned int transferid = *(unsigned int*)( (const char*)data + 4 );
			ti = transferid % m_father->get_task_thread_count();
		}
		else
			ti = get_thread_index();

		task* t = NULL;
		if( net_global::is_need_max_speed() )
			t = new optimized_compress_send_task( data, len, this, ti );
		else
			t = new compress_send_task( data, len, this, ti );
		m_father->push_task( t );
	}
	else
	{
		boost::mutex::scoped_lock lock( m_dsv.get_mutex() );
		_send_message( _compress_message( data, len, -1 ) );
	}
}
//
//void tcp_session::close()
//{
//	m_socket->close();
//	m_send_crypt_key = 0;
//	m_recv_crypt_key = 0;
//	m_close_time = 0;
//	m_close_time_if_no_data = 0;
//	m_recv_size = 0;
//	m_send_size = 0;
//	m_isconnected = false;
//	m_thread_index = 0;
//}

//void tcp_session::delay_close( unsigned int t )
//{
//	m_close_time = (unsigned int)time( NULL ) + t;
//}
//
//void tcp_session::delay_close_if_no_data( unsigned int t )
//{
//	m_close_time_if_no_data = (unsigned int)time( NULL ) + t;
//}
//
//void tcp_session::run()
//{
//	{
//		boost::mutex::scoped_lock lock( m_mutex );
//		_write_message();
//	}
//	if( m_isneedcat )
//		_check_action_time();
//	if( m_close_time )
//	{
//		if( (unsigned int)time( NULL ) >= m_close_time )
//		{
//			m_close_time = 0;
//			this->close();
//			net_global::write_close_log( "IP:[%s] delay close", this->get_remote_address_string().c_str() );
//		}
//	}
//	if( m_close_time_if_no_data )
//	{
//		if( m_father && (unsigned int)time( NULL ) >= m_close_time_if_no_data )
//		{
//			m_close_time_if_no_data = 0;
//			if( m_recv_size < 12 )
//			{
//				{
//					boost::mutex::scoped_lock lock( m_father->m_proc_mutex );
//					std::map<unsigned int, unsigned int>::iterator it = m_father->m_idleip.find( this->get_remote_address_ui() );
//					if( it != m_father->m_idleip.end() )
//					{
//						if( ++it->second > 50 )
//						{
//							m_father->m_idleip.erase( it );
//							m_father->add_ban_ip( this->get_remote_address_ui(), 3600, net_global::BAN_REASON_TOO_MANY_IDLE_CONNECTION );
//						}
//					}
//					else
//						m_father->m_idleip[this->get_remote_address_ui()] = 1;
//				}
//				this->close();
//				net_global::write_close_log( "IP:[%s] close if no data recv size = %d", this->get_remote_address_string().c_str(), m_recv_size );
//			}
//		}
//	}
//}

//call_back_mgr* tcp_session::_get_cb_mgr()
//{
//	if( m_father )
//		return m_father->get_cb_mgr();
//	else
//	{
//		//assert( 0 );
//		return NULL;
//	}
//}

//void tcp_session::_send_message( message_t* msg )
//{
//	boost::mutex::scoped_lock lock( m_mutex );
//	if( !is_connected() )
//		return;
//	m_not_sent_size += msg->len;
//	if( m_father && m_father->is_limit_mode() )
//	{
//		if( m_not_sent_size >= QUEUE_MESSAGE_LIMIT_SIZE )
//		{
//			//printf("error: not send size > QUEUE_MESSAGE_LIMIT_SIZE close socket\n");
//			close();
//			net_global::write_close_log( "IP:[%s] close, message queue is full", this->get_remote_address_string().c_str() );
//			return;
//		}
//	}
//	m_queue_send_msg.push_back( msg );
//}

void tcp_session::_read_next_message()
{
	boost::asio::async_read( *m_socket,
		boost::asio::buffer( m_recv_buffer, MESSAGE_HEAD_LEN ),
		boost::bind( &tcp_session::handle_read_header, this,
		boost::asio::placeholders::error ) );
}

void tcp_session::_uncompress_message()
{
	unsigned short& datalen = *(unsigned short*)m_recv_buffer;
	datalen = 2 + ssl_decrypt( &m_recv_crypt_key, (unsigned char*)(m_recv_buffer + 2), datalen - 2, (unsigned char*)(m_recv_buffer + 2) );
	unsigned short type = *(unsigned short*)( m_recv_buffer + 2 );
	unsigned int checksum = 0;
	std::swap( *(unsigned int*)( m_recv_buffer + MESSAGE_BASIC_HEAD_LEN ), checksum );

	if( !m_dsv.verify_data_stream( m_recv_buffer, datalen, checksum ) )
	{
		if( m_father )
		{
			m_father->add_ban_ip( this->get_remote_address_ui(), 120, net_global::BAN_REASON_WRONG_CHECK_SUM );
			printf( "IP:[%s] try to hack server. Ban it for 120 seconds.\n", get_remote_address_string().c_str() );
		}

		this->close();
		net_global::write_close_log( "IP:[%s] close, check sum error", this->get_remote_address_string().c_str() );
		return;
	}

	if( ( type & COMPRESS_MASK ) &&
		( m_iscompress || m_uncommpress_type.end() != m_uncommpress_type.find( type & ~COMPRESS_MASK ) ) )
	{
		compression_buffer_ptr_t ptr = s_compression_buffer_mgr.get_free_buffer();
		char* buffptr = ptr->get_buff();
		unsigned int size = MAX_MESSAGE_LEN * 2 - MESSAGE_HEAD_LEN;
		if( net_global::get_compress_strategy()->uncompress( buffptr, &size,
												m_recv_buffer + MESSAGE_HEAD_LEN, datalen - MESSAGE_HEAD_LEN ) )
		{
			message_t* msg = net_global::get_message( size + MESSAGE_HEAD_LEN );
			msg->from = this;
			memcpy( msg->data + MESSAGE_HEAD_LEN, buffptr, size );
			memcpy( msg->data, m_recv_buffer, MESSAGE_HEAD_LEN );
			*(unsigned short*)( msg->data + 2 ) &= ~COMPRESS_MASK;
			*(unsigned short*)msg->data = size + MESSAGE_HEAD_LEN;
			push_message( msg );

			//printf( "uncompress message, before:%u, now:%u\n", datalen, size + MESSAGE_HEAD_LEN );
			return;
		}
		else
			;//assert( 0 && "uncompress message failed" );
			//printf("uncompress message failed close socket\n");
	}
	else
	{
		message_t* msg = net_global::get_message( datalen );
		msg->from = this;
		memcpy( msg->data, m_recv_buffer, datalen );
		push_message( msg );
		return;
	}
	if( m_father )
	{
		m_father->add_ban_ip( this->get_remote_address_ui(), 120, net_global::BAN_REASON_UNCOMPRESS_FAIL );
		printf( "IP:[%s] try to hack server. Ban it for 120 seconds.\n", get_remote_address_string().c_str() );
	}
	this->close();
	net_global::write_close_log( "IP:[%s] uncompress message failed", this->get_remote_address_string().c_str() );
}

message_t* tcp_session::_compress_message( const void* data, unsigned short len, int t_idx )
{
	if( m_iscompress && len >= 128 && net_global::get_compress_strategy() )
	{
		//assert( !( *(unsigned short*)( (const char*)data + 2 ) & COMPRESS_MASK ) );

		unsigned int size = MAX_MESSAGE_LEN * 2;
		char* buffptr = NULL;
		compression_buffer_ptr_t ptr( NULL );
		if( m_father && t_idx >= 0 )
		{
			if( m_father->is_thread_task_transfer_id_mode() )
				buffptr = m_father->get_thread_buffer( t_idx );
			else
				buffptr = m_father->get_thread_buffer( m_thread_index );
		}
		else
		{
			ptr = s_compression_buffer_mgr.get_free_buffer();
			buffptr = ptr->get_buff();
		}
		if( net_global::get_compress_strategy()->compress( buffptr,
											&size, (const char*)data + MESSAGE_HEAD_LEN, len - MESSAGE_HEAD_LEN ) )
		{
			if( size + MESSAGE_HEAD_LEN < len )
			{
				message_t* p = net_global::get_message( size + MESSAGE_HEAD_LEN + 1 );
				p->from = this;
				memcpy( p->data + MESSAGE_HEAD_LEN, buffptr, size );
				memcpy( p->data, data, MESSAGE_HEAD_LEN );
				*(unsigned short*)( p->data + 2 ) |= COMPRESS_MASK;
				*(unsigned short*)p->data = size + MESSAGE_HEAD_LEN;
				*(unsigned int*)(p->data + MESSAGE_BASIC_HEAD_LEN) = 0;
				*(unsigned int*)(p->data + MESSAGE_BASIC_HEAD_LEN) = m_dsv.make_checksum( p->data, size + MESSAGE_HEAD_LEN );
#ifdef NET_FLOW_RATE_LOG
				m_compress_size += ( len - MESSAGE_HEAD_LEN ) - size;
#endif
				*(unsigned short*)p->data = 2 + ssl_encrypt( &m_send_crypt_key, (unsigned char*)(p->data + 2), p->len - 3, (unsigned char*)(p->data + 2) );
				return p;
			}
		}
	}
	if( len == 1 )
	{
		message_t* p = net_global::get_message( 1 );
		memcpy( p->data, data, 1 );
		return p;
	}
	message_t* p = net_global::get_message( len + 1 );
	p->from = this;
	memcpy( p->data, data, len );
	*(unsigned int*)(p->data + MESSAGE_BASIC_HEAD_LEN) = 0;
	*(unsigned int*)(p->data + MESSAGE_BASIC_HEAD_LEN) = m_dsv.make_checksum( p->data, len );
	*(unsigned short*)p->data = 2 + ssl_encrypt( &m_send_crypt_key, (unsigned char*)(p->data + 2), len - 2, (unsigned char*)(p->data + 2) );
	return p;
}
//
//void tcp_session::_check_action_time()
//{
//	if( !is_connected() )
//		return;
//
//	unsigned int now = 0;
//	if( m_father )
//		now = m_father->get_unix_time();
//	else
//		now = (unsigned int)time( NULL );
//	if( m_last_action_time > 0 && now - m_last_action_time >= 3 * 60 )
//	{
//		this->close();
//		m_last_action_time = 0;
//
//		net_global::write_close_log( "IP:[%s] not any action for 180 seconds", this->get_remote_address_string().c_str() );
//	}
//}
//
//void tcp_session::_record_action()
//{
//	if( !is_connected() )
//		return;
//	if( m_father )
//		m_last_action_time = m_father->get_unix_time();
//	else
//		m_last_action_time = (unsigned int)time( NULL );
//}
//
//void tcp_session::_clear_send_msg()
//{
//	while( !m_queue_send_msg.empty() )
//	{
//		net_global::free_message( m_queue_send_msg.front() );
//		m_queue_send_msg.pop_front();
//	}
//}
//
//void tcp_session::_on_close( const boost::system::error_code& error )
//{
//	boost::mutex::scoped_lock lock( m_mutex );
//	m_send_crypt_key = 0;
//	m_recv_crypt_key = 0;
//	_clear_send_msg();
//	if( is_valid() && !m_isclosing && _get_cb_mgr() )
//	{
//		m_isclosing = true;
//		_get_cb_mgr()->add_cb( &tcp_session::on_close, this, error );
//	}
//}

void tcp_session::_write_message()
{
	// optimize for sending-data frequently
	if( m_is_sending_data )
		return;

	if( m_queue_send_msg.empty() )
		return;
	int len = 0;

	while( !m_queue_send_msg.empty() )
	{
		message_t* msg = m_queue_send_msg.front();
		if( len + msg->len <= MAX_MESSAGE_LEN )
		{
			memcpy( m_sending_data + len, msg->data, msg->len );
			len += msg->len;
			m_queue_send_msg.pop_front();
			net_global::free_message( msg );
		}
		else
			break;
	}
	boost::asio::async_write( *m_socket,
		boost::asio::buffer( m_sending_data,
		len ),
		boost::bind( &tcp_session::handle_write, this,
		boost::asio::placeholders::error, len, 0 ) );
	
	m_is_sending_data = true;
}

void tcp_session::handle_read_header( const boost::system::error_code& error )
{
	if( !is_valid() )
		return;

	if( !error )
	{
		_record_action();

		unsigned short datalen = *(unsigned short*)m_recv_buffer;
		m_recv_size += datalen;

		if( datalen > MESSAGE_HEAD_LEN )
		{
			//assert( datalen <= MAX_MESSAGE_LEN );
			boost::asio::async_read( *m_socket,
				boost::asio::buffer( m_recv_buffer + MESSAGE_HEAD_LEN, datalen - MESSAGE_HEAD_LEN ),
				boost::bind( &tcp_session::handle_read_body, this,
				boost::asio::placeholders::error ) );
		}
		else if( datalen == MESSAGE_HEAD_LEN )
		{
			_uncompress_message();
			_read_next_message();
		}
		else
		{
			//printf( "datalen < 12, close socket\n" );
			if( m_father )
			{
				m_father->add_ban_ip( this->get_remote_address_ui(), 120, net_global::BAN_REASON_HACK_PACKET );
				printf( "IP:[%s] try to hack server. Ban it for 120 seconds.\n", get_remote_address_string().c_str() );
			}
			this->close();
			net_global::write_close_log( "IP:[%s] message length is not valid", this->get_remote_address_string().c_str() );
		}
	}
	else
		_on_close( error );
}

void tcp_session::handle_read_body( const boost::system::error_code& error )
{
	if( !is_valid() )
		return;

	if( !error )
	{
		_record_action();

		_uncompress_message();
		_read_next_message();
	}
	else
		_on_close( error );
}

void tcp_session::handle_write( const boost::system::error_code& error, int size, int block_idx )
{
	if( !is_valid() )
		return;

	if( !error )
	{
		{
			boost::mutex::scoped_lock lock( m_mutex );
			m_is_sending_data = false;
			m_not_sent_size -= size;
			_write_message();
		}

#ifdef NET_FLOW_RATE_LOG
		m_send_size += size;
#endif
		_record_action();
	}
	else
		_on_close( error );
}

//void tcp_session::on_close( const boost::system::error_code& error )
//{
//	{
//		boost::mutex::scoped_lock lock( m_mutex );
//		m_isclosing = false;
//		try
//		{
//			m_socket->close();
//		}
//		catch( ... )
//		{
//		}
//		m_isconnected = false;
//	}
//
//	if( m_father )
//	{
//		m_father->decrease_connection_count();
//		m_father->remove_session( this );
//	}
//}
//
//void tcp_session::push_message( message_t* msg )
//{
//	if( m_father )
//		m_father->push_message( msg );
//}
//
//void tcp_session::reset()
//{
//	boost::mutex::scoped_lock lock( m_mutex );
//	m_isconnected = false;
//	m_father = NULL;
//	m_last_action_time = 0;
//	m_close_time = 0;
//	m_close_time_if_no_data = 0;
//	m_isvalid = false;
//	m_thread_index = 0;
//	m_is_sending_data = false;
//	m_isclosing = false;
//	m_remote_ip_str.clear();
//	m_remote_ip_ui = 0;
//
//	m_not_sent_size = 0;
//	m_send_crypt_key = 0;
//	m_recv_crypt_key = 0;
//
//	m_send_size = 0;
//	m_recv_size = 0;
//#ifdef NET_FLOW_RATE_LOG
//	m_compress_size = 0;
//#endif
//
//	_clear_send_msg();
//	if( m_socket )
//		delete m_socket;
//	m_socket = new tcp::socket( m_io_service );
//
//	m_dsv.reset();
//}
//
