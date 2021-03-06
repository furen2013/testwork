#include "StdAfx.h"
#include "LG2GateParser.h"
#include "MsgHead.pb.h"
#include "MessageLG2Gate.pb.h"
#include "MessageG2C.pb.h"
#include "CProtoSocket.h"
#include "MessageG2C.pb.h"
#include "../GameLogic/GateUserManager.h"
#include "MyNetGlobleObj.h"
#include "MessageGate2LG.pb.h"
#include "MessageGate2GS.pb.h"
#include "GProtoSocket.h"
#include "LoginSocket.h"
#include "GameServerSocket.h"
extern LoginSocket* p2LoginSocket;
extern GameServerSocket* p2GameServerSocket;
initialiseSingleton(CLG2GateParser);
CLG2GateParser::CLG2GateParser(void)
{
}


CLG2GateParser::~CLG2GateParser(void)
{
}

void CLG2GateParser::ParseMessage(const message_t& msg,const CGProtoSocket* pSocket)
{
	unsigned short totalsize = *((unsigned short*)msg.data);
	//unsigned short headsize = *((unsigned short*)msg.data + 1);
	unsigned short mark = sizeof(unsigned short);
	MsgHead Msghead;
	Msghead.ParseFromArray(msg.data + mark, totalsize);
	//unsigned short msgBodyBegin = mark + headsize;
	switch(Msghead.type())
	{
	case LG2Gate_MsgLG2GateReqLoginUserList:
		{
			MsgGate2LGLoginUserInfoList MsgACK;
			std::vector<unsigned long> vcAccount;
			GUManager.GetLoginClientList(vcAccount);
			std::vector<unsigned long>::iterator it = vcAccount.begin();
			unsigned long account = 0;
			for (; it != vcAccount.end(); ++ it)
			{
				account = (*it);
				tgLoginUserInfo* pInfo = MsgACK.add_listloginuser();
				pInfo->set_account(account);
			}
			p2LoginSocket->send_message(Gate2LG_MsgGate2LGLoginUserInfoList, &MsgACK );
			//GUManager.
			
		}
		break;
	case LG2Gate_MsgLG2GateLoginACK:
		{
			MsgLG2GateLoginACK Msg;
			Msg.ParseFromString(Msghead.body());
			MsgGate2GSLoginReq Msg2GS;
			MsgG2CLoginACK MsgAck;
			CCProtoSocket* pProtoSocket = GUManager.GetClient(Msg.id());
			if (pProtoSocket)
			{
				MsgAck.set_account(Msg.account());
				if (Msg.account() == 0)
				{
					MsgAck.set_account(0);
					pProtoSocket->send_message(G2C_LoginACK, &MsgAck);
				}
				else
				{
					CCProtoSocket*pSocket = GUManager.GetLoginClient(Msg.account());
					if (pSocket)
					{
						//GUManager.DelFrom3
						//LoginClient(pSocket->GetAccountID());
						GUManager.DelClient((DWORD)pSocket);
						pSocket->close();
					}

					pProtoSocket->setAccountID(Msg.account());
					if (GUManager.Add2LoginClient(pProtoSocket))
					{
						MsgGate2GSLoginReq req;
						req.set_account(Msg.account());
						p2GameServerSocket->send_message(Gate2LG_MsgGate2LGLoginReq, &req);
					}
					else
					{

						MsgAck.set_account(0);
						pProtoSocket->send_message(G2C_LoginACK, &MsgAck);
					}
				}
				
			}
			else
			{
				MyLog::log->warn("error socket [%d]", Msg.id());

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
			CCProtoSocket* pProtoSocket = GUManager.GetClient(Msghead.account());
			if (pProtoSocket)
			{
				//message_t* pNew = MyNetGlobleObj::messageclone(msg);
				pProtoSocket->send_message(&Msghead);
			}
			else
			{
				MyLog::log->warn("not found socket");
			}

		}

	}
}