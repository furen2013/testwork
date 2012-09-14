#pragma once
#include "../Public/ItemDef.h"
#include "../Protocol/PacketDef.h"

enum Stats
{
	STAT_STRENGTH,		//力量
	STAT_AGILITY,		//敏捷
	STAT_STAMINA,		//耐力
	STAT_INTELLECT,		//智力
	STAT_SPIRIT,		//精神
	STAT_VITALITY,		//体力
};

enum DeathState
{
	ALIVE = 0,  // Unit is alive and well
	JUST_DIED,  // Unit has JUST died
	CORPSE,	 // Unit has died but remains in the world as a corpse
	DEAD		// Unit is dead and his corpse is gone from the world
};

enum MoveOP
{
	MOVE_HEARTBEAT,														
	MOVE_START_FORWARD							,						
	MOVE_START_BACKWARD							,						
	MOVE_START_STRAFE_LEFT						,						
	MOVE_START_STRAFE_RIGHT						,			
	MOVE_STOP_STRAFE							,			
	MOVE_START_TURN_LEFT						,			
	MOVE_START_TURN_RIGHT						,			
	MOVE_STOP_TURN								,			
	MOVE_START_PITCH_UP							,			
	MOVE_START_PITCH_DOWN						,			
	MOVE_STOP_PITCH								,			
	MOVE_SET_RUN_MODE							,			
	MOVE_SET_WALK_MODE							,			
	MOVE_FALL_LAND								,			
	MOVE_STOP									,			
	MOVE_JUMP									,			
	MOVE_SET_FACING								,			
	MOVE_FLY_START_AND_END						,			
	MOVE_FLY_PITCH_DOWN_AFTER_UP					,		
	MOVE_FLY_PITCH_UP_Z								,		
	MOVE_SET_PITCH								,			
	MOVE_START_SWIM								,			
	MOVE_STOP_SWIM								,			
	MOVE_TRANSPORT_STEP_IN_OUT					,	
	MOVE_FLY_DOWN_UNK							,  
};															

enum MoveAck
{
	MOVE_FORCE_WALK_SPEED_CHANGE_ACK				,	
	MOVE_FEATHER_FALL_ACK						,	
	MOVE_WATER_WALK_ACK						,	
	MOVE_FORCE_SWIM_BACK_SPEED_CHANGE_ACK			,	
	MOVE_FORCE_TURN_RATE_CHANGE_ACK					,	
	MOVE_FORCE_RUN_SPEED_CHANGE_ACK,
	MOVE_FORCE_RUN_BACK_SPEED_CHANGE_ACK,
	MOVE_FORCE_SWIM_SPEED_CHANGE_ACK				,	
	MOVE_FORCE_MOVE_ROOT_ACK						,	
	MOVE_FORCE_MOVE_UNROOT_ACK,	
	MOVE_KNOCK_BACK_ACK						,	
	MOVE_HOVER_ACK								,	
	MOVE_SET_FLY_ACK							,
	MOVE_FORCE_FLY_BACK_SPEED_CHANGE_ACK			,	
	MOVE_FORCE_MOVE_SET_FLY_SPEED_ACK				,	
};
enum MovementFlags
{
	// Byte 1 (Resets on Movement Key Press)
	MOVEFLAG_MOVE_STOP                  = 0x00,			//verified
	MOVEFLAG_MOVE_FORWARD				= 0x01,			//verified
	MOVEFLAG_MOVE_BACKWARD				= 0x02,			//verified
	MOVEFLAG_STRAFE_LEFT				= 0x04,			//verified
	MOVEFLAG_STRAFE_RIGHT				= 0x08,			//verified
	MOVEFLAG_TURN_LEFT					= 0x10,			//verified
	MOVEFLAG_TURN_RIGHT					= 0x20,			//verified
	MOVEFLAG_PITCH_DOWN					= 0x40,			//Unconfirmed
	MOVEFLAG_PITCH_UP					= 0x80,			//Unconfirmed

