#pragma once
#ifndef PLAYER_DEF_H
#define PLAYER_DEF_H
enum Gender
{
	GENDER_FEMALE	= 0,
	GENDER_MALE		= 1,
	GENDER_NONE		= 2
};

enum Classes
{
	CLASS_MIN		= 0,
	CLASS_WARRIOR	= 1,		//	武修	MASK = 1
	CLASS_BOW		= 2,		//	羽箭	MASK = 2
	CLASS_PRIEST	= 3,		//	仙道	MASK = 4
	CLASS_MAGE		= 4,		//	真巫	MASK = 8
	CLASS_DRUID,				//	变身	MASK = 
	CLASS_ROGUE,				//	刺客	MASK = 8
	CLASS_MAX = 8,
};

static const char* class_name[] = 
{
	"","武修","羽箭","仙道","真巫",
};

#define CALSS_MASK_DATIANMOWUSHI		0x00000001		/*大天魔武师*/
#define CLASS_MASK_ZIWEITIANWUSHI		0x00000002		/*紫薇天武师*/
#define CLASS_MASK_MOWUSHI (CALSS_MASK_DATIANMOWUSHI & CLASS_MASK_ZIWEITIANWUSHI)				/*魔武使*/
#define CLASS_MASK_BEIJIZHENWUSHI		0x00000004		/*北极真武师*/
#define CLASS_MASK_QIXINGZHENWUSHI		0x00000008		/*七星真武师*/
#define CLASS_MASK_ZHENWUSHI (CLASS_MASK_BEIJIZHENWUSHI & CLASS_MASK_QIXINGZHENWUSHI)			/*真武使*/
#define CLASS_MASK_WUXIUZHE (CLASS_MASK_MOWUSHI & CLASS_MASK_ZHENWUSHI)											/*武修者*/
#define CLASS_MASK_XUANWUDUNJIASHI		0x00000010		/*玄武遁甲师*/
#define CLASS_MASK_XUANWUHUJIASHI		0x00000020		/*玄武护甲师*/
#define CLASS_MASK_XUANWUSHI (CLASS_MASK_XUANWUDUNJIASHI & CLASS_MASK_XUANWUHUJIASHI)			/*玄武使*/
#define CLASS_MASK_BAIHUTIANSHASHI		0x00000040		/*白虎天杀师*/
#define CLASS_MASK_BAIHUPOJUNSHI		0x00000080		/*白虎破军师*/
#define CLASS_MASK_BAIHUSHI	(CLASS_MASK_BAIHUTIANSHASHI & CLASS_MASK_BAIHUPOJUNSHI)				/*白虎使*/
#define CLASS_MASK_QIXINGZHE (CLASS_MASK_XUANWUSHI & CLASS_MASK_BAIHUSHI)										/*骑行者*/
#define CLASS_MASK_WUXIU (CLASS_MASK_WUXIUZHE & CLASS_MASK_QIXINGZHE)															/*武修*/

