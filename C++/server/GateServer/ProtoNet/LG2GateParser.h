#pragma once
#ifndef CLG2GATEPARSER_H
#define CLG2GATEPARSER_H
#include "../../../Common/share/Singleton.h"
class CGProtoSocket;

class CLG2GateParser : public Singleton<CLG2GateParser>
{
public:
	CLG2GateParser(void);
	~CLG2GateParser(void);
public:
	void ParseMessage(const message_t& msg,const CGProtoSocket* pSocket);
};


#endif