	// Byte 2 (Resets on Situation Change)
	MOVEFLAG_WALK						= 0x100,		//verified
	MOVEFLAG_TAXI						= 0x200,
	MOVEMENTFALG_TAXI					= 0x00000300,
	MOVEFLAG_NO_COLLISION				= 0x400,
	MOVEFLAG_FLYING	    				= 0x800,		//verified
	MOVEFLAG_JUMPING					= 0x1000,		//Unconfirmed
	MOVEFLAG_FALLING					= 0x2000,       //verified
	MOVEFLAG_FALLING_FAR				= 0x4000,		//verified
	MOVEFLAG_FREE_FALLING				= 0x8000,		//half verified

	// Byte 3 (Set by server. TB = Third Byte. Completely unconfirmed.)
	MOVEFLAG_TB_PENDING_STOP			= 0x10000,		// (MOVEFLAG_PENDING_STOP)
	MOVEFLAG_TB_PENDING_UNSTRAFE		= 0x20000,		// (MOVEFLAG_PENDING_UNSTRAFE)
	MOVEFLAG_TB_PENDING_FALL			= 0x40000,		// (MOVEFLAG_PENDING_FALL)
	MOVEFLAG_TB_PENDING_FORWARD			= 0x80000,		// (MOVEFLAG_PENDING_FORWARD)
	MOVEFLAG_TB_PENDING_BACKWARD		= 0x100000,		// (MOVEFLAG_PENDING_BACKWARD)
	MOVEFLAG_SWIMMING          		    = 0x200000,		//  verified
	MOVEFLAG_FLYING_PITCH_UP	        = 0x400000,		// (half confirmed)(MOVEFLAG_PENDING_STR_RGHT)
	MOVEFLAG_TB_MOVED					= 0x800000,		// (half confirmed) gets called when landing (MOVEFLAG_MOVED)

	// Byte 4 (Script Based Flags. Never reset, only turned on or off.)
	MOVEFLAG_AIR_SUSPENSION	   	 		= 0x1000000,	// confirmed allow body air suspension(good name? lol).
	MOVEFLAG_AIR_SWIMMING				= 0x2000000,	// confirmed while flying.
	MOVEFLAG_SPLINE_MOVER				= 0x4000000,	// Unconfirmed
	MOVEFLAG_IMMOBILIZED				= 0x8000000,
	MOVEFLAG_WATER_WALK					= 0x10000000,
	MOVEFLAG_FEATHER_FALL				= 0x20000000,	// Does not negate fall damage.
	MOVEFLAG_LEVITATE					= 0x40000000,
	MOVEFLAG_LOCAL						= 0x80000000,	// This flag defaults to on. (Assumption)

	// Masks
	MOVEFLAG_MOVING_MASK				= 0x03,
	MOVEFLAG_STRAFING_MASK				= 0x0C,
	MOVEFLAG_TURNING_MASK				= 0x30,
	MOVEFLAG_FALLING_MASK				= 0x6000,
	MOVEFLAG_MOTION_MASK				= 0xE00F,		// Forwards, Backwards, Strafing, Falling
	MOVEFLAG_PENDING_MASK				= 0x7F0000,
	MOVEFLAG_PENDING_STRAFE_MASK		= 0x600000,
	MOVEFLAG_PENDING_MOVE_MASK			= 0x180000,
	MOVEFLAG_FULL_FALLING_MASK			= 0xE000,
};

class MovementInfo
{
public:
	uint32 flags;
	//uint8 unk1;
	uint32 time;
	// swimming and unk
	//float   s_pitch;
	//on slip 8 is zero, on jump some other number
	//9,10 changes if you are not on foot
	//uint32 unk11, unk13;
	//uint32 unklast;//something related to collision
	// spline
	//float   u_unk1;

