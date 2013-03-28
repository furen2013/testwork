#include "StdAfx.h"
#include "GateParser.h"
#include "GProtoSocket.h"
#include "MessageC2G.pb.h"
#include "CProtoSocket.h"
#include "MessageG2C.pb.h"
#include "MessageGate2LG.pb.h"
#include "../GameLogic/GateUserManager.h"
#include "LoginSocket.h"
extern LoginSocket* p2LoginSocket;
initialiseSingleton(CGateParser);
CGateParser::CGateParser(void)
{
}


CGateParser::~CGateParser(void)
{
}

void CGateParser::ParseMessage(const message_t& msg, CCProtoSocket* pSocket)
{
	unsigned short totalsize = *((unsigned short*)msg.data);
	//unsigned short headsize = *((unsigned short*)msg.data + 1);
	unsigned short mark = sizeof(unsigned short);
	MsgHead Msghead;
	Msghead.ParseFromArray(msg.data + mark, totalsize);
	//unsigned short msgBodyBegin = mark + headsize;
	switch(Msghead.type())
	{
	case C2S_MsgMailLoginReq:
		{
			DWORD ID = (DWORD)pSocket;
			MsgMailLoginReq MsgRecive;
			MsgRecive.ParseFromString(Msghead.body());
			MyLog::log->notice("recive login mail request mail[%s] password[%s]", MsgRecive.mail(),MsgRecive.password());
			if (GUManager.GetClient(ID))
			{
				if (pSocket->GetAccountID() != 0)
				{
					MyLog::log->warn("mail login in the user is already login in");
				}
				else
				{
					MsgGate2LGMailLoginReq MsgSend;
					MsgSend.set_mail(MsgRecive.mail());
					MsgSend.set_password(MsgRecive.password());
					MsgSend.set_id(ID);

					if (p2LoginSocket)
					{
						p2LoginSocket->send_message(Gate2LG_MsgGate2LGLoginMailReq, &MsgSend);
					}
				}

			}
			else{
				MyLog::log->warn("recive login mail request mail[%s] password[%s] not found session", MsgRecive.mail(),MsgRecive.password());
			}
			
			//GUManager.
		}
		break;
	case C2S_MsgLoginMacReq:
		{
			if (pSocket->GetAccountID() != 0)
			{
				MsgG2CErrorACK MsgErrorACK;
				MsgErrorACK.set_en(MsgG2CErrorACK_enResult_LG_ALREADYLOGIN);
				pSocket->send_message(G2C_MsgG2CErrorACK,&MsgErrorACK);
				MyLog::log->warn("mac login the user is already login in");

			}
			else
			{
				MsgC2SLoginMacReq MsgLoginMac;
				MsgLoginMac.ParseFromString(Msghead.body());
				if (MsgLoginMac.has_mac())
				{
					MsgGate2LGLoginReq Msg;
					Msg.set_mac(MsgLoginMac.mac());
					Msg.set_id(pSocket->GetSessionID());
					
					if (p2LoginSocket)
					{
						p2LoginSocket->send_message(Gate2LG_MsgGate2LGLoginReq, &Msg);
					}
				}

			}
			
		}
		break;
	case C2S_MsgBindMailReq:
	case C2S_MsgUnbindMacReq:
	case C2S_MsgBindMacReq:
		{
			if (pSocket->GetAccountID() == 0)
			{
				MsgG2CErrorACK MsgErrorACK;
				MsgErrorACK.set_en(MsgG2CErrorACK_enResult_LG_YOUARENOTLOGIN);
				pSocket->send_message(G2C_MsgG2CErrorACK,&MsgErrorACK);

			}
			else
			{
				MsgBindMailReq Msg;
				Msg.ParseFromString(Msghead.body());
				if (pSocket->GetAccountID() != Msg.account())
				{
					MsgG2CErrorACK MsgErrorACK;
					MsgErrorACK.set_en(MsgG2CErrorACK_enResult_LG_UNKNOW);
					pSocket->send_message(G2C_MsgG2CErrorACK,&MsgErrorACK);

				}
				else
				{
					Msghead.set_account(pSocket->GetSessionID());
					p2LoginSocket->send_message(&Msghead);
					//p2LoginSocket->_send_message(pNew);
				}
			}
		}
		break;

	}
	//unsigned short sII = *((unsigned short*)msg.data + sizeof(unsigned short));

}