#pragma once
enum EMapItemType
{
	eMapItemTypeNone = 0,
	eMapItemTypeCoin,
	eMapItemTypeItem
};

enum EMapItemState
{
	eMapItemStateNone = 0,
	eMapItemStateLock,//锁定的掉落道具
	eMapItemStateFree,//自由拾取的掉落道具
	MapItemStateNum
};


#pragma pack(push,1)
struct MapInfo
{
	uint32 mapid;
	uint32 screenid;
	uint32 type;
	uint32 playerlimit;
	uint32 minlevel;
	float repopx;
	float repopy;
	float repopz;
	uint32 repopmapid;
	char * area_name;
	uint32 flags;
	uint32 cooldown;
	uint32 lvl_mod_a;
	uint32 required_quest;
	uint32 required_item;
	uint32 heroic_key_1;
	uint32 heroic_key_2;
	float update_distance;
	uint32 checkpoint_id;
	char* map_file;
	char* name;

	bool HasFlag(uint32 flag)
	{
		return (flags & flag) != 0;
	}
};

#pragma pack(pop)



enum BattleGroundTypes
{
	BATTLEGROUND_ALTERAC_VALLEY = 1,
	BATTLEGROUND_WARSONG_GULCH	= 2,
	BATTLEGROUND_ARATHI_BASIN	= 3,
	BATTLEGROUND_ARENA_2V2		= 4,
	BATTLEGROUND_ARENA_3V3		= 5,
	BATTLEGROUND_ARENA_5V5		= 6,
	BATTLEGROUND_EYE_OF_THE_STORM=7,
	BATTLEGROUND_NUM_TYPES		 =8,
};

/// Weather defines
enum WeatherTypes
{
	WEATHER_TYPE_NORMAL            = 0, // NORMAL
	WEATHER_TYPE_FOG               = 1, // FOG --> current value irrelant
	WEATHER_TYPE_RAIN              = 2, // RAIN
	WEATHER_TYPE_HEAVY_RAIN        = 4, // HEAVY_RAIN
	WEATHER_TYPE_SNOW              = 8, // SNOW
	WEATHER_TYPE_SANDSTORM         = 16 // SANDSTORM
};

enum WeatherSounds
{
	WEATHER_NOSOUND                = 0,
	WEATHER_RAINLIGHT              = 8533,
	WEATHER_RAINMEDIUM             = 8534,
	WEATHER_RAINHEAVY              = 8535,
	WEATHER_SNOWLIGHT              = 8536,
	WEATHER_SNOWMEDIUM             = 8537,
	WEATHER_SNOWHEAVY              = 8538,
	WEATHER_SANDSTORMLIGHT         = 8556,
	WEATHER_SANDSTORMMEDIUM        = 8557,
	WEATHER_SANDSTORMHEAVY         = 8558
};