#pragma once
#include "PacketDef.h"
#include "Opcodes.h"
#include "../Public/PublicDef.h"
#include "../Public/ItemDef.h"
#include "../Public/UnitDef.h"
#include "../Public/PlayerDef.h"
#include "../Public/ByteBuffer.h"
namespace MSG_S2C
{
	using namespace SDBase;
	enum
	{
		LOGIN_ACK = MSG_BASE_GT2C,
		ENTERGAME_ACK,
		LOGOUT_ACK,
		CREATEROLE_ACK,
		ROLELIST_ACK,
		DELROLE_ACK,
		RESUMEROLE_ACK,

		CREATURE_APPEAR_PKG = MSG_BASE_GS2C,	//出现包(发给周围玩家)
		CREATURE_DISAPPEAR_PKG,				//消失包(怪物的也是一样)
		ENTERMAP_PKG,			//角色进入地图(发给自己)
		CREATURE_DIE_PKG,		//死亡包
		RELIVE_ACK,			//复活回应
		RELIVE_PKG,			//复活消息通知包
		RELIVE_REQ,		//角色行走回应
		CREATURE_MOVE_PKG,		//其它角色行走通知
		PLAYER_RUN_ACK,		//角色跑动回应
		CREATURE_RUN_PKG,		//其它角色跑动通知
		HPMP_PKG,			//HPMP修改通知
		PLAYER_EXP_PKG,		//等级经验通知
		PLAYER_ATTACK_ACK, 	//攻击回应
		PLAYER_ATTACK_PKG,		//其它角色攻击通知
		PLAYER_PROP_PKG,		//角色属性通知
		PLAYER_LEVEL_UP_PKG,		//角色升级通知
		MAPITEM_APPEAR_PKG,				//地图道具出现包
		MAPITEM_DISAPPEAR_PKG,				//地图道具消失包
		ITEM_CONTAINER_PKG,				//道具包
		ITEM_ADD_TO_CONTAINER_PKG,			//添加道具到背包的通知
		ITEM_REMOVE_FROM_CONTAINER_PKG,	//从背包删除道具的通知
		MAPITEM_PICKUP_BST,				//拾取地图道具的广播(暂不用)
		ITEM_MOVE_POS_PKG,					//移动背包道具位置的结果
		APPEARANCE_PKG,					//外观变化
		MONEY_MODIFY,						//金币变化
		TRADELIST,
		ITEM_MODI_NUM_CONTAINER_PKG,		//修改背包中道具数量
		
		//////////////////////////////////////////////////////////////////////////
		//	New Msg
		
		LEVELUP_INFO								,	
		LOG_XPGAIN,
		UPDATE_OBJECT,
		COMPRESSED_UPDATE_OBJECT,		
		DESTROY_OBJECT,
		RAID_GROUP_ONLY							,	
		SMSG_SET_REST_START								,	
		SMSG_SUMMON_REQUEST,
		
		// added by Gui for fee
		ACCOUNT_EXPIRE_IN_FEW_MINUTES,

		//////////////////////////////////////////////////////////////////////////
		//	Move
		//////////////////////////////////////////////////////////////////////////
		MOVE_OP,
		
		MONSTER_MOVE,
		MOVE_FORCE_ROOT,
		MOVE_FORCE_UNROOT,	
		MOVE_WATER_WALK							,	
		MOVE_LAND_WALK								,	

		MOVE_SET_FLY								,	
		MOVE_SET_UNFLY								,	
		
		MOVE_SET_SPEED,

		MOVE_NEW_WORLD									,	
		MOVE_TELEPORT_ACK							,	
		MOVE_MOUNTSPECIAL_ANIM,

		MOVE_KNOCK_BACK								,	
		MOVE_FEATHER_FALL							,	
		MOVE_NORMAL_FALL							,	

		MOVE_SET_HOVER								,	
		MOVE_UNSET_HOVER							,	
		//MSG_MOVE_HOVER									,	
// 		SMSG_SET_WALK_SPEED								,	
// 		SMSG_SET_RUN_BACK_SPEED							,	
// 		SMSG_SET_SWIM_SPEED								,	
// 		SMSG_SET_SWIM_BACK_SPEED						,	
// 		SMSG_SET_TURN_RATE								,	
		MOVE_UNLOCK_MOVEMENT,

		MOUNT_INVITE,
		MOUNT_ACCEPT,
		MOUNT_DECLINE,
		MOUNT_DISBAND,
		MOUNT_RESULT,
		//////////////////////////////////////////////////////////////////////////
		//	Trade
		//////////////////////////////////////////////////////////////////////////

		TRADE_STAT,							//
		TRADE_STATUS_EXTENDED,
		//////////////////////////////////////////////////////////////////////////
		//	Channel
		//////////////////////////////////////////////////////////////////////////
		CHANNEL_LIST,	
		CHANNEL_NOTIFY,	
		CHANNEL_NUM_MEMBERS_QUERY_RESPONSE,
		CHANNEL_AVAILABLE_VOICE,

		//////////////////////////////////////////////////////////////////////////
		//	Chat
		//////////////////////////////////////////////////////////////////////////
		CHAT_MESSAGE,
		EMOTE,	
		CHAT_EMOTE_TEXT,	
		CHAT_PLAYER_NOT_FOUND,	
		CHANNEL_VOICE_SESSION								,	
		SMSG_REPORT_SPAM_RESPONSE						,

		//////////////////////////////////////////////////////////////////////////
		//	Group
		//////////////////////////////////////////////////////////////////////////

		GROUP_INVITE                ,			//	对方邀请你
		GROUP_DECLINE          ,				//	拒绝
		SMSG_GROUP_CANCEL           ,	
		GROUP_UNINVITE         ,
		GROUP_SET_LEADER       ,
		GROUP_SET_PLAYER_ICON,
		GROUP_DESTROYED        ,
		GROUP_LIST             ,
		GROUP_MEMBER_STAT,
		PARTY_MEMBER_STATS,
		PARTY_COMMAND_RESULT,
		PARTY_KILL_LOG,
		MINIMAP_PING,

		//UMSG_UPDATE_GROUP_MEMBERS						,	
		RAID_READYCHECK							,	

		START_MIRROR_TIMER,
		PAUSE_MIRROR_TIMER,
		STOP_MIRROR_TIMER,
		//////////////////////////////////////////////////////////////////////////
		//	Guild
		//////////////////////////////////////////////////////////////////////////
		GUILD_EVENT								,	
		GUILD_INVITE								,	
		GUILD_DECLINE								,	
		GUILD_INFO									,	
		GUILD_ROSTER								,	
		GUILD_COMMAND_RESULT						,	
		GUILD_UPDATE								,	
		GUILD_LOG									,
		GUILD_SAVE_EMBLEM							,	
		GUILD_BANK_LOG								,
		GUILD_GET_FULL_PERMISSIONS					,
		GUILD_BANK_GET_AVAILABLE_AMOUNT				,
		GUILD_BANK_VIEW_RESPONSE					,
		GUILD_QUERY_RESPONSE						,	

		GUILD_PETITION_DECLINE							,	
		GUILD_PETITION_SHOW_SIGNATURES					,	
		GUILD_PETITION_SIGN_RESULTS						,	
		GUILD_TURN_IN_PETITION_RESULTS					,	
		GUILD_PETITION_QUERY_RESPONSE					,	
		GUILD_PETITION_RENAME							,	
		GUILD_SET_MEMBER_RANK_ACK						,

		GUILD_LIST_INFO_ACK,
		GUILD_DECLARE_WAR_NOTIFY,
		GUILD_ALLY_REQ_NOTIFY,
		GUILD_ALLY_ACK,
		GUILD_ALLY_STATE_NOTIFY,
		GUILD_CONTRIBUTION_POINTS_NOTIFY,

		FRIEND_LIST								,	
		FRIEND_STATUS								,	

		//////////////////////////////////////////////////////////////////////////
		//	Player
		//////////////////////////////////////////////////////////////////////////
		SPELLS_INITIAL,				//	登陆后发送已学会的技能信息
		//////////////////////////////////////////////////////////////////////////
		//	Fight
		//////////////////////////////////////////////////////////////////////////

		SPELL_START,	
		SPELL_GO,
		SPELL_CAST_RESULT,	
		SPELL_FAILURE,
		SPELL_COOLDOWN,
		SPELL_COOLDOWN_EVENT,
		SPELL_LOG_EXECUTE,	
		SPELL_HEALMANAON_PLAYER,
		SPELL_HEAL_ON_PLAYER,	
		SPELL_DELAYED,
		SPELL_TARGET_CAST_RESULT,	
		SPELL_CLEAR_COOLDOWN								,	
		//SMSG_COOLDOWN_CHEAT								,	

		SPELL_PLAY_VISUAL,	

		SPELL_DAMAGE_SHIELD,	

		SPELL_CHANNEL_START,	
		SPELL_CHANNEL_UPDATE,	

		SPELL_RESURRECT_REQUEST,	

		SMSG_RESURRECT_FAILED							,	

		SPELL_NONMELEE_DAMAGE_LOG,	
		SPELL_LOG_MISS,
		SPELL_DISPEL_LOG								,	
		SPELL_LEARNED							,	
		SPELL_SUPERCEDED,	

		//SMSG_SPELLORDAMAGE_IMMUNE						,	
		SPELL_SET_FLAT_MODIFIER					,	
		//SMSG_SET_PCT_SPELL_MODIFIER						,	
		
		CANCEL_AUTO_REPEAT							,	
		SPELL_REMOVED,	


		ATTACKER_STATE_UPDATE,
		ATTACK_START,	
		ATTACK_STOP,	

		TARGET_CLEAR,

