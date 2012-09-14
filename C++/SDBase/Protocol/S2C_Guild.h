#pragma once

#include "S2C.h"

namespace MSG_S2C
{
	struct stGuild_Create : public PakHead
	{
		stGuild_Create(){ wProNO = GUILD_CREATE; }
		CPacketSn& Sn(CPacketSn& cps) const { PakHead::Sn(cps); return cps;}
		CPacketUsn& Usn(CPacketUsn& cpu)	{ PakHead::Usn(cpu);return cpu;}
	};
	struct stGuild_Command_Result : public PakHead
	{
		stGuild_Command_Result(){ wProNO = GUILD_COMMAND_RESULT; }
		uint32 iCmd;
		string szMsg;uint32 iType;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << iCmd << szMsg << iType;  return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> iCmd >> szMsg >> iType;  return cpu; }
	};
	struct stGuild_Log : public PakHead
	{
		stGuild_Log(){ wProNO = GUILD_LOG; }
		struct stLog 
		{
			ui32	iEvent;
			uint64	Event1;
			uint64	Event2;
			uint8	Event3;
			ui32	TimeStamp;
			CPacketSn& Sn(CPacketSn& cps) const {cps << iEvent << Event1 << Event2 << Event3 << TimeStamp;  return cps; }
			CPacketUsn& Usn(CPacketUsn& cpu)	{cpu >> iEvent >> Event1 >> Event2 >> Event3 >> TimeStamp;  return cpu; }
		};
		vector<stLog> vLogs;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << vLogs;  return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> vLogs;  return cpu; }
	};
	//公会所有信息
	struct stGuild_Roster : public PakHead
	{
		stGuild_Roster(){ wProNO = GUILD_ROSTER; }
		string motd;
		string guildInfo;
		ui32	maxbanks;
		struct stBank 
		{
			uint32 iRights;
			int32 iGoldLimitPerDay;
			struct stPermission
			{
				uint32 iFlags;
				int32 iStacksPerDay;
			}Permissions[MAX_GUILD_BANK_TABS];
			CPacketSn& Sn(CPacketSn& cps) const 
			{
				cps << iRights << iGoldLimitPerDay;
				for( uint8 i = 0; i < MAX_GUILD_BANK_TABS; i++ )
				{
					cps << Permissions[0].iFlags;
					cps << Permissions[1].iStacksPerDay;
				};
				return cps; 
			}
			CPacketUsn& Usn(CPacketUsn& cpu)	
			{
				cpu >> iRights >> iGoldLimitPerDay;
				for( uint32 i = 0; i < MAX_GUILD_BANK_TABS; i++ )
				{
					cpu >> Permissions[0].iFlags;
					cpu >> Permissions[1].iStacksPerDay;
				};
				return cpu; 
			}
		};
		struct stMember
		{
			ui32	player_id;//low_guid;
			ui32	high_guid;
			ui8		bOnline;
			string  name;
			ui32	rank_id;
			ui32	last_level;
			ui32	Class;
			ui32	last_zone;
			float	lastOnline;
			string szPublicNote;
			string  szOfficerNote;
			uint8 gender;
			uint32 contribution_points;
			CPacketSn& Sn(CPacketSn& cps) const {cps << player_id << high_guid << bOnline << name << rank_id <<last_level<<Class<<last_zone<<lastOnline<<szPublicNote<<szOfficerNote<<gender<<contribution_points;  return cps; }
			CPacketUsn& Usn(CPacketUsn& cpu)	{cpu >> player_id >> high_guid >> bOnline >> name >> rank_id >>last_level>>Class>>last_zone>>lastOnline>>szPublicNote>>szOfficerNote>>gender>>contribution_points;  return cpu; }
		};
		vector<stBank> vBanks;
		vector<stMember> vMembers;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << vBanks << vMembers << motd << guildInfo;  return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> vBanks >> vMembers >> motd >> guildInfo;  return cpu; }
	};
	//对应查询公会的消息回复
	struct stGuild_Query_Response : public PakHead
	{
		stGuild_Query_Response(){ wProNO = GUILD_QUERY_RESPONSE; }
		uint32 guild_id;
		string guild_name;
		std::map<uint32, std::string> alliance_guilds;
		uint8 level;
		uint32 score;
		uint32 lead_guild_id;
		vector<string> vBanks;
		uint32 emblemStyle;
		uint32 emblemColor;
		std::set<uint32> enroll_castles; // 报名过的城堡地图ID
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << guild_id << guild_name << alliance_guilds << level << score << lead_guild_id << vBanks << emblemStyle << emblemColor << enroll_castles;  return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> guild_id >> guild_name >> alliance_guilds >> level >> score >> lead_guild_id >> vBanks >> emblemStyle >> emblemColor >> enroll_castles;  return cpu; }
		
		/*
		uint32 emblemStyle;
		uint32 emblemColor;
		uint32 borderStyle;
		uint32 borderColor;
		uint32 backgroundColor;

		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << guild_id << guild_name << vBanks<<emblemStyle<<emblemColor<<borderStyle<<borderColor<<backgroundColor;  return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> guild_id >> guild_name >> vBanks>>emblemStyle>>emblemColor>>borderStyle>>borderColor>>backgroundColor;  return cpu; }
		*/
	};
	struct stGuild_Bank_Log : public PakHead
	{
		stGuild_Bank_Log(){ wProNO = GUILD_BANK_LOG; }
		ui32	slotid;//6=moneylog;
		struct stBankLog 
		{
			ui32	iAction;
			uint32	player_id;//low_guid;
			uint32	high_guid;
			uint32 uEntry;
			ui32	TimeStamp;
			CPacketSn& Sn(CPacketSn& cps) const {cps << iAction << player_id << high_guid << uEntry << TimeStamp;  return cps; }
			CPacketUsn& Usn(CPacketUsn& cpu)	{cpu >> iAction >> player_id >> high_guid >> uEntry >> TimeStamp;  return cpu; }
		};
		vector<stBankLog> vLogs;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << slotid << vLogs;  return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> slotid >> vLogs;  return cpu; }
	};
	//公会简介
	struct stGuild_Info : public PakHead
	{
		stGuild_Info(){ wProNO = GUILD_INFO; }
		string guildName;
		uint32 create_year;
		uint32 create_month;
		uint32 create_day;
		uint32 member_count;
		uint32 level;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << guildName << create_year << create_month << create_day << member_count << level;  return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> guildName >> create_year >> create_month >> create_day >> member_count >> level;  return cpu; }
	};
	//对方邀请
	struct stGuild_Invite : public PakHead
	{
		stGuild_Invite(){ wProNO = GUILD_INVITE; }
		string guildName;
		string inviteeName;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << guildName << inviteeName;  return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);    cpu >> guildName >> inviteeName;  return cpu; }
	};
	//对方拒绝
	struct stGuild_Decline : public PakHead
	{
		stGuild_Decline(){ wProNO = GUILD_DECLINE; }
		string player_who_invite;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << player_who_invite;  return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> player_who_invite;  return cpu; }
	};
	struct stGuild_Save_Emblem : public PakHead
	{
		stGuild_Save_Emblem(){ wProNO = GUILD_SAVE_EMBLEM; }
		uint64 guid;
		uint32 emblemStyle, emblemColor, borderStyle, borderColor, backgroundColor,error;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << guid << emblemStyle << emblemColor<<borderStyle<<borderColor<<backgroundColor<<error; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> guid >> emblemStyle >> emblemColor>>borderStyle>>borderColor>>backgroundColor>>error; return cpu; }
	};
	struct stGuild_Petition_Show_Sign : public PakHead
	{
		stGuild_Petition_Show_Sign(){ wProNO = GUILD_PETITION_SHOW_SIGNATURES; }
		uint64 item_guid,leader_guid;
		ui32	player_id;
		ui8		sign_count;
		vector<uint64> vSign;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << item_guid << leader_guid << player_id<<sign_count<<vSign; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> item_guid >> leader_guid >> player_id>>sign_count>>vSign; return cpu; }
	};
	struct stGuild_Petition_Query_Response : public PakHead
	{
		stGuild_Petition_Query_Response(){ wProNO = GUILD_PETITION_QUERY_RESPONSE; }
		uint64  leader_guid;
		ui32	chater_id;
		string  GuildName;
		ui32	CharterType;
		ui8		slots;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << leader_guid << leader_guid << chater_id<<GuildName<<CharterType<<slots; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> leader_guid >> leader_guid >> chater_id>>GuildName>>CharterType>>slots; return cpu; }
	};

	struct stGuild_Petition_Sign_Result : public PakHead
	{
		stGuild_Petition_Sign_Result(){ wProNO = GUILD_PETITION_SIGN_RESULTS; }
		uint64 item_guid, target_guid;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << item_guid << target_guid; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> item_guid >> target_guid; return cpu; }
	};
	struct stGuild_Turn_In_Petition_Result : public PakHead
	{
		stGuild_Turn_In_Petition_Result(){ wProNO = GUILD_TURN_IN_PETITION_RESULTS; }
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);return cpu; }
	};
	struct stGuild_Petition_Rename : public PakHead
	{
		stGuild_Petition_Rename(){ wProNO = GUILD_PETITION_RENAME; }
		uint64 guid;
		string name;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << guid << name; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> guid >> name; return cpu; }
	};
	struct stGuild_Bank_Get_Abailable_Amound : public PakHead
	{
		stGuild_Bank_Get_Abailable_Amound(){ wProNO = GUILD_BANK_GET_AVAILABLE_AMOUNT; }
		ui32 money;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << money;return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> money;return cpu; }
	};
	struct stGuild_Bank_View_Tab_Response : public PakHead
	{
		stGuild_Bank_View_Tab_Response(){ wProNO = GUILD_BANK_VIEW_RESPONSE; }
		uint32 bankBalance;
		uint8 iTabId;//if 0,vTabs ; else vTabItems;
		ui32 AllowedItemWithdraws;
		struct stTab 
		{
			string szTabName;
			string szTabIcon;
			CPacketSn& Sn(CPacketSn& cps) const { cps << szTabName << szTabIcon;return cps; }
			CPacketUsn& Usn(CPacketUsn& cpu)	{ cpu >> szTabName >> szTabIcon;return cpu; }
		};
		vector<stTab> vTabs;

		struct stTabItem
		{
			uint32 entry;
			uint32 enchant;
			uint32 stack_count;
			CPacketSn& Sn(CPacketSn& cps) const { cps << entry << enchant << stack_count;return cps; }
			CPacketUsn& Usn(CPacketUsn& cpu)	{ cpu >> entry >> enchant >> stack_count;return cpu; }
		};
		vector<stTabItem> vTabItems;
		ui8		updated_slot1;
		ui8		updated_slot2;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << bankBalance<<iTabId<<AllowedItemWithdraws<<vTabs<<vTabItems;return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> bankBalance>>iTabId>>AllowedItemWithdraws>>vTabs>>vTabItems;return cpu; }
	};
	struct stGuild_Get_Full_Permissions : public PakHead
	{
		stGuild_Get_Full_Permissions(){ wProNO = GUILD_GET_FULL_PERMISSIONS; }
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
	struct stFriend_Stat : public PakProxyHead
	{
		stFriend_Stat(){ wProNO = FRIEND_STATUS;bOnline=0; }
		ui64	guid;
		ui8	friend_result;
		ui8	bOnline;
		ui32	level;
		ui32	Class;
		string note;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << guid << friend_result << bOnline << level << Class<<note;return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> guid >> friend_result >> bOnline >> level >> Class>>note;return cpu; }
	};
	struct stFriend_List : public PakProxyHead
	{
		stFriend_List(){ wProNO = FRIEND_LIST; }
		ui32	flag;
		struct stFriend
		{
			ui64	guid;
			ui32	flag;
			string name;
			string note;
			ui8		bOnline;
			ui32	level;
			ui32	Class;
			CPacketSn& Sn(CPacketSn& cps) const {	cps << guid << flag << name << note << bOnline << level << Class;return cps; }
			CPacketUsn& Usn(CPacketUsn& cpu)	{	cpu >> guid >> flag >> name >> note >> bOnline >> level >> Class;return cpu; }
		};
		vector<stFriend> vFriends;
		vector<ui64> vIgnores;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << flag << vFriends << vIgnores;return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> flag >> vFriends >> vIgnores;return cpu; }
	};

	struct stSetMemberRankAck : public PakHead
	{
		stSetMemberRankAck() { wProNO = GUILD_SET_MEMBER_RANK_ACK; }
		std::string member;
		uint8 bRankFull;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << member << bRankFull; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> member >> bRankFull; return cpu; }
	};

	struct stGuildListInfoAck : public PakHead
	{
		stGuildListInfoAck() { wProNO = GUILD_LIST_INFO_ACK; }
		struct guild_info_t
		{
			uint32 id;
			std::string guildName;
			uint8 create_year;
			uint8 create_month;
			uint8 create_day;
			uint8 member_count;
			uint8 level;
			std::string master_name;
			CPacketSn& Sn(CPacketSn& cps) const {	cps << id << guildName << create_year << create_month << create_day << member_count << level << master_name;  return cps; }
			CPacketUsn& Usn(CPacketUsn& cpu)	{	cpu >> id >> guildName >> create_year >> create_month >> create_day >> member_count >> level >> master_name;  return cpu; }
		};
		std::vector<guild_info_t> vGuilds;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << vGuilds;  return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> vGuilds;  return cpu; }
	};
	struct stGuildDeclareWarNotify : public PakHead
	{
		stGuildDeclareWarNotify() { wProNO = GUILD_DECLARE_WAR_NOTIFY; }
		std::string active_guildname;
		std::string passive_guildname;

		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << active_guildname << passive_guildname;  return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> active_guildname >> passive_guildname;  return cpu; }
	};

	struct stGuildAllyReqNotify : public PakHead
	{
		stGuildAllyReqNotify() { wProNO = GUILD_ALLY_REQ_NOTIFY; }
		std::string master;
		uint32 master_id;
		std::string guild_name;
		uint32 guild_id;

		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << master << master_id << guild_name << guild_id;  return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> master >> master_id >> guild_name >> guild_id;  return cpu; }
	};

	struct stGuildAllyAck : public PakHead
	{
		stGuildAllyAck() { wProNO = GUILD_ALLY_ACK; }
		uint32 master_id;
		uint8 baccept;

		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << master_id << baccept;  return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> master_id >> baccept;  return cpu; }
	};

	struct stGuildAllyStateNotify : public PakHead
	{
		stGuildAllyStateNotify() { wProNO = GUILD_ALLY_STATE_NOTIFY; }
		uint32 guild_id;
		std::string guild_name;
		uint8 bestablish;

		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << guild_id << guild_name << bestablish;  return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> guild_id >> guild_name >> bestablish;  return cpu; }
	};

	struct stGuildContributionPointsNotify : public PakHead
	{
		stGuildContributionPointsNotify() { wProNO = GUILD_CONTRIBUTION_POINTS_NOTIFY; }

		uint32 player_id;
		uint32 points;
		uint32 guild_score;

		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << player_id << points << guild_score;  return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> player_id >> points >> guild_score;  return cpu; }
	};
	struct stCastleNPCStateNotify : public PakHead
	{
		stCastleNPCStateNotify() { wProNO = MSG_CASTLE_NPC_STATE_NOTIFY; }
		
		uint32 map_id;
		std::set<uint32> buy_npcs;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << map_id << buy_npcs;  return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> map_id >> buy_npcs;  return cpu; }
	};

	struct stCastleStateAck : public PakHead
	{
		stCastleStateAck() { wProNO = MSG_CASTLE_STATE_ACK; }
		struct castle_state
		{
			uint32 mapid;
			uint8 state;	// 0 free 1 building 2 ready to fight 3 fighting
			uint32 owner_guild;
			std::string owner_guild_name;
			std::set<uint32> fight_day_of_week;
			uint8 prepare_time;
			uint8 fight_duaration;
			uint8 fight_time;
			std::string castle_name;
			CPacketSn& Sn(CPacketSn& cps) const {	cps << mapid << state << owner_guild << owner_guild_name << fight_day_of_week << prepare_time << fight_duaration << fight_time << castle_name; return cps; }
			CPacketUsn& Usn(CPacketUsn& cpu)	{	cpu >> mapid >> state >> owner_guild >> owner_guild_name >> fight_day_of_week >> prepare_time >> fight_duaration >> fight_time >> castle_name; return cpu; }
		};

		std::vector<castle_state> vstates;
		uint32 server_time;

		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << vstates << server_time; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> vstates >> server_time; return cpu; }
	};

	struct stCastleCountDown : public PakHead
	{
		stCastleCountDown() { wProNO = MSG_CASTLE_COUNT_DOWN; }
		std::string castle_name;
		uint32 mapid;
		uint8 next_state; // 2 ready 3 fight 0 end
		uint8 count_down_mins; // count down minutes
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << mapid << castle_name << next_state << count_down_mins; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> mapid >> castle_name >> next_state >> count_down_mins; return cpu; }
	};
}

enum FriendsResult {
	FRIEND_DB_ERROR				= 0x00,
	FRIEND_LIST_FULL			= 0x01,
	FRIEND_ONLINE				= 0x02,
	FRIEND_OFFLINE				= 0x03,
	FRIEND_NOT_FOUND			= 0x04,
	FRIEND_REMOVED				= 0x05,
	FRIEND_ADDED_ONLINE			= 0x06,
	FRIEND_ADDED_OFFLINE		= 0x07,
	FRIEND_ALREADY				= 0x08,
	FRIEND_SELF					= 0x09,
	FRIEND_ENEMY				= 0x0A,
	FRIEND_IGNORE_FULL			= 0x0B,
	FRIEND_IGNORE_SELF			= 0x0C,
	FRIEND_IGNORE_NOT_FOUND		= 0x0D,
	FRIEND_IGNORE_ALREADY		= 0x0E,
	FRIEND_IGNORE_ADDED			= 0x0F,
	FRIEND_IGNORE_REMOVED		= 0x10
};