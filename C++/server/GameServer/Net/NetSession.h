#pragma once
#ifndef NETSESSION_H
#define NETSESSION_H
#include "MsgHead.pb.h"
#include "TypeDef.h"
class CGTSocket;
class NetSession
{
public:
	NetSession();
	~NetSession();
	void sendMessage(::google::protobuf::Message* message, MsgType type);
protected:
	DWORD _account;
	CGTSocket* _socket;
};
#endif