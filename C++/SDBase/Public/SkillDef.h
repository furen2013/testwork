#ifndef _SKILLDEF_H
#define _SKILLDEF_H
#include "../Public/TypeDef.h"
#include "../Protocol/PacketDef.h"

struct FishingZoneEntry
{
	uint32 ZoneID;
	uint32 MinSkill;
	uint32 MaxSkill;
};

struct ZoneGuardEntry
{
	uint32 ZoneID;
	uint32 HordeEntry;
	uint32 AllianceEntry;
};

#define SKILL_FROST                     6
#define SKILL_FIRE                      8
#define SKILL_ARMS                      26
#define SKILL_COMBAT                    38
#define SKILL_SUBTLETY                  39
#define SKILL_POISONS                   40
#define SKILL_SWORDS                    43
#define SKILL_AXES                      44
#define SKILL_BOWS                      45
#define SKILL_GUNS                      46
#define SKILL_BEAST_MASTERY             50
#define SKILL_SURVIVAL                  51
#define SKILL_MACES                     54
#define SKILL_2H_SWORDS                 55
#define SKILL_HOLY                      56
#define SKILL_SHADOW                    78
#define SKILL_DEFENSE                   95
#define SKILL_LANG_COMMON               98
#define SKILL_RACIAL_DWARVEN            101
#define SKILL_LANG_ORCISH               109
#define SKILL_LANG_DWARVEN              111
#define SKILL_LANG_DARNASSIAN           113
#define SKILL_LANG_TAURAHE              115
#define SKILL_DUAL_WIELD                42401
#define SKILL_RACIAL_TAUREN             124
#define SKILL_ORC_RACIAL                125
#define SKILL_RACIAL_NIGHT_ELF          126
#define SKILL_FIRST_AID                 129
#define SKILL_FERAL_COMBAT              134
#define SKILL_LANG_THALASSIAN           137
#define SKILL_STAVES                    136
#define SKILL_LANG_DRACONIC             138
#define SKILL_LANG_DEMON_TONGUE         139
#define SKILL_LANG_TITAN                140
#define SKILL_LANG_OLD_TONGUE           141
#define SKILL_SURVIVAL2                 142
#define SKILL_RIDING_HORSE              148
#define SKILL_RIDING_WOLF               149
#define SKILL_RIDING_RAM                152
#define SKILL_RIDING_TIGER              150
#define SKILL_SWIMING                   155
#define SKILL_2H_MACES                  160
#define SKILL_UNARMED                   162
#define SKILL_MARKSMANSHIP              163
#define SKILL_BLACKSMITHING             164
#define SKILL_LEATHERWORKING            165
#define SKILL_ALCHEMY                   171
#define SKILL_2H_AXES                   172
#define SKILL_DAGGERS                   173
#define SKILL_THROWN                    176
#define SKILL_HERBALISM                 182
#define SKILL_GENERIC_DND               183
#define SKILL_RETRIBUTION               184
#define SKILL_COOKING                   185
#define SKILL_MINING                    186
#define SKILL_PET_IMP                   188
#define SKILL_PET_FELHUNTER             189
#define SKILL_TAILORING                 197
#define SKILL_ENGINERING                202
#define SKILL_PET_SPIDER                203
#define SKILL_PET_VOIDWALKER            204
#define SKILL_PET_SUCCUBUS              205
#define SKILL_PET_INFERNAL              206
#define SKILL_PET_DOOMGUARD             207
#define SKILL_PET_WOLF                  208
#define SKILL_PET_CAT                   209
#define SKILL_PET_BEAR                  210
#define SKILL_PET_BOAR                  211
#define SKILL_PET_CROCILISK             212
#define SKILL_PET_CARRION_BIRD          213
#define SKILL_PET_GORILLA               215
#define SKILL_PET_CRAB                  214
#define SKILL_PET_RAPTOR                217
#define SKILL_PET_TALLSTRIDER           218
#define SKILL_RACIAL_UNDED              220
#define SKILL_CROSSBOWS                 226
#define SKILL_SPEARS                    227
#define SKILL_WANDS                     228
#define SKILL_POLEARMS                  229
#define SKILL_ATTRIBUTE_ENCHANCEMENTS   230
#define SKILL_SLAYER_TALENTS            231
#define SKILL_MAGIC_TALENTS             233
#define SKILL_DEFENSIVE_TALENTS         234
#define SKILL_PET_SCORPID               236
#define SKILL_ARCANE                    237
#define SKILL_PET_TURTLE                251
#define SKILL_FURY                      256
#define SKILL_PROTECTION                257
#define SKILL_BEAST_TRAINING            261
#define SKILL_PROTECTION2               267
#define SKILL_PET_TALENTS               270
#define SKILL_PLATE_MAIL                293
#define SKILL_ASSASSINATION             253
#define SKILL_LANG_GNOMISH              313
#define SKILL_LANG_TROLL                315
#define SKILL_ENCHANTING                333
#define SKILL_DEMONOLOGY                354
#define SKILL_AFFLICTION                355
#define SKILL_FISHING                   356
#define SKILL_ENHANCEMENT               373
#define SKILL_RESTORATION               374
#define SKILL_ELEMENTAL_COMBAT          375
#define SKILL_SKINNING                  393
#define SKILL_LEATHER                   414
#define SKILL_CLOTH                     415
#define SKILL_MAIL                      413
#define SKILL_SHIELD                    433
#define SKILL_FIST_WEAPONS              473
#define SKILL_TRACKING_BEAST            513
#define SKILL_TRACKING_HUMANOID         514
#define SKILL_TRACKING_DEMON            516
#define SKILL_TRACKING_UNDEAD           517
#define SKILL_TRACKING_DRAGON           518
#define SKILL_TRACKING_ELEMENTAL        519
#define SKILL_RIDING_RAPTOR             533
#define SKILL_RIDING_MECHANOSTRIDER     553
#define SKILL_RIDING_UNDEAD_HORSE       554
#define SKILL_RESTORATION2              573
#define SKILL_BALANCE                   574
#define SKILL_DESTRUCTION               593
#define SKILL_HOLY2                     594
#define SKILL_DISCIPLINE                613
#define SKILL_LOCKPICKING               633
#define SKILL_PET_BAT                   653
#define SKILL_PET_HYENA                 654
#define SKILL_PET_OWL                   655
#define SKILL_PET_WIND_SERPENT          656
#define SKILL_LANG_GUTTERSPEAK          673
#define SKILL_RIDING_KODO               713
#define SKILL_RACIAL_TROLL              733
#define SKILL_RACIAL_GNOME              753
#define SKILL_RACIAL_HUMAN              754
#define SKILL_JEWELCRAFTING             755
#define SKILL_RACIAL_BLOODELF           756
#define SKILL_PET_EVENT_REMOTECONTROL   758
#define SKILL_LANG_DRAENEI              759
#define SKILL_DRAENEI_RACIAL            760
#define SKILL_PET_FELGUARD              761
#define SKILL_RIDING                    762
#define SKILL_PET_DRAGONHAWK            763
#define SKILL_PET_NETHER_RAY            764
#define SKILL_PET_SPOREBAT              765
#define SKILL_PET_WARP_STALKER          766
#define SKILL_PET_RAVAGER               767
#define SKILL_PET_SERPENT               768
#define SKILL_INTERNAL                  769

#define SKILL_TYPE_ATTRIBUTES           5
#define SKILL_TYPE_WEAPON               6
#define SKILL_TYPE_CLASS                7
#define SKILL_TYPE_ARMOR                8
#define SKILL_TYPE_SECONDARY            9
#define SKILL_TYPE_LANGUAGE             10
#define SKILL_TYPE_PROFESSION           11
#define SKILL_TYPE_NA                   12

typedef struct
{
	uint8 itemclass;
	uint32 subclass;
} ItemProf;

const ItemProf* GetProficiencyBySkill(uint32 skill);

enum MECHANICS
{
	MECHANIC_CHARMED = 1,
	MECHANIC_DISORIENTED, // 2
	MECHANIC_DISARMED, // 3
	MECHANIC_DISTRACED, // 4
	MECHANIC_FLEEING, // 5
	MECHANIC_CLUMSY, // 6
	MECHANIC_ROOTED, // 7
	MECHANIC_PACIFIED, // 8
	MECHANIC_SILENCED, // 9
	MECHANIC_ASLEEP, // 10
	MECHANIC_ENSNARED, // 11
	MECHANIC_STUNNED, // 12
	MECHANIC_FROZEN, // 13
	MECHANIC_INCAPACIPATED, // 14
	MECHANIC_BLEEDING, // 15
	MECHANIC_HEALING, // 16
	MECHANIC_POLYMORPHED, // 17
	MECHANIC_BANISHED, // 18
	MECHANIC_SHIELDED, // 19
	MECHANIC_SHACKLED, // 20
	MECHANIC_MOUNTED, // 21
	MECHANIC_SEDUCED, // 22
	MECHANIC_TURNED, // 23
	MECHANIC_HORRIFIED, // 24
	MECHANIC_INVULNARABLE, // 25
	MECHANIC_INTERRUPTED, // 26
	MECHANIC_DAZED, // 27
	MECHANIC_UNK1, // 28, fill in please
	MECHANIC_UNK2, // 29, fill in please
	MECHANIC_SAPPED, // 30,
	MECHANIC_TAUNT,
	MECHANIC_MAX
};


#endif


