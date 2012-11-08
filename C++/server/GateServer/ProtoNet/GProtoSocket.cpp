#include "StdAfx.h"
#include "GProtoSocket.h"
#include "MyNetGlobleObj.h"
#include "GateParser.h"
#include "LG2GateParser.h"
CGProtoSocket* p2LoginSocket = NULL;


CGProtoSocket::CGProtoSocket(boost::asio::io_service& is):tcp_ProtoClient(*MyNetGlobleObj::get_io_service() )
{
}


CGProtoSocket::~CGProtoSocket(void)
{
}


void CGProtoSocket::on_close( const boost::system::error_code& error )
{
	MyLog::log->error( "%s disconnected, error message:%s",serverName.c_str(), error.message().c_str() );
	tcp_ProtoClient::on_close( error );
}

void CGProtoSocket::on_connect()
{
	MyLog::log->info( "%s is connected",serverName.c_str());
	/*
	string strPacket = CCSPacketBuilder::BuildGateInfoReqPkg();
	PostSend(strPacket.c_str(), strPacket.size());
	*/
	//sServer.OnConnectedCS( this->get_remote_address_string() );
	tcp_ProtoClient::on_connect();

	m_isreconnect = true;
}

void CGProtoSocket::on_connect_failed( boost::system::error_code error )
{
	MyLog::log->error( "%s server failed, error message:%s",serverName.c_str(), error.message().c_str() );

	m_isreconnect = true;
}

void CGProtoSocket::proc_message(const message_t& msg )
{

	CLG2GateParser::getSingleton().ParseMessage(msg, this);
	//GATEPARSER.ParseMessage(msg,this);
		
	//unsigned short sI = *((unsigned short*)msg.data);
	//unsigned short sII = *((unsigned short*)msg.data + sizeof(unsigned short));
	//sCSParser.ParsePacket( this, (char*)msg.data, msg.len );
}