		ATTACKSWING_NOTINRANGE						,	
		ATTACKSWING_BADFACING						,	
		//SMSG_ATTACKSWING_NOTSTANDING					,	
		//SMSG_ATTACKSWING_DEADTARGET						,	
		//SMSG_ATTACKSWING_CANT_ATTACK					,	
		//SMSG_VICTIMSTATEUPDATE_OBSOLETE					,	
		//SMSG_DAMAGE_DONE_OBSOLETE						,	
		//SMSG_DAMAGE_TAKEN_OBSOLETE						,	
		COMBAT_CANCEL								,	
		//SMSG_PLAYER_COMBAT_XP_GAIN_OBSOLETE				,	

		AURA_PERIODIC_LOG,
		AURA_SET_DURATION,
		AURA_SET_SINGLE,

		AURA_UPDATE_DURATION,
		AURA_SET_EXTRA_INFO,

		SET_COMBO_POINTS							,	
		//SMSG_SET_AURA_MULTIPLE							,  

		DAMAGE_ENVIRONMENTAL_LOG,	

		ZONE_UNDER_ATTACK							,	
		SMSG_SET_FORCED_REACTIONS						,	
		SMSG_SPIRIT_HEALER_POS							,	
		SMSG_CORPSE_RECLAIM_DELAY						,	

		//////////////////////////////////////////////////////////////////////////
		//	BattleGround
		//////////////////////////////////////////////////////////////////////////
		AREA_SPIRIT_HEALER_TIME					,	
		AREA_SPIRIT_HEALER_QUEUE,
		INSPECT_HONOR_STATS,
		INSPECT_ARENA_STATS							,	
		BATTLEGROUND_PLAYER_JOINED					,	
		BATTLEFIELD_STATUS							,	
		BATTLEGROUND_PLAYER_LEFT					,	
		BATTLEGROUND_INIT_WORLD_STATES							,	
		BATTLEFIELD_LIST							,	
		BATTLEGROUN_UPDATE_WORLD_STATE							,	
		BATTLEGROUND_GROUP_JOINED					,	

// 		SMSG_BATTLEFIELD_WIN							,	
// 		SMSG_BATTLEFIELD_LOSE							,	
PVP_LOG_DATA								,	
PVP_CREDIT									,	

		//////////////////////////////////////////////////////////////////////////
		//	Faction
		//////////////////////////////////////////////////////////////////////////
		SMSG_INITIALIZE_FACTIONS					,	//(0x0122)
		SMSG_SET_FACTION_VISIBLE					,	//(0x0123)
		SMSG_SET_FACTION_STANDING					,	//(0x0124)

		//////////////////////////////////////////////////////////////////////////
		//	AI
		//////////////////////////////////////////////////////////////////////////
		AI_REACTION,
		AI_SWITCH_ACTIVE_MOVER,

		//////////////////////////////////////////////////////////////////////////
		//	Pet
		//////////////////////////////////////////////////////////////////////////
		PET_TAME_FAILURE							,	
		PET_NAME_INVALID							,	
		PET_SPELLS_MSG									,	
		PET_MODE									,	
		PET_ACTION_SOUND							,	
		//SMSG_PET_DISMISS_SOUND							,	
		PET_UNLEARN_CONFIRM						,	
		//SMSG_PET_ACTION_FEEDBACK						,	
// 		SMSG_PET_TAME_UNK								,	
// 		SMSG_UNKNOWN_PET								,	
//SMSG_PET_CAST_FAILED							,	
//SMSG_PET_BROKEN									,	
PET_STABLE_RESULT								,	
PETS_LIST_STABLED							,	

		//////////////////////////////////////////////////////////////////////////
		//	Duel
		//////////////////////////////////////////////////////////////////////////
		DUEL_REQUESTED								,	
		DUEL_OUTOFBOUNDS							,	
		DUEL_INBOUNDS								,	
		DUEL_COMPLETE								,	
		DUEL_WINNER								,	
		DUEL_COUNTDOWN								,	

		//////////////////////////////////////////////////////////////////////////
		//	Item
		//////////////////////////////////////////////////////////////////////////
		ITEM_BUY,
		ITEM_BUY_FAILURE,						//	购买失败消息
		ITEM_SELL,
		ITEM_COOLDOWN,
		INVENTORY_CHANGE_FAILURE,			//	道具移动失败消息
		ITEM_SELL_FAILURE,						//	卖出失败消息
		ITEM_TIME_UPDATE,
		ITEM_ENCHANT_TIME_UPDATE					,	
		ITEM_PUSH_RESULT,					//	添加道具消息
		ITEM_QUERY_SINGLE_RESPONSE,			//	道具详细信息
		READ_ITEM_RET,						//	读取道具的结果
		LIST_INVENTORY,						//	出售道具的列表

		ITEM_INVENTORY_CHANGE_FAILURE,	

		ITEM_READ_OK,
		//SMSG_READ_ITEM_FAILED							,	
		ITEM_NAME_QUERY_RESPONSE					,	
		MSG_SPLIT_MONEY									,	
		ITEM_ENCHANTMENT_LOG								,	

		//SMSG_BUY_BANK_SLOT_RESULT						,	

		//////////////////////////////////////////////////////////////////////////
		//	Area
		//////////////////////////////////////////////////////////////////////////
		AREA_TRIGGER_MESSAGE,	
		AREA_EXPLORATION_EXPERIENCE,	

		TRANSFER_PENDING							,	
		TRANSFER_ABORTED							,	

		//////////////////////////////////////////////////////////////////////////
		//	ArenaTeam
		//////////////////////////////////////////////////////////////////////////
		ARENA_TEAM_QUERY_RESPONSE,	
		ARENA_TEAM_COMMAND_RESULT,	
		ARENA_TEAM_ROSTER,	
		ARENA_TEAM_INVITE,	
		ARENA_TEAM_STATS,	
		//SMSG_ARENA_NO_TEAM								,	

		//////////////////////////////////////////////////////////////////////////
		//	Auction
		//////////////////////////////////////////////////////////////////////////
		AUCTION_COMMAND_RESULT,	
		AUCTION_LIST_RESULT,	
		AUCTION_OWNER_LIST_RESULT,	
		AUCTION_BIDDER_NOTIFICATION,	
		AUCTION_OWNER_NOTIFICATION,	
		AUCTION_BIDDER_LIST_RESULT,	
		AUCTION_HELLO,

		//////////////////////////////////////////////////////////////////////////
		//	Quest
		//////////////////////////////////////////////////////////////////////////
		QUESTGIVER_STATUS,	
		QUESTGIVER_QUEST_DETAILS,	
		QUESTGIVER_QUEST_LIST,	

		QUESTGIVER_REQUEST_ITEMS					,	
		QUESTGIVER_OFFER_REWARD					,	
		QUESTGIVER_QUEST_INVALID					,	
		QUESTGIVER_QUEST_COMPLETE					,	
		QUESTGIVER_QUEST_FAILED					,	

		QUESTGIVER_INRANGE_STATUS_QUERY_RESPONSE	,

		QUESTLOG_FULL								,	
		QUESTUPDATE_FAILED							,	
		QUESTUPDATE_FAILEDTIMER					,	
		QUESTUPDATE_COMPLETE						,	
		QUESTUPDATE_ADD_KILL						,	
		QUESTUPDATE_ADD_ITEM						,	
		QUEST_CONFIRM_ACCEPT						,	


		QUEST_PUSH_RESULT,
		//////////////////////////////////////////////////////////////////////////
		//	NPC
		//////////////////////////////////////////////////////////////////////////
		NPC_TABARDVENDOR_ACTIVATE,
		NPC_SHOW_BANK									,	
		NPC_TRAINER_LIST								,	
		NPC_PETITION_SHOWLIST							,	
		NPC_GOSSIP_MESSAGE								,	
		NPC_TEXT_UPDATE							,	
		NPC_GOSSIP_COMPLETE,
		NPC_BINDER_CONFIRM								,	
		NPC_BINDPOINTUPDATE							,	
		NPC_PLAYERBOUND								,	
		NPC_SPIRIT_HEALER_CONFIRM						,	
		NPC_GOSSIP_POI									,	
		//SMSG_NPC_WONT_TALK								,	

		//////////////////////////////////////////////////////////////////////////
		//	Mail
		//////////////////////////////////////////////////////////////////////////
		MAIL_TEXT_QUERY_RESPONSE					,	
		MAIL_RECEIVED							,	
		MAIL_LIST_RESULT							,	
		MAIL_SEND_RESULT							,	
		MAIL_QUERY_NEXT_TIME						,	

		//////////////////////////////////////////////////////////////////////////
		//	Skill
		//////////////////////////////////////////////////////////////////////////

		//////////////////////////////////////////////////////////////////////////
		//	Loot
		//////////////////////////////////////////////////////////////////////////
		MSG_RANDOM_ROLL,
		LOOT_REMOVED								,	
		LOOT_ROLL_WON								,	
		LOOT_ALL_PASSED							,	
		SMSG_LOOT_CLEAR_MONEY							,	
		SMSG_LOOT_MONEY_NOTIFY							,	
		SMSG_LOOT_MASTER_LIST							,	
		SMSG_LOOT_RELEASE_RESPONSE						,	
		LOOT_START_ROLL							,	
		LOOT_ROLL									,	
		LOOT_RESPONSE								,	
		SMSG_LOOT_ITEM_NOTIFY							,	