/*
//
//	常量定义
//
typedef enum
{
	SKILL_NAME_MAX	= 32,
	SKILL_DESC_MAX	= 256,
};
//
//	主分类定义——技能主类型
//
typedef enum
{
	STP_INVALID = 0,		//	非法值
	STP_ATTACK = 1,		
	STP_DEFENSE = 2,	
	STP_STATE = 3,	
	STP_EXPENDABLE = 4,		
	STP_SUMMON = 5,
}SKILL_TYPE_PRIMARY;



#define MAX_SKILL_TYPE               770};
//
//////////////////////////////////////////////////////////////////////////
enum tagUseSkillResult
{
	SKILL_USE_RESULT_BEGIN,						//##表示条件满足，开始使用技能
	SKILL_USE_RESULT_SUCCEEDED,
	SKILL_USE_RESULT_FAILED,
	SKILL_USE_RESULT_END,						//##施法结束
	SKILL_USE_RESULT_INVALID_STATE,				//##当前状态不能使用技能，比如被麻痹
	SKILL_USE_RESULT_INVALID_CONDITION,
	SKILL_USE_RESULT_INVALID_HP,
	SKILL_USE_RESULT_INVALID_MP,
	SKILL_USE_RESULT_INVALID_RP,
	SKILL_USE_RESULT_INVALID_YP,
	SKILL_USE_RESULT_INVALID_TARGET,
	SKILL_USE_RESULT_INVALID_DISTANT,
	SKILL_USE_RESULT_INVALID_SKILL,
	SKILL_USE_RESULT_INVALID_TIME,				//##允许再次使用技能的时间未到达
	SKILL_USE_RESULT_INVALID_EQUIP,				//##无效的装备
	SKILL_USE_RESULT_BLOCKED,					//##被阻挡了
};

enum tagDamageType
{
	DAMAGE_TYPE_HP,
	DAMAGE_TYPE_MP,
};

typedef enum tagSkillTargetType
{
	STT_INVALID		= 0,
	STT_SINGLEOBJ			= 1,
	STT_AREA		= 2,
	STT_ALL			= 3,
	STT_AREA_POINT	= 4,
	STT_AREA_LINE	= 5,
	STT_AREA_QUAD	= 6,
	STT_AREA_ROUND	= 7,
	STT_AREA_FAN	= 8,
}STT_TYPE;

typedef enum tagSkillTargetRelative
{
	STR_INVALID		= 0,
	STR_ENEMY		= 1,
	STR_FRIEND		= 2,
}STR_TYPE;

typedef enum tagSkillStep
{
	SS_INVALID		= 0,
}SS_STATE;

typedef union
{
	struct  
	{						
		ui16	typeid_2;		//	分类内Index		smallint
		ui16	typeid_1;		//	主分类			smallint		对应 SKILL_TYPE_PRIMARY
	}	sep_val;
	ui32	com_val;
}SKILL_ID;

typedef union
{
	struct  
	{						
		ui16	typeid_2;		//	分类内Index		smallint
		ui16	typeid_1;		//	主分类			smallint		对应 SKILL_TYPE_PRIMARY
	}	sep_val;
	ui32	com_val;
}BUF_ID;

typedef struct tagSkillType
{
	bool ReadRecord(const char *Buff);
	ui32	type_id;
	string	szName;

//	WORD	wLevel;									//技能等级
	ui8		nDemageType;
	ui8		nTargetType;
	ui8		nTargetRelative;

	ui8		nDamageCalcMethod;			// 伤害计算方式
	ui16	nAddtiveFlags;				// 
	ui16	nAddtiveOdds;				// 附加几率.
	ui8		nHaveSpecialEffect;			// 是否有特殊攻击效果
	ui16	nSpecialEffectOdds;		// 特殊效果几率

	//char AttackAreaDesc[SKILL_TARGETAREA_DESC_MAX];	// 区域几何参数描述

	ui16	nHPCost;
	ui16	nMPCost;
	ui16	nHPCostPercent;							//消耗HP％
	ui16	nMPCostPercent;							//消耗MP％
	ui16	nXXCost;

	float	fMaxRange;								// 最大施法距离
	float	fMinRange;								// 最大施法距离

	ui16	nPrepareTime;							//	准备时间 S.
	ui16	nCDTime;								//	CD
	ui16	nFreezeTime;							//	释放后的僵直时间

	ui8		nDiscontinuousAttacking;				// 间断攻击(持续施法)
	ui16	nDiscontAttackBrokenCondition;			// 间断攻击打断方式
	ui16	nDiscontAttackLoopNum;					// 间断攻击循环次数
	ui32	nDiscontAttackCycle;						// 间断攻击周期 ms

	ui16	Faction;								// 派别
	ui16	LevelReq;								// 等级
	ui32 	Weapon;									// 武器
	float	ReleaseAngle;							// 释放角度
	ui8 	Valid;									// 是否有效

	//toadd?
	ui16	wHate;									//产生的仇恨
	SKILL_ID	nPreSkill;							//前置技能需求
	BUF_ID	nAddBuf;							//技能附加状态

	ui16	nMagicHurtMax;							//技能对攻击加成随机的大值
	ui16	nMagicHurtMin;							//技能对攻击加成随机的小值

	//ui16	wMaxlength;								//最大施法距离
	//ui16	wMinlength;								//最小施法距离
	//ui16	wAngle;									//技能释放角度
	//ui16	wCooldown;								//技能冷却时间
	//ui16	wNatureType;							//技能元素属性 金木水火土电

	//ui16	wMotionID;								//技能动作ID
	//char	szMotion[21];							//技能动作名字
	//char	szReleaseVison[41];						//施法效果
	//char	szFlyVision[41];						//飞行效果
	//char	szHitVision[41];						//命中效果
	//BYTE	byHurtType;								//技能命中对象
	//BYTE	byMagicStateLevel;						//技能附加状态等级
	//BYTE	byMagicStatePercent;					//技能附加状态几率
	//WORD	wMagicStateReleased;					//技能解除状态
	//WORD	wTmFreeze;								//技能僵硬时间
	//WORD	wTmMotion;								//技能动作播放时间
	//BYTE	byPassivity;							//技能是否为被动
	//BYTE	byPlayerLevel;							//技能学习等级
	//BYTE	byJob;									//技能学习职业需求
	//BYTE	byShape;								//技能释放类型
	//BYTE	byMaxAims;								//最大目标个数
	//BYTE	byRadius;								//范围技能半径
	//BYTE	byNeedItem;								//需要武器

	CPacketSn& Sn(CPacketSn& cps) const {cps << type_id << szName << nDemageType << nTargetType << nTargetRelative
		<< nDamageCalcMethod << nAddtiveFlags << nAddtiveOdds << nHaveSpecialEffect << nSpecialEffectOdds
		<< nHPCost << nMPCost << nHPCostPercent << nMPCostPercent << nXXCost ; return cps;}
	CPacketUsn& Usn(CPacketUsn& cpu) {cpu >> type_id >> szName >> nDemageType >> nTargetType >> nTargetRelative
		>> nDamageCalcMethod >> nAddtiveFlags >> nAddtiveOdds >> nHaveSpecialEffect >> nSpecialEffectOdds
		>> nHPCost >> nMPCost >> nHPCostPercent >> nMPCostPercent >> nXXCost ; return cpu;}
}SKILL_TYPE,*PSKILL_TYPE;

typedef struct tagSkillType_C : public tagSkillType
{
	char	szDesc[SKILL_DESC_MAX];
	ui32	nIcon;
	char	TargetSelBrush[128];

	char 	Icon[128];								// 技能图标
	char 	PrepareAnim[128];						// 吟唱动作
	char 	PrepareEffect[128];						// 吟唱特效
	char 	ReleaseAnim[128];						// 释放/攻击动作
	char 	ReleaseEffect[128];						// 释放/攻击特效
	ui16	ReleaseEffectLife;						// 释放特效播放时间
	//BYTE NumReleaseSerial;							
	char 	TrackAnim[128];							// 轨迹动作
	char 	HitAnim[128];							// 被击动作
	char 	HitEffect[128];							// 被击特效

	ui8		TargetSelectionFlag;		// 目标选中标记
	ui8		TargetAreaFlag;				// 目标区域标记

}SKILL_TYPE_C,*PSKILL_TYPE_C;

//////////////////////////////////////////////////////////////////////////
//tagSkillData服务端使用,用来描述一个存在的技能对象
typedef struct tagSkillData
{
	bool FromMagic(class CSkill* pMagic, ui32 dwNow);
	ui32	type_id;
	ui8		m_byLevel;
	ui16	m_wCurrPoint;
	ui16	m_wCooldown;

	ui8		nStep;

	CPacketSn& Sn(CPacketSn& cps) const {cps << type_id << m_byLevel << m_wCurrPoint << m_wCooldown << nStep; return cps;}
	CPacketUsn& Usn(CPacketUsn& cpu) {cpu >> type_id >> m_byLevel >> m_wCurrPoint >> m_wCooldown >> nStep; return cpu;}

}SKILL_DATA,*PSKILL_DATA;
//
//////////////////////////////////////////////////////////////////////////


typedef struct tagBufType
{
	bool ReadRecord(const char *Buff);

	BUF_ID	type_id;

	char	szName[21];		//状态名称
	ui8	byLevel;				//状态等级
	ui8	byFavor;				//是否有利状态
	char	szVision[41];			//状态持续特效
	ui8	byTmLast;				//状态持续时间
	ui8	byTmIntervel;			//状态间隔时间
	ui8	byType;					//状态类型
	ui8	byPileup;				//可否叠加
	ui8	byReleaseAuto;			//受攻击时是否解除
	ui8	byPower;				//增加力量
	ui8	byStrength;				//增加强壮
	ui8	byIntelligence;			//增加智力
	ui8	byBodyQuality;			//增加体质
	ui8	byCharm;				//增加法力
	ui8	byDefence;				//物理防御增加
	ui8	byAttack;				//物理攻击增加
	ui8	byDefenceMagic;			//法术攻击增加
	ui8	byFireDefence;			//火伤害吸收
	ui8	byIceDefence;			//冰伤害吸收
	ui8	byElecDefence;			//电伤害吸收
	ui8	byPoisonDefence;		//毒伤害吸收
	ui8	byHit;					//命中增加
	ui8	byAvoid;				//闪避增加
	ui8	byBurst;				//暴击率
	ui8	byAttackRate;			//攻击速度
	ui8	byMoveRate;				//移动速度
	ui8	byHP;					//生命值增加
	ui8	byMP;					//法术值增加
	ui8	byHPRenew;				//生命恢复增加
	ui8	byMPRenew;				//法术恢复增加
	ui8	byProtect;				//格档值增加
	ui8	byProtectPercent;		//格档率增加
	ui8	wExperience;			//经验值增加％
	ui8	bySpecialState;			//特殊状态
	ui8	byColor;				//状态颜色
	ui8	byKeepAfterDied;		//死亡后是否清除

}BUF_TYPE,*PBUF_TYPE;

typedef struct tagBufData
{
	BUF_ID	type_id;
}BUF_DATA,*PBUF_DATA;


enum SpellSchools
{
	SPELL_SCHOOL_NORMAL                 = 0,
	SPELL_SCHOOL_HOLY                   = 1,
	SPELL_SCHOOL_FIRE                   = 2,
	SPELL_SCHOOL_NATURE                 = 3,
	SPELL_SCHOOL_FROST                  = 4,
	SPELL_SCHOOL_SHADOW                 = 5,
	SPELL_SCHOOL_ARCANE                 = 6
};

#define MAX_SPELL_SCHOOL                  7

enum SpellSchoolMask
{
	SPELL_SCHOOL_MASK_NONE    = 0x00,                       // not exist
	SPELL_SCHOOL_MASK_NORMAL  = (1 << SPELL_SCHOOL_NORMAL), // PHYSICAL (Armor)
	SPELL_SCHOOL_MASK_HOLY    = (1 << SPELL_SCHOOL_HOLY  ),
	SPELL_SCHOOL_MASK_FIRE    = (1 << SPELL_SCHOOL_FIRE  ),
	SPELL_SCHOOL_MASK_NATURE  = (1 << SPELL_SCHOOL_NATURE),
	SPELL_SCHOOL_MASK_FROST   = (1 << SPELL_SCHOOL_FROST ),
	SPELL_SCHOOL_MASK_SHADOW  = (1 << SPELL_SCHOOL_SHADOW),
	SPELL_SCHOOL_MASK_ARCANE  = (1 << SPELL_SCHOOL_ARCANE)
};

#define SPELL_SCHOOL_MASK_MAGIC                            \
	( SPELL_SCHOOL_MASK_FIRE | SPELL_SCHOOL_MASK_NATURE |  \
	SPELL_SCHOOL_MASK_FROST | SPELL_SCHOOL_MASK_SHADOW | \
	SPELL_SCHOOL_MASK_ARCANE )

inline SpellSchools GetFirstSchoolInMask(SpellSchoolMask mask)
{
	for(int i = 0; i < MAX_SPELL_SCHOOL; ++i)
		if(mask & (1 << i))
			return SpellSchools(i);

	return SPELL_SCHOOL_NORMAL;
}

#define MAX_AURAS 56
#define MAX_POSITIVE_AURAS 40

enum AURA_FLAGS
{
	AFLAG_NEGATIVE          = 0x09,
	AFLAG_POSITIVE          = 0x1F,
	AFLAG_MASK              = 0xFF
};

//m_schoolAbsorb
enum DAMAGE_ABSORB_TYPE
{
	ALL_DAMAGE_ABSORB       = -2,
	ONLY_MAGIC_ABSORB       = -1,
};

enum AuraType
{
	SPELL_AURA_NONE = 0,
	SPELL_AURA_BIND_SIGHT = 1,
	SPELL_AURA_MOD_POSSESS = 2,
	SPELL_AURA_PERIODIC_DAMAGE = 3,
	SPELL_AURA_DUMMY = 4,
	SPELL_AURA_MOD_CONFUSE = 5,
	SPELL_AURA_MOD_CHARM = 6,
	SPELL_AURA_MOD_FEAR = 7,
	SPELL_AURA_PERIODIC_HEAL = 8,
	SPELL_AURA_MOD_ATTACKSPEED = 9,
	SPELL_AURA_MOD_THREAT = 10,
	SPELL_AURA_MOD_TAUNT = 11,
	SPELL_AURA_MOD_STUN = 12,
	SPELL_AURA_MOD_DAMAGE_DONE = 13,
	SPELL_AURA_MOD_DAMAGE_TAKEN = 14,
	SPELL_AURA_DAMAGE_SHIELD = 15,
	SPELL_AURA_MOD_STEALTH = 16,
	SPELL_AURA_MOD_DETECT = 17,
	SPELL_AURA_MOD_INVISIBILITY = 18,
	SPELL_AURA_MOD_INVISIBILITY_DETECTION = 19,
	SPELL_AURA_OBS_MOD_HEALTH = 20,                         //20,21 unofficial
	SPELL_AURA_OBS_MOD_MANA = 21,
	SPELL_AURA_MOD_RESISTANCE = 22,
	SPELL_AURA_PERIODIC_TRIGGER_SPELL = 23,
	SPELL_AURA_PERIODIC_ENERGIZE = 24,
	SPELL_AURA_MOD_PACIFY = 25,
	SPELL_AURA_MOD_ROOT = 26,
	SPELL_AURA_MOD_SILENCE = 27,
	SPELL_AURA_REFLECT_SPELLS = 28,
	SPELL_AURA_MOD_STAT = 29,
	SPELL_AURA_MOD_SKILL = 30,
	SPELL_AURA_MOD_INCREASE_SPEED = 31,
	SPELL_AURA_MOD_INCREASE_MOUNTED_SPEED = 32,
	SPELL_AURA_MOD_DECREASE_SPEED = 33,
	SPELL_AURA_MOD_INCREASE_HEALTH = 34,
	SPELL_AURA_MOD_INCREASE_ENERGY = 35,
	SPELL_AURA_MOD_SHAPESHIFT = 36,
	SPELL_AURA_EFFECT_IMMUNITY = 37,
	SPELL_AURA_STATE_IMMUNITY = 38,
	SPELL_AURA_SCHOOL_IMMUNITY = 39,
	SPELL_AURA_DAMAGE_IMMUNITY = 40,
	SPELL_AURA_DISPEL_IMMUNITY = 41,
	SPELL_AURA_PROC_TRIGGER_SPELL = 42,
	SPELL_AURA_PROC_TRIGGER_DAMAGE = 43,
	SPELL_AURA_TRACK_CREATURES = 44,
	SPELL_AURA_TRACK_RESOURCES = 45,
	SPELL_AURA_MOD_PARRY_SKILL = 46,
	SPELL_AURA_MOD_PARRY_PERCENT = 47,
	SPELL_AURA_MOD_DODGE_SKILL = 48,
	SPELL_AURA_MOD_DODGE_PERCENT = 49,
	SPELL_AURA_MOD_BLOCK_SKILL = 50,
	SPELL_AURA_MOD_BLOCK_PERCENT = 51,
	SPELL_AURA_MOD_CRIT_PERCENT = 52,
	SPELL_AURA_PERIODIC_LEECH = 53,
	SPELL_AURA_MOD_HIT_CHANCE = 54,
	SPELL_AURA_MOD_SPELL_HIT_CHANCE = 55,
	SPELL_AURA_TRANSFORM = 56,
	SPELL_AURA_MOD_SPELL_CRIT_CHANCE = 57,
	SPELL_AURA_MOD_INCREASE_SWIM_SPEED = 58,
	SPELL_AURA_MOD_DAMAGE_DONE_CREATURE = 59,
	SPELL_AURA_MOD_PACIFY_SILENCE = 60,
	SPELL_AURA_MOD_SCALE = 61,
	SPELL_AURA_PERIODIC_HEALTH_FUNNEL = 62,
	SPELL_AURA_PERIODIC_MANA_FUNNEL = 63,
	SPELL_AURA_PERIODIC_MANA_LEECH = 64,
	SPELL_AURA_MOD_CASTING_SPEED = 65,
	SPELL_AURA_FEIGN_DEATH = 66,
	SPELL_AURA_MOD_DISARM = 67,
	SPELL_AURA_MOD_STALKED = 68,
	SPELL_AURA_SCHOOL_ABSORB = 69,
	SPELL_AURA_EXTRA_ATTACKS = 70,
	SPELL_AURA_MOD_SPELL_CRIT_CHANCE_SCHOOL = 71,
	SPELL_AURA_MOD_POWER_COST_SCHOOL_PCT = 72,
	SPELL_AURA_MOD_POWER_COST_SCHOOL = 73,
	SPELL_AURA_REFLECT_SPELLS_SCHOOL = 74,
	SPELL_AURA_MOD_LANGUAGE = 75,
	SPELL_AURA_FAR_SIGHT = 76,
	SPELL_AURA_MECHANIC_IMMUNITY = 77,
	SPELL_AURA_MOUNTED = 78,
	SPELL_AURA_MOD_DAMAGE_PERCENT_DONE = 79,
	SPELL_AURA_MOD_PERCENT_STAT = 80,
	SPELL_AURA_SPLIT_DAMAGE_PCT = 81,
	SPELL_AURA_WATER_BREATHING = 82,
	SPELL_AURA_MOD_BASE_RESISTANCE = 83,
	SPELL_AURA_MOD_REGEN = 84,
	SPELL_AURA_MOD_POWER_REGEN = 85,
	SPELL_AURA_CHANNEL_DEATH_ITEM = 86,
	SPELL_AURA_MOD_DAMAGE_PERCENT_TAKEN = 87,
	SPELL_AURA_MOD_HEALTH_REGEN_PERCENT = 88,
	SPELL_AURA_PERIODIC_DAMAGE_PERCENT = 89,
	SPELL_AURA_MOD_RESIST_CHANCE = 90,
	SPELL_AURA_MOD_DETECT_RANGE = 91,
	SPELL_AURA_PREVENTS_FLEEING = 92,
	SPELL_AURA_MOD_UNATTACKABLE = 93,
	SPELL_AURA_INTERRUPT_REGEN = 94,
	SPELL_AURA_GHOST = 95,
	SPELL_AURA_SPELL_MAGNET = 96,
	SPELL_AURA_MANA_SHIELD = 97,
	SPELL_AURA_MOD_SKILL_TALENT = 98,
	SPELL_AURA_MOD_ATTACK_POWER = 99,
	SPELL_AURA_AURAS_VISIBLE = 100,
	SPELL_AURA_MOD_RESISTANCE_PCT = 101,
	SPELL_AURA_MOD_MELEE_ATTACK_POWER_VERSUS = 102,
	SPELL_AURA_MOD_TOTAL_THREAT = 103,
	SPELL_AURA_WATER_WALK = 104,
	SPELL_AURA_FEATHER_FALL = 105,
	SPELL_AURA_HOVER = 106,
	SPELL_AURA_ADD_FLAT_MODIFIER = 107,
	SPELL_AURA_ADD_PCT_MODIFIER = 108,
	SPELL_AURA_ADD_TARGET_TRIGGER = 109,
	SPELL_AURA_MOD_POWER_REGEN_PERCENT = 110,
	SPELL_AURA_ADD_CASTER_HIT_TRIGGER = 111,
	SPELL_AURA_OVERRIDE_CLASS_SCRIPTS = 112,
	SPELL_AURA_MOD_RANGED_DAMAGE_TAKEN = 113,
	SPELL_AURA_MOD_RANGED_DAMAGE_TAKEN_PCT = 114,
	SPELL_AURA_MOD_HEALING = 115,
	SPELL_AURA_MOD_REGEN_DURING_COMBAT = 116,
	SPELL_AURA_MOD_MECHANIC_RESISTANCE = 117,
	SPELL_AURA_MOD_HEALING_PCT = 118,
	SPELL_AURA_SHARE_PET_TRACKING = 119,
	SPELL_AURA_UNTRACKABLE = 120,
	SPELL_AURA_EMPATHY = 121,
	SPELL_AURA_MOD_OFFHAND_DAMAGE_PCT = 122,
	SPELL_AURA_MOD_TARGET_RESISTANCE = 123,
	SPELL_AURA_MOD_RANGED_ATTACK_POWER = 124,
	SPELL_AURA_MOD_MELEE_DAMAGE_TAKEN = 125,
	SPELL_AURA_MOD_MELEE_DAMAGE_TAKEN_PCT = 126,
	SPELL_AURA_RANGED_ATTACK_POWER_ATTACKER_BONUS = 127,
	SPELL_AURA_MOD_POSSESS_PET = 128,
	SPELL_AURA_MOD_SPEED_ALWAYS = 129,
	SPELL_AURA_MOD_MOUNTED_SPEED_ALWAYS = 130,
	SPELL_AURA_MOD_RANGED_ATTACK_POWER_VERSUS = 131,
	SPELL_AURA_MOD_INCREASE_ENERGY_PERCENT = 132,
	SPELL_AURA_MOD_INCREASE_HEALTH_PERCENT = 133,
	SPELL_AURA_MOD_MANA_REGEN_INTERRUPT = 134,
	SPELL_AURA_MOD_HEALING_DONE = 135,
	SPELL_AURA_MOD_HEALING_DONE_PERCENT = 136,
	SPELL_AURA_MOD_TOTAL_STAT_PERCENTAGE = 137,
	SPELL_AURA_MOD_HASTE = 138,
	SPELL_AURA_FORCE_REACTION = 139,
	SPELL_AURA_MOD_RANGED_HASTE = 140,
	SPELL_AURA_MOD_RANGED_AMMO_HASTE = 141,
	SPELL_AURA_MOD_BASE_RESISTANCE_PCT = 142,
	SPELL_AURA_MOD_RESISTANCE_EXCLUSIVE = 143,
	SPELL_AURA_SAFE_FALL = 144,
	SPELL_AURA_CHARISMA = 145,
	SPELL_AURA_PERSUADED = 146,
	SPELL_AURA_ADD_CREATURE_IMMUNITY = 147,
	SPELL_AURA_RETAIN_COMBO_POINTS = 148,
	SPELL_AURA_RESIST_PUSHBACK  = 149,                      //    Resist Pushback
	SPELL_AURA_MOD_SHIELD_BLOCKVALUE_PCT = 150,
	SPELL_AURA_TRACK_STEALTHED  = 151,                      //    Track Stealthed
	SPELL_AURA_MOD_DETECTED_RANGE = 152,                    //    Mod Detected Range
	SPELL_AURA_SPLIT_DAMAGE_FLAT = 153,                     //    Split Damage Flat
	SPELL_AURA_MOD_STEALTH_LEVEL = 154,                     //    Stealth Level Modifier
	SPELL_AURA_MOD_WATER_BREATHING = 155,                   //    Mod Water Breathing
	SPELL_AURA_MOD_REPUTATION_GAIN = 156,                   //    Mod Reputation Gain
	SPELL_AURA_PET_DAMAGE_MULTI = 157,                      //    Mod Pet Damage
	SPELL_AURA_MOD_SHIELD_BLOCKVALUE = 158,
	SPELL_AURA_NO_PVP_CREDIT = 159,
	SPELL_AURA_MOD_AOE_AVOIDANCE = 160,
	SPELL_AURA_MOD_HEALTH_REGEN_IN_COMBAT = 161,
	SPELL_AURA_POWER_BURN_MANA = 162,
	SPELL_AURA_MOD_CRIT_DAMAGE_BONUS_MELEE = 163,
	SPELL_AURA_164 = 164,
	SPELL_AURA_MELEE_ATTACK_POWER_ATTACKER_BONUS = 165,
	SPELL_AURA_MOD_ATTACK_POWER_PCT = 166,
	SPELL_AURA_MOD_RANGED_ATTACK_POWER_PCT = 167,
	SPELL_AURA_MOD_DAMAGE_DONE_VERSUS = 168,
	SPELL_AURA_MOD_CRIT_PERCENT_VERSUS = 169,
	SPELL_AURA_DETECT_AMORE = 170,
	SPELL_AURA_MOD_SPEED_NOT_STACK = 171,
	SPELL_AURA_MOD_MOUNTED_SPEED_NOT_STACK = 172,
	SPELL_AURA_ALLOW_CHAMPION_SPELLS = 173,
	SPELL_AURA_MOD_SPELL_DAMAGE_OF_STAT_PERCENT = 174,      // by defeult intelect, dependent from SPELL_AURA_MOD_SPELL_HEALING_OF_STAT_PERCENT
	SPELL_AURA_MOD_SPELL_HEALING_OF_STAT_PERCENT = 175,
	SPELL_AURA_SPIRIT_OF_REDEMPTION = 176,
	SPELL_AURA_AOE_CHARM = 177,
	SPELL_AURA_MOD_DEBUFF_RESISTANCE = 178,
	SPELL_AURA_MOD_ATTACKER_SPELL_CRIT_CHANCE = 179,
	SPELL_AURA_MOD_FLAT_SPELL_DAMAGE_VERSUS = 180,
	SPELL_AURA_MOD_FLAT_SPELL_CRIT_DAMAGE_VERSUS = 181,     // unused - possible flat spell crit damage versus
	SPELL_AURA_MOD_RESISTANCE_OF_INTELLECT_PERCENT = 182,
	SPELL_AURA_MOD_CRITICAL_THREAT = 183,
	SPELL_AURA_MOD_ATTACKER_MELEE_HIT_CHANCE = 184,
	SPELL_AURA_MOD_ATTACKER_RANGED_HIT_CHANCE= 185,
	SPELL_AURA_MOD_ATTACKER_SPELL_HIT_CHANCE = 186,
	SPELL_AURA_MOD_ATTACKER_MELEE_CRIT_CHANCE = 187,
	SPELL_AURA_MOD_ATTACKER_RANGED_CRIT_CHANCE = 188,
	SPELL_AURA_MOD_RATING = 189,
	SPELL_AURA_MOD_FACTION_REPUTATION_GAIN = 190,
	SPELL_AURA_USE_NORMAL_MOVEMENT_SPEED = 191,
	SPELL_AURA_HASTE_MELEE = 192,
	SPELL_AURA_MELEE_SLOW = 193,
	SPELL_AURA_MOD_DEPRICATED_1  = 194,                     // not used now, old SPELL_AURA_MOD_SPELL_DAMAGE_OF_INTELLECT
	SPELL_AURA_MOD_DEPRICATED_2  = 195,                     // not used now, old SPELL_AURA_MOD_SPELL_HEALING_OF_INTELLECT
	SPELL_AURA_MOD_COOLDOWN = 196,                          // only 24818 Noxious Breath
	SPELL_AURA_MOD_ATTACKER_SPELL_AND_WEAPON_CRIT_CHANCE = 197,
	SPELL_AURA_MOD_ALL_WEAPON_SKILLS = 198,
	SPELL_AURA_MOD_INCREASES_SPELL_PCT_TO_HIT = 199,
	SPELL_AURA_MOD_XP_PCT = 200,
	SPELL_AURA_FLY = 201,
	SPELL_AURA_IGNORE_COMBAT_RESULT = 202,
	SPELL_AURA_MOD_ATTACKER_MELEE_CRIT_DAMAGE = 203,
	SPELL_AURA_MOD_ATTACKER_RANGED_CRIT_DAMAGE = 204,
	SPELL_AURA_205 = 205,                                   // unused
	SPELL_AURA_MOD_SPEED_MOUNTED = 206,                     // ? used in strange spells
	SPELL_AURA_MOD_INCREASE_FLIGHT_SPEED = 207,
	SPELL_AURA_MOD_SPEED_FLIGHT = 208,
	SPELL_AURA_MOD_FLIGHT_SPEED_ALWAYS = 209,
	SPELL_AURA_210 = 210,                                   // unused
	SPELL_AURA_MOD_FLIGHT_SPEED_NOT_STACK = 211,
	SPELL_AURA_MOD_RANGED_ATTACK_POWER_OF_STAT_PERCENT = 212,
	SPELL_AURA_MOD_RAGE_FROM_DAMAGE_DEALT = 213,
	SPELL_AURA_214 = 214,
	SPELL_AURA_ARENA_PREPARATION = 215,
	SPELL_AURA_HASTE_SPELLS = 216,
	SPELL_AURA_217 = 217,
	SPELL_AURA_HASTE_RANGED = 218,
	SPELL_AURA_MOD_MANA_REGEN_FROM_STAT = 219,
	SPELL_AURA_MOD_RATING_FROM_STAT = 220,
	SPELL_AURA_221 = 221,
	SPELL_AURA_222 = 222,
	SPELL_AURA_223 = 223,
	SPELL_AURA_224 = 224,
	SPELL_AURA_DUMMY_3 = 225,
	SPELL_AURA_PERIODIC_DUMMY = 226,
	SPELL_AURA_227 = 227,
	SPELL_AURA_DETECT_STEALTH = 228,
	SPELL_AURA_MOD_AOE_DAMAGE_AVOIDANCE = 229,
	SPELL_AURA_230 = 230,
	SPELL_AURA_231 = 231,
	SPELL_AURA_MECHANIC_DURATION_MOD = 232,
	SPELL_AURA_233 = 233,
	SPELL_AURA_MECHANIC_DURATION_MOD_NOT_STACK = 234,
	SPELL_AURA_MOD_DISPEL_RESIST = 235,
	SPELL_AURA_236 = 236,
	SPELL_AURA_MOD_SPELL_DAMAGE_OF_ATTACK_POWER = 237,
	SPELL_AURA_MOD_SPELL_HEALING_OF_ATTACK_POWER = 238,
	SPELL_AURA_MOD_SCALE_2 = 239,
	SPELL_AURA_MOD_EXPERTISE = 240,
	SPELL_AURA_241 = 241,
	SPELL_AURA_MOD_SPELL_DAMAGE_FROM_HEALING = 242,
	SPELL_AURA_243 = 243,
	SPELL_AURA_244 = 244,
	SPELL_AURA_MOD_DURATION_OF_MAGIC_EFFECTS = 245,
	SPELL_AURA_246 = 246,
	SPELL_AURA_247 = 247,
	SPELL_AURA_MOD_COMBAT_RESULT_CHANCE = 248,
	SPELL_AURA_249 = 249,
	SPELL_AURA_MOD_INCREASE_HEALTH_2 = 250,
	SPELL_AURA_MOD_ENEMY_DODGE = 251,
	TOTAL_AURAS=252
};

// Spell aura states
enum AuraState
{                                                           // (C) used in caster aurastate (T) used in target aura state
	AURA_STATE_DEFENSE                      = 1,            // C
	AURA_STATE_HEALTHLESS_20_PERCENT        = 2,            // CT
	AURA_STATE_RACE                         = 3,            // CT (?) FIX ME: not implemented yet!
	//AURA_STATE_UNKNOWN1                   = 4,            //    not used
	AURA_STATE_JUDGEMENT                    = 5,            // C
	//AURA_STATE_UNKNOWN2                   = 6,            //    not used
	AURA_STATE_HUNTER_PARRY                 = 7,            // C
	AURA_STATE_ROGUE_ATTACK_FROM_STEALTH    = 7,            // C  FIX ME: not implemented yet!
	//AURA_STATE_UNKNOWN3                   = 8,            //    not used
	//AURA_STATE_UNKNOWN4                   = 9,            //    not used
	AURA_STATE_WARRIOR_VICTORY_RUSH         = 10,           // C  warrior victory rush
	AURA_STATE_HUNTER_CRIT_STRIKE           = 10,           // C  hunter crit strike
	AURA_STATE_CRIT                         = 11,           // C
	//AURA_STATE_UNKNOWN6                   = 12,           //    not used
	AURA_STATE_HEALTHLESS_35_PERCENT        = 13,           // C
	AURA_STATE_IMMOLATE                     = 14,           //  T
	AURA_STATE_SWIFTMEND                    = 15,           //  T
	AURA_STATE_DEADLY_POISON                = 16            //  T
};


enum Targets
{
	TARGET_SELF                        = 1,
	TARGET_RANDOM_ENEMY_CHAIN_IN_AREA  = 2,                 // only one spell has that, but regardless, it's a target type after all
	TARGET_PET                         = 5,
	TARGET_CHAIN_DAMAGE                = 6,
	TARGET_AREAEFFECT_CUSTOM           = 8,
	TARGET_ALL_ENEMY_IN_AREA           = 15,
	TARGET_ALL_ENEMY_IN_AREA_INSTANT   = 16,
	TARGET_EFFECT_SELECT               = 18,                // highly depends on the spell effect
	TARGET_ALL_PARTY_AROUND_CASTER     = 20,
	TARGET_SINGLE_FRIEND               = 21,
	TARGET_ALL_AROUND_CASTER           = 22,                // used only in TargetA, target selection dependent from TargetB
	TARGET_GAMEOBJECT                  = 23,
	TARGET_IN_FRONT_OF_CASTER          = 24,
	TARGET_DUELVSPLAYER                = 25,
	TARGET_GAMEOBJECT_ITEM             = 26,
	TARGET_MASTER                      = 27,
	TARGET_ALL_ENEMY_IN_AREA_CHANNELED = 28,
	TARGET_ALL_FRIENDLY_UNITS_AROUND_CASTER = 30,           // in TargetB used only with TARGET_ALL_AROUND_CASTER and in self casting range in TargetA
	TARGET_MINION                      = 32,
	TARGET_ALL_PARTY                   = 33,
	TARGET_ALL_PARTY_AROUND_CASTER_2   = 34,                // used in Tranquility
	TARGET_SINGLE_PARTY                = 35,
	TARGET_AREAEFFECT_PARTY            = 37,
	TARGET_SCRIPT                      = 38,
	TARGET_SELF_FISHING                = 39,
	TARGET_TOTEM_EARTH                 = 41,
	TARGET_TOTEM_WATER                 = 42,
	TARGET_TOTEM_AIR                   = 43,
	TARGET_TOTEM_FIRE                  = 44,
	TARGET_CHAIN_HEAL                  = 45,
	TARGET_DYNAMIC_OBJECT              = 47,
	TARGET_AREAEFFECT_CUSTOM_2         = 52,
	TARGET_CURRENT_SELECTED_ENEMY      = 53,                // if used in A and B==16 then enemy and nearest enemies, in B no visible affect different from provided A
	TARGET_RANDOM_RAID_MEMBER          = 56,
	TARGET_SINGLE_FRIEND_2             = 57,
	TARGET_AREAEFFECT_PARTY_AND_CLASS  = 61,
	TARGET_SINGLE_ENEMY                = 77,
	TARGET_NONCOMBAT_PET               = 90,
};

enum SpellMissInfo
{
	SPELL_MISS_NONE                    = 0,
	SPELL_MISS_MISS                    = 1,
	SPELL_MISS_RESIST                  = 2,
	SPELL_MISS_DODGE                   = 3,
	SPELL_MISS_PARRY                   = 4,
	SPELL_MISS_BLOCK                   = 5,
	SPELL_MISS_EVADE                   = 6,
	SPELL_MISS_IMMUNE                  = 7,
	SPELL_MISS_IMMUNE2                 = 8,
	SPELL_MISS_DEFLECT                 = 9,
	SPELL_MISS_ABSORB                  = 10,
	SPELL_MISS_REFLECT                 = 11,
};

enum SpellHitType
{
	SPELL_HIT_TYPE_UNK1 = 0x00001,
	SPELL_HIT_TYPE_CRIT = 0x00002,
	SPELL_HIT_TYPE_UNK2 = 0x00004,
	SPELL_HIT_TYPE_UNK3 = 0x00008,
	SPELL_HIT_TYPE_UNK4 = 0x00020
};

enum SpellDmgClass
{
	SPELL_DAMAGE_CLASS_NONE     = 0,
	SPELL_DAMAGE_CLASS_MAGIC    = 1,
	SPELL_DAMAGE_CLASS_MELEE    = 2,
};

struct SpellEntry
{
	ui32    Id;                                           // 0 normally counted from 0 field (but some tools start counting from 1, check this before tool use for data view!)
	ui32    Category;                                     // 1
	//ui32     castUI                                     // 2 not used
	ui32    Dispel;                                       // 3
	ui32    Mechanic;                                     // 4
	ui32    Attributes;                                   // 5
	ui32    AttributesEx;                                 // 6
	ui32    AttributesEx2;                                // 7
	ui32    AttributesEx3;                                // 8
	ui32    AttributesEx4;                                // 9
	ui32    AttributesEx5;                              // 10 not used
	//ui32    AttributesEx6;                              // 11 not used
	ui32    Stances;                                      // 12
	ui32    StancesNot;                                   // 13
	ui32    Targets;                                      // 14
	ui32    TargetCreatureType;                           // 15
	ui32    RequiresSpellFocus;                           // 16
	//ui32    FacingCasterFlags;                          // 17 not used
	ui32    CasterAuraState;                              // 18
	ui32    TargetAuraState;                              // 19
	//ui32    CasterAuraStateNot                          // 20 not used
	//ui32    TargetAuraStateNot                          // 21 not used
	ui32    CastingTimeIndex;                             // 22
	ui32    RecoveryTime;                                 // 23
	ui32    CategoryRecoveryTime;                         // 24
	ui32    InterruptFlags;                               // 25
	ui32    AuraInterruptFlags;                           // 26
	ui32    ChannelInterruptFlags;                        // 27
	ui32    procFlags;                                    // 28
	ui32    procChance;                                   // 29
	ui32    procCharges;                                  // 30
	ui32    maxLevel;                                     // 31
	ui32    baseLevel;                                    // 32
	ui32    spellLevel;                                   // 33
	ui32    DurationIndex;                                // 34
	i32     powerType;                                    // 35
	ui32    manaCost;                                     // 36
	ui32    manaCostPerlevel;                             // 37
	ui32    manaPerSecond;                                // 38
	ui32    manaPerSecondPerLevel;                        // 39
	ui32    rangeIndex;                                   // 40
	float     speed;                                        // 41
	ui32    modalNextSpell;                               // 42
	ui32    StackAmount;                                  // 43
	ui32    Totem[2];                                     // 44-45
	i32     Reagent[8];                                   // 46-53
	ui32    ReagentCount[8];                              // 54-61
	i32     EquippedItemClass;                            // 62 (value)
	i32     EquippedItemSubClassMask;                     // 63 (mask)
	i32     EquippedItemInventoryTypeMask;                // 64 (mask)
	ui32    Effect[3];                                    // 65-67
	i32     EffectDieSides[3];                            // 68-70
	ui32    EffectBaseDice[3];                            // 71-73
	float     EffectDicePerLevel[3];                        // 74-76
	float     EffectRealPointsPerLevel[3];                  // 77-79
	i32     EffectBasePoints[3];                          // 80-82 (don't must be used in spell/auras explicitly, must be used cached Spell::m_currentBasePoints)
	ui32    EffectMechanic[3];                            // 83-85
	ui32    EffectImplicitTargetA[3];                     // 86-88
	ui32    EffectImplicitTargetB[3];                     // 89-91
	ui32    EffectRadiusIndex[3];                         // 92-94 - spellradius.dbc
	ui32    EffectApplyAuraName[3];                       // 95-97
	ui32    EffectAmplitude[3];                           // 98-100
	float     EffectMultipleValue[3];                       // 101-103
	ui32    EffectChainTarget[3];                         // 104-106
	ui32    EffectItemType[3];                            // 107-109
	i32     EffectMiscValue[3];                           // 110-112
	ui32    EffectTriggerSpell[3];                        // 113-115
	float     EffectPointsPerComboPoint[3];                 // 116-118
	ui32    SpellVisual;                                  // 119
	// 120 not used
	ui32    SpellIconID;                                  // 121
	ui32    activeIconID;                                 // 122
	ui32    spellPriority;                                // 123
	char*     SpellName[16];                                // 124-139
	//ui32    SpellNameFlag;                              // 140
	char*     Rank[16];                                     // 141-156
	//ui32    RankFlags;                                  // 157
	//char*     Description[16];                            // 158-173 not used
	//ui32    DescriptionFlags;                           // 174     not used
	//char*     ToolTip[16];                                // 175-190 not used
	//ui32    ToolTipFlags;                               // 191     not used
	ui32    ManaCostPercentage;                           // 192
	ui32    StartRecoveryCategory;                        // 193
	ui32    StartRecoveryTime;                            // 194
	ui32    MaxTargetLevel;                               // 195
	ui32    SpellFamilyName;                              // 196
	ui64    SpellFamilyFlags;                             // 197+198
	ui32    MaxAffectedTargets;                           // 199
	ui32    DmgClass;                                     // 200  defenseType
	ui32    PreventionType;                               // 201
	//ui32    StanceBarOrder;                             // 202 not used
	float     DmgMultiplier[3];                             // 203-205
	//ui32    MinFactionId;                               // 206 not used, and 0 in 2.4.2
	//ui32    MinReputation;                              // 207 not used, and 0 in 2.4.2
	//ui32    RequiredAuraVision;                         // 208 not used
	ui32    TotemCategory[2];                             // 209-210
	ui32    AreaId;                                       // 211
	ui32    SchoolMask;                                   // 212 school mask

private:
	// prevent creating custom entries (copy data from original infact)
	SpellEntry(SpellEntry const&);                      // DON'T must have implementation
};





enum SpellState
{
	SPELL_STATE_NULL      = 0,
	SPELL_STATE_PREPARING = 1,
	SPELL_STATE_CASTING   = 2,
	SPELL_STATE_FINISHED  = 3,
	SPELL_STATE_IDLE      = 4,
	SPELL_STATE_DELAYED   = 5
};

enum SpellFailedReason
{
	SPELL_FAILED_AFFECTING_COMBAT               = 0x00,
	SPELL_FAILED_ALREADY_AT_FULL_HEALTH         = 0x01,
	SPELL_FAILED_ALREADY_AT_FULL_MANA           = 0x02,
	SPELL_FAILED_ALREADY_AT_FULL_POWER          = 0x03,
	SPELL_FAILED_ALREADY_BEING_TAMED            = 0x04,
	SPELL_FAILED_ALREADY_HAVE_CHARM             = 0x05,
	SPELL_FAILED_ALREADY_HAVE_SUMMON            = 0x06,
	SPELL_FAILED_ALREADY_OPEN                   = 0x07,
	SPELL_FAILED_AURA_BOUNCED                   = 0x08,
	SPELL_FAILED_AUTOTRACK_INTERRUPTED          = 0x09,
	SPELL_FAILED_BAD_IMPLICIT_TARGETS           = 0x0A,
	SPELL_FAILED_BAD_TARGETS                    = 0x0B,
	SPELL_FAILED_CANT_BE_CHARMED                = 0x0C,
	SPELL_FAILED_CANT_BE_DISENCHANTED           = 0x0D,
	SPELL_FAILED_CANT_BE_DISENCHANTED_SKILL     = 0x0E,
	SPELL_FAILED_CANT_BE_PROSPECTED             = 0x0F,
	SPELL_FAILED_CANT_CAST_ON_TAPPED            = 0x10,
	SPELL_FAILED_CANT_DUEL_WHILE_INVISIBLE      = 0x11,
	SPELL_FAILED_CANT_DUEL_WHILE_STEALTHED      = 0x12,
	SPELL_FAILED_CANT_STEALTH                   = 0x13,
	SPELL_FAILED_CASTER_AURASTATE               = 0x14,
	SPELL_FAILED_CASTER_DEAD                    = 0x15,
	SPELL_FAILED_CHARMED                        = 0x16,
	SPELL_FAILED_CHEST_IN_USE                   = 0x17,
	SPELL_FAILED_CONFUSED                       = 0x18,
	SPELL_FAILED_DONT_REPORT                    = 0x19,
	SPELL_FAILED_EQUIPPED_ITEM                  = 0x1A,
	SPELL_FAILED_EQUIPPED_ITEM_CLASS            = 0x1B,
	SPELL_FAILED_EQUIPPED_ITEM_CLASS_MAINHAND   = 0x1C,
	SPELL_FAILED_EQUIPPED_ITEM_CLASS_OFFHAND    = 0x1D,
	SPELL_FAILED_ERROR                          = 0x1E,
	SPELL_FAILED_FIZZLE                         = 0x1F,
	SPELL_FAILED_FLEEING                        = 0x20,
	SPELL_FAILED_FOOD_LOWLEVEL                  = 0x21,
	SPELL_FAILED_HIGHLEVEL                      = 0x22,
	SPELL_FAILED_HUNGER_SATIATED                = 0x23,
	SPELL_FAILED_IMMUNE                         = 0x24,
	SPELL_FAILED_INTERRUPTED                    = 0x25,
	SPELL_FAILED_INTERRUPTED_COMBAT             = 0x26,
	SPELL_FAILED_ITEM_ALREADY_ENCHANTED         = 0x27,
	SPELL_FAILED_ITEM_GONE                      = 0x28,
	SPELL_FAILED_ITEM_NOT_FOUND                 = 0x29,
	SPELL_FAILED_ITEM_NOT_READY                 = 0x2A,
	SPELL_FAILED_LEVEL_REQUIREMENT              = 0x2B,
	SPELL_FAILED_LINE_OF_SIGHT                  = 0x2C,
	SPELL_FAILED_LOWLEVEL                       = 0x2D,
	SPELL_FAILED_LOW_CASTLEVEL                  = 0x2E,
	SPELL_FAILED_MAINHAND_EMPTY                 = 0x2F,
	SPELL_FAILED_MOVING                         = 0x30,
	SPELL_FAILED_NEED_AMMO                      = 0x31,
	SPELL_FAILED_NEED_AMMO_POUCH                = 0x32,
	SPELL_FAILED_NEED_EXOTIC_AMMO               = 0x33,
	SPELL_FAILED_NOPATH                         = 0x34,
	SPELL_FAILED_NOT_BEHIND                     = 0x35,
	SPELL_FAILED_NOT_FISHABLE                   = 0x36,
	SPELL_FAILED_NOT_FLYING                     = 0x37,
	SPELL_FAILED_NOT_HERE                       = 0x38,
	SPELL_FAILED_NOT_INFRONT                    = 0x39,
	SPELL_FAILED_NOT_IN_CONTROL                 = 0x3A,
	SPELL_FAILED_NOT_KNOWN                      = 0x3B,
	SPELL_FAILED_NOT_MOUNTED                    = 0x3C,
	SPELL_FAILED_NOT_ON_TAXI                    = 0x3D,
	SPELL_FAILED_NOT_ON_TRANSPORT               = 0x3E,
	SPELL_FAILED_NOT_READY                      = 0x3F,
	SPELL_FAILED_NOT_SHAPESHIFT                 = 0x40,
	SPELL_FAILED_NOT_STANDING                   = 0x41,
	SPELL_FAILED_NOT_TRADEABLE                  = 0x42,
	SPELL_FAILED_NOT_TRADING                    = 0x43,
	SPELL_FAILED_NOT_UNSHEATHED                 = 0x44,
	SPELL_FAILED_NOT_WHILE_GHOST                = 0x45,
	SPELL_FAILED_NO_AMMO                        = 0x46,
	SPELL_FAILED_NO_CHARGES_REMAIN              = 0x47,
	SPELL_FAILED_NO_CHAMPION                    = 0x48,
	SPELL_FAILED_NO_COMBO_POINTS                = 0x49,
	SPELL_FAILED_NO_DUELING                     = 0x4A,
	SPELL_FAILED_NO_ENDURANCE                   = 0x4B,
	SPELL_FAILED_NO_FISH                        = 0x4C,
	SPELL_FAILED_NO_ITEMS_WHILE_SHAPESHIFTED    = 0x4D,
	SPELL_FAILED_NO_MOUNTS_ALLOWED              = 0x4E,
	SPELL_FAILED_NO_PET                         = 0x4F,
	SPELL_FAILED_NO_POWER                       = 0x50,
	SPELL_FAILED_NOTHING_TO_DISPEL              = 0x51,
	SPELL_FAILED_NOTHING_TO_STEAL               = 0x52,
	SPELL_FAILED_ONLY_ABOVEWATER                = 0x53,
	SPELL_FAILED_ONLY_DAYTIME                   = 0x54,
	SPELL_FAILED_ONLY_INDOORS                   = 0x55,
	SPELL_FAILED_ONLY_MOUNTED                   = 0x56,
	SPELL_FAILED_ONLY_NIGHTTIME                 = 0x57,
	SPELL_FAILED_ONLY_OUTDOORS                  = 0x58,
	SPELL_FAILED_ONLY_SHAPESHIFT                = 0x59,
	SPELL_FAILED_ONLY_STEALTHED                 = 0x5A,
	SPELL_FAILED_ONLY_UNDERWATER                = 0x5B,
	SPELL_FAILED_OUT_OF_RANGE                   = 0x5C,
	SPELL_FAILED_PACIFIED                       = 0x5D,
	SPELL_FAILED_POSSESSED                      = 0x5E,
	SPELL_FAILED_REAGENTS                       = 0x5F,
	SPELL_FAILED_REQUIRES_AREA                  = 0x60,
	SPELL_FAILED_REQUIRES_SPELL_FOCUS           = 0x61,
	SPELL_FAILED_ROOTED                         = 0x62,
	SPELL_FAILED_SILENCED                       = 0x63,
	SPELL_FAILED_SPELL_IN_PROGRESS              = 0x64,
	SPELL_FAILED_SPELL_LEARNED                  = 0x65,
	SPELL_FAILED_SPELL_UNAVAILABLE              = 0x66,
	SPELL_FAILED_STUNNED                        = 0x67,
	SPELL_FAILED_TARGETS_DEAD                   = 0x68,
	SPELL_FAILED_TARGET_AFFECTING_COMBAT        = 0x69,
	SPELL_FAILED_TARGET_AURASTATE               = 0x6A,
	SPELL_FAILED_TARGET_DUELING                 = 0x6B,
	SPELL_FAILED_TARGET_ENEMY                   = 0x6C,
	SPELL_FAILED_TARGET_ENRAGED                 = 0x6D,
	SPELL_FAILED_TARGET_FRIENDLY                = 0x6E,
	SPELL_FAILED_TARGET_IN_COMBAT               = 0x6F,
	SPELL_FAILED_TARGET_IS_PLAYER               = 0x70,
	SPELL_FAILED_TARGET_IS_PLAYER_CONTROLLED    = 0x71,
	SPELL_FAILED_TARGET_NOT_DEAD                = 0x72,
	SPELL_FAILED_TARGET_NOT_IN_PARTY            = 0x73,
	SPELL_FAILED_TARGET_NOT_LOOTED              = 0x74,
	SPELL_FAILED_TARGET_NOT_PLAYER              = 0x75,
	SPELL_FAILED_TARGET_NO_POCKETS              = 0x76,
	SPELL_FAILED_TARGET_NO_WEAPONS              = 0x77,
	SPELL_FAILED_TARGET_UNSKINNABLE             = 0x78,
	SPELL_FAILED_THIRST_SATIATED                = 0x79,
	SPELL_FAILED_TOO_CLOSE                      = 0x7A,
	SPELL_FAILED_TOO_MANY_OF_ITEM               = 0x7B,
	SPELL_FAILED_TOTEM_CATEGORY                 = 0x7C,
	SPELL_FAILED_TOTEMS                         = 0x7D,
	SPELL_FAILED_TRAINING_POINTS                = 0x7E,
	SPELL_FAILED_TRY_AGAIN                      = 0x7F,
	SPELL_FAILED_UNIT_NOT_BEHIND                = 0x80,
	SPELL_FAILED_UNIT_NOT_INFRONT               = 0x81,
	SPELL_FAILED_WRONG_PET_FOOD                 = 0x82,
	SPELL_FAILED_NOT_WHILE_FATIGUED             = 0x83,
	SPELL_FAILED_TARGET_NOT_IN_INSTANCE         = 0x84,
	SPELL_FAILED_NOT_WHILE_TRADING              = 0x85,
	SPELL_FAILED_TARGET_NOT_IN_RAID             = 0x86,
	SPELL_FAILED_DISENCHANT_WHILE_LOOTING       = 0x87,
	SPELL_FAILED_PROSPECT_WHILE_LOOTING         = 0x88,
	SPELL_FAILED_PROSPECT_NEED_MORE             = 0x89,
	SPELL_FAILED_TARGET_FREEFORALL              = 0x8A,
	SPELL_FAILED_NO_EDIBLE_CORPSES              = 0x8B,
	SPELL_FAILED_ONLY_BATTLEGROUNDS             = 0x8C,
	SPELL_FAILED_TARGET_NOT_GHOST               = 0x8D,
	SPELL_FAILED_TOO_MANY_SKILLS                = 0x8E,
	SPELL_FAILED_TRANSFORM_UNUSABLE             = 0x8F,
	SPELL_FAILED_WRONG_WEATHER                  = 0x90,
	SPELL_FAILED_DAMAGE_IMMUNE                  = 0x91,
	SPELL_FAILED_PREVENTED_BY_MECHANIC          = 0x92,
	SPELL_FAILED_PLAY_TIME                      = 0x93,
	SPELL_FAILED_REPUTATION                     = 0x94,
	SPELL_FAILED_MIN_SKILL                      = 0x95,
	SPELL_FAILED_NOT_IN_ARENA                   = 0x96,
	SPELL_FAILED_NOT_ON_SHAPESHIFT              = 0x97,
	SPELL_FAILED_NOT_ON_STEALTHED               = 0x98,
	SPELL_FAILED_NOT_ON_DAMAGE_IMMUNE           = 0x99,
	SPELL_FAILED_NOT_ON_MOUNTED                 = 0x9A,
	SPELL_FAILED_TOO_SHALLOW                    = 0x9B,
	SPELL_FAILED_TARGET_NOT_IN_SANCTUARY        = 0x9C,
	SPELL_FAILED_TARGET_IS_TRIVIAL              = 0x9D,
	SPELL_FAILED_BM_OR_INVISGOD                 = 0x9E,
	SPELL_FAILED_EXPERT_RIDING_REQUIREMENT      = 0x9F,
	SPELL_FAILED_ARTISAN_RIDING_REQUIREMENT     = 0xA0,
	SPELL_FAILED_NOT_IDLE                       = 0xA1,
	SPELL_FAILED_NOT_INACTIVE                   = 0xA2,
	SPELL_FAILED_PARTIAL_PLAYTIME               = 0xA3,
	SPELL_FAILED_NO_PLAYTIME                    = 0xA4,
	SPELL_FAILED_NOT_IN_BATTLEGROUND            = 0xA5,
	SPELL_FAILED_ONLY_IN_ARENA                  = 0xA6,
	SPELL_FAILED_TARGET_LOCKED_TO_RAID_INSTANCE = 0xA7,
	SPELL_FAILED_UNKNOWN                        = 0xA8,
};

enum SpellFamilyNames
{
	SPELLFAMILY_GENERIC = 0,
	SPELLFAMILY_MAGE = 3,
	SPELLFAMILY_WARRIOR = 4,
	SPELLFAMILY_WARLOCK = 5,
	SPELLFAMILY_PRIEST = 6,
	SPELLFAMILY_DRUID = 7,
	SPELLFAMILY_ROGUE = 8,
	SPELLFAMILY_HUNTER = 9,
	SPELLFAMILY_PALADIN = 10,
	SPELLFAMILY_SHAMAN = 11,
	SPELLFAMILY_POTION = 13
};

//Some SpellFamilyFlags
#define SPELLFAMILYFLAG_ROGUE_VANISH            0x000000800LL
#define SPELLFAMILYFLAG_ROGUE_STEALTH           0x000400000LL
#define SPELLFAMILYFLAG_ROGUE_BACKSTAB          0x000800004LL
#define SPELLFAMILYFLAG_ROGUE_SAP               0x000000080LL
#define SPELLFAMILYFLAG_ROGUE_FEINT             0x008000000LL
#define SPELLFAMILYFLAG_ROGUE_KIDNEYSHOT        0x000200000LL
#define SPELLFAMILYFLAG_ROGUE__FINISHING_MOVE   0x9003E0000LL

//Some SpellIDs
#define SPELLID_MAGE_HYPOTHERMIA            41425

// Spell clasification
enum SpellSpecific
{
	SPELL_NORMAL = 0,
	SPELL_SEAL = 1,
	SPELL_BLESSING = 2,
	SPELL_AURA = 3,
	SPELL_STING = 4,
	SPELL_CURSE = 5,
	SPELL_ASPECT = 6,
	SPELL_TRACKER = 7,
	SPELL_WARLOCK_ARMOR = 8,
	SPELL_MAGE_ARMOR = 9,
	SPELL_ELEMENTAL_SHIELD = 10,
	SPELL_MAGE_POLYMORPH = 11,
	SPELL_POSITIVE_SHOUT = 12,
	SPELL_JUDGEMENT = 13,
	SPELL_BATTLE_ELIXIR = 14,
	SPELL_GUARDIAN_ELIXIR = 15,
	SPELL_FLASK_ELIXIR = 16
};

// ***********************************
// Spell Attributes definitions
// ***********************************

#define SPELL_ATTR_UNK0                           0x00000001            // 0
#define SPELL_ATTR_UNK2                           0x00000004            // 2 on next swing?
#define SPELL_ATTR_UNK3                           0x00000008            // 3 not set in 2.4.2
#define SPELL_ATTR_UNK4                           0x00000010            // 4
#define SPELL_ATTR_UNK5                           0x00000020            // 5 trade spells?
#define SPELL_ATTR_PASSIVE                        0x00000040            // 6 Passive spell
#define SPELL_ATTR_UNK7                           0x00000080            // 7 visible?
#define SPELL_ATTR_UNK8                           0x00000100            // 8
#define SPELL_ATTR_UNK9                           0x00000200            // 9
#define SPELL_ATTR_UNK10                          0x00000400            // 10
#define SPELL_ATTR_UNK11                          0x00000800            // 11
#define SPELL_ATTR_DAYTIME_ONLY                   0x00001000            // 12 only useable at daytime, not set in 2.4.2
#define SPELL_ATTR_NIGHT_ONLY                     0x00002000            // 13 only useable at night, not set in 2.4.2
#define SPELL_ATTR_INDOORS_ONLY                   0x00004000            // 14 only useable indoors, not set in 2.4.2
#define SPELL_ATTR_OUTDOORS_ONLY                  0x00008000            // 15 Only useable outdoors.
#define SPELL_ATTR_NOT_SHAPESHIFT                 0x00010000            // 16 Not while shapeshifted
#define SPELL_ATTR_ONLY_STEALTHED                 0x00020000            // 17 Must be in stealth
#define SPELL_ATTR_UNK18                          0x00040000            // 18
#define SPELL_ATTR_UNK19                          0x00080000            // 19
#define SPELL_ATTR_UNK20                          0x00100000            // 20
#define SPELL_ATTR_IMPOSSIBLE_DODGE_PARRY_BLOCK   0x00200000            // 21 Cannot be dodged/parried/blocked
#define SPELL_ATTR_UNK22                          0x00400000            // 22
#define SPELL_ATTR_UNK23                          0x00800000            // 23 castable while dead?
#define SPELL_ATTR_CASTABLE_WHILE_MOUNTED         0x01000000            // 24 castable while mounted
#define SPELL_ATTR_UNK25                          0x02000000            // 25 shaded while active aura?
#define SPELL_ATTR_UNK26                          0x04000000            // 26
#define SPELL_ATTR_CASTABLE_WHILE_SITTING         0x08000000            // 27 castable while sitting
#define SPELL_ATTR_CANT_USED_IN_COMBAT            0x10000000            // 28 Cannot be used in combat
#define SPELL_ATTR_UNAFFECTED_BY_INVULNERABILITY  0x20000000            // 29 unaffected by invulnerability (hmm possible not...)
#define SPELL_ATTR_UNK30                          0x40000000            // 30 breakable by damage?
#define SPELL_ATTR_UNK31                          0x80000000            // 31

#define SPELL_ATTR_EX_UNK0                        0x00000001            // 0
#define SPELL_ATTR_EX_DRAIN_ALL_POWER             0x00000002            // 1 use all power (Only paladin Lay of Hands and Bunyanize)
#define SPELL_ATTR_EX_UNK2                        0x00000004            // 2 channeled 1
#define SPELL_ATTR_EX_UNK3                        0x00000008            // 3
#define SPELL_ATTR_EX_UNK4                        0x00000010            // 4
#define SPELL_ATTR_EX_UNK5                        0x00000020            // 5 Not break stealth??
#define SPELL_ATTR_EX_UNK6                        0x00000040            // 6 channeled 2
#define SPELL_ATTR_EX_NEGATIVE                    0x00000080            // 7
#define SPELL_ATTR_EX_NOT_IN_COMBAT_TARGET        0x00000100            // 8 Spell req target not to be in combat state
#define SPELL_ATTR_EX_UNK9                        0x00000200            // 9
#define SPELL_ATTR_EX_UNK10                       0x00000400            // 10
#define SPELL_ATTR_EX_UNK11                       0x00000800            // 11
#define SPELL_ATTR_EX_UNK12                       0x00001000            // 12
#define SPELL_ATTR_EX_UNK13                       0x00002000            // 13
#define SPELL_ATTR_EX_UNK14                       0x00004000            // 14
#define SPELL_ATTR_EX_UNK15                       0x00008000            // 15
#define SPELL_ATTR_EX_UNAFFECTED_BY_SCHOOL_IMMUNE 0x00010000            // 16 unaffected by school immunity
#define SPELL_ATTR_EX_UNK17                       0x00020000            // 17
#define SPELL_ATTR_EX_UNK18                       0x00040000            // 18
#define SPELL_ATTR_EX_UNK19                       0x00080000            // 19
#define SPELL_ATTR_EX_REQ_COMBO_POINTS1           0x00100000            // 20 Req combo points on target
#define SPELL_ATTR_EX_UNK21                       0x00200000            // 21
#define SPELL_ATTR_EX_REQ_COMBO_POINTS2           0x00400000            // 22 Req combo points on target
#define SPELL_ATTR_EX_UNK23                       0x00800000            // 23
#define SPELL_ATTR_EX_UNK24                       0x01000000            // 24 Req fishing pole??
#define SPELL_ATTR_EX_UNK25                       0x02000000            // 25 not set in 2.4.2
#define SPELL_ATTR_EX_UNK26                       0x04000000            // 26
#define SPELL_ATTR_EX_UNK27                       0x08000000            // 27
#define SPELL_ATTR_EX_UNK28                       0x10000000            // 28
#define SPELL_ATTR_EX_UNK29                       0x20000000            // 29
#define SPELL_ATTR_EX_UNK30                       0x40000000            // 30 overpower
#define SPELL_ATTR_EX_UNK31                       0x80000000            // 31

#define SPELL_ATTR_EX2_UNK0                       0x00000001            // 0
#define SPELL_ATTR_EX2_UNK1                       0x00000002            // 1
#define SPELL_ATTR_EX2_UNK2                       0x00000004            // 2
#define SPELL_ATTR_EX2_UNK3                       0x00000008            // 3
#define SPELL_ATTR_EX2_UNK4                       0x00000010            // 4
#define SPELL_ATTR_EX2_UNK5                       0x00000020            // 5
#define SPELL_ATTR_EX2_UNK6                       0x00000040            // 6
#define SPELL_ATTR_EX2_UNK7                       0x00000080            // 7
#define SPELL_ATTR_EX2_UNK8                       0x00000100            // 8 not set in 2.4.2
#define SPELL_ATTR_EX2_UNK9                       0x00000200            // 9
#define SPELL_ATTR_EX2_UNK10                      0x00000400            // 10
#define SPELL_ATTR_EX2_UNK11                      0x00000800            // 11
#define SPELL_ATTR_EX2_UNK12                      0x00001000            // 12
#define SPELL_ATTR_EX2_UNK13                      0x00002000            // 13
#define SPELL_ATTR_EX2_UNK14                      0x00004000            // 14
#define SPELL_ATTR_EX2_UNK15                      0x00008000            // 15 not set in 2.4.2
#define SPELL_ATTR_EX2_UNK16                      0x00010000            // 16
#define SPELL_ATTR_EX2_UNK17                      0x00020000            // 17 Hunters Shot and Stings only have this flag
#define SPELL_ATTR_EX2_UNK18                      0x00040000            // 18 Only Revive pet - possible req dead pet
#define SPELL_ATTR_EX2_NOT_NEED_SHAPESHIFT        0x00080000            // 19 does not necessarly need shapeshift
#define SPELL_ATTR_EX2_UNK20                      0x00100000            // 20
#define SPELL_ATTR_EX2_UNK21                      0x00200000            // 21
#define SPELL_ATTR_EX2_UNK22                      0x00400000            // 22
#define SPELL_ATTR_EX2_UNK23                      0x00800000            // 23 Only mage Arcane Concentration have this flag
#define SPELL_ATTR_EX2_UNK24                      0x01000000            // 24
#define SPELL_ATTR_EX2_UNK25                      0x02000000            // 25
#define SPELL_ATTR_EX2_UNK26                      0x04000000            // 26 unaffected by school immunity
#define SPELL_ATTR_EX2_UNK27                      0x08000000            // 27
#define SPELL_ATTR_EX2_UNK28                      0x10000000            // 28
#define SPELL_ATTR_EX2_CANT_CRIT                  0x20000000            // 29 Spell can't crit
#define SPELL_ATTR_EX2_UNK30                      0x40000000            // 30
#define SPELL_ATTR_EX2_UNK31                      0x80000000            // 31

#define SPELL_ATTR_EX3_UNK0                       0x00000001            // 0
#define SPELL_ATTR_EX3_UNK1                       0x00000002            // 1
#define SPELL_ATTR_EX3_UNK2                       0x00000004            // 2
#define SPELL_ATTR_EX3_UNK3                       0x00000008            // 3
#define SPELL_ATTR_EX3_UNK4                       0x00000010            // 4 Druid Rebirth only this spell have this flag
#define SPELL_ATTR_EX3_UNK5                       0x00000020            // 5
#define SPELL_ATTR_EX3_UNK6                       0x00000040            // 6
#define SPELL_ATTR_EX3_UNK7                       0x00000080            // 7
#define SPELL_ATTR_EX3_UNK8                       0x00000100            // 8
#define SPELL_ATTR_EX3_UNK9                       0x00000200            // 9
#define SPELL_ATTR_EX3_MAIN_HAND                  0x00000400            // 10 Main hand weapon required
#define SPELL_ATTR_EX3_UNK12                      0x00001000            // 12
#define SPELL_ATTR_EX3_UNK13                      0x00002000            // 13
#define SPELL_ATTR_EX3_UNK14                      0x00004000            // 14 "Honorless Target" only this spells have this flag
#define SPELL_ATTR_EX3_UNK15                      0x00008000            // 15 Auto Shoot, Shoot, Throw,  - this is autoshot flag
#define SPELL_ATTR_EX3_UNK16                      0x00010000            // 16
#define SPELL_ATTR_EX3_UNK17                      0x00020000            // 17 no initial aggro
#define SPELL_ATTR_EX3_UNK18                      0x00040000            // 18
#define SPELL_ATTR_EX3_UNK19                      0x00080000            // 19
#define SPELL_ATTR_EX3_DEATH_PERSISTENT           0x00100000            // 20 Death persistent spells
#define SPELL_ATTR_EX3_UNK21                      0x00200000            // 21
#define SPELL_ATTR_EX3_UNK23                      0x00800000            // 23
#define SPELL_ATTR_EX3_UNK25                      0x02000000            // 25
#define SPELL_ATTR_EX3_UNK26                      0x04000000            // 26
#define SPELL_ATTR_EX3_UNK27                      0x08000000            // 27
#define SPELL_ATTR_EX3_UNK28                      0x10000000            // 28
#define SPELL_ATTR_EX3_UNK29                      0x20000000            // 29
#define SPELL_ATTR_EX3_UNK30                      0x40000000            // 30
#define SPELL_ATTR_EX3_UNK31                      0x80000000            // 31

#define SPELL_ATTR_EX4_UNK0                       0x00000001            // 0
#define SPELL_ATTR_EX4_UNK1                       0x00000002            // 1 proc on finishing move?
#define SPELL_ATTR_EX4_UNK2                       0x00000004            // 2
#define SPELL_ATTR_EX4_UNK3                       0x00000008            // 3
#define SPELL_ATTR_EX4_UNK4                       0x00000010            // 4
#define SPELL_ATTR_EX4_UNK5                       0x00000020            // 5
#define SPELL_ATTR_EX4_UNK6                       0x00000040            // 6
#define SPELL_ATTR_EX4_UNK7                       0x00000080            // 7
#define SPELL_ATTR_EX4_UNK8                       0x00000100            // 8
#define SPELL_ATTR_EX4_UNK9                       0x00000200            // 9
#define SPELL_ATTR_EX4_UNK11                      0x00000800            // 11
#define SPELL_ATTR_EX4_UNK12                      0x00001000            // 12
#define SPELL_ATTR_EX4_UNK13                      0x00002000            // 13
#define SPELL_ATTR_EX4_UNK14                      0x00004000            // 14
#define SPELL_ATTR_EX4_UNK15                      0x00008000            // 15
#define SPELL_ATTR_EX4_UNK16                      0x00010000            // 16 not usable in arena
#define SPELL_ATTR_EX4_UNK17                      0x00020000            // 17 usable in arena
#define SPELL_ATTR_EX4_UNK18                      0x00040000            // 18
#define SPELL_ATTR_EX4_UNK19                      0x00080000            // 19
#define SPELL_ATTR_EX4_UNK20                      0x00100000            // 20
#define SPELL_ATTR_EX4_UNK21                      0x00200000            // 21
#define SPELL_ATTR_EX4_UNK22                      0x00400000            // 22
#define SPELL_ATTR_EX4_UNK23                      0x00800000            // 23
#define SPELL_ATTR_EX4_UNK24                      0x01000000            // 24
#define SPELL_ATTR_EX4_UNK25                      0x02000000            // 25 pet scaling auras
#define SPELL_ATTR_EX4_CAST_ONLY_IN_OUTLAND       0x04000000            // 26 Can only be used in Outland.
#define SPELL_ATTR_EX4_UNK27                      0x08000000            // 27
#define SPELL_ATTR_EX4_UNK28                      0x10000000            // 28
#define SPELL_ATTR_EX4_UNK29                      0x20000000            // 29
#define SPELL_ATTR_EX4_UNK30                      0x40000000            // 30
#define SPELL_ATTR_EX4_UNK31                      0x80000000            // 31

#define SPELL_ATTR_EX5_UNK0                       0x00000001            // 0
#define SPELL_ATTR_EX5_UNK1                       0x00000002            // 1 not need reagents if UNIT_FLAG_RESTING
#define SPELL_ATTR_EX5_UNK2                       0x00000004            // 2
#define SPELL_ATTR_EX5_UNK3                       0x00000008            // 3 usable while stunned
#define SPELL_ATTR_EX5_UNK4                       0x00000010            // 4
#define SPELL_ATTR_EX5_SINGLE_TARGET_SPELL        0x00000020            // 5 Only one target can be apply at a time
#define SPELL_ATTR_EX5_UNK6                       0x00000040            // 6
#define SPELL_ATTR_EX5_UNK7                       0x00000080            // 7
#define SPELL_ATTR_EX5_UNK8                       0x00000100            // 8
#define SPELL_ATTR_EX5_UNK9                       0x00000200            // 9
#define SPELL_ATTR_EX5_UNK10                      0x00000400            // 10
#define SPELL_ATTR_EX5_UNK11                      0x00000800            // 11
#define SPELL_ATTR_EX5_UNK12                      0x00001000            // 12
#define SPELL_ATTR_EX5_UNK13                      0x00002000            // 13
#define SPELL_ATTR_EX5_UNK14                      0x00004000            // 14
#define SPELL_ATTR_EX5_UNK15                      0x00008000            // 15
#define SPELL_ATTR_EX5_UNK16                      0x00010000            // 16
#define SPELL_ATTR_EX5_UNK17                      0x00020000            // 17 usable while feared
#define SPELL_ATTR_EX5_UNK18                      0x00040000            // 18 usable while confused
#define SPELL_ATTR_EX5_UNK19                      0x00080000            // 19
#define SPELL_ATTR_EX5_UNK20                      0x00100000            // 20
#define SPELL_ATTR_EX5_UNK21                      0x00200000            // 21
#define SPELL_ATTR_EX5_UNK22                      0x00400000            // 22
#define SPELL_ATTR_EX5_UNK23                      0x00800000            // 23
#define SPELL_ATTR_EX5_UNK24                      0x01000000            // 24
#define SPELL_ATTR_EX5_UNK25                      0x02000000            // 25
#define SPELL_ATTR_EX5_UNK26                      0x04000000            // 26
#define SPELL_ATTR_EX5_UNK27                      0x08000000            // 27
#define SPELL_ATTR_EX5_UNK28                      0x10000000            // 28
#define SPELL_ATTR_EX5_UNK29                      0x20000000            // 29
#define SPELL_ATTR_EX5_UNK30                      0x40000000            // 30
#define SPELL_ATTR_EX5_UNK31                      0x80000000            // 31 Forces all nearby enemies to focus attacks caster

#define SPELL_ATTR_EX6_UNK0                       0x00000001            // 0 Only Move spell have this flag
#define SPELL_ATTR_EX6_UNK1                       0x00000002            // 1 not set in 2.4.2
#define SPELL_ATTR_EX6_UNK2                       0x00000004            // 2
#define SPELL_ATTR_EX6_UNK3                       0x00000008            // 3
#define SPELL_ATTR_EX6_UNK4                       0x00000010            // 4 not set in 2.4.2
#define SPELL_ATTR_EX6_UNK5                       0x00000020            // 5
#define SPELL_ATTR_EX6_UNK6                       0x00000040            // 6
#define SPELL_ATTR_EX6_UNK7                       0x00000080            // 7
#define SPELL_ATTR_EX6_UNK8                       0x00000100            // 8
#define SPELL_ATTR_EX6_UNK9                       0x00000200            // 9 not set in 2.4.2
#define SPELL_ATTR_EX6_UNK10                      0x00000400            // 10
#define SPELL_ATTR_EX6_UNK11                      0x00000800            // 11
#define SPELL_ATTR_EX6_UNK12                      0x00001000            // 12 not set in 2.4.2
#define SPELL_ATTR_EX6_UNK13                      0x00002000            // 13 not set in 2.4.2
#define SPELL_ATTR_EX6_UNK14                      0x00004000            // 14 not set in 2.4.2
#define SPELL_ATTR_EX6_UNK15                      0x00008000            // 15 not set in 2.4.2
#define SPELL_ATTR_EX6_UNK16                      0x00010000            // 16 not set in 2.4.2
#define SPELL_ATTR_EX6_UNK17                      0x00020000            // 17 not set in 2.4.2
#define SPELL_ATTR_EX6_UNK18                      0x00040000            // 18 not set in 2.4.2
#define SPELL_ATTR_EX6_UNK19                      0x00080000            // 19 not set in 2.4.2
#define SPELL_ATTR_EX6_UNK20                      0x00100000            // 20 not set in 2.4.2
#define SPELL_ATTR_EX6_UNK21                      0x00200000            // 21 not set in 2.4.2
#define SPELL_ATTR_EX6_UNK22                      0x00400000            // 22 not set in 2.4.2
#define SPELL_ATTR_EX6_UNK23                      0x00800000            // 23 not set in 2.4.2
#define SPELL_ATTR_EX6_UNK24                      0x01000000            // 24 not set in 2.4.2
#define SPELL_ATTR_EX6_UNK25                      0x02000000            // 25 not set in 2.4.2
#define SPELL_ATTR_EX6_UNK26                      0x04000000            // 26 not set in 2.4.2
#define SPELL_ATTR_EX6_UNK27                      0x08000000            // 27 not set in 2.4.2
#define SPELL_ATTR_EX6_UNK28                      0x10000000            // 28 not set in 2.4.2
#define SPELL_ATTR_EX6_UNK29                      0x20000000            // 29 not set in 2.4.2
#define SPELL_ATTR_EX6_UNK30                      0x40000000            // 30 not set in 2.4.2
#define SPELL_ATTR_EX6_UNK31                      0x80000000            // 31 not set in 2.4.2


enum SpellEffects
{
	SPELL_EFFECT_INSTAKILL                 = 1,
	SPELL_EFFECT_SCHOOL_DAMAGE             = 2,
	SPELL_EFFECT_DUMMY                     = 3,
	SPELL_EFFECT_PORTAL_TELEPORT           = 4,
	SPELL_EFFECT_TELEPORT_UNITS            = 5,
	SPELL_EFFECT_APPLY_AURA                = 6,
	SPELL_EFFECT_ENVIRONMENTAL_DAMAGE      = 7,
	SPELL_EFFECT_MANA_DRAIN                = 8,
	SPELL_EFFECT_HEALTH_LEECH              = 9,
	SPELL_EFFECT_HEAL                      = 10,
	SPELL_EFFECT_BIND                      = 11,
	SPELL_EFFECT_PORTAL                    = 12,
	SPELL_EFFECT_RITUAL_BASE               = 13,
	SPELL_EFFECT_RITUAL_SPECIALIZE         = 14,
	SPELL_EFFECT_RITUAL_ACTIVATE_PORTAL    = 15,
	SPELL_EFFECT_QUEST_COMPLETE            = 16,
	SPELL_EFFECT_WEAPON_DAMAGE_NOSCHOOL    = 17,
	SPELL_EFFECT_RESURRECT                 = 18,
	SPELL_EFFECT_ADD_EXTRA_ATTACKS         = 19,
	SPELL_EFFECT_DODGE                     = 20,
	SPELL_EFFECT_EVADE                     = 21,
	SPELL_EFFECT_PARRY                     = 22,
	SPELL_EFFECT_BLOCK                     = 23,
	SPELL_EFFECT_CREATE_ITEM               = 24,
	SPELL_EFFECT_WEAPON                    = 25,
	SPELL_EFFECT_DEFENSE                   = 26,
	SPELL_EFFECT_PERSISTENT_AREA_AURA      = 27,
	SPELL_EFFECT_SUMMON                    = 28,
	SPELL_EFFECT_LEAP                      = 29,
	SPELL_EFFECT_ENERGIZE                  = 30,
	SPELL_EFFECT_WEAPON_PERCENT_DAMAGE     = 31,
	SPELL_EFFECT_TRIGGER_MISSILE           = 32,
	SPELL_EFFECT_OPEN_LOCK                 = 33,
	SPELL_EFFECT_SUMMON_CHANGE_ITEM        = 34,
	SPELL_EFFECT_APPLY_AREA_AURA           = 35,
	SPELL_EFFECT_LEARN_SPELL               = 36,
	SPELL_EFFECT_SPELL_DEFENSE             = 37,
	SPELL_EFFECT_DISPEL                    = 38,
	SPELL_EFFECT_LANGUAGE                  = 39,
	SPELL_EFFECT_DUAL_WIELD                = 40,
	SPELL_EFFECT_SUMMON_WILD               = 41,
	SPELL_EFFECT_SUMMON_GUARDIAN           = 42,
	SPELL_EFFECT_TELEPORT_UNITS_FACE_CASTER= 43,
	SPELL_EFFECT_SKILL_STEP                = 44,
	SPELL_EFFECT_UNDEFINED_45              = 45,
	SPELL_EFFECT_SPAWN                     = 46,
	SPELL_EFFECT_TRADE_SKILL               = 47,
	SPELL_EFFECT_STEALTH                   = 48,
	SPELL_EFFECT_DETECT                    = 49,
	//    SPELL_EFFECT_SUMMON_OBJECT             = 50,
	SPELL_EFFECT_TRANS_DOOR                = 50,
	SPELL_EFFECT_FORCE_CRITICAL_HIT        = 51,
	SPELL_EFFECT_GUARANTEE_HIT             = 52,
	SPELL_EFFECT_ENCHANT_ITEM              = 53,
	SPELL_EFFECT_ENCHANT_ITEM_TEMPORARY    = 54,
	SPELL_EFFECT_TAMECREATURE              = 55,
	SPELL_EFFECT_SUMMON_PET                = 56,
	SPELL_EFFECT_LEARN_PET_SPELL           = 57,
	SPELL_EFFECT_WEAPON_DAMAGE             = 58,
	SPELL_EFFECT_OPEN_LOCK_ITEM            = 59,
	SPELL_EFFECT_PROFICIENCY               = 60,
	SPELL_EFFECT_SEND_EVENT                = 61,
	SPELL_EFFECT_POWER_BURN                = 62,
	SPELL_EFFECT_THREAT                    = 63,
	SPELL_EFFECT_TRIGGER_SPELL             = 64,
	SPELL_EFFECT_HEALTH_FUNNEL             = 65,
	SPELL_EFFECT_POWER_FUNNEL              = 66,
	SPELL_EFFECT_HEAL_MAX_HEALTH           = 67,
	SPELL_EFFECT_INTERRUPT_CAST            = 68,
	SPELL_EFFECT_DISTRACT                  = 69,
	SPELL_EFFECT_PULL                      = 70,
	SPELL_EFFECT_PICKPOCKET                = 71,
	SPELL_EFFECT_ADD_FARSIGHT              = 72,
	SPELL_EFFECT_SUMMON_POSSESSED          = 73,
	SPELL_EFFECT_SUMMON_TOTEM              = 74,
	SPELL_EFFECT_HEAL_MECHANICAL           = 75,
	SPELL_EFFECT_SUMMON_OBJECT_WILD        = 76,
	SPELL_EFFECT_SCRIPT_EFFECT             = 77,
	SPELL_EFFECT_ATTACK                    = 78,
	SPELL_EFFECT_SANCTUARY                 = 79,
	SPELL_EFFECT_ADD_COMBO_POINTS          = 80,
	SPELL_EFFECT_CREATE_HOUSE              = 81,
	SPELL_EFFECT_BIND_SIGHT                = 82,
	SPELL_EFFECT_DUEL                      = 83,
	SPELL_EFFECT_STUCK                     = 84,
	SPELL_EFFECT_SUMMON_PLAYER             = 85,
	SPELL_EFFECT_ACTIVATE_OBJECT           = 86,
	SPELL_EFFECT_SUMMON_TOTEM_SLOT1        = 87,
	SPELL_EFFECT_SUMMON_TOTEM_SLOT2        = 88,
	SPELL_EFFECT_SUMMON_TOTEM_SLOT3        = 89,
	SPELL_EFFECT_SUMMON_TOTEM_SLOT4        = 90,
	SPELL_EFFECT_THREAT_ALL                = 91,
	SPELL_EFFECT_ENCHANT_HELD_ITEM         = 92,
	SPELL_EFFECT_SUMMON_PHANTASM           = 93,
	SPELL_EFFECT_SELF_RESURRECT            = 94,
	SPELL_EFFECT_SKINNING                  = 95,
	SPELL_EFFECT_CHARGE                    = 96,
	SPELL_EFFECT_SUMMON_CRITTER            = 97,
	SPELL_EFFECT_KNOCK_BACK                = 98,
	SPELL_EFFECT_DISENCHANT                = 99,
	SPELL_EFFECT_INEBRIATE                 = 100,
	SPELL_EFFECT_FEED_PET                  = 101,
	SPELL_EFFECT_DISMISS_PET               = 102,
	SPELL_EFFECT_REPUTATION                = 103,
	SPELL_EFFECT_SUMMON_OBJECT_SLOT1       = 104,
	SPELL_EFFECT_SUMMON_OBJECT_SLOT2       = 105,
	SPELL_EFFECT_SUMMON_OBJECT_SLOT3       = 106,
	SPELL_EFFECT_SUMMON_OBJECT_SLOT4       = 107,
	SPELL_EFFECT_DISPEL_MECHANIC           = 108,
	SPELL_EFFECT_SUMMON_DEAD_PET           = 109,
	SPELL_EFFECT_DESTROY_ALL_TOTEMS        = 110,
	SPELL_EFFECT_DURABILITY_DAMAGE         = 111,
	SPELL_EFFECT_SUMMON_DEMON              = 112,
	SPELL_EFFECT_RESURRECT_NEW             = 113,
	SPELL_EFFECT_ATTACK_ME                 = 114,
	SPELL_EFFECT_DURABILITY_DAMAGE_PCT     = 115,
	SPELL_EFFECT_SKIN_PLAYER_CORPSE        = 116,
	SPELL_EFFECT_SPIRIT_HEAL               = 117,
	SPELL_EFFECT_SKILL                     = 118,
	SPELL_EFFECT_APPLY_PET_AURA            = 119,
	SPELL_EFFECT_TELEPORT_GRAVEYARD        = 120,
	SPELL_EFFECT_NORMALIZED_WEAPON_DMG     = 121,
	SPELL_EFFECT_122                       = 122,
	SPELL_EFFECT_123                       = 123,
	SPELL_EFFECT_PLAYER_PULL               = 124,
	SPELL_EFFECT_REDUCE_THREAT_PERCENT     = 125,
	SPELL_EFFECT_STEAL_BENEFICIAL_BUFF     = 126,
	SPELL_EFFECT_PROSPECTING               = 127,
	SPELL_EFFECT_APPLY_AURA_NEW2           = 128,
	SPELL_EFFECT_129                       = 129,
	SPELL_EFFECT_130                       = 130,
	SPELL_EFFECT_131                       = 131,
	SPELL_EFFECT_132                       = 132,
	SPELL_EFFECT_UNLEARN_SPECIALIZATION    = 133,
	SPELL_EFFECT_134                       = 134,
	SPELL_EFFECT_135                       = 135,
	SPELL_EFFECT_136                       = 136,
	SPELL_EFFECT_137                       = 137,
	SPELL_EFFECT_138                       = 138,
	SPELL_EFFECT_139                       = 139,
	SPELL_EFFECT_140                       = 140,
	SPELL_EFFECT_141                       = 141,
	SPELL_EFFECT_TRIGGER_SPELL_WITH_VALUE  = 142,
	SPELL_EFFECT_143                       = 143,
	SPELL_EFFECT_144                       = 144,
	SPELL_EFFECT_145                       = 145,
	SPELL_EFFECT_146                       = 146,
	SPELL_EFFECT_147                       = 147,
	SPELL_EFFECT_148                       = 148,
	SPELL_EFFECT_149                       = 149,
	SPELL_EFFECT_150                       = 150,
	SPELL_EFFECT_TRIGGER_SPELL_2           = 151,
	SPELL_EFFECT_152                       = 152,
	SPELL_EFFECT_153                       = 153,
	TOTAL_SPELL_EFFECTS                    = 154
};


// Spell mechanics
enum Mechanics
{
	MECHANIC_NONE             = 0,
	MECHANIC_CHARM            = 1,
	MECHANIC_CONFUSED         = 2,
	MECHANIC_DISARM           = 3,
	MECHANIC_DISTRACT         = 4,
	MECHANIC_FEAR             = 5,
	MECHANIC_FUMBLE           = 6,
	MECHANIC_ROOT             = 7,
	MECHANIC_PACIFY           = 8,                          //0 spells use this mechanic
	MECHANIC_SILENCE          = 9,
	MECHANIC_SLEEP            = 10,
	MECHANIC_SNARE            = 11,
	MECHANIC_STUN             = 12,
	MECHANIC_FREEZE           = 13,
	MECHANIC_KNOCKOUT         = 14,
	MECHANIC_BLEED            = 15,
	MECHANIC_BANDAGE          = 16,
	MECHANIC_POLYMORPH        = 17,
	MECHANIC_BANISH           = 18,
	MECHANIC_SHIELD           = 19,
	MECHANIC_SHACKLE          = 20,
	MECHANIC_MOUNT            = 21,
	MECHANIC_PERSUADE         = 22,                         //0 spells use this mechanic
	MECHANIC_TURN             = 23,
	MECHANIC_HORROR           = 24,
	MECHANIC_INVULNERABILITY  = 25,
	MECHANIC_INTERRUPT        = 26,
	MECHANIC_DAZE             = 27,
	MECHANIC_DISCOVERY        = 28,
	MECHANIC_IMMUNE_SHIELD    = 29,                         // Divine (Blessing) Shield/Protection and Ice Block
	MECHANIC_SAPPED           = 30
};

// Used for spell 42292 Immune Movement Impairment and Loss of Control (0x49967da6)
#define IMMUNE_TO_MOVEMENT_IMPAIRMENT_AND_LOSS_CONTROL_MASK ( \
	(1<<MECHANIC_CHARM   )|(1<<MECHANIC_CONFUSED )|(1<<MECHANIC_FEAR  )| \
	(1<<MECHANIC_ROOT    )|(1<<MECHANIC_PACIFY   )|(1<<MECHANIC_SLEEP )| \
	(1<<MECHANIC_SNARE   )|(1<<MECHANIC_STUN     )|(1<<MECHANIC_FREEZE)| \
	(1<<MECHANIC_KNOCKOUT)|(1<<MECHANIC_POLYMORPH)|(1<<MECHANIC_BANISH)| \
	(1<<MECHANIC_SHACKLE )|(1<<MECHANIC_TURN     )|(1<<MECHANIC_HORROR)| \
	(1<<MECHANIC_DAZE    )|(1<<MECHANIC_SAPPED   ) )

// Spell dispell type
enum DispelType
{
	DISPEL_NONE         = 0,
	DISPEL_MAGIC        = 1,
	DISPEL_CURSE        = 2,
	DISPEL_DISEASE      = 3,
	DISPEL_POISON       = 4,
	DISPEL_STEALTH      = 5,
	DISPEL_INVISIBILITY = 6,
	DISPEL_ALL          = 7,
	DISPEL_SPE_NPC_ONLY = 8,
	DISPEL_ENRAGE       = 9,
	DISPEL_ZG_TICKET    = 10
};

#define DISPEL_ALL_MASK   ( \
	(1<<IMMUNE_DISPEL_MAGIC) | \
	(1<<IMMUNE_DISPEL_CURSE) | \
	(1<<IMMUNE_DISPEL_DISEASE) | \
	(1<<IMMUNE_DISPEL_POISON) )

enum SpellImmunity
{
	IMMUNITY_EFFECT                = 0,
	IMMUNITY_STATE                 = 1,
	IMMUNITY_SCHOOL                = 2,
	IMMUNITY_DAMAGE                = 3,
	IMMUNITY_DISPEL                = 4,
	IMMUNITY_MECHANIC              = 5
};

#define MAX_SPELL_IMMUNITY         6

enum ImmuneToDispel
{
	IMMUNE_DISPEL_MAGIC        = 1,
	IMMUNE_DISPEL_CURSE        = 2,
	IMMUNE_DISPEL_DISEASE      = 3,
	IMMUNE_DISPEL_POISON       = 4,
	IMMUNE_DISPEL_STEALTH      = 5,
	IMMUNE_DISPEL_INVISIBILITY = 6,
	IMMUNE_DISPEL_ALL          = 7,
	IMMUNE_DISPEL_SPE_NPC_ONLY = 8,
	IMMUNE_DISPEL_CRAZY        = 9,
	IMMUNE_DISPEL_ZG_TICKET    = 10
};

enum ImmuneToDamage
{
	IMMUNE_DAMAGE_PHYSICAL     = 1,
	IMMUNE_DAMAGE_MAGIC        = 126
};

enum ImmuneToSchool
{
	IMMUNE_SCHOOL_PHYSICAL     = 1,
	IMMUNE_SCHOOL_HOLY         = 2,
	IMMUNE_SCHOOL_FIRE         = 4,
	IMMUNE_SCHOOL_NATURE       = 8,
	IMMUNE_SCHOOL_FROST        = 16,
	IMMUNE_SCHOOL_SHADOW       = 32,
	IMMUNE_SCHOOL_ARCANE       = 64,
	IMMUNE_SCHOOL_MAGIC        = 126
};


enum CurrentSpellTypes
{
	CURRENT_MELEE_SPELL = 0,
	CURRENT_FIRST_NON_MELEE_SPELL = 1,                      // just counter
	CURRENT_GENERIC_SPELL = 1,
	CURRENT_AUTOREPEAT_SPELL = 2,
	CURRENT_CHANNELED_SPELL = 3,
	CURRENT_MAX_SPELL = 4                                   // just counter
};


enum SpellInterruptFlags
{
	SPELL_INTERRUPT_FLAG_MOVEMENT     = 0x01,
	SPELL_INTERRUPT_FLAG_DAMAGE       = 0x02,
	SPELL_INTERRUPT_FLAG_INTURRUPT    = 0x04,
	SPELL_INTERRUPT_FLAG_AUTOATTACK   = 0x08,
	//SPELL_INTERRUPT_FLAG_TURNING      = 0x10              // unknown, not turning
};


struct SkillLineAbilityEntry
{
	ui32    id;                                           // 0, INDEX
	ui32    skillId;                                      // 1
	ui32    spellId;                                      // 2
	ui32    racemask;                                     // 3
	ui32    classmask;                                    // 4
	//ui32    racemaskNot;                                // 5 always 0 in 2.4.2
	//ui32    classmaskNot;                               // 6 always 0 in 2.4.2
	ui32    req_skill_value;                              // 7 for trade skill.not for training.
	ui32    forward_spellid;                              // 8
	ui32    learnOnGetSkill;                              // 9 can be 1 or 2 for spells learned on get skill
	ui32    max_value;                                    // 10
	ui32    min_value;                                    // 11
	// 12-13, unknown, always 0
	ui32    reqtrainpoints;                               // 14
};


struct SkillLineEntry
{
	ui32    id;                                           // 0
	ui32    categoryId;                                   // 1 (index from SkillLineCategory.dbc)
	//ui32    skillCostID;                                // 2 not used
	char*     name[16];                                     // 3-18
	// 19 string flags, not used
	//char*     description[16];                            // 20-35, not used
	// 36 string flags, not used
	ui32    spellIcon;                                    // 37
};

struct SpellCastTimesEntry
{
	ui32    ID;
	ui32    CastTime;
};

struct SpellDurationEntry
{
	ui32    ID;
	i32     Duration[3];
};

struct SpellShapeshiftEntry
{
	ui32 ID;                                              // 0
	//uint32 buttonPosition;                                // 1 unused
	//char*  Name[16];                                      // 2-17 unused
	//uint32 NameFlags;                                     // 18 unused
	ui32 flags1;                                          // 19
	i32  creatureType;                                    // 20 <=0 humanoid, other normal creature types
	//uint32 unk1;                                          // 21 unused
	ui32 attackSpeed;                                     // 22
	//uint32 modelID;                                       // 23 unused, alliance modelid (where horde case?)
	//uint32 unk2;                                          // 24 unused
	//uint32 unk3;                                          // 25 unused
	//uint32 unk4;                                          // 26 unused
	//uint32 unk5;                                          // 27 unused
	//uint32 unk6;                                          // 28 unused
	//uint32 unk7;                                          // 29 unused
	//uint32 unk8;                                          // 30 unused
	//uint32 unk9;                                          // 31 unused
	//uint32 unk10;                                         // 32 unused
	//uint32 unk11;                                         // 33 unused
	//uint32 unk12;                                         // 34 unused
};

enum SkillCategory
{
	SKILL_CATEGORY_ATTRIBUTES    =  5,
	SKILL_CATEGORY_WEAPON        =  6,
	SKILL_CATEGORY_CLASS         =  7,
	SKILL_CATEGORY_ARMOR         =  8,
	SKILL_CATEGORY_SECONDARY     =  9,                      // secondary professions
	SKILL_CATEGORY_LANGUAGES     = 10,
	SKILL_CATEGORY_PROFESSION    = 11,                      // primary professions
	SKILL_CATEGORY_NOT_DISPLAYED = 12
};


enum SpellAuraInterruptFlags
{
	AURA_INTERRUPT_FLAG_UNK0                = 0x00000001,   // 0
	AURA_INTERRUPT_FLAG_DAMAGE              = 0x00000002,   // 1    removed by any damage
	AURA_INTERRUPT_FLAG_UNK2                = 0x00000004,   // 2
	AURA_INTERRUPT_FLAG_MOVE                = 0x00000008,   // 3    removed by any movement
	AURA_INTERRUPT_FLAG_TURNING             = 0x00000010,   // 4    removed by any turning
	AURA_INTERRUPT_FLAG_ENTER_COMBAT        = 0x00000020,   // 5    removed by entering combat
	AURA_INTERRUPT_FLAG_NOT_MOUNTED         = 0x00000040,   // 6    removed by unmounting
	AURA_INTERRUPT_FLAG_NOT_ABOVEWATER      = 0x00000080,   // 7    removed by entering water
	AURA_INTERRUPT_FLAG_NOT_UNDERWATER      = 0x00000100,   // 8    removed by leaving water
	AURA_INTERRUPT_FLAG_NOT_SHEATHED        = 0x00000200,   // 9    removed by unsheathing
	AURA_INTERRUPT_FLAG_UNK10               = 0x00000400,   // 10
	AURA_INTERRUPT_FLAG_UNK11               = 0x00000800,   // 11
	AURA_INTERRUPT_FLAG_UNK12               = 0x00001000,   // 12   removed by attack? 
	AURA_INTERRUPT_FLAG_UNK13               = 0x00002000,   // 13
	AURA_INTERRUPT_FLAG_UNK14               = 0x00004000,   // 14
	AURA_INTERRUPT_FLAG_UNK15               = 0x00008000,   // 15
	AURA_INTERRUPT_FLAG_UNK16               = 0x00010000,   // 16
	AURA_INTERRUPT_FLAG_MOUNTING            = 0x00020000,   // 17   removed by mounting
	AURA_INTERRUPT_FLAG_NOT_SEATED          = 0x00040000,   // 18   removed by standing up
	AURA_INTERRUPT_FLAG_UNK19               = 0x00080000,   // 19   leaving area/getting teleported?
	AURA_INTERRUPT_FLAG_UNK20               = 0x00100000,   // 20
	AURA_INTERRUPT_FLAG_UNK21               = 0x00200000,   // 21
	AURA_INTERRUPT_FLAG_UNK22               = 0x00400000,   // 22
	AURA_INTERRUPT_FLAG_ENTER_PVP_COMBAT    = 0x00800000,   // 23   removed by entering pvp combat
	AURA_INTERRUPT_FLAG_DIRECT_DAMAGE       = 0x01000000    // 24   removed by any direct damage
};

*/