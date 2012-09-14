#ifndef _SPELLDEF_H
#define _SPELLDEF_H
#include "../Public/TypeDef.h"
#include "../Protocol/PacketDef.h"

#define MAX_AURAS 56 // 40 buff slots, 16 debuff slots.
#define MAX_POSITIVE_AURAS 40 // ?
#define MAX_PASSIVE_AURAS 192   // grep: i mananged to break this.. :p seems we need more

#define XP_TRIGGER_SPELL 2
#define XP_TRIGGER_BAR_MAX 100
enum
{
	ActionButton_Type_MACRO = 64,
	ActionButton_Type_Item  = 128,
	ActionButton_Type_Spell = 0,
};


enum CastInterruptFlags
{
	CAST_INTERRUPT_NULL            = 0x0,
	CAST_INTERRUPT_ON_SILENCE      = 0x1,
	CAST_INTERRUPT_ON_SLEEP        = 0x2, // could be wrong
	CAST_INTERRUPT_ON_STUNNED      = 0x4, // could be wrong
	CAST_INTERRUPT_ON_MOVEMENT     = 0x8,
	CAST_INTERRUPT_ON_DAMAGE_TAKEN = 0x10
};

enum ChannelInterruptFlags
{
	CHANNEL_INTERRUPT_NULL  = 0x0,
	CHANNEL_INTERRUPT_ON_1  = 0x1,
	CHANNEL_INTERRUPT_ON_2  = 0x2,
	CHANNEL_INTERRUPT_ON_3  = 0x4,
	CHANNEL_INTERRUPT_ON_4  = 0x8,
	CHANNEL_INTERRUPT_ON_5  = 0x10,
	CHANNEL_INTERRUPT_ON_6  = 0x20,
	CHANNEL_INTERRUPT_ON_7  = 0x40,
	CHANNEL_INTERRUPT_ON_8  = 0x80,
	CHANNEL_INTERRUPT_ON_9  = 0x100,
	CHANNEL_INTERRUPT_ON_10 = 0x200,
	CHANNEL_INTERRUPT_ON_11 = 0x400,
	CHANNEL_INTERRUPT_ON_12 = 0x800,
	CHANNEL_INTERRUPT_ON_13 = 0x1000,
	CHANNEL_INTERRUPT_ON_14 = 0x2000,
	CHANNEL_INTERRUPT_ON_15 = 0x4000,
	CHANNEL_INTERRUPT_ON_16 = 0x8000,
	CHANNEL_INTERRUPT_ON_17 = 0x10000,
	CHANNEL_INTERRUPT_ON_18 = 0x20000
};

enum AuraInterruptFlags
{
	AURA_INTERRUPT_NULL                       = 0x0,
	AURA_INTERRUPT_ON_HOSTILE_SPELL_INFLICTED = 0x1,
	AURA_INTERRUPT_ON_ANY_DAMAGE_TAKEN        = 0x2,
	AURA_INTERRUPT_ON_UNK1                    = 0x4,
	AURA_INTERRUPT_ON_MOVEMENT                = 0x8, // could be AURA_INTERRUPT_ON_MOVEMENT
	AURA_INTERRUPT_ON_UNK2                    = 0x10,
	AURA_INTERRUPT_ON_UNK3                    = 0x20,
	AURA_INTERRUPT_ON_UNUSED1                 = 0x40,
	AURA_INTERRUPT_ON_SLOWED                  = 0x80,
	AURA_INTERRUPT_ON_LEAVE_WATER             = 0x100, // could be AURA_INTERRUPT_ON_LEAVE_CURRENT_SURFACE
	AURA_INTERRUPT_ON_UNUSED2                 = 0x200,
	AURA_INTERRUPT_ON_UNK4                    = 0x400,
	AURA_INTERRUPT_ON_UNK5                    = 0x800,
	AURA_INTERRUPT_ON_START_ATTACK            = 0x1000,
	AURA_INTERRUPT_ON_UNK6                    = 0x2000,
	AURA_INTERRUPT_ON_UNUSED3                 = 0x4000,
	AURA_INTERRUPT_ON_CAST_SPELL              = 0x8000,
	AURA_INTERRUPT_ON_UNK7                    = 0x10000,
	AURA_INTERRUPT_ON_MOUNT                   = 0x20000,
	AURA_INTERRUPT_ON_STAND_UP                = 0x40000,
	AURA_INTERRUPT_ON_LEAVE_AREA              = 0x80000,
	AURA_INTERRUPT_ON_INVINCIBLE              = 0x100000,
	AURA_INTERRUPT_ON_STEALTH                 = 0x200000,
	AURA_INTERRUPT_ON_UNK8                    = 0x400000,
};
//! 4-bit flag
enum AURA_FLAGS
{
	AFLAG_EMPTY = 0x0,
	AFLAG_SET = 0x9
};

enum AUARA_STAE_FLAGS
{
	AURASTATE_FLAG_DODGE_BLOCK			= 1,        //1
	AURASTATE_FLAG_HEALTH20             = 2,        //2
	AURASTATE_FLAG_BERSERK              = 4,        //3
	AURASTATE_FLAG_JUDGEMENT            = 16,       //5
	AURASTATE_FLAG_PARRY                = 64,       //7
	AURASTATE_FLAG_LASTKILLWITHHONOR    = 512,      //10
	AURASTATE_FLAG_CRITICAL             = 1024,     //11
	AURASTATE_FLAG_HEALTH35             = 4096,     //13
	AURASTATE_FLAG_IMMOLATE             = 8192,     //14
	AURASTATE_FLAG_REJUVENATE           = 16384,    //15 //where do i use this ?
	AURASTATE_FLAG_POISON               = 32768,    //16
};

enum SpellCastTargetFlags
{
	TARGET_FLAG_SELF                = 0x0001, // they are checked in following order
	TARGET_FLAG_UNK1                = 0x0000,
	TARGET_FLAG_UNIT                = 0x0002,
	TARGET_FLAG_UNK2                = 0x0004,
	TARGET_FLAG_UNK3                = 0x0008,
	TARGET_FLAG_ITEM                = 0x0010,
	TARGET_FLAG_SOURCE_LOCATION     = 0x0020,
	TARGET_FLAG_DEST_LOCATION       = 0x0040,
	TARGET_FLAG_UNK6                = 0x0080,
	TARGET_FLAG_UNK7                = 0x0100,
	TARGET_FLAG_CORPSE              = 0x0200,
	TARGET_FLAG_UNK8                = 0x0400,
	TARGET_FLAG_OBJECT              = 0x0800,
	TARGET_FLAG_TRADE_ITEM          = 0x1000,
	TARGET_FLAG_STRING              = 0x2000,
	TARGET_FLAG_UNK9                = 0x4000,
	TARGET_FLAG_CORPSE2             = 0x8000
};

enum DISPEL_TYPE
{
    DISPEL_ZGTRINKETS = -1,
    DISPEL_NULL,
    DISPEL_MAGIC,
    DISPEL_CURSE,
    DISPEL_DISEASE,
    DISPEL_POISON,
    DISPEL_STEALTH,
    DISPEL_INVISIBILTY,
    DISPEL_ALL,
    DISPEL_SPECIAL_NPCONLY,
    DISPEL_FRENZY,
	DISPEL_CONTROL,

	DISPEL_MAX,
};

enum DISPEL_MECHANIC_TYPE
{
    DISPEL_MECHANIC_CHARM       = 1,
    DISPEL_MECHANIC_FEAR        = 5,
    DISPEL_MECHANIC_ROOT        = 7,
    DISPEL_MECHANIC_SLEEP       = 10,
    DISPEL_MECHANIC_SNARE       = 11,
    DISPEL_MECHANIC_STUN        = 12,
    DISPEL_MECHANIC_KNOCKOUT    = 14,
    DISPEL_MECHANIC_BLEED       = 15,
    DISPEL_MECHANIC_POLYMORPH   = 17,
    DISPEL_MECHANIC_BANISH      = 18,
    DISPEL_MECHANIC_MOUNTED     = 21,

	DISPEL_MECHANIC_MAX,
};

