#include "StdAfx.h"
#include "NetParser.h"
#include "MessageGate2GS.pb.h"
#include "Net/NetSessionManager.h"
#include "Net/NetSession.h"
#include "logic/farm/FarmManager.h"
#include "logic/Player.h"
#include "logic/PlayerInfoManager.h"

initialiseSingleton(NetParser);
NetParser::NetParser(void)
{
}


NetParser::~NetParser(void)
{
}

void NetParser::ParseMessage(const message_t& msg, CGTSocket* pSocket)
{
	unsigned short totalsize = *((unsigned short*)msg.data);
	//unsigned short headsize = *((unsigned short*)msg.data + 1);
	unsigned short mark = sizeof(unsigned short);
	MsgHead Msghead;
	Msghead.ParseFromArray(msg.data + mark, totalsize);
	switch(Msghead.type())
	{
	case GS_MsgGate2GSLoginReq:
		{
			MsgGate2GSLoginReq Msg;
			Msg.ParseFromString(Msghead.body());
			Player * pUser = new Player();
			NetSession* p = NetSessionManager::getSingleton().CreateSession(Msg.account());
			if (p == NULL)
			{

			}
			else
			{
				pUser->setSession(p);
				pUser->Load(Msg.account());
			}

		}
		break;
	case GS_MsgGaet2GSLoginOutReq:
		{
			MsgGate2GSLoginOutReq Msg;
			Msg.ParseFromString(Msghead.body());
		}
	}
}
