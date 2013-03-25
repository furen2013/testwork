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
			//数据库装在回调
			NetSession* p = NetSessionManager::getSingleton().FindSession(Msg.account());
			if (p == NULL)
			{
				//该玩家未登录
				FarmLogic* pFarmLogic = FarmManager::getSingleton().GetFarmLogic(Msg.account());
				if (pFarmLogic == NULL)
				{
					//该玩第一次登陆
					pFarmLogic = FarmManager::getSingleton().CreateFarm(Msg.account());
				}

				PlayerInfo* playerInfo = PlayerInfoManager::getSingleton().GetPlayerInfo(Msg.account());
				if (playerInfo == NULL)
				{
					playerInfo = PlayerInfoManager::getSingleton().CreatePlayerInfo(Msg.account());
				}
				// 载入resource 资源 访问数据库 异步

			}
			else
			{

			}
		}
	}
}
