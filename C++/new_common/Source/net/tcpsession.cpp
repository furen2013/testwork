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
	
}

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


void tcp_session::_Read_Other()
{
	_uncompress_message();
	_read_next_message();
}



void tcp_session::_uncompress_message()
{
	unsigned short& datalen = *(unsigned short*)m_recv_buffer;
	datalen = 2 + ssl_decrypt( &m_recv_crypt_key, (unsigned char*)(m_recv_buffer + 2), datalen - 2, (unsigned char*)(m_recv_buffer + 2) );
	unsigned short type = *(unsigned short*)( m_recv_buffer + 2 );
	unsigned int checksum = 0;
	std::swap( *(unsigned int*)( m_recv_buffer + m_message_basic_head_len ), checksum );

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
		unsigned int size = MAX_MESSAGE_LEN * 2 - m_message_head_len;
		if( net_global::get_compress_strategy()->uncompress( buffptr, &size,
												m_recv_buffer + m_message_head_len, datalen - m_message_head_len ) )
		{
			message_t* msg = net_global::get_message( size + m_message_head_len );
			msg->from = this;
			memcpy( msg->data + m_message_head_len, buffptr, size );
			memcpy( msg->data, m_recv_buffer, m_message_head_len );
			*(unsigned short*)( msg->data + 2 ) &= ~COMPRESS_MASK;
			*(unsigned short*)msg->data = size + m_message_head_len;
			push_message( msg );

			//printf( "uncompress message, before:%u, now:%u\n", datalen, size + m_message_head_len );
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

void tcp_session::_async_read(unsigned short datalen)
{
	boost::asio::async_read( *m_socket,
		boost::asio::buffer( m_recv_buffer + m_message_head_len, datalen - m_message_head_len ),
		boost::bind( &tcp_basesession::handle_read_body, this,
		boost::asio::placeholders::error ) );
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
											&size, (const char*)data + m_message_head_len, len - m_message_head_len ) )
		{
			if( size + m_message_head_len < len )
			{
				message_t* p = net_global::get_message( size + m_message_head_len + 1 );
				p->from = this;
				memcpy( p->data + m_message_head_len, buffptr, size );
				memcpy( p->data, data, m_message_head_len );
				*(unsigned short*)( p->data + 2 ) |= COMPRESS_MASK;
				*(unsigned short*)p->data = size + m_message_head_len;
				*(unsigned int*)(p->data + m_message_basic_head_len) = 0;
				*(unsigned int*)(p->data + m_message_basic_head_len) = m_dsv.make_checksum( p->data, size + m_message_head_len );
#ifdef NET_FLOW_RATE_LOG
				m_compress_size += ( len - m_message_head_len ) - size;
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
	*(unsigned int*)(p->data + m_message_basic_head_len) = 0;
	*(unsigned int*)(p->data + m_message_basic_head_len) = m_dsv.make_checksum( p->data, len );
	*(unsigned short*)p->data = 2 + ssl_encrypt( &m_send_crypt_key, (unsigned char*)(p->data + 2), len - 2, (unsigned char*)(p->data + 2) );
	return p;
}

