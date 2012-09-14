#pragma once
#include "TypeDef.h"
#pragma pack(push,1)
class QuestScript;
struct Quest
{
	uint32 id;
	uint32 zone_id;
	uint32 quest_sort;
	uint32 quest_flags;
	uint32 min_level;
	uint32 max_level;
	uint32 type;
	uint32 required_races;
	uint32 required_class;
	uint32 required_tradeskill;
	uint32 required_tradeskill_value;
	uint32 required_rep_faction;
	uint32 required_rep_value;

	uint32 time;
	uint32 special_flags;

	uint32 previous_quest_id;
	uint32 next_quest_id;

	uint32 srcitem;
	uint32 srcitemcount;

	char * title;					//	名称
	char * details;					//	描述
	char * objectives;				//	目标
	char * completiontext;			//	完成对话
	char * incompletetext;			//	未完成对话
	char * endtext;

	char * objectivetexts[4];

	uint32 required_item[4];		//	完成任务所需的道具,完成任务后会删除
	uint32 required_itemcount[4];	//	完成任务所需的道具数量

	uint32 required_mob[4];			//	完成任务所需杀的怪物id
	uint32 required_mobcount[4];	//	完成任务所需杀的怪物数量
	uint32 required_spell[4];
	uint32 required_honor;			//	完成任务扣除的荣誉

	uint32 reward_choiceitem[6];		//	完成任务选择的奖励品
	uint32 reward_choiceitemcount[6];	//	完成任务选择的奖励品数量

	uint32 reward_item[4];				//	完成任务的奖励品
	uint32 reward_itemcount[4];			//	完成任务的奖励品数量

	uint32 reward_repfaction[2];
	int32 reward_repvalue[2];
	uint32 reward_replimit;

	uint32 reward_money;				//	完成任务奖励的金币
	uint32 reward_xp;					//	完成任务奖励的经验
	uint32 reward_spell;				//	完成任务学会的技能
	uint32 reward_honor;				//	完成任务奖励的荣誉
	uint32 effect_on_player;

	uint32 point_mapid;
	uint32 point_x;
	uint32 point_y;
	uint32 point_opt;

	uint32 required_money;
	uint32 required_triggers[4];
	uint32 required_quests[4];
	uint32 receive_items[4];		//	接任务所需的道具,完成任务后会删除
	uint32 receive_itemcount[4];	//	接任务所需的道具数量
	int is_repeatable;

	uint32 bTeam;
	uint32 bSex;
	uint32 hasItem;
	uint32 hasItemCnt;

	uint32 IsMainLineQuest;
	uint32 MainLineQuest;

	uint32 count_required_mob;
	uint32 count_requiredquests;
	uint32 count_requiredtriggers;
	uint32 count_receiveitems;
	uint32 count_reward_choiceitem;
	uint32 count_required_item;
	uint32 required_mobtype[4];
	uint32 count_reward_item;
	uint32 reward_xp_as_money;	QuestScript* pQuestScript;
};
#pragma pack(pop)



enum QUEST_SHARE
{
	QUEST_SHARE_MSG_SHARING_QUEST   = 0,
	QUEST_SHARE_MSG_CANT_TAKE_QUEST = 1,
	QUEST_SHARE_MSG_ACCEPT_QUEST	= 2,
	QUEST_SHARE_MSG_REFUSE_QUEST	= 3,
	QUEST_SHARE_MSG_TOO_FAR		 = 4,
	QUEST_SHARE_MSG_BUSY			= 5,
	QUEST_SHARE_MSG_LOG_FULL		= 6,
	QUEST_SHARE_MSG_HAVE_QUEST	  = 7,
	QUEST_SHARE_MSG_FINISH_QUEST	= 8,
};


