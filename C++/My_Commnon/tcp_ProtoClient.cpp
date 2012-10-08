#include "StdAfx.h"
#include "tcp_ProtoClient.h"


tcp_ProtoClient::tcp_ProtoClient( boost::asio::io_service& is )
	: Tcp_ProtoSession( is ), m_last_reconnect_time( 0 ), m_isreconnect( false ), m_reconnect_time( 3 ), m_isconnecting( false ), m_isinitconncted( false )
{
	reset();
	m_isvalid = true;

	MyNetGlobleObj::add_net_obj( this );
}

tcp_ProtoClient::~tcp_ProtoClient()
{
	MyNetGlobleObj::del_net_obj( this );
	_clear_recv_msg();
}

void tcp_ProtoClient::_connect( std::string address, unsigned short port )
{
	m_endpoint.port( port );
	m_endpoint.address( boost::asio::ip::address_v4::from_string( address ) );
	reconnect();
	m_isinitconncted = true;
}

void tcp_ProtoClient::connect( const char* address, unsigned short port )
{
	std::string ip( address );
	struct hostent *hptr = gethostbyname( address );
	if( hptr )
	{
		char str[32] = { 0 };
		sprintf( str, "%d.%d.%d.%d",
			(hptr->h_addr_list[0][0]&0x00ff),
			(hptr->h_addr_list[0][1]&0x00ff),
			(hptr->h_addr_list[0][2]&0x00ff),
			(hptr->h_addr_list[0][3]&0x00ff));
		ip = str;
	}
	else
	{
		//assert( 0 && "invalid address" );
		return;
	}
	m_io_service.post( boost::bind( &tcp_ProtoClient::_connect, this, ip, port ) );
}

void tcp_ProtoClient::connect( unsigned long address, unsigned short port )
{
	in_addr addr;
	addr.s_addr = address;
	char* ip = inet_ntoa( addr );
	connect( ip, port );
}

bool tcp_ProtoClient::wait_connect( unsigned long address, unsigned short port )
{
	connect( address, port );

	boost::mutex::scoped_lock lock( m_conn_mutex );
	m_conn_cond.wait( m_conn_mutex );
	return is_connected();
}

bool tcp_ProtoClient::wait_connect( const char* address, unsigned short port )
{
	connect( address, port );

	boost::mutex::scoped_lock lock( m_conn_mutex );
	m_conn_cond.wait( m_conn_mutex );
	return is_connected();
}

void tcp_ProtoClient::on_connect()
{
	_read_next_message();
}

void tcp_ProtoClient::handle_connect( const boost::system::error_code& error )
{
	boost::mutex::scoped_lock lock( m_mutex );
	m_isconnecting = false;
	if( m_isconnected )
		return;

	if( !error )
	{
		m_isconnected = true;
		boost::asio::async_read( *m_socket,
			boost::asio::buffer( m_recv_buffer, 1 ),
			boost::bind( &tcp_ProtoClient::handle_read_crypt_key, this,
			boost::asio::placeholders::error ) );
	}
	else
	{
		m_isconnected = false;
		m_cb_mgr.add_cb( &tcp_ProtoClient::on_connect_failed, this, error );

		boost::mutex::scoped_lock lock( m_conn_mutex );
		m_conn_cond.notify_one();
	}

	m_last_reconnect_time = (unsigned int)time( NULL );
}

void tcp_ProtoClient::handle_read_crypt_key( const boost::system::error_code& error )
{
	if( !is_valid() )
		return;

	if( !error )
	{
		_record_action();
		m_send_crypt_key = (unsigned char)m_recv_buffer[0];
		m_recv_crypt_key = m_send_crypt_key;
		m_cb_mgr.add_cb( &tcp_ProtoClient::on_connect, this );
	}
	else
		_on_close( error );

	boost::mutex::scoped_lock lock( m_conn_mutex );
	m_conn_cond.notify_one();
}


void tcp_ProtoClient::on_accept( tcp_server* p )
{
	//assert( 0 );
}

void tcp_ProtoClient::reconnect()
{
	if( m_isconnected )
	{
		//printf( "tcp_ProtoClient::reconnect() socket is already connected\n" );
		return;
	}
	if( m_isconnecting )
		return;
	m_isconnecting = true;
	m_socket->async_connect( m_endpoint, boost::bind( &tcp_ProtoClient::handle_connect, this, boost::asio::placeholders::error ) );
	//printf( "tcp_ProtoClient::reconnect() called, ip:%s port:%d\n", m_endpoint.address().to_string().c_str(), m_endpoint.port() );
}

void tcp_ProtoClient::thread_run_asio()
{
	tcp_basesession::run();

	boost::mutex::scoped_lock lock( m_mutex );
	if( !m_isconnected && m_isreconnect && !m_isconnecting && m_isinitconncted )
	{
		unsigned int now = (unsigned int)time( NULL );
		if( now - m_last_reconnect_time > m_reconnect_time )
			reconnect();
	}
}

void tcp_ProtoClient::run()
{
	m_cb_mgr.poll();
	{
		boost::mutex::scoped_lock lock( m_msg_mutex );
		if( m_queue_recv_msg.empty() )
		{
			boost::xtime xt;
			boost::xtime_get( &xt, boost::xtime_clock_types::TIME_UTC_ );
			xt.nsec += 10000000;
			if( !m_msg_cond.timed_wait( m_msg_mutex, xt ) )
				return;
		}
		std::swap( m_queue_proc_swap_msg, m_queue_recv_msg );
	}
	while( !m_queue_proc_swap_msg.empty() )
	{
		message_t* msg = m_queue_proc_swap_msg.front();
		proc_message( *msg );
		MyNetGlobleObj::free_message( msg );
		m_queue_proc_swap_msg.pop();
	}
}

void tcp_ProtoClient::run_no_wait()
{
	m_cb_mgr.poll();
	{
		boost::mutex::scoped_lock lock( m_msg_mutex );
		if( m_queue_recv_msg.empty() )
			return;
		std::swap( m_queue_proc_swap_msg, m_queue_recv_msg );
	}
	while( !m_queue_proc_swap_msg.empty() )
	{
		message_t* msg = m_queue_proc_swap_msg.front();
		proc_message( *msg );
		MyNetGlobleObj::free_message( msg );
		m_queue_proc_swap_msg.pop();
	}
}

void tcp_ProtoClient::push_message( message_t* msg )
{
	boost::mutex::scoped_lock lock( m_msg_mutex );
	m_queue_recv_msg.push( msg );
	m_msg_cond.notify_one();
}

call_back_mgr* tcp_ProtoClient::_get_cb_mgr()
{
	return &m_cb_mgr;
}

void tcp_ProtoClient::_clear_recv_msg()
{
	boost::mutex::scoped_lock lock( m_msg_mutex );
	while( !m_queue_recv_msg.empty() )
	{
		MyNetGlobleObj::free_message( m_queue_recv_msg.front() );
		m_queue_recv_msg.pop();
	}
}
