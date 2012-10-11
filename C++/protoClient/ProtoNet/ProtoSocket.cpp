#include "StdAfx.h"
#include "ProtoSocket.h"
#include "../new_common/Source/log4cpp-1.0/MyLog.h"


CProtoSocket* g_css;

CProtoSocket::CProtoSocket(boost::asio::io_service& is ) : tcp_ProtoClient( *MyNetGlobleObj::get_io_service() )
{
	//m_isreconnect = true;
}

CProtoSocket::~CProtoSocket(void)
{
}

void CProtoSocket::on_close( const boost::system::error_code& error )
{
	MyLog::log->error( "center server disconnected, error message:%s", error.message().c_str() );
	tcp_ProtoClient::on_close( error );
}

void CProtoSocket::on_connect()
{
	/*
	string strPacket = CCSPacketBuilder::BuildGateInfoReqPkg();
	PostSend(strPacket.c_str(), strPacket.size());
	*/
	//sServer.OnConnectedCS( this->get_remote_address_string() );
	tcp_ProtoClient::on_connect();

	m_isreconnect = true;
}

void CProtoSocket::on_connect_failed( boost::system::error_code error )
{
	//MyLog::log->error( "connect center server failed, error message:%s", error.message().c_str() );

	m_isreconnect = true;
}

void CProtoSocket::proc_message( const message_t& msg )
{
	//sCSParser.ParsePacket( this, (char*)msg.data, msg.len );
}


