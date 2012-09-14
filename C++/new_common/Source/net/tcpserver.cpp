#include "tcpserver.h"
#include "tcpsession.h"
#include "../utilities/task_thread_pool.h"
#include "../ssl/crypt.h"

class message_pool
{
public:
	struct msg : public message_t
	{
		volatile boost::uint32_t is_using;
		bool is_dynamic;

		inline bool acquire()
		{
			if( is_using == 0 )
			{
				is_using = 1;
				return true;
			}
			else
				return false;
		}
		inline bool release( boost::mutex& m )
		{
			if( is_dynamic )
			{
				free( data );
				is_dynamic = false;
				m.lock();
				return true;
			}
			else
			{
				m.lock();
				is_using = 0;
				return false;
			}
		}
	};

	message_pool( int ps ) : pool_size( ps ), spool_size( ps * 10 )
	{
		m_used[0] = 0;
		m_used[1] = 0;
		m_used[2] = 0;
		m_spool = new msg[spool_size];
		m_lpool = new msg[pool_size];
		m_data = (char*)malloc( 1024 * spool_size + MAX_MESSAGE_LEN * pool_size );
		assert( m_data );

		for( int i = 0; i < spool_size; ++i )
		{
			m_spool[i].data = m_data + 1024 * i;
			m_spool[i].is_using = 0;
			m_spool[i].is_dynamic = false;
		}
		for( int i = 0; i < pool_size; ++i )
		{
			m_lpool[i].data = m_data + 1024 * spool_size + MAX_MESSAGE_LEN * i;
			m_lpool[i].is_using = 0;
			m_lpool[i].is_dynamic = false;
		}
	}
	~message_pool()
	{
		free( m_data );
		delete[] m_spool;
		delete[] m_lpool;
	}

	message_t* get( unsigned short size )
	{
		msg* ptr = NULL;
		int count = 0;
		bool empty = true;
		{
			boost::mutex::scoped_lock lock( m_mutex );
			if( size <= 1024 )
			{
				ptr = m_spool;
				count = spool_size;
				if( m_used[0] < spool_size )
					empty = false;
			}
			else
			{
				ptr = m_lpool;
				count = pool_size;
				if( m_used[1] < pool_size )
					empty = false;
			}

			if( !empty )
			{
				for( int i = 0; i < count; ++i )
				{
					if( ptr[i].acquire() )
					{
						ptr[i].len = size;
						++m_used[size > 1024 ? 1 : 0];
						return &ptr[i];
					}
				}
			}
		}
		ptr = new msg;
		ptr->is_using = 1;
		ptr->is_dynamic = true;
		ptr->data = (char*)malloc( size );
		ptr->len = size;
		boost::mutex::scoped_lock lock( m_mutex );
		++m_used[2];
		return ptr;
	}
	void release( message_t* p )
	{
		int is_long = p->len > 1024;
		if( static_cast<msg*>( p )->release( m_mutex ) )
			--m_used[2];
		else
			--m_used[is_long];
		m_mutex.unlock();
	}

	boost::uint32_t get_used()
	{
		boost::mutex::scoped_lock lock( m_mutex );
		boost::uint32_t n = m_used[0] + m_used[1] + m_used[2];
		return n;
	}

private:
	msg* m_spool;
	msg* m_lpool;
	char* m_data;
	int pool_size;
	int spool_size;
	int m_used[3];
	boost::mutex m_mutex;
};

static boost::asio::io_service* s_io_service = NULL;
static compress_strategy* s_compress_strategy = NULL;
static bool s_is_need_max_speed = false;
static message_pool* s_msg_pool = NULL;

compress_strategy* net_global::get_compress_strategy()
{
	return s_compress_strategy;
}

bool net_global::is_need_max_speed()
{
	return s_is_need_max_speed;
}

boost::asio::io_service* net_global::get_io_service()
{
	if( !s_io_service )
		s_io_service = new boost::asio::io_service;
	return s_io_service;
}


static std::set<net_global::net_obj*> s_set_objects;
static boost::thread* s_net_service_thread[64] = { NULL };
class asio_run_timer;
static net_global::asio_run_timer* s_asio_run_timer = NULL;
static boost::mutex s_obj_mutex;
static volatile boost::uint32_t s_asio_thread_count = 0;

