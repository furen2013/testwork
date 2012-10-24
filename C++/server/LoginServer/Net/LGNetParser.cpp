#include "StdAfx.h"
#include "LGNetParser.h"
#include "MessageGate2LG.pb.h"
#include "MessageLG2Gate.pb.h"
initialiseSingleton(CLGNetParser);
CLGNetParser::CLGNetParser(void)
{
}


CLGNetParser::~CLGNetParser(void)
{
}

void CLGNetParser::ParseMessage(message_t& msg, CLoginGateSocket* pSocket)
{
	unsigned short totalsize = *((unsigned short*)msg.data);
	unsigned short headsize = *((unsigned short*)msg.data + 1);
	unsigned short mark = 2 * sizeof(unsigned short);
	MsgHead Msghead;
	Msghead.ParseFromArray(msg.data + mark, headsize);
	unsigned short msgBodyBegin = mark + headsize;
	switch(Msghead.type())
	{
	case Gate2LG_MsgGate2LGLoginReq:
		{
			MsgGate2LGLoginReq Msg;
			Msg.ParseFromArray(msg.data + msgBodyBegin, Msghead.msgsize());

			//if ok
			MsgLG2GateLoginACK MsgAck;
			//MsgAck.set_id()
		}
		break;

	}
}