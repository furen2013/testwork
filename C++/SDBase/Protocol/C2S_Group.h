#pragma once

#include "C2S.h"
namespace MSG_C2S
{

	struct stPartyMemberStat : public PakHead
	{
		stPartyMemberStat(){ wProNO = PARTY_MEMBER_STAT; }
		ui64	guid;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << guid; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> guid; return cpu; }
	};
	struct stGroupAccept : public PakHead
	{
		stGroupAccept(){ wProNO = GROUP_ACCEPT; }
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);return cpu; }
	};

	struct stGroupDecline : public PakHead
	{
		stGroupDecline(){ wProNO = GROUP_DECLINE; }
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);return cpu; }
	};

	struct stGroupCancel : public PakHead
	{
		stGroupCancel(){ wProNO = GROUP_CANCEL; }
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);return cpu; }
	};

	struct stGroupAssit : public PakHead
	{
		stGroupAssit(){ wProNO = GROUP_ASSISTANT_LEADER; }
		ui64	guid;
		ui8		flag;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << guid << flag; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> guid >> flag; return cpu; }
	};
	struct stPartyAssit : public PakHead
	{
		stPartyAssit(){ wProNO = PARTY_ASSIGNMENT; }
		ui64	guid;
		ui8		flag1;
		ui8		flag2;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << guid << flag1 << flag2; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> guid >> flag1 >> flag2; return cpu; }
	};

	struct stMiniMapPing : public PakHead
	{
		stMiniMapPing(){ wProNO = MINIMAP_PING; }
		float	x;
		float	y;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << x << y; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> x >> y; return cpu; }

	};
	
	struct stGroupLootMethod : public PakHead
	{
		stGroupLootMethod(){ wProNO = GROUP_LOOT_METHOD; }
		ui32 lootMethod;ui64 lootMaster;ui32 threshold;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << lootMethod << lootMaster << threshold; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> lootMethod >> lootMaster >> threshold; return cpu; }
	};
	struct stGroupSetPlayerIcon : public PakHead
	{
		stGroupSetPlayerIcon(){ wProNO = GROUP_SET_PLAYER_ICON; }
		uint64 guid;uint8 icon;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << guid << icon; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> guid >> icon; return cpu; }
	};

	//	���öӳ�
	struct stGroupSetLeader : public PakHead
	{
		stGroupSetLeader(){ wProNO = GROUP_SET_LEADER; }
		ui64	guid;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << guid; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> guid; return cpu; }

	};

	//	����,ֻ�жӳ�����
	struct stGroupUnviteGuid : PakHead
	{
		stGroupUnviteGuid(){ wProNO = GROUP_UNINVITE_GUID; }
		ui64	guid;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << guid; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> guid; return cpu; }

	};
	
	//	����,ֻ�жӳ�����
	struct stGroupUnviteName : public PakHead
	{
		stGroupUnviteName(){ wProNO = GROUP_UNINVITE_GUID; }
		string membername;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << membername; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> membername; return cpu; }

	};
	//	Ҫ�����
	struct stGroupInvite : public PakHead
	{
		stGroupInvite(){ wProNO = GROUP_INVITE; }
		string membername;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << membername; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> membername; return cpu; }
	};
	//	��ɢ����
	struct stGroupDisband : public PakHead
	{
		stGroupDisband(){ wProNO = GROUP_DISBAND; }
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu; return cpu; }

	};
	struct stGroup_Raid_Convert : public PakHead
	{
		//ת���Ŷ�
		stGroup_Raid_Convert(){ wProNO = GROUP_RAID_CONVERT; }
	};
	struct stGroup_Change_Sub_Group : public PakHead
	{
		//�л�����
		stGroup_Change_Sub_Group(){ wProNO = GROUP_CHANGE_SUB_GROUP; }
		std::string name;
		uint8 subGroup;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << name << subGroup; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> name >> subGroup; return cpu; }
	};



	struct stGroupSwep : public PakHead
	{
		stGroupSwep(){ wProNO = GROUP_SWEP_MEMBER; }
		ui64  srcguid;
		ui64  desguid;
		CPacketSn& Sn(CPacketSn& cps) const { PakHead::Sn(cps); cps << srcguid << desguid; return cps;}
		CPacketUsn& Usn(CPacketUsn& cpu) {PakHead::Usn(cpu);cpu >> srcguid >> desguid ; return cpu;}

	};

	struct stGroupSwepName : public PakHead
	{
		stGroupSwepName(){ wProNO = GROUP_SWEP_MEMBER_NAME; }
		std::string  src;
		std::string  des;
		CPacketSn& Sn(CPacketSn& cps) const { PakHead::Sn(cps); cps << src << des; return cps;}
		CPacketUsn& Usn(CPacketUsn& cpu) {PakHead::Usn(cpu);cpu >> src >> des ; return cpu;}

	};

	struct stGroup_Assistant_Leader : public PakHead
	{
		//���ø��ӳ�
		stGroup_Assistant_Leader(){ wProNO = GROUP_ASSISTANT_LEADER; }
		uint64 guid;
		uint8 on;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << guid << on; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> guid >> on; return cpu; }
	};
	struct stGroup_Promote : public PakHead
	{
		//����TANK
		stGroup_Promote(){ wProNO = GROUP_PROMOTE; }
		uint8 promotetype, on;
		uint64 guid;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << promotetype << on << guid; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> promotetype >> on >> guid; return cpu; }
	};
	struct stRaid_Request_Info : public PakHead
	{
		stRaid_Request_Info(){ wProNO = RAID_REQUEST_INFO; }
	};
	struct stRaid_ReadyCheck : public PakHead
	{
		//��λ.. ѯ��
		stRaid_ReadyCheck(){ wProNO = RAID_READYCHECK; }
		uint8 ready;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << ready; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> ready; return cpu; }
	};

}
