#include "../stdafx.h"
#include "GSSocket.h"
#include "GSListenSocket.h"
#include "GSParser.h"

CGSSocket::CGSSocket( boost::asio::io_service& is ) : tcp_session( is )
{
	m_strIP = "";
	m_dwIP = 0;
	m_iPort = 0;
	m_byGSIdx = 0xFF;
	m_dwGSVersion = 0;
}

CGSSocket::~CGSSocket(void)
{
}

void CGSSocket::on_accept( tcp_server* p )
{
	m_strIP = this->get_remote_address_string();
	m_dwIP = this->get_remote_address_ui();
	m_iPort = this->get_remote_port();

	MyLog::log->info( "A GS Connection[%s] Accepted", m_strIP.c_str() );

	sGSLS.AddAcceptedSocket( this );
	tcp_session::on_accept( p );
}

void CGSSocket::on_close( const boost::system::error_code& error )
{
	sGSLS.RemoveAcceptedSocket(this);
	tcp_session::on_close( error );
}

void CGSSocket::proc_message( const message_t& msg )
{
	sGSParser.ParsePacket( this, (char*)msg.data, msg.len );
}

void CGSSocket::PostSend( const void* data, uint16 len )
{
	send_message( data, len );
}
