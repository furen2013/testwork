#pragma once
#ifndef CLGNETPARSER_H
#define CLGNETPARSER_H
#include "../../../Common/share/Singleton.h"
#include "../../../../new_common/Source/net/asiodef.h"
#include "MsgHead.pb.h"
extern enum enBindResult;
extern enum enMsgBindResult;
class CLoginGateSocket;
class CLGNetParser :  public Singleton<CLGNetParser>
{
public:
	CLGNetParser(void);
	~CLGNetParser(void);
public:
	void ParseMessage(const message_t& msg, CLoginGateSocket* pSocket);
	enMsgBindResult ParseBindMsg(enBindResult en, unsigned long account, const char* mail, const char* password, const char* mac);
};

#define CLGPARSER CLGNetParser::getSingleton()

#endif