enum QUEST_STATUS
{
	QMGR_QUEST_NOT_AVAILABLE			= 0x00,	// There aren't quests avaiable.				   | "No Mark"
	QMGR_QUEST_AVAILABLELOW_LEVEL	   = 0x01,	// Quest avaiable, and your level isnt enough.	 | "Gray Quotation Mark !"
	QMGR_QUEST_CHAT					 = 0x02,	// Quest avaiable it shows a talk baloon.		  | "No Mark"
	QMGR_QUEST_NOT_FINISHED			 = 0x03,	// Quest isnt finished yet.						| "Gray Question ? Mark"
	QMGR_QUEST_REPEATABLE_FINISHED		= 0x04,	//	DIALOG_STATUS_REWARD_REP 任务完成,可以重复领取奖励
	QMGR_QUEST_REPEATABLE			   = 0x05,	// Quest repeatable								| "Blue Question ? Mark" 
	QMGR_QUEST_AVAILABLE				= 0x06,	// Quest avaiable, and your level is enough		| "Yellow Quotation ! Mark" 
	QMGR_QUEST_FINISHED				 = 0x08,	// Quest has been finished.						| "Yellow Question  ? Mark" (7 has no minimap icon)
	//QUEST_ITEM_UPDATE				 = 0x06	 // Yellow Question "?" Mark. //Unknown
};

enum INVALID_REASON
{
	INVALID_REASON_DONT_HAVE_REQ			= 0,
	INVALID_REASON_DONT_HAVE_LEVEL			= 1,
	INVALID_REASON_DONT_HAVE_RACE			= 6,
	INVALID_REASON_COMPLETED_QUEST			= 7,
	INVALID_REASON_HAVE_TIMED_QUEST			= 12,
	INVALID_REASON_HAVE_QUEST				= 13,
	//	INVALID_REASON_DONT_HAVE_REQ_ITEMS	  = 0x13,
	//	INVALID_REASON_DONT_HAVE_REQ_MONEY	  = 0x15,
	INVALID_REASON_DONT_HAVE_EXP_ACCOUNT	= 16,
	INVALID_REASON_DONT_HAVE_REQ_ITEMS		= 21, //changed for 2.1.3
	INVALID_REASON_DONT_HAVE_REQ_MONEY		= 23,
	INVALID_REASON_UNKNOW26					= 26, //"you have completed 10 daily quests today"
	INVALID_REASON_UNKNOW27					= 27,//"You cannot completed quests once you have reached tired time"
};

enum FAILED_REASON
{
	FAILED_REASON_FAILED			= 0,
	FAILED_REASON_INV_FULL			= 4,
	FAILED_REASON_DUPE_ITEM_FOUND   = 17,
};
enum QuestSlotOffsets
{
	QUEST_ID_OFFSET = 0,
	QUEST_STATE_OFFSET = 1,
	QUEST_COUNTS_OFFSET = 2,
	QUEST_TIME_OFFSET = 3
};

#define MAX_QUEST_OFFSET 4

enum QuestSlotStateMask
{
	QUEST_STATE_NONE     = 0x0000,
	QUEST_STATE_COMPLETE = 0x0001,
	QUEST_STATE_FAIL     = 0x0002
};

enum QuestType
{
	QUEST_TYPE_NONE = 0,
	QUEST_TYPE_REPEATEABLE,
	QUEST_TYPE_DAILY,
	QUEST_TYPE_MAINLINE,
};

