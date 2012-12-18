#include "StdAfx.h"
#include "LGNetParser.h"
#include "MessageGate2LG.pb.h"
#include "MessageLG2Gate.pb.h"
#include "MessageC2G.pb.h"
#include "LoginGateSocket.h"
#include "../LoginUserManager.h"
#include "../LoginUser.h"
#include "../UserStorage.h"
initialiseSingleton(CLGNetParser);
CLGNetParser::CLGNetParser(void)
{
}


CLGNetParser::~CLGNetParser(void)
{
}


enMsgBindResult CLGNetParser::ParseBindMsg(enBindResult en, unsigned long account, const char* mail, const char* password, const char* mac)
{
	enMsgBindResult enReturn = BindMsgResult_OK;
	switch(en)
	{
	case BindResultMailAlreadyBinded:
		{
			MyLog::log->notice("account[%lu] mail[%s] password[%s] mac[%s] mail is already binded", account, mail,
				password,mac);
			enReturn = BindMsgResultMacAlreadyBinded;
		}
		break;
	case BindResultEmptyMac:
		{
			MyLog::log->notice("account[%lu] mail[%s] password[%s] mac[%s] mac is empty", account, mail,
				password,mac);
			enReturn = BindMsgResultEmptyMac;
		}
		break;
	case BindResultEmptyMail:
		{
			MyLog::log->notice("account[%lu] mail[%s] password[%s] mac[%s] mail is empty", account, mail,
				password,mac);
			enReturn = BindMsgResultEmptyMail;
		}
		break;
	case BindResultErrorMac:
		{
			MyLog::log->notice("account[%lu] mail[%s] password[%s] mac[%s] mac is wrong", account, mail,
				password,mac);
			enReturn = BindMsgResultErrorMac;
		}
		break;
	case BindResultErrorMail:
		{
			MyLog::log->notice("account[%lu] mail[%s] password[%s] mac[%s] mail is wrong", account, mail,
				password,mac);
			enReturn = BindMsgResultErrorMail;
		}
		break;
	case BindResultMacAlreadyBinded:
		{
			MyLog::log->notice("account[%lu] mail[%s] password[%s] mac[%s] mac is already binded", account, mail,
				password,mac);
			enReturn = BindMsgResultMacAlreadyBinded;
		}
		break;
	case BindResultNotFoundUser:
		{
			MyLog::log->notice("account[%lu] mail[%s] password[%s] mac[%s] mac not found user", account, mail,
				password,mac);
			enReturn = BindMsgResultNotFoundUser;
		}
		break;
	case BindResultOK:
		{
			MyLog::log->notice("account[%lu] mail[%s] password[%s] mac[%s] bind type excute ok", account, mail,
				password,mac);
			enReturn = BindMsgResult_OK;
		}
	default:
		{
			MyLog::log->notice("account[%lu] mail[%s] password[%s] mac[%s] account other error", 
				account, mail, password,mac);
			enReturn = BindMsgResultError_Unknown;
			
		}
	}
	return enReturn;
}