void net_global::add_net_obj( net_obj* obj )
{
	boost::mutex::scoped_lock lock( s_obj_mutex );
	s_set_objects.insert( obj );
}

void net_global::del_net_obj( net_obj* obj )
{
	boost::mutex::scoped_lock lock( s_obj_mutex );
	s_set_objects.erase( obj );
}

class net_run_timer : public net_global::asio_run_timer
{
public:
	net_run_timer( boost::asio::io_service& io, int interval ) : asio_run_timer( io, interval )
	{
	}

	virtual void v_call()
	{
		boost::mutex::scoped_lock lock( s_obj_mutex );
		std::for_each( s_set_objects.begin(), s_set_objects.end(), boost::bind( &net_global::net_obj::thread_run_asio, _1 ) );
	}
};

void io_service_run()
{
	interlocked_increment( &s_asio_thread_count );
	s_io_service->run();
	interlocked_decrement( &s_asio_thread_count );
}

void net_global::set_compress_strategy( compress_strategy* imp )
{
	s_compress_strategy = imp;
}

void net_global::init_net_service( int thread_count, int proc_interval, compress_strategy* cs_imp, bool need_max_speed, int msg_pool_size )
{
	ssl_init_dictionary();

	s_asio_run_timer = new net_run_timer( *get_io_service(), proc_interval );
	s_compress_strategy = cs_imp;
	s_is_need_max_speed = need_max_speed;
	if( need_max_speed )
		init_memory_for_speed();

	for( int i = 0; i < thread_count; ++i )
		s_net_service_thread[i] = new boost::thread( &io_service_run );

	s_msg_pool = new message_pool( msg_pool_size );
}

message_t* net_global::get_message( unsigned short size )
{
	if( s_msg_pool )
		return s_msg_pool->get( size );
	else
	{
		message_t* p = new message_t;
		p->data = (char*)malloc( size );
		p->from = NULL;
		p->len = size;
		return p;
	}
}

void net_global::free_message( message_t* p )
{
	if( s_msg_pool )
		s_msg_pool->release( p );
	else
	{
		free( p->data );
		delete p;
	}
}

boost::uint32_t net_global::get_message_pool_used()
{
	if( s_msg_pool )
		return s_msg_pool->get_used();
	else
		return 0;
}

static bool net_service_stoped = false;

void net_global::stop_net_service()
{
	if( s_asio_run_timer )
	{
		s_asio_run_timer->stop();
		s_io_service->stop();
		for( int i = 0; i < 64; ++i )
			if( s_net_service_thread[i] )
			{
				s_net_service_thread[i]->join();
				delete s_net_service_thread[i];
				s_net_service_thread[i] = NULL;
			}
	}
	net_service_stoped = true;
}

void net_global::free_net_service()
{
	if( !net_service_stoped )
		stop_net_service();
	if( s_asio_run_timer )
	{
		delete s_asio_run_timer;
		s_asio_run_timer = NULL;
		delete s_io_service;
		s_io_service = NULL;
	}
	if( s_is_need_max_speed )
		free_memory_for_speed();
	s_is_need_max_speed = false;
	if( s_msg_pool )
	{
		delete s_msg_pool;
		s_msg_pool = NULL;
	}
}

long net_global::get_asio_thread_alive_count()
{
	return s_asio_thread_count;
}

void net_global::write_close_log( const char* txt, ... )
{
#ifndef _WIN32
	FILE* fp = fopen( "close_reason.log", "a" );
	if( fp )
	{
		va_list ap;
		char buffer[4096];
		va_start(ap, txt);
		vsnprintf(buffer, 4096, txt, ap);
		va_end(ap);

		unsigned int t = (unsigned int)time( NULL );
		int y, m, d, h, min, s;
		convert_unix_time( t, &y, &m, &d, &h, &min, &s );
		fprintf( fp, "[%d-%d-%d %d:%d:%d] %s\n", y, m, d, h, min, s, buffer );
		fclose( fp );
	}
#endif
}

//} // end of namespace net_global

