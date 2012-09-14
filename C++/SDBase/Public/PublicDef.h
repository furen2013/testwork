#pragma once

#define XINJIANG_VERSION

#define STR_MAXLEN_ACCOUNT 20
#define STR_MAXLEN_DESKEY 64
#define STR_MAXLEN_RASKEY 128

#define MAX_GUILD_BANK_TABS 6


enum GuildEvent
{
	GUILD_EVENT_PROMOTION		   =0x0,
	GUILD_EVENT_DEMOTION			=0x1,
	GUILD_EVENT_MOTD				=0x2,
	GUILD_EVENT_JOINED			  =0x3,
	GUILD_EVENT_LEFT				=0x4,
	GUILD_EVENT_REMOVED			 =0x5,
	GUILD_EVENT_LEADER_IS		   =0x6,
	GUILD_EVENT_LEADER_CHANGED	  =0x7,
	GUILD_EVENT_DISBANDED		   =0x8,
	GUILD_EVENT_TABARDCHANGE		=0x9,
	GUILD_EVENT_UNK1				=0xA,
	GUILD_EVENT_UNK2				=0xB,
	GUILD_EVENT_HASCOMEONLINE	   =0xC,
	GUILD_EVENT_HASGONEOFFLINE	  =0xD,
	GUILD_EVENT_BANKTABBOUGHT		= 0xF,
	GUILD_EVENT_SETNEWBALANCE		= 0x11,
	GUILD_EVENT_SETRANK				= 0x12,
	GUILD_EVENT_SET_INFORMATION		= 0x13,
};

enum GuildLogEventE
{
	GUILD_LOG_EVENT_INVITE		= 1,
	GUILD_LOG_EVENT_JOIN		= 2,
	GUILD_LOG_EVENT_PROMOTION	= 3,
	GUILD_LOG_EVENT_DEMOTION	= 4,
	GUILD_LOG_EVENT_REMOVAL		= 5,
	GUILD_LOG_EVENT_LEFT		= 6,
	GUILD_LOG_EVENT_SETRANK		= 7,
};

enum GUILDEMBLEM_ERRORS
{
	ERR_GUILDEMBLEM_SUCCESS,
	ERR_GUILDEMBLEM_INVALID_TABARD_COLORS,
	ERR_GUILDEMBLEM_NOGUILD,
	ERR_GUILDEMBLEM_NOTGUILDMASTER,
	ERR_GUILDEMBLEM_NOTENOUGHMONEY,
	ERR_GUILDEMBLEM_INVALIDVENDOR,
};


enum GuildRankRights
{
	GR_RIGHT_EMPTY			= 0x00200,
	GR_RIGHT_GCHATLISTEN	= 0x00001,
	GR_RIGHT_GCHATSPEAK		= 0x00002,
	GR_RIGHT_OFFCHATLISTEN	= 0x00004,
	GR_RIGHT_OFFCHATSPEAK	= 0x00008,
	GR_RIGHT_INVITE			= 0x00010,
	GR_RIGHT_REMOVE			= 0x00020,
	GR_RIGHT_SET_RANK		= 0x00040,
	GR_RIGHT_DECLARE_WAR	= 0x00080,
	GR_RIGHT_FENGYIN		= 0x00100,
	// unknown 0x00200
	// unknown 0x00400
	// unknown 0x00800
	GR_RIGHT_SETMOTD		= 0x01000,
	GR_RIGHT_EPNOTE			= 0x02000,
	GR_RIGHT_VIEWOFFNOTE	= 0x04000,
	GR_RIGHT_EOFFNOTE		= 0x08000,
	GR_RIGHT_EGUILDINFO		= 0x10000,
	GR_RIGHT_ALL			= 0x1F1FF,

	GR_RIGHT_CAPTAIN		= GR_RIGHT_ALL - GR_RIGHT_DECLARE_WAR - GR_RIGHT_EGUILDINFO,
	GR_RIGHT_DEFAULT		= GR_RIGHT_GCHATLISTEN | GR_RIGHT_GCHATSPEAK | GR_RIGHT_EMPTY,

	GR_RIGHT_GUILD_BANK_VIEW_TAB		= 0x01,
	GR_RIGHT_GUILD_BANK_DEPOSIT_ITEMS	= 0x02,
};

enum CharterTypes
{
	CHARTER_TYPE_GUILD			= 0,
	CHARTER_TYPE_ARENA_2V2		= 1,
	CHARTER_TYPE_ARENA_3V3		= 2,
	CHARTER_TYPE_ARENA_5V5		= 3,
	NUM_CHARTER_TYPES			= 4,
};

enum ChatChannelType
{
	CHAT_CHANNEL_TYPE_PRIVATE	= 0,
	CHAT_CHANNEL_TYPE_CITY		= 1,
	CHAT_CHANNEL_TYPE_TRADE		= 2,
	CHAT_CHANNEL_TYPE_LFG		= 3,
};