#define CLASS_MASK_SIMINGQIDAOSHI		0x00000100		/*司命祈祷师*/
#define CLASS_MASK_YOUMINGFENGXIANSHI	0x00000200		/*幽冥奉献师*/
#define CLASS_MASK_QIDAOSHI (CLASS_MASK_SIMINGQIDAOSHI & CLASS_MASK_YOUMINGFENGXIANSHI)			/*祈祷使*/
#define CLASS_MASK_FENTIANGAOMINGSHI	0x00000400		/*焚天告命师*/
#define CLASS_MASK_JIUYOUXIANJISHI		0x00000800		/*九幽献祭师*/
#define CALSS_MASK_ZHOUSHASHI (CLASS_MASK_FENTIANGAOMINGSHI & CLASS_MASK_JIUYOUXIANJISHI)		/*咒杀使*/
#define CLASS_MASK_ZHONGLINGZHE (CLASS_MASK_QIDAOSHI & CALSS_MASK_ZHOUSHASHI)									/*种灵者*/
#define CLASS_MASK_LINGZHUZHAOHUANSHI	0x00001000		/*领主召唤师*/
#define CLASS_MASK_SHENYUANZHAOHUANSHI	0x00002000		/*深渊召唤师*/
#define CLASS_MASK_ZHAOHUANSHI 	(CLASS_MASK_LINGZHUZHAOHUANSHI & CLASS_MASK_SHENYUANZHAOHUANSHI) /*召唤使*/
#define CLASS_MASK_ZIRANKUILEISHI		0x00004000		/*自然傀儡师*/
#define CLASS_MASK_JIGUANKUILEISHI		0x00008000		/*机关傀儡师*/
#define CLASS_MASK_KUILEISHI (CLASS_MASK_ZIRANKUILEISHI & CLASS_MASK_JIGUANKUILEISHI)			/*傀儡使*/
#define CLASS_MASK_KUILEIZHE (CLASS_MASK_ZHAOHUANSHI & CLASS_MASK_KUILEISHI)								/*傀儡者*/
#define CLASS_MASK_ZHENWU (CLASS_MASK_ZHONGLINGZHE & CLASS_MASK_KUILEIZHE)														/*真巫*/

#define CLASS_MASK_TIANYIZHENSHUISHI	0x00010000		/*天一真水师*/
#define CLASS_MASK_WANXIANGJINGSHUISHI	0x00020000		/*万象净水师*/
#define CALSS_MASK_NINGBINGZHE CLASS_MASK_TIANYIZHENSHUISHI	& CLASS_MASK_WANXIANGJINGSHUISHI	/*凝冰使*/
#define CLASS_MASK_SIJIUZHENHUOSHI		0x00040000		/*四九真火师*/
#define CLASS_MASK_HUOLIANLIEYANSHI		0x00080000		/*红莲烈焰师*/
#define CLASS_MASK_LIEYANSHI (CLASS_MASK_SIJIUZHENHUOSHI & CLASS_MASK_HUOLIANLIEYANSHI)			/*烈焰使*/
#define CLASS_DAOFAZHE (CALSS_MASK_NINGBINGZHE & CLASS_MASK_LIEYANSHI)										/*道法者*/
#define CLASS_MASK_ZISHUFUZHOUSHI		0x00100000		/*紫书符咒师*/
#define CLASS_MASK_SANXINGFUZHOUSHI		0x00200000		/*三星符咒师*/
#define CLASS_MASK_FUZHOUSHI (CLASS_MASK_ZISHUFUZHOUSHI & CLASS_MASK_SANXINGFUZHOUSHI)			/*符咒使*/
#define CLASS_MASK_YUZHIZHENFASHI		0x00400000		/*玉石阵法师*/
#define CLASS_MASK_XUKONGZHENFASHI		0x00800000		/*虚空阵法师*/
#define CLASS_MASK_ZHENFASHI (CLASS_MASK_YUZHIZHENFASHI & CLASS_MASK_XUKONGZHENFASHI)			/*阵法使*/
#define CLASS_MASK_SHUCHENGZHE (CLASS_MASK_FUZHOUSHI & CLASS_MASK_ZHENFASHI)								/*术承者*/
#define CLASS_MASK_XIANDAO (CLASS_DAOFAZHE & CLASS_MASK_FUZHOUSHI)																/*仙道*/