		//////////////////////////////////////////////////////////////////////////
		//	Other
		//////////////////////////////////////////////////////////////////////////
		MSG_DUNGEON_DIFFICULTY,
		SMSG_GAMEOBJECT_DESPAWN_ANIM					,	
		SMSG_QUERY_OBJECT_POSITION					,	
		SMSG_QUERY_OBJECT_ROTATION					,	
		SMSG_ZONE_MAP									,	
		SMSG_FORCEACTIONSHOW							,	
		SMSG_GODMODE									,	
		SMSG_GAMETIME_UPDATE							,	
		SMSG_GAMETIME_SET								,	
		SMSG_GAMESPEED_SET								,	
		SMSG_SERVERTIME									,	
		SMSG_WHOIS										,	
		SMSG_OPEN_CONTAINER								,	
		SMSG_INSPECT									,	

		MSG_TABARDVENDOR_ACTIVATE						,	
		SMSG_RWHOIS										,	
		SMSG_RESISTLOG									,	
		SMSG_PONG										,	
		FISH_NOT_HOOKED							,	
		FISH_ESCAPED								,	
		GAMEOBJECT_CUSTOM_ANIM						,	
		PLAY_MUSIC									,	
		PLAY_OBJECT_SOUND							,	
		SERVER_MESSAGE								,	
		SMSG_WEATHER									,	
		SMSG_RESET_INSTANCE								,	
		SMSG_INSTANCE_SAVE								,	
		SMSG_INSTANCE_RESET_ACTIVATE					,	
		SMSG_RAID_INSTANCE_INFO							,	
		SMSG_PLAYER_SKINNED								,	

		//////////////////////////////////////////////////////////////////////////
		//	Taxi
		//////////////////////////////////////////////////////////////////////////
		TAXI_SHOW_NODES								,	
		TAXI_NODE_STATUS							,	
		TAXI_ACTIVATE_REPLY							,	
		TAXI_NEW_PATH								,	

		MSG_TALENT_WIPE_CONFIRM							,	


		MSG_WHO										,	
		SMSG_LOGOUT_RESPONSE							,	
		SMSG_PLAYED_TIME								,	
		SMSG_INSPECT_TALENTS                            ,

		SMSG_VOICE_SYSTEM_STATUS						,
		SMSG_DISABLE_MICROPHONE							,  // manual added its a result for CMSG_ENABLE_MICROPHONE

		ACTION_BUTTONS								,	

		SET_PROFICIENCY							,	

		SMSG_PLAY_SOUND									,	
		//////////////////////////////////////////////////////////////////////////
		//	Query
		//////////////////////////////////////////////////////////////////////////
		QUERY_RESPONSE						,	
		QUERY_TIME_RESPONSE						,	
		QUERY_CREATURE_RESPONSE					,	
		QUERY_GAMEOBJECT_RESPONSE					,	
		QUERY_CORPSE_RESPONSE					,	
		QUERY_PAGE_TEXT_RESPONSE					,	
		QUERY_PET_NAME_RESPONSE					,	
		QUERY_QUEST_RESPONSE						,	
		//SMSG_GAMEOBJECT_PAGETEXT						,	
		//////////////////////////////////////////////////////////////////////////
		//	GM
		//////////////////////////////////////////////////////////////////////////
		SMSG_GMTICKET_GETTICKET							,	
		SMSG_GM_PLAYER_INFO								,	
		SMSG_GMTICKET_DELETETICKET						,	
		SMSG_GMTICKET_SYSTEMSTATUS						,	
		MSG_GM_BIND_OTHER								,	
		MSG_GM_SUMMON									,	
		MSG_GM_SHOWLABEL								,	
		SMSG_GMTICKET_CREATE							,	
		SMSG_GMTICKET_UPDATETEXT						,	

		
		TUTORIAL_FLAGS								,	
		LOGIN_SETTIMESPEED							,	

		NOTIFY_MSG,						

		AI_DIED,


		//////////////////////////////////////////////////////////////////////////
		// Contribution
		//////////////////////////////////////////////////////////////////////////
		CONTRIBUTION_CONFIRM_RESULT,
		SELF_CONTRIBUTION_HISTORY_RESPONSE,
		CONTRIBUTION_BILLBOARD_RESPONSE,
		CONTRIBUTION_QUERY_RESULT,

		SHOP_ITEMLIST,

		MAIL_ERROR,

		GUILD_CREATE,

		COPY_NAME,
		HIDE_GM,

		SYSTEM_TIPS,

		MSG_TRADE_SWITCH,
		MSG_TARGET_FORBID_TRADE,

		MSG_QUEUE_INSTANCE_UPDATE,
		MSG_ENTER_INSTANCE_COUNT_DOWN,
		MSG_ARENA_UPDATE_STATE,
		MSG_INSTANCE_BILLBOARD,
		MSG_PLAYER_LEAVE_INSTANCE,
		MSG_PLAYER_ENTER_INSTANCE,
		MSG_SUNYOU_INSTANCE_LIST,

		MSG_SYSTEM_GIFT,
		MSG_SYSTEM_GIFT_NOTIFY,
		MSG_SYSTEM_NOTIFY_TOP_MOVE,
		MSG_SYSTEM_NOTIFY_TOP_ADD,
		MSG_SYSTEM_NOTIFY_TOP_REMOVE,
		MSG_SYSTEM_NOTIFY_TOP_CENTER,
		MSG_ENTER_LEAVE_PVP_ZONE_NOTIFY,
		MSG_JINGLIAN_ITEM_ACK,
		MSG_XIANGQIAN_ITEM_ACK,
		MSG_FINISHQUESTS,

		MSG_RECRUIT_NOTIFY,
		MSG_RECRUIT_ACK,

		MSG_CHOICE_WHILE_IN_INSTANCE,//逃亡副本里死亡后是否推出副本
		MSG_CASTLE_NPC_STATE_NOTIFY,

		MSG_CASTLE_STATE_ACK,
		MSG_CASTLE_COUNT_DOWN,
		
		MSG_MESSAGE_BOX,

		MSG_LADDER_ACK,

		MSG_BATTLE_GROUND_POWER_UPDATE,

		MSG_TITLE_LIST,
		MSG_TITLE_ADD,
		MSG_TITLE_REMOVE,

		MSG_QUEST_ESCORT_NOTIFY,
		MSG_ON_ITEM_FIELD_RECORD_CHANGE,
		MSG_RESERVED1,
		MSG_RESERVED2,
		MSG_RESERVED3,
		MSG_RESERVED4,
		MSG_RESERVED5,

//#ifdef _ACTIVITY_PROTOCOL
		// for activity tool
		MSG_ACT_TOOL_ACCESS_ACK,
		MSG_ACTIVITY_LIST_ACK,
		MSG_UPDATE_ACTIVITY_ACK,
		MSG_REMOVE_ACTIVITY_ACK,
		MSG_DUTY_CHANGE_NOTIFY,
//#endif
		//////////////////////////////////////////////////////////////////////////

		MSG_QUERY_PLAYERS_ACK,

		MSG_DONATE_ACK,
		
		MSG_DONATION_LADDER_ACK,
		MSG_DONATION_EVENT_LIST,
		MSG_DONATION_HISTORY,

		MSG_CC_RESULT,

		MSG_BATTLE_GROUND_SPECIAL_NOTIFY,

		MSG_CREDIT_APPLY_ACK,
		MSG_CREDIT_ACTION_ACK,
		MSG_CREDIT_HISTORY_ACK,
		
		MSG_DONATE_ADD_HISTROY,

		MSG_GROUP_SWEP,
		MSG_CHANGE_SUBGROUP,
		MSG_REMOVE_MEMBER,
		MSG_ADD_MEMBER,

		MSG_PLAY_SOUND_NOTIFY,

		MSG_BATTLE_GROUND_RESOURCE_UPDATE,

		MSG_SCREEN_SHAKE,
		MSG_SCENE_EFFECT,
		MSG_BATTLE_GROUND_DETAIL_INFORMATION,
		MSG_CREATURE_FORCE_PLAY_ANIMATION,
		NUM_MSG_TYPES,
	};

	struct stCreatureForcePlayAnimation : public PakHead
	{
		stCreatureForcePlayAnimation() { wProNO = MSG_CREATURE_FORCE_PLAY_ANIMATION; }
		uint64 CreatureID;
		uint16 AnimationID;

		CPacketSn& Sn(CPacketSn& cps) const { PakHead::Sn(cps); cps << CreatureID << AnimationID; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)    { PakHead::Usn(cpu);cpu >> CreatureID >> AnimationID; return cpu; }
	};

	struct stBattleGroundDetailInformation : public PakHead
	{
		stBattleGroundDetailInformation() { wProNO = MSG_BATTLE_GROUND_DETAIL_INFORMATION; }
		std::vector<battle_ground_player_detail_information> v;
		uint8 WinnerRace;

		CPacketSn& Sn(CPacketSn& cps) const { PakHead::Sn(cps); cps << v << WinnerRace; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)    { PakHead::Usn(cpu);cpu >> v >> WinnerRace; return cpu; }
	};

	struct stSceneEffect : public PakHead
	{
		stSceneEffect() { wProNO = MSG_SCENE_EFFECT; }

		std::string effect_file_name;
		int loop_count;
		float x;
		float y;
		float z;
		float scale;						// effect scale
		std::string sound_file_name;
		int play_sound_delay;			// ms

		CPacketSn& Sn(CPacketSn& cps) const { PakHead::Sn(cps); cps << effect_file_name << loop_count << x << y << z << scale << sound_file_name << play_sound_delay; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)    { PakHead::Usn(cpu);cpu >> effect_file_name >> loop_count >> x >> y >> z >> scale >> sound_file_name >> play_sound_delay; return cpu; }
	};

	struct stScreenShake : public PakHead
	{
		stScreenShake() { wProNO = MSG_SCREEN_SHAKE; }
		
		int duration;		// seconds

		CPacketSn& Sn(CPacketSn& cps) const { PakHead::Sn(cps); cps << duration; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)    { PakHead::Usn(cpu);cpu >> duration; return cpu; }
	};