enum SpellCastError
{
	SPELL_FAILED_AFFECTING_COMBAT                                = 0,
	SPELL_FAILED_ALREADY_AT_FULL_HEALTH                          = 1,
	SPELL_FAILED_ALREADY_AT_FULL_MANA                            = 2,
	SPELL_FAILED_ALREADY_AT_FULL_POWER                           = 3,
	SPELL_FAILED_ALREADY_BEING_TAMED                             = 4,
	SPELL_FAILED_ALREADY_HAVE_CHARM                              = 5,
	SPELL_FAILED_ALREADY_HAVE_SUMMON                             = 6,
	SPELL_FAILED_ALREADY_OPEN                                    = 7,
	SPELL_FAILED_AURA_BOUNCED                                    = 8,
	SPELL_FAILED_AUTOTRACK_INTERRUPTED                           = 9,
	SPELL_FAILED_BAD_IMPLICIT_TARGETS                            = 10,
	SPELL_FAILED_BAD_TARGETS                                     = 11,
	SPELL_FAILED_CANT_BE_CHARMED                                 = 12,
	SPELL_FAILED_CANT_BE_DISENCHANTED                            = 13,
	SPELL_FAILED_CANT_BE_DISENCHANTED_SKILL                      = 14,
	SPELL_FAILED_CANT_BE_PROSPECTED                              = 15,
	SPELL_FAILED_CANT_CAST_ON_TAPPED                             = 16,
	SPELL_FAILED_CANT_DUEL_WHILE_INVISIBLE                       = 17,
	SPELL_FAILED_CANT_DUEL_WHILE_STEALTHED                       = 18,
	SPELL_FAILED_CANT_STEALTH                                    = 19,
	SPELL_FAILED_CASTER_AURASTATE                                = 20,
	SPELL_FAILED_CASTER_DEAD                                     = 21,
	SPELL_FAILED_CHARMED                                         = 22,
	SPELL_FAILED_CHEST_IN_USE                                    = 23,
	SPELL_FAILED_CONFUSED                                        = 24,
	SPELL_FAILED_DONT_REPORT                                     = 25,
	SPELL_FAILED_EQUIPPED_ITEM                                   = 26,
	SPELL_FAILED_EQUIPPED_ITEM_CLASS                             = 27,
	SPELL_FAILED_EQUIPPED_ITEM_CLASS_MAINHAND                    = 28,
	SPELL_FAILED_EQUIPPED_ITEM_CLASS_OFFHAND                     = 29,
	SPELL_FAILED_ERROR                                           = 30,
	SPELL_FAILED_FIZZLE                                          = 31,
	SPELL_FAILED_FLEEING                                         = 32,
	SPELL_FAILED_FOOD_LOWLEVEL                                   = 33,
	SPELL_FAILED_HIGHLEVEL                                       = 34,
	SPELL_FAILED_HUNGER_SATIATED                                 = 35,
	SPELL_FAILED_IMMUNE                                          = 36,
	SPELL_FAILED_INTERRUPTED                                     = 37,
	SPELL_FAILED_INTERRUPTED_COMBAT                              = 38,
	SPELL_FAILED_ITEM_ALREADY_ENCHANTED                          = 39,
	SPELL_FAILED_ITEM_GONE                                       = 40,
	SPELL_FAILED_ITEM_NOT_FOUND                                  = 41,
	SPELL_FAILED_ITEM_NOT_READY                                  = 42,
	SPELL_FAILED_LEVEL_REQUIREMENT                               = 43,
	SPELL_FAILED_LINE_OF_SIGHT                                   = 44,
	SPELL_FAILED_LOWLEVEL                                        = 45,
	SPELL_FAILED_LOW_CASTLEVEL                                   = 46,
	SPELL_FAILED_MAINHAND_EMPTY                                  = 47,
	SPELL_FAILED_MOVING                                          = 48,
	SPELL_FAILED_NEED_AMMO                                       = 49,
	SPELL_FAILED_NEED_AMMO_POUCH                                 = 50,
	SPELL_FAILED_NEED_EXOTIC_AMMO                                = 51,
	SPELL_FAILED_NOPATH                                          = 52,
	SPELL_FAILED_NOT_BEHIND                                      = 53,
	SPELL_FAILED_NOT_FISHABLE                                    = 54,
	SPELL_FAILED_NOT_FLYING                                      = 55,
	SPELL_FAILED_NOT_HERE                                        = 56,
	SPELL_FAILED_NOT_INFRONT                                     = 57,
	SPELL_FAILED_NOT_IN_CONTROL                                  = 58,
	SPELL_FAILED_NOT_KNOWN                                       = 59,
	SPELL_FAILED_NOT_MOUNTED                                     = 60,
	SPELL_FAILED_NOT_ON_TAXI                                     = 61,
	SPELL_FAILED_NOT_ON_TRANSPORT                                = 62,
	SPELL_FAILED_NOT_READY                                       = 63,
	SPELL_FAILED_NOT_SHAPESHIFT                                  = 64,
	SPELL_FAILED_NOT_STANDING                                    = 65,
	SPELL_FAILED_NOT_TRADEABLE                                   = 66,
	SPELL_FAILED_NOT_TRADING                                     = 67,
	SPELL_FAILED_NOT_UNSHEATHED                                  = 68,
	SPELL_FAILED_NOT_WHILE_GHOST                                 = 69,
	SPELL_FAILED_NO_AMMO                                         = 70,
	SPELL_FAILED_NO_CHARGES_REMAIN                               = 71,
	SPELL_FAILED_NO_CHAMPION                                     = 72,
	SPELL_FAILED_NO_COMBO_POINTS                                 = 73,
	SPELL_FAILED_NO_DUELING                                      = 74,
	SPELL_FAILED_NO_ENDURANCE                                    = 75,
	SPELL_FAILED_NO_FISH                                         = 76,
	SPELL_FAILED_NO_ITEMS_WHILE_SHAPESHIFTED                     = 77,
	SPELL_FAILED_NO_MOUNTS_ALLOWED                               = 78,
	SPELL_FAILED_NO_PET                                          = 79,
	SPELL_FAILED_NO_POWER                                        = 80,
	SPELL_FAILED_NOTHING_TO_DISPEL                               = 81,
	SPELL_FAILED_NOTHING_TO_STEAL                                = 82,
	SPELL_FAILED_ONLY_ABOVEWATER                                 = 83,
	SPELL_FAILED_ONLY_DAYTIME                                    = 84,
	SPELL_FAILED_ONLY_INDOORS                                    = 85,
	SPELL_FAILED_ONLY_MOUNTED                                    = 86,
	SPELL_FAILED_ONLY_NIGHTTIME                                  = 87,
	SPELL_FAILED_ONLY_OUTDOORS                                   = 88,
	SPELL_FAILED_ONLY_SHAPESHIFT                                 = 89,
	SPELL_FAILED_ONLY_STEALTHED                                  = 90,
	SPELL_FAILED_ONLY_UNDERWATER                                 = 91,
	SPELL_FAILED_OUT_OF_RANGE                                    = 92,
	SPELL_FAILED_PACIFIED                                        = 93,
	SPELL_FAILED_POSSESSED                                       = 94,
	SPELL_FAILED_REAGENTS                                        = 95,
	SPELL_FAILED_REQUIRES_AREA                                   = 96,
	SPELL_FAILED_REQUIRES_SPELL_FOCUS                            = 97,
	SPELL_FAILED_ROOTED                                          = 98,
	SPELL_FAILED_SILENCED                                        = 99,
	SPELL_FAILED_SPELL_IN_PROGRESS                               = 100,
	SPELL_FAILED_SPELL_LEARNED                                   = 101,
	SPELL_FAILED_SPELL_UNAVAILABLE                               = 102,
	SPELL_FAILED_STUNNED                                         = 103,
	SPELL_FAILED_TARGETS_DEAD                                    = 104,
	SPELL_FAILED_TARGET_AFFECTING_COMBAT                         = 105,
	SPELL_FAILED_TARGET_AURASTATE                                = 106,
	SPELL_FAILED_TARGET_DUELING                                  = 107,
	SPELL_FAILED_TARGET_ENEMY                                    = 108,
	SPELL_FAILED_TARGET_ENRAGED                                  = 109,
	SPELL_FAILED_TARGET_FRIENDLY                                 = 110,
	SPELL_FAILED_TARGET_IN_COMBAT                                = 111,
	SPELL_FAILED_TARGET_IS_PLAYER                                = 112,
	SPELL_FAILED_TARGET_IS_PLAYER_CONTROLLED                     = 113,
	SPELL_FAILED_TARGET_NOT_DEAD                                 = 114,
	SPELL_FAILED_TARGET_NOT_IN_PARTY                             = 115,
	SPELL_FAILED_TARGET_NOT_LOOTED                               = 116,
	SPELL_FAILED_TARGET_NOT_PLAYER                               = 117,
	SPELL_FAILED_TARGET_NO_POCKETS                               = 118,
	SPELL_FAILED_TARGET_NO_WEAPONS                               = 119,
	SPELL_FAILED_TARGET_UNSKINNABLE                              = 120,
	SPELL_FAILED_THIRST_SATIATED                                 = 121,
	SPELL_FAILED_TOO_CLOSE                                       = 122,
	SPELL_FAILED_TOO_MANY_OF_ITEM                                = 123,
	SPELL_FAILED_TOTEM_CATEGORY                                  = 124,
	SPELL_FAILED_TOTEMS                                          = 125,
	SPELL_FAILED_TRAINING_POINTS                                 = 126,
	SPELL_FAILED_TRY_AGAIN                                       = 127,
	SPELL_FAILED_UNIT_NOT_BEHIND                                 = 128,
	SPELL_FAILED_UNIT_NOT_INFRONT                                = 129,
	SPELL_FAILED_WRONG_PET_FOOD                                  = 130,
	SPELL_FAILED_NOT_WHILE_FATIGUED                              = 131,
	SPELL_FAILED_TARGET_NOT_IN_INSTANCE                          = 132,
	SPELL_FAILED_NOT_WHILE_TRADING                               = 133,
	SPELL_FAILED_TARGET_NOT_IN_RAID                              = 134,
	SPELL_FAILED_DISENCHANT_WHILE_LOOTING                        = 135,
	SPELL_FAILED_PROSPECT_WHILE_LOOTING                          = 136,
	SPELL_FAILED_PROSPECT_NEED_MORE                              = 137,
	SPELL_FAILED_TARGET_FREEFORALL                               = 138,
	SPELL_FAILED_NO_EDIBLE_CORPSES                               = 139,
	SPELL_FAILED_ONLY_BATTLEGROUNDS                              = 140,
	SPELL_FAILED_TARGET_NOT_GHOST                                = 141,
	SPELL_FAILED_TOO_MANY_SKILLS                                 = 142,
	SPELL_FAILED_TRANSFORM_UNUSABLE                              = 143,
	SPELL_FAILED_WRONG_WEATHER                                   = 144,
	SPELL_FAILED_DAMAGE_IMMUNE                                   = 145,
	SPELL_FAILED_PREVENTED_BY_MECHANIC                           = 146,
	SPELL_FAILED_PLAY_TIME                                       = 147,
	SPELL_FAILED_REPUTATION                                      = 148,
	SPELL_FAILED_MIN_SKILL                                       = 149,
	SPELL_FAILED_NOT_IN_ARENA                                    = 150,
	SPELL_FAILED_NOT_ON_SHAPESHIFT                               = 151,
	SPELL_FAILED_NOT_ON_STEALTHED                                = 152,
	SPELL_FAILED_NOT_ON_DAMAGE_IMMUNE                            = 153,
	SPELL_FAILED_NOT_ON_MOUNTED                                  = 154,
	SPELL_FAILED_TOO_SHALLOW                                     = 155,
	SPELL_FAILED_TARGET_NOT_IN_SANCTUARY                         = 156,
	SPELL_FAILED_TARGET_IS_TRIVIAL                               = 157,
	SPELL_FAILED_BM_OR_INVISGOD                                  = 158,
	SPELL_FAILED_EXPERT_RIDING_REQUIREMENT                       = 159,
	SPELL_FAILED_ARTISAN_RIDING_REQUIREMENT                      = 160,
	SPELL_FAILED_NOT_IDLE                                        = 161,
	SPELL_FAILED_NOT_INACTIVE                                    = 162,
	SPELL_FAILED_PARTIAL_PLAYTIME                                = 163,
	SPELL_FAILED_NO_PLAYTIME                                     = 164,
	SPELL_FAILED_NOT_IN_BATTLEGROUND                             = 165,
	SPELL_FAILED_ONLY_IN_ARENA                                   = 166,
	SPELL_FAILED_TARGET_LOCKED_TO_RAID_INSTANCE                  = 167,
	SPELL_FAILED_UNKNOWN                                         = 168,
	SPELL_FAILED_TOO_NEAR                                        = 169,
	SPELL_FAILED_CANTUSE_IN_SHAPESHIFT,
	SPELL_FAILED_CANTUSE_IN_MOUNT,
	SPELL_FAILED_CANTUSE_IN_COMBAT,
	SPELL_FAILED_WRONG_WEAPON,
	SPELL_FAILED_NOT_ENOUGH_BAG_POS,
	SPELL_CANCAST_OK                                             = 255,
};

