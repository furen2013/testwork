#ifndef __SPELLSTORE_H
#define __SPELLSTORE_H

#include "TypeDef.h"
#include "Timer.h"

#pragma pack(push,1)

struct BankSlotPrice
{
	uint32 Id;
	uint32 Price;
};

struct ItemSetEntry
{
    uint32 id;                  //1
    char* name;                //2
    uint32 flag;                //10 constant
    uint32 itemid[8];           //11 - 18
    uint32 SpellID[8];          //28 - 35
    uint32 itemscount[8];       //36 - 43
    uint32 RequiredSkillID;     //44
    uint32 RequiredSkillAmt;    //45
};

struct Lock
{
    uint32 Id;
    uint32 locktype[5]; // 0 - no lock, 1 - item needed for lock, 2 - min lockping skill needed
    uint32 lockmisc[5]; // if type is 1 here is a item to unlock, else is unknow for now
    uint32 minlockskill[5]; // min skill in lockpiking to unlock.
};

struct emoteentry
{
    uint32 Id;
    //uint32 name;
    uint32 textid;
    uint32 textid2;
    uint32 textid3;
    uint32 textid4;
    uint32 textid5;
    uint32 textid6;
};

struct skilllinespell //SkillLineAbility.dbc
{
    uint32 Id;
    uint32 skilline;
    uint32 spell;
    uint32 next;
    uint32 minrank;
    uint32 grey;
    uint32 green;
    uint32 reqTP;
};

struct EnchantEntry
{
    uint32 Id;
    uint32 type[3];
    int32 min[3];//for compat, in practice min==max
    int32 max[3];
    uint32 spell[3];
    char* Name;
    uint32 visual;
    uint32 EnchantGroups;
    uint32 GemEntry;
	uint32 ProcChance;
};

struct GemPropertyEntry{
    uint32 Entry;
    uint32 EnchantmentID;
    uint32 SocketMask;
};

struct skilllineentry //SkillLine.dbc
{
    uint32 id;
    uint32 type;
    char* Name;
};

