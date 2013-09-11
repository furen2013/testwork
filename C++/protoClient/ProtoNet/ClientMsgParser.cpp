#include "StdAfx.h"
#include "ClientMsgParser.h"
#include "MsgHead.pb.h"
#include "MessageG2C.pb.h"
#include "MessageLG2Gate.pb.h"
#include "../../new_common/Source/log4cpp-1.0/MyLog.h"
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
	//unsigned short headsize = *((unsigned short*)msg.data + 1);
	unsigned short mark = sizeof(unsigned short);
	MsgHead Msghead;
	Msghead.ParseFromArray(msg.data + mark, totalsize);
	//unsigned short msgBodyBegin = mark + headsize;
	switch(Msghead.type())
	{
	//case G2C_LoginMacACK:
	//	{
	//		MsgG2CLoginMacACK Msg;
	//		Msg.ParseFromString(Msghead.body());
	//		MyLog::log->notice("MsgG2CLoginMacACK receive account[%lu]", Msg.account());
	//		account = Msg.account();

	//	}
	//	break;
	case G2C_MsgG2CErrorACK:
		{
			MsgG2CErrorACK Msg;
			Msg.ParseFromString(Msghead.body());
			MyLog::log->notice("recive message [MsgG2CErrorACK] ");
			switch(Msg.en())
			{
			case MsgG2CErrorACK_enResult_LG_ALREADYLOGIN:
				{
					MyLog::log->notice("you are already login");
				}
				break;
			}
		}
		break;
	case LG2C_MsgBindMailACK:
		{
			MsgLG2GateBindACK Msg;
			Msg.ParseFromString(Msghead.body());
			switch(Msg.entype())
			{
			case TypeBindLogic_BindMail:
				{
					MyLog::log->notice("recive message [LG2C_MsgBindMailACK_TypeBindLogic_BindMail]");
				}
				break;
			case TypeBindLogic_UnbindMac:
				{
					MyLog::log->notice("recive message [LG2C_MsgBindMailACK_TypeBindLogic_UnbindMac]");
				}
				break;
			case TypeBindLogic_BindMac:
				{
					MyLog::log->notice("recive message [LG2C_MsgBindMailACK_TypeBindLogic_BindMac]");
				}
				break;
			}

			MyLog::log->notice("recive message [LG2C_MsgBindMailACK]");

		}
		break;

	}
}