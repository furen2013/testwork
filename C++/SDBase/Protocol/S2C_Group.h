#pragma once

#include "S2C.h"
namespace MSG_S2C
{
	//	队伍解散
	struct stGroupDestroyed : public PakHead
	{
		stGroupDestroyed(){ wProNO = GROUP_DESTROYED; }

		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);return cpu; }

	};
	//	设置队长
	struct stGroupSetLeader : public PakHead
	{
		stGroupSetLeader(){ wProNO = GROUP_SET_LEADER; }
		string	name;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << name; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> name; return cpu; }
	};
	struct stGroupSetPlayerIcon : public PakHead
	{
		stGroupSetPlayerIcon(){ wProNO = GROUP_SET_PLAYER_ICON; }
		uint64 guid;uint8 icon;
		uint64 m_targetIcons[8];
		int m_targetUniqueID[8];
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << guid << icon; cps.AddBuf(m_targetIcons, sizeof(m_targetIcons)); cps.AddBuf(m_targetUniqueID, sizeof(m_targetUniqueID)); return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> guid >> icon; cpu.GetBuf(m_targetIcons, sizeof(m_targetIcons)); cpu.GetBuf(m_targetUniqueID, sizeof(m_targetUniqueID)); return cpu; }
	};
	//	队伍成员列表
	struct stGroupList : public PakHead
	{
		stGroupList(){ wProNO = GROUP_LIST; }
		ui8		grouptype;
		ui8		groupid;
		ui8		flag;
		ui32	membercount;
		ui8		subgroupcount;
		ui64	leaderguid;
		ui8		lootmethod;
		ui64	looterguid;
		ui8		lootthreshold;
		ui8		difficulty;
		string	data;
		struct stMember
		{
			uint32 guid;
			std::string name;
			uint8 Race;
			uint8 Class;
			uint8 Gender;
			uint8 flags;
			uint8 isloggedin;
			ui32  level;
			uint32 equiphead[4];//0普通头盔,1怪物头盔,2普通胸甲,3怪物上衣
			CPacketSn& Sn(CPacketSn& cps) const { cps << guid << name << Race << Class << Gender << flags << isloggedin<<level; cps.AddBuf(equiphead, sizeof(equiphead)); return cps; }
			CPacketUsn& Usn(CPacketUsn& cpu)	{ cpu >> guid >> name >> Race >> Class >> Gender >> flags >> isloggedin>>level; cpu.GetBuf(equiphead, sizeof(equiphead)); return cpu; }
		};
		struct stSubGroup
		{
			uint8 ID;
			std::vector<stMember> vMembers;
			CPacketSn& Sn(CPacketSn& cps) const { cps << ID << vMembers;  return cps; }
			CPacketUsn& Usn(CPacketUsn& cpu)	{ cpu >> ID >> vMembers;  return cpu; }
		};
		std::vector<stSubGroup> vSubGroups;

		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << grouptype << groupid << flag << membercount << subgroupcount << leaderguid << lootmethod << looterguid << lootthreshold << difficulty << data << vSubGroups; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> grouptype >> groupid >> flag >> membercount >> subgroupcount >> leaderguid >> lootmethod >> looterguid >> lootthreshold >> difficulty >> data >> vSubGroups; return cpu; }
	};

	struct stGroupUninvite : public PakHead
	{
		stGroupUninvite(){ wProNO = GROUP_UNINVITE; }

		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);return cpu; }

	};
	//	邀请组队
	struct stGroupInvite : public PakHead
	{
		stGroupInvite(){ wProNO = GROUP_INVITE; }
		string name;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << name;  return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> name;  return cpu; }
	};

	//	拒绝邀请
	struct stGroupDecline : public PakHead
	{
		stGroupDecline(){ wProNO = GROUP_DECLINE; }
		string name;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << name;  return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> name;  return cpu; }
	};
	//	队伍成员状态更新
	struct stPartyMemberStat : public PakHead
	{
		stPartyMemberStat(){ wProNO = PARTY_MEMBER_STATS; }
		ui64	guid;
		ui32	mask;
		string	data;

		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << guid << mask << data; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> guid >> mask >> data; return cpu; }

	};
	struct stGroupMemberStat : public PakHead
	{
		stGroupMemberStat(){ wProNO = GROUP_MEMBER_STAT; }
		ui64	guid;
		ui32	mask;
		string	data;

		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << guid << mask << data; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> guid >> mask >> data; return cpu; }

	};

	struct stMiniMapPing : public PakHead
	{
		stMiniMapPing(){ wProNO = MINIMAP_PING; }
		ui64	guid;
		float	x;
		float	y;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << guid << x << y; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> guid >> x >> y; return cpu; }

	};

	struct stGroupSwep : public PakHead
	{
		stGroupSwep() {wProNO = MSG_GROUP_SWEP;}
		uint64 guiddes;
		uint64 guidsrc;
		CPacketSn& Sn(CPacketSn& cps) const {PakHead::Sn(cps); cps << guiddes << guidsrc; return cps;}
		CPacketUsn& Usn(CPacketUsn& cpu) {PakHead::Usn(cpu); cpu >> guiddes >> guidsrc; return cpu;}
		
	};

	struct stGroupChangeSubgroup : public PakHead
	{
		stGroupChangeSubgroup() {wProNO = MSG_CHANGE_SUBGROUP; }
		uint64 guid;
		uint8 team;
		CPacketSn& Sn(CPacketSn& cps) const {PakHead::Sn(cps); cps << guid << team; return cps;}
		CPacketUsn& Usn(CPacketUsn& cpu) {PakHead::Usn(cpu); cpu >> guid >> team; return cpu;}

	};

	struct stGroupAddMember : public PakHead
	{
		stGroupAddMember() {wProNO = MSG_ADD_MEMBER; }
		struct stMember
		{
			uint32 guid;
			std::string name;
			uint8 Race;
			uint8 Class;
			uint8 Gender;
			uint8 flags;
			uint8 isloggedin;
			ui32  level;
			uint32 equiphead[4];//0普通头盔,1怪物头盔,2普通胸甲,3怪物上衣
			CPacketSn& Sn(CPacketSn& cps) const { cps << guid << name << Race << Class << Gender << flags << isloggedin<<level; cps.AddBuf(equiphead, sizeof(equiphead)); return cps; }
			CPacketUsn& Usn(CPacketUsn& cpu)	{ cpu >> guid >> name >> Race >> Class >> Gender >> flags >> isloggedin>>level; cpu.GetBuf(equiphead, sizeof(equiphead)); return cpu; }
		};
		uint8 SubTeam;
		stMember NewMember;

		CPacketSn& Sn(CPacketSn& cps) const {PakHead::Sn(cps);cps << SubTeam << NewMember; return cps;}
		CPacketUsn& Usn(CPacketUsn& cpu) {PakHead::Usn(cpu);cpu >> SubTeam >> NewMember; return cpu;}

	};

	struct stGroupRemoveMember : public PakHead
	{
		stGroupRemoveMember() {wProNO = MSG_REMOVE_MEMBER; }
		uint64 guid;

		CPacketSn& Sn(CPacketSn& cps) const {PakHead::Sn(cps); cps << guid; return cps;}
		CPacketUsn& Usn(CPacketUsn& cpu) {PakHead::Usn(cpu); cpu >> guid; return cpu;}

	};


	struct stParty_Command_Result : public PakHead
	{
		stParty_Command_Result(){ wProNO = PARTY_COMMAND_RESULT; }
		ui32	op;				//	enum PartyOperation
		string	member;
		ui32	res;			//	enum PartyResult

		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << op << member << res;  return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> op >> member >> res;  return cpu; }
	};
	struct stParty_Kill_Log : public PakHead
	{
		stParty_Kill_Log(){ wProNO = PARTY_KILL_LOG; }
		ui64	playerguid;
		ui64	unitguid;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << playerguid << unitguid;  return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> playerguid >> unitguid;  return cpu; }
	};

	struct stGuild_Event : public PakHead
	{
		stGuild_Event(){ wProNO = GUILD_EVENT; }
		ui8		guild_event;
		vector<string> vStrs;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << guild_event << vStrs;  return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> guild_event >> vStrs;  return cpu; }
	};
	struct stRaid_ReadyCheck : public PakHead
	{
		stRaid_ReadyCheck(){ wProNO = RAID_READYCHECK; }
		ui64	player_guid;
		uint8 ready;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << player_guid << ready; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> player_guid >> ready; return cpu; }
	};

}
