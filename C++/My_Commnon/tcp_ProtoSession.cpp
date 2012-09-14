#include "StdAfx.h"
#include "tcp_ProtoSession.h"
#include "MyNetGlobleObj.h"


Tcp_ProtoSession::Tcp_ProtoSession( boost::asio::io_service& is ) :tcp_basesession(is)
{

}


Tcp_ProtoSession::~Tcp_ProtoSession(void)
{
}


void Tcp_ProtoSession::handle_read_header( const boost::system::error_code& error )
{

}
void Tcp_ProtoSession::handle_read_body( const boost::system::error_code& error )
{

}
void Tcp_ProtoSession::handle_write( const boost::system::error_code& error, int size, int block_idx )
{

}
void Tcp_ProtoSession::send_message( const void* data, unsigned short len )
{

}


void Tcp_ProtoSession::_write_message()
{

}
void Tcp_ProtoSession::_read_next_message()
{
	boost::asio::async_read( *m_socket,
		boost::asio::buffer( m_recv_buffer, MyNetGlobleObj.GetMsgHeadLen() ),
		boost::bind( &tcp_basesession::handle_read_header, this,
		boost::asio::placeholders::error ) );
}