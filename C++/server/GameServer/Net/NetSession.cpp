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
	
}

OpcodeHandler* NetSession::GetMsgOpcodeHandler(MsgType en)
{
	if (en > C2S_GSBegin && en < C2S_GSEnd)
	{
		return &WorldPacketHandlers[en - C2S_GSBegin];
	}
	return NULL;
}