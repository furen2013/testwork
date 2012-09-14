#pragma once
#include "../../../SDBase/Protocol/PacketDef.h"

namespace MSG_GS2MS
{	
	using namespace SDBase;
	enum
	{
		GS_REGISTER		= MSG_BASE_GS2MS,		
		GS_UNREGISTER,
		PROXY_MSG,		//请求MS转发消息
		PLAYER_ENTER,	//玩家进入游戏
		PLAYER_LEAVE,	//玩家退出游戏
		PLAYER_JUMP,	//玩家切换场景服务器
	};

	struct stRegister : public PakHead 
	{
		stRegister(){ wProNO = GS_REGISTER; }
		ui32	gsidx;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << gsidx; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> gsidx; return cpu; }
	};

	struct stUnRegister : public PakHead 
	{
		stUnRegister(){ wProNO = GS_UNREGISTER; }
		ui32	gsidx;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << gsidx; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> gsidx; return cpu; }
	};

	struct stPlayerEnter : public PakHead 
	{
		stPlayerEnter(){ wProNO = PLAYER_ENTER; }
		ui64	player_guid;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << player_guid; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> player_guid; return cpu; }
	};
	struct stPlayerLeave : public PakHead 
	{
		stPlayerLeave(){ wProNO = PLAYER_LEAVE; }
		ui64	player_guid;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << player_guid; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> player_guid; return cpu; }
	};
	struct stPlayerJump : public PakHead 
	{
		stPlayerJump(){ wProNO = PLAYER_JUMP; }
		ui64	player_guid;
		ui32	togs;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << player_guid << togs; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> player_guid >> togs; return cpu; }
	};

	//enum PROXY_MSG_ID
	//{
	//	MSG_SOCIAL_SENDFRIENDLIST,
	//	MSG_SOCIAL_SETNOTE,
	//	MSG_SOCIAL_ADDFRIEND,
	//	MSG_SOCIAL_REMOVEFRIEND,
	//	MSG_SOCIAL_ADDIGNORE,
	//	MSG_SOCIAL_REMOVEIGNORE,
	//	

	//};

}