#include "StdAfx.h"
#include "GSocket.h"
#include "MyLog.h"

CGTSocket::CGTSocket( boost::asio::io_service& is ) : Tcp_ProtoSession( is )
{
	m_dwIP = 0;
	m_iPort = 0;
}

CGTSocket::~CGTSocket(void)
{
}

void CGTSocket::on_accept( tcp_server* p )
{
	m_strIP = this->get_remote_address_string();
	m_dwIP = this->get_remote_address_ui();
	m_iPort = this->get_remote_port();

	MyLog::log->info( "A GT Connection[%s] Accepted", m_strIP.c_str() );

	//sGTLS.AddAcceptedSocket( this );
	Tcp_ProtoSession::on_accept( p );
}

void CGTSocket::on_close( const boost::system::error_code& error )
{
	//sGTLS.RemoveAcceptedSocket(this);
	Tcp_ProtoSession::on_close( error );
}

void CGTSocket::proc_message( const message_t& msg )
{
	//todo parasePacket
	//sGTParser.ParsePacket( this, (char*)msg.data, msg.len );
}

void CGTSocket::PostSend( const void* data, size_t len )
{
	send_message( data, len );
}
//
//void CGTSocket::PostSend( PakHead& msg )
//{
//	CPacketSn cps;
//	cps << msg;
//	cps.SetProLen();
//	send_message( cps.GetBuf(), cps.GetSize() );
//}