enum QUEST_MOB_TYPES
{
	QUEST_MOB_TYPE_CREATURE = 1,
	QUEST_MOB_TYPE_GAMEOBJECT = 2,
	QUEST_MOB_TYPE_ESCORT = 3,
};
/*
#define MAX_QUEST_LOG_SIZE 25

#define QUEST_OBJECTIVES_COUNT 4
#define QUEST_SOURCE_ITEM_IDS_COUNT 4
#define QUEST_REWARD_CHOICES_COUNT 6
#define QUEST_REWARDS_COUNT 4
#define QUEST_DEPLINK_COUNT 10
#define QUEST_REPUTATIONS_COUNT 5
#define QUEST_EMOTE_COUNT 4

enum QuestFailedReasons
{
	INVALIDREASON_DONT_HAVE_REQ                 = 0,
	INVALIDREASON_QUEST_FAILED_LOW_LEVEL        = 1,        //You are not high enough level for that quest.
	INVALIDREASON_QUEST_FAILED_WRONG_RACE       = 6,        //That quest is not available to your race.
	INVALIDREASON_QUEST_ALREADY_DONE            = 7,        //You have completed that quest.
	INVALIDREASON_QUEST_ONLY_ONE_TIMED          = 12,       //You can only be on one timed quest at a time.
	INVALIDREASON_QUEST_ALREADY_ON              = 13,       //You are already on that quest
	INVALIDREASON_QUEST_FAILED_EXPANSION        = 16,       //This quest requires an expansion enabled account.
	INVALIDREASON_QUEST_ALREADY_ON2             = 18,       //You are already on that quest
	INVALIDREASON_QUEST_FAILED_MISSING_ITEMS    = 21,       //You don't have the required items with you. Check storage.
	INVALIDREASON_QUEST_FAILED_NOT_ENOUGH_MONEY = 23,       //You don't have enough money for that quest.
	INVALIDREASON_DAILY_QUESTS_REMAINING        = 26,       //You have already completed 10 daily quests today
	INVALIDREASON_QUEST_FAILED_CAIS             = 27,       //You cannot complete quests once you have reached tired time
};

enum QuestShareMessages
{
	QUEST_PARTY_MSG_SHARING_QUEST   = 0,
	QUEST_PARTY_MSG_CANT_TAKE_QUEST = 1,
	QUEST_PARTY_MSG_ACCEPT_QUEST    = 2,
	QUEST_PARTY_MSG_REFUSE_QUEST    = 3,
	QUEST_PARTY_MSG_TOO_FAR         = 4,
	QUEST_PARTY_MSG_BUSY            = 5,
	QUEST_PARTY_MSG_LOG_FULL        = 6,
	QUEST_PARTY_MSG_HAVE_QUEST      = 7,
	QUEST_PARTY_MSG_FINISH_QUEST    = 8,
};

enum __QuestTradeSkill
{
	QUEST_TRSKILL_NONE           = 0,
	QUEST_TRSKILL_ALCHEMY        = 1,
	QUEST_TRSKILL_BLACKSMITHING  = 2,
	QUEST_TRSKILL_COOKING        = 3,
	QUEST_TRSKILL_ENCHANTING     = 4,
	QUEST_TRSKILL_ENGINEERING    = 5,
	QUEST_TRSKILL_FIRSTAID       = 6,
	QUEST_TRSKILL_HERBALISM      = 7,
	QUEST_TRSKILL_LEATHERWORKING = 8,
	QUEST_TRSKILL_POISONS        = 9,
	QUEST_TRSKILL_TAILORING      = 10,
	QUEST_TRSKILL_MINING         = 11,
	QUEST_TRSKILL_FISHING        = 12,
	QUEST_TRSKILL_SKINNING       = 13,
	QUEST_TRSKILL_JEWELCRAFTING  = 14,
};

enum QuestStatus
{
	QUEST_STATUS_NONE           = 0,
	QUEST_STATUS_COMPLETE       = 1,
	QUEST_STATUS_UNAVAILABLE    = 2,
	QUEST_STATUS_INCOMPLETE     = 3,
	QUEST_STATUS_AVAILABLE      = 4,
	MAX_QUEST_STATUS
};

enum __QuestGiverStatus
{
	DIALOG_STATUS_NONE                     = 0,
	DIALOG_STATUS_UNAVAILABLE              = 1,
	DIALOG_STATUS_CHAT                     = 2,
	DIALOG_STATUS_INCOMPLETE               = 3,
	DIALOG_STATUS_REWARD_REP               = 4,
	DIALOG_STATUS_AVAILABLE_REP            = 5,
	DIALOG_STATUS_AVAILABLE                = 6,
	DIALOG_STATUS_REWARD2                  = 7,             // not yellow dot on minimap
	DIALOG_STATUS_REWARD                   = 8              // yellow dot on minimap
};

enum __QuestFlags
{
	// Flags used at server and sended to client
	QUEST_FLAGS_STAY_ALIVE     = 1,                         // Not used currently
	QUEST_FLAGS_EVENT          = 2,                         // Not used currently
	QUEST_FLAGS_EXPLORATION    = 4,                         // Not used currently
	QUEST_FLAGS_SHARABLE       = 8,                         // Can be shared: Player::CanShareQuest()
	//QUEST_FLAGS_NONE2        = 16,                        // Not used currently
	QUEST_FLAGS_EPIC           = 32,                        // Not used currently: Unsure of content
	QUEST_FLAGS_RAID           = 64,                        // Not used currently
	QUEST_FLAGS_TBC            = 128,                       // Not used currently: Available if TBC expension enabled only
	QUEST_FLAGS_UNK2           = 256,                       // Not used currently: _DELIVER_MORE Quest needs more than normal _q-item_ drops from mobs
	QUEST_FLAGS_HIDDEN_REWARDS = 512,                       // Items and money rewarded only sent in SMSG_QUESTGIVER_OFFER_REWARD (not in SMSG_QUESTGIVER_QUEST_DETAILS or in client quest log(SMSG_QUEST_QUERY_RESPONSE))
	QUEST_FLAGS_UNK4           = 1024,                      // Not used currently: Unknown tbc flag
	QUEST_FLAGS_TBC_RACES      = 2048,                      // Not used currently: Bloodelf/draenei starting zone quests
	QUEST_FLAGS_DAILY          = 4096,                      // Used to know quest is Daily one

	// Mangos flags for set SpecialFlags in DB if required but used only at server
	QUEST_MANGOS_FLAGS_REPEATABLE           = 0x010000,     // Set by 1 in SpecialFlags from DB
	QUEST_MANGOS_FLAGS_EXPLORATION_OR_EVENT = 0x020000,     // Set by 2 in SpecialFlags from DB (if reequired area explore, spell SPELL_EFFECT_QUEST_COMPLETE casting, table `*_script` command SCRIPT_COMMAND_QUEST_EXPLORED use, set from script DLL)
	QUEST_MANGOS_FLAGS_DB_ALLOWED = 0xFFFF | QUEST_MANGOS_FLAGS_REPEATABLE | QUEST_MANGOS_FLAGS_EXPLORATION_OR_EVENT,

	// Mangos flags for internal use only
	QUEST_MANGOS_FLAGS_DELIVER              = 0x040000,     // Internal flag computed only
	QUEST_MANGOS_FLAGS_SPEAKTO              = 0x080000,     // Internal flag computed only
	QUEST_MANGOS_FLAGS_KILL_OR_CAST         = 0x100000,     // Internal flag computed only
	QUEST_MANGOS_FLAGS_TIMED                = 0x200000,     // Internal flag computed only
};

// This Quest class provides a convenient way to access a few pretotaled (cached) quest details,
// all base quest information, and any utility functions such as generating the amount of
// xp to give
class Quest
{
	friend class ObjectMgr;
public:
	Quest(class Field * questRecord);
	ui32 XPValue(class CPlayer *pPlayer ) const;

	bool HasFlag( ui32 flag ) const { return ( QuestFlags & flag ) != 0; }
	void SetFlag( ui32 flag ) { QuestFlags |= flag; }

	// table data accessors:
	ui32 GetQuestId() const { return QuestId; }
	i32  GetZoneOrSort() const { return ZoneOrSort; }
	i32  GetSkillOrClass() const { return SkillOrClass; }
	ui32 GetMinLevel() const { return MinLevel; }
	ui32 GetQuestLevel() const { return QuestLevel; }
	ui32 GetType() const { return Type; }
	ui32 GetRequiredRaces() const { return RequiredRaces; }
	ui32 GetRequiredSkillValue() const { return RequiredSkillValue; }
	ui32 GetRepObjectiveFaction() const { return RepObjectiveFaction; }
	i32  GetRepObjectiveValue() const { return RepObjectiveValue; }
	ui32 GetRequiredMinRepFaction() const { return RequiredMinRepFaction; }
	i32  GetRequiredMinRepValue() const { return RequiredMinRepValue; }
	ui32 GetRequiredMaxRepFaction() const { return RequiredMaxRepFaction; }
	i32  GetRequiredMaxRepValue() const { return RequiredMaxRepValue; }
	ui32 GetSuggestedPlayers() const { return SuggestedPlayers; }
	ui32 GetLimitTime() const { return LimitTime; }
	i32  GetPrevQuestId() const { return PrevQuestId; }
	i32  GetNextQuestId() const { return NextQuestId; }
	i32  GetExclusiveGroup() const { return ExclusiveGroup; }
	ui32 GetNextQuestInChain() const { return NextQuestInChain; }
	ui32 GetCharTitleId() const { return CharTitleId; }
	ui32 GetSrcItemId() const { return SrcItemId; }
	ui32 GetSrcItemCount() const { return SrcItemCount; }
	ui32 GetSrcSpell() const { return SrcSpell; }
	std::string GetTitle() const { return Title; }
	std::string GetDetails() const { return Details; }
	std::string GetObjectives() const { return Objectives; }
	std::string GetOfferRewardText() const { return OfferRewardText; }
	std::string GetRequestItemsText() const { return RequestItemsText; }
	std::string GetEndText() const { return EndText; }
	i32  GetRewOrReqMoney() const;

	ui32 GetRewMoneyMaxLevel() const { return RewMoneyMaxLevel; }
	// use in XP calculation at client
	ui32 GetRewSpell() const { return RewSpell; }
	ui32 GetRewSpellCast() const { return RewSpellCast; }
	ui32 GetRewMailTemplateId() const { return RewMailTemplateId; }
	ui32 GetRewMailDelaySecs() const { return RewMailDelaySecs; }
	ui32 GetPointMapId() const { return PointMapId; }
	float  GetPointX() const { return PointX; }
	float  GetPointY() const { return PointY; }
	ui32 GetPointOpt() const { return PointOpt; }
	ui32 GetIncompleteEmote() const { return IncompleteEmote; }
	ui32 GetCompleteEmote() const { return CompleteEmote; }
	ui32 GetQuestStartScript() const { return QuestStartScript; }
	ui32 GetQuestCompleteScript() const { return QuestCompleteScript; }
	bool   IsRepeatable() const { return QuestFlags & QUEST_MANGOS_FLAGS_REPEATABLE; }
	bool   IsAutoComplete() const { return Objectives.empty(); }
	ui32 GetFlags() const { return QuestFlags; }
	bool   IsDaily() const { return QuestFlags & QUEST_FLAGS_DAILY; }

	// multiple values
	std::string ObjectiveText[QUEST_OBJECTIVES_COUNT];
	ui32 ReqItemId[QUEST_OBJECTIVES_COUNT];
	ui32 ReqItemCount[QUEST_OBJECTIVES_COUNT];
	ui32 ReqSourceId[QUEST_SOURCE_ITEM_IDS_COUNT];
	ui32 ReqSourceCount[QUEST_SOURCE_ITEM_IDS_COUNT];
	ui32 ReqSourceRef[QUEST_SOURCE_ITEM_IDS_COUNT];
	i32  ReqCreatureOrGOId[QUEST_OBJECTIVES_COUNT];   // >0 Creature <0 Gameobject
	ui32 ReqCreatureOrGOCount[QUEST_OBJECTIVES_COUNT];
	ui32 ReqSpell[QUEST_OBJECTIVES_COUNT];
	ui32 RewChoiceItemId[QUEST_REWARD_CHOICES_COUNT];
	ui32 RewChoiceItemCount[QUEST_REWARD_CHOICES_COUNT];
	ui32 RewItemId[QUEST_REWARDS_COUNT];
	ui32 RewItemCount[QUEST_REWARDS_COUNT];
	ui32 RewRepFaction[QUEST_REPUTATIONS_COUNT];
	i32  RewRepValue[QUEST_REPUTATIONS_COUNT];
	ui32 DetailsEmote[QUEST_EMOTE_COUNT];
	ui32 OfferRewardEmote[QUEST_EMOTE_COUNT];

	ui32 GetReqItemsCount() const { return m_reqitemscount; }
	ui32 GetReqCreatureOrGOcount() const { return m_reqCreatureOrGOcount; }
	ui32 GetRewChoiceItemsCount() const { return m_rewchoiceitemscount; }
	ui32 GetRewItemsCount() const { return m_rewitemscount; }

	typedef std::vector<i32> PrevQuests;
	PrevQuests prevQuests;
	typedef std::vector<ui32> PrevChainQuests;
	PrevChainQuests prevChainQuests;

	// cached data
private:
	ui32 m_reqitemscount;
	ui32 m_reqCreatureOrGOcount;
	ui32 m_rewchoiceitemscount;
	ui32 m_rewitemscount;

	// table data
protected:
	ui32 QuestId;
	i32  ZoneOrSort;
	i32  SkillOrClass;
	ui32 MinLevel;
	ui32 QuestLevel;
	ui32 Type;
	ui32 RequiredRaces;
	ui32 RequiredSkillValue;
	ui32 RepObjectiveFaction;
	i32  RepObjectiveValue;
	ui32 RequiredMinRepFaction;
	i32  RequiredMinRepValue;
	ui32 RequiredMaxRepFaction;
	i32  RequiredMaxRepValue;
	ui32 SuggestedPlayers;
	ui32 LimitTime;
	ui32 QuestFlags;
	ui32 CharTitleId;
	i32  PrevQuestId;
	i32  NextQuestId;
	i32  ExclusiveGroup;
	ui32 NextQuestInChain;
	ui32 SrcItemId;
	ui32 SrcItemCount;
	ui32 SrcSpell;
	std::string Title;
	std::string Details;
	std::string Objectives;
	std::string OfferRewardText;
	std::string RequestItemsText;
	std::string EndText;
	i32  RewOrReqMoney;
	ui32 RewMoneyMaxLevel;
	ui32 RewSpell;
	ui32 RewSpellCast;
	ui32 RewMailTemplateId;
	ui32 RewMailDelaySecs;
	ui32 PointMapId;
	float  PointX;
	float  PointY;
	ui32 PointOpt;
	ui32 IncompleteEmote;
	ui32 CompleteEmote;
	ui32 QuestStartScript;
	ui32 QuestCompleteScript;
};

enum QuestUpdateState
{
	QUEST_UNCHANGED = 0,
	QUEST_CHANGED = 1,
	QUEST_NEW = 2
};

struct QuestStatusData
{
	QuestStatusData()
		: m_status(QUEST_STATUS_NONE),m_rewarded(false),
		m_explored(false), m_timer(0), uState(QUEST_NEW)
	{
		memset(m_itemcount,    0, QUEST_OBJECTIVES_COUNT * sizeof(ui32));
		memset(m_creatureOrGOcount, 0, QUEST_OBJECTIVES_COUNT * sizeof(ui32));
	}

	QuestStatus m_status;
	bool m_rewarded;
	bool m_explored;
	ui32 m_timer;
	QuestUpdateState uState;

	ui32 m_itemcount[ QUEST_OBJECTIVES_COUNT ];
	ui32 m_creatureOrGOcount[ QUEST_OBJECTIVES_COUNT ];
};

*/