enum SpellEffects
{
	SPELL_EFFECT_NULL = 0,
	SPELL_EFFECT_INSTANT_KILL,              //    1			立即杀掉
	SPELL_EFFECT_SCHOOL_DAMAGE,             //    2			普通伤害
	SPELL_EFFECT_DUMMY,                     //    3			
	SPELL_EFFECT_PORTAL_TELEPORT,           //    4			/*暂时不用*/
	SPELL_EFFECT_TELEPORT_UNITS,            //    5    
	SPELL_EFFECT_APPLY_AURA,                //    6    
	SPELL_EFFECT_ENVIRONMENTAL_DAMAGE,      //    7    
	SPELL_EFFECT_POWER_DRAIN,               //    8    
	SPELL_EFFECT_HEALTH_LEECH,              //    9    
	SPELL_EFFECT_HEAL,                      //    10    
	SPELL_EFFECT_BIND,                      //    11    
	SPELL_EFFECT_PORTAL,                    //    12
	SPELL_EFFECT_RITUAL_BASE,               //    13
	SPELL_EFFECT_RITUAL_SPECIALIZE,         //    14
	SPELL_EFFECT_RITUAL_ACTIVATE_PORTAL,    //    15
	SPELL_EFFECT_QUEST_COMPLETE,            //    16    
	SPELL_EFFECT_WEAPON_DAMAGE_NOSCHOOL,    //    17    
	SPELL_EFFECT_RESURRECT,                 //    18    
	SPELL_EFFECT_ADD_EXTRA_ATTACKS,         //    19    
	SPELL_EFFECT_DODGE,                     //    20    
	SPELL_EFFECT_EVADE,                     //    21    
	SPELL_EFFECT_PARRY,                     //    22    
	SPELL_EFFECT_BLOCK,                     //    23    
	SPELL_EFFECT_CREATE_ITEM,               //    24    
	SPELL_EFFECT_WEAPON,                    //    25
	SPELL_EFFECT_DEFENSE,                   //    26
	SPELL_EFFECT_PERSISTENT_AREA_AURA,      //    27    
	SPELL_EFFECT_SUMMON,                    //    28    
	SPELL_EFFECT_LEAP,                      //    29    
	SPELL_EFFECT_ENERGIZE,                  //    30    
	SPELL_EFFECT_WEAPON_PERCENT_DAMAGE,     //    31    
	SPELL_EFFECT_TRIGGER_MISSILE,           //    32    
	SPELL_EFFECT_OPEN_LOCK,                 //    33    
	SPELL_EFFECT_TRANSFORM_ITEM,            //    34    
	SPELL_EFFECT_APPLY_AREA_AURA,           //    35    
	SPELL_EFFECT_LEARN_SPELL,               //    36    
	SPELL_EFFECT_SPELL_DEFENSE,             //    37    
	SPELL_EFFECT_DISPEL,                    //    38    
	SPELL_EFFECT_LANGUAGE,                  //    39
	SPELL_EFFECT_DUAL_WIELD,                //    40    
	SPELL_EFFECT_SUMMON_WILD,               //    41    
	SPELL_EFFECT_SUMMON_GUARDIAN,           //    42    
	SPELL_EFFECT_TELEPORT_UNITS_FACE_CASTER,//    43
	SPELL_EFFECT_SKILL_STEP,                //    44    
	SPELL_EFFECT_UNDEFINED_45,              //    45    
	SPELL_EFFECT_SPAWN,                     //    46
	SPELL_EFFECT_TRADE_SKILL,               //    47
	SPELL_EFFECT_STEALTH,                   //    48
	SPELL_EFFECT_DETECT,                    //    49
	SPELL_EFFECT_SUMMON_OBJECT,             //    50    
	//SPELL_EFFECT_TRANS_DOOR,              //    50    
	SPELL_EFFECT_FORCE_CRITICAL_HIT,        //    51
	SPELL_EFFECT_GUARANTEE_HIT,             //    52
	SPELL_EFFECT_ENCHANT_ITEM,              //    53    
	SPELL_EFFECT_ENCHANT_ITEM_TEMPORARY,    //    54    
	SPELL_EFFECT_TAMECREATURE,              //    55    
	SPELL_EFFECT_SUMMON_PET,                //    56    
	SPELL_EFFECT_LEARN_PET_SPELL,           //    57    
	SPELL_EFFECT_WEAPON_DAMAGE,             //    58    
	SPELL_EFFECT_OPEN_LOCK_ITEM,            //    59    
	SPELL_EFFECT_PROFICIENCY,               //    60
	SPELL_EFFECT_SEND_EVENT,                //    61    
	SPELL_EFFECT_POWER_BURN,                //    62
	SPELL_EFFECT_THREAT,                    //    63
	SPELL_EFFECT_TRIGGER_SPELL,             //    64    
	SPELL_EFFECT_HEALTH_FUNNEL,             //    65
	SPELL_EFFECT_POWER_FUNNEL,              //    66
	SPELL_EFFECT_HEAL_MAX_HEALTH,           //    67    
	SPELL_EFFECT_INTERRUPT_CAST,            //    68
	SPELL_EFFECT_DISTRACT,                  //    69
	SPELL_EFFECT_PULL,                      //    70
	SPELL_EFFECT_PICKPOCKET,                //    71
	SPELL_EFFECT_ADD_FARSIGHT,              //    72
	SPELL_EFFECT_SUMMON_POSSESSED,          //    73    
	SPELL_EFFECT_SUMMON_TOTEM,              //    74    
	SPELL_EFFECT_HEAL_MECHANICAL,           //    75
	SPELL_EFFECT_SUMMON_OBJECT_WILD,        //    76
	SPELL_EFFECT_SCRIPT_EFFECT,             //    77    
	SPELL_EFFECT_ATTACK,                    //    78
	SPELL_EFFECT_SANCTUARY,                 //    79
	SPELL_EFFECT_ADD_COMBO_POINTS,          //    80    
	SPELL_EFFECT_CREATE_HOUSE,              //    81
	SPELL_EFFECT_BIND_SIGHT,                //    82
	SPELL_EFFECT_DUEL,                      //    83
	SPELL_EFFECT_STUCK,                     //    84
	SPELL_EFFECT_SUMMON_PLAYER,             //    85
	SPELL_EFFECT_ACTIVATE_OBJECT,           //    86
	SPELL_EFFECT_SUMMON_TOTEM_SLOT1,        //    87    
	SPELL_EFFECT_SUMMON_TOTEM_SLOT2,        //    88    
	SPELL_EFFECT_SUMMON_TOTEM_SLOT3,        //    89    
	SPELL_EFFECT_SUMMON_TOTEM_SLOT4,        //    90    
	SPELL_EFFECT_THREAT_ALL,                //    91
	SPELL_EFFECT_ENCHANT_HELD_ITEM,         //    92
	SPELL_EFFECT_SUMMON_PHANTASM,           //    93
	SPELL_EFFECT_SELF_RESURRECT,            //    94    
	SPELL_EFFECT_SKINNING,                  //    95    
	SPELL_EFFECT_CHARGE,                    //    96    
	SPELL_EFFECT_SUMMON_CRITTER,            //    97    
	SPELL_EFFECT_KNOCK_BACK,                //    98    
	SPELL_EFFECT_DISENCHANT,                //    99    
	SPELL_EFFECT_INEBRIATE,                 //    100    
	SPELL_EFFECT_FEED_PET,                  //    101
	SPELL_EFFECT_DISMISS_PET,               //    102
	SPELL_EFFECT_REPUTATION,                //    103
	SPELL_EFFECT_SUMMON_OBJECT_SLOT1,       //    104
	SPELL_EFFECT_SUMMON_OBJECT_SLOT2,       //    105
	SPELL_EFFECT_SUMMON_OBJECT_SLOT3,       //    106
	SPELL_EFFECT_SUMMON_OBJECT_SLOT4,       //    107
	SPELL_EFFECT_DISPEL_MECHANIC,           //    108    
	SPELL_EFFECT_SUMMON_DEAD_PET,           //    109
	SPELL_EFFECT_DESTROY_ALL_TOTEMS,        //    110
	SPELL_EFFECT_DURABILITY_DAMAGE,         //    111
	SPELL_EFFECT_SUMMON_DEMON,              //    112    
	SPELL_EFFECT_RESURRECT_FLAT,            //    113    
	SPELL_EFFECT_ATTACK_ME,                 //    114
	SPELL_EFFECT_DURABILITY_DAMAGE_PCT,     //    115
	SPELL_EFFECT_SKIN_PLAYER_CORPSE,        //    116
	SPELL_EFFECT_SPIRIT_HEAL,               //    117
	SPELL_EFFECT_SKILL,                     //    118
	SPELL_EFFECT_APPLY_PET_AURA,            //    119    
	SPELL_EFFECT_TELEPORT_GRAVEYARD,        //    120
	SPELL_EFFECT_DUMMYMELEE,                //    121
	SPELL_EFFECT_AREA_SCHOOL_DAMAGE,                  //    122
	SPELL_EFFECT_AREA_SCHOOL_HEAL,                  //    123
	SPELL_EFFECT_PLAYER_PULL,               //    124
	SPELL_EFFECT_AREA_SCHOOL_ENERGY,                  //    125
	SPELL_EFFECT_UNKNOWN5,                  //    126
	SPELL_EFFECT_PROSPECTING,               //    127
	SPELL_EFFECT_UNKNOWN7,                  //    128
	SPELL_EFFECT_AREA_BUF,                  //    129
	SPELL_EFFECT_SETANIMAL,                 //    130
	SPELL_EFFECT_UNSETANIMAL,               //    131
	SPELL_EFFECT_UNKNOWN12,                 //    132
	SPELL_EFFECT_FORGET_SPECIALIZATION,     //    133
	SPELL_EFFECT_SCHOOL_DAMAGE_NEARBYTWO,   //    134
	SPELL_EFFECT_DAMAGE_TO_HEALTH,          //    135
	SPELL_EFFECT_ADDPETTOLIST,              //    136
	SPELL_EFFECT_RECORDPOS,                 //    137
	SPELL_EFFECT_UNKNOWN18,                 //    138
	SPELL_EFFECT_UNKNOWN19,                 //    139
	SPELL_EFFECT_UNKNOWN20,                 //    140
	SPELL_EFFECT_REFLECTDAMAGE,             //    141
	SPELL_EFFECT_TRIGGER_SPELL_WITH_VALUE,	//    142
	SPELL_EFFECT_XP_TRIGGER,                //    143
	SPELL_EFFECT_BANYUEZHAN,				//	  144
	SPELL_EFFECT_HEAL_MANA,					//	  145
	SPELL_EFFECT_CHONGZHUANG,				//	  146
	SPELL_EFFECT_CONSUME2GIFT,				//	  147
	SPELL_EFFECT_PHYSATTACK,				//    148
	SPELL_EFFECT_EXTRA_DAMAGE,				//	  149
	SPELL_EFFECT_ADD_TITLE,					//	  150
	TOTAL_SPELL_EFFECTS,                    //    151
};