	struct stBattleGroundResourceUpdate : public PakHead
	{
		stBattleGroundResourceUpdate() { wProNO = MSG_BATTLE_GROUND_RESOURCE_UPDATE; }
		uint16 resource[3];			// 资源数 数组下标 0 ~ 2  妖 人 巫
		uint8 player_count[3];		// 人数 数组下标 0 ~ 2  妖 人 巫
		int8 banner_owner_state[5];	// 旗帜所有者状态。 0 无人占领
													//	1~3 妖人巫占领
													//	11~13 从无人占领到妖人巫占领
													//	21~23 从妖占领到妖人巫占领
													//	31~33 从人占领到妖人巫占领
													//	41~43 从巫占领到妖人巫占领
													//	最多5面旗帜

		// 人数和资源都为0时 界面不显示

		CPacketSn& Sn(CPacketSn& cps) const { PakHead::Sn(cps); cps.AddBuf( resource, sizeof( resource ) ); cps.AddBuf( player_count, sizeof( player_count ) ); cps.AddBuf( banner_owner_state, sizeof( banner_owner_state ) ); return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)    { PakHead::Usn(cpu);cpu.GetBuf( resource, sizeof( resource ) ); cpu.GetBuf( player_count, sizeof( player_count ) ); cpu.GetBuf( banner_owner_state, sizeof( banner_owner_state ) ); return cpu; }
	};

	struct stPlaySoundNotify : public PakHead
	{
		stPlaySoundNotify() { wProNO = MSG_PLAY_SOUND_NOTIFY; }
		uint64 Sound3DBindObjectID;
		std::string SourceFile;

		CPacketSn& Sn(CPacketSn& cps) const { PakHead::Sn(cps); cps << Sound3DBindObjectID << SourceFile; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)    { PakHead::Usn(cpu);cpu >> Sound3DBindObjectID >> SourceFile; return cpu; }
	};

	struct stCreditApplyAck : public PakHead
	{
		stCreditApplyAck() { wProNO = MSG_CREDIT_APPLY_ACK; }

		enum { CREDIT_APPLY_SUCCESS, CREDIT_APPLY_ALREADY_HAVE, CREDIT_APPLY_LEVEL_LESS_80, CREDIT_APPLY_NOT_ENOUGH_GOLD, CREDIT_APPLY_SYSTEM_BUSY, };
		uint8 result;

		CPacketSn& Sn(CPacketSn& cps) const { PakHead::Sn(cps); cps << result; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)    { PakHead::Usn(cpu);cpu >> result; return cpu; }
	};

	struct stCreditActionAck : public PakHead
	{
		stCreditActionAck() { wProNO = MSG_CREDIT_ACTION_ACK; }

		enum { CREDIT_ACTION_SUCCESS, CREDIT_ACTION_NOT_ENOUGH_YUANBAO, CREDIT_ACTION_SYSTEM_BUSY, };
		uint8 result;
		uint8 is_restore;

		CPacketSn& Sn(CPacketSn& cps) const { PakHead::Sn(cps); cps << result << is_restore; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)    { PakHead::Usn(cpu);cpu >> result >> is_restore; return cpu; }
	};

	struct stCreditHistoryAck : public PakHead
	{
		stCreditHistoryAck() { wProNO = MSG_CREDIT_HISTORY_ACK; }

		struct _history
		{
			int yuanbao;		// 负的为转帐，正的为还款
			uint32 datetime;	// unixtime

			CPacketSn& Sn(CPacketSn& cps) const { cps << yuanbao << datetime; return cps; }
			CPacketUsn& Usn(CPacketUsn& cpu)    { cpu >> yuanbao >> datetime; return cpu; }
		};
		std::vector<_history> v;

		CPacketSn& Sn(CPacketSn& cps) const { PakHead::Sn(cps); cps << v; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)    { PakHead::Usn(cpu);cpu >> v; return cpu; }
	};

	struct stBattleGroundSpecialNotify : public PakHead
	{
		stBattleGroundSpecialNotify() { wProNO = MSG_BATTLE_GROUND_SPECIAL_NOTIFY; }
		
		std::string who;
		uint32 state;
		bool is_break;
		std::string who_break;
		
		CPacketSn& Sn(CPacketSn& cps) const { PakHead::Sn(cps); cps << who << state << is_break << who_break; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)    { PakHead::Usn(cpu);cpu >> who >> state >> is_break >> who_break; return cpu; }
	};

	struct stCCResult : public PakHead
	{
		stCCResult() { wProNO = MSG_CC_RESULT; }

		enum { _STUN, _ROOT, _FEAR, _SLOW, _DAMAGE, _SILENCE, _TAUNT };
		enum { _IMMUNE, _RESIST };

		uint32 spellid;
		uint8 effect;
		uint8 result;
		uint64 casterid;
		uint64 victimid;
		CPacketSn& Sn(CPacketSn& cps) const { PakHead::Sn(cps); cps << spellid << effect << result << casterid << victimid; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)    { PakHead::Usn(cpu);cpu >> spellid >> effect >> result >> casterid >> victimid; return cpu; }
	};

	struct stDonateAck : public PakHead
	{
		stDonateAck() { wProNO = MSG_DONATE_ACK; }

		enum { DONATE_RESULT_OK, DONATE_RESULT_NOT_ENOUGH_YUANBAO, DONATE_RESULT_EXPIRE, DONATE_NOT_FOUND, DONATE_SYSTEM_ERROR };
		uint8 result;
		
		CPacketSn& Sn(CPacketSn& cps) const { PakHead::Sn(cps); cps << result; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)    { PakHead::Usn(cpu);cpu >> result; return cpu; }
	};
	
	struct stAddDonateHistroy : PakHead
	{
		stAddDonateHistroy() { wProNO = MSG_DONATE_ADD_HISTROY; }
		
		uint32 event_id;
		uint32 datatime;
		uint32 yuanbao;

		CPacketSn& Sn(CPacketSn& cps) const { PakHead::Sn(cps); cps << event_id << datatime << yuanbao ; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{ PakHead::Usn(cpu); cpu >> event_id >> datatime >> yuanbao ; return cpu;}
	};
	struct stDonationLadderAck : public PakHead
	{
		stDonationLadderAck() { wProNO = MSG_DONATION_LADDER_ACK; }
		struct info
		{
			std::string name;
			uint32 yuanbao;
			std::string leave_words;
			std::string guild_name;
			uint32 level;
			CPacketSn& Sn(CPacketSn& cps) const { cps << name << yuanbao << leave_words << guild_name << level; return cps;}
			CPacketUsn& Usn(CPacketUsn& cpu)	{ cpu >> name >> yuanbao >> leave_words >> guild_name >> level; return cpu;}
		};
		std::vector<info> v;
		uint32 query_event_id;
		uint32 local_query ; //自己的排名
		bool total_query ;

		CPacketSn& Sn(CPacketSn& cps) const { PakHead::Sn(cps); cps << v << query_event_id << local_query << total_query; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{ PakHead::Usn(cpu);cpu >> v >> query_event_id >> local_query >> total_query; return cpu; }

	};

	//捐助事件
	struct stDonationEventList : public PakHead
	{
		stDonationEventList() { wProNO = MSG_DONATION_EVENT_LIST; }
		struct evt
		{
			uint32 id;
			uint32 start;
			uint32 expire;
			uint32 yuanbao;
			uint32 des_count;
			CPacketSn& Sn(CPacketSn& cps) const { cps << id << start << expire << yuanbao << des_count; return cps; }
			CPacketUsn& Usn(CPacketUsn& cpu)	{ cpu >> id >> start >> expire >> yuanbao >> des_count; return cpu;}
		};
		std::vector<evt> v;

		CPacketSn& Sn(CPacketSn& cps) const { PakHead::Sn(cps); cps << v; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{ PakHead::Usn(cpu);cpu >> v; return cpu; }
	};

	//捐助记录
	struct stDonationHistory : public PakHead
	{
		stDonationHistory() { wProNO = MSG_DONATION_HISTORY; }
		struct evt
		{
			uint32 event_id;
			uint32 datatime;
			uint32 yuanbao;

			CPacketSn& Sn(CPacketSn& cps) const { cps << event_id << datatime << yuanbao ; return cps; }
			CPacketUsn& Usn(CPacketUsn& cpu)	{ cpu >> event_id >> datatime >> yuanbao ; return cpu;}
		};

		std::vector<evt> v;

		CPacketSn& Sn(CPacketSn& cps) const { PakHead::Sn(cps); cps << v; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{ PakHead::Usn(cpu);cpu >> v; return cpu; }
	};

	struct stQueryPlayersAck : public PakHead
	{
		stQueryPlayersAck() { wProNO = MSG_QUERY_PLAYERS_ACK; }
		struct player_info
		{
			uint32 id;
			std::string name;
			uint8 mapid;
			uint8 race;
			uint8 cls;
			uint8 level;
			uint8 gender;
			CPacketSn& Sn(CPacketSn& cps) const { cps << id << name << race << cls << mapid << level << gender; return cps; }
			CPacketUsn& Usn(CPacketUsn& cpu)    { cpu >> id >> name >> race >> cls >> mapid >> level >> gender; return cpu; }
		};
		std::vector<player_info> v;
		CPacketSn& Sn(CPacketSn& cps) const { PakHead::Sn(cps); cps << v; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)    { PakHead::Usn(cpu);cpu >> v; return cpu; }
	};

#ifdef _ACTIVITY_PROTOCOL
	struct stActToolAccessAck : public PakHead
	{
		stActToolAccessAck() { wProNO = MSG_ACT_TOOL_ACCESS_ACK; }
		uint8 pass;
		uint32 servertime;
		CPacketSn& Sn(CPacketSn& cps) const { PakHead::Sn(cps); cps << pass << servertime; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)    { PakHead::Usn(cpu);cpu >> pass >> servertime; return cpu; }
	};
	struct stActivityListAck : public PakHead
	{
		stActivityListAck(){ wProNO = MSG_ACTIVITY_LIST_ACK; }