tcp_server::tcp_server( int id )
	: m_id( id ), m_acceptor( NULL ), m_sessionpool( NULL ), m_poolcount( 0 ), m_thread_buffer( NULL ), m_thread_count( 0 ), m_cur_thread_index( 0 ),
	m_ttti_mode( false ), m_accepting_count( 0 ), m_limit_mode( false ), m_connection_count( 0 ), m_fp_log( NULL ), m_fp_connection_log( NULL ), m_security( true )
{
#ifdef NET_FLOW_RATE_LOG
	m_fp_log = NULL;
	m_total_send_size = 0;
	m_total_recv_size = 0;
	m_total_compress_size = 0;
#endif
	m_ttp = new task_thread_pool;
	net_global::add_net_obj( this );
	m_unix_time = (unsigned int)time( NULL );
	m_last_calculate_time = m_unix_time;
	m_last_log_connection_time = m_unix_time;
	m_last_clean_idle_ip_time = m_unix_time;
}

tcp_server::~tcp_server()
{

}

bool tcp_server::create( unsigned short port, unsigned int poolcount, int thread_count )
{
	tcp::endpoint ep( tcp::v4(), port );
	if( m_acceptor )
	{
		delete m_acceptor;
		m_acceptor = NULL;
	}
	try
	{
		m_acceptor = new tcp::acceptor( *net_global::get_io_service() );//, ep, false );
		m_acceptor->open( ep.protocol() );

		boost::asio::socket_base::reuse_address option( true );
		boost::asio::socket_base::linger optiontemp;
		boost::asio::socket_base::linger option2( true, 0 );
		m_acceptor->get_option( optiontemp );
		printf("before: linger timeout value[%d]", optiontemp.timeout());
		m_acceptor->set_option( option2 );
		m_acceptor->get_option( optiontemp );
		printf("after:  linger timeout value[%d]", optiontemp.timeout());

		m_acceptor->set_option( option );
		m_acceptor->set_option( option2 );
		m_acceptor->bind( ep );
#ifdef _WIN32
		m_acceptor->listen( 128 );
#else
		m_acceptor->listen( 1024 );
#endif
	}
	catch( boost::system::system_error& e )
	{
		// error code == 10048, connot listen the same port at a time.
		return false;
	}

	m_ttp->startup( thread_count );
	if( m_thread_buffer )
		delete[] m_thread_buffer;
	m_thread_buffer = new char[THREAD_BUFFER_SIZE * thread_count];
	m_thread_count = thread_count;

	if( poolcount == 0 )
		poolcount = 20;

	m_sessionpool = new tcp_basesession*[poolcount];
	for( unsigned int i = 0; i < poolcount; ++i )
	{
		m_sessionpool[i] = create_session();
		//assert( m_sessionpool[i] );
	}

	//if( MyLog::log )
	//	MyLog::log->info("服务器连接限制[%d]", poolcount);

	boost::mutex::scoped_lock lock( m_proc_mutex );
	m_poolcount = poolcount;
	return true;
}

void tcp_server::handle_accept( tcp_basesession* p, const boost::system::error_code& error )
{
	{
		boost::mutex::scoped_lock lock( m_proc_mutex );
		--m_accepting_count;
	}
	if( is_ban_ip( p->get_remote_address_ui() ) )
	{
		printf( "banned ip [%s] connection detected, closing...\n", p->get_remote_address_string().c_str() );
		p->close();
		p->reset();
		remove_session( p );
		return;
	}

	if( !error )
	{
		//printf( "accept a client\n" );
		p->m_recv_size = 0;
		m_cb_mgr.add_cb( &tcp_session::on_accept, p, this );
	}
	else
	{
		printf( "accept error:%s\n", error.message().c_str() );
		remove_session( p );
	}
}

void tcp_server::_add_session( tcp_basesession* p )
{
	boost::mutex::scoped_lock lock( m_proc_mutex );
	m_sessions.insert( p );
	p->set_valid( true );
}

void tcp_server::remove_session( tcp_basesession* p )
{
	boost::mutex::scoped_lock lock( m_proc_mutex );
	//assert( m_sessions.find( p ) != m_sessions.end() );
	m_sessions.erase( p );
	p->set_valid( false );
}

void tcp_server::push_message( message_t* msg )
{
	boost::mutex::scoped_lock lock( m_msg_mutex );
	m_queue_recv_msg.push( msg );
	m_msg_cond.notify_one();
}

tcp_basesession* tcp_server::get_free_session()
{
	if( m_poolcount == 0 )
		return NULL;
	for( unsigned int i = 0; i < m_poolcount; ++i )
		if( m_sessionpool[i] && !m_sessionpool[i]->is_valid() )
		{
			m_sessionpool[i]->reset();
			m_sessionpool[i]->set_valid( true );
			return m_sessionpool[i];
		}
	return NULL;
}

