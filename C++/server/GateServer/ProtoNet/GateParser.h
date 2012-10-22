#pragma once
#ifndef GATEPARSER_H
#define GATEPARSER_H
#include "MsgHead.pb.h"
class CGProtoSocket;

class CGateParser : public Singleton<CGateParser>
{
public:
	CGateParser(void);
	virtual ~CGateParser(void);
	void ParseMessage(message_t& msg, CGProtoSocket* pSocket);
};

#define GATEPARSER CGateParser::getSingleton()
#endif