enum instance_category_t
{
	INSTANCE_CATEGORY_ARENA,
	INSTANCE_CATEGORY_REFRESH_MONSTER,
	INSTANCE_CATEGORY_DYNAMIC,
	INSTANCE_CATEGORY_ESCAPE,
	INSTANCE_CATEGORY_UNIQUE_PVP_ZONE,
	INSTANCE_CATEGORY_TOWER_DEFENSE,
	INSTANCE_CATEGORY_UNIQUE_CASTLE,
	INSTANCE_CATEGORY_BATTLE_GROUND,
	INSTANCE_CATEGORY_TEAM_ARENA,
	INSTANCE_CATEGORY_RAID,
	INSTANCE_CATEGORY_ADVANCED_BATTLE_GROUND,
	INSTANCE_CATEGORY_NUMBER
};


class LocationVector;

struct spawn_info
{
	uint32 entry;
	uint32 index;
	uint32 mapid;
	uint32 minlevel;
	uint32 maxlevel;
	uint32 interval;
};

struct sunyou_instance_configuration
{
	instance_category_t category;
	int32 iconid;
	int32 mapid;
	int32 minlevel;
	int32 maxlevel;
	int32 maxplayer;
	int32 expire;
	int32 cost_type;
	int32 cost_value1;
	int32 cost_value2;
	int32 enter_limit;
	int32 bg_faction_min_player;
	int32 bg_faction_max_player;
	int32 bg_faction_count;
	int32 open_start[6];
	int32 open_end[6];
	std::vector<LocationVector*> random_vrl;
	std::vector<spawn_info*> vsi;
	uint32 resurrect_time;
	std::string lua_script;
};

enum
{
	DOTA_2_KILL = 1,
	DOTA_3_KILL = 2,
	DOTA_4_KILL = 4,
	DOTA_5_KILL = 8,

	DOTA_FIRST_BLOOD = 16,
	DOTA_KILLING_SPREE = 32,
	DOTA_DOMINATING = 64,
	DOTA_MEGAKILL = 128,
	DOTA_UNSTOPPABLE = 256,
	DOTA_WHICKEDSICK = 512,
	DOTA_MONSTERKILL = 1024,
	DOTA_GODLIKE = 2048,
	DOTA_HOLYSHIT = 4096,
};

struct account_info_t
{
	int id;
	std::string name;
	std::string gm_flag;
	std::string source;
	std::string email;
	int question[2];
	std::string nationality;
	std::string province;
	std::string city;
	uint16 birth_year;
	uint8 birth_month;
	uint8 birth_day;
	std::string id_card;
	std::string description;
	uint32 reg_time;
	std::string safe_lock_pwd;
	uint32 safe_lock_flag;
	uint32 occupation;
	uint32 education;
	std::string qq;
	std::string msn;
	std::string telephone;
	std::string zipcode;
	std::string address;
	uint8 gender;
	std::string real_name;
};

inline void copy_account_info( const account_info_t& src, account_info_t& dest )
{
	dest.email = src.email;
	dest.question[0] = src.question[0];
	dest.question[1] = src.question[1];
	dest.nationality = src.nationality;
	dest.province = src.province;
	dest.city = src.city;
	dest.birth_year = src.birth_year;
	dest.birth_month = src.birth_month;
	dest.birth_day = src.birth_day;
	dest.id_card = src.id_card;
	dest.description = src.description;
	dest.occupation = src.occupation;
	dest.education = src.education;
	dest.qq = src.qq;
	dest.msn = src.msn;
	dest.telephone = src.telephone;
	dest.zipcode = src.zipcode;
	dest.address = src.address;
	dest.gender = src.gender;
	dest.real_name = src.real_name;
}

inline CPacketSn& operator << ( CPacketSn& sn, const account_info_t& info )
{
	sn << info.id << info.name << info.gm_flag << info.source << info.email << info.question[0] << info.question[1] << info.nationality << info.province
		<< info.city << info.birth_year << info.birth_month << info.birth_day << info.id_card << info.description << info.reg_time
		<< info.safe_lock_pwd << info.safe_lock_flag << info.occupation << info.education << info.qq << info.msn << info.telephone << info.zipcode << info.address
		<< info.gender << info.real_name;
	return sn;
}

inline CPacketUsn& operator >> ( CPacketUsn& usn, account_info_t& info )
{
	usn >> info.id >> info.name >> info.gm_flag >> info.source >> info.email >> info.question[0] >> info.question[1] >> info.nationality >> info.province
		>> info.city >> info.birth_year >> info.birth_month >> info.birth_day >> info.id_card >> info.description >> info.reg_time
		>> info.safe_lock_pwd >> info.safe_lock_flag >> info.occupation >> info.education >> info.qq >> info.msn >> info.telephone >> info.zipcode >> info.address
		>> info.gender >> info.real_name;
	return usn;
}

enum
{
	SYSTEMTIPS_LEVEL = 1, //等级提示
	SYSTEMTIPS_QUEST = 2, //可以领取的新任务
	SYSTEMTIPS_SKILL = 3, //可学习的新技能
	SYSTEMTIPS_EQUIP = 4, //可获得的新装备
	SYSTEMTIPS_ITEM = 5, //可使用的新消耗道具
	SYSTEMTIPS_MAP = 6, //适合练级的区域
	SYSTEMTIPS_WAY = 7, //本级别最适合游戏途径
	SYSTEMTIPS_SYS = 8, //系统提示
};
