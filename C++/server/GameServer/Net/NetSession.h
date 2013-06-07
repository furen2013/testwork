#pragma once
#ifndef NETSESSION_H
#define NETSESSION_H
#include "MsgHead.pb.h"
#include "TypeDef.h"

class CGTSocket;
class NetSession;
struct OpcodeHandler
{
	uint16 status;
	void (NetSession::*handler)(MsgHead& Msg);
};

enum SessionStatus
{
	STATUS_AUTHED = 0,
	STATUS_LOGGEDIN
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
	void addMsg(MsgHead* msg);

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

	void HandleCreateFarmReq(MsgHead& Msg);
	void HandleCreateCellReq(MsgHead& Msg);
	void update(int time);
protected:
	OpcodeHandler* GetMsgOpcodeHandler(MsgType en);
protected:
	DWORD _account;
	CGTSocket* _socket;
	int _MsgNumber;
	Player* _player;
	
	std::queue<MsgHead*> _msgs;
	boost::mutex _msgslock;
	
};


#endif