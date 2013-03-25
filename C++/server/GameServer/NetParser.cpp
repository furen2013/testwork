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
			//���ݿ�װ�ڻص�
			NetSession* p = NetSessionManager::getSingleton().FindSession(Msg.account());
			if (p == NULL)
			{
				//�����δ��¼
				FarmLogic* pFarmLogic = FarmManager::getSingleton().GetFarmLogic(Msg.account());
				if (pFarmLogic == NULL)
				{
					//�����һ�ε�½
					pFarmLogic = FarmManager::getSingleton().CreateFarm(Msg.account());
				}

				PlayerInfo* playerInfo = PlayerInfoManager::getSingleton().GetPlayerInfo(Msg.account());
				if (playerInfo == NULL)
				{
					playerInfo = PlayerInfoManager::getSingleton().CreatePlayerInfo(Msg.account());
				}
				// ����resource ��Դ �������ݿ� �첽

			}
			else
			{

			}
		}
	}
}