#define CLASS_MASK_ZHONGJIANSHASHI		0x01000000		/*终极暗杀师*/
#define CLASS_MASK_CISHAZHANDOUSHI		0x02000000		/*刺杀战斗师*/
#define CLASS_MASK_LIESHASHI (CLASS_MASK_ZHONGJIANSHASHI & CLASS_MASK_CISHAZHANDOUSHI)				/*猎杀使*/
#define CLASS_MASK_NUYULIESHOUSHI		0x04000000		/*怒羽猎兽使*/
#define CLASS_MASK_CONGLINLIESHOUSHI	0x08000000		/*丛林猎兽使*/
#define CLASS_MASK_LIESHOUSHI (CLASS_MASK_NUYULIESHOUSHI & CLASS_MASK_CONGLINLIESHOUSHI)			/*猎兽使*/
#define CLASS_MASK_KONGSHOUZHE (CLASS_MASK_LIESHASHI & CLASS_MASK_LIESHOUSHI)											/*控兽者*/
#define CLASS_MASK_YINGYANSHESHOUSHI	0x10000000		/*鹰眼射手师*/
#define CLASS_MASK_CHANRAOSHESHOUSHI	0x20000000		/*缠绕射手师*/
#define CLASS_MASK_AOFAJIANSHI (CLASS_MASK_YINGYANSHESHOUSHI & CLASS_MASK_CHANRAOSHESHOUSHI)		/*奥法箭使*/
#define CLASS_MASK_HUANXIANGSHESHOUSHI	0x40000000		/*幻象射手师*/
#define CLASS_MASK_LUOXINGSHESHOUSHI	0x80000000		/*落星射手师*/
#define CLASS_MASK_HUANYINGJIANSHI (CLASS_MASK_HUANXIANGSHESHOUSHI & CLASS_MASK_LUOXINGSHESHOUSHI) /*幻影箭使*/
#define CLASS_MASK_JIANLINGZHE (CLASS_MASK_AOFAJIANSHI & CLASS_MASK_HUANYINGJIANSHI)									/*箭灵者*/
#define CLASS_MASK_YUJIAN (CLASS_MASK_KONGSHOUZHE & CLASS_MASK_JIANLINGZHE)																/*羽箭*/

enum Races
{
	RACE_MIN	= 0,
	RACE_YAO	= 1,		//	妖		MASK = 1
	RACE_REN	 = 2,		//	巫		MASK = 2
	RACE_WU		= 3,		//	人		MASK = 4
	RACE_MAX	= 4,
};										

static const char* race_name[] = 
{
	"","妖","人","巫",
};

//////////////////////////////////////////////////////////////////////////
//	Group defines
//////////////////////////////////////////////////////////////////////////
enum GroupTypes
{
	GROUP_TYPE_PARTY					= 0,
	GROUP_TYPE_RAID						= 1,
};

enum MaxGroupCount
{
	MAX_GROUP_SIZE_PARTY				= 5,
	MAX_GROUP_SIZE_RAID					= 30,
};
 


enum ShapeshiftForm
{
	FORM_NORMAL             = 0,
	FORM_CAT                = 1,
	FORM_TREE               = 2,
	FORM_TRAVEL             = 3,
	FORM_AQUA               = 4,
	FORM_BEAR               = 5,
	FORM_AMBIENT            = 6,
	FORM_GHOUL              = 7,
	FORM_DIREBEAR           = 8,
	FORM_CREATUREBEAR       = 14,
	FORM_GHOSTWOLF          = 16,
	FORM_BATTLESTANCE       = 17,
	FORM_DEFENSIVESTANCE    = 18,
	FORM_BERSERKERSTANCE    = 19,
	FORM_SWIFT              = 27,
	FORM_SHADOW             = 28,
	FORM_FLIGHT             = 29,
	FORM_STEALTH            = 30,
	FORM_MOONKIN            = 31,
	FORM_SPIRITOFREDEMPTION = 32,
};

