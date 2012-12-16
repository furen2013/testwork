#pragma once
#include "../server/Common/share/Singleton.h"
#include "asiodef.h"
class CProtoSocket;
class CClientMsgParser : public Singleton<CClientMsgParser>
{
public:
	CClientMsgParser(void);
	~CClientMsgParser(void);
public:
	void proc_message(const message_t& msg, CProtoSocket* p);
public:
	unsigned long account;
};



