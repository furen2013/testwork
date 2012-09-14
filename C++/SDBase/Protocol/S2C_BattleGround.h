#pragma once

#include "S2C.h"

namespace MSG_S2C
{
	struct stArea_Spirit_Healer_Time : PakHead
	{
		stArea_Spirit_Healer_Time(){ wProNO = AREA_SPIRIT_HEALER_TIME; }
		uint64	guid;
		ui32	restime;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << guid << restime; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> guid >> restime; return cpu; }
	};	

	struct stInspect_Arena_Stats : public PakHead
	{
		stInspect_Arena_Stats(){ wProNO = INSPECT_ARENA_STATS; }
		uint64 guid;
		ui32 team_type;
		ui32 team_id;
		ui32 stat_rating;
		ui32 gamesplayedweek;
		ui32 gameswonweek;
		ui32 gamesplayedseason;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << guid<<team_type<<team_id<<stat_rating<<gamesplayedweek<<gameswonweek<<gamesplayedseason; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> guid>>team_type>>team_id>>stat_rating>>gamesplayedweek>>gameswonweek>>gamesplayedseason; return cpu; }
	};
	struct stPVP_Log_Data : public PakHead
	{
		stPVP_Log_Data(){ wProNO = PVP_LOG_DATA; }
	};
	struct stBG_Player_Joined : public PakHead
	{
		stBG_Player_Joined(){ wProNO = BATTLEGROUND_PLAYER_JOINED; }
		uint64 guid;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << guid; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> guid; return cpu; }
	};
	struct stBG_Stats : public PakHead
	{
		stBG_Stats(){ wProNO = BATTLEFIELD_STATUS; }
		ui8		Status;
		uint32 bgTeam;
		uint32 BGType;
		ui32	InstanceID;
		ui32	RatedMatch;
		ui32	mapid;
		ui32	time;

		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps <<Status<<bgTeam<< BGType<<InstanceID<<RatedMatch<<mapid<<time; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >>Status>>bgTeam>> BGType>>InstanceID>>RatedMatch>>mapid>>time; return cpu; }
	};
	struct stBG_Player_Left : public PakHead
	{
		stBG_Player_Left(){ wProNO = BATTLEGROUND_PLAYER_LEFT; }
		uint64 guid;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << guid; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> guid; return cpu; }
	};
	struct stInspect_Honor_Stats : public PakHead
	{
		stInspect_Honor_Stats(){ wProNO = INSPECT_HONOR_STATS; }
		uint64 guid;
		ui32	honor_currency;
		ui32	kills;
		ui32	today_contribution;
		ui32	yestoday_contribution;
		ui32	lifetime_honor_kills;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << guid<<honor_currency<<kills<<today_contribution<<yestoday_contribution<<lifetime_honor_kills; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> guid>>honor_currency>>kills>>today_contribution>>yestoday_contribution>>lifetime_honor_kills; return cpu; }
	};

	struct stBG_Init_World_States : public PakHead
	{
		stBG_Init_World_States(){ wProNO = BATTLEGROUND_INIT_WORLD_STATES; }
		ui32	mapid;
		ui32	flag1,flag2;
		struct stStat
		{
			ui32 index;
			ui32 value;
			CPacketSn& Sn(CPacketSn& cps) const {	cps << index<<value; return cps; }
			CPacketUsn& Usn(CPacketUsn& cpu)	{	cpu >> index>>value; return cpu; }
		};
		vector<stStat> vStats;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps <<mapid<<flag1<<flag2<<vStats; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >>mapid>>flag1>>flag2>>vStats; return cpu; }
	};
	struct stBG_Update_World_States : public PakHead
	{
		stBG_Update_World_States(){ wProNO = BATTLEGROUN_UPDATE_WORLD_STATE; }
		ui32 index;
		ui32 value;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << index<<value; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> index>>value; return cpu; }
	};
	struct stBG_List : public PakHead
	{
		stBG_List(){ wProNO = BATTLEFIELD_LIST; }
		ui64	guid;
		uint32 BattlegroundType;
		vector<ui32> vBGs;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << guid<<BattlegroundType<<vBGs; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> guid>>BattlegroundType>>vBGs; return cpu; }
	};
	struct stBG_Group_Joined : public PakHead
	{
		stBG_Group_Joined(){ wProNO = BATTLEGROUND_GROUP_JOINED; }
	};

	
}
