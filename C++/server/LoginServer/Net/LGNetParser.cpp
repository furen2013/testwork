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
			unsigned long account = 0;
			CLoginUser* pLoginUser = LUM.GetLoginUser(Msg.mac().c_str());

			if (pLoginUser != NULL)
			{
				//already login 
				account = pLoginUser->m_Info->account;
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
	case C2Gate_MsgBindMailReq:
		{
			MsgBindMailReq Msg;
			Msg.ParseFromArray(msg.data + msgBodyBegin, Msghead.msgsize());
			MsgLG2GateBindMailACK MsgACK;
			MsgACK.set_account(Msg.account());
			MyLog::log->notice("recive bind mail request account[%l] mail[%s] password[%s] mac[%s]", 
				Msg.account(), Msg.mail(), Msg.password(),Msg.mac());
			if (LUM.isAlreadyLogin(Msg.account()) == false)
			{
				MsgACK.set_result(MsgLG2GateBindMailACK_enResult_LG_ERRORNOTLOGIN);
			}
			else
			{
				CLoginUser* pUser = LUM.GetLoginUser(Msg.account());
				enBindMail en = LUM.bindMail(Msg.account(), Msg.mail().c_str(), Msg.password().c_str(), Msg.mac().c_str());
				switch(en)
				{
				case BindMail_MailAlreadyBinded:
					{
						MsgACK.set_result(MsgLG2GateBindMailACK_enResult_LG_ERROR_MAIL_IS_BINDED);
						MyLog::log->notice("account[%l] mail[%s] password[%s] mac[%s] account is already binded", 
							Msg.account(), Msg.mail(), Msg.password(),Msg.mac());
					}
					break;
				case BindMail_OK:
					{
						MsgACK.set_result(MsgLG2GateBindMailACK_enResult_LG_OK);
						MyLog::log->notice("account[%l] mail[%s] password[%s] mac[%s] account bind mail ok", 
							Msg.account(), Msg.mail(), Msg.password(),Msg.mac());
					}
					break;
				default:
					{
						MyLog::log->notice("account[%l] mail[%s] password[%s] mac[%s] account other error", 
							Msg.account(), Msg.mail(), Msg.password(),Msg.mac());
						MsgACK.set_result(MsgLG2GateBindMailACK_enResult_LG_ERROR);
					}

				}
				pSocket->send_message(LG2C_MsgBindMailACK,&MsgACK);
			}
			
		}
		break;
	default:
		{
			MyLog::log->warn("unknown msg gate 2 lg");
		}

	}
}