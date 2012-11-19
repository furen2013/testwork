#include "StdAfx.h"
#include "ClientMsgParser.h"
#include "MsgHead.pb.h"
initialiseSingleton(CClientMsgParser);

CClientMsgParser::CClientMsgParser(void)
{
}


CClientMsgParser::~CClientMsgParser(void)
{
}

void CClientMsgParser::proc_message(const message_t& msg, CProtoSocket* p)
{
	unsigned short totalsize = *((unsigned short*)msg.data);
	unsigned short headsize = *((unsigned short*)msg.data + 1);
	unsigned short mark = 2 * sizeof(unsigned short);
	MsgHead Msghead;
	Msghead.ParseFromArray(msg.data + mark, headsize);
	unsigned short msgBodyBegin = mark + headsize;
	switch(Msghead.type())
	{
	case G2C_LoginMacACK:
		{

		}
		break;
	}
}