enum MOD_TYPES
{
	SPELL_AURA_NONE = 0,                                // None
	SPELL_AURA_BIND_SIGHT = 1,                          // Bind Sight
	SPELL_AURA_MOD_POSSESS = 2,                         // Mod Possess
	SPELL_AURA_PERIODIC_DAMAGE = 3,                     // Periodic Damage
	SPELL_AURA_DUMMY = 4,                               // Script Aura
	SPELL_AURA_MOD_CONFUSE = 5,                         // Mod Confuse
	SPELL_AURA_MOD_CHARM = 6,                           // Mod Charm
	SPELL_AURA_MOD_FEAR = 7,                            // Mod Fear
	SPELL_AURA_PERIODIC_HEAL = 8,                       // Periodic Heal
	SPELL_AURA_MOD_ATTACKSPEED = 9,                     // Mod Attack Speed
	SPELL_AURA_MOD_THREAT = 10,                         // Mod Threat
	SPELL_AURA_MOD_TAUNT = 11,                          // Taunt
	SPELL_AURA_MOD_STUN = 12,                           // Stun
	SPELL_AURA_MOD_DAMAGE_DONE = 13,                    // Mod Damage Done
	SPELL_AURA_MOD_DAMAGE_TAKEN = 14,                   // Mod Damage Taken
	SPELL_AURA_DAMAGE_SHIELD = 15,                      // Damage Shield
	SPELL_AURA_MOD_STEALTH = 16,                        // Mod Stealth
	SPELL_AURA_MOD_DETECT = 17,                         // Mod Detect
	SPELL_AURA_MOD_INVISIBILITY = 18,                   // Mod Invisibility
	SPELL_AURA_MOD_INVISIBILITY_DETECTION = 19,         // Mod Invisibility Detection
	SPELL_AURA_MOD_TOTAL_HEALTH_REGEN_PCT = 20,
	SPELL_AURA_MOD_TOTAL_MANA_REGEN_PCT = 21,
	SPELL_AURA_MOD_RESISTANCE = 22,                     // Mod Resistance
	SPELL_AURA_PERIODIC_TRIGGER_SPELL = 23,             // Periodic Trigger
	SPELL_AURA_PERIODIC_ENERGIZE = 24,                  // Periodic Energize
	SPELL_AURA_MOD_PACIFY = 25,                         // Pacify
	SPELL_AURA_MOD_ROOT = 26,                           // Root
	SPELL_AURA_MOD_SILENCE = 27,                        // Silence
	SPELL_AURA_REFLECT_SPELLS = 28,                     // Reflect Spells %
	SPELL_AURA_MOD_STAT = 29,                           // Mod Stat
	SPELL_AURA_MOD_SKILL = 30,                          // Mod Skill
	SPELL_AURA_MOD_INCREASE_SPEED = 31,                 // Mod Speed
	SPELL_AURA_MOD_INCREASE_MOUNTED_SPEED = 32,         // Mod Speed Mounted
	SPELL_AURA_MOD_DECREASE_SPEED = 33,                 // Mod Speed Slow
	SPELL_AURA_MOD_INCREASE_HEALTH = 34,                // Mod Increase Health
	SPELL_AURA_MOD_INCREASE_ENERGY = 35,                // Mod Increase Energy
	SPELL_AURA_MOD_SHAPESHIFT = 36,                     // Shapeshift
	SPELL_AURA_EFFECT_IMMUNITY = 37,                    // Immune Effect
	SPELL_AURA_STATE_IMMUNITY = 38,                     // Immune State
	SPELL_AURA_SCHOOL_IMMUNITY = 39,                    // Immune School    
	SPELL_AURA_DAMAGE_IMMUNITY = 40,                    // Immune Damage
	SPELL_AURA_DISPEL_IMMUNITY = 41,                    // Immune Dispel Type
	SPELL_AURA_PROC_TRIGGER_SPELL = 42,                 // Proc Trigger Spell
	SPELL_AURA_PROC_TRIGGER_DAMAGE = 43,                // Proc Trigger Damage
	SPELL_AURA_TRACK_CREATURES = 44,                    // Track Creatures
	SPELL_AURA_TRACK_RESOURCES = 45,                    // Track Resources
	SPELL_AURA_MOD_PARRY_SKILL = 46,                    // Mod Parry Skill
	SPELL_AURA_MOD_PARRY_PERCENT = 47,                  // Mod Parry Percent
	SPELL_AURA_MOD_DODGE_SKILL = 48,                    // Mod Dodge Skill
	SPELL_AURA_MOD_DODGE_PERCENT = 49,                  // Mod Dodge Percent  
	SPELL_AURA_MOD_BLOCK_SKILL = 50,                    // Mod Block Skill
	SPELL_AURA_MOD_BLOCK_PERCENT = 51,                  // Mod Block Percent
	SPELL_AURA_MOD_CRIT_PERCENT = 52,                   // Mod Crit Percent
	SPELL_AURA_PERIODIC_LEECH = 53,                     // Periodic Leech
	SPELL_AURA_MOD_HIT_CHANCE = 54,                     // Mod Hit Chance
	SPELL_AURA_MOD_SPELL_HIT_CHANCE = 55,               // Mod Spell Hit Chance
	SPELL_AURA_TRANSFORM = 56,                          // Transform
	SPELL_AURA_MOD_SPELL_CRIT_CHANCE = 57,              // Mod Spell Crit Chance
	SPELL_AURA_MOD_INCREASE_SWIM_SPEED = 58,            // Mod Speed Swim
	SPELL_AURA_MOD_DAMAGE_DONE_CREATURE = 59,           // Mod Creature Dmg Done   
	SPELL_AURA_MOD_PACIFY_SILENCE = 60,                 // Pacify & Silence
	SPELL_AURA_MOD_SCALE = 61,                          // Mod Scale
	SPELL_AURA_PERIODIC_HEALTH_FUNNEL = 62,             // Periodic Health Funnel
	SPELL_AURA_PERIODIC_MANA_FUNNEL = 63,               // Periodic Mana Funnel
	SPELL_AURA_PERIODIC_MANA_LEECH = 64,                // Periodic Mana Leech
	SPELL_AURA_MOD_CASTING_SPEED = 65,                  // Haste - Spells
	SPELL_AURA_FEIGN_DEATH = 66,                        // Feign Death
	SPELL_AURA_MOD_DISARM = 67,                         // Disarm
	SPELL_AURA_MOD_STALKED = 68,                        // Mod Stalked
	SPELL_AURA_SCHOOL_ABSORB = 69,                      // School Absorb    
	SPELL_AURA_EXTRA_ATTACKS = 70,                      // Extra Attacks
	SPELL_AURA_MOD_SPELL_CRIT_CHANCE_SCHOOL = 71,       // Mod School Spell Crit Chance
	SPELL_AURA_MOD_POWER_COST = 72,                     // Mod Power Cost
	SPELL_AURA_MOD_POWER_COST_SCHOOL = 73,              // Mod School Power Cost
	SPELL_AURA_REFLECT_SPELLS_SCHOOL = 74,              // Reflect School Spells %
	SPELL_AURA_MOD_LANGUAGE = 75,                       // Mod Language
	SPELL_AURA_FAR_SIGHT = 76,                          // Far Sight
	SPELL_AURA_MECHANIC_IMMUNITY = 77,                  // Immune Mechanic
	SPELL_AURA_MOUNTED = 78,                            // Mounted
	SPELL_AURA_MOD_DAMAGE_PERCENT_DONE = 79,            // Mod Dmg %   
	SPELL_AURA_MOD_PERCENT_STAT = 80,                   // Mod Stat %
	SPELL_AURA_SPLIT_DAMAGE = 81,                       // Split Damage
	SPELL_AURA_WATER_BREATHING = 82,                    // Water Breathing
	SPELL_AURA_MOD_BASE_RESISTANCE = 83,                // Mod Base Resistance
	SPELL_AURA_MOD_REGEN = 84,                          // Mod Health Regen
	SPELL_AURA_MOD_POWER_REGEN = 85,                    // Mod Power Regen
	SPELL_AURA_CHANNEL_DEATH_ITEM = 86,                 // Create Death Item
	SPELL_AURA_MOD_DAMAGE_PERCENT_TAKEN = 87,           // Mod Dmg % Taken
	SPELL_AURA_MOD_PERCENT_REGEN = 88,                  // Mod Health Regen Percent
	SPELL_AURA_PERIODIC_DAMAGE_PERCENT = 89,            // Periodic Damage Percent   
	SPELL_AURA_MOD_RESIST_CHANCE = 90,                  // Mod Resist Chance
	SPELL_AURA_MOD_DETECT_RANGE = 91,                   // Mod Detect Range
	SPELL_AURA_PREVENTS_FLEEING = 92,                   // Prevent Fleeing
	SPELL_AURA_MOD_UNATTACKABLE = 93,                   // Mod Uninteractible
	SPELL_AURA_INTERRUPT_REGEN = 94,                    // Interrupt Regen
	SPELL_AURA_GHOST = 95,                              // Ghost
	SPELL_AURA_SPELL_MAGNET = 96,                       // Spell Magnet
	SPELL_AURA_MANA_SHIELD = 97,                        // Mana Shield
	SPELL_AURA_MOD_SKILL_TALENT = 98,                   // Mod Skill Talent
	SPELL_AURA_MOD_ATTACK_POWER = 99,                   // Mod Attack Power
	SPELL_AURA_AURAS_VISIBLE = 100,                     // Auras Visible
	SPELL_AURA_MOD_RESISTANCE_PCT = 101,                // Mod Resistance %
	SPELL_AURA_MOD_CREATURE_ATTACK_POWER = 102,         // Mod Creature Attack Power
	SPELL_AURA_MOD_TOTAL_THREAT = 103,                  // Mod Total Threat (Fade)
	SPELL_AURA_WATER_WALK = 104,                        // Water Walk
	SPELL_AURA_FEATHER_FALL = 105,                      // Feather Fall
	SPELL_AURA_HOVER = 106,                             // Hover
	SPELL_AURA_ADD_FLAT_MODIFIER = 107,                 // Add Flat Modifier
	SPELL_AURA_ADD_PCT_MODIFIER = 108,                  // Add % Modifier
	SPELL_AURA_ADD_TARGET_TRIGGER = 109,                // Add Class Target Trigger    
	SPELL_AURA_MOD_POWER_REGEN_PERCENT = 110,           // Mod Power Regen %
	SPELL_AURA_ADD_CASTER_HIT_TRIGGER = 111,            // Add Class Caster Hit Trigger
	SPELL_AURA_OVERRIDE_CLASS_SCRIPTS = 112,            // Override Class Scripts
	SPELL_AURA_MOD_RANGED_DAMAGE_TAKEN = 113,           // Mod Ranged Dmg Taken
	SPELL_AURA_MOD_RANGED_DAMAGE_TAKEN_PCT = 114,       // Mod Ranged % Dmg Taken
	SPELL_AURA_MOD_HEALING = 115,                       // Mod Healing
	SPELL_AURA_IGNORE_REGEN_INTERRUPT = 116,            // Regen During Combat
	SPELL_AURA_MOD_MECHANIC_RESISTANCE = 117,           // Mod Mechanic Resistance
	SPELL_AURA_MOD_HEALING_PCT = 118,                   // Mod Healing %
	SPELL_AURA_SHARE_PET_TRACKING = 119,                // Share Pet Tracking    
	SPELL_AURA_UNTRACKABLE = 120,                       // Untrackable
	SPELL_AURA_EMPATHY = 121,                           // Empathy (Lore, whatever)
	SPELL_AURA_MOD_OFFHAND_DAMAGE_PCT = 122,            // Mod Offhand Dmg %
	SPELL_AURA_MOD_POWER_COST_PCT = 123,                // Mod Power Cost % --> armor penetration & spell penetration
	SPELL_AURA_MOD_RANGED_ATTACK_POWER = 124,           // Mod Ranged Attack Power
	SPELL_AURA_MOD_MELEE_DAMAGE_TAKEN = 125,            // Mod Melee Dmg Taken
	SPELL_AURA_MOD_MELEE_DAMAGE_TAKEN_PCT = 126,        // Mod Melee % Dmg Taken
	SPELL_AURA_RANGED_ATTACK_POWER_ATTACKER_BONUS = 127,// Rngd Atk Pwr Attckr Bonus
	SPELL_AURA_MOD_POSSESS_PET = 128,                   // Mod Possess Pet
	SPELL_AURA_MOD_INCREASE_SPEED_ALWAYS = 129,         // Mod Speed Always   
	SPELL_AURA_MOD_MOUNTED_SPEED_ALWAYS = 130,          // Mod Mounted Speed Always
	SPELL_AURA_MOD_CREATURE_RANGED_ATTACK_POWER = 131,  // Mod Creature Ranged Attack Power
	SPELL_AURA_MOD_INCREASE_ENERGY_PERCENT = 132,       // Mod Increase Energy %
	SPELL_AURA_MOD_INCREASE_HEALTH_PERCENT = 133,       // Mod Max Health %
	SPELL_AURA_MOD_MANA_REGEN_INTERRUPT = 134,          // Mod Interrupted Mana Regen
	SPELL_AURA_MOD_HEALING_DONE = 135,                  // Mod Healing Done
	SPELL_AURA_MOD_HEALING_DONE_PERCENT = 136,          // Mod Healing Done %
	SPELL_AURA_MOD_TOTAL_STAT_PERCENTAGE = 137,         // Mod Total Stat %
	SPELL_AURA_MOD_HASTE = 138,                         // Haste - Melee
	SPELL_AURA_FORCE_REACTION = 139,                    // Force Reaction    
	SPELL_AURA_MOD_RANGED_HASTE = 140,                  // Haste - Ranged
	SPELL_AURA_MOD_RANGED_AMMO_HASTE = 141,             // Haste - Ranged (Ammo Only)
	SPELL_AURA_MOD_BASE_RESISTANCE_PCT = 142,           // Mod Base Resistance %
	SPELL_AURA_MOD_RESISTANCE_EXCLUSIVE = 143,          // Mod Resistance Exclusive
	SPELL_AURA_SAFE_FALL = 144,                         // Safe Fall
	SPELL_AURA_CHARISMA = 145,                          // Charisma
	SPELL_AURA_PERSUADED = 146,                         // Persuaded
	SPELL_AURA_ADD_CREATURE_IMMUNITY = 147,             // Add Creature Immunity
	SPELL_AURA_RETAIN_COMBO_POINTS = 148,               // Retain Combo Points
	SPELL_AURA_RESIST_PUSHBACK = 149,                   // Resist Pushback
	SPELL_AURA_MOD_SHIELD_BLOCK_PCT = 150,              // Mod Shield Block %
	SPELL_AURA_TRACK_STEALTHED = 151,                   // Track Stealthed
	SPELL_AURA_MOD_DETECTED_RANGE = 152,                // Mod Detected Range
	SPELL_AURA_SPLIT_DAMAGE_FLAT = 153,                 // Split Damage Flat
	SPELL_AURA_MOD_STEALTH_LEVEL = 154,                 // Stealth Level Modifier
	SPELL_AURA_MOD_WATER_BREATHING = 155,               // Mod Water Breathing
	SPELL_AURA_MOD_REPUTATION_ADJUST = 156,             // Mod Reputation Gain
	SPELL_AURA_PET_DAMAGE_MULTI = 157,                  // Mod Pet Damage
	SPELL_AURA_MOD_SHIELD_BLOCK = 158,                  // Mod Shield Block
	SPELL_AURA_NO_PVP_CREDIT = 159,                     // No PVP Credit 
	SPELL_AURA_MOD_SIDE_REAR_PDAE_DAMAGE_TAKEN = 160,   // Mod Side/Rear PBAE Damage Taken 
	SPELL_AURA_MOD_HEALTH_REGEN_IN_COMBAT = 161,        // Mod Health Regen In Combat
	SPELL_AURA_POWER_BURN = 162,                        // Power Burn 
	SPELL_AURA_MOD_CRIT_DAMAGE_BONUS_MELEE = 163,       // Mod Critical Damage Bonus (Physical)
	SPELL_AURA_MELEE_ATTACK_POWER_ATTACKER_BONUS = 165, // Melee AP Attacker Bonus
	SPELL_AURA_MOD_ATTACK_POWER_PCT = 166,              // Mod Attack Power
	SPELL_AURA_MOD_RANGED_ATTACK_POWER_PCT = 167,       // Mod Ranged Attack Power %
	SPELL_AURA_INCREASE_DAMAGE = 168,                   // Increase Damage Type
	SPELL_AURA_INCREASE_CRITICAL = 169,                 // Increase Critical Type
	SPELL_AURA_DETECT_AMORE = 170,                      // Detect Amore
	SPELL_AURA_INCREASE_MOVEMENT_AND_MOUNTED_SPEED = 172,// Increase Movement and Mounted Speed (Non-Stacking)
	SPELL_AURA_INCREASE_SPELL_DAMAGE_PCT = 174,         // Increase Spell Damage by % status
	SPELL_AURA_INCREASE_SPELL_HEALING_PCT = 175,        // Increase Spell Healing by % status
	SPELL_AURA_SPIRIT_OF_REDEMPTION = 176,              // Spirit of Redemption Auras
	SPELL_AURA_AREA_CHARM = 177,                        // Area Charm 
	SPELL_AURA_INCREASE_ATTACKER_SPELL_CRIT = 179,      // Increase Attacker Spell Crit Type
	SPELL_AURA_INCREASE_SPELL_DAMAGE_VS_TYPE = 180,     // Increase Spell Damage Type
	SPELL_AURA_INCREASE_ARMOR_BASED_ON_INTELLECT_PCT = 182, // Increase Armor based on Intellect
	SPELL_AURA_DECREASE_CRIT_THREAT = 183,              // Decrease Critical Threat by
	SPELL_AURA_DECREASE_ATTACKER_CHANCE_TO_HIT_MELEE = 184,//Reduces Attacker Chance to Hit with Melee
	SPELL_AURA_DECREASE_ATTACKER_CHANGE_TO_HIT_RANGED = 185,// Reduces Attacker Chance to Hit with Ranged 
	SPELL_AURA_DECREASE_ATTACKER_CHANGE_TO_HIT_SPELLS = 186,// Reduces Attacker Chance to Hit with Spells
	SPELL_AURA_DECREASE_ATTACKER_CHANGE_TO_CRIT_MELEE = 187,// Reduces Attacker Chance to Crit with Melee (Ranged?)
	SPELL_AURA_DECREASE_ATTACKER_CHANGE_TO_CRIT_RANGED = 188,// Reduces Attacker Chance to Crit with Ranged (Melee?)
	SPELL_AURA_INCREASE_REPUTATION = 190,               // Increases reputation from killed creatures
	SPELL_AURA_SPEED_LIMIT = 191,                       // speed limit
	SPELL_AURA_MELEE_SLOW_PCT = 192,
	SPELL_AURA_INCREASE_TIME_BETWEEN_ATTACKS = 193,
	SPELL_AURA_INREASE_SPELL_DAMAGE_PCT_OF_INTELLECT = 194,  // NOT USED ANYMORE - 174 used instead
	SPELL_AURA_INCREASE_HEALING_PCT_OF_INTELLECT = 195,		// NOT USED ANYMORE - 175 used instead
	SPELL_AURA_MOD_ALL_WEAPON_SKILLS = 196,
	SPELL_AURA_REDUCE_ATTACKER_CRICTICAL_HIT_CHANCE_PCT = 197,
	SPELL_AURA_INCREASE_SPELL_HIT_PCT = 199,
	SPELL_AURA_CANNOT_BE_DODGED = 201,
	SPELL_AURA_FINISHING_MOVES_CANNOT_BE_DODGED = 202,
	SPELL_AURA_REDUCE_ATTACKER_CRICTICAL_HIT_DAMAGE_MELEE_PCT = 203,
	SPELL_AURA_REDUCE_ATTACKER_CRICTICAL_HIT_DAMAGE_RANGED_PCT = 204,
	SPELL_AURA_MOD_LOOT_GOLD = 209,
	SPELL_AURA_MOD_LOOT_ITEMCHANCE = 210,
	SPELL_AURA_INCREASE_RANGED_ATTACK_POWER_PCT_OF_INTELLECT = 212,
	SPELL_AURA_INCREASE_RAGE_FROM_DAMAGE_DEALT_PCT = 213,
	SPELL_AURA_INCREASE_CASTING_TIME_PCT = 216,
	SPELL_AURA_REGEN_MANA_STAT_PCT=219,
	SPELL_AURA_HEALING_STAT_PCT=220,
	SPELL_AURA_INCREASE_REGEN_HEALTH_PCT=221,
	SPELL_AURA_INCREASE_REGEN_HEALTH_POINT=222,
	SPELL_AURA_INCREASE_REGEN_MANA_PCT=223,
	SPELL_AURA_INCREASE_MAX_HEALTH=230,//Used by Commanding Shout
	SPELL_AURA_MODIFY_HITCHANGE_PCT=237,
	SPELL_AURA_INCREASE_REGENMANAPOINT=238,
	SPELL_AURA_MODIFY_MECHANICS_PROBABILITY=239,
	SPELL_AURA_MODIFY_AXE_SKILL=240,
	SPELL_AURA_XP_TRIGGER=241,
	SPELL_AURA_IDLE_XP=242,
	SPELL_AURA_EXTRA_XP=243,
	SPELL_AURA_SHAPESHIFT_FIGHT_NOMOUNT=244,	
	SPELL_AURA_SHAPESHIFT_NOFIGHT_NOMOUNT=245,	
	SPELL_AURA_SHAPESHIFT_FIGHT_MOUNT=246,
	SPELL_AURA_SHAPESHIFT_NOFIGHT_MOUNT=247,	
	SPELL_AURA_MOUNT_FIGHT=248,
	SPELL_AURA_MOUNT_NOFIGHT=249,
	SPELL_AURA_MOD_SPELL_CDT=250,
	SPELL_AURA_DAMAGE_TO_HEALTH=251,
	TOTAL_SPELL_AURAS = 252,
};

