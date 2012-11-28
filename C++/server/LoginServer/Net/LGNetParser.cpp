#include "StdAfx.h"
#include "LGNetParser.h"
#include "MessageGate2LG.pb.h"
#include "MessageLG2Gate.pb.h"
#include "LoginGateSocket.h"
#include "../LoginUserManager.h"
#include "../UserStorage.h"
initialiseSingleton(CLGNetParser);
CLGNetParser::CLGNetParser(void)
{
}


CLGNetParser::~CLGNetParser(void)
{
}

void CLGNetParser::ParseMessage(const message_t& msg, CLoginGateSocket* pSocket)
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
			unsigned long account = LUM.tryLogin(Msg.mac().c_str());
			MsgLG2GateLoginACK MsgAck;
			MsgAck.set_id(Msg.id());
			MsgAck.set_account(account);
			MsgAck.set_result(MsgLG2GateLoginACK_enResult_LG_OK);
			pSocket->send_message(LG2Gate_MsgLG2GateLoginACK,&MsgAck);
			MyLog::log->notice("send_message MsgLG2GateLoginACK account[%l]", account);

		}
		break;
	case Gate2LG_MsgGate2LGClientDisconnect:
		{
			MsgGate2LGClientDisconnect Msg;
			Msg.ParseFromArray(msg.data + msgBodyBegin, Msghead.msgsize());
			if (Msg.id() == 0)
			{
				MyLog::log->warn("unkown client disconnect account[%l]", Msg.id());
			}
			else
			{
				if (LUM.tryLoginOut(Msg.id()))
				{
					MyLog::log->notice("client disconnent account [%l]", Msg.id());
				}
				else
				{
					MyLog::log->warn("login out account[%l] is not login in", Msg.id());
				}
			}
		}
	default:
		{
			MyLog::log->warn("unknown msg gate 2 lg");
		}

	}
}