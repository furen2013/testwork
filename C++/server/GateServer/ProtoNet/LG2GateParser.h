#pragma once
#ifndef CLG2GATEPARSER_H
#define CLG2GATEPARSER_H
class CCProtoSocket;

class CLG2GateParser : public Singleton<CLG2GateParser>
{
public:
	CLG2GateParser(void);
	~CLG2GateParser(void);
public:
	void ParseMessage(message_t& msg, CCProtoSocket* pSocket);
};


#endif