	float x, y, z, orientation;
	//uint32 FallTime;// duration of last jump (when in jump duration from jump begin to now)
	float j_sinAngle, j_cosAngle, j_xyspeed;
	//uint64 transGuid;
	//float transX, transY, transZ, transO, transTime;
	void Init()
	{
		flags = 0;
		//unk1 = 0;
		time = 0;
		//s_pitch = 0.f;
		//unk11 = unk13 = 0;
		//unklast = 0;
		//u_unk1 = 0.f;
		x = y = z = orientation = 0.f;
		//FallTime = 0;
		j_sinAngle = j_cosAngle = j_xyspeed = 0.f;
		//transGuid = 0;
		//transX = transY = transZ = transO = transTime = 0.f;
	}
	CPacketSn& Sn(CPacketSn& cps) const 
	{
		cps << flags << time << x << y << z << orientation;
		if( flags & MOVEFLAG_JUMPING )
		{
			cps << j_sinAngle << j_cosAngle << j_xyspeed;
		}
		return cps; 
	}
	CPacketUsn& Usn(CPacketUsn& cpu)	
	{
		cpu >> flags >> time >> x >> y >> z >> orientation;
		if( flags & MOVEFLAG_JUMPING )
		{
			cpu >> j_sinAngle >> j_cosAngle >> j_xyspeed;
		}
		else
		{
			j_sinAngle = j_cosAngle = j_xyspeed = 0.0f;
		}
		return cpu; 
	}

};

enum NPCFlags {
	//									Hex				Decimal			Bit  Comments
	UNIT_NPC_FLAG_NONE				= 0x00000000,	//0,			01
	UNIT_NPC_FLAG_GOSSIP			= 0x00000001,	//1,			02	对话npc Gossip/Talk (CMSG_GOSSIP_HELLO)
	UNIT_NPC_FLAG_QUESTGIVER		= 0x00000002,	//2,			03	任务npc
	UNIT_NPC_FLAG_TRAINER_CLASS		= 0x00000004,	//4,			07	职业技能训练师
 	UNIT_NPC_FLAG_TRAINER_PROF		= 0x00000008,	//8,			08	专业训练师
	UNIT_NPC_FLAG_VENDOR			= 0x00000010,	//16,			09	道具商 (CMSG_LIST_INVENTORY)
	UNIT_NPC_FLAG_ARMORER			= 0x00000020,	//32,			14	修理商
	UNIT_NPC_FLAG_TAXIVENDOR		= 0x00000040,	//64,			15	飞行管理员 (CMSG_TAXIQUERYAVAILABLENODES)
	UNIT_NPC_FLAG_INNKEEPER			= 0x00000080,	//128,		18	旅店老板 Innkeeper Asking for Bind Point
	UNIT_NPC_FLAG_BANKER			= 0x00000100,	//256 ,		19	银行管理员
	UNIT_NPC_FLAG_ARENACHARTER		= 0x00000200,	//512,		20	竞技场管理员 GuildMasters also have UNIT_NPC_FLAG_TABARDCHANGER!!
	UNIT_NPC_FLAG_BATTLEFIELDPERSON	= 0x00000400,	//1024,		22	战场管理员BattleMaster (CMSG_BATTLEMASTER_HELLO (0x02D7))
	UNIT_NPC_FLAG_AUCTIONEER		= 0x00000800,	//2048,		23	拍卖行管理员 Auctioneer (MSG_AUCTION_HELLO)
	UNIT_NPC_FLAG_GUILD_BANK		= 0x00001000,	//4096,		25  工会银行
	UNIT_NPC_FLAG_MAIL				= 0x00002000,	//8192			邮件
	UNIT_NPC_FLAG_TRANSPORTER		= 0x00004000,	//				传送
	UNIT_NPC_FLAG_GUILD				= 0x00008000,	//				部族管理员
	UNIT_NPC_FLAG_VENDOR_ZAHUO      = 0x10000000,	//杂货
	UNIT_NPC_FLAG_VENDOR_YAOSHUI	= 0x20000000,	//药水
	UNIT_NPC_FLAG_VENDOR_WUQI		= 0x40000000,	//武器
	UNIT_NPC_FLAG_VENDOR_FANGJU		= 0x80000000,	//防具
	UNIT_NPC_FLAG_VENDOR_SHOUSHI	= 0x01000000,	//首饰
	UNIT_NPC_FLAG_VENDOR_ZUOQI		= 0x02000000,	//坐骑
	UNIT_NPC_FLAG_TRAINER_WUXIU		= 0x04000000,	//武修
	UNIT_NPC_FLAG_TRAINER_YUJIAN	= 0x08000000,	//羽箭
	UNIT_NPC_FLAG_TRAINER_XIANDAO	= 0x00100000,	//仙道
	UNIT_NPC_FLAG_TRAINER_ZHENWU	= 0x00200000,	//真巫
	UNIT_NPC_FLAG_JIAYUAN			= 0x00400000,	//家园
	UNIT_NPC_FLAG_BAISHI			= 0x00800000,	// 拜师
};