void tcp_server::push_task( task* p )
{
	m_ttp->push_task( p );
}

char* tcp_server::get_thread_buffer( int index )
{
	return m_thread_buffer + index * THREAD_BUFFER_SIZE;
}

int tcp_server::generate_thread_index()
{
	int i = m_cur_thread_index;
	if( ++m_cur_thread_index >= m_thread_count )
		m_cur_thread_index = 0;
	return i;
}

void tcp_server::increase_connection_count()
{
	boost::mutex::scoped_lock lock( m_proc_mutex );
	++m_connection_count;
}

void tcp_server::decrease_connection_count()
{
	boost::mutex::scoped_lock lock( m_proc_mutex );
	--m_connection_count;
}

bool tcp_server::is_ban_ip( unsigned int addr )
{
	boost::mutex::scoped_lock lock( m_ban_mutex );
	return m_banip.end() != m_banip.find( addr );
}

void tcp_server::add_ban_ip( unsigned int addr, unsigned int sec, net_global::ban_reason_t br )
{
	char fn[64] = { 0 };
	sprintf( fn, "connection%d.log", m_id );
	m_fp_connection_log = fopen( fn, "a" );
	if( m_fp_connection_log )
	{
		time_t tnow = m_unix_time;
		tm* ptm = localtime( &tnow );
		in_addr ad;
		ad.s_addr = addr;
		char* ip = inet_ntoa( ad );

		fprintf( m_fp_connection_log, "%04d-%02d-%02d %02d:%02d:%02d|Banned IP:[%s], reason:%d\n",
			ptm->tm_year+1900, ptm->tm_mon + 1, ptm->tm_mday, ptm->tm_hour, ptm->tm_min, ptm->tm_sec,
			ip, br );

		fclose( m_fp_connection_log );
	}

	boost::mutex::scoped_lock lock( m_ban_mutex );
	std::map<unsigned int, std::pair<unsigned int, net_global::ban_reason_t> >::iterator it =  m_banip.find( addr );
	if( it != m_banip.end() )
	{
		if( it->second.first < sec )
		{
			it->second.first = sec;
			it->second.second = br;
		}
	}
	else
		m_banip[addr] = std::make_pair( m_unix_time + sec, br );
}

void tcp_server::add_ban_ip( const std::string& addr, unsigned int sec, net_global::ban_reason_t br )
{
	unsigned int iaddr = boost::asio::ip::address_v4::from_string( addr ).to_ulong();
	add_ban_ip( iaddr, sec, br );
}

void tcp_server::remove_ban_ip( unsigned int addr )
{
	boost::mutex::scoped_lock lock( m_ban_mutex );
	m_banip.erase( addr );
}

void tcp_server::run()
{
	_real_run( true );
}

void tcp_server::run_no_wait()
{
	_real_run( false );
}

