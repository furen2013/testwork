#include "stdafx.h"
#include "GSMessageParser.h"
#include "../GameLogic/GateUserManager.h"
#include "CProtoSocket.h"
#include "LoginSocket.h"
#include "GameServerSocket.h"
#include "MessageGate2LG.pb.h"
#include "MessageGate2GS.pb.h"
#include "MessageG2C.pb.h"
extern LoginSocket* p2LoginSocket;

initialiseSingleton(GSMessageParser);
GSMessageParser::GSMessageParser()
{

}

GSMessageParser::~GSMessageParser()
{

}


void GSMessageParser::ParseMessage(const message_t& msg, GameServerSocket* pSocket)
{
	unsigned short totalsize = *((unsigned short*)msg.data);
	//unsigned short headsize = *((unsigned short*)msg.data + 1);
	unsigned short mark = sizeof(unsigned short);
	MsgHead Msghead;
	Msghead.ParseFromArray(msg.data + mark, totalsize);
	//unsigned short msgBodyBegin = mark + headsize;
	switch(Msghead.type())
	{
	case GS2Client_GS2GateLoginOKACK:
		{
			CCProtoSocket*pSocket = GUManager.GetLoginClient(Msghead.account());
			if (pSocket == NULL)
			{
				// 客户端连接不存在 

				MsgGate2LGClientDisconnect Msg;
				Msg.set_id(Msghead.account());
				p2LoginSocket->send_message(Gate2LG_MsgGate2LGClientDisconnect, &Msg);

				MsgGate2GSLoginOutReq MsgLoginOut;
				MsgLoginOut.set_account(Msghead.account());
				pSocket->send_message(GS_MsgGaet2GSLoginOutReq, &MsgLoginOut);
			}
			else
			{
				MsgG2CLoginACK MsgAck;
				MsgAck.set_account(0);
				pSocket->send_message(G2C_LoginACK, &MsgAck);
			}
			
			//Msghead.account()
		}

	default:
		{

			CCProtoSocket*pSocket = GUManager.GetLoginClient(Msghead.account());
			if (pSocket)
			{
				pSocket->send_message(&Msghead);
			}
			else
			{
				MyLog::log->warn("GSParserMsg failed find login account [%lu]", Msghead.account());
			}
		}

	}
}