#pragma once
#ifndef GATEPARSER_H
#define GATEPARSER_H
#include "MsgHead.pb.h"
class CCProtoSocket;

class CGateParser : public Singleton<CGateParser>
{
public:
	CGateParser(void);
	virtual ~CGateParser(void);
	void ParseMessage(const message_t& msg, CCProtoSocket* pSocket);
};

#define GATEPARSER CGateParser::getSingleton()
#endif