void CLGNetParser::ParseMessage(const message_t& msg, CLoginGateSocket* pSocket)
{
	unsigned short totalsize = *((unsigned short*)msg.data);
	////unsigned short headsize = *((unsigned short*)msg.data + 1);
	unsigned short mark = sizeof(unsigned short);
	MsgHead Msghead;
	Msghead.ParseFromArray(msg.data + mark, totalsize);
	////unsigned short msgBodyBegin = mark + headsize;
	switch(Msghead.type())
	{
	case Gate2LG_MsgGate2LGLoginMailReq:
		{
			MsgGate2LGMailLoginReq Msg;
			//Msg.ParseFromString(Msghead.body());
			Msg.ParseFromString(Msghead.body());

			MyLog::log->notice("recive mail login request mail[%s] password[%s]", Msg.mail().c_str(), Msg.password().c_str());
			tgLoginMail tg = LUM.tryLogin(Msg.mail().c_str(), Msg.password().c_str());
			MsgLG2GateLoginACK MsgACK;
			switch(tg.en)
			{
			case LoginMailResult_ErrorAlreadyLogin:
				{
					MsgACK.set_result(MsgLG2GateLoginACK_enResult_LG_ALREADYLOGIN);
				}
				break;
			case LoginMailResult_NotFoundMail:
				{
					MsgACK.set_result(MsgLG2GateLoginACK_enResult_LG_NOTFOUNDMAIL);
				}
				break;
			case LoginMailResult_ErrorPassword:
				{
					MsgACK.set_result(MsgLG2GateLoginACK_enResult_LG_ERRORPASSWORD);
				}
				break;
			case MsgLG2GateLoginACK_enResult_LG_OK:
				{
					MsgACK.set_result(MsgLG2GateLoginACK_enResult_LG_OK);
				}
				break;
			}

			MyLog::log->notice("send mail login ACK account[%l]",MsgACK.account());
			MsgACK.set_account(tg.account);
			pSocket->send_message(LG2Gate_MsgLG2GateLoginACK,&MsgACK);

		}
		break;
	case Gate2LG_MsgGate2LGLoginReq:
		{
			MsgGate2LGLoginReq Msg;
			Msg.ParseFromString(Msghead.body());
			unsigned long account = 0;
			CLoginUser* pLoginUser = LUM.GetLoginUser(Msg.mac().c_str());

			if (pLoginUser != NULL)
			{
				//already login 
				//account = pLoginUser->m_Info->account;
			}
			else
			{
				account = LUM.tryLogin(Msg.mac().c_str());
			}


			MsgLG2GateLoginACK MsgAck;
			MsgAck.set_id(Msg.id());
			MsgAck.set_account(account);
			MsgAck.set_result(MsgLG2GateLoginACK_enResult_LG_OK);
			pSocket->send_message(LG2Gate_MsgLG2GateLoginACK,&MsgAck);
			MyLog::log->notice("send_message MsgLG2GateLoginACK account[%lu]", account);

		}
		break;
	case Gate2LG_MsgGate2LGClientDisconnect:
		{
			MsgGate2LGClientDisconnect Msg;
			Msg.ParseFromString(Msghead.body());
			if (Msg.id() == 0)
			{
				MyLog::log->warn("unkown client disconnect account[%lu]", Msg.id());
			}
			else
			{
				if (LUM.tryLoginOut(Msg.id()))
				{
					MyLog::log->notice("client disconnent account [%lu]", Msg.id());
				}
				else
				{
					MyLog::log->warn("login out account[%lu] is not login in", Msg.id());
				}
			}
		}
		break;
	case C2Gate_MsgBindMailReq:
		{
			MsgBindMailReq Msg;
			Msg.ParseFromString(Msghead.body());
			MsgLG2GateBindACK MsgACK;
			MsgACK.set_account(Msg.account());
			MsgACK.set_entype(TypeBindLogic_BindMail);
			MyLog::log->notice("recive bind mail request account[%lu] mail[%s] password[%s] mac[%s]", 
				Msg.account(), Msg.mail().c_str(), Msg.password().c_str(),Msg.mac().c_str());
			if (LUM.isAlreadyLogin(Msg.account()) == false)
			{
				MsgACK.set_result(BindMsgResultNotFoundAccount);
			}
			else
			{
				CLoginUser* pUser = LUM.GetLoginUser(Msg.account());
				enBindResult en = LUM.bindMail(Msg.account(), Msg.mail().c_str(), Msg.password().c_str(), Msg.mac().c_str());
				enMsgBindResult enMsg = ParseBindMsg(en,Msg.account(), Msg.mail().c_str(), Msg.password().c_str(), Msg.mac().c_str());
				MsgACK.set_result(enMsg);
				
			}
			pSocket->send_message(LG2C_MsgBindMailACK,&MsgACK, Msghead.account());
			
		}
		break;
	case C2Gate_MsgUnbindMacReq:
		{
			MsgUnbindMacReq Msg;
			Msg.ParseFromString(Msghead.body());
			MsgLG2GateBindACK MsgACK;
			MsgACK.set_account(Msg.account());
			MsgACK.set_entype(TypeBindLogic_UnbindMac);

			MyLog::log->notice("recive unbind mac request account[%lu] mail[%s] password[%s] mac[%s]", 
				Msg.account(), Msg.mail().c_str(), Msg.password().c_str(),Msg.mac().c_str());
			enBindResult en = LUM.UnbindMac(Msg.account(), Msg.mail().c_str(),Msg.password().c_str(), Msg.mac().c_str());
			enMsgBindResult enMsg = ParseBindMsg(en,Msg.account(), Msg.mail().c_str(), Msg.password().c_str(), Msg.mac().c_str());
			MsgACK.set_result(enMsg);
			pSocket->send_message(LG2C_MsgBindMailACK,&MsgACK, Msghead.account());
		}
		break;
	case C2Gate_MsgBindMacReq:
		{
			MsgBindMacReq Msg;
			MsgLG2GateBindACK MsgACK;
			MsgACK.set_entype(TypeBindLogic_BindMac);
			Msg.ParseFromString(Msghead.body());
			MsgACK.set_account(Msg.account());

			MyLog::log->notice("recive bind mac request account[%lu] mail[%s] password[%s] mac[%s]", 
				Msg.account(), Msg.mail().c_str(), Msg.password().c_str(),Msg.mac().c_str());
			enBindResult en = LUM.bindMac(Msg.account(), Msg.mail().c_str(),Msg.password().c_str(), Msg.mac().c_str());
			enMsgBindResult enMsg = ParseBindMsg(en,Msg.account(), Msg.mail().c_str(), Msg.password().c_str(), Msg.mac().c_str());
			MsgACK.set_result(enMsg);
			pSocket->send_message(LG2C_MsgBindMailACK,&MsgACK, Msghead.account());
		}
	default:
		{
			MyLog::log->warn("unknown msg gate 2 lg");
		}
		break;

	}
}