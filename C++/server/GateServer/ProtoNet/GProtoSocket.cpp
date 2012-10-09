#include "StdAfx.h"
#include "GProtoSocket.h"
#include "MyNetGlobleObj.h"


CGProtoSocket::CGProtoSocket(boost::asio::io_service& is):tcp_ProtoClient(*MyNetGlobleObj::get_io_service() )
{
}


CGProtoSocket::~CGProtoSocket(void)
{
}


void CGProtoSocket::on_close( const boost::system::error_code& error )
{
	MyLog::log->error( "center server disconnected, error message:%s", error.message().c_str() );
	tcp_ProtoClient::on_close( error );
}

void CGProtoSocket::on_connect()
{
	/*
	string strPacket = CCSPacketBuilder::BuildGateInfoReqPkg();
	PostSend(strPacket.c_str(), strPacket.size());
	*/
	sServer.OnConnectedCS( this->get_remote_address_string() );
	tcp_ProtoClient::on_connect();

	m_isreconnect = true;
}

void CGProtoSocket::on_connect_failed( boost::system::error_code error )
{
	MyLog::log->error( "connect center server failed, error message:%s", error.message().c_str() );

	m_isreconnect = true;
}

void CGProtoSocket::proc_message( const message_t& msg )
{
	//sCSParser.ParsePacket( this, (char*)msg.data, msg.len );
}
