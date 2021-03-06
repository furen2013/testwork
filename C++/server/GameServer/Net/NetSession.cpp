#include "stdafx.h"
#include "NetSession.h"
#include "../net/GSocket.h"
#include "MessageFarmC2S.pb.h"
OpcodeHandler WorldPacketHandlers[C2S_GSEnd - C2S_GSBegin];

NetSession::NetSession(): _player(NULL)
{




}
NetSession::~NetSession()
{

}
void NetSession::addMsg(MsgHead* msg)
{
	boost::mutex::scoped_lock lock( _msgslock );
	_msgs.push(msg);
}

void NetSession::update(int time)
{
	boost::mutex::scoped_lock lock( _msgslock );
	while(!_msgs.empty())
	{
		MsgHead* p = _msgs.front();
		MsgHead head(*p);
		OpcodeHandler* handler = GetMsgOpcodeHandler(p->type());
		(this->*handler->handler)(*p);
		delete p;
		_msgs.pop();
	}
	

	
	//_msgs.pop()
}
void NetSession::sendMessage(::google::protobuf::Message* message, MsgType type)
{
	MsgHead msgHead;
	msgHead.set_type(type);
	msgHead.set_msgsize(message->ByteSize());
	msgHead.set_account(_account);
	std::string strTemp;
	message->SerializeToString(&strTemp);
	msgHead.set_body(strTemp);
	_socket->send_message(&msgHead);
}

void NetSession::InitHandleTable()
{
	_MsgNumber = C2S_GSEnd - C2S_GSBegin;
	for(uint32 i = 0; i < _MsgNumber; ++i)
	{
		WorldPacketHandlers[i].status = STATUS_LOGGEDIN;
		WorldPacketHandlers[i].handler = 0;
	}
	// farm msg
	GetMsgOpcodeHandler(C2S_MsgFarmStateReq)->handler = &NetSession::HandleFarmStateReq;
	GetMsgOpcodeHandler(C2S_MsgSeedCellReq)->handler = &NetSession::HandleSeedCellReq;
	GetMsgOpcodeHandler(C2S_MsgSpreadManureReq)->handler = &NetSession::HandleSpreadManureReq;
	GetMsgOpcodeHandler(C2S_MsgGatherPloughCellReq)->handler = &NetSession::HandleGatherPloughCellReq;
	GetMsgOpcodeHandler(C2S_MsgWaterCellReq)->handler = &NetSession::HandleWaterCellReq;
	GetMsgOpcodeHandler(C2S_MsgTechnologyStateReq)->handler = &NetSession::HandleTechnologyStateReq;
	GetMsgOpcodeHandler(C2S_MsgOpenTechLevelReq)->handler = &NetSession::HandleTechLevelReq;
	GetMsgOpcodeHandler(C2S_MsgApplyAddTechInfoReq)->handler = &NetSession::HandleTechnologyStateReq;
	GetMsgOpcodeHandler(C2S_MsgAddTechValueReq)->handler = &NetSession::HandleAddTechValueReq;
	GetMsgOpcodeHandler(C2S_MsgBuildMillReq)->handler = &NetSession::HandleBuildMillReq;
	GetMsgOpcodeHandler(C2S_MsgBuildWaterWayReq)->handler = &NetSession::HandleBuildWaterWayReq;
	GetMsgOpcodeHandler(C2S_MsgCreateFarmReq)->handler = &NetSession::HandleCreateFarmReq;
	GetMsgOpcodeHandler(C2S_MsgCreateCellReq)->handler = &NetSession::HandleCreateCellReq;
	
}

OpcodeHandler* NetSession::GetMsgOpcodeHandler(MsgType en)
{
	if (en > C2S_GSBegin && en < C2S_GSEnd)
	{
		return &WorldPacketHandlers[en - C2S_GSBegin];
	}
	return NULL;
}