#include "stdafx.h"
#include "NetSession.h"
#include "../net/GSocket.h"
#include "MessageFarmC2S.pb.h"
#include "../logic/Player.h"
#include "../logic/farm/FarmLogic.h"
void NetSession::HandleFarmStateReq(MsgHead& Msg)
{
	MsgFarmStateReq MsgRecive;
	MsgRecive.ParseFromString(Msg.body());
	_player->sendFarmState();
}

void NetSession::HandleGatherPloughCellReq(MsgHead& Msg)
{
	MsgGatherPloughCellReq MsgRecive;
	MsgRecive.ParseFromString(Msg.body());
	_player->gatherPloughCell(MsgRecive.cellid());
}

void NetSession::HandleSeedCellReq(MsgHead& Msg)
{
	MsgSeedCellReq MsgRecive;
	MsgRecive.ParseFromString(Msg.body());
	_player->seedCell(MsgRecive.cellid(), MsgRecive.seedlevel());
}

void NetSession::HandleSpreadManureReq(MsgHead& Msg)
{
	MsgSpreadManureReq MsgRecive;
	MsgRecive.ParseFromString(Msg.body());
	_player->spreadManure(MsgRecive.cellid(), MsgRecive.manurelevel());
}

void NetSession::HandleWaterCellReq(MsgHead& Msg)
{
	MsgWaterCellReq MsgRecive;
	MsgRecive.ParseFromString(Msg.body());
	_player->wateringCell(MsgRecive.cellid());
}

void NetSession::HandleCreateCellReq(MsgHead& Msg)
{
	if (_player)
	{
	}
}

void NetSession::HandleCreateFarmReq(MsgHead& Msg)
{
	if (_player)
	{
		if (_player->getFarm() != NULL)
		{

		}
		
	}
}