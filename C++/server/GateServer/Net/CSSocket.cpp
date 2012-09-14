#include "../stdafx.h"
#include "CSSocket.h"
//#include "CSParser.h"
//initialiseSingleton(CCSSocket);

CCSSocket* g_css;

CCSSocket::CCSSocket() : tcp_client( *net_global::get_io_service() )
{
	//m_isreconnect = true;
}

CCSSocket::~CCSSocket(void)
{
}

void CCSSocket::on_close( const boost::system::error_code& error )
{
	MyLog::log->error( "center server disconnected, error message:%s", error.message().c_str() );
	tcp_client::on_close( error );
}

void CCSSocket::on_connect()
{
	/*
	string strPacket = CCSPacketBuilder::BuildGateInfoReqPkg();
	PostSend(strPacket.c_str(), strPacket.size());
	*/
	sServer.OnConnectedCS( this->get_remote_address_string() );
	tcp_client::on_connect();

	m_isreconnect = true;
}

void CCSSocket::on_connect_failed( boost::system::error_code error )
{
	MyLog::log->error( "connect center server failed, error message:%s", error.message().c_str() );

	m_isreconnect = true;
}

void CCSSocket::proc_message( const message_t& msg )
{
	//sCSParser.ParsePacket( this, (char*)msg.data, msg.len );
}

void CCSSocket::PostSend( const void* data, uint16 len )
{
	send_message( data, len );
}

void CCSSocket::PostSend( const PakHead& msg )
{
	CPacketSn cps;
	cps << msg;
	cps.SetProLen();
	send_message( cps.GetBuf(), cps.GetSize() );
}
