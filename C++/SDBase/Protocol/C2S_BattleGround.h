#pragma once

#include "C2S.h"
namespace MSG_C2S
{
	struct stBG_Port : public PakHead
	{
		stBG_Port(){ wProNO = BATTLEFIELD_PORT; }
		uint16 mapinfo, unk;
		uint8 action;
		uint32 bgtype;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << mapinfo<<unk<<action<<bgtype; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> mapinfo>>unk>>action>>bgtype; return cpu; }
	};
	struct stBG_Stat : public PakHead
	{
		stBG_Stat(){ wProNO = BATTLEFIELD_STATUS; }
	};
	struct stBG_List : public PakHead
	{
		stBG_List(){ wProNO = BATTLEFIELD_LIST; }
		uint64 guid;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << guid; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> guid; return cpu; }
	};
	struct stBG_Master_Hello : public PakHead
	{
		stBG_Master_Hello(){ wProNO = BATTLEMASTER_HELLO; }
		uint64 guid;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << guid; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> guid; return cpu; }
	};
	struct stBG_Player_Positions : public PakHead
	{
		stBG_Player_Positions(){ wProNO = BATTLEGROUND_PLAYER_POSITIONS; }
	};
	struct stBG_Master_Join : public PakHead
	{
		stBG_Master_Join(){ wProNO = BATTLEMASTER_JOIN; }
		uint64 guid;
		uint32 bgtype;
		uint32 instance;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << guid<<bgtype<<instance; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> guid>>bgtype>>instance; return cpu; }
	};
	struct stArena_Join : public PakHead
	{
		stArena_Join(){ wProNO = ARENA_JOIN; }
		uint64 guid;
		uint8 arenacategory;
		uint8 as_group;
		uint8 rated_match;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << guid<<arenacategory<<as_group<<rated_match; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> guid>>arenacategory>>as_group>>rated_match; return cpu; }
	};
	struct stInspect_Honor_Stats : public PakHead
	{
		stInspect_Honor_Stats(){ wProNO = INSPECT_HONOR_STATS; }
		uint64 guid;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << guid; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> guid; return cpu; }
	};
	struct stInspect_Arena_Stats : public PakHead
	{
		stInspect_Arena_Stats(){ wProNO = INSPECT_ARENA_STATS; }
		uint64 guid;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << guid; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> guid; return cpu; }
	};
	struct stPVP_Log_Data : public PakHead
	{
		stPVP_Log_Data(){ wProNO = PVP_LOG_DATA; }
	};
	struct stBG_Move_Spline_Done: public PakHead
	{
		stBG_Move_Spline_Done(){ wProNO = CMSG_MOVE_SPLINE_DONE; }
	};
	struct stArea_Spirit_Healer_Queue : PakHead
	{
		stArea_Spirit_Healer_Queue(){ wProNO = AREA_SPIRIT_HEALER_QUEUE; }
		uint64	guid;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << guid; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> guid; return cpu; }
	};	
	struct stArea_Spirit_Healer_Query : PakHead
	{
		stArea_Spirit_Healer_Query(){ wProNO = AREA_SPIRIT_HEALER_QUERY; }
		uint64	guid;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << guid; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> guid; return cpu; }
	};	

}