enum ItemSpellCategory
{
	ITEM_SPELL_CATEGORY_NULL,
	ITEM_SPELL_CATEGORY_POTION,			// 服药
	ITEM_SPELL_CATEGORY_INC_STAT,		// 改变状态的物品使用
	ITEM_SPELL_TELEPORT,				//	传送
	ITEM_SPELL_CATEGORY_MAX,
};

enum SpellCategory
{
	SPELL_NORMAL = 4,
};
enum SpellSchools
{
	SCHOOL_NORMAL                 = 0,
	SCHOOL_HOLY                   = 1,
	SCHOOL_FIRE                   = 2,
	SCHOOL_NATURE                 = 3,
	SCHOOL_FROST                  = 4,
	SCHOOL_SHADOW                 = 5,
	SCHOOL_ARCANE                 = 6
};
//////////////////////////////////////////////////////////////////////////add by hao zi/////////
#define MAX_SPELL_SCHOOL                  7

enum SpellSchoolMask
{
	SPELL_SCHOOL_MASK_NONE    = 0x00,                       // not exist
	SPELL_SCHOOL_MASK_NORMAL  = (1 << SCHOOL_NORMAL), // PHYSICAL (Armor)
	SPELL_SCHOOL_MASK_HOLY    = (1 << SCHOOL_HOLY  ),
	SPELL_SCHOOL_MASK_FIRE    = (1 << SCHOOL_FIRE  ),
	SPELL_SCHOOL_MASK_NATURE  = (1 << SCHOOL_NATURE),
	SPELL_SCHOOL_MASK_FROST   = (1 << SCHOOL_FROST ),
	SPELL_SCHOOL_MASK_SHADOW  = (1 << SCHOOL_SHADOW),
	SPELL_SCHOOL_MASK_ARCANE  = (1 << SCHOOL_ARCANE)
};