		CPacketSn& Sn(CPacketSn& cps) const;
		CPacketUsn& Usn(CPacketUsn& cpu);
	};
	struct stUpdateActivityAck : public PakHead
	{
		stUpdateActivityAck() : act_ptr( 0 ) { wProNO = MSG_UPDATE_ACTIVITY_ACK; }

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
	private:
		uint32 act_ptr;
	};
	struct stRemoveActivityAck : public PakHead
	{
		stRemoveActivityAck() { wProNO = MSG_REMOVE_ACTIVITY_ACK; }
		uint32 actid;
		CPacketSn& Sn(CPacketSn& cps) const;
		CPacketUsn& Usn(CPacketUsn& cpu);
	};
	struct stDutyChangeNotify : public PakHead
	{
		stDutyChangeNotify() { wProNO = MSG_DUTY_CHANGE_NOTIFY; }
		uint32 actid;
		uint8 on_duty;
		CPacketSn& Sn(CPacketSn& cps) const;

		CPacketUsn& Usn(CPacketUsn& cpu);
	};
#endif


	struct stOnItemFieldRecordChange : public PakHead
	{
		stOnItemFieldRecordChange() { wProNO = MSG_ON_ITEM_FIELD_RECORD_CHANGE; }
		uint32 entry;
		uint32 zoneid;
		CPacketSn& Sn(CPacketSn& cps) const { PakHead::Sn(cps); cps << entry << zoneid; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)    { PakHead::Usn(cpu);cpu >> entry >> zoneid; return cpu; }
	};

	struct stQuestEscortNotify : public PakHead
	{
		stQuestEscortNotify() { wProNO = MSG_QUEST_ESCORT_NOTIFY; }

		std::string who;
		uint32 qst_id;
		uint32 npc_id;
		CPacketSn& Sn(CPacketSn& cps) const { PakHead::Sn(cps); cps << who << qst_id << npc_id; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)    { PakHead::Usn(cpu);cpu >> who >> qst_id >> npc_id; return cpu; }
	};

	struct stTitleList : public PakHead
	{
		stTitleList(){ wProNO = MSG_TITLE_LIST; }
		title_map vTitleList;
		CPacketSn& Sn(CPacketSn& cps) const { PakHead::Sn(cps); cps << vTitleList; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)    { PakHead::Usn(cpu);cpu >> vTitleList; return cpu; }
	};

	struct stTitleAdd : public PakHead
	{
		stTitleAdd(){ wProNO = MSG_TITLE_ADD; }
		stTitle title;
		CPacketSn& Sn(CPacketSn& cps) const { PakHead::Sn(cps); cps << title; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)    { PakHead::Usn(cpu);cpu >> title; return cpu; }
	};

	struct stTitleRemove : public PakHead
	{
		stTitleRemove(){ wProNO = MSG_TITLE_REMOVE; }
		stTitle title;
		CPacketSn& Sn(CPacketSn& cps) const { PakHead::Sn(cps); cps << title; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)    { PakHead::Usn(cpu);cpu >> title; return cpu; }
	};

	struct stBattleGroundPowerUpdate : public PakHead	// 战场战斗力更新消息
	{
		stBattleGroundPowerUpdate() { wProNO = MSG_BATTLE_GROUND_POWER_UPDATE; }
		uint16 power[3]; // 战斗力。数组下标 0妖 1人 2巫
		uint8 side[3]; // 战斗方(0-2 根据策划要求做相应显示)。数组下标 0妖 1人 2巫
		uint8 num[3]; // 各阵营人数。 数组下标 0妖 1人 2巫
		CPacketSn& Sn(CPacketSn& cps) const { PakHead::Sn(cps); cps << power[0] << power[1] << power[2] << side[0] << side[1] << side[2] << num[0] << num[1] << num[2]; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)    { PakHead::Usn(cpu);cpu >> power[0] >> power[1] >> power[2] >> side[0] >> side[1] >> side[2] >> num[0] >> num[1] >> num[2]; return cpu; }
	};

	struct stLadderAck : public PakHead
	{
		stLadderAck() { wProNO = MSG_LADDER_ACK; }
		ladder_vector lv[RACE_MAX];
		uint8 ladder_category;

		CPacketSn& Sn(CPacketSn& cps) const {
			PakHead::Sn(cps);
			cps << ladder_category;
			for( int i = 0; i < RACE_MAX; ++i )
				cps << lv[i];
			return cps;
		}
		CPacketUsn& Usn(CPacketUsn& cpu) {
			PakHead::Usn(cpu);
			cpu >> ladder_category;
			for( int i = 0; i < RACE_MAX; ++i )
				cpu >> lv[i];
			return cpu;
		}
	};

	struct stMessageBox : public PakHead
	{
		stMessageBox(){ wProNO = MSG_MESSAGE_BOX; }
		std::string message;
		CPacketSn& Sn(CPacketSn& cps) const { PakHead::Sn(cps); cps << message; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)    { PakHead::Usn(cpu);cpu >> message; return cpu; }
	};

	struct stChoiceWhileInInstance : public PakHead
	{
		stChoiceWhileInInstance(){ wProNO = MSG_CHOICE_WHILE_IN_INSTANCE; }
	};

	struct stServerTime : public PakHead
	{
		stServerTime(){ wProNO = SMSG_SERVERTIME; }
		ui32 timeServer;
		CPacketSn& Sn(CPacketSn& cps) const { PakHead::Sn(cps); cps << timeServer; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)    { PakHead::Usn(cpu);cpu >> timeServer; return cpu; }
	};

	struct stFinishQuests : public PakHead
	{
		stFinishQuests(){ wProNO = MSG_FINISHQUESTS; }
		set<uint32> quests;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << quests; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> quests; return cpu; }
	};

	struct stRecruitNotify : public PakHead
	{
		stRecruitNotify() { wProNO = MSG_RECRUIT_NOTIFY; }
		std::string who;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << who; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> who; return cpu; }
	};

	struct stRecruitAck : public PakHead
	{
		stRecruitAck() { wProNO = MSG_RECRUIT_ACK; }
		uint8 ret;
		std::string teacher;
		std::string student;
		uint32 teacher_id;
		uint32 student_id;

		enum{ RESULT_ACCEPT, RESULT_REFUSE, RESULT_OFFLINE, RESULT_YOU_ALREADY_HAVE, RESULT_TARGET_ALREADY_HAVE, RESULT_DUPLICATE, RESULT_LOW_LEVEL, RESULT_DIFFERENT_FACTION };
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << ret; if( ret == RESULT_ACCEPT ){ cps << teacher << student << teacher_id << student_id; } return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> ret; if( ret == RESULT_ACCEPT ){ cpu >> teacher >> student >> teacher_id >> student_id; } return cpu; }
	};

	struct stSystemNotifyTopMove : public PakHead
	{
		stSystemNotifyTopMove(){ wProNO = MSG_SYSTEM_NOTIFY_TOP_MOVE; }
		struct stNotify
		{
			uint32 id;
			uint32 ntype;//1游戏特色介绍（橙色），2游戏操作介绍（橙色），3商品销售信息（蓝色），4游戏活动介绍（绿色），5游戏事件公告（红色），6相关提示（白色）
			string tips;
			CPacketSn& Sn(CPacketSn& cps) const { cps << id << ntype << tips; return cps; }
			CPacketUsn& Usn(CPacketUsn& cpu)	{ cpu >> id >> ntype >> tips; return cpu; }
		};
		vector<stNotify> vNotify;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << vNotify; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> vNotify; return cpu; }
	};
	struct stSystemNotifyRemove : public PakHead
	{
		stSystemNotifyRemove(){ wProNO = MSG_SYSTEM_NOTIFY_TOP_REMOVE; }
		uint32 id;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << id; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> id; return cpu; }
	};
	struct stSystemNotifyAdd : public PakHead
	{
		stSystemNotifyAdd(){ wProNO = MSG_SYSTEM_NOTIFY_TOP_ADD; }
		uint32 id;
		uint32 ntype;//1游戏特色介绍（橙色），2游戏操作介绍（橙色），3商品销售信息（蓝色），4游戏活动介绍（绿色），5游戏事件公告（红色），6相关提示（白色）
		string tips;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << id << ntype << tips; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> id >> ntype >> tips; return cpu; }
	};
	struct stSystemNotifyTopCenter : public PakHead
	{
		stSystemNotifyTopCenter(){ wProNO = MSG_SYSTEM_NOTIFY_TOP_CENTER; }
		uint32 ntype;//1特殊物品（橙色），2特别信息（蓝色），3特别战斗信息（红色），4相关提示（白色）
		string tips;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << ntype << tips; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> ntype >> tips; return cpu; }
	};

	struct stSystem_Gift_Notify: public PakHead
	{
		stSystem_Gift_Notify(){ wProNO = MSG_SYSTEM_GIFT_NOTIFY; }
		uint32 ntype;//2金币，1道具，3经验,4消息
		uint32 miscvalue1;//金币=金币数量，道具=道具entry，经验=经验数量
		uint32 miscvalue2;//道具=道具数量
		string Tips;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << ntype << miscvalue1 << miscvalue2; if(ntype==4) cps << Tips; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> ntype >> miscvalue1 >> miscvalue2; if(ntype==4) cpu >> Tips; return cpu; }
	};
	struct stSystem_Gift : public PakHead
	{
		stSystem_Gift(){ wProNO = MSG_SYSTEM_GIFT; }
		uint32 timecounter;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << timecounter; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> timecounter; return cpu; }
	};
	struct stEnterLeavePVPZoneNotify : public PakHead
	{
		stEnterLeavePVPZoneNotify() { wProNO = MSG_ENTER_LEAVE_PVP_ZONE_NOTIFY; }
		uint32 guid;
		uint8 is_enter;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << guid << is_enter; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> guid >> is_enter; return cpu; }
	};

	struct stJingLianItemAck : public PakHead
	{
		stJingLianItemAck() { wProNO = MSG_JINGLIAN_ITEM_ACK; }
		uint8 result;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << result; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> result; return cpu; }
	};

	struct stXiangqianItemAck : public PakHead
	{
		stXiangqianItemAck() { wProNO = MSG_XIANGQIAN_ITEM_ACK; }
		uint8 result;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << result; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> result; return cpu; }
	};