//////////////////////////////////////////////////////////////////////////
//
//////////////////////////////////////////////////////////////////////////
// 
// 
// enum Languages
// {
// 	LANG_UNIVERSAL                              = 0x00,
// 	LANG_ORCISH                                 = 0x01,
// 	LANG_DARNASSIAN                             = 0x02,
// 	LANG_TAURAHE                                = 0x03,
// 	LANG_DWARVISH                               = 0x06,
// 	LANG_COMMON                                 = 0x07,
// 	LANG_DEMONIC                                = 0x08,
// 	LANG_TITAN                                  = 0x09,
// 	LANG_THELASSIAN                             = 0x0A,
// 	LANG_DRACONIC                               = 0x0B,
// 	LANG_KALIMAG                                = 0x0C,
// 	LANG_GNOMISH                                = 0x0D,
// 	LANG_TROLL                                  = 0x0E,
// 	LANG_GUTTERSPEAK                            = 0x21,
// 	LANG_DRAENEI                                = 0x23,
// 	NUM_LANGUAGES                               = 0x24
// };
//
//static const uint32 LanguageSkills[NUM_LANGUAGES] = {
//	0,				// UNIVERSAL		0x0s0
//	109,			// ORCISH			0x01
//	113,			// DARNASSIAN		0x02
//	115,			// TAURAHE			0x03
//	0,				// -				0x04
//	0,				// -				0x05
//	111,			// DWARVISH			0x06
//	98,				// COMMON			0x07
//	139,			// DEMON TONGUE		0x08
//	140,			// TITAN			0x09
//	137,			// THALSSIAN		0x0A
//	138,			// DRACONIC			0x0B
//	0,				// KALIMAG			0x0C
//	313,			// GNOMISH			0x0D
//	315,			// TROLL			0x0E
//	0,				// -				0x0F
//	0,				// -				0x10
//	0,				// -				0x11
//	0,				// -				0x12
//	0,				// -				0x13
//	0,				// -				0x14
//	0,				// -				0x15
//	0,				// -				0x16
//	0,				// -				0x17
//	0,				// -				0x18
//	0,				// -				0x19
//	0,				// -				0x1A
//	0,				// -				0x1B
//	0,				// -				0x1C
//	0,				// -				0x1D
//	0,				// -				0x1E
//	0,				// -				0x1F
//	0,				// -				0x20
//	673,			// -				0x21
//	0,				// -				0x22
//	759,			// -				0x23
//};
/*#define MSG_COLOR_YELLOW	"|r"
#define MSG_COLOR_RED	   "|cffff2020"
#define MSG_COLOR_GREEN	 "|c1f40af20"
#define MSG_COLOR_LIGHTRED  "|cffff6060"*/

#define MSG_COLOR_LIGHTRED	  "<color:ffff6060>"
#define MSG_COLOR_LIGHTBLUE	 "<color:ff00ccff>"
#define MSG_COLOR_BLUE		  "<color:ff0000ff>"
#define MSG_COLOR_GREEN		 "<color:ff00ff00>"
#define MSG_COLOR_ANN_GREEN	 "<color:1f40af20>"
#define MSG_COLOR_RED		   "<color:ffff0000>"
#define MSG_COLOR_GOLD		  "<color:ffffcc00>"
#define MSG_COLOR_GREY		  "<color:ff888888>"
#define MSG_COLOR_WHITE		 "<color:ffffffff>"
#define MSG_COLOR_SUBWHITE	  "<color:ffbbbbbb>"
#define MSG_COLOR_MAGENTA	   "<color:ffff00ff>"
#define MSG_COLOR_YELLOW		"<color:ffffff00>"
#define MSG_COLOR_CYAN		  "<color:ff00ffff>"