#define POWER_TYPE_HEALTH -2
#define POWER_TYPE_MANA 0



enum UnitSpecialStates
{
	UNIT_STATE_NORMAL    = 0x0000,
	UNIT_STATE_DISARMED  = 0X0001,
	UNIT_STATE_CHARM     = 0x0002,
	UNIT_STATE_FEAR      = 0x0004,
	UNIT_STATE_ROOT      = 0x0008,
	UNIT_STATE_SLEEP     = 0x0010,  // never set
	UNIT_STATE_SNARE     = 0x0020,  // never set
	UNIT_STATE_STUN      = 0x0040,
	UNIT_STATE_KNOCKOUT  = 0x0080,  // not used
	UNIT_STATE_BLEED     = 0x0100,  // not used
	UNIT_STATE_POLYMORPH = 0x0200,  // not used
	UNIT_STATE_BANISH    = 0x0400,  // not used
	UNIT_STATE_CONFUSE   = 0x0800,
	UNIT_STATE_PACIFY    = 0x1000,
	UNIT_STATE_SILENCE   = 0x2000,
	UNIT_STATE_FROZEN    = 0x4000,
	UNIT_STATE_STORM     = 0x8000,
};

enum UnitFieldBytes1
{
	U_FIELD_BYTES_ANIMATION_FROZEN = 0x01,
};

enum UnitFieldBytes2
{
	U_FIELD_BYTES_HIDE_POS_AURAS = 0x01,
};

enum UnitDynamicFlags
{
	U_DYN_FLAG_LOOTABLE				 = 0x01,
	U_DYN_FLAG_UNIT_TRACKABLE		   = 0x02,
	U_DYN_FLAG_TAGGED_BY_OTHER		  = 0x04,
	U_DYN_FLAG_TAPPED_BY_PLAYER		 = 0x08,
	U_DYN_FLAG_PLAYER_INFO			  = 0x10,
	U_DYN_FLAG_DEAD					 = 0x20,
};
// #define POWER_TYPE_RAGE 1
// #define POWER_TYPE_FOCUS 2
// #define POWER_TYPE_ENERGY 3
// we have power type 15 and 31 :S

