#pragma once
#ifndef CLGNETPARSER_H
#define CLGNETPARSER_H
#include "../../../Common/share/Singleton.h"
#include "../../../../new_common/Source/net/asiodef.h"
#include "MsgHead.pb.h"
class CLoginGateSocket;
class CLGNetParser :  public Singleton<CLGNetParser>
{
public:
	CLGNetParser(void);
	~CLGNetParser(void);
public:
	void ParseMessage(const message_t& msg, CLoginGateSocket* pSocket);
};

#define CLGPARSER CLGNetParser::getSingleton()

#endif