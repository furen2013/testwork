#pragma once

#include "S2C.h"
namespace MSG_S2C
{
	struct stArenaTeam_Query_Response : public PakHead
	{
		stArenaTeam_Query_Response(){ wProNO = ARENA_TEAM_QUERY_RESPONSE; }
		ui32	teamid;
		string name;
		ui32	maxPlayer;
		ui32	emblemColour;
		ui32	emblemStyle;
		ui32	borderColour;
		ui32	borderStyle;
		ui32	backgroundColour;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << teamid << name << maxPlayer << emblemColour << emblemStyle << borderColour << borderStyle << backgroundColour;return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> teamid >> name >> maxPlayer >> emblemColour >> emblemStyle >> borderColour >> borderStyle >> backgroundColour;return cpu; }
	};
	struct stArenaTeam_Command_Result : public PakHead
	{
		stArenaTeam_Command_Result(){ wProNO = ARENA_TEAM_COMMAND_RESULT; }
		ItemPrototype type;
		string name;
		string desc;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps.AddBuf(&type, sizeof(type)); cps << name << desc;return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu.GetBuf(&type, sizeof(type)); cpu >> name >> desc;return cpu; }
	};
	struct stArenaTeam_Roster : public PakHead
	{
		stArenaTeam_Roster(){ wProNO = ARENA_TEAM_ROSTER; }
		ui32	teamid;
		ui32	maxplayer_count;
		struct stPlayer
		{
			stPlayer(ui64 id,ui8 login,string nm,ui8 leader,ui8 lv,ui8 cl, ui32 PTW, ui32 WTW, ui32 PTS, ui32 WTS, ui32 sr):guid(id),bLogin(login),name(nm),bLeader(leader)
			,level(lv),nclass(cl),Played_ThisWeek(PTW),Won_ThisWeek(WTW),Played_ThisSeason(PTS),Won_ThisSeason(WTS),stat_rating(sr){}
			stPlayer(){}
			ui64 guid;
			ui8	bLogin;
			string name;
			ui8 bLeader;
			ui8 level;
			ui8	nclass;
			uint32 Played_ThisWeek;
			uint32 Won_ThisWeek;
			uint32 Played_ThisSeason;
			uint32 Won_ThisSeason;
			uint32 stat_rating;
			CPacketSn& Sn(CPacketSn& cps) const {	cps << guid << bLogin << name << bLeader << level << nclass << Played_ThisWeek << Won_ThisWeek << Played_ThisSeason << Won_ThisSeason << stat_rating;return cps; }
			CPacketUsn& Usn(CPacketUsn& cpu)	{	cpu >> guid >> bLogin >> name >> bLeader >> level >> nclass >> Played_ThisWeek >> Won_ThisWeek >> Played_ThisSeason >> Won_ThisSeason >> stat_rating;return cpu; }
		};
		vector<stPlayer> vMembers;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << teamid << maxplayer_count << vMembers;return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> teamid >> maxplayer_count >> vMembers;return cpu; }
	};
	struct stArenaTeam_Invite : public PakHead
	{
		stArenaTeam_Invite(){ wProNO = ARENA_TEAM_INVITE; }
		string player_name;
		string team_name;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << player_name << team_name;return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> player_name >> team_name;return cpu; }
	};
	struct stArenaTeam_Stats : public PakHead
	{
		stArenaTeam_Stats(){ wProNO = ARENA_TEAM_STATS; }
		uint32 id;
		uint32 stat_rating;
		uint32 stat_gamesplayedweek;
		uint32 stat_gameswonweek;
		uint32 stat_gamesplayedseason;
		uint32 stat_gameswonseason;
		uint32 stat_ranking;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << id << stat_rating << stat_gamesplayedweek << stat_gameswonweek << stat_gamesplayedseason << stat_gameswonseason << stat_ranking;return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> id >> stat_rating >> stat_gamesplayedweek >> stat_gameswonweek >> stat_gamesplayedseason >> stat_gameswonseason >> stat_ranking;return cpu; }
	};
}
