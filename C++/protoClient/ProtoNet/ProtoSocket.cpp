#include "StdAfx.h"
#include "ProtoSocket.h"
#include "../new_common/Source/log4cpp-1.0/MyLog.h"
#include "ClientMsgParser.h"
#include "MessageG2C.pb.h"


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
	MyLog::log->error( "connect gate server failed, error message:%s", error.message().c_str() );

	m_isreconnect = true;
}

void CProtoSocket::proc_message( const message_t& msg )
{
	CClientMsgParser::getSingleton().proc_message(msg, this);
	//unsigned short totalsize = *((unsigned short*)msg.data);
	//unsigned short headsize = *((unsigned short*)msg.data + 1);
	//unsigned short mark = 2 * sizeof(unsigned short);
	//MsgHead Msghead;
	//Msghead.ParseFromArray(msg.data + mark, headsize);
	//unsigned short msgBodyBegin = mark + headsize;
	//switch(Msghead.type())
	//{
	//case G2C_LoginMacACK:
	//	{
	//		MsgG2CLoginMacACK Msg;
	//		Msg.ParseFromArray(msg.data + msgBodyBegin, Msghead.msgsize());
	//	}
	//	break;
	//default:
	//	{
	//		MyLog::log->warn("unknown message %d", (int)Msghead.type());
	//	}
	//}
	////sCSParser.ParsePacket( this, (char*)msg.data, msg.len );
}