// 	struct stSystem_Tips : public PakHead
// 	{
// 		stSystem_Tips(){ wProNO = SYSTEM_TIPS; }
// 		struct tips
// 		{
// 			uint32 ntype;
// 			string tip;
// 			CPacketSn& Sn(CPacketSn& cps) const {	cps << ntype << tip; return cps; }
// 			CPacketUsn& Usn(CPacketUsn& cpu)	{	cpu >> ntype >> tip; return cpu; }
// 		};
// 		vector<tips> vtips;
// 		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << vtips; return cps; }
// 		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> vtips; return cpu; }
// 	};
	
	struct stHideGM : public PakHead
	{
		stHideGM() { wProNO = HIDE_GM; }
		bool bHide;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << bHide; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> bHide; return cpu; }
	};

	struct stCopyName : public PakHead
	{
		stCopyName(){ wProNO = COPY_NAME; }
		string name;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << name; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> name; return cpu; }
	};
	
	struct stReliveReq : public PakHead
	{
		stReliveReq(){ wProNO = RELIVE_REQ; }
	};
	struct stPong : public PakHead
	{
		stPong(){ wProNO = SMSG_PONG; }
	};
	struct stPlayer_Skinned : public PakHead
	{
		stPlayer_Skinned(){ wProNO = SMSG_PLAYER_SKINNED; }
	};
	struct stSet_Rest_Start : public PakHead
	{
		stSet_Rest_Start(){ wProNO = SMSG_SET_REST_START; }
		ui32	timeLogoff;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << timeLogoff; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> timeLogoff; return cpu; }
	};
	struct stCorpse_Reclaim_Delay : public PakHead
	{
		stCorpse_Reclaim_Delay(){ wProNO = SMSG_CORPSE_RECLAIM_DELAY; }
		ui32	delay;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << delay; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> delay; return cpu; }
	};
	struct stWeather : public PakHead
	{
		stWeather(){ wProNO = SMSG_WEATHER; }
		ui32	Effect;
		float	Density;
		ui32	Sound;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << Effect << Density << Sound; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> Effect >> Density >> Sound; return cpu; }
	};
	struct stRaid_Instance_Info : public PakHead
	{
		stRaid_Instance_Info(){ wProNO = SMSG_RAID_INSTANCE_INFO; }
		struct stMap
		{
			ui32	mapid;
			ui32	expire;
			ui32	instanceid;
			CPacketSn& Sn(CPacketSn& cps) const {cps << mapid << expire << instanceid; return cps; }
			CPacketUsn& Usn(CPacketUsn& cpu)	{cpu >> mapid >> expire >> instanceid; return cpu; }
		};
		vector<stMap> vMaps;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << vMaps; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> vMaps; return cpu; }
	};
	struct stInstance_Save : public PakHead
	{
		stInstance_Save(){ wProNO = SMSG_INSTANCE_SAVE; }
		ui32	mapid;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << mapid; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> mapid; return cpu; }
	};
	struct stInstance_Reset : public PakHead
	{
		stInstance_Reset(){ wProNO = SMSG_RESET_INSTANCE; }
		ui32	mapid;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << mapid; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> mapid; return cpu; }
	};
	struct stInstance_Reset_Active : public PakHead
	{
		stInstance_Reset_Active(){ wProNO = SMSG_INSTANCE_RESET_ACTIVATE; }
		ui8	reset;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << reset; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> reset; return cpu; }
	};
	struct stTaxi_Node_Stat : public PakHead
	{
		stTaxi_Node_Stat(){ wProNO = TAXI_NODE_STATUS; }
		ui64	guid;
		ui32	stat;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << guid << stat;; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> guid >> stat;; return cpu; }
	};
	struct stTaxi_New_Path : public PakHead
	{
		stTaxi_New_Path(){ wProNO = TAXI_NEW_PATH; }
	};
	struct stTaxi_Show_Nodes : public PakHead
	{
		stTaxi_Show_Nodes(){ wProNO = TAXI_SHOW_NODES; }
		ui64	guid;
		ui32	curloc;
		vector<ui32> vNodes;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << guid << curloc << vNodes;; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> guid >> curloc >> vNodes; return cpu; }
	};
	struct stTaxi_Activate_Reply : public PakHead
	{
		stTaxi_Activate_Reply(){ wProNO = TAXI_ACTIVATE_REPLY; }
		ui32	stat;
		// 0 Ok
		// 1 Unspecified Server Taxi Error
		// 2.There is no direct path to that direction
		// 3 Not enough Money

		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << stat;; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> stat;; return cpu; }
	};

	struct stRaid_Group_Only : public PakHead
	{
		stRaid_Group_Only(){ wProNO = RAID_GROUP_ONLY; }
		ui32	unk1;
		ui32	unk2;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << unk1 << unk2;; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> unk1 >> unk2;; return cpu; }
	};
	struct stVoice_System_Stats: public PakHead
	{
		stVoice_System_Stats(){ wProNO = SMSG_VOICE_SYSTEM_STATUS; }
	};
	struct stMsg_Dungeon_Difficulty : public PakHead
	{
		stMsg_Dungeon_Difficulty(){ wProNO = MSG_DUNGEON_DIFFICULTY; }
		ui32	instanceType;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << instanceType; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> instanceType; return cpu; }
	};
	struct stServer_Message : public PakHead
	{
		stServer_Message(){ wProNO = SERVER_MESSAGE; }
		ui32	type;
		string message;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << type << message; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> type >> message; return cpu; }
	};
	struct stFish_Not_Hooked: public PakHead
	{
		stFish_Not_Hooked(){ wProNO = FISH_NOT_HOOKED; }
	};
	struct stFish_Escaped: public PakHead
	{
		stFish_Escaped(){ wProNO = FISH_ESCAPED; }
	};
	struct stGameBoj_Custom_Anim: public PakHead
	{
		stGameBoj_Custom_Anim(){ wProNO = GAMEOBJECT_CUSTOM_ANIM; }
		ui64	guid;
		ui32	value;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << guid << value; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> guid >> value; return cpu; }
	};
	struct stPlay_Object_Sound: public PakHead
	{
		stPlay_Object_Sound(){ wProNO = PLAY_OBJECT_SOUND; }
		ui64	creature_guid;
		ui32	value;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << creature_guid << value; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> creature_guid >> value; return cpu; }
	};
	
	struct stSet_Proficiency: public PakHead
	{
		stSet_Proficiency(){ wProNO = SET_PROFICIENCY; }
		uint8	ItemClass;
		uint32	Profinciency;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << ItemClass << Profinciency; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> ItemClass >> Profinciency; return cpu; }
	};
	struct stTalent_Wipe_Confirm: public PakHead
	{
		stTalent_Wipe_Confirm(){ wProNO = MSG_TALENT_WIPE_CONFIRM; }
		ui64	player_guid;
		ui32	cost;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << player_guid << cost; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> player_guid >> cost; return cpu; }
	};
	struct stLogin_Set_TimeSpeed: public PakHead
	{
		stLogin_Set_TimeSpeed(){ wProNO = LOGIN_SETTIMESPEED; }
		ui32	gametime;
		float	gamespeed;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << gametime << gamespeed; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> gametime >> gamespeed; return cpu; }
	};
	struct stTutorial_Flags : public PakHead
	{
		stTutorial_Flags(){ wProNO = TUTORIAL_FLAGS; }
		ui8	Tutorials[8];
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps.AddBuf(Tutorials, sizeof(Tutorials)); return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu.GetBuf(Tutorials, sizeof(Tutorials)); return cpu; }
	};
	struct stQuery_Quest_Response : public PakHead
	{
		stQuery_Quest_Response(){ wProNO = QUERY_QUEST_RESPONSE; }
		ui32	pageid;
		string	text;
		ui32	next_pageid;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << pageid<<text<<next_pageid; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> pageid>>text>>next_pageid; return cpu; }
	};
	struct stQuery_Page_Text_Response : public PakHead
	{
		stQuery_Page_Text_Response(){ wProNO = QUERY_PAGE_TEXT_RESPONSE; }
		ui32	pageid;
		string	text;
		ui32	next_pageid;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << pageid<<text<<next_pageid; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> pageid>>text>>next_pageid; return cpu; }
	};
	struct stQuery_Corpse_Response : public PakHead
	{
		stQuery_Corpse_Response(){ wProNO = QUERY_CORPSE_RESPONSE; }
		ui8		bShow;
		ui32	mapid;
		float	x,y,z;
		ui32	instance_mapid;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << bShow<<mapid<<x<<y<<z<<instance_mapid; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> bShow>>mapid>>x>>y>>z>>instance_mapid; return cpu; }
	};
	struct stQuery_GameObj_Response : public PakHead
	{
		stQuery_GameObj_Response(){ wProNO = QUERY_GAMEOBJECT_RESPONSE; }
		ui32	entry;
		ui32	Type;
		string	name;
		ui32	DisplayID;
		ui32	SpellFocus;

		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << entry<<Type<<name<<DisplayID<<SpellFocus; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> entry>>Type>>name>>DisplayID>>SpellFocus; return cpu; }
	};
	struct stQuery_Creature_Response : public PakHead
	{
		stQuery_Creature_Response(){ wProNO = QUERY_CREATURE_RESPONSE; }
		ui32	entry;
		string	name;
		string	info_str;
		ui32	Type;
		ui32	Family;
		ui32	Rank;
		ui32	SpellDataID;
		ui32	Male_DisplayID;
		ui32	Female_DisplayID;
		ui32	Civilian;
		ui32	Leader;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << entry<<name<<info_str<<Type<<Family<<Rank<<SpellDataID<<
			Male_DisplayID<<Female_DisplayID<<Civilian<<Leader; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> entry>>name>>info_str>>Type>>Family>>Rank>>SpellDataID>>
			Male_DisplayID>>Female_DisplayID>>Civilian>>Leader; return cpu; }
	};
	struct stQuery_Time_Response : public PakHead
	{
		stQuery_Time_Response(){ wProNO = QUERY_TIME_RESPONSE; }
		ui32	time;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << time; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> time; return cpu; }
	};
	struct stQuery_Name_Response : public PakHead
	{
		stQuery_Name_Response(){ wProNO = QUERY_RESPONSE; }
		ui64	guid;
		string	name;
		ui32	race;
		ui32	gender;
		ui32	Class;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << guid<<name<<race<<gender<<Class; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> guid>>name>>race>>gender>>Class; return cpu; }
	};
	struct stSound_Play : public PakHead
	{
		stSound_Play(){ wProNO = SMSG_PLAY_SOUND; }
		ui32	sound;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << sound; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> sound; return cpu; }
	};
	struct stGameObj_Despawn_Anim : public PakHead
	{
		stGameObj_Despawn_Anim(){ wProNO = SMSG_GAMEOBJECT_DESPAWN_ANIM; }
		ui64 guid;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << guid; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> guid; return cpu; }
	};
	struct stInspect_Talents : public PakHead
	{
		stInspect_Talents(){ wProNO = SMSG_INSPECT_TALENTS; }
		uint32 talent_points;
		uint32 mask;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << talent_points << mask; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> talent_points >> mask; return cpu; }
	};
	struct stPlayed_Time : public PakHead
	{
		stPlayed_Time(){ wProNO = SMSG_PLAYED_TIME; }
		ui32	play_time1;
		ui32	play_time2;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << play_time1 << play_time2; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> play_time1 >> play_time2; return cpu; }
	};
	struct stLogout_Response : public PakHead
	{
		stLogout_Response(){ wProNO = SMSG_LOGOUT_RESPONSE; }
		ui8 accepted;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << accepted; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> accepted; return cpu; }
	};

	struct stMsg_Who : public PakHead
	{
		stMsg_Who(){ wProNO = MSG_WHO; }
		struct stWho
		{
			string name;
			string guildname;
			ui32	Level;
			ui32	Class;
			ui32	Race;
			ui32	ZoneID;
			CPacketSn& Sn(CPacketSn& cps) const {	cps << name << guildname << Level <<Class<<Race<<ZoneID; return cps; }
			CPacketUsn& Usn(CPacketUsn& cpu)	{	cpu >> name >> guildname >> Level >>Class>>Race>>ZoneID; return cpu; }
		};
		vector<stWho> vPlayers;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << vPlayers; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> vPlayers; return cpu; }
	};
	
	struct stArea_Exploration_XP : PakHead
	{
		stArea_Exploration_XP(){ wProNO = AREA_EXPLORATION_EXPERIENCE; }
		ui32	areaid;
		ui32	xp;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << areaid << xp; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> areaid >> xp; return cpu; }
	};	
	struct stArea_Trigger_Message : PakHead
	{
		stArea_Trigger_Message(){ wProNO = AREA_TRIGGER_MESSAGE; }
		string message;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << message; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> message; return cpu; }
	};	

	struct stNotify_Msg : public PakHead
	{
		stNotify_Msg(){ wProNO = NOTIFY_MSG; }
		string notify;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << notify; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> notify; return cpu; }
	};

	struct stDestroyObj : public PakHead
	{
		stDestroyObj(){ wProNO = DESTROY_OBJECT; }
		ui64	guid;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << guid; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> guid; return cpu; }
	};

	struct stLevel_Up_Info : public PakHead
	{
		stLevel_Up_Info(){ wProNO = LEVELUP_INFO; }
		uint32	level;
		uint32	Hp;
		uint32	Mana;
		uint32	unk0;
		uint32	unk1;
		uint32	unk2;
		uint32	unk3;
		uint32	Stat0;
		uint32	Stat1;
		uint32	Stat2;
		uint32	Stat3;
		uint32	Stat4;
		uint32	Stat5;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << level<<Hp<<Mana<<Stat0<<Stat1<<Stat2<<Stat3<<Stat4<<Stat5; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> level>>Hp>>Mana>>Stat0>>Stat1>>Stat2>>Stat3>>Stat4>>Stat5; return cpu; }
	};
	struct stLog_XP_Gain : public PakHead
	{
		stLog_XP_Gain(){ wProNO = LOG_XPGAIN; }
		uint64	guid;                                    // Always 0
		uint32	xp;                                      // Normal XP
		uint8	type;                                    // Unknown.. seems to always be 0		
		uint32	restxp;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << guid<<xp<<type<<restxp; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> guid>>xp>>type>>restxp; return cpu; }
	};


	struct stEnterGameAck : public PakHead
	{
		stEnterGameAck(){ wProNO = ENTERGAME_ACK; }
		ui8			nError;
		ui64		guid;
		string		strName;
		ui8			nSex;
		ui8			nJob;

		ui8			nLevel;
		ui32		nCurExp;
		ui32		nMaxExp;
		ui32		nMoney;

		ui16		nCurHP;
		ui16		nMaxHP;
		ui16		nCurMP;
		ui16		nMaxMP;

		ui32		nMapID;

		float		x;
		float		y;
		float		z;
		float		dir;

		CPacketSn& Sn(CPacketSn& cps) const {PakHead::Sn(cps) << nError << guid << strName << nSex << nJob
			<< nLevel << nCurExp << nMaxExp << nMoney << nCurHP << nMaxHP << nCurMP << nMaxMP << nMapID << x << y << z << dir; return cps;}
		CPacketUsn& Usn(CPacketUsn& cpu) {PakHead::Usn(cpu) >> nError >> guid >> strName >> nSex >> nJob
			>> nLevel >> nCurExp >> nMaxExp >> nMoney >> nCurHP >> nMaxHP >> nCurMP >> nMaxMP >> nMapID >> x >> y >> z >> dir; return cpu;}
	};

	struct stLoginAck : public PakHead 
	{
		stLoginAck(){ wProNO = LOGIN_ACK; }
		ui8		nError;
		ui32	nAccountID;
		ui32	nSessionID;
// 		string	strAccount;
		string	strDesKey;
		string	GMFlags;
		ui32	Muted;
		ui32	Baned;
		bool	bFangchenmiAccount;//是否是未成年人账号
		uint32	LastLogout;
		uint32	ChenmiTime;//沉迷的游戏时间累积

		CPacketSn& Sn(CPacketSn& cps) const {PakHead::Sn(cps)  << nError << nAccountID << nSessionID << strDesKey << GMFlags << Muted << bFangchenmiAccount << LastLogout << ChenmiTime; return cps;}
		CPacketUsn& Usn(CPacketUsn& cpu)	{PakHead::Usn(cpu) >> nError >> nAccountID >> nSessionID >> strDesKey >> GMFlags >> Muted >> bFangchenmiAccount >> LastLogout >> ChenmiTime; return cpu;}
	};
	struct RoleInfo//	used show rolelist to client
	{
		RoleInfo(){ memset( this, 0, sizeof( RoleInfo ) - sizeof( std::string ) ); }
		ui64 guid;
		ui8 nStat;
		ui8	nGender;
		ui8	nRace;
		ui8	nClass;
		
		ui32 nLevel;
		ui8	nGS;
		ui32 nMapID;
		ui32 nZoneID;
		ui8 bFirstLogin;
		ui32 displayid;
		ui32 equipdisplay[EQUIPMENT_SLOT_END-EQUIPMENT_SLOT_START];
		string name;
		CPacketSn& Sn(CPacketSn& cps) const {cps << guid << nStat << nRace << nClass << nLevel << nGender << name << nGS << nMapID << nZoneID << displayid; cps.AddBuf(&equipdisplay[0], sizeof(equipdisplay));return cps;}
		CPacketUsn& Usn(CPacketUsn& cpu)	{cpu >> guid >> nStat >> nRace >> nClass >> nLevel >> nGender >> name >> nGS >> nMapID >> nZoneID >> displayid; cpu.GetBuf(&equipdisplay[0], sizeof(equipdisplay)); return cpu;}
	};

	struct stCreateRoleAck : public PakHead
	{
		stCreateRoleAck(){ wProNO = CREATEROLE_ACK; }

		enum eError
		{
			NOT_LOGON = 1,
			ROLE_IS_FULL,
			BANNED_NAME,
			NAME_IS_USED,
			NO_SUCH_RACECLASS,
			NAME_IS_TOO_LONG,
			GENERAL_ERROR,
		};
		ui8		nError;

		RoleInfo role;
		CPacketSn& Sn(CPacketSn& cps) const {PakHead::Sn(cps) << nError << role; return cps;}
		CPacketUsn& Usn(CPacketUsn& cpu) {PakHead::Usn(cpu) >> nError >> role; return cpu;}
	};

	struct stRoleListAck : public PakHead 
	{
		stRoleListAck(){ wProNO = ROLELIST_ACK; }
		ui8		nError;
		vector<RoleInfo> vRoles;

		CPacketSn& Sn(CPacketSn& cps) const {PakHead::Sn(cps) << nError << vRoles; return cps;}
		CPacketUsn& Usn(CPacketUsn& cpu) {PakHead::Usn(cpu) >> nError >> vRoles; return cpu;}
	};

	struct stDelRoleAck : public PakHead 
	{
		stDelRoleAck(){ wProNO = DELROLE_ACK; }
		ui8		nError;
		ui64	guid;

		CPacketSn& Sn(CPacketSn& cps) const {PakHead::Sn(cps) << nError << guid; return cps;}
		CPacketUsn& Usn(CPacketUsn& cpu) {PakHead::Usn(cpu) >> nError >> guid; return cpu;}
	};

	struct stResumeRoleAck : public PakHead 
	{
		stResumeRoleAck(){ wProNO = RESUMEROLE_ACK; }
		ui8		nError;
		string	strRoleName;

		CPacketSn& Sn(CPacketSn& cps) const {PakHead::Sn(cps) << nError << strRoleName; return cps;}
		CPacketUsn& Usn(CPacketUsn& cpu) {PakHead::Usn(cpu) >> nError >> strRoleName; return cpu;}
	};

	struct stEnterMapPkg : public PakHead 
	{
		stEnterMapPkg(){ wProNO = ENTERMAP_PKG; }
		ui64		guid;

		string		strMap;
		float		x,y,z,dir;

		CPacketSn& Sn(CPacketSn& cps) const {PakHead::Sn(cps) << guid << strMap << x << y << z << dir; return cps;}
		CPacketUsn& Usn(CPacketUsn& cpu) {PakHead::Usn(cpu) >> guid >> strMap >> x >> y >> z >> dir; return cpu;}
	};

	struct stCreatureDiePkg : public PakHead 
	{
		stCreatureDiePkg(){ wProNO = CREATURE_DIE_PKG; }
		ui64		guid;

		CPacketSn& Sn(CPacketSn& cps) const {PakHead::Sn(cps) << guid; return cps;}
		CPacketUsn& Usn(CPacketUsn& cpu) {PakHead::Usn(cpu) >> guid; return cpu;}
	};

	struct stReliveAck : public PakHead 
	{
		stReliveAck(){ wProNO = RELIVE_ACK; }
		ui64		guid;
		ui8			nReliveType;
		ui8			nError;
		ui8			nLevel;
		ui32		nExp;
		ui32		nMaxExp;
		ui16		nCurHP,nMaxHP,nCurMP,nMaxMP;

		string		strMap;

		float		x,y,z,dir;

		CPacketSn& Sn(CPacketSn& cps) const {PakHead::Sn(cps) << guid << nReliveType << nError << nLevel << nExp << nMaxExp
			<< nCurHP << nMaxHP << nCurMP << nMaxMP << strMap << x << y << z << dir; return cps;}
		CPacketUsn& Usn(CPacketUsn& cpu) {PakHead::Usn(cpu) >> guid >> nReliveType >> nError >> nLevel >> nExp >> nMaxExp
			>> nCurHP >> nMaxHP >> nCurMP >> nMaxMP >> strMap >> x >> y >> z >> dir; return cpu;}
	};

	struct stRelivePkg : public PakHead 
	{
		stRelivePkg(){ wProNO = RELIVE_PKG; }
		ui64		guid;
		float		x,y,z,dir;
		ui8			nHPPercent;
		ui8			nMPPercent;

		CPacketSn& Sn(CPacketSn& cps) const {PakHead::Sn(cps) << guid << x << y << z << dir << nHPPercent << nMPPercent; return cps;}
		CPacketUsn& Usn(CPacketUsn& cpu) {PakHead::Usn(cpu) >> guid >> x >> y >> z >> dir >> nHPPercent >> nMPPercent; return cpu;}
	};

	struct stObjectUpdate : public PakHead
	{
		stObjectUpdate(){ wProNO = UPDATE_OBJECT; }
		ByteBuffer buffer;
		CPacketSn& Sn(CPacketSn& cps) const { PakHead::Sn(cps) << buffer; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu) { PakHead::Usn(cpu) >> buffer; return cpu; }
	};

	struct stAccountExpireInFewMinutes : public PakHead
	{
		stAccountExpireInFewMinutes() { wProNO = ACCOUNT_EXPIRE_IN_FEW_MINUTES; }
		uint8 howlong;		// minutes
		CPacketSn& Sn(CPacketSn& cps) const { PakHead::Sn(cps) << howlong; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu) { PakHead::Usn(cpu) >> howlong; return cpu; }
	};

	struct stQueueInstanceUpdate : public PakHead
	{
		stQueueInstanceUpdate(){ wProNO = MSG_QUEUE_INSTANCE_UPDATE; }
		uint32 mapid[3];
		CPacketSn& Sn(CPacketSn& cps) const { PakHead::Sn(cps); cps.AddBuf( mapid, sizeof( mapid ) ); return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu) { PakHead::Usn(cpu); cpu.GetBuf( mapid, sizeof( mapid ) ); return cpu; }
	};

	struct stEnterInstanceCountDown : public PakHead
	{
		stEnterInstanceCountDown() { wProNO = MSG_ENTER_INSTANCE_COUNT_DOWN; }
		uint32 mapid;
		uint8 seconds;
		CPacketSn& Sn(CPacketSn& cps) const { PakHead::Sn(cps) << mapid << seconds; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu) { PakHead::Usn(cpu) >> mapid >> seconds; return cpu; }
	};

	struct stArenaUpdateState : public PakHead
	{
		stArenaUpdateState() { wProNO = MSG_ARENA_UPDATE_STATE; }

		struct info
		{
			std::string name;
			uint8 level;
			uint8 race;
			uint8 cls;
			uint8 kill;
			CPacketSn& Sn(CPacketSn& cps) const { cps << name << level << race << cls << kill; return cps; }
			CPacketUsn& Usn(CPacketUsn& cpu) { cpu >> name >> level >> race >> cls >> kill; return cpu; }
		};

		std::vector<info> vinfo;

		CPacketSn& Sn(CPacketSn& cps) const { PakHead::Sn(cps) << vinfo; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu) { PakHead::Usn(cpu) >> vinfo; return cpu; }
	};

	struct stInstanceBillboard : public PakHead
	{
		stInstanceBillboard() { wProNO = MSG_INSTANCE_BILLBOARD; }
		struct info {
			std::string name;
			uint8 rank;
			uint8 level;
			uint8 race;
			uint8 cls;
			uint32 kill;
			uint32 gold;
			uint32 exp;
			CPacketSn& Sn(CPacketSn& cps) const { cps << name << rank << level << race << cls << kill << gold << exp; return cps; }
			CPacketUsn& Usn(CPacketUsn& cpu) { cpu >> name >> rank >> level >> race >> cls >> kill >> gold >> exp; return cpu; }
		};
		std::vector<info> vinfo;

		CPacketSn& Sn(CPacketSn& cps) const { PakHead::Sn(cps) << vinfo; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu) { PakHead::Usn(cpu) >> vinfo; return cpu; }
	};

	struct stPlayerEnterInstance : public PakHead
	{
		stPlayerEnterInstance() { wProNO = MSG_PLAYER_ENTER_INSTANCE; }
		uint32 mapid;
		uint32 category;
		uint32 expire;

		CPacketSn& Sn(CPacketSn& cps) const { PakHead::Sn(cps) << mapid << category << expire; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu) { PakHead::Usn(cpu) >> mapid >> category >> expire; return cpu; }
	};

	struct stPlayerLeaveInstance : public PakHead
	{
		stPlayerLeaveInstance() { wProNO = MSG_PLAYER_LEAVE_INSTANCE; }
		uint32 guid;
		std::string name;

		CPacketSn& Sn(CPacketSn& cps) const { PakHead::Sn(cps) << guid << name; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu) { PakHead::Usn(cpu) >> guid >> name; return cpu; }
	};

	struct stSunyouInstanceList : public PakHead
	{
		stSunyouInstanceList() { wProNO = MSG_SUNYOU_INSTANCE_LIST; }
		std::vector<sunyou_instance_configuration> v;

		CPacketSn& Sn(CPacketSn& cps) const
		{
			PakHead::Sn(cps) << v.size();
			for( size_t i = 0; i < v.size(); ++i )
			{
				const sunyou_instance_configuration& sic = v[i];
				cps << (int&)sic.category << sic.iconid << sic.mapid << sic.minlevel << sic.maxlevel << sic.maxplayer << sic.expire << sic.cost_type << sic.cost_value1 << sic.cost_value2;
				for( int j = 0; j < 6; ++j )
				{
					cps << sic.open_start[j] << sic.open_end[j];
				}
				cps << sic.resurrect_time;
			}
			return cps;
		}
		CPacketUsn& Usn(CPacketUsn& cpu)
		{
			size_t size = 0;
			PakHead::Usn(cpu) >> size;
			for( size_t i = 0; i < size; ++i )
			{
				sunyou_instance_configuration sic;
				cpu >> (int&)sic.category >> sic.iconid >> sic.mapid >> sic.minlevel >> sic.maxlevel >> sic.maxplayer >> sic.expire >> sic.cost_type >> sic.cost_value1 >> sic.cost_value2;
				for( int j = 0; j < 6; ++j )
				{
					cpu >> sic.open_start[j] >> sic.open_end[j];
				}
				cpu >> sic.resurrect_time;
				v.push_back( sic );
			}
			
			return cpu;
		}
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