#define SPELL_SCHOOL_MASK_MAGIC                            \
	( SPELL_SCHOOL_MASK_FIRE | SPELL_SCHOOL_MASK_NATURE |  \
	SPELL_SCHOOL_MASK_FROST | SPELL_SCHOOL_MASK_SHADOW | \
	SPELL_SCHOOL_MASK_ARCANE )

#define SPELL_SCHOOL_MASK_ALL                            \
	( SPELL_SCHOOL_MASK_MAGIC | SPELL_SCHOOL_MASK_NORMAL |  \
	SPELL_SCHOOL_MASK_HOLY )


//////////////////////////////////////////////////////////////////////////
enum EnviromentalDamage
{
	DAMAGE_EXHAUSTED = 0,
	DAMAGE_DROWNING = 1,
	DAMAGE_FALL = 2,
	DAMAGE_LAVA = 3,
	DAMAGE_SLIME = 4,
	DAMAGE_FIRE = 5
};
enum HitStatus
{
	HITSTATUS_unk			= 0x01,
	HITSTATUS_HITANIMATION  = 0x02,
	HITSTATUS_DUALWIELD     = 0x04,
	HITSTATUS_MISS          = 0x10,
	HITSTATUS_ABSORBED      = 0x20,
	HITSTATUS_RESIST        = 0x40,
	HITSTATUS_CRICTICAL     = 0x80,
	HITSTATUS_BLOCK         = 0x800,
	HITSTATUS_GLANCING      = 0x4000,
	HITSTATUS_CRUSHINGBLOW  = 0x8000,
	HITSTATUS_NOACTION      = 0x10000,
	HITSTATUS_SWINGNOHITSOUND = 0x80000 // as in miss?
};

