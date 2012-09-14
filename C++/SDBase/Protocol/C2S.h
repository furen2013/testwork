#pragma once

#include "PacketDef.h"
#include "../Public/PublicDef.h"
#include "../Public/ItemDef.h"
#include "../Public/PlayerDef.h"
#include "../Public/UnitDef.h"
namespace MSG_C2S
{
	using namespace SDBase;
	enum
	{
		LOGIN_REQ = MSG_BASE_C2GT,		
		CREATEROLE_REQ,
		ROLELIST_REQ,
		DELROLE_REQ,
		RESUMEROLE_REQ,

		GROUP_ID_REQ,
		
		ENTERGAME_REQ	= MSG_BASE_C2GS,		//请求角色进入游戏
		LOGOUT_REQ,							//小退请求
		EXIT_REQ,								//大退请求	
		RELIVE_REQ,							//复活请求
// 		CHAT_REQ,								//聊天请求消息
// 		PLAYER_MOVE_REQ,						//角色行走请求
// 		PLAYER_RUN_REQ,						//角色跑动请求
// 		PLAYER_ATTACK_REQ,						//攻击请求
// 		MAPITEM_PICKUP_REQ,					//拾取地图道具的请求
// 		MAPITEM_DROP_REG,						//丢弃背包道具到地图的请求
// 		TALK_TO_NPC,						//与NPC对话
		//////////////////////////////////////////////////////////////////////////
		//	Move
		//////////////////////////////////////////////////////////////////////////
		MOVE_OP,	

		MOVE_WORLDPORT_ACK							,	
		MOVE_TELEPORT_ACK							,	
		MOVE_TIME_SKIPPED							,	
		MOVE_NOT_ACTIVE_MOVER						,	
		MOVE_SET_ACTIVE_MOVER							,	

		MOVE_WORLD_TELEPORT,
		MOVE_TELEPORT_TO_UNIT						,	
		MOVE_TELEPORT_CHEAT,
		
		MOVE_ACK,
	

// 		CMSG_MOVE_START_SWIM_CHEAT						,	
// 		CMSG_MOVE_STOP_SWIM_CHEAT						,	
// 		CMSG_MOVE_UNLOCK_MOVEMENT_ACK					,	
// MSG_MOVE_FEATHER_FALL							,	
// MSG_MOVE_WATER_WALK								,	
		MOVE_SPLINE_DONE							,	
// CMSG_MOVE_FALL_RESET							,	

		MOVE_MOUNTSPECIAL_ANIM,
//		CMSG_MOVE_SET_FLY_SPEED_ACK						,	

		MOUNT_INVITE,
		MOUNT_DISBAND,
		MOUNT_ACCEPT,
		MOUNT_DECLINE,
		//////////////////////////////////////////////////////////////////////////
		//	Channel
		//////////////////////////////////////////////////////////////////////////
		CHANNEL_JOIN,	
		CHANNEL_LEAVE,	
		CHANNEL_LIST,	
		CHANNEL_PASSWORD,	
		CHANNEL_SET_OWNER,	
		CHANNEL_OWNER,	
		CHANNEL_MODERATOR,	
		CHANNEL_UNMODERATOR,	
		CHANNEL_MUTE,	
		CHANNEL_UNMUTE,	
		CHANNEL_INVITE,	
		CHANNEL_KICK,	
		CHANNEL_BAN,	
		CHANNEL_UNBAN,	
		CHANNEL_ANNOUNCEMENTS,	
		CHANNEL_MODERATE,	
		CHANNEL_SILENT_VOICE,
		CHANNEL_SILENT_ALL,
		CHANNEL_UNSILENT_ALL,
		CHANNEL_GET_ROSTER_INFO,
		CHANNEL_NUM_MEMBERS_QUERY,

		CMSG_VOICE_CHAT_QUERY							,
		CMSG_ENABLE_MICROPHONE							,	

// 		CMSG_CHANNEL_TURN_VOICE_ON						,
// 		CMSG_CHANNEL_TURN_VOICE_ON_2					,

		//////////////////////////////////////////////////////////////////////////
		//	Chat
		//////////////////////////////////////////////////////////////////////////
		CHAT_MESSAGE,	
		CHAT_REPORT_SPAM,
		CHAT_TEXT_EMOTE,
		CMSG_EMOTE										,	

		//////////////////////////////////////////////////////////////////////////
		//	Pet
		//////////////////////////////////////////////////////////////////////////
		PET_SET_ACTION								,	
		PET_ACTION									,	
		PET_ABANDON								,	
		PET_RENAME									,	
		PET_REQUEST_INFO							,	
		PET_STABLE								,	
		PET_UNSTABLE								,	
		PET_STABLE_SWAP								,	
		//CMSG_PET_STOP_ATTACK							,	
		PET_BUY_STABLE_SLOT							,	
PET_UNLEARN,
// 	CMSG_AUTH_SRP6_BEGIN							,	
// 	CMSG_AUTH_SRP6_PROOF							,	
// 	CMSG_AUTH_SRP6_RECODE							,	
// 	CMSG_CHAR_CREATE								,	
// 	CMSG_CHAR_ENUM									,	
// 	CMSG_CHAR_DELETE								,	
// CMSG_PET_CANCEL_AURA							,	
PETS_LIST_STABLED							,	

		//////////////////////////////////////////////////////////////////////////
		//	Duel
		//////////////////////////////////////////////////////////////////////////
		DUEL_ACCEPTED								,	
		DUEL_CANCELLED								,	

		//////////////////////////////////////////////////////////////////////////
		//	Trade
		//////////////////////////////////////////////////////////////////////////
		TRADE_INITIATE,
		TRADE_CANCEL,
		TRADE_CLEAR_ITEM,
		TRADE_IGNORE,
		TRADE_SET_ITEM,
		TRADE_SET_GOLD,
		TRADE_ACCEPT,
		//TRADE_UNACCEPT,
		TRADE_LOCK,
		TRADE_BEGIN,
		TRADE_BUSY,

		//////////////////////////////////////////////////////////////////////////
		//	Group
		//////////////////////////////////////////////////////////////////////////
		GROUP_INVITE,                              //	发出邀请
		GROUP_CANCEL                         ,
		GROUP_ACCEPT                         ,
		GROUP_DECLINE                        ,
		GROUP_UNINVITE_NAME                       ,
		GROUP_UNINVITE_GUID                  ,
		GROUP_SET_LEADER                     ,
		GROUP_LOOT_METHOD                          ,
		GROUP_SET_PLAYER_ICON						,	

