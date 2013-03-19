#pragma once
#ifndef GSNETPARSER_H
#define GSNETPARSER_H
#include "Singleton.h"
#include "MsgHead.pb.h"
class CGTSocket;

class NetParser : public Singleton<NetParser>
{
public:
	NetParser(void);
	virtual ~NetParser(void);
	void ParseMessage(const message_t& msg, CGTSocket* pSocket);
};
#define NETPARSER NetParser::getSingleton()
#endif