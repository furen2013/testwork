#include "StdAfx.h"
#include "LG2GateParser.h"
#include "MsgHead.pb.h"
#include "MessageLG2Gate.pb.h"
#include "CProtoSocket.h"

initialiseSingleton(CLG2GateParser);
CLG2GateParser::CLG2GateParser(void)
{
}


CLG2GateParser::~CLG2GateParser(void)
{
}

void CLG2GateParser::ParseMessage(message_t& msg, CCProtoSocket* pSocket)
{
	unsigned short totalsize = *((unsigned short*)msg.data);
	unsigned short headsize = *((unsigned short*)msg.data + 1);
	unsigned short mark = 2 * sizeof(unsigned short);
	MsgHead Msghead;
	Msghead.ParseFromArray(msg.data + mark, headsize);
	unsigned short msgBodyBegin = mark + headsize;
	switch(Msghead.type())
	{
	case LG2Gate_MsgLG2GateLoginACK:
		{
			MsgLG2GateLoginACK Msg;
			Msg.ParseFromArray(msg.data + msgBodyBegin, Msghead.msgsize());
			if (Msg.account() == 0)
			{

			}
			else
			{
				sUserMgr.GetClient(Msg.id());
			}
			//unsigned long account = LUM.tryLogin(Msg.mac().c_str());
			//MsgLG2GateLoginACK MsgAck;
			//MsgAck.set_id(Msg.id());
			//MsgAck.set_account(account);
			//MsgAck.set_result(MsgLG2GateLoginACK_enResult_LG_OK);
			//pSocket->send_message(LG2Gate_MsgLG2GateLoginACK,&MsgAck);

		}
		break;
	default:
		{
			MyLog::log->warn("unknown msg gate 2 lg");
		}

	}
}