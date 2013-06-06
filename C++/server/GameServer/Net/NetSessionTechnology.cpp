#include "stdafx.h"
#include "NetSession.h"
#include "../net/GSocket.h"
#include "MessageTechnologyC2S.pb.h"
#include "MessageTechnologyG2C.pb.h"
#include "../logic/Player.h"
#include "MessageFarmC2S.pb.h"
void NetSession::HandleTechnologyStateReq(MsgHead& Msg)
{
	//MsgTechnologyStateReq Msg;
	if (_player)
	{
		_player->sendTechnologyState();
	}

}
void NetSession::HandleTechLevelReq(MsgHead& Msg)
{
	if (_player)
	{
		MsgOpenTechLevelReq MsgRecive;
		MsgRecive.ParseFromString(Msg.body());
		_player->openTechLevel(MsgRecive.level());

	}

	
}
void NetSession::HandleApplyAddTechInfoReq(MsgHead& Msg)
{
	if (_player)
	{
		MsgApplyAddTechInfoReq MsgRecive;
		MsgRecive.ParseFromString(Msg.body());
		_player->addTechInfo(MsgRecive.level(), MsgRecive.id(), MsgRecive.addcount());
	}
}

void NetSession::HandleAddTechValueReq(MsgHead& Msg)
{
	if (_player)
	{
		MsgAddTechValueReq MsgRecive;
		MsgRecive.ParseFromString(Msg.body());
		_player->addTechValue(MsgRecive.count());
	}
}

void NetSession::HandleBuildMillReq(MsgHead& Msg)
{
	if (_player)
	{
		MsgBuildMillReq MsgRecive;
		MsgRecive.ParseFromString(Msg.body());


	}
}

void NetSession::HandleBuildWaterWayReq(MsgHead& Msg)
{
	if (_player)
	{
		MsgBuildWaterWayReq MsgRecive;
		MsgRecive.ParseFromString(Msg.body());
	}
}