void tcp_server::thread_run_asio()
{
	//m_ttp->proc_waiting_tasks();

	unsigned int now = m_unix_time;
#ifdef NET_FLOW_RATE_LOG
	unsigned int rs = 0;
	unsigned int ss = 0;
	unsigned int cc = 0;
	unsigned int sending_size = 0;
	int cs = 0;
	bool bcheck = false;
	if( m_last_calculate_time == 0 )
		m_last_calculate_time = now;
	else if( now - m_last_calculate_time >= 20 )
	{
		bcheck = true;
		m_last_calculate_time = now;
	}
#endif

	int tempsize = 0;
	int connection_size = 0;
	{
		boost::mutex::scoped_lock lock( m_proc_mutex );
		tempsize = m_sessions.size();
		connection_size = m_connection_count;
		std::copy( m_sessions.begin(), m_sessions.end(), m_tempsession );
	}
	for( int i = 0; i < tempsize; ++i )
	{
		tcp_basesession* p = m_tempsession[i];
		if( p && p->is_valid() )
		{
			p->run();
#ifdef NET_FLOW_RATE_LOG
			if( bcheck )
			{
				rs += p->m_recv_size;
				ss += p->m_send_size;
				cs += p->m_compress_size;
				sending_size += p->get_not_sent_size();
				p->m_recv_size = 0;
				p->m_send_size = 0;
				p->m_compress_size = 0;
			}
#endif
		}

	}
#ifdef NET_FLOW_RATE_LOG
	if( bcheck )
	{
		m_total_recv_size += rs;
		m_total_send_size += ss;
		m_total_compress_size += cs;
		time_t tnow = now;
		tm* ptm = localtime( &tnow );
		float fr = (float)rs / 1024.f;
		float fs = (float)ss / 1024.f;
		float rps = fr / 20.f;
		float sps = fs / 20.f;
		char temp[32];
		sprintf( temp, "net_flow_rate_%d.log", m_id );
		m_fp_log = fopen( temp, "a" );
		if( m_fp_log )
		{
			fprintf( m_fp_log, "%04d-%02d-%02d %02d:%02d:%02d|recv:%.2fKB(%.2fKB/S) send:%.2fKB(%.2fKB/S) t_recv:%.2fKB t_send:%.2fKB t_comp:%.2fKB conn:%u acc_q:%d send_q:%d msg_pool_used:%d\n",
					ptm->tm_year+1900, ptm->tm_mon + 1, ptm->tm_mday, ptm->tm_hour, ptm->tm_min, ptm->tm_sec,
					fr, rps, fs, sps, (double)m_total_recv_size / 1024.0, (double)m_total_send_size / 1024.0,
					(double)m_total_compress_size / 1024.0, connection_size, m_accepting_count, sending_size, net_global::get_message_pool_used() );
			fclose( m_fp_log );
			m_fp_log = NULL;
		}
	}
#endif
	_prepare_for_next_accept();

	boost::mutex::scoped_lock lock( m_ban_mutex );
	for( std::map<unsigned int, std::pair<unsigned int, net_global::ban_reason_t> >::iterator it = m_banip.begin(); it != m_banip.end(); )
	{
		std::map<unsigned int, std::pair<unsigned int, net_global::ban_reason_t> >::iterator it2 = it;
		++it;
		if( it2->second.first < m_unix_time )
			m_banip.erase( it2 );
	}
}

void tcp_server::stop()
{
	m_acceptor->close();
	m_ttp->shutdown();
	net_global::del_net_obj( this );
	if( m_sessionpool )
	{
		for( unsigned int i = 0; i < m_poolcount; ++i )
			delete m_sessionpool[i];
		delete[] m_sessionpool;
	}

	if( m_acceptor)
		delete m_acceptor;

	m_ttp->shutdown();
	delete m_ttp;
	if( m_thread_buffer )
		delete[] m_thread_buffer;
}

void tcp_server::_prepare_for_next_accept()
{
	{
		boost::mutex::scoped_lock lock( m_proc_mutex );
		if( m_accepting_count >= m_poolcount / 5 )
			return;
	}

	tcp_basesession* p = get_free_session();
	if( p )
	{
		{
			boost::mutex::scoped_lock lock( m_proc_mutex );
			m_sessions.insert( p );
			++m_accepting_count;

			if( m_unix_time - m_last_clean_idle_ip_time > 3600 )
			{
				m_idleip.clear();
				m_last_clean_idle_ip_time = m_unix_time;
			}
		}
		m_acceptor->async_accept( p->socket(), boost::bind( &tcp_server::handle_accept, this, p, boost::asio::placeholders::error ) );
	}
}

void tcp_server::_real_run( bool is_wait )
{
	m_unix_time = (unsigned int)time( NULL );
	m_cb_mgr.poll();
	{
		boost::mutex::scoped_lock lock( m_msg_mutex );
		if( m_queue_recv_msg.empty() )
		{
			if( is_wait )
			{
				boost::xtime xt;
				boost::xtime_get( &xt, boost::xtime_clock_types::TIME_UTC_ );
				xt.nsec += 10000000;
				if( !m_msg_cond.timed_wait( m_msg_mutex, xt ) )
					return;
			}
			else
				return;
		}
		std::swap( m_queue_proc_swap_msg, m_queue_recv_msg );
	}
	while( !m_queue_proc_swap_msg.empty() )
	{
		message_t* msg = m_queue_proc_swap_msg.front();

		if( msg->from->is_valid() && msg->from->is_connected() )
			msg->from->proc_message( *msg );

		net_global::free_message( msg );
		m_queue_proc_swap_msg.pop();
	}
}
