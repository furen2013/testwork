#include "StdAfx.h"
#include "NetParser.h"
#include "MessageGate2GS.pb.h"
#include "Net/NetSessionManager.h"
#include "Net/NetSession.h"

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
			}
		}
	}
}