		GROUP_DISBAND                        ,		//	leave group
		GROUP_RAID_CONVERT,
		GROUP_ASSISTANT_LEADER           ,
		PARTY_ASSIGNMENT,
		PARTY_MEMBER_STAT,
		MINIMAP_PING,
		GROUP_PROMOTE,
		GROUP_CHANGE_SUB_GROUP						,	
		RAID_REQUEST_INFO							,	
		RAID_READYCHECK							,	

		//////////////////////////////////////////////////////////////////////////
		//	Guild
		//////////////////////////////////////////////////////////////////////////
		GUILD_CREATE								,	
		GUILD_INVITE								,	
		GUILD_ACCEPT								,	
		GUILD_DECLINE								,	
		GUILD_INFO									,	
		GUILD_ROSTER								,	
		GUILD_PROMOTE								,	
		GUILD_DEMOTE								,	
		GUILD_LEAVE								,	
		GUILD_REMOVE								,	
		GUILD_DISBAND								,	
		GUILD_LEADER								,	
		GUILD_MOTD									,	
		GUILD_LOG									,
		GUILD_SAVE_EMBLEM							,	
		GUILD_GET_FULL_PERMISSIONS					,
		GUILD_BANK_GET_AVAILABLE_AMOUNT				,
		GUILD_BANK_LOG								,
		GUILD_BANK_OPEN							,
		GUILD_BANK_VIEW_TAB						,
		GUILD_BANK_DEPOSIT_ITEM					,
		GUILD_BANK_PURCHASE_TAB					,
		GUILD_BANK_MODIFY_TAB						,
		GUILD_BANK_DEPOSIT_MONEY					,
		GUILD_BANK_WITHDRAW_MONEY					,
		GUILD_RANK									,	
		GUILD_ADD_RANK								,	
		GUILD_DEL_RANK								,	
		GUILD_SET_PUBLIC_NOTE						,	
		GUILD_SET_OFFICER_NOTE						,	
		GUILD_QUERY								,	
		GUILD_SET_INFORMATION						,	

		GUILD_PETITION_BUY								,	
		GUILD_PETITION_SHOW_SIGNATURES					,	
		GUILD_PETITION_SIGN								,	
		GUILD_PETITION_DECLINE							,	
		GUILD_OFFER_PETITION								,	
		GUILD_TURN_IN_PETITION							,	
		GUILD_PETITION_QUERY								,	

		GUILD_PETITION_RENAME								,	
		GUILD_SET_MEMBER_RANK							,
		GUILD_QUERY_GUILD_LIST_REQ						,
		GUILD_DECLARE_WAR								,
		GUILD_ALLY_REQ,
		GUILD_ALLY_REPLY,
		//UMSG_DELETE_GUILD_CHARTER						,	

		FRIEND_LIST								,	
		FRIEND_ADD									,	
		FRIEND_DEL									,	
		FRIEND_SET_NOTE							,	
		FRIEND_ADD_IGNORE									,	
		FRIEND_DEL_IGNORE									,	

		//////////////////////////////////////////////////////////////////////////
		//	Item
		//////////////////////////////////////////////////////////////////////////
		ITEM_SPLIT,				// split item
		ITEM_SWAP_INV,			// swap inventroy's item
		ITEM_SWAP,				// swap item between bags
		ITEM_DESTROY,
		ITEM_QUERY_SINGLE,
		ITEM_AUTOEQUIP,
		ITEM_AUTOEQUIP_SLOT,
		ITEM_REPAIR,
		PAGE_TEXT_QUERY,
		ITEM_READ,

		ITEM_WRAP,
		LIST_INVENTORY,				//	请求出售道具列表
		ITEM_BUYBACK,				//	买回自己售出的道具
		ITEM_BUY,					//	购买道具
		ITEM_BUY_IN_SLOT,
		BUY_BANK_SLOT,
		ITEM_SELL,					//	出售道具
		ITEM_AUTOSTORE_BAG,
		ITEM_AUTOBANK,
		ITEM_AUTOSTORE_BANK,

		ITEM_SOCKET_GEMS,
		ITEM_CANCEL_TEMPORARY_ENCHANTMENT,	


		ITEM_OPEN							,	
		ITEM_NAME_QUERY							,	
		
		MSG_SPLIT_MONEY									,	

		ITEM_DROP									,	
		ITEM_PICKUP								,	

		ITEM_SHOW_SHIZHUANG,
		//////////////////////////////////////////////////////////////////////////
		//	Areatrigger
		//////////////////////////////////////////////////////////////////////////
		AREA_TRIGGER,	
		//////////////////////////////////////////////////////////////////////////
		//	ArenaTeam
		//////////////////////////////////////////////////////////////////////////
		ARENA_TEAM_QUERY,	
		ARENA_TEAM_ROSTER,	
		ARENA_TEAM_ADD_MEMBER,	
		ARENA_TEAM_INVITE_ACCEPT,	
		ARENA_TEAM_INVITE_DECLINE,	
		ARENA_TEAM_LEAVE,	
		ARENA_TEAM_REMOVE_PLAYER,	
		ARENA_TEAM_DISBAND,	
		ARENA_TEAM_PROMOTE,	

		//////////////////////////////////////////////////////////////////////////
		//	Auction
		//////////////////////////////////////////////////////////////////////////
		AUCTION_SELL_ITEM,	
		AUCTION_REMOVE_ITEM,	
		AUCTION_LIST_ITEMS,	
		AUCTION_LIST_OWNER_ITEMS,	
		AUCTION_PLACE_BID,	
		AUCTION_LIST_BIDDER_ITEMS,	
		AUCTION_HELLO,
		//////////////////////////////////////////////////////////////////////////
		//	BattleGround
		//////////////////////////////////////////////////////////////////////////
		BATTLEFIELD_STATUS							,	
		BATTLEFIELD_PORT							,	
		BATTLEFIELD_LIST							,	
		BATTLEMASTER_HELLO							,	
		AREA_SPIRIT_HEALER_QUERY,
		AREA_SPIRIT_HEALER_QUEUE					,	
		BATTLEGROUND_PLAYER_POSITIONS				,	
		BATTLEMASTER_JOIN							,	
		ARENA_JOIN									,	
		INSPECT_HONOR_STATS							,	
		INSPECT_ARENA_STATS,
		BATTLEFIELD_LEAVE,	
		CMSG_MOVE_SPLINE_DONE,
		//CMSG_BATTLEFIELD_JOIN							,	
		//////////////////////////////////////////////////////////////////////////
		//	Quest
		//////////////////////////////////////////////////////////////////////////
		QUEST_QUERY,	
		QUEST_PUSHTO_PARTY,
		QUEST_PUSH_RESULT,
		QUEST_CONFIRM_ACCEPT						,	