enum PartyUpdateFlags
{
	GROUP_UPDATE_FLAG_NONE						= 0,		// 0x00000000
	GROUP_UPDATE_FLAG_ONLINE					= 1,		// 0x00000001  uint8
	GROUP_UPDATE_FLAG_HEALTH					= 2,		// 0x00000002  uint16
	GROUP_UPDATE_FLAG_MAXHEALTH					= 4,		// 0x00000004  uint16
	GROUP_UPDATE_FLAG_POWER_TYPE				= 8,		// 0x00000008  uint16
	GROUP_UPDATE_FLAG_POWER						= 16,		// 0x00000010  uint16
	GROUP_UPDATE_FLAG_MAXPOWER					= 32,		// 0x00000020  uint16
	GROUP_UPDATE_FLAG_LEVEL						= 64,		// 0x00000040  uint16
	GROUP_UPDATE_FLAG_ZONEID					= 128,		// 0x00000080  uint16
	GROUP_UPDATE_FLAG_POSITION					= 256,		// 0x00000100  uint16, uint16
	GROUP_UPDATE_FLAG_PLAYER_AURAS				= 512,		// 0x00000200  uint64, uint16 for each uint64
	GROUP_UPDATE_FLAG_PET_GUID					= 1024,		// 0x00000400  uint64
	GROUP_UPDATE_FLAG_PET_NAME					= 2048,		// 0x00000800  string
	GROUP_UPDATE_FLAG_PET_DISPLAYID				= 4096,		// 0x00001000  uint16
	GROUP_UPDATE_FLAG_PET_HEALTH				= 8192,		// 0x00002000  uint16
	GROUP_UPDATE_FLAG_PET_MAXHEALTH				= 16384,	// 0x00004000  uint16
	GROUP_UPDATE_FLAG_PET_POWER_TYPE			= 32768,	// 0x00008000  uint8
	GROUP_UPDATE_FLAG_PET_POWER					= 65535,	// 0x00010000  uint16
	GROUP_UPDATE_FLAG_PET_MAXPOWER				= 131070,	// 0x00020000  uint16
	GROUP_UPDATE_FLAG_PET_AURAS					= 262144,	// 0x00040000  uint64, uint16 for each uint64
	GROUP_UPDATE_FLAG_EQUIPMENT					= 524288,
	GROUP_UPDATE_FLAG_MAPID						= 1048576,
};

enum PartyUpdateFlagGroups
{
	GROUP_UPDATE_TYPE_FULL_CREATE				=	GROUP_UPDATE_FLAG_ONLINE | GROUP_UPDATE_FLAG_HEALTH | GROUP_UPDATE_FLAG_MAXHEALTH |
	GROUP_UPDATE_FLAG_POWER | GROUP_UPDATE_FLAG_LEVEL |
	GROUP_UPDATE_FLAG_MAPID | GROUP_UPDATE_FLAG_ZONEID | GROUP_UPDATE_FLAG_MAXPOWER | GROUP_UPDATE_FLAG_POSITION,
	GROUP_UPDATE_TYPE_FULL_REQUEST_REPLY		=   0x7FFC0BFF,
};

enum PartyErrors
{
	ERR_PARTY_NO_ERROR					= 0,
	ERR_PARTY_CANNOT_FIND				= 1,
	ERR_PARTY_IS_NOT_IN_YOUR_PARTY		= 2,
	ERR_PARTY_UNK						= 3,
	ERR_PARTY_IS_FULL					= 4,
	ERR_PARTY_ALREADY_IN_GROUP			= 5,
	ERR_PARTY_YOU_ARENT_IN_A_PARTY		= 6,
	ERR_PARTY_YOU_ARE_NOT_LEADER		= 7,
	ERR_PARTY_WRONG_FACTION				= 8,
	ERR_PARTY_IS_IGNORING_YOU			= 9,
};

enum QuickGroupUpdateFlags
{
	PARTY_UPDATE_FLAG_POSITION			= 1,
	PARTY_UPDATE_FLAG_ZONEID			= 2,
	PARTY_UPDATE_FLAG_MAPID				= 3,

	PARTY_UPDATE_FLAG_PET_NAME			= 4,
	PARTY_UPDATE_FLAG_PET_AURAS			= 5,
};



enum PlayerFlags
{
	PLAYER_FLAG_PARTY_LEADER		= 0x01,
	PLAYER_FLAG_AFK					= 0x02,
	PLAYER_FLAG_DND					= 0x04,
	PLAYER_FLAG_GM					= 0x08,
	PLAYER_FLAG_DEATH_WORLD_ENABLE  = 0x10,
	PLAYER_FLAG_RESTING				= 0x20,
	PLAYER_FLAG_UNKNOWN1            = 0x40,
	PLAYER_FLAG_FREE_FOR_ALL_PVP	= 0x80,
	PLAYER_FLAG_UNKNOWN2            = 0x100,
	PLAYER_FLAG_PVP_TOGGLE			= 0x200,
	PLAYER_FLAG_NOHELM				= 0x400,
	PLAYER_FLAG_NOCLOAK				= 0x800,
	PLAYER_FLAG_NEED_REST_3_HOURS	= 0x1000,
	PLAYER_FLAG_NEED_REST_5_HOURS	= 0x2000,
};

