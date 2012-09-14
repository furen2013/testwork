#pragma once

#include "C2S.h"
namespace MSG_C2S
{
	//查询公会信息
	struct stGuild_Query : public PakHead
	{
		stGuild_Query(){ wProNO = GUILD_QUERY; }
		ui32	guild_id;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << guild_id; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> guild_id; return cpu; }
	};
	//创建公会
	struct stGuild_Create : public PakHead
	{
		stGuild_Create(){ wProNO = GUILD_CREATE; }
		//ui32	guild_id;
		string guild_name;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << guild_name; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> guild_name; return cpu; }
	};
	//邀请加入公会
	struct stGuild_Invite : public PakHead
	{
		stGuild_Invite(){ wProNO = GUILD_INVITE; }
		string inviteeName;//邀请方的名字
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << inviteeName; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> inviteeName; return cpu; }
	};
	//收到stGuild_Invite后,被邀请方的回复消息
	struct stGuild_Accept : public PakHead
	{
		stGuild_Accept(){ wProNO = GUILD_ACCEPT; }
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);return cpu; }
	};
	//收到stGuild_Invite后,被邀请方的回复消息
	struct stGuild_Decline : public PakHead
	{
		stGuild_Decline(){ wProNO = GUILD_DECLINE; }
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);return cpu; }
	};
	struct stGuild_Info : public PakHead
	{
		stGuild_Info(){ wProNO = GUILD_INFO; }
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);return cpu; }
	};
	struct stGuild_Roster : public PakHead
	{
		stGuild_Roster(){ wProNO = GUILD_ROSTER; }
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);return cpu; }
	};
	struct stGuild_Leave : public PakHead
	{
		stGuild_Leave(){ wProNO = GUILD_LEAVE; }
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);return cpu; }
	};
	struct stGuild_Disband : public PakHead
	{
		stGuild_Disband(){ wProNO = GUILD_DISBAND; }
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);return cpu; }
	};
	//设置公会介绍
	struct stGuild_Set_Info : public PakHead
	{
		stGuild_Set_Info(){ wProNO = GUILD_SET_INFORMATION; }
		string NewGuildInfo;;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << NewGuildInfo; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> NewGuildInfo; return cpu; }
	};
	//提升成员
	struct stGuild_Promote : public PakHead
	{
		stGuild_Promote(){ wProNO = GUILD_PROMOTE; }
		string name;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << name; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> name; return cpu; }
	};
	//降低成员
	struct stGuild_Demote : public PakHead
	{
		stGuild_Demote(){ wProNO = GUILD_DEMOTE; }
		string name;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << name; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> name; return cpu; }
	};
	//删除成员
	struct stGuild_Remove : public PakHead
	{
		stGuild_Remove(){ wProNO = GUILD_REMOVE; }
		string name;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << name; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> name; return cpu; }
	};
	//设置公会会长
	struct stGuild_Set_Leader : public PakHead
	{
		stGuild_Set_Leader(){ wProNO = GUILD_LEADER; }
		string name;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << name; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> name; return cpu; }
	};
	struct stGuild_Set_Motd : public PakHead
	{
		stGuild_Set_Motd(){ wProNO = GUILD_MOTD; }
		string motd;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << motd; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> motd; return cpu; }
	};
	//设置公会职位
	struct stGuild_Set_Bank : public PakHead
	{
		stGuild_Set_Bank(){ wProNO = GUILD_RANK; }
		uint32 rankId;
		string newName;
		uint32 iRights;
		int32 iGoldLimitPerDay;
		struct stPermission
		{
			uint32 iFlags;
			int32 iStacksPerDay;
		}Permissions[MAX_GUILD_BANK_TABS];
		CPacketSn& Sn(CPacketSn& cps) const 
		{
			PakHead::Sn(cps); 
			cps << rankId << newName << iRights << iGoldLimitPerDay;
			for( uint8 i = 0; i < MAX_GUILD_BANK_TABS; i++ )
			{
				cps << Permissions[0].iFlags;
				cps << Permissions[1].iStacksPerDay;
			};
			return cps; 
		}
		CPacketUsn& Usn(CPacketUsn& cpu)	
		{
			PakHead::Usn(cpu);
			cpu >> rankId >> newName >> iRights >> iGoldLimitPerDay; 
			for( uint32 i = 0; i < MAX_GUILD_BANK_TABS; i++ )
			{
				cpu >> Permissions[0].iFlags;
				cpu >> Permissions[1].iStacksPerDay;
			};
			return cpu; 
		}
	};
	//增加公会职位
	struct stGuild_Add_Rank : public PakHead
	{
		stGuild_Add_Rank(){ wProNO = GUILD_ADD_RANK; }
		string rankName;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << rankName; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> rankName; return cpu; }
	};
	//删除公会职位
	struct stGuild_Del_Rank : public PakHead
	{
		stGuild_Del_Rank(){ wProNO = GUILD_DEL_RANK; }
		string rankName;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << rankName; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> rankName; return cpu; }
	};
	struct stGuild_Set_Public_Note : public PakHead
	{
		stGuild_Set_Public_Note(){ wProNO = GUILD_SET_PUBLIC_NOTE; }
		string target, newnote;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << target << newnote; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> target >> newnote; return cpu; }
	};
	struct stGuild_Set_Officer_Note : public PakHead
	{
		stGuild_Set_Officer_Note(){ wProNO = GUILD_SET_OFFICER_NOTE; }
		string target, newnote;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << target << newnote; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> target >> newnote; return cpu; }
	};
	struct stGuild_Save_Emblem : public PakHead
	{
		stGuild_Save_Emblem(){ wProNO = GUILD_SAVE_EMBLEM; }
		uint64 guid;
		uint32 emblemStyle, emblemColor, borderStyle, borderColor, backgroundColor;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << guid << emblemStyle << emblemColor<<borderStyle<<borderColor<<backgroundColor; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> guid >> emblemStyle >> emblemColor>>borderStyle>>borderColor>>backgroundColor; return cpu; }
	};
	struct stGuild_Petition_Buy : public PakHead
	{
		stGuild_Petition_Buy(){ wProNO = GUILD_PETITION_BUY; }
		uint64 creature_guid;
		string name;
		ui32 arena_index;
		uint64 crap;
		uint32 crap2;
		uint32 crap3,crap4,crap5,crap6,crap7,crap8,crap9,crap10,crap11,crap12;
		uint16 crap13;
		uint8 crap14;
		uint32 crap15;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << creature_guid << name << arena_index; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> creature_guid >> name >> arena_index; return cpu; }
	};
	struct stGuild_Petition_Show_Sign : public PakHead
	{
		stGuild_Petition_Show_Sign(){ wProNO = GUILD_PETITION_SHOW_SIGNATURES; }
		uint64 item_guid;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << item_guid; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> item_guid; return cpu; }
	};
	struct stGuild_Petition_Query : public PakHead
	{
		stGuild_Petition_Query(){ wProNO = GUILD_PETITION_QUERY; }
		uint32 charter_id;
		uint64 item_guid;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << charter_id << item_guid; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> charter_id >> item_guid; return cpu; }
	};
	struct stGuild_Petition_Sign : public PakHead
	{
		stGuild_Petition_Sign(){ wProNO = GUILD_PETITION_SIGN; }
		uint64 item_guid;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << item_guid; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> item_guid; return cpu; }
	};
	struct stGuild_Turn_In_Petition : public PakHead
	{
		stGuild_Turn_In_Petition(){ wProNO = GUILD_TURN_IN_PETITION; }
		uint64 mooguid;
		uint32 icon, iconcolor, bordercolor, border, background;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << mooguid << icon<<iconcolor<<bordercolor<<border<<background; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> mooguid >> icon>>iconcolor>>bordercolor>>border>>background; return cpu; }
	};
	struct stGuild_Petition_Rename : public PakHead
	{
		stGuild_Petition_Rename(){ wProNO = GUILD_PETITION_RENAME; }
		uint64 guid;
		string name;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << guid << name; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> guid >> name; return cpu; }
	};
	struct stGuild_Offer_Petition : public PakHead
	{
		stGuild_Offer_Petition(){ wProNO = GUILD_OFFER_PETITION; }
		uint32 shit;
		uint64 item_guid, target_guid;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << shit << item_guid << target_guid; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> shit >> item_guid >> target_guid; return cpu; }
	};
	struct stGuild_Bank_Purchase_Tab : public PakHead
	{
		stGuild_Bank_Purchase_Tab(){ wProNO = GUILD_BANK_PURCHASE_TAB; }
		uint64 guid;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << guid; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> guid; return cpu; }
	};
	struct stGuild_Bank_Get_Abailable_Amound : public PakHead
	{
		stGuild_Bank_Get_Abailable_Amound(){ wProNO = GUILD_BANK_GET_AVAILABLE_AMOUNT; }
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);return cpu; }
	};
	struct stGuild_Bank_Modify_Tab : public PakHead
	{
		stGuild_Bank_Modify_Tab(){ wProNO = GUILD_BANK_MODIFY_TAB; }
		uint64 guid;
		uint8 slot;
		string tabname;
		string tabicon;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << guid << slot<<tabname<<tabicon; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> guid >> slot>>tabname>>tabicon; return cpu; }
	};
	struct stGuild_Bank_Withdraw_Money : public PakHead
	{
		stGuild_Bank_Withdraw_Money(){ wProNO = GUILD_BANK_WITHDRAW_MONEY; }
		uint64 guid;
		uint32 money;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << guid << money; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> guid >> money; return cpu; }
	};
	struct stGuild_Bank_Deposit_Money : public PakHead
	{
		stGuild_Bank_Deposit_Money(){ wProNO = GUILD_BANK_DEPOSIT_MONEY; }
		uint64 guid;
		uint32 money;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << guid << money; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> guid >> money; return cpu; }
	};

	struct stGuild_Bank_Deposit_Item : public PakHead
	{
		stGuild_Bank_Deposit_Item(){ wProNO = GUILD_BANK_DEPOSIT_ITEM; }
		uint64 guid;
		uint8 source_isfrombank;
		uint8 dest_bank;
		uint8 dest_bankslot;
		uint32 wtf;

		uint8 source_bank;
		uint8 source_bankslot;

		uint8 source_bagslot;
		uint8 source_slot;
		uint8 wtf2;
		uint8 wtf3;
		uint8 withdraw_stack;
		uint8 deposit_stack;

		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << guid << source_isfrombank << dest_bank << dest_bankslot << wtf
			<< source_bank << source_bankslot
			<< source_bagslot << source_slot << wtf2 << wtf3 << withdraw_stack << dest_bankslot; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> guid >> source_isfrombank >> dest_bank >> dest_bankslot >> wtf
			>> source_bank >> source_bankslot
			>> source_bagslot >> source_slot >> wtf2 >> wtf3 >> withdraw_stack >> deposit_stack; return cpu; }
	};
	struct stGuild_Bank_Open : public PakHead
	{
		stGuild_Bank_Open(){ wProNO = GUILD_BANK_OPEN; }
		uint64 guid;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << guid; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> guid; return cpu; }
	};
	struct stGuild_Bank_View_Tab : public PakHead
	{
		stGuild_Bank_View_Tab(){ wProNO = GUILD_BANK_VIEW_TAB; }
		uint64 guid;
		uint8 tabid;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << guid << tabid; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> guid >> tabid; return cpu; }
	};
	struct stGuild_Get_Full_Permissions : public PakHead
	{
		stGuild_Get_Full_Permissions(){ wProNO = GUILD_GET_FULL_PERMISSIONS; }
	};
	struct stGuild_Bank_Log : public PakHead
	{
		stGuild_Bank_Log(){ wProNO = GUILD_BANK_LOG; }
		uint8 slotid;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << slotid; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> slotid; return cpu; }
	};

	struct stFriend_List : public PakHead
	{
		stFriend_List(){ wProNO = FRIEND_LIST; }
		uint32 flag;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << flag; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> flag; return cpu; }
	};
	struct stFriend_Add : public PakHead
	{
		stFriend_Add(){ wProNO = FRIEND_ADD; }
		string name, note;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << name << note; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> name >> note; return cpu; }
	};
	struct stFriend_Del : public PakHead
	{
		stFriend_Del(){ wProNO = FRIEND_DEL; }
		uint64 FriendGuid;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << FriendGuid; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> FriendGuid; return cpu; }
	};
	struct stFriend_Set_Note : public PakHead
	{
		stFriend_Set_Note(){ wProNO = FRIEND_SET_NOTE; }
		uint64 guid;
		string note;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << guid << note; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> guid >> note; return cpu; }
	};
	struct stFriend_Add_Ignore : public PakHead
	{
		stFriend_Add_Ignore(){ wProNO = FRIEND_ADD_IGNORE; }
		string ignore_name;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << ignore_name; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> ignore_name; return cpu; }
	};
	struct stFriend_Del_Ignore : public PakHead
	{
		stFriend_Del_Ignore(){ wProNO = FRIEND_DEL_IGNORE; }
		uint64 IgnoreGuid;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << IgnoreGuid; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> IgnoreGuid; return cpu; }
	};
	struct stGuildSetMemberRank : public PakHead
	{
		stGuildSetMemberRank() { wProNO = GUILD_SET_MEMBER_RANK; }
		std::string member;
		uint8 rank;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << member << rank; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> member >> rank; return cpu; }
	};
	struct stQueryGuildListReq : public PakHead
	{
		stQueryGuildListReq() { wProNO = GUILD_QUERY_GUILD_LIST_REQ; }
	};
	struct stGuildDeclareWar : public PakHead
	{
		stGuildDeclareWar() { wProNO = GUILD_DECLARE_WAR; }
		uint32 hostileguild;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << hostileguild; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> hostileguild; return cpu; }
	};

	struct stGuildAllyReq : public PakHead
	{
		stGuildAllyReq() { wProNO = GUILD_ALLY_REQ; }
		uint32 allianceguild;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << allianceguild; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> allianceguild; return cpu; }
	};

	struct stBuyCastleNPC : public PakHead
	{
		stBuyCastleNPC() { wProNO = MSG_BUY_CASTLE_NPC; }
		uint32 map_id;
		uint32 npc_id;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << map_id << npc_id; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> map_id >> npc_id; return cpu; }
	};

	struct stQueryCastleState : public PakHead
	{
		stQueryCastleState() { wProNO = MSG_QUERY_CASTLE_STATE; }
	};
}