		QUESTGIVER_STATUS_QUERY,	
		QUESTGIVER_HELLO,
		QUESTGIVER_QUERY_QUEST						,	
		QUESTGIVER_ACCEPT_QUEST,
		QUESTGIVER_CANCEL,
		QUESTGIVER_REQUEST_REWARD,
		QUESTGIVER_COMPLETE_QUEST,
		QUESTGIVER_CHOOSE_REWARD,
		QUESTGIVER_INRANGE_STATUS_QUERY			,

		QUESTLOG_REMOVE_QUEST,
// 		CMSG_FLAG_QUEST									,	
// 		CMSG_FLAG_QUEST_FINISH							,	
// 		CMSG_CLEAR_QUEST								,	

// 		CMSG_QUESTGIVER_QUEST_AUTOLAUNCH				,	
// 		CMSG_QUESTLOG_SWAP_QUEST						,	

		//////////////////////////////////////////////////////////////////////////
		//	NPC
		//////////////////////////////////////////////////////////////////////////

		NPC_TABARDVENDOR_ACTIVATE,
		NPC_BANKER_ACTIVATE,
		NPC_TRAINER_LIST								,	
		NPC_TRAINER_BUY_SPELL							,	
		NPC_PETITION_SHOWLIST							,	

		NPC_GOSSIP_HELLO								,	
		NPC_GOSSIP_SELECT_OPTION						,	
		NPC_SPIRIT_HEALER_ACTIVATE						,	
		NPC_TEXT_QUERY								,	
		NPC_BINDER_ACTIVATE							,	
		//CMSG_RUN_SCRIPT									,	

		//////////////////////////////////////////////////////////////////////////
		//	Spell
		//////////////////////////////////////////////////////////////////////////
		SPELL_LEARN_TALENT,	
		SPELL_UNLEARN_TALENTS							,	
		SKILL_UNLEARN,	

		SPELL_CAST,
		SPELL_CANCEL_CAST,
		SPELL_CANCEL_AURA								,	
		SPELL_CANCEL_CHANNELLING							,	
		SPELL_CANCEL_AUTO_REPEAT,
		SPELL_ADD_DYNAMIC_TARGET_OBSOLETE,

		ITEM_USE,							//使用
		SPELL_SELF_RES,

		//CMSG_CANCEL_GROWTH_AURA							,	
		//CMSG_NEW_SPELL_SLOT								,	
		MSG_TALENT_WIPE_CONFIRM							,	

		ATTACK_SWING								,	
		ATTACK_STOP			,	
		//////////////////////////////////////////////////////////////////////////
		//	PVP
		//////////////////////////////////////////////////////////////////////////
		CMSG_SET_PVP_RANK_CHEAT							,	
		CMSG_ADD_PVP_MEDAL_CHEAT						,	
		CMSG_DEL_PVP_MEDAL_CHEAT						,	
		CMSG_SET_PVP_TITLE								,	
		CMSG_DISABLE_PVP_CHEAT							,	
		CMSG_PVP_PORT_OBSOLETE							,	
		PVP_LOG_DATA								,	
		CMSG_SET_VISIBLE_RANK							,	

		//////////////////////////////////////////////////////////////////////////
		//	Mail
		//////////////////////////////////////////////////////////////////////////
		MAIL_SEND,
		MAIL_GET_LIST								,	
		MAIL_TEXT_QUERY							,	
		MAIL_TAKE_MONEY							,	
		MAIL_TAKE_ITEM								,	
		MAIL_MARK_AS_READ							,	
		MAIL_RETURN_TO_SENDER						,	
		MAIL_DELETE								,	
		MAIL_CREATE_TEXT_ITEM						,	
		MAIL_QUERY_NEXT_TIME						,	

		//////////////////////////////////////////////////////////////////////////
		//	Skill
		//////////////////////////////////////////////////////////////////////////
// 		CMSG_SKILL_BUY_STEP								,	
// 		CMSG_SKILL_BUY_RANK								,	

		//////////////////////////////////////////////////////////////////////////
		//	Loot
		//////////////////////////////////////////////////////////////////////////
		MSG_RANDOM_ROLL									,	
		CMSG_REPOP_REQUEST								,	
		LOOT_AUTOSTORE_ITEM						,	
		LOOT_ROLL									,	
		LOOT										,	
		LOOT_RELEASE								,	
		LOOT_MASTER_GIVE							,	
		LOOT_SET_AUTO_PASS							,
		LOOT_MONEY,	

		CMSG_COMPLETE_CINEMATIC							,	
		CMSG_TOGGLE_CLOAK								,	
		CMSG_TOGGLE_HELM								,	
		MSG_DUNGEON_DIFFICULTY							,	

		MSG_WHO,
// 		CMSG_XP_CHEAT									,	
		CMSG_LOGOUT_REQUEST								,	
		CMSG_PLAYER_LOGOUT								,	
		CMSG_LOGOUT_CANCEL								,	
		CMSG_ZONEUPDATE									,	
		CMSG_SET_TARGET_OBSOLETE						,	
		CMSG_SET_SELECTION								,	
		CMSG_STANDSTATECHANGE							,	
		CMSG_BUG										,	
		CMSG_RECLAIM_CORPSE								,	
		CMSG_RESURRECT_RESPONSE							,	
		CMSG_SET_WATCHED_FACTION_INDEX					,	
		CMSG_TOGGLE_PVP									,	

		GAMEOBJ_USE								,	
		CMSG_PLAYED_TIME								,	
		CMSG_INSPECT									,	
		CMSG_RESET_INSTANCE								,	
		CMSG_SUMMON_RESPONSE							,	
		CMSG_DISMOUNT									,	