enum ladder_category
{
	LADDER_KILL_COUNT,
	LADDER_BE_KILL_COUNT,
	LADDER_TOTAL_HONOR,
	LADDER_LEVEL,
	LADDER_COIN,
	LADDER_TOTAL_CONTRIBUTE,
	LADDER_GUILD_LEVEL,
	LADDER_TOTAL_CHARGE,
	LADDER_ARENA_1V1,
	LADDER_ARENA_2V2,
	LADDER_ARENA_3V3,
	LADDER_ARENA_4V4,
	LADDER_ARENA_5V5,
	LADDER_ARENA_LV80_1V1,
	LADDER_ARENA_LV80_2V2,
	LADDER_ARENA_LV80_3V3,
	LADDER_ARENA_LV80_4V4,
	LADDER_ARENA_LV80_5V5,
	LADDER_MAX,
};

struct ladder_info
{
	uint32 key;
	uint32 playerid;			//如果是公会排行榜就是公会id
	std::string playername;		//如果是公会排行榜就是会长名称:公会名称
	uint8 nrace;uint8 nclass;
};
inline bool operator < ( const ladder_info& a, const ladder_info& b )
{
	return a.key > b.key;
}

inline CPacketSn& operator << ( CPacketSn& sn, const ladder_info& info )
{
	sn << info.key << info.playerid << info.playername << info.nrace << info.nclass;
	return sn;
}

inline CPacketUsn& operator >> ( CPacketUsn& usn, ladder_info& info )
{
	usn >> info.key >> info.playerid >> info.playername >> info.nrace >> info.nclass;
	return usn;
}

typedef std::vector<ladder_info> ladder_vector;
struct ladders
{
	ladder_vector lv[LADDER_MAX][RACE_MAX]; // 数组第一个下标表示：0全部 1妖 2人 3巫，  数组第二个下标表示：排行榜的类型
};

struct stTitle
{
	stTitle(){}
	stTitle(uint32 _title, uint32 _time_left){
		title = _title;
		time_left = _time_left;
		bModified = true;
	}
	uint32 title;
	uint32 time_left;
	bool bModified;
};


inline CPacketSn& operator << ( CPacketSn& sn, const stTitle& info )
{
	sn << info.title << info.time_left;
	return sn;
}

inline CPacketUsn& operator >> ( CPacketUsn& usn, stTitle& info )
{
	usn >> info.title >> info.time_left;
	return usn;
}


typedef std::map<uint32, stTitle> title_map;

enum give_exp_type
{
	GIVE_EXP_TYPE_KILL_MONSTER,
	GIVE_EXP_TYPE_QUEST,
	GIVE_EXP_TYPE_DYNAMIC_INSTANCE,
	GIVE_EXP_TYPE_GIFT,
	GIVE_EXP_TYPE_ACTIVITY,
	GIVE_EXP_TYPE_COUNT
};

struct battle_ground_player_detail_information
{
	uint32 id;
	std::string name;
	uint8 race;
	uint8 cls;
	uint16 kill;
	uint16 bekill;
	uint32 damage;
	uint32 healing;
	int32 honor;
};

inline CPacketSn& operator << ( CPacketSn& sn, const battle_ground_player_detail_information& info )
{
	sn << info.id << info.name << info.race << info.cls << info.kill << info.bekill << info.damage << info.healing << info.honor;
	return sn;
}

inline CPacketUsn& operator >> ( CPacketUsn& usn, battle_ground_player_detail_information& info )
{
	usn >> info.id >> info.name >> info.race >> info.cls >> info.kill >> info.bekill >> info.damage >> info.healing >> info.honor;
	return usn;
}