// Struct for the entry in Spell.dbc
struct SpellEntry
{
	SpellEntry(){memset(this, 0, sizeof( *this ) ); ThreatForSpell = 1; is_melee_spell = false; is_ranged_spell = false; in_front_status = 1;}
	uint32 Id;                              //1
	uint32 Category;                        //2������ϵ����(�����˺���ʥ�˺�)
// 	uint32 field4;                          //3 something like spelltype 0: general spells 1: Pet spells 2: Disguise / transormation spells 3: enchantment spells
	uint32 DispelType;                      //4ħ����ħ������ID
	uint32 MechanicsType;                   //5ħ��MechanicID�������õĴ���
	uint32 Attributes;                      //6
	uint32 AttributesEx;                    //7
	uint32 Flags3;                          //8
	uint32 Flags4;                          //9 // Flags to
	uint32 buffType;                          //10 // Flags....
// 	uint32 unk201_1;                        //11 // Flags 2.0.1 unknown one
// 	uint32 unk240_1;						//12
	uint32 RequiredShapeShift;              //13 // Flags BitMask for shapeshift spells
// 	uint32 UNK14;                           //14-> this is wrong // Flags BitMask for which shapeshift forms this spell can NOT be used in.
	uint32 Targets;                         //15 - N / MĿ��(����������������)
	uint32 TargetCreatureType;              //16Ŀ������(�������������)
	uint32 RequiresSpellFocus;              //17��Ҫ���ض���gameobj����ʩ��(����ѧ����Ҫ����)
// 	uint32 unk240_2;						//18
	uint32 CasterAuraState;                 //19ʩ���߹⻷����
	uint32 TargetAuraState;                 //20Ŀ��⻷����
// 	uint32 unk201_2;                        //21 2.0.1 unknown two
// 	uint32 unk201_3;                        //22 2.0.1 unknown three
	uint32 CastingTimeIndex;                //23
	uint32 RecoveryTime;                    //24ʩ��ʱ��1Ϊ˲��19
	uint32 CategoryRecoveryTime;            //25 recoverytime������ȴʱ��
	uint32 InterruptFlags;                  //26��ϵı��
	uint32 AuraInterruptFlags;              //27�⻷��ϵı��
	uint32 ChannelInterruptFlags;           //28������ϵı��
	uint32 procFlags;                       //29
	uint32 procChance;                      //30
	int32 procCharges;                      //31
	uint32 maxLevel;                        //32���ȼ�
	uint32 baseLevel;                       //33�����ȼ�ѧϰ�˼�����Ҫ�ĵȼ�
	uint32 spellLevel;                      //34ħ���ȼ�
	uint32 DurationIndex;                   //35ħ������ʱ��
	uint32 powerType;                       //36��������
	uint32 manaCost;                        //37����ħ��ֵ
	uint32 manaCostPerlevel;                //38ÿ������ħ��ֵ
	uint32 manaPerSecond;                   //39ÿ������ħ��ֵ
	uint32 manaPerSecondPerLevel;           //40ÿ��ÿ������ħ��ֵ
	uint32 rangeIndex;                      //41ʩ����������
	float  speed;                           //42�ٶ�
	uint32 modalNextSpell;                  //43
	uint32 maxstack;                        //44
	uint32 Totem[2];                        //45 - 46ʩ����Ҫ����Ʒ(ʩ������ʧ)��ͼ�ڸ�ħ�����ֵ�
	uint32 Reagent[8];                      //47 - 54ʩ����Ʒ(ʩ������Ʒ��ʧ)
	uint32 ReagentCount[8];                 //55 - 62ʩ����Ʒ��Ҫ�ĸ���
	int32 EquippedItemClass;               //63��ħװ���ķ���ֵ
	uint32 EquippedItemSubClass;            //64��ħװ�����ӷ���ֵ(subclass)(�����Ǹ�ħ�Ĵ��븽����ʲôħ)
	uint32 RequiredItemFlags;               //65
	uint32 Effect[3];                       //66 - 68ħ��Ч��1
	uint32 EffectDieSides[3];               //69 - 71ħ��Ч��ֵ���ӵ����ֵ(����������)
	uint32 EffectBaseDice[3];               //72 - 74ħ������Ч��ֵ(�˺������ʵ�)
	float  EffectDicePerLevel[3];           //75 - 77
	float  EffectRealPointsPerLevel[3];     //78 - 80ÿ����ʵЧ������
	int32  EffectBasePoints[3];             //81 - 83
	int32  EffectMechanic[3];               //84 - 86       Related to SpellMechanic.dbc
	uint32 EffectImplicitTargetA[3];        //87 - 89Ч�����е�Ŀ��A
	uint32 EffectImplicitTargetB[3];        //90 - 92
	uint32 EffectRadiusIndex[3];            //93 - 95ħ����Ч��������
	uint32 EffectApplyAuraName[3];          //96 - 98Ч��Ӧ�õĹ⻷��
	uint32 EffectAmplitude[3];              //99 - 101�������˺���ʱ����
	float  Effectunknown[3];                //102 - 104     This value is the $ value from description
	uint32 EffectChainTarget[3];            //105 - 107Ч������Ŀ��
	uint32 EffectSpellGroupRelation[3];     //108 - 110     Not sure maybe we should rename it. its the relation to field: SpellGroupType
	uint32 EffectMiscValue[3];              //111 - 113
	uint32 EffectTriggerSpell[3];           //114 - 116���ͼ���Ч��
	float  EffectPointsPerComboPoint[3];    //117 - 117ÿcombo���Ч������(��������������)
	uint32 SpellVisual;                     //120����visual(�Ӿ�
	uint32 field114;                        //121
	uint32 dummy;                           //122
	uint32 CoSpell;                         //123   activeIconID;
	uint32 spellPriority;                   //124��������Ȩ
	char* Name;                             //125
	//uint32 NameAlt1;                        //126
	//uint32 NameAlt2;                        //127
	//uint32 NameAlt3;                        //128
	//uint32 NameAlt4;                        //129
	//uint32 NameAlt5;                        //130
	//uint32 NameAlt6;                        //131
	//uint32 NameAlt7;                        //132
	//uint32 NameAlt8;                        //133
	//uint32 NameAlt9;                        //134
	//uint32 NameAlt10;                       //135
	//uint32 NameAlt11;                       //136
	//uint32 NameAlt12;                       //137
	//uint32 NameAlt13;                       //138
	//uint32 NameAlt14;                       //139
	//uint32 NameAlt15;                       //140
	//uint32 NameFlags;                       //141
	char * Rank;                            //142ħ������
	//uint32 RankAlt1;                        //143
	//uint32 RankAlt2;                        //144
	//uint32 RankAlt3;                        //145
	//uint32 RankAlt4;                        //146
	//uint32 RankAlt5;                        //147
	//uint32 RankAlt6;                        //148
	//uint32 RankAlt7;                        //149
	//uint32 RankAlt8;                        //150
	//uint32 RankAlt9;                        //151
	//uint32 RankAlt10;                       //152
	//uint32 RankAlt11;                       //153
	//uint32 RankAlt12;                       //154
	//uint32 RankAlt13;                       //155
	//uint32 RankAlt14;                       //156
	//uint32 RankAlt15;                       //157
	//uint32 RankFlags;                       //158
	char * Description;                     //159
	//uint32 DescriptionAlt1;                 //160
	//uint32 DescriptionAlt2;                 //161
	//uint32 DescriptionAlt3;                 //162
	//uint32 DescriptionAlt4;                 //163
	//uint32 DescriptionAlt5;                 //164
	//uint32 DescriptionAlt6;                 //165
	//uint32 DescriptionAlt7;                 //166
	//uint32 DescriptionAlt8;                 //167
	//uint32 DescriptionAlt9;                 //168
	//uint32 DescriptionAlt10;                //169
	//uint32 DescriptionAlt11;                //170
	//uint32 DescriptionAlt12;                //171
	//uint32 DescriptionAlt13;                //172
	//uint32 DescriptionAlt14;                //173
	//uint32 DescriptionAlt15;                //174
	//uint32 DescriptionFlags;                //175
	char * BuffDescription;                 //176
	//uint32 BuffDescriptionAlt1;             //177
	//uint32 BuffDescriptionAlt2;             //178
	//uint32 BuffDescriptionAlt3;             //179
	//uint32 BuffDescriptionAlt4;             //180
	//uint32 BuffDescriptionAlt5;             //181
	//uint32 BuffDescriptionAlt6;             //182
	//uint32 BuffDescriptionAlt7;             //183
	//uint32 BuffDescriptionAlt8;             //184
	//uint32 BuffDescriptionAlt9;             //185
	//uint32 BuffDescriptionAlt10;            //186
	//uint32 BuffDescriptionAlt11;            //187
	//uint32 BuffDescriptionAlt12;            //188
	//uint32 BuffDescriptionAlt13;            //189
	//uint32 BuffDescriptionAlt14;            //190
	//uint32 BuffDescriptionAlt15;            //191
	//uint32 buffdescflags;                   //192
	uint32 ManaCostPercentage;              //193����ħ���ٷֱ�%
// 	uint32 unkflags;                        //194 
	uint32 StartRecoveryTime;               //195��ʼ�ָ���ȴʱ������
	uint32 StartRecoveryCategory;           //196��ʼ�ָ���ȴ��ʱ��
	uint32 SpellFamilyName;                 //197
	uint32 SpellGroupType;					//198+199
	uint32 MaxTargets;                      //200 
 	uint32 Spell_Dmg_Type;                  //201   dmg_class Integer      0=None, 1=Magic, 2=Melee, 3=Ranged
// 	uint32 FG;                              //202   0,1,2 related to Spell_Dmg_Type I think
// 	int32 FH;                               //203   related to paladin aura's 
	float dmg_multiplier[3];                //204 - 206   if the name is correct I dono
// 	uint32 FL;                              //207   only one spellid:6994 has this value = 369 UNUSED
// 	uint32 FM;                              //208   only one spellid:6994 has this value = 4 UNUSED
// 	uint32 FN;                              //209  3 spells 1 or 2   
	uint32 TotemCategory[2];				//210-211
	uint32 RequiresAreaId;				     		//212 
	uint32 School;						// 213

