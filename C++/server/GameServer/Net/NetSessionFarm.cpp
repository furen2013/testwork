#include "stdafx.h"
#include "NetSession.h"
#include "../net/GSocket.h"
#include "MessageFarmC2S.pb.h"
void NetSession::HandleFarmStateReq(MsgHead& Msg)
{
	MsgFarmStateReq MsgRecive;
	MsgRecive.ParseFromString(Msg.body());

	

}

void NetSession::HandleGatherPloughCellReq(MsgHead& Msg)
{
	MsgGatherPloughCellReq MsgRecive;
	MsgRecive.ParseFromString(Msg.body());
}

void NetSession::HandleSeedCellReq(MsgHead& Msg)
{
	MsgSeedCellReq MsgRecive;
	MsgRecive.ParseFromString(Msg.body());
}

void NetSession::HandleSpreadManureReq(MsgHead& Msg)
{
	MsgSpreadManureReq MsgRecive;
	MsgRecive.ParseFromString(Msg.body());
}

void NetSession::HandleWaterCellReq(MsgHead& Msg)
{
	MsgWaterCellReq MsgRecive;
	MsgRecive.ParseFromString(Msg.body());
}