//#define RACEMASK_ALL_PLAYABLE \
//	((1<<(RACE_HUMAN-1))   |(1<<(RACE_ORC-1))          |(1<<(RACE_DWARF-1))   | \
//	(1<<(RACE_NIGHTELF-1))|(1<<(RACE_UNDEAD-1))|(1<<(RACE_TAUREN-1))  | \
//	(1<<(RACE_GNOME-1))   |(1<<(RACE_TROLL-1))        |(1<<(RACE_BLOODELF-1))| \
//	(1<<(RACE_DRAENEI-1)) )
//#define CLASSMASK_ALL_PLAYABLE \
//	((1<<(CLASS_WARRIOR-1))|(1<<(CLASS_HUNTER-1))| \
//	(1<<(CLASS_ROGUE-1))  |((1<<(CLASS_SHAMAN-1))| \
//	(1<<(CLASS_MAGE-1)) )
//
//#define CLASSMASK_WAND_USERS (1<<(CLASS_MAGE-1))

// 
// enum SwitchWeapon
// {
// 	DEFAULT_SWITCH_WEAPON       = 1500,                     //cooldown in ms
// 	ROGUE_SWITCH_WEAPON         = 1000
// };
// 
// enum MeleeHitOutcome<
// {
// 	MELEE_HIT_EVADE, MELEE_HIT_MISS, MELEE_HIT_DODGE, MELEE_HIT_BLOCK, MELEE_HIT_PARRY,
// 	MELEE_HIT_GLANCING, MELEE_HIT_CRIT, MELEE_HIT_CRUSHING, MELEE_HIT_NORMAL, MELEE_HIT_BLOCK_CRIT
// };
// 
// enum Stats
// {
// 	STAT_STRENGTH                      = 0,
// 	STAT_AGILITY                       = 1,
// 	STAT_STAMINA                       = 2,
// 	STAT_INTELLECT                     = 3,
// 	STAT_SPIRIT                        = 4
// };
// 
// #define MAX_STATS                        5
// 
// enum Powers
// {
// 	POWER_MANA                          = 0,
// 	POWER_RAGE                          = 1,
// 	POWER_FOCUS                         = 2,
// 	POWER_ENERGY                        = 3,
// 	POWER_HAPPINESS                     = 4,
// 	POWER_RUNES                         = 5
// };
// 
// #define MAX_POWERS                        5                 // not count POWER_RUNES for now
// 
// 
// // Player summoning auto-decline time (in secs)
// #define MAX_PLAYER_SUMMON_DELAY                   (2*MINUTE)
// #define MAX_MONEY_AMOUNT                       (0x7FFFFFFF-1)
// 
// //////////////////////////////////////////////////////////////////////////
// //	Trade
// //////////////////////////////////////////////////////////////////////////
// enum TRADE_STATUS
// {
// 	TRADE_STATUS_PLAYER_BUSY	    = 0x00,
// 	TRADE_STATUS_PROPOSED		    = 0x01,
// 	TRADE_STATUS_INITIATED		    = 0x02,
// 	TRADE_STATUS_CANCELLED		    = 0x03,
// 	TRADE_STATUS_ACCEPTED		    = 0x04,
// 	TRADE_STATUS_ALREADY_TRADING    = 0x05,
// 	TRADE_STATUS_PLAYER_NOT_FOUND   = 0x06,
// 	TRADE_STATUS_STATE_CHANGED	    = 0x07,
// 	TRADE_STATUS_COMPLETE		    = 0x08,
// 	TRADE_STATUS_UNACCEPTED		    = 0x09,
// 	TRADE_STATUS_TOO_FAR_AWAY	    = 0x0A,
// 	TRADE_STATUS_WRONG_FACTION	    = 0x0B,
// 	TRADE_STATUS_FAILED			    = 0x0C,
// 	TRADE_STATUS_DEAD			    = 0x0D,
// 	TRADE_STATUS_PETITION		    = 0x0E,
// 	TRADE_STATUS_PLAYER_IGNORED	    = 0x0F,
// };
// enum TRADE_DATA
// {
// 	TRADE_GIVE		= 0x00,
// 	TRADE_RECEIVE	 = 0x01,
// };

#endif //PLAYER_DEF_H