	int32 weaponMask;

	uint32 classmask_foreditor;
	uint32 always_apply;
	char* icon;			// for client
	float Attach1;
	uint32 Attach2;
	uint32 Attach3;
	uint32 Attach4;
	uint32 Attach5;

    /// CUSTOM: these fields are used for the modifications made in the world.cpp
	uint32 diejia;
    uint32 DiminishStatus;                  //
    uint32 proc_interval;                   //!!! CUSTOM, <Fill description for variable>
    uint32 buffIndexType;					//!!! CUSTOM, <Fill description for variable>
    uint32 c_is_flags;						//!!! CUSTOM, store spell checks in a static way : isdamageind,ishealing
    //uint32 buffType;                        //!!! CUSTOM, these are related to creating a item through a spell
    uint32 RankNumber;                      //!!! CUSTOM, this protects players from having >1 rank of a spell
    uint32 NameHash;                        //!!! CUSTOM, related to custom spells, summon spell quest related spells
    float base_range_or_radius_sqr;         //!!! CUSTOM, needed for aoe spells most of the time
	uint32 talent_tree;						//!!! CUSTOM,
	uint32 in_front_status;					//!!! CUSTOM,
	bool is_melee_spell;					//!!! CUSTOM,
	bool is_ranged_spell;					//!!! CUSTOM,
	bool spell_can_crit;					//!!! CUSTOM,
    uint32 EffectSpellGroupRelation_high[3];     //!!! this is not contained in client dbc but server must have it
	uint32 ThreatForSpell;

