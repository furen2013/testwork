#pragma once
#ifndef NETSESSION_H
#define NETSESSION_H
#include "MsgHead.pb.h"
#include "TypeDef.h"
class CGTSocket;
class NetSession;
enum SessionStatus
{
	STATUS_AUTHED = 0,
	STATUS_LOGGEDIN
};

struct OpcodeHandler
{
	uint16 status;
	void (NetSession::*handler)(MsgHead& Msg);
};
class Player;
class FarmLogic;
class NetSession
{
public:
	NetSession();
	~NetSession();
	void sendMessage(::google::protobuf::Message* message, MsgType type);
	void InitHandleTable();
	inline void setPlayer(Player* p){_player = p;}
public:
	void HandleFarmStateReq(MsgHead& Msg);
	void HandleSeedCellReq(MsgHead& Msg);
	void HandleGatherPloughCellReq(MsgHead& Msg);
	void HandleSpreadManureReq(MsgHead& Msg);
	void HandleWaterCellReq(MsgHead& Msg);
	
	//
	void HandleTechnologyStateReq(MsgHead& Msg);
	void HandleTechLevelReq(MsgHead& Msg);
	void HandleApplyAddTechInfoReq(MsgHead& Msg);
	void HandleAddTechValueReq(MsgHead& Msg);
	void HandleBuildMillReq(MsgHead& Msg);
	void HandleBuildWaterWayReq(MsgHead& Msg);

	
protected:
	OpcodeHandler* GetMsgOpcodeHandler(MsgType en);
protected:
	DWORD _account;
	CGTSocket* _socket;
	int _MsgNumber;
	Player* _player;
	OpcodeHandler WorldPacketHandlers[C2S_GSEnd - C2S_GSBegin];
};


#endif