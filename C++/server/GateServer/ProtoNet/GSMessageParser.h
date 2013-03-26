#pragma once
#ifndef GSMESSAGEPARSER_H
#define GSMESSAGEPARSER_H
#include "MsgHead.pb.h"
class GameServerSocket;

class GSMessageParser : public Singleton<GSMessageParser>
{
public:
	GSMessageParser(void);
	virtual ~GSMessageParser(void);
	void ParseMessage(const message_t& msg, GameServerSocket* pSocket);
};

#define GSPARSER GSMessageParser::getSingleton()
#endif