	uint32 ProcOnNameHash[3];

	// love me or hate me, all "In a cone in front of the caster" spells don't necessarily mean "in front"
	float cone_width;
	//Spell Coefficient
	float casttime_coef;                                    //!!! CUSTOM, faster spell bonus calculation
	uint32 spell_coef_flags;                                //!!! CUSTOM, store flags for spell coefficient calculations
	float fixed_dddhcoef;                                   //!!! CUSTOM, fixed DD-DH coefficient for some spells
	float fixed_hotdotcoef;                                 //!!! CUSTOM, fixed HOT-DOT coefficient for some spells
	float Dspell_coef_override;                             //!!! CUSTOM, overrides any spell coefficient calculation and use this value in DD&DH
	float OTspell_coef_override;							//!!! CUSTOM, overrides any spell coefficient calculation and use this value in HOT&DOT

	bool self_cast_only;
	bool apply_on_shapeshift_change;
};

struct ItemExtendedCostEntry
{
    uint32 costid;
    uint32 honor;
    uint32 arena;
    uint32 item[5];
    uint32 count[5];
	uint32 gold;
	uint32 yuanbao;
	uint32 guild_score;
	uint32 guild_contribute;
};

struct TalentEntry
{
    uint32  TalentID;
    uint32  TalentTree;
    uint32  Row;
    uint32  Col;
    uint32  RankID[5];
    uint32  DependsOn;
    uint32  DependsOnRank;
};

struct TalentTabEntry
{
    uint32	TalentTabID;
    uint32	ClassMask;
    uint32	TabPage;
};

struct Trainerspell
{
    uint32 Id;
    uint32 skilline1;
    uint32 skilline2;
    uint32 skilline3;
    uint32 maxlvl;
    uint32 charclass;
};

struct SpellCastTime
{
    uint32 ID;
    uint32 CastTime;
};

struct SpellRadius
{
    uint32 ID;
    float Radius;
    float Radius2;
};

struct SpellRange
{
    uint32 ID;
    float minRange;
    float maxRange;
};

struct SpellDuration
{
    uint32 ID;
    uint32 Duration1;
    uint32 Duration2;
    uint32 Duration3;
};

struct RandomProps
{
    uint32 ID;
    uint32 spells[3];
};

struct AreaTable
{
    uint32 AreaId;
    uint32 mapId;
    uint32 ZoneId;
    uint32 explorationFlag;
    uint32 AreaFlags;
    uint32 EXP;//not XP
    uint32 level;
    char* name;
    uint32 category;
};

struct FactionTemplateDBC
{
    uint32 ID;
    uint32 Faction;
    uint32 FactionGroup;
    uint32 Mask;
    uint32 FriendlyMask;
    uint32 HostileMask;
    uint32 EnemyFactions[4];
    uint32 FriendlyFactions[4];
};

struct AuctionHouseDBC
{
    uint32 id;
    uint32 fee;
    uint32 tax;   
};

struct FactionDBC
{
    uint32 ID;
    int32 RepListId;
    uint32 baseRepMask[4];
    //int32 baseRepValue[4];
    uint32 parentFaction;
    char* Name;
};

