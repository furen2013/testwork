#pragma once
#include "TypeDef.h"
// from `creature_template` table

enum ELITE
{
	ELITE_NORMAL = 0,
	ELITE_ELITE,
	ELITE_RAREELITE,
	ELITE_WORLDBOSS,
	ELITE_RARE
};

bool Rand(float chance);
bool Rand(uint32 chance);
bool Rand(int32 chance);

class GossipScript;
#pragma pack(push,1)
struct CreatureInfo
{
	uint32 Id;
	char * Name;
	char * info_str;
// 	uint32 Flags1;
 	uint32 Type;
	uint32 Family;
	uint32 Rank;
// 	uint32 Unknown1;
 	uint32 SpellDataID;
	uint32 Male_DisplayID;
	uint32 Female_DisplayID;
// 	uint32 Male_DisplayID2;
// 	uint32 Female_DisplayID2;
// 	float unkfloat1;
// 	float unkfloat2;
 	uint32  Civilian;
	float  anispeed_walk;
	float  anispeed_run;
	uint32 sound_death;
	uint32 sound_attack1;
	uint32 sound_attack2;
	uint32 sound_stand;
	uint32 sound_run;
// 	uint8  Leader;

	std::string lowercase_name;
	GossipScript * gossip_script;
	uint32 GenerateModelId(uint32 * dest)
	{
// 		/* only M */
// 		if(( Male_DisplayID ) && !Female_DisplayID )
// 		{
// 			*dest = Male_DisplayID;
// 			return 0;
// 		}
// 		/* only F */
// 		if(( Female_DisplayID ) && !Male_DisplayID )
// 		{
// 			*dest = Female_DisplayID;
// 			return 1;
// 		}

		*dest = Male_DisplayID;
		return 0;
	}
};

struct AI_Spell;
struct SpellEntry;
struct CreatureProto
{
	CreatureProto():m_canSpellAttack(false),movable(0),immunecc(0){}
	uint32 Id;
	uint32 MinLevel;
	uint32 MaxLevel;
	uint32 Faction;					//	阵营
	uint32 MinHealth;
	uint32 MaxHealth;
	uint32 Mana;
	float  Scale;
	uint32	NPCFLags;
	uint32 AttackTime;				//	攻击间隔（单位：ms）
	uint32 AttackType;				//  攻击类型
	float MinDamage;
	float MaxDamage;
	//uint32 RangedAttackTime;
	//float RangedMinDamage;
	//float RangedMaxDamage;
	uint32 MountedDisplayID;		//	坐骑外形ID
	uint32 Item1SlotDisplay;		//	装备1外形
	uint32 Item1Info;				//	装备1信息
	uint32 Item1Slot;				//	装备1位置
	uint32 Item2SlotDisplay;
	uint32 Item2Info;
	uint32 Item2Slot;
// 	uint32 Item3SlotDisplay;
// 	uint32 Item3Info;
// 	uint32 Item3Slot;
	uint32 RespawnTime;				//	刷新时间
	uint32 armo;					//	护甲值
	float CombatReach;				//	战斗攻击范围
	float BoundingRadius;			//	警戒范围
// 	char * aura_string;				//	光环
	uint32 boss;					//	是否boss
	uint32 money;					//	掉落铜币
	uint32 invisibility_type;		//	是否可见
	uint32 death_state;				//	死亡动作
	float	walk_speed;//base movement
	float	run_speed;//most of the time mobs use this
	float fly_speed;
	uint32 ride;					//是否可骑乘
	uint32 maxdropitemcnt;			//掉落道具的最大数量
	uint32 movable;					// 是否可移动
	uint32 immunecc;				// 是否免疫控制技能
	char* lua_script;


	/* AI Stuff */
	bool m_canRangedAttack;
	bool m_canFlee;
	float m_fleeHealth;
	uint32 m_fleeDuration;
	bool m_canCallForHelp;
	float m_callForHelpHealth;

	bool m_canSpellAttack;
	SpellEntry* m_defaultAttackSpell;

	set<uint32> start_auras;
	list<AI_Spell*> spells;
};
#pragma pack(pop)


//////////////////////////////////////////////////////////////////////////
//	GO
//////////////////////////////////////////////////////////////////////////

struct Quest;
typedef std::map<Quest*, uint32 > GameObjectGOMap;

typedef std::map<Quest*, std::map<uint32, uint32> > GameObjectItemMap;


#pragma pack(push,1)
struct GameObjectInfo
{
	uint32 ID;
	uint32 Type;
	uint32 DisplayID;
	char * Name;
	uint32 SpellFocus;
	uint32 castspell;
	//uint32 sound1;
// 	uint32 sound6;
// 	uint32 sound7;
// 	uint32 sound8;
// 	uint32 sound9;
	uint32 reqspell;
	uint32 reqquest;
	uint32 reqitem;
	uint32 spawntime;
	uint32 new_obj;
	uint32 mine_min;
	uint32 mine_max;
	uint32 questid;

	// Quests
	GameObjectGOMap goMap;
	GameObjectItemMap itemMap;
	GossipScript * gossip_script;
};
#pragma pack(pop)

enum GAMEOBJECT_TYPES
{
	GAMEOBJECT_TYPE_DOOR			   = 0,
	GAMEOBJECT_TYPE_BUTTON			 = 1,
	GAMEOBJECT_TYPE_QUESTGIVER		 = 2,
	GAMEOBJECT_TYPE_CHEST			  = 3,
	GAMEOBJECT_TYPE_BINDER			 = 4,
	GAMEOBJECT_TYPE_GENERIC			= 5,
	GAMEOBJECT_TYPE_TRAP			   = 6,
	GAMEOBJECT_TYPE_CHAIR			  = 7,
	GAMEOBJECT_TYPE_SPELL_FOCUS		= 8,
	GAMEOBJECT_TYPE_TEXT			   = 9,
	GAMEOBJECT_TYPE_GOOBER			 = 10,
	GAMEOBJECT_TYPE_TRANSPORT		  = 11,
	GAMEOBJECT_TYPE_AREADAMAGE		 = 12,
	GAMEOBJECT_TYPE_CAMERA			 = 13,
	GAMEOBJECT_TYPE_MAP_OBJECT		 = 14,
	GAMEOBJECT_TYPE_MO_TRANSPORT	   = 15,
	GAMEOBJECT_TYPE_DUEL_ARBITER	   = 16,
	GAMEOBJECT_TYPE_FISHINGNODE		= 17,
	GAMEOBJECT_TYPE_RITUAL			 = 18,
	GAMEOBJECT_TYPE_MAILBOX			= 19,
	GAMEOBJECT_TYPE_AUCTIONHOUSE	   = 20,
	GAMEOBJECT_TYPE_GUARDPOST		  = 21,
	GAMEOBJECT_TYPE_SPELLCASTER		= 22,
	GAMEOBJECT_TYPE_MEETINGSTONE	   = 23,
	GAMEOBJECT_TYPE_FLAGSTAND		  = 24,
	GAMEOBJECT_TYPE_FISHINGHOLE		= 25,
	GAMEOBJECT_TYPE_FLAGDROP		   = 26,
	GAMEOBJECT_TYPE_PICK			= 27,
};