enum SPELL_DMG_TYPE // SPELL_ENTRY_Spell_Dmg_Type
{
	SPELL_DMG_TYPE_NONE   = 0,
	SPELL_DMG_TYPE_MAGIC  = 1,
	SPELL_DMG_TYPE_MELEE  = 2,
	SPELL_DMG_TYPE_RANGED = 3
};

// value's for SendSpellLog
enum SPELL_LOG
{
	SPELL_LOG_NONE,
	SPELL_LOG_MISS,
	SPELL_LOG_RESIST,
	SPELL_LOG_DODGE,
	SPELL_LOG_PARRY,
	SPELL_LOG_BLOCK,
	SPELL_LOG_EVADE,
	SPELL_LOG_IMMUNE,
	SPELL_LOG_IMMUNE2,
	SPELL_LOG_DEFLECT,
	SPELL_LOG_ABSORB,
	SPELL_LOG_REFLECT
};

enum spell_avoid_mask
{
	SPELL_AVOID_MASK_DODGE = 1,
	SPELL_AVOID_MASK_BLOCK = 2
};

enum Flags3
{
	FLAGS3_NULL               = 0x0,
	FLAGS3_MOUNT_USE               = 0x1,
	FLAGS3_SHAPESHIFT_USE               = 0x2,    // Can be used while stealthed
	FLAGS3_UNK4               = 0x4,    // request pet maybe
	FLAGS3_UNK5               = 0x8,    // something todo with temp enchanted items
	FLAGS3_PARTY_EFFECTING_AURA = 0x10, // Party affecting aura's
	FLAGS3_ACTIVATE_AUTO_SHOT = 0x20,   // spell that enable's auto shoot
	FLAGS3_UNK8               = 0x40,   //Polymorph spells
	FLAGS3_UNK9               = 0x80,
	FLAGS3_UNUSED1            = 0x100,
	FLAGS3_UNK11              = 0x200,  // used by 2 spells, 30421 | Nether Portal - Perseverence and  30466 | Nether Portal - Perseverence
	FLAGS3_TAME_X             = 0x400,  // tame [creature]
	FLAGS3_FUNNEL             = 0x800,  // only funnel spells
	FLAGS3_UNK14              = 0x1000, // swipe / Cleave spells
	FLAGS3_ENCHANT_OWN_ONLY   = 0x2000, // no trade window targets, BoE items get soulbound to you
	FLAGS3_SPELL_PLAYER_EVENT = 0x4000, // Player event's like logging in, finishing quests, triggering cinematic, being adored, Heartbroken etc
	FLAGS3_UNUSED3            = 0x8000,
	FLAGS3_CONTROL_UNIT       = 0x10000, // PvP Controller, RC, Creature taming, Taming Lesson
	FLAGS3_REQ_RANGED_WEAPON  = 0x20000, // this is shit and has nothing to do with auto shot
	FLAGS3_REVIVE_PET         = 0x40000, // actually 1 spell, revive pet
	FLAGS3_UNK21              = 0x80000, // this is a group of spells that are triggered by something. (I have no clue on how to name this one)
	FLAGS3_REQ_BEHIND_TARGET  = 0x100000, //wrong
	FLAGS3_UNK23              = 0x200000,
	FLAGS3_UNK24              = 0x400000,
	FLAGS3_UNK25              = 0x800000,
	FLAGS3_UNK26              = 0x1000000,
	FLAGS3_UNK27              = 0x2000000,
	FLAGS3_UNK28              = 0x4000000,
	FLAGS3_UNK29              = 0x8000000, // fishing spells and enchanting weapons
	FLAGS3_UNK30              = 0x10000000, // some secondairy spell triggers, especialy for lightning shield alike spells
	FLAGS3_UNK31              = 0x20000000,
	FLAGS3_UNK32              = 0x40000000,
};

enum Flags4
{
	FLAGS4_BG_ONLY                      = 0x800,
	FLAGS4_PLAYER_RANGED_SPELLS         = 0x8000,
	CAN_PERSIST_AND_CASTED_WHILE_DEAD   = 0x100000,
	FLAGS4_PLAYER_RANGED_WAND           = 0x400000
};

enum Flags5
{
	FLAGS5_PROCCHANCE_COMBOBASED        = 0x2,
	FLAGS5_ONLY_IN_OUTLANDS             = 0x4000000,
};

typedef enum {
	EFF_TARGET_NONE										= 0,
	EFF_TARGET_SELF										= 1,
	EFF_TARGET_INVISIBLE_OR_HIDDEN_ENEMIES_AT_LOCATION_RADIUS		= 3,
	EFF_TARGET_FRIENDLY									= 4,
	EFF_TARGET_PET										= 5,
	EFF_TARGET_SINGLE_ENEMY								= 6,
	EFF_TARGET_SCRIPTED_TARGET							= 7,
	EFF_TARGET_ALL_TARGETABLE_AROUND_LOCATION_IN_RADIUS  = 8,
	EFF_TARGET_HEARTSTONE_LOCATION						= 9,
	EFF_TARGET_ALL_ENEMY_IN_AREA							= 15,
	EFF_TARGET_ALL_ENEMY_IN_AREA_INSTANT					= 16,
	EFF_TARGET_TELEPORT_LOCATION							= 17,
	EFF_TARGET_LOCATION_TO_SUMMON						= 18,
	EFF_TARGET_ALL_PARTY_AROUND_CASTER					= 20,
	EFF_TARGET_SINGLE_FRIEND								= 21,
	EFF_TARGET_ALL_ENEMIES_AROUND_CASTER					= 22,
	EFF_TARGET_GAMEOBJECT								= 23,
	EFF_TARGET_IN_FRONT_OF_CASTER						= 24,
	EFF_TARGET_DUEL										= 25,//Dont know the real name!!!
	EFF_TARGET_GAMEOBJECT_ITEM							= 26,
	EFF_TARGET_PET_MASTER								= 27,
	EFF_TARGET_ALL_ENEMY_IN_AREA_CHANNELED				= 28,
	EFF_TARGET_ALL_PARTY_IN_AREA_CHANNELED				= 29,
	EFF_TARGET_ALL_FRIENDLY_IN_AREA						= 30,
	EFF_TARGET_ALL_TARGETABLE_AROUND_LOCATION_IN_RADIUS_OVER_TIME	= 31,
	EFF_TARGET_MINION									= 32,
	EFF_TARGET_ALL_PARTY_IN_AREA							= 33,
	EFF_TARGET_SINGLE_PARTY								= 35,
	EFF_TARGET_PET_SUMMON_LOCATION						= 36,
	EFF_TARGET_ALL_PARTY									= 37,
	EFF_TARGET_SCRIPTED_OR_SINGLE_TARGET					= 38,
	EFF_TARGET_SELF_FISHING								= 39,
	EFF_TARGET_SCRIPTED_GAMEOBJECT						= 40,
	EFF_TARGET_TOTEM_EARTH								= 41,
	EFF_TARGET_TOTEM_WATER								= 42,
	EFF_TARGET_TOTEM_AIR									= 43,
	EFF_TARGET_TOTEM_FIRE								= 44,
	EFF_TARGET_CHAIN										= 45,
	EFF_TARGET_SCIPTED_OBJECT_LOCATION					= 46,
	EFF_TARGET_DYNAMIC_OBJECT							= 47,//not sure exactly where is used
	EFF_TARGET_MULTIPLE_SUMMON_LOCATION					= 48,
	EFF_TARGET_MULTIPLE_SUMMON_PET_LOCATION				= 49,
	EFF_TARGET_SUMMON_LOCATION							= 50,
	EFF_TARGET_CALIRI_EGS								= 51,
	EFF_TARGET_LOCATION_NEAR_CASTER						= 52,
	EFF_TARGET_CURRENT_SELECTION							= 53,
	EFF_TARGET_TARGET_AT_ORIENTATION_TO_CASTER			= 54,
	EFF_TARGET_LOCATION_INFRONT_CASTER					= 55,
	EFF_TARGET_PARTY_MEMBER								= 57,
	EFF_TARGET_TARGET_FOR_VISUAL_EFFECT					= 59,
	EFF_TARGET_SCRIPTED_TARGET2							= 60,
	EFF_TARGET_AREAEFFECT_PARTY_AND_CLASS				= 61,
	EFF_TARGET_PRIEST_CHAMPION							= 62, //wtf ?
	EFF_TARGET_NATURE_SUMMON_LOCATION					= 63, 
	EFF_TARGET_BEHIND_TARGET_LOCATION					= 65, 
	EFF_TARGET_MULTIPLE_GUARDIAN_SUMMON_LOCATION			= 72,
	EFF_TARGET_NETHETDRAKE_SUMMON_LOCATION				= 73,
	EFF_TARGET_SCRIPTED_LOCATION							= 74,
	EFF_TARGET_LOCATION_INFRONT_CASTER_AT_RANGE			= 75,
	EFF_TARGET_ENEMYS_IN_ARE_CHANNELED_WITH_EXCEPTIONS	= 76,
	EFF_TARGET_SELECTED_ENEMY_CHANNELED					= 77,
	EFF_TARGET_SELECTED_ENEMY_DEADLY_POISON				= 86,
	EFF_TARGET_CREATURE									= 87,
} SpellEffectTarget;