struct DBCTaxiNode
{
    uint32 id;
    uint32 mapid;
    float x;
    float y;
    float z;
    uint32 horde_mount;
    uint32 alliance_mount;
};

struct DBCTaxiPath
{
    uint32 id;
    uint32 from;
    uint32 to;
    uint32 price;
};

struct DBCTaxiPathNode
{
    uint32 id;
    uint32 path;
    uint32 seq;
    uint32 mapid;
    float x;
    float y;
    float z;
    uint32 waittime;
};

struct CreatureSpellDataEntry
{
    uint32 id;
    uint32 Spells[3];
    uint32 PHSpell;
    uint32 Cooldowns[3];
    uint32 PH;
};

struct CharRaceEntry
{
	uint32 race_id;
	uint32 team_id;
	uint32 cinematic_id;
	char* name1;
};

struct CharClassEntry
{
    uint32 class_id;
    uint32 power_type;
    char* name;
};

struct CreatureFamilyEntry
{
    uint32 ID;
    float minsize;
    uint32 minlevel;
    float maxsize;
    uint32 maxlevel;
    uint32 skilline;
    uint32 tameable;		//second skill line - 270 Generic
    uint32 petdietflags;
    char* name;   
};

struct MapEntry
{
    uint32 id;
    char* name_internal;
    uint32 map_type;
    char* real_name;  
};

struct ItemRandomSuffixEntry
{
	uint32 id;
	uint32 enchantments[3];
	uint32 prefixes[3];
};

struct gtFloat
{
	uint32 id;
	float val;
};

struct CombatRatingDBC
{
	uint32 id;
	float val;
};

struct ChatChannelDBC
{
	uint32 id;
	uint32 flags;
};

struct DurabilityQualityEntry
{
    uint32 id;
    float quality_modifier;
};

struct DurabilityCostsEntry
{
    uint32 itemlevel;
    uint32 modifier[29];
};

struct stConsume2GiftEntry
{
	uint32 id;
	uint32 item[5];
	uint32 itemcount[5];
};

struct NameGenData
{
	char* name;
	uint32 type;
};

struct LfgDungeonType
{
	uint32 id;
	uint32 type;
};

struct QuestTips
{
	uint32 id;
	uint32 type;
	uint32 racemask;
	uint32 classmask;
	uint32 level;
	char* text;
};

struct stSystemNotify
{
	uint32 id;
	uint32 ntype;
	char* tips;
};

struct stDefaultAddItem
{
	uint32 id;
	uint32 entry[14];
};

struct MapSpawnPos
{
	uint32 id;
	uint32 race;
	uint32 mapid;
	float x,y,z;
};
struct Idle_Gift
{
	uint32 id;
	uint32 level;
	uint32 type;
	uint32 miscvalue1;
	uint32 miscvalue2;
};

struct Playtime_Trigger
{
	uint32 id;
	uint32 play_time_min;
	uint32 play_time_max;
	uint32 type1;
	uint32 miscvalue1_1;
	uint32 miscvalue1_2;
	uint32 type2;
	uint32 miscvalue2_1;
	uint32 miscvalue2_2;
	uint32 type3;
	uint32 miscvalue3_1;
	uint32 miscvalue3_2;
	uint32 waittime;
};

struct stPlayerTitle
{
	uint32 id;
	char* title;
	uint32 title_property;
};

struct stNpcTransPos
{
	uint32 id;
	uint32 type;
	uint32 mapid;
	float x,y,z,o;
};

struct stNpcScriptTrans
{
	uint32 index;
	uint32 npc_entry;
	char* name;
	uint32 transpos_id;
};

#pragma pack(pop)

inline float GetRadius(SpellRadius *radius)
{
	return radius ? radius->Radius : 0.0f;
}
inline uint32 GetCastTime(SpellCastTime *time)
{
	return time ? time->CastTime : 0;
}
inline float GetMaxRange(SpellRange *range)
{
	return range ? range->maxRange : 0.0f;
}
inline float GetMinRange(SpellRange *range)
{
	return range ? range->minRange : 0.0f;
}
inline uint32 GetDuration(SpellDuration *dur)
{
	return dur ? dur->Duration1 : 0;
}

#define SAFE_DBC_CODE_RETURNS			/* undefine this to make out of range/nulls return null. */

#endif
