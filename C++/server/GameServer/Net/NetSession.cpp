#include "stdafx.h"
#include "NetSession.h"
#include "../net/GSocket.h"

NetSession::NetSession()
{

}
NetSession::~NetSession()
{

}

void NetSession::sendMessage(::google::protobuf::Message* message, MsgType type)
{
	MsgHead msgHead;
	msgHead.set_type(type);
	msgHead.set_msgsize(message->ByteSize());
	msgHead.set_account(_account);
	std::string strTemp;
	message->SerializeToString(&strTemp);
	msgHead.set_body(strTemp);
	_socket->send_message(&msgHead);
}