/*
enum ECreatureType
{
	eCreatureNone = 0,
	eCreaturePlayer,
	eCreatureMonster,
	eCreatureNPC,
};

enum ECreatureState
{
	eCreatureStateLive = 0,
	eCreatureStateDie,//死亡,尸体完整的
	eCreatureStateDebris,//残骸,被挖过的
	eCreatureStateDisappear,
	eCreatureStateNum,
};

//
//	角色外观数据 
//
typedef struct _tagCHARACTER_APPEARANCE
{
	//ui8		basic_head;		//	基本头部		
	//ui8		basic_figure;	//	基本体型		
	//ui8		skin_color;		//	肤    色		
	//ui8		lip;			//	嘴    唇		
	//ui8		eyeball;		//	眼    球

	//ui32	Head;			//	发型			
	//ui32	Shirt;			//	耳朵			
	//ui32	Gloves;			//	脸部1			
	//ui32	Legs;			//	脸部2
	//ui32	Boots;			//	上半身
	//ui32	Hair;			//	下半身
	//ui32	Mask;			//	手部
	//ui32	RightShoulder;			//	手指
	//ui32	LeftShoulder;			//	脚部
	//ui32	Necklace;			//	背部
	//ui32    Chest;		//	武器
	//ui32	Belt;
	//ui32	RightWeapon;
	//ui32	LeftWeapon;
	//ui32	KneeCap;
	//ui32	RightKneeCap;
	//ui32	LeftKneeCap;
	//ui32	Ride;
	//ui32	Cape;

	struct
	{
		ui32	nModelIdx;

	}Appear[ITS_COUNT];

	CPacketSn& Sn(CPacketSn& cps) const {cps.AddBuf(Appear, sizeof(Appear)); return cps;}
	CPacketUsn& Usn(CPacketUsn& cpu) {cpu.GetBuf(Appear, sizeof(Appear)); return cpu;}
}CHARACTER_APPEARANCE,*PCHARACTER_APPEARANCE;



enum BaseModGroup
{
	CRIT_PERCENTAGE,
	SHIELD_BLOCK_VALUE,
	BASEMOD_END
};

enum BaseModType
{
	FLAT_MOD,
	PCT_MOD
};

#define MOD_END (PCT_MOD+1)
enum DeathState
{
	ALIVE       = 0,
	JUST_DIED   = 1,
	CORPSE      = 2,
	DEAD        = 3,
	JUST_ALIVED = 4
};

// Value masks for UNIT_FIELD_FLAGS
enum UnitFlags
{
	UNIT_FLAG_UNKNOWN7       = 0x00000001,
	UNIT_FLAG_NON_ATTACKABLE = 0x00000002,                  // not attackable
	UNIT_FLAG_DISABLE_MOVE   = 0x00000004,
	UNIT_FLAG_UNKNOWN1       = 0x00000008,                  // for all units, make unit attackable even it's friendly in some cases...
	UNIT_FLAG_RENAME         = 0x00000010,
	UNIT_FLAG_RESTING        = 0x00000020,
	UNIT_FLAG_UNKNOWN9       = 0x00000040,
	UNIT_FLAG_UNKNOWN10      = 0x00000080,
	UNIT_FLAG_UNKNOWN2       = 0x00000100,                  // 2.0.8
	UNIT_FLAG_UNKNOWN11      = 0x00000200,
	UNIT_FLAG_LOOTING        = 0x00000400,                  // loot animation
	UNIT_FLAG_PET_IN_COMBAT  = 0x00000800,                  // in combat?, 2.0.8
	UNIT_FLAG_PVP            = 0x00001000,                  // ok
	UNIT_FLAG_SILENCED       = 0x00002000,                  // silenced, 2.1.1
	UNIT_FLAG_UNKNOWN4       = 0x00004000,                  // 2.0.8
	UNIT_FLAG_UNKNOWN13      = 0x00008000,
	UNIT_FLAG_UNKNOWN14      = 0x00010000,
	UNIT_FLAG_PACIFIED       = 0x00020000,
	UNIT_FLAG_DISABLE_ROTATE = 0x00040000,                  // stunned, 2.1.1
	UNIT_FLAG_IN_COMBAT      = 0x00080000,
	UNIT_FLAG_TAXI_FLIGHT    = 0x00100000,                  // disbale casting at client side spell not allowed by taxi flight (mounted?), probably used with 0x4 flag
	UNIT_FLAG_DISARMED       = 0x00200000,                  // disable melee spells casting..., "Required melee weapon" added to melee spells tooltip.
	UNIT_FLAG_CONFUSED       = 0x00400000,
	UNIT_FLAG_FLEEING        = 0x00800000,
	UNIT_FLAG_UNKNOWN5       = 0x01000000,                  // used in spell Eyes of the Beast for pet...
	UNIT_FLAG_NOT_SELECTABLE = 0x02000000,                  // ok
	UNIT_FLAG_SKINNABLE      = 0x04000000,
	UNIT_FLAG_MOUNT          = 0x08000000,                  // the client seems to handle it perfectly
	UNIT_FLAG_UNKNOWN17      = 0x10000000,
	UNIT_FLAG_UNKNOWN6       = 0x20000000,                  // used in Feing Death spell
	UNIT_FLAG_SHEATHE        = 0x40000000
};


enum UnitState
{
	UNIT_STAT_STOPPED         = 0,
	UNIT_STAT_DIED            = 1,
	UNIT_STAT_MELEE_ATTACKING = 2,                          // player is melee attacking someone
	//UNIT_STAT_MELEE_ATTACK_BY = 4,                          // player is melee attack by someone
	UNIT_STAT_STUNDED         = 8,
	UNIT_STAT_ROAMING         = 16,
	UNIT_STAT_CHASE           = 32,
	UNIT_STAT_SEARCHING       = 64,
	UNIT_STAT_FLEEING         = 128,
	UNIT_STAT_MOVING          = (UNIT_STAT_ROAMING | UNIT_STAT_CHASE | UNIT_STAT_SEARCHING | UNIT_STAT_FLEEING),
	UNIT_STAT_IN_FLIGHT       = 256,                        // player is in flight mode
	UNIT_STAT_FOLLOW          = 512,
	UNIT_STAT_ROOT            = 1024,
	UNIT_STAT_CONFUSED        = 2048,
	UNIT_STAT_ALL_STATE       = 0xffff                      //(UNIT_STAT_STOPPED | UNIT_STAT_MOVING | UNIT_STAT_IN_COMBAT | UNIT_STAT_IN_FLIGHT)
};

enum UnitMoveType
{
	MOVE_WALK       = 0,
	MOVE_RUN        = 1,
	MOVE_WALKBACK   = 2,
	MOVE_SWIM       = 3,
	MOVE_SWIMBACK   = 4,
	MOVE_TURN       = 5,
	MOVE_FLY        = 6,
	MOVE_FLYBACK    = 7
};

#define MAX_MOVE_TYPE 8

enum UnitDynFlags
{
	UNIT_DYNFLAG_LOOTABLE          = 0x0001,
	UNIT_DYNFLAG_TRACK_UNIT        = 0x0002,
	UNIT_DYNFLAG_OTHER_TAGGER      = 0x0004,
	UNIT_DYNFLAG_ROOTED            = 0x0008,
	UNIT_DYNFLAG_SPECIALINFO       = 0x0010,
	UNIT_DYNFLAG_DEAD              = 0x0020
};
enum ShapeshiftForm
{
	FORM_NONE               = 0x00,
	FORM_CAT                = 0x01,
	FORM_TREE               = 0x02,
	FORM_TRAVEL             = 0x03,
	FORM_AQUA               = 0x04,
	FORM_BEAR               = 0x05,
	FORM_AMBIENT            = 0x06,
	FORM_GHOUL              = 0x07,
	FORM_DIREBEAR           = 0x08,
	FORM_CREATUREBEAR       = 0x0E,
	FORM_CREATURECAT        = 0x0F,
	FORM_GHOSTWOLF          = 0x10,
	FORM_BATTLESTANCE       = 0x11,
	FORM_DEFENSIVESTANCE    = 0x12,
	FORM_BERSERKERSTANCE    = 0x13,
	FORM_TEST               = 0x14,
	FORM_ZOMBIE             = 0x15,
	FORM_FLIGHT_EPIC        = 0x1B,
	FORM_SHADOW             = 0x1C,
	FORM_FLIGHT             = 0x1D,
	FORM_STEALTH            = 0x1E,
	FORM_MOONKIN            = 0x1F,
	FORM_SPIRITOFREDEMPTION = 0x20
};
extern float baseMoveSpeed[MAX_MOVE_TYPE];

enum WeaponAttackType
{
	BASE_ATTACK   = 0,
};

#define MAX_ATTACK  1

enum DamageEffectType
{
	DIRECT_DAMAGE           = 0,                            // used for normal weapon damage (not for class abilities or spells)
	SPELL_DIRECT_DAMAGE     = 1,                            // spell/class abilities damage
	DOT                     = 2,
	HEAL                    = 3,
	NODAMAGE                = 4,                            // used also in case when damage applied to health but not applied to spell channelInterruptFlags/etc
	SELF_DAMAGE             = 5
};

struct CleanDamage
{
	CleanDamage(ui32 _damage, WeaponAttackType _attackType, MeleeHitOutcome _hitOutCome) :
damage(_damage), attackType(_attackType), hitOutCome(_hitOutCome) {}

ui32 damage;
WeaponAttackType attackType;
MeleeHitOutcome hitOutCome;
};
enum UnitVisibility
{
	VISIBILITY_OFF                = 0,                      // absolute, not detectable, GM-like, can see all other
	VISIBILITY_ON                 = 1,
	VISIBILITY_GROUP_STEALTH      = 2,                      // detect chance, seen and can see group members
	VISIBILITY_GROUP_INVISIBILITY = 3,                      // invisibility, can see and can be seen only another invisible unit or invisible detection unit
	VISIBILITY_GROUP_NO_DETECT    = 4                       // state just at stealth apply for update Grid state
};

/// Non Player Character flags
enum NPCFlags
{
	UNIT_NPC_FLAG_NONE                  = 0x00000000,
	UNIT_NPC_FLAG_GOSSIP                = 0x00000001,       // 100%
	UNIT_NPC_FLAG_QUESTGIVER            = 0x00000002,       // guessed, probably ok
	UNIT_NPC_FLAG_UNK1                  = 0x00000004,
	UNIT_NPC_FLAG_UNK2                  = 0x00000008,
	UNIT_NPC_FLAG_TRAINER               = 0x00000010,       // 100%
	UNIT_NPC_FLAG_TRAINER_CLASS         = 0x00000020,       // 100%
	UNIT_NPC_FLAG_TRAINER_PROFESSION    = 0x00000040,       // 100%
	UNIT_NPC_FLAG_VENDOR                = 0x00000080,       // 100%
	UNIT_NPC_FLAG_VENDOR_AMMO           = 0x00000100,       // 100%, general goods vendor
	UNIT_NPC_FLAG_VENDOR_FOOD           = 0x00000200,       // 100%
	UNIT_NPC_FLAG_VENDOR_POISON         = 0x00000400,       // guessed
	UNIT_NPC_FLAG_VENDOR_REAGENT        = 0x00000800,       // 100%
	UNIT_NPC_FLAG_REPAIR                = 0x00001000,       // 100%
	UNIT_NPC_FLAG_FLIGHTMASTER          = 0x00002000,       // 100%
	UNIT_NPC_FLAG_SPIRITHEALER          = 0x00004000,       // guessed
	UNIT_NPC_FLAG_SPIRITGUIDE           = 0x00008000,       // guessed
	UNIT_NPC_FLAG_INNKEEPER             = 0x00010000,       // 100%
	UNIT_NPC_FLAG_BANKER                = 0x00020000,       // 100%
	UNIT_NPC_FLAG_PETITIONER            = 0x00040000,       // 100% 0xC0000 = guild petitions, 0x40000 = arena team petitions
	UNIT_NPC_FLAG_TABARDDESIGNER        = 0x00080000,       // 100%
	UNIT_NPC_FLAG_BATTLEMASTER          = 0x00100000,       // 100%
	UNIT_NPC_FLAG_AUCTIONEER            = 0x00200000,       // 100%
	UNIT_NPC_FLAG_STABLEMASTER          = 0x00400000,       // 100%
	UNIT_NPC_FLAG_GUILD_BANKER          = 0x00800000,       // cause client to send 997 opcode
	UNIT_NPC_FLAG_UNK3                  = 0x01000000,       // cause client to send 1015 opcode
	UNIT_NPC_FLAG_GUARD                 = 0x10000000,       // custom flag for guards
};
enum MovementFlags
{
	MOVEMENTFLAG_NONE           = 0x00000000,
	MOVEMENTFLAG_FORWARD        = 0x00000001,
	MOVEMENTFLAG_BACKWARD       = 0x00000002,
	MOVEMENTFLAG_STRAFE_LEFT    = 0x00000004,
	MOVEMENTFLAG_STRAFE_RIGHT   = 0x00000008,
	MOVEMENTFLAG_LEFT           = 0x00000010,
	MOVEMENTFLAG_RIGHT          = 0x00000020,
	MOVEMENTFLAG_PITCH_UP       = 0x00000040,
	MOVEMENTFLAG_PITCH_DOWN     = 0x00000080,
	MOVEMENTFLAG_WALK_MODE      = 0x00000100,               // Walking
	MOVEMENTFLAG_ONTRANSPORT    = 0x00000200,               // Used for flying on some creatures
	MOVEMENTFLAG_LEVITATING     = 0x00000400,
	MOVEMENTFLAG_FLY_UNK1       = 0x00000800,
	MOVEMENTFLAG_JUMPING        = 0x00001000,
	MOVEMENTFLAG_UNK4           = 0x00002000,
	MOVEMENTFLAG_FALLING        = 0x00004000,
	// 0x8000, 0x10000, 0x20000, 0x40000, 0x80000, 0x100000
	MOVEMENTFLAG_SWIMMING       = 0x00200000,               // appears with fly flag also
	MOVEMENTFLAG_FLY_UP         = 0x00400000,
	MOVEMENTFLAG_CAN_FLY        = 0x00800000,
	MOVEMENTFLAG_FLYING         = 0x01000000,
	MOVEMENTFLAG_FLYING2        = 0x02000000,               // Actual flying mode
	MOVEMENTFLAG_SPLINE         = 0x04000000,               // used for flight paths
	MOVEMENTFLAG_SPLINE2        = 0x08000000,               // used for flight paths
	MOVEMENTFLAG_WATERWALKING   = 0x10000000,               // prevent unit from falling through water
	MOVEMENTFLAG_SAFE_FALL      = 0x20000000,               // active rogue safe fall spell (passive)
	MOVEMENTFLAG_UNK3           = 0x40000000
};


enum Team
{
	HORDE               = 67,
	ALLIANCE            = 469,
};



enum TrainerType                                            // this is important type for npcs!
{
	TRAINER_TYPE_CLASS             = 0,
	TRAINER_TYPE_MOUNTS            = 1,                     // on blizz it's 2
	TRAINER_TYPE_TRADESKILLS       = 2,
	TRAINER_TYPE_PETS              = 3
};

#define MAX_TRAINER_TYPE 4

enum CreatureType
{
	CREATURE_TYPE_BEAST            = 1,
	CREATURE_TYPE_DRAGON           = 2,
	CREATURE_TYPE_DEMON            = 3,
	CREATURE_TYPE_ELEMENTAL        = 4,
	CREATURE_TYPE_GIANT            = 5,
	CREATURE_TYPE_UNDEAD           = 6,
	CREATURE_TYPE_HUMANOID         = 7,
	CREATURE_TYPE_CRITTER          = 8,
	CREATURE_TYPE_MECHANICAL       = 9,
	CREATURE_TYPE_NOTSPECIFIED     = 10,
	CREATURE_TYPE_TOTEM            = 11,
	CREATURE_TYPE_NON_COMBAT_PET   = 12,
	CREATURE_TYPE_GAS_CLOUD        = 13
};

ui32 const CREATURE_TYPEMASK_HUMANOID_OR_UNDEAD = (1 << (CREATURE_TYPE_HUMANOID-1)) | (1 << (CREATURE_TYPE_UNDEAD-1));
*/