		//////////////////////////////////////////////////////////////////////////
		//	Other
		//////////////////////////////////////////////////////////////////////////
		//CMSG_FAR_SIGHT									,	
		CMSG_QUERY_OBJECT_POSITION					,	
		CMSG_QUERY_OBJECT_ROTATION					,	
		CMSG_ZONE_MAP									,	
		CMSG_FORCEACTION								,	
		CMSG_FORCEACTIONONOTHER							,	
		CMSG_FORCEACTIONSHOW							,	
		CMSG_GODMODE									,	
		CMSG_GAMETIME_SET								,	
		CMSG_GAMESPEED_SET								,	
		CMSG_SERVERTIME									,	
		CMSG_WHOIS										,	
		CMSG_AUTOSTORE_GROUND_ITEM						,	
		CMSG_AUTOEQUIP_GROUND_ITEM						,	
		CMSG_SET_FACTION_ATWAR							,	
		CMSG_SET_FACTION_CHEAT							,	
		CMSG_RWHOIS										,	
		CMSG_PING										,	
		CMSG_SET_SKILL_CHEAT							,	
		SET_SHEATHED								,	

		//////////////////////////////////////////////////////////////////////////
		//	Taxi
		//////////////////////////////////////////////////////////////////////////
		CMSG_TAXICLEARALLNODES							,	
		CMSG_TAXIENABLEALLNODES							,	
		CMSG_TAXISHOWNODES								,	
		CMSG_TAXINODE_STATUS_QUERY						,	
		CMSG_TAXIQUERYAVAILABLENODES					,	
		CMSG_ACTIVATETAXI								,	
		CMSG_ACTIVATE_MULTIPLE_TAXI						,	

		//////////////////////////////////////////////////////////////////////////
		//	ActionBar
		//////////////////////////////////////////////////////////////////////////
		CMSG_SET_ACTION_BUTTON							,	
		CMSG_SET_ACTIONBAR_TOGGLES						,	

		//////////////////////////////////////////////////////////////////////////
		//	Turorial
		//////////////////////////////////////////////////////////////////////////
		TUTORIAL_FLAG								,	
		TUTORIAL_CLEAR								,	
		TUTORIAL_RESET								,	
		//CMSG_SERVER_BROADCAST							,	

		//////////////////////////////////////////////////////////////////////////
		//	Query
		//////////////////////////////////////////////////////////////////////////
		QUERY_NAME									,	
		QUERY_TIME									,	
		QUERY_CREATURE								,	
		QUERY_GAMEOBJECT						,	
		QUERY_CORPSE								,	
		QUERY_PAGE_TEXT							,	
		QUERY_PET_NAME								,	
		//////////////////////////////////////////////////////////////////////////
		//	GM
		//////////////////////////////////////////////////////////////////////////
		CMSG_SERVER_COMMAND								,	
		CMSG_GM_VISION									,	
		CMSG_GM_SILENCE									,	
		CMSG_GM_REVEALTO								,	
		CMSG_GM_RESURRECT								,	
		CMSG_GM_SUMMONMOB								,	
		CMSG_GM_MOVECORPSE								,	
		CMSG_GM_FREEZE									,	
		CMSG_GM_UBERINVIS								,	
		CMSG_GM_REQUEST_PLAYER_INFO						,	
		CMSG_GM_TEACH									,	
		CMSG_GM_CREATE_ITEM_TARGET						,	
		CMSG_GMTICKET_GETTICKET							,	
		CMSG_GMTICKET_DELETETICKET						,	
		CMSG_GMTICKET_SYSTEMSTATUS						,	
		CMSG_GMTICKETSYSTEM_TOGGLE						,	

		CMSG_GM_INVIS									,	
		MSG_GM_BIND_OTHER								,	
		MSG_GM_SUMMON									,	
		CMSG_GM_SET_SECURITY_GROUP						,	
		CMSG_GM_NUKE									,	
		MSG_GM_SHOWLABEL								,	
		CMSG_GMTICKET_CREATE							,	
		CMSG_GMTICKET_UPDATETEXT						,	

		CMSG_LEARN_SPELL								,	
		CMSG_CREATEMONSTER								,	
		CMSG_DESTROYMONSTER								,	
		CMSG_CREATEITEM									,	
		CMSG_CREATEGAMEOBJECT							,	


		//////////////////////////////////////////////////////////////////////////
		// Contribution
		//////////////////////////////////////////////////////////////////////////
		QUERY_CONTRIBUTION_PLAYER,
		CONTRIBUTION_CONFIRM,
		QUERY_SELF_CONTRIBUTION_HISTORY,
		QUERY_CONTRIBUTION_BILLBOARD,

		CMSG_LOADING_OK,

		CMSG_SHOP_BUY,
		CMSG_SHOP_ADDTOCATEGORY,
		CMSG_SHOP_GETLIST,

		MSG_TRADE_SWITCH,

		RESURRECT_BY_OTHER,
		
		MSG_QUEUE_INSTANCE,
		MSG_LEAVE_QUEUE_INSTANCE,

		MSG_ENTER_LEAVE_PVP_ZONE,

		MSG_JINGLIAN_CONTAINER_MOVE_ITEM_REQ,

		MSG_JINGLIAN_ITEM_REQ,

		MSG_XIANGQIAN_CONTAINER_MOVE_ITEM_REQ,

		MSG_XIANGQIAN_ITEM_REQ,

		MSG_RECRUIT_REQ,
		MSG_RECRUIT_REPLY,
		
		CMSG_CHOICE_INSTANCE_DEAD_EXIT,

		MSG_BUY_CASTLE_NPC,

		MSG_QUERY_CASTLE_STATE,

		MSG_LADDER_REQ,

		MSG_CHOOSE_TITLE,
		MSG_TITLE_LIST,

		MSG_QUEST_ESCORT_REPLY,

		MSG_RETURN_2_LOGIN,

		// for activity tool
//#ifdef _ACTIVITY_PROTOCOL
		MSG_ACT_TOOL_ACCESS_REQ,
		MSG_QUERY_ACTIVITY_LIST,
		MSG_UPDATE_ACTIVITY_REQ,
		MSG_REMOVE_ACTIVITY_REQ,
//#endif
		//////////////////////////////////////////////////////////////////////////

		MSG_QUERY_PLAYERS,
		MSG_LEAP_PREPARE,

		MSG_DONATE_REQ,
		MSG_QUERY_DONATION_LADDER,

		MSG_CREDIT_APPLY_REQ,
		MSG_CREDIT_ACTION_REQ,
		MSG_QUERY_CREDIT_HISTORY_REQ,


		
		GROUP_SWEP_MEMBER,
		GROUP_SWEP_MEMBER_NAME,
		MSG_MAX,
		NUM_MSG_TYPES = MSG_MAX + 100,
	};