enum Attributes
{
	ATTRIBUTES_NULL								= 0x0,
	ATTRIBUTES_UNK2								= 0x1,
	ATTRIBUTES_UNK3								= 0x2, // related to ranged??
	ATTRIBUTE_ON_NEXT_ATTACK					= 0x4,
	ATTRIBUTES_UNUSED0							= 0x8,
	ATTRIBUTES_UNK6								= 0x10,
	ATTRIBUTES_UNK7								= 0x20, // Tradeskill recipies
	ATTRIBUTES_PASSIVE							= 0x40,
	ATTRIBUTES_NO_VISUAL_AURA					= 0x80,
	ATTRIBUTES_UNK10							= 0x100,	//seems to be afflicts pet
	ATTRIBUTES_UNK11							= 0x200, // looks like temp enchants.
	ATTRIBUTES_UNK12							= 0x400, //completely the same as ATTRIBUTE_ON_NEXT_ATTACK for class spells. So difference somewhere in mob abilities.
	ATTRIBUTES_UNK13							= 0x800,
	ATTRIBUTES_UNUSED1							= 0x1000,
	ATTRIBUTES_UNUSED2							= 0x2000,
	ATTRIBUTES_UNUSED3							= 0x4000,
	ATTRIBUTES_ONLY_OUTDOORS					= 0x8000,
	ATTRIBUTES_UNK								= 0x10000,
	ATTRIBUTES_REQ_STEALTH						= 0x20000,
	ATTRIBUTES_UNK20							= 0x40000,//it's not : must be behind
	ATTRIBUTES_UNK21							= 0x80000,
	ATTRIBUTES_STOP_ATTACK						= 0x100000,//switch off auto attack on use. Maim,Gouge,Disengage,Polymorph etc
	ATTRIBUTES_CANT_BE_DPB				    	= 0x200000,//can't be dodged, blocked, parried
	ATTRIBUTES_UNK24							= 0x400000, // related to ranged
	ATTRIBUTES_UNK25							= 0x800000,
	ATTRIBUTES_MOUNT_CASTABLE					= 0x1000000, //castable on mounts
	ATTRIBUTES_TRIGGER_COOLDOWN			        = 0x2000000, //also requires atributes ex = 32 ?
	ATTRIBUTES_UNK28							= 0x4000000,
	ATTRIBUTES_UNK29							= 0x8000000,
	ATTRIBUTES_REQ_OOC							= 0x10000000, //     ATTRIBUTES_REQ_OUT_OF_COMBAT
	ATTRIBUTES_IGNORE_INVULNERABILITY           = 0x20000000, //debuffs that can't be removed by any spell and spells that can't be resisted in any case
	ATTRIBUTES_UNK32							= 0x40000000, // seems like IS_DIMINISHING but some spells not there (f.e. Gouge)
};

enum AttributesEx
{
	ATTRIBUTESEX_NULL                         = 0x0, // 0
	ATTRIBUTESEX_UNK2                         = 0x1, // 1, pet summonings
	ATTRIBUTESEX_DRAIN_WHOLE_MANA             = 0x2, // 2
	ATTRIBUTESEX_UNK4                         = 0x4, // 3
	ATTRIBUTESEX_UNK5                         = 0x8, // 4
	ATTRIBUTESEX_UNK6                         = 0x10, // 5, stealth effects but Rockbiter wtf 0_0
	ATTRIBUTESEX_NOT_BREAK_STEALTH            = 0x20, // 6
	ATTRIBUTESEX_UNK8							= 0x40, // 7 [POSSIBLY: dynamite, grenades from engineering etc..]
	ATTRIBUTESEX_UNK9                         = 0x80,
	ATTRIBUTESEX_UNK10                        = 0x100,
	ATTRIBUTESEX_UNK11                        = 0x200,
	ATTRIBUTESEX_UNK12                        = 0x400,
	ATTRIBUTESEX_UNK13                        = 0x800,
	ATTRIBUTESEX_UNK14                        = 0x1000, // related to pickpocket
	ATTRIBUTESEX_UNK15                        = 0x2000, // related to remote control
	ATTRIBUTESEX_UNK16                        = 0x4000,
	ATTRIBUTESEX_UNK17                        = 0x8000, // something like "grant immunity"
	ATTRIBUTESEX_UNK18                        = 0x10000, // something like "grant immunity" too
	ATTRIBUTESEX_REMAIN_OOC                   = 0x20000,
	ATTRIBUTESEX_UNK20                        = 0x40000,
	ATTRIBUTESEX_UNK21                        = 0x80000,
	ATTRIBUTESEX_UNK22                        = 0x100000, // related to "Finishing move" and "Instantly overpowers"
	ATTRIBUTESEX_UNK23                        = 0x200000,
	ATTRIBUTESEX_UNK24                        = 0x400000, // only related to "Finishing move"
	ATTRIBUTESEX_UNK25                        = 0x800000, // related to spells like "ClearAllBuffs"
	ATTRIBUTESEX_UNK26                        = 0x1000000, // FISHING SPELLS
	ATTRIBUTESEX_UNK27                        = 0x2000000, // related to "Detect" spell
	ATTRIBUTESEX_UNK28                        = 0x4000000,
	ATTRIBUTESEX_UNK29                        = 0x8000000,
	ATTRIBUTESEX_UNK30                        = 0x10000000,
	ATTRIBUTESEX_UNK31                        = 0x20000000,
	ATTRIBUTESEX_UNK32                        = 0x40000000, // Overpower
};


struct SpellCastTargets
{

	SpellCastTargets() : m_targetMask(0), m_unitTarget(0), m_itemTarget(0), m_srcX(0), m_srcY(0), m_srcZ(0),
		m_destX(0), m_destY(0), m_destZ(0) {}

	SpellCastTargets(uint16 TargetMask, uint64 unitTarget, uint64 itemTarget, float srcX, float srcY,
		float srcZ, float destX, float destY, float destZ) : m_targetMask(TargetMask), m_unitTarget(unitTarget),
		m_itemTarget(itemTarget), m_srcX(srcX), m_srcY(srcY), m_srcZ(srcZ), m_destX(destX), m_destY(destY), m_destZ(destZ) {}

	SpellCastTargets(uint64 unitTarget) : m_targetMask(0x2), m_unitTarget(unitTarget), m_itemTarget(0),
		m_srcX(0), m_srcY(0), m_srcZ(0), m_destX(0), m_destY(0), m_destZ(0) {}

	SpellCastTargets(CPacketUsn& cpu, uint64 caster) : m_targetMask(0), m_unitTarget(0), m_itemTarget(0), m_srcX(0), m_srcY(0), m_srcZ(0),
		m_destX(0), m_destY(0), m_destZ(0)
	{
		cpu >> *this;
	}

	uint32 m_targetMask;
	uint64 m_unitTarget;
	uint64 m_itemTarget;
	float m_srcX, m_srcY, m_srcZ;
	float m_destX, m_destY, m_destZ;
	std::string m_strTarget;
	CPacketSn& Sn(CPacketSn& cps) const 
	{	
		cps << m_targetMask;
		if( m_targetMask & TARGET_FLAG_SELF )
		{
			cps << m_unitTarget;
		}

		if( m_targetMask & (TARGET_FLAG_OBJECT | TARGET_FLAG_UNIT | TARGET_FLAG_CORPSE | TARGET_FLAG_CORPSE2 ) )
		{
			cps << m_unitTarget;
		}

		if( m_targetMask & ( TARGET_FLAG_ITEM | TARGET_FLAG_TRADE_ITEM ) )
		{
			cps << m_itemTarget;
		}

		if( m_targetMask & TARGET_FLAG_SOURCE_LOCATION )
		{
			cps << m_srcX << m_srcY << m_srcZ;
		}

		if( m_targetMask & TARGET_FLAG_DEST_LOCATION )
		{
			cps << m_destX << m_destY << m_destZ << m_unitTarget;
		}

		if( m_targetMask & TARGET_FLAG_STRING )
		{
			cps << m_strTarget;
		}
		return cps;
	}
	CPacketUsn& Usn(CPacketUsn& cpu)	
	{	
		cpu >> m_targetMask;
		if( m_targetMask & TARGET_FLAG_SELF )
		{
			cpu >> m_unitTarget;
		}

		if( m_targetMask & (TARGET_FLAG_OBJECT | TARGET_FLAG_UNIT | TARGET_FLAG_CORPSE | TARGET_FLAG_CORPSE2 ) )
		{
			cpu >> m_unitTarget;
		}

		if( m_targetMask & ( TARGET_FLAG_ITEM | TARGET_FLAG_TRADE_ITEM ) )
		{
			cpu >> m_itemTarget;
		}

		if( m_targetMask & TARGET_FLAG_SOURCE_LOCATION )
		{
			cpu >> m_srcX >> m_srcY >> m_srcZ;

			if( !( m_targetMask & TARGET_FLAG_DEST_LOCATION ) )
			{
				m_destX = m_srcX;
				m_destY = m_srcY;
				m_destZ = m_srcZ;
			}
		}

		if( m_targetMask & TARGET_FLAG_DEST_LOCATION )
		{
			cpu >> m_destX >> m_destY >> m_destZ >> m_unitTarget;
			if( !( m_targetMask & TARGET_FLAG_SOURCE_LOCATION ) )
			{
				m_srcX = m_destX;
				m_srcY = m_destY;
				m_srcZ = m_destZ;
			}
		}

		if( m_targetMask & TARGET_FLAG_STRING )
		{
			cpu >> m_strTarget;
		}
		return cpu; 
	}

	SpellCastTargets& operator=(const SpellCastTargets &target)
	{
		m_unitTarget = target.m_unitTarget;
		m_itemTarget = target.m_itemTarget;

		m_srcX = target.m_srcX;
		m_srcY = target.m_srcY;
		m_srcZ = target.m_srcZ;

		m_destX = target.m_destX;
		m_destY = target.m_destY;
		m_destZ = target.m_destZ;

		m_strTarget = target.m_strTarget;

		m_targetMask = target.m_targetMask;

		return *this;
	}
};

#endif