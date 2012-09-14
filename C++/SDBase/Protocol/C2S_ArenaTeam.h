#pragma once
#include "C2S.h"
namespace MSG_C2S
{
	struct stArenaTeam_Roster : public PakHead
	{
		stArenaTeam_Roster(){ wProNO = ARENA_TEAM_ROSTER; }
		uint32 teamId;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << teamId; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> teamId; return cpu; }
	};
	struct stArenaTeam_Query : public PakHead
	{
		stArenaTeam_Query(){ wProNO = ARENA_TEAM_QUERY; }
		uint32 teamId;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << teamId; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> teamId; return cpu; }
	};
	struct stArenaTeam_AddMember : public PakHead
	{
		stArenaTeam_AddMember(){ wProNO = ARENA_TEAM_ADD_MEMBER; }
		string player_name;
		uint32 teamId;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << teamId << player_name; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> teamId >> player_name; return cpu; }
	};
	struct stArenaTeam_Invite_Accept : public PakHead
	{
		stArenaTeam_Invite_Accept(){ wProNO = ARENA_TEAM_INVITE_ACCEPT; }
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);return cpu; }
	};
	struct stArenaTeam_Invite_Decline : public PakHead
	{
		stArenaTeam_Invite_Decline(){ wProNO = ARENA_TEAM_INVITE_DECLINE; }
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps);return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);return cpu; }
	};
	struct stArenaTeam_Leave : public PakHead
	{
		stArenaTeam_Leave(){ wProNO = ARENA_TEAM_LEAVE; }
		uint32 teamId;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << teamId; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> teamId; return cpu; }
	};
	struct stArenaTeam_Remove_Player : public PakHead
	{
		stArenaTeam_Remove_Player(){ wProNO = ARENA_TEAM_REMOVE_PLAYER; }
		uint32 teamId;
		string name;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << teamId << name; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> teamId >> name; return cpu; }
	};
	struct stArenaTeam_Disband : public PakHead
	{
		stArenaTeam_Disband(){ wProNO = ARENA_TEAM_DISBAND; }
		uint32 teamId;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << teamId; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> teamId; return cpu; }
	};
	struct stArenaTeam_Promote : public PakHead
	{
		stArenaTeam_Promote(){ wProNO = ARENA_TEAM_PROMOTE; }
		uint32 teamId;
		string name;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << teamId << name; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> teamId >> name; return cpu; }
	};
	
}