	struct stCreditApplyReq : public PakHead
	{
		stCreditApplyReq() { wProNO = MSG_CREDIT_APPLY_REQ; }
	};

	struct stCreditActionReq : public PakHead
	{
		stCreditActionReq() { wProNO = MSG_CREDIT_ACTION_REQ; }
		uint32 yuanbao;
		uint8 is_restore;			// 是否还款？ 如果是false则是从信用卡转帐到基本账户

		CPacketSn& Sn(CPacketSn& cps) const { PakHead::Sn(cps); cps << yuanbao << is_restore; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{ PakHead::Usn(cpu);cpu >> yuanbao >> is_restore; return cpu; }
	};

	struct stQueryCreditHistoryReq : public PakHead
	{
		stQueryCreditHistoryReq() { wProNO = MSG_QUERY_CREDIT_HISTORY_REQ; }
		uint32 from;
		uint32 to;
		
		CPacketSn& Sn(CPacketSn& cps) const { PakHead::Sn(cps); cps << from << to; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{ PakHead::Usn(cpu);cpu >> from >> to; return cpu; }
	};

	struct stGroupIDReq : public PakHead
	{
		stGroupIDReq() { wProNO = GROUP_ID_REQ; }
		uint32 groupid;
		CPacketSn& Sn(CPacketSn& cps) const { PakHead::Sn(cps); cps << groupid; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{ PakHead::Usn(cpu);cpu >> groupid; return cpu; }
	};
	struct stDonateReq : public PakHead //捐助
	{
		stDonateReq() { wProNO = MSG_DONATE_REQ; }
		uint32 event_id;
		uint32 yuanbao;
		std::string leave_words;

		CPacketSn& Sn(CPacketSn& cps) const { PakHead::Sn(cps); cps << event_id << yuanbao << leave_words; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{ PakHead::Usn(cpu);cpu >> event_id >> yuanbao >> leave_words; return cpu; }
	};

	struct stQueryDonationLadder : public PakHead //查询排行
	{
		stQueryDonationLadder() { wProNO = MSG_QUERY_DONATION_LADDER; }
		uint32 event_id;
		bool is_total;
		CPacketSn& Sn(CPacketSn& cps) const { PakHead::Sn(cps); cps << event_id << is_total; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{ PakHead::Usn(cpu);cpu >> event_id >> is_total; return cpu; }
	};

	struct stLeapPrepare : public PakHead
	{
		stLeapPrepare() { wProNO = MSG_LEAP_PREPARE; }
		float x;
		float y;
		float z;
		float o;

		CPacketSn& Sn(CPacketSn& cps) const { PakHead::Sn(cps); cps << x << y << z << o; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{ PakHead::Usn(cpu);cpu >> x >> y >> z >> o; return cpu; }
	};

	struct stQueryPlayers : public PakHead
	{
		stQueryPlayers() { wProNO = MSG_QUERY_PLAYERS; }

		uint8 min_level;
		uint8 max_level;
		uint16 mapid;
		uint8 race;
		uint8 cls;
		std::string str;

		CPacketSn& Sn(CPacketSn& cps) const { PakHead::Sn(cps); cps << min_level << max_level << mapid << race << cls << str; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{ PakHead::Usn(cpu);cpu >> min_level >> max_level >> mapid >> race >> cls >> str; return cpu; }
	};


#ifdef _ACTIVITY_PROTOCOL
	struct stActToolAccessReq : public PakHead
	{
		stActToolAccessReq() { wProNO = MSG_ACT_TOOL_ACCESS_REQ; }
		std::string user;
		std::string password;
		CPacketSn& Sn(CPacketSn& cps) const { PakHead::Sn(cps); cps << user << password; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{ PakHead::Usn(cpu);cpu >> user >> password; return cpu; }
	};

	struct stQueryActivityList : public PakHead
	{
		stQueryActivityList() { wProNO = MSG_QUERY_ACTIVITY_LIST; }
	};

	struct stUpdateActivityReq : public PakHead
	{
		stUpdateActivityReq() { wProNO = MSG_UPDATE_ACTIVITY_REQ; }
		uint32 act_ptr;
		template<class T>
		void SetPtr( T p ) {
			act_ptr = reinterpret_cast<uint32>( p );
		}
		template<class T>
		T GetPtr() {
			return reinterpret_cast<T>( act_ptr );
		}
		CPacketSn& Sn(CPacketSn& cps) const;
		CPacketUsn& Usn(CPacketUsn& cpu);
	};

	struct stRemoveActivityReq : public PakHead
	{
		stRemoveActivityReq() { wProNO = MSG_REMOVE_ACTIVITY_REQ; }
		uint32 actid;
		CPacketSn& Sn(CPacketSn& cps) const { PakHead::Sn(cps); cps << actid; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{ PakHead::Usn(cpu);cpu >> actid; return cpu; }
	};
#endif

	struct stReturn2Login : public PakHead
	{
		stReturn2Login(){ wProNO = MSG_RETURN_2_LOGIN; }
	};

	struct stQuestEscortReply : public PakHead
	{
		stQuestEscortReply() { wProNO = MSG_QUEST_ESCORT_REPLY; }
		uint8 is_accept;
		uint32 quest_id;
		uint32 npc_id;
		CPacketSn& Sn(CPacketSn& cps) const { PakHead::Sn(cps); cps << is_accept << quest_id << npc_id; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{ PakHead::Usn(cpu);cpu >> is_accept >> quest_id >> npc_id; return cpu; }
	};

	struct stTitleList : public PakHead
	{
		stTitleList(){ wProNO = MSG_TITLE_LIST; }
	};

	struct stChooseTitle : public PakHead
	{
		stChooseTitle(){ wProNO = MSG_CHOOSE_TITLE; }
		uint32 title_index;
		CPacketSn& Sn(CPacketSn& cps) const { PakHead::Sn(cps); cps << title_index; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{ PakHead::Usn(cpu);cpu >> title_index; return cpu; }
	};

	struct stChoiceInstanceDeadExit : public PakHead
	{
		stChoiceInstanceDeadExit(){ wProNO = CMSG_CHOICE_INSTANCE_DEAD_EXIT; }
		bool bExit;
		CPacketSn& Sn(CPacketSn& cps) const { PakHead::Sn(cps); cps << bExit; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{ PakHead::Usn(cpu);cpu >> bExit; return cpu; }
	};

	struct stServerTime : public PakHead
	{
		stServerTime(){ wProNO = CMSG_SERVERTIME; }
	};

	struct stResurrectByOther : public PakHead
	{
		stResurrectByOther(){ wProNO = RESURRECT_BY_OTHER; }
		bool bAccept;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << bAccept; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> bAccept; return cpu; }
	};
	struct stReliveReq : public PakHead
	{
		enum{
			Relive_Item,
			Relive_Home,
			Relive_Player,
		};
		stReliveReq(){ wProNO = RELIVE_REQ; }
		uint8 type;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << type; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> type; return cpu; }
	};
	struct stPing : public PakHead
	{
		stPing(){ wProNO = CMSG_PING; }
		uint32 index;
		uint32 timestamp;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << index << timestamp; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> index >> timestamp; return cpu; }
	};
	struct stLoadingOK : public PakHead
	{
		stLoadingOK(){ wProNO = CMSG_LOADING_OK; }
	};
	struct stDisMount : public PakHead
	{
		stDisMount(){ wProNO = CMSG_DISMOUNT; }
	};
	struct stInspect : public PakHead
	{
		stInspect(){ wProNO = CMSG_INSPECT; }
		ui64	guid;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << guid; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> guid; return cpu; }
	};
	struct stSet_Sheathed : public PakHead
	{
		stSet_Sheathed(){ wProNO = SET_SHEATHED; }
		ui32	active;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << active; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> active; return cpu; }
	};
	struct stQuery_Pet : public PakHead
	{
		stQuery_Pet(){ wProNO = QUERY_PET_NAME; }
		uint64 petGuid;
		ui32	pet_number;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << petGuid << pet_number; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> petGuid >> pet_number; return cpu; }
	};
	struct stQuery_Page_Text : public PakHead
	{
		stQuery_Page_Text(){ wProNO = QUERY_PAGE_TEXT; }
		ui32	pageid;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << pageid; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> pageid; return cpu; }
	};
	struct stQuery_Name : public PakHead
	{
		stQuery_Name(){ wProNO = QUERY_NAME; }
		ui64	guid;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << guid; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> guid; return cpu; }
	};
	struct stQuery_Time : public PakHead
	{
		stQuery_Time(){ wProNO = QUERY_TIME; }
	};
	struct stQuery_Creature : public PakHead
	{
		stQuery_Creature(){ wProNO = QUERY_CREATURE; }
		ui64	guid;
		ui32	entry;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << guid << entry; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> guid >> entry; return cpu; }
	};
	struct stQuery_GameObj : public PakHead
	{
		stQuery_GameObj(){ wProNO = QUERY_GAMEOBJECT; }
		ui64	guid;
		ui32	entry;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << guid << entry; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> guid >> entry; return cpu; }
	};
	struct stReset_Instance : public PakHead
	{
		stReset_Instance(){ wProNO = CMSG_RESET_INSTANCE; }
	};
	struct stSummon_Response : public PakHead
	{
		stSummon_Response(){ wProNO = CMSG_SUMMON_RESPONSE; }
	};
	struct stPlayed_Time: public PakHead
	{
		stPlayed_Time(){ wProNO = CMSG_PLAYED_TIME; }
	};
	struct stTutorial_Reset: public PakHead
	{
		stTutorial_Reset(){ wProNO = TUTORIAL_RESET; }
	};
	struct stTutorial_Clear : public PakHead
	{
		stTutorial_Clear(){ wProNO = TUTORIAL_CLEAR; }
	};
	struct stTutorial_Flag : public PakHead
	{
		stTutorial_Flag(){ wProNO = TUTORIAL_FLAG; }
		ui32 flag;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << flag; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> flag; return cpu; }
	};
	struct stGameObj_Use : public PakHead
	{
		stGameObj_Use(){ wProNO = GAMEOBJ_USE; }
		ui64	guid;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << guid; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> guid; return cpu; }
	};
	struct stToggle_PVP : public PakHead
	{
		stToggle_PVP(){ wProNO = CMSG_TOGGLE_PVP; }
	};
	struct stFaction_Set_Watched_Index : public PakHead
	{
		stFaction_Set_Watched_Index(){ wProNO = CMSG_SET_WATCHED_FACTION_INDEX; }
		uint32 factionid;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << factionid; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> factionid; return cpu; }
	};

	struct stActionButton_Set : public PakHead
	{
		stActionButton_Set(){ wProNO = CMSG_SET_ACTION_BUTTON; }
		uint8 button, misc, type; 
		uint32 action; 
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << button << misc << type << action; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> button >> misc >> type >> action; return cpu; }
	};
	struct stActionBar_Set_Toggles : public PakHead
	{
		stActionBar_Set_Toggles(){ wProNO = CMSG_SET_ACTIONBAR_TOGGLES; }
		uint8 cActionBarId; 
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << cActionBarId; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> cActionBarId; return cpu; }
	};
	struct stResurrect_Response : public PakHead
	{
		stResurrect_Response(){ wProNO = CMSG_RESURRECT_RESPONSE; }
		uint64 guid;
		uint8 status;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << guid << status; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> guid >> status; return cpu; }
	};
	struct stCorpse_Reclaim : public PakHead
	{
		stCorpse_Reclaim(){ wProNO = CMSG_RECLAIM_CORPSE; }
		uint64 guid;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << guid; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> guid; return cpu; }
	};
	struct stBugReport : public PakHead
	{
		stBugReport(){ wProNO = CMSG_BUG; }
		uint32 suggestion, contentlen;
		std::string content;
		uint32 typelen;
		std::string type;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << suggestion<<contentlen<<content<<typelen<<type; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> suggestion>>contentlen>>content>>typelen>>type; return cpu; }
	};
	struct stStandState_Change : public PakHead
	{
		stStandState_Change(){ wProNO = CMSG_STANDSTATECHANGE; }
		uint8 animstate;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << animstate; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> animstate; return cpu; }
	};
	struct stSet_Selection : public PakHead
	{
		stSet_Selection(){ wProNO = CMSG_SET_SELECTION; }
		uint64 guid;
		bool ToAttack;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << guid << ToAttack; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> guid >> ToAttack; return cpu; }
	};
	struct stSet_Target : public PakHead
	{
		stSet_Target(){ wProNO = CMSG_SET_TARGET_OBSOLETE; }
		uint64 guid;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << guid; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> guid; return cpu; }
	};
	struct stZone_Update : public PakHead
	{
		stZone_Update(){ wProNO = CMSG_ZONEUPDATE; }
		uint32 newZone;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << newZone; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> newZone; return cpu; }
	};
	struct stLogout_Cancel : public PakHead
	{
		stLogout_Cancel(){ wProNO = CMSG_LOGOUT_CANCEL; }
	};	
	struct stLogout : public PakHead
	{
		stLogout(){ wProNO = CMSG_PLAYER_LOGOUT; }
	};	
	struct stLogout_Request : public PakHead
	{
		stLogout_Request(){ wProNO = CMSG_LOGOUT_REQUEST; }
	};	
	struct stMsg_Who : public PakHead
	{
		stMsg_Who(){ wProNO = MSG_WHO; }
		uint32 min_level;
		uint32 max_level;
		string chatname;
		uint32 class_mask;
		uint32 race_mask;
		uint32 zone_count;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << min_level<<max_level<<chatname<<class_mask<<race_mask<<zone_count; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> min_level>>max_level>>chatname>>class_mask>>race_mask>>zone_count; return cpu; }
	};
	

	struct stMsg_Dungeon_Difficulty : public PakHead
	{
		stMsg_Dungeon_Difficulty(){ wProNO = MSG_DUNGEON_DIFFICULTY; }
		ui32	 instanceType;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << instanceType; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> instanceType; return cpu; }
	};
	struct stMsg_Toggle_Helm : public PakHead
	{
		stMsg_Toggle_Helm(){ wProNO = CMSG_TOGGLE_HELM; }
	};
	struct stMsg_Toggle_Cloak : public PakHead
	{
		stMsg_Toggle_Cloak(){ wProNO = CMSG_TOGGLE_CLOAK; }
	};
	struct stMsg_Complete_Cinematic : public PakHead
	{
		stMsg_Complete_Cinematic(){ wProNO = CMSG_COMPLETE_CINEMATIC; }
	};

	struct stMSG_Repop_Request : public PakHead
	{
		stMSG_Repop_Request(){ wProNO = CMSG_REPOP_REQUEST; }
	};
	struct stArea_Trigger : public PakHead
	{
		stArea_Trigger(){ wProNO = AREA_TRIGGER; }
		ui32	id;

		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << id; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> id; return cpu; }
	};
	//	随即rool一个道具
	struct stMsg_Random_Roll : public PakHead
	{
		stMsg_Random_Roll(){ wProNO = MSG_RANDOM_ROLL; }
		uint32 min, max;

		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << min << max; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> min >> max; return cpu; }
	};
	
	
	struct stLoginReq : public PakHead 
	{
		stLoginReq(){ wProNO = LOGIN_REQ; }
		ui32		nIP;
		ui32		nAccountID;
		ui32		nSession;

		CPacketSn& Sn(CPacketSn& cps) const {PakHead::Sn(cps) << nIP << nAccountID << nSession; return cps;}
		CPacketUsn& Usn(CPacketUsn& cpu) {PakHead::Usn(cpu) >> nIP >> nAccountID >> nSession; return cpu;}
	};

	struct stCreateRoleReq : public PakHead
	{
		stCreateRoleReq(){ wProNO = CREATEROLE_REQ; }
		ui32 nAccountID;
		string Name;
		ui8 nSex, nRace, nClass;

		CPacketSn& Sn(CPacketSn& cps) const {PakHead::Sn(cps)	<< nAccountID << Name << nRace << nSex << nClass; return cps;}
		CPacketUsn& Usn(CPacketUsn& cpu)	{PakHead::Usn(cpu)	>> nAccountID >> Name >> nRace >> nSex >> nClass; return cpu;}
	};

	struct stRoleListReq : public PakHead
	{
		stRoleListReq(){ wProNO = ROLELIST_REQ; }
		ui32	nAccountID;

		CPacketSn& Sn(CPacketSn& cps) const {PakHead::Sn(cps) << nAccountID; return cps;}
		CPacketUsn& Usn(CPacketUsn& cpu) {PakHead::Usn(cpu) >> nAccountID; return cpu;}
	};

	struct stDelRoleReq : public PakHead 
	{
		stDelRoleReq(){ wProNO = DELROLE_REQ; }
		ui64 guid;
		ui32 nAccountID;
		CPacketSn& Sn(CPacketSn& cps) const {PakHead::Sn(cps) << nAccountID << guid; return cps;}
		CPacketUsn& Usn(CPacketUsn& cpu) {PakHead::Usn(cpu) >> nAccountID >> guid; return cpu;}
	};

	struct stResumeRoleReq : public PakHead
	{
		stResumeRoleReq(){ wProNO = RESUMEROLE_REQ; }
		string strUserID,strRoleName;

		CPacketSn& Sn(CPacketSn& cps) const {PakHead::Sn(cps) << strUserID << strRoleName; return cps;}
		CPacketUsn& Usn(CPacketUsn& cpu) {PakHead::Usn(cpu) >> strUserID >> strRoleName; return cpu;}
	};

	struct stEnterGameReq : public PakHead
	{
		stEnterGameReq(){ wProNO = ENTERGAME_REQ; }
		ui32			AccountID;
		ui64			guid;
		string			strRole;
		string			AccountName;// added by Nathan Gui

		string			strIP;		//client do not need to fill this
		string			GMFlags;	//client do not need to fill this
		ui32			Muted;		//client do not need to fill this
		ui32			Baned;		//client do not need to fill this

		bool	bFangchenmiAccount;//是否是未成年人账号
		uint32	LastLogout;
		uint32	ChenmiTime;//沉迷的游戏时间累积
		
		CPacketSn& Sn(CPacketSn& cps) const {PakHead::Sn(cps) << guid << AccountID << strRole << AccountName << strIP << GMFlags << Muted << Baned << bFangchenmiAccount << LastLogout << ChenmiTime; return cps;}
		CPacketUsn& Usn(CPacketUsn& cpu) {PakHead::Usn(cpu) >> guid >> AccountID >> strRole >> AccountName >> strIP >> GMFlags >> Muted >> Baned >> bFangchenmiAccount >> LastLogout >> ChenmiTime; return cpu;}
	};

	struct stLogoutReq : public PakHead
	{
		stLogoutReq(){ wProNO = LOGOUT_REQ; }
	};

	struct stExitReq : public PakHead 
	{
		stExitReq(){ wProNO = EXIT_REQ; }
		ui32		accountid;
		ui32		guid;
		ui32		sessionid;

		CPacketSn& Sn(CPacketSn& cps) const {PakHead::Sn(cps)  << accountid << guid << sessionid; return cps;}
		CPacketUsn& Usn(CPacketUsn& cpu)	{PakHead::Usn(cpu) >> accountid >> guid >> sessionid; return cpu;}
	};

	struct stQueueInstance : public PakHead
	{
		stQueueInstance(){ wProNO = MSG_QUEUE_INSTANCE; }
		uint32 mapid;

		CPacketSn& Sn(CPacketSn& cps) const {PakHead::Sn(cps) << mapid; return cps;}
		CPacketUsn& Usn(CPacketUsn& cpu) {PakHead::Usn(cpu) >> mapid; return cpu;}
	};

	struct stLeaveQueueInstance : public PakHead
	{
		stLeaveQueueInstance() { wProNO = MSG_LEAVE_QUEUE_INSTANCE; }
		uint32 mapid;

		CPacketSn& Sn(CPacketSn& cps) const {PakHead::Sn(cps) << mapid; return cps;}
		CPacketUsn& Usn(CPacketUsn& cpu) {PakHead::Usn(cpu) >> mapid; return cpu;}
	};

	struct stEnterLeavePVPZone : public PakHead
	{
		uint8 value;// 0 离开pvp或安全区域, 1进入pvp区域, 2进入安全区域
		stEnterLeavePVPZone() { wProNO = MSG_ENTER_LEAVE_PVP_ZONE; }
		CPacketSn& Sn(CPacketSn& cps) const {PakHead::Sn(cps) << value; return cps;}
		CPacketUsn& Usn(CPacketUsn& cpu) {PakHead::Usn(cpu) >> value; return cpu;}
	};

	struct stJingLianContainerMoveItemReq : public PakHead
	{
		stJingLianContainerMoveItemReq() { wProNO = MSG_JINGLIAN_CONTAINER_MOVE_ITEM_REQ; }
		uint8 container_slot;
		uint8 slot;
		uint8 jinglian_container_slot;
		uint8 to_inventory;
		CPacketSn& Sn(CPacketSn& cps) const {PakHead::Sn(cps) << container_slot << slot << jinglian_container_slot << to_inventory; return cps;}
		CPacketUsn& Usn(CPacketUsn& cpu) {PakHead::Usn(cpu) >> container_slot >> slot >> jinglian_container_slot >> to_inventory; return cpu;}
	};

	struct stJingLianItemReq : public PakHead
	{
		stJingLianItemReq() { wProNO = MSG_JINGLIAN_ITEM_REQ; }
	};

	struct stXiangqianContainerMoveItemReq : public PakHead
	{
		stXiangqianContainerMoveItemReq() { wProNO = MSG_XIANGQIAN_CONTAINER_MOVE_ITEM_REQ; }

		uint8 container_slot;
		uint8 slot;
		uint8 xiangqian_container_slot;
		uint8 to_inventory;
		CPacketSn& Sn(CPacketSn& cps) const {PakHead::Sn(cps) << container_slot << slot << xiangqian_container_slot << to_inventory; return cps;}
		CPacketUsn& Usn(CPacketUsn& cpu) {PakHead::Usn(cpu) >> container_slot >> slot >> xiangqian_container_slot >> to_inventory; return cpu;}
	};
	
	struct stXiangqianItemReq : public PakHead
	{
		stXiangqianItemReq() { wProNO = MSG_XIANGQIAN_ITEM_REQ; }
	};

	struct stRecruitReq : public PakHead
	{
		stRecruitReq() { wProNO = MSG_RECRUIT_REQ; }
		std::string student;

		CPacketSn& Sn(CPacketSn& cps) const {PakHead::Sn(cps) << student; return cps;}
		CPacketUsn& Usn(CPacketUsn& cpu) {PakHead::Usn(cpu) >> student; return cpu;}
	};

	struct stRecruitReply : public PakHead
	{
		stRecruitReply() { wProNO = MSG_RECRUIT_REPLY; }
		uint8 accept;

		CPacketSn& Sn(CPacketSn& cps) const {PakHead::Sn(cps) << accept; return cps;}
		CPacketUsn& Usn(CPacketUsn& cpu) {PakHead::Usn(cpu) >> accept; return cpu;}
	};

	struct stLadderReq : public PakHead
	{
		stLadderReq() { wProNO = MSG_LADDER_REQ; }
	};
};

//Client <<====>> Gate Server
/*
		#define CL_GT_LOGIN_REQ			GT_CS_LOGIN_REQ		//账号上线请求
		#define GT_CL_LOGIN_ACK			CS_GT_LOGIN_ACK		//账号上线回应
		#define CL_GT_EXIT_REQ			GT_CS_EXIT_REQ		//账号下线请求
		#define CL_GT_ENTERGAME_REQ		GT_GS_ENTERGAME_REQ		//角色进入游戏世界
		#define GT_CL_ENTERGAME_ACK		GS_GT_ENTERGAME_ACK		//回应角色进入游戏
		#define CL_GT_LOGOUT_REQ		GT_GS_LOGOUT_REQ		//小退
		#define GT_CL_LOGOUT_ACK		GS_GT_LOGOUT_ACK		//小退响应
		#define CL_GT_CREATEROLE_REQ	GT_DB_CREATEROLE_REQ		//请求创建角色
		#define	GT_CL_CREATEROLE_ACK	DB_GT_CREATEROLE_ACK		//回应创建角色
		#define CL_GT_ROLELIST_REQ		GT_DB_ROLELIST_REQ			//请求账号角色信息
		#define GT_CL_ROLELIST_ACK		DB_GT_ROLELIST_ACK			//回应账号角色信息
		#define CL_GT_DELROLE_REQ		GT_DB_DELROLE_REQ			//请求删除角色
		#define GT_CL_DELROLE_ACK		DB_GT_DELROLE_ACK			//响应删除角色
		#define CL_GT_RESUMEROLE_REQ	GT_DB_RESUMEROLE_REQ		//请求恢复角色
		#define GT_CL_RESUMEROLE_ACK	DB_GT_RESUMEROLE_ACK		//响应恢复角色
		#define GT_CL_PLAYER_APPEAR_PKG	GS_GT_PLAYER_APPEAR_PKG		//角色出现包
*/

