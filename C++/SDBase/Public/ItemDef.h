#pragma once
#include "../Public/TypeDef.h"
#include "../Protocol/PacketDef.h"
#include "../Public/itemprototype.h"

struct ItemPage
{
	uint32 id;
	char * text;
	uint32 next_page;
};

#pragma pack(push, 1)

typedef struct item_extra_data
{
	uint8 hole_cnt;
	uint32 hole_1,hole_2,hole_3;
	uint8 jinglian_level;
	uint8 xiangqian_level;
	uint32 property[2];
	item_extra_data()
	{
		memset(this, 0, sizeof(item_extra_data));
	}
}ItemExtraData;

typedef struct tagTradeItem
{
	ui32	entry;
	ui32	displayinfoid;
	ui32	stackcount;			//	��������
	ui64	giftcreator;
	ui64	creator;
	ui32	spellcharge;
	ItemExtraData extra;
	ui32	maxduration;		//	����;�
	ui32	duration;			//	�;�
	tagTradeItem()
	{
		entry	= 0;
	}
}TradeItem;

#pragma pack(pop)

#define PARTY_LOOT_FFA	  0
#define PARTY_LOOT_MASTER   2
#define PARTY_LOOT_RR	   1
#define PARTY_LOOT_NBG	  4
#define PARTY_LOOT_GROUP	3


enum LootType
{
	LOOT_CORPSE                 = 1,
	LOOT_SKINNING               = 2,
	LOOT_FISHING                = 3,
	LOOT_PICKPOCKETING          = 2,                        // 4 unsupported by client, sending LOOT_SKINNING instead
	LOOT_DISENCHANTING          = 2,                        // 5 unsupported by client, sending LOOT_SKINNING instead
	LOOT_PROSPECTING            = 2,                        // 6 unsupported by client, sending LOOT_SKINNING instead
	LOOT_INSIGNIA               = 2                         // 7 unsupported by client, sending LOOT_SKINNING instead
};
/*
typedef enum
{
	ICT_INVLALID = 0,
	ICT_BAG,
	ICT_EQUIP,
	ICT_DEPOT,
	ICT_INVALID_POS = 0xFFFE,
	//ICT_MAP
}ITEM_CONTAINER_TYPE;

//
//	�����ඨ�塪����Ʒ������
//
typedef enum
{
	ITP_INVALID = 0,
	ITP_WEAPON,				//	����
	ITP_CLOTHES,			//	����
	ITP_CONSUME,			//	����Ʒ
	ITP_PETITEM,			//	�������
	ITP_TASK,				//	�������
	ITP_MATERIAL,			//	��������
	ITP_GEM,				//	��ʯ
}ITEM_TYPE_PRIMARY;

//
//	�η��ඨ�塪����Ʒ��װ��λ�õĶ���
//
typedef enum
{
	ITS_INVALID = 0,		//	����װ����Ʒ
	ITS_Head,			//ͷ��
	ITS_Shirt,			// �·�
	ITS_Gloves,			// ��
	ITS_Legs,			// ��
	ITS_BootsS,			// Ь
	ITS_Shoulder,		// ���
	ITS_Chest,			// �ؼ�
	ITS_Belt,			// ����
	ITS_Kneecap,		// ��ϥ
	// ���ص�
	ITS_Weapon,			// ����
	ITS_Hair_Node,		// ͷ��
	ITS_Necklace_Node,	// ����
	//ITS_RightHand_Node,	// ��������
	//ITS_LeftHand_Node,	// ��������
	ITS_Ride_Node,		// ��˵�
	ITS_COUNT,				//	װ��λ�õ�����
}ITEM_TYPE_SECONDARY;

const ui32	Default_Equip[eJobNum][ITS_COUNT][3] = 
{
	0,0,0,
	0,0,0,
	2,2,1,
	2,3,1,
	2,4,1,
	2,5,1,
	0,0,0,
	0,0,0,
	0,0,0,
	0,0,0,
	0,0,0,
	0,0,0,
	0,0,0,
	0,0,0,
	//0,0,0,

	0,0,0,
	0,0,0,
	2,2,1,
	2,3,1,
	2,4,1,
	2,5,1,
	0,0,0,
	0,0,0,
	0,0,0,
	0,0,0,
	0,0,0,
	0,0,0,
	0,0,0,
	0,0,0,
	//0,0,0,

	0,0,0,
	0,0,0,
	2,2,1,
	2,3,1,
	2,4,1,
	2,5,1,
	0,0,0,
	0,0,0,
	0,0,0,
	0,0,0,
	0,0,0,
	0,0,0,
	0,0,0,
	//0,0,0,
};

typedef union
{
	struct  
	{						
		ui16	typeid_3;		//	������Index		smallint
		ui8	typeid_2;		//	�η���			tinyint		��Ӧ ITEM_TYPE_SECONDARY
		ui8	typeid_1;		//	������			tinyint		��Ӧ ITEM_TYPE_PRIMARY
	}	sep_val;
	ui32	com_val;
}ITEM_ID;

typedef enum
{
	//�޸Ĵ����ݽṹ��Ҫ�޸� 
	//���ǽ���������Ч����֤
	PAI_INVALID			= 0,	//	invalid value

	PAI_eqp_pos_block	= 255,	//	����װ������װ��λ�õı�ʾ

}PAI_ITEM;

typedef enum
{
	EPI_INVALID			= 0,
}EPI_ITEM;

struct _ItemStat
{
	ui32 ItemStatType;
	i32  ItemStatValue;

};

// masks for ITEM_FIELD_FLAGS field
enum ITEM_FLAGS
{
	ITEM_FLAGS_BINDED                         = 0x00000001,
	ITEM_FLAGS_CONJURED                       = 0x00000002,
	ITEM_FLAGS_OPENABLE                       = 0x00000004,
	ITEM_FLAGS_WRAPPED                        = 0x00000008,
	ITEM_FLAGS_WRAPPER                        = 0x00000200, // used or not used wrapper
	ITEM_FLAGS_PARTY_LOOT                     = 0x00000800, // determines if item is party loot or not
	ITEM_FLAGS_CHARTER                        = 0x00002000, // arena/guild charter
	ITEM_FLAGS_UNIQUE_EQUIPPED                = 0x00080000,
	ITEM_FLAGS_THROWABLE                      = 0x00400000, // not used in game for check trow possibility, only for item in game tooltip
	ITEM_FLAGS_SPECIALUSE                     = 0x00800000  // last used flag in 2.3.0
};


enum ItemModType
{
	ITEM_MOD_MANA                     = 0,
	ITEM_MOD_HEALTH                   = 1,
	ITEM_MOD_AGILITY                  = 3,
	ITEM_MOD_STRENGTH                 = 4,
	ITEM_MOD_INTELLECT                = 5,
	ITEM_MOD_SPIRIT                   = 6,
	ITEM_MOD_STAMINA                  = 7,
	ITEM_MOD_DEFENSE_SKILL_RATING     = 12,
	ITEM_MOD_DODGE_RATING             = 13,
	ITEM_MOD_PARRY_RATING             = 14,
	ITEM_MOD_BLOCK_RATING             = 15,
	ITEM_MOD_HIT_MELEE_RATING         = 16,
	ITEM_MOD_HIT_SPELL_RATING         = 18,
	ITEM_MOD_CRIT_MELEE_RATING        = 19,
	ITEM_MOD_CRIT_SPELL_RATING        = 21,
	ITEM_MOD_HIT_TAKEN_MELEE_RATING   = 22,
	ITEM_MOD_HIT_TAKEN_SPELL_RATING   = 24,
	ITEM_MOD_CRIT_TAKEN_MELEE_RATING  = 25,
	ITEM_MOD_CRIT_TAKEN_SPELL_RATING  = 27,
	ITEM_MOD_HASTE_MELEE_RATING       = 28,
	ITEM_MOD_HASTE_SPELL_RATING       = 30,
	ITEM_MOD_HIT_RATING               = 31,
	ITEM_MOD_CRIT_RATING              = 32,
	ITEM_MOD_HIT_TAKEN_RATING         = 33,
	ITEM_MOD_CRIT_TAKEN_RATING        = 34,
	ITEM_MOD_RESILIENCE_RATING        = 35,
	ITEM_MOD_HASTE_RATING             = 36,
};

#define MAX_ITEM_MOD                    38


enum InventoryType
{
	INVTYPE_NON_EQUIP                           = 0,
	INVTYPE_WEAPON,			//����
	INVTYPE_HEAD,			//ͷ��
	INVTYPE_SHOULDER,		//�粿
	INVTYPE_CHEST,			//�ز�
	INVTYPE_WAIST,			//����
	INVTYPE_KNEECAP,		//��ϥ
	INVTYPE_DRESS,			//����
	INVTYPE_FINGER1,		//��ָ1
	INVTYPE_FINGER2,		//��ָ2
	INVTYPE_NECK,			//����
	INVTYPE_TRINKET,		//��Ʒ                     ,

	INVTYPE_HAIR,			//����
	INVITPE_GLOVES,			//����
	INVTYPE_WEAR,			//����,
	INVTYPE_TROUSERS,		//����
	INVTYPE_BOOTS,			//Ь��                    ,

	INVTYPE_2HWEAPON                           ,
	INVTYPE_BAG                                 ,
};

#define MAX_INVTYPE                               30
enum ItemClass
{
	ITEM_CLASS_CONSUMABLE                       = 0,
	ITEM_CLASS_CONTAINER                        = 1,
	ITEM_CLASS_WEAPON                           = 2,
	ITEM_CLASS_GEM                              = 3,
	ITEM_CLASS_ARMOR                            = 4,
	ITEM_CLASS_REAGENT                          = 5,
	ITEM_CLASS_PROJECTILE                       = 6,
	ITEM_CLASS_TRADE_GOODS                      = 7,
	ITEM_CLASS_GENERIC                          = 8,
	ITEM_CLASS_RECIPE                           = 9,
	ITEM_CLASS_MONEY                            = 10,
	ITEM_CLASS_QUIVER                           = 11,
	ITEM_CLASS_QUEST                            = 12,
	ITEM_CLASS_KEY                              = 13,
	ITEM_CLASS_PERMANENT                        = 14,
	ITEM_CLASS_JUNK                             = 15
};

#define MAX_ITEM_CLASS                            16

enum ItemSubclassConsumable
{
	ITEM_SUBCLASS_CONSUMABLE                    = 0,
	ITEM_SUBCLASS_POTION                        = 1,
	ITEM_SUBCLASS_ELIXIR                        = 2,
	ITEM_SUBCLASS_FLASK                         = 3,
	ITEM_SUBCLASS_SCROLL                        = 4,
	ITEM_SUBCLASS_FOOD                          = 5,
	ITEM_SUBCLASS_ITEM_ENHANCEMENT              = 6,
	ITEM_SUBCLASS_BANDAGE                       = 7,
	ITEM_SUBCLASS_CONSUMABLE_OTHER              = 8,
	ITEM_SUBCLASS_HP,
	ITEM_SUBCLASS_MP,
};

#define MAX_ITEM_SUBCLASS_CONSUMABLE              9

enum ItemSubclassContainer
{
	ITEM_SUBCLASS_CONTAINER                     = 0,
	ITEM_SUBCLASS_SOUL_CONTAINER                = 1,
	ITEM_SUBCLASS_HERB_CONTAINER                = 2,
	ITEM_SUBCLASS_ENCHANTING_CONTAINER          = 3,
	ITEM_SUBCLASS_ENGINEERING_CONTAINER         = 4,
	ITEM_SUBCLASS_GEM_CONTAINER                 = 5,
	ITEM_SUBCLASS_MINING_CONTAINER              = 6,
	ITEM_SUBCLASS_LEATHERWORKING_CONTAINER      = 7
};

#define MAX_ITEM_SUBCLASS_CONTAINER               8

enum ItemSubclassWeapon
{
	ITEM_SUBCLASS_WEAPON_AXE                    = 0,
	ITEM_SUBCLASS_WEAPON_AXE2                   = 1,
	ITEM_SUBCLASS_WEAPON_BOW                    = 2,
	ITEM_SUBCLASS_WEAPON_GUN                    = 3,
	ITEM_SUBCLASS_WEAPON_MACE                   = 4,
	ITEM_SUBCLASS_WEAPON_MACE2                  = 5,
	ITEM_SUBCLASS_WEAPON_POLEARM                = 6,
	ITEM_SUBCLASS_WEAPON_SWORD                  = 7,
	ITEM_SUBCLASS_WEAPON_SWORD2                 = 8,
	ITEM_SUBCLASS_WEAPON_obsolete               = 9,
	ITEM_SUBCLASS_WEAPON_STAFF                  = 10,
	ITEM_SUBCLASS_WEAPON_EXOTIC                 = 11,
	ITEM_SUBCLASS_WEAPON_EXOTIC2                = 12,
	ITEM_SUBCLASS_WEAPON_FIST                   = 13,
	ITEM_SUBCLASS_WEAPON_MISC                   = 14,
	ITEM_SUBCLASS_WEAPON_DAGGER                 = 15,
	ITEM_SUBCLASS_WEAPON_THROWN                 = 16,
	ITEM_SUBCLASS_WEAPON_SPEAR                  = 17,
	ITEM_SUBCLASS_WEAPON_CROSSBOW               = 18,
	ITEM_SUBCLASS_WEAPON_WAND                   = 19,
	ITEM_SUBCLASS_WEAPON_FISHING_POLE           = 20
};

#define MAX_ITEM_SUBCLASS_WEAPON                  21

enum ItemSubclassGem
{
	ITEM_SUBCLASS_GEM_RED                       = 0,
	ITEM_SUBCLASS_GEM_BLUE                      = 1,
	ITEM_SUBCLASS_GEM_YELLOW                    = 2,
	ITEM_SUBCLASS_GEM_PURPLE                    = 3,
	ITEM_SUBCLASS_GEM_GREEN                     = 4,
	ITEM_SUBCLASS_GEM_ORANGE                    = 5,
	ITEM_SUBCLASS_GEM_META                      = 6,
	ITEM_SUBCLASS_GEM_SIMPLE                    = 7,
	ITEM_SUBCLASS_GEM_PRISMATIC                 = 8
};

#define MAX_ITEM_SUBCLASS_GEM                     9

enum ItemSubclassArmor
{

	ITEM_SUBCLASS_ARMOR_HEAD = 2,				//ͷ��
	ITEM_SUBCLASS_ARMOR_SHOULDER,				//�粿
	ITEM_SUBCLASS_ARMOR_CHEST,					//�ز�
	ITEM_SUBCLASS_ARMOR_WAIST,					//����
	ITEM_SUBCLASS_ARMOR_KNEECAP,				//��ϥ
	ITEM_SUBCLASS_ARMOR_DRESS,					//����
	ITEM_SUBCLASS_ARMOR_FINGER1,				//��ָ1
	ITEM_SUBCLASS_ARMOR_FINGER2,				//��ָ2
	ITEM_SUBCLASS_ARMOR_NECK,					//����
	ITEM_SUBCLASS_ARMOR_TRINKET,				//��Ʒ 
												 
	ITEM_SUBCLASS_ARMOR_HAIR,					//����
	ITEM_SUBCLASS_ARMOR_GLOVES,					//����
	ITEM_SUBCLASS_ARMOR_WEAR,					//����,
	ITEM_SUBCLASS_ARMOR_TROUSERS,				//����
	ITEM_SUBCLASS_ARMOR_BOOTS,					//Ь�� 
												 
	ITEM_SUBCLASS_ARMOR_MISC       ,
	ITEM_SUBCLASS_ARMOR_CLOTH      ,
	ITEM_SUBCLASS_ARMOR_LEATHER    ,
	ITEM_SUBCLASS_ARMOR_MAIL       ,
	ITEM_SUBCLASS_ARMOR_PLATE      ,
	ITEM_SUBCLASS_ARMOR_BUCKLER    ,
	ITEM_SUBCLASS_ARMOR_SHIELD     ,
	ITEM_SUBCLASS_ARMOR_LIBRAM     ,
	ITEM_SUBCLASS_ARMOR_IDOL       ,
	ITEM_SUBCLASS_ARMOR_TOTEM      
};

#define MAX_ITEM_SUBCLASS_ARMOR                  10

enum ItemSubclassReagent
{
	ITEM_SUBCLASS_REAGENT                       = 0
};

#define MAX_ITEM_SUBCLASS_REAGENT                 1

enum ItemSubclassProjectile
{
	ITEM_SUBCLASS_WAND                          = 0,        // ABS
	ITEM_SUBCLASS_BOLT                          = 1,        // ABS
	ITEM_SUBCLASS_ARROW                         = 2,
	ITEM_SUBCLASS_BULLET                        = 3,
	ITEM_SUBCLASS_THROWN                        = 4         // ABS
};

#define MAX_ITEM_SUBCLASS_PROJECTILE              5

enum ItemSubclassTradeGoods
{
	ITEM_SUBCLASS_TRADE_GOODS                   = 0,
	ITEM_SUBCLASS_PARTS                         = 1,
	ITEM_SUBCLASS_EXPLOSIVES                    = 2,
	ITEM_SUBCLASS_DEVICES                       = 3,
	ITEM_SUBCLASS_JEWELCRAFTING                 = 4,
	ITEM_SUBCLASS_CLOTH                         = 5,
	ITEM_SUBCLASS_LEATHER                       = 6,
	ITEM_SUBCLASS_METAL_STONE                   = 7,
	ITEM_SUBCLASS_MEAT                          = 8,
	ITEM_SUBCLASS_HERB                          = 9,
	ITEM_SUBCLASS_ELEMENTAL                     = 10,
	ITEM_SUBCLASS_TRADE_GOODS_OTHER             = 11,
	ITEM_SUBCLASS_ENCHANTING                    = 12,
	ITEM_SUBCLASS_MATERIAL                      = 13        // Added in 2.4.2
};

#define MAX_ITEM_SUBCLASS_TRADE_GOODS             14

enum ItemSubclassGeneric
{
	ITEM_SUBCLASS_GENERIC                       = 0
};

#define MAX_ITEM_SUBCLASS_GENERIC                 1

enum ItemSubclassRecipe
{
	ITEM_SUBCLASS_BOOK                          = 0,
	ITEM_SUBCLASS_LEATHERWORKING_PATTERN        = 1,
	ITEM_SUBCLASS_TAILORING_PATTERN             = 2,
	ITEM_SUBCLASS_ENGINEERING_SCHEMATIC         = 3,
	ITEM_SUBCLASS_BLACKSMITHING                 = 4,
	ITEM_SUBCLASS_COOKING_RECIPE                = 5,
	ITEM_SUBCLASS_ALCHEMY_RECIPE                = 6,
	ITEM_SUBCLASS_FIRST_AID_MANUAL              = 7,
	ITEM_SUBCLASS_ENCHANTING_FORMULA            = 8,
	ITEM_SUBCLASS_FISHING_MANUAL                = 9,
	ITEM_SUBCLASS_JEWELCRAFTING_RECIPE          = 10
};

#define MAX_ITEM_SUBCLASS_RECIPE                  11

enum ItemSubclassMoney
{
	ITEM_SUBCLASS_MONEY                         = 0
};

#define MAX_ITEM_SUBCLASS_MONEY                   1

enum ItemSubclassQuiver
{
	ITEM_SUBCLASS_QUIVER0                       = 0,        // ABS
	ITEM_SUBCLASS_QUIVER1                       = 1,        // ABS
	ITEM_SUBCLASS_QUIVER                        = 2,
	ITEM_SUBCLASS_AMMO_POUCH                    = 3
};

#define MAX_ITEM_SUBCLASS_QUIVER                  4

enum ItemSubclassQuest
{
	ITEM_SUBCLASS_QUEST                         = 0
};

#define MAX_ITEM_SUBCLASS_QUEST                   1

enum ItemSubclassKey
{
	ITEM_SUBCLASS_KEY                           = 0,
	ITEM_SUBCLASS_LOCKPICK                      = 1
};

#define MAX_ITEM_SUBCLASS_KEY                     2

enum ItemSubclassPermanent
{
	ITEM_SUBCLASS_PERMANENT                     = 0
};

#define MAX_ITEM_SUBCLASS_PERMANENT               1

enum ItemSubclassJunk
{
	ITEM_SUBCLASS_JUNK                          = 0,
	ITEM_SUBCLASS_JUNK_REAGENT                  = 1,
	ITEM_SUBCLASS_JUNK_PET                      = 2,
	ITEM_SUBCLASS_JUNK_HOLIDAY                  = 3,
	ITEM_SUBCLASS_JUNK_OTHER                    = 4,
	ITEM_SUBCLASS_JUNK_MOUNT                    = 5
};

#define MAX_ITEM_SUBCLASS_JUNK                    6

const ui32 MaxItemSubclassValues[MAX_ITEM_CLASS] =
{
	MAX_ITEM_SUBCLASS_CONSUMABLE,
	MAX_ITEM_SUBCLASS_CONTAINER,
	MAX_ITEM_SUBCLASS_WEAPON,
	MAX_ITEM_SUBCLASS_GEM,
	MAX_ITEM_SUBCLASS_ARMOR,
	MAX_ITEM_SUBCLASS_REAGENT,
	MAX_ITEM_SUBCLASS_PROJECTILE,
	MAX_ITEM_SUBCLASS_TRADE_GOODS,
	MAX_ITEM_SUBCLASS_GENERIC,
	MAX_ITEM_SUBCLASS_RECIPE,
	MAX_ITEM_SUBCLASS_MONEY,
	MAX_ITEM_SUBCLASS_QUIVER,
	MAX_ITEM_SUBCLASS_QUEST,
	MAX_ITEM_SUBCLASS_KEY,
	MAX_ITEM_SUBCLASS_PERMANENT,
	MAX_ITEM_SUBCLASS_JUNK
};
enum InventorySlot
{
	NULL_BAG                   = 0,
	NULL_SLOT                  = 255
};

inline ui8 ItemSubClassToDurabilityMultiplierId(ui32 ItemClass, ui32 ItemSubClass)
{
	switch(ItemClass)
	{
	case ITEM_CLASS_WEAPON: return ItemSubClass;
	case ITEM_CLASS_ARMOR:  return ItemSubClass + 21;
	}
	return 0;
}

struct _Damage
{
	float DamageMin;
	float DamageMax;
	ui32 DamageType;                                      // id from Resistances.dbc

};

struct _Spell
{
	ui32 SpellId;                                         // id from Spell.dbc
	ui32 SpellTrigger;
	i32  SpellCharges;
	float  SpellPPMRate;
	i32  SpellCooldown;
	ui32 SpellCategory;                                   // id from SpellCategory.dbc
	i32  SpellCategoryCooldown;

};

enum BAG_FAMILY_MASK
{
	BAG_FAMILY_MASK_ARROWS                    = 0x00000001,
	BAG_FAMILY_MASK_BULLETS                   = 0x00000002,
	BAG_FAMILY_MASK_SHARDS                    = 0x00000004,
	BAG_FAMILY_MASK_LEATHERWORKING_SUPP       = 0x00000008,
	BAG_FAMILY_MASK_UNUSED                    = 0x00000010, // not used currently
	BAG_FAMILY_MASK_HERBS                     = 0x00000020,
	BAG_FAMILY_MASK_ENCHANTING_SUPP           = 0x00000040,
	BAG_FAMILY_MASK_ENGINEERING_SUPP          = 0x00000080,
	BAG_FAMILY_MASK_KEYS                      = 0x00000100,
	BAG_FAMILY_MASK_GEMS                      = 0x00000200,
	BAG_FAMILY_MASK_MINING_SUPP               = 0x00000400,
	BAG_FAMILY_MASK_SOULBOUND_EQUIPMENT       = 0x00000800,
	BAG_FAMILY_MASK_VANITY_PETS               = 0x00001000
};
enum ItemBondingType
{
	NO_BIND                                     = 0,
	BIND_WHEN_PICKED_UP                         = 1,
	BIND_WHEN_EQUIPED                           = 2,
	BIND_WHEN_USE                               = 3,
	BIND_QUEST_ITEM                             = 4,
	BIND_QUEST_ITEM1                            = 5         // not used in game
};

#define MAX_BIND_TYPE                             6


struct ItemSetEntry
{
	//uint32    id                                          // 0 item set ID
	char*     name[16];                                     // 1-16
	// 17 string flags, unused
	// 18-28 items from set, but not have all items listed, use ItemPrototype::ItemSet instead
	// 29-34 unused
	ui32    spells[8];                                    // 35-42
	ui32    items_to_triggerspell[8];                     // 43-50
	ui32    required_skill_id;                            // 51
	ui32    required_skill_value;                         // 52
};

typedef struct tagItemProperty
{
	bool ReadRecord(const char *Buff);

	//ITEM_ID	id;

	//ui8		nWeaponType;	//��������

	//char	szName[21];
	//ui8		nQuality;		//������Ϸ�趨����ƷƷ�ʣ��ͼ�ֵ�����䡢��ɫ����Ʒ���Ե����
	//ui8		bCanUser;		//�Ƿ���Ե��ʹ��
	//ui8		bCanSell;		//�Ƿ���Գ��۸�NPC��ɫ
	//ui8		bCanExchange;	//�Ƿ���Խ���
	//ui8		bCanOverLap;	//�Ƿ���Ե���
	//ui16	nOverLap;		//�������������;ö�
	//ui32	nPrice;			//�۸�
	//ui8		nLevel;			//�ȼ�����
	//ui32	nSuitID;		//��װ��ID
	//ui32	nCDGroup;		//CD��ID

	//struct 
	//{
	//	ui8		index;
	//	ui16	value;
	//}EP_Item[8];

	//struct
	//{
	//	ui8		index;		//	���Ա����ID	tinyint
	//	i16		value;		//	���Ա����ֵ	smallint
	//}BP_Item[10];//��Ʒ�Ļ�������

	ui32 ItemId;
	ui32 Class;                                           //	���
	ui32 SubClass;                                        //	����
	ui32 DisplayInfoID;                                   //	
	ui32 Quality;					//	Ʒ��
	ui32 Flags;						
	ui32 BuyCount;					//	��������
	ui32 BuyPrice;					//	����۸�
	ui32 SellPrice;					//	�����۸�
	ui32 nInventoryType;			//	��װ��λ��
	ui32 AllowableClass;			//	����ְҵ
	ui32 AllowableRace;				//	��������
	ui32 ItemLevel;					//	���ߵǼ�
	ui32 RequiredLevel;				//	װ����Ҫ�Ǽ�
	ui32 RequiredSkill;             //	װ����Ҫ�����
	ui32 RequiredSkillRank;			//	װ����Ҫ����ܵȼ�
	ui32 RequiredSpell;				//	װ����Ҫս������
	ui32 MaxCount;					//	�������
	ui32 Stackable;					//	��������
	ui32 ContainerSlots;			//	���������Ĵ�С
	_ItemStat ItemStat[10];			//	������������
	_Damage Damage[5];				//	�����˺�����
	_Spell Spells[5];				//	����ս����������
	ui32 Armor;					//���ӵĹ�����
	ui32 Delay;					//	�������

	ui32 FireRes;
	ui32 Block;
	ui32 RequiredDisenchantSkill;
	ui32 LockID;
	ui32 DisenchantID;
	ui32 BagFamily;                                       // id from ItemBagFamily.dbc
	ui32 StartQuest;                                      // id from QuestCache.wdb
	ui32 ItemSet;                                         // id from ItemSet.dbc
	ui32 MaxDurability;
	i32 Duration;                                         // negative = realtime, positive = ingame time
	ui32 Bonding;
	string name;
	string Description;
	ui32 Sheath;
	ui32 TotemCategory;                                   // id from TotemCategory.dbc

}ItemPrototype, *PItemPrototype;

class CItem;
typedef struct tagItemData
{
public:
	ITEM_ID		type_id;

	ui64		m_llItemID;
	ui8			m_wMaxDura;
	ui16		nOverLap;			//�������������;ö�
	ui8			m_bBind;
	ui8			nLevel;
	char		szSign[21];

	union
	{
		struct
		{
			struct
			{
				ui8		index;		//	���Ա����ID	tinyint
				i16		value;		//	���Ա����ֵ	smallint

			}BP_Item;//��Ʒ�Ļ�������

			ui8		ExternPtr[4];

			struct
			{
				ui8		index;				//	�������Ա����ID_1	PAI	tinyint
				i16		value;				//	�������Ա����ֵ_1	PAV	smallint

			}AP_Item[4];
		};
		ui32	nSkillID;
	};

	ui8	Reserved[20];

	CPacketSn& Sn(CPacketSn& cps) const {cps.AddBuf(this, sizeof(tagItemData)); return cps;}
	CPacketUsn& Usn(CPacketUsn& cpu) {cpu.GetBuf(this, sizeof(tagItemData)); return cpu;}
//public:
//	bool FromItem(CItem* pItem);
//	bool ToItem(CItem* pItem, ui8 byVersion);
//	bool ToItem_Version1(CItem* pItem);
} TITEMDATA, *PTITEMDATA;


enum ItemQualities
{
	ITEM_QUALITY_POOR                  = 0,                 //GREY
	ITEM_QUALITY_NORMAL                = 1,                 //WHITE
	ITEM_QUALITY_UNCOMMON              = 2,                 //GREEN
	ITEM_QUALITY_RARE                  = 3,                 //BLUE
	ITEM_QUALITY_EPIC                  = 4,                 //PURPLE
	ITEM_QUALITY_LEGENDARY             = 5,                 //ORANGE
	ITEM_QUALITY_ARTIFACT              = 6                  //LIGHT YELLOW
};

#define MAX_ITEM_QUALITY                 7


enum LockType
{
	LOCKTYPE_PICKLOCK              = 1,
	LOCKTYPE_HERBALISM             = 2,
	LOCKTYPE_MINING                = 3,
	LOCKTYPE_DISARM_TRAP           = 4,
	LOCKTYPE_OPEN                  = 5,
	LOCKTYPE_TREASURE              = 6,
	LOCKTYPE_CALCIFIED_ELVEN_GEMS  = 7,
	LOCKTYPE_CLOSE                 = 8,
	LOCKTYPE_ARM_TRAP              = 9,
	LOCKTYPE_QUICK_OPEN            = 10,
	LOCKTYPE_QUICK_CLOSE           = 11,
	LOCKTYPE_OPEN_TINKERING        = 12,
	LOCKTYPE_OPEN_KNEELING         = 13,
	LOCKTYPE_OPEN_ATTACKING        = 14,
	LOCKTYPE_GAHZRIDIAN            = 15,
	LOCKTYPE_BLASTING              = 16,
	LOCKTYPE_SLOW_OPEN             = 17,
	LOCKTYPE_SLOW_CLOSE            = 18,
	LOCKTYPE_FISHING               = 19
};

enum InventoryChangeFailure
{
	EQUIP_ERR_OK                                 = 0,
	EQUIP_ERR_CANT_EQUIP_LEVEL_I                 = 1,
	EQUIP_ERR_ERR_CANT_EQUIP_SKILL               = 2,
	EQUIP_ERR_ITEM_DOESNT_GO_TO_SLOT             = 3,
	EQUIP_ERR_BAG_FULL                           = 4,
	EQUIP_ERR_NONEMPTY_BAG_OVER_OTHER_BAG        = 5,
	EQUIP_ERR_CANT_TRADE_EQUIP_BAGS              = 6,
	EQUIP_ERR_ONLY_AMMO_CAN_GO_HERE              = 7,
	EQUIP_ERR_NO_REQUIRED_PROFICIENCY            = 8,
	EQUIP_ERR_NO_EQUIPMENT_SLOT_AVAILABLE        = 9,
	EQUIP_ERR_YOU_CAN_NEVER_USE_THAT_ITEM        = 10,
	EQUIP_ERR_YOU_CAN_NEVER_USE_THAT_ITEM2       = 11,
	EQUIP_ERR_NO_EQUIPMENT_SLOT_AVAILABLE2       = 12,
	EQUIP_ERR_CANT_EQUIP_WITH_TWOHANDED          = 13,
	EQUIP_ERR_CANT_DUAL_WIELD                    = 14,
	EQUIP_ERR_ITEM_DOESNT_GO_INTO_BAG            = 15,
	EQUIP_ERR_ITEM_DOESNT_GO_INTO_BAG2           = 16,
	EQUIP_ERR_CANT_CARRY_MORE_OF_THIS            = 17,
	EQUIP_ERR_NO_EQUIPMENT_SLOT_AVAILABLE3       = 18,
	EQUIP_ERR_ITEM_CANT_STACK                    = 19,
	EQUIP_ERR_ITEM_CANT_BE_EQUIPPED              = 20,
	EQUIP_ERR_ITEMS_CANT_BE_SWAPPED              = 21,
	EQUIP_ERR_SLOT_IS_EMPTY                      = 22,
	EQUIP_ERR_ITEM_NOT_FOUND                     = 23,
	EQUIP_ERR_CANT_DROP_SOULBOUND                = 24,
	EQUIP_ERR_OUT_OF_RANGE                       = 25,
	EQUIP_ERR_TRIED_TO_SPLIT_MORE_THAN_COUNT     = 26,
	EQUIP_ERR_COULDNT_SPLIT_ITEMS                = 27,
	EQUIP_ERR_MISSING_REAGENT                    = 28,
	EQUIP_ERR_NOT_ENOUGH_MONEY                   = 29,
	EQUIP_ERR_NOT_A_BAG                          = 30,
	EQUIP_ERR_CAN_ONLY_DO_WITH_EMPTY_BAGS        = 31,
	EQUIP_ERR_DONT_OWN_THAT_ITEM                 = 32,
	EQUIP_ERR_CAN_EQUIP_ONLY1_QUIVER             = 33,
	EQUIP_ERR_MUST_PURCHASE_THAT_BAG_SLOT        = 34,
	EQUIP_ERR_TOO_FAR_AWAY_FROM_BANK             = 35,
	EQUIP_ERR_ITEM_LOCKED                        = 36,
	EQUIP_ERR_YOU_ARE_STUNNED                    = 37,
	EQUIP_ERR_YOU_ARE_DEAD                       = 38,
	EQUIP_ERR_CANT_DO_RIGHT_NOW                  = 39,
	EQUIP_ERR_INT_BAG_ERROR                      = 40,
	EQUIP_ERR_CAN_EQUIP_ONLY1_QUIVER2            = 41,
	EQUIP_ERR_CAN_EQUIP_ONLY1_AMMOPOUCH          = 42,
	EQUIP_ERR_STACKABLE_CANT_BE_WRAPPED          = 43,
	EQUIP_ERR_EQUIPPED_CANT_BE_WRAPPED           = 44,
	EQUIP_ERR_WRAPPED_CANT_BE_WRAPPED            = 45,
	EQUIP_ERR_BOUND_CANT_BE_WRAPPED              = 46,
	EQUIP_ERR_UNIQUE_CANT_BE_WRAPPED             = 47,
	EQUIP_ERR_BAGS_CANT_BE_WRAPPED               = 48,
	EQUIP_ERR_ALREADY_LOOTED                     = 49,
	EQUIP_ERR_INVENTORY_FULL                     = 50,
	EQUIP_ERR_BANK_FULL                          = 51,
	EQUIP_ERR_ITEM_IS_CURRENTLY_SOLD_OUT         = 52,
	EQUIP_ERR_BAG_FULL3                          = 53,
	EQUIP_ERR_ITEM_NOT_FOUND2                    = 54,
	EQUIP_ERR_ITEM_CANT_STACK2                   = 55,
	EQUIP_ERR_BAG_FULL4                          = 56,
	EQUIP_ERR_ITEM_SOLD_OUT                      = 57,
	EQUIP_ERR_OBJECT_IS_BUSY                     = 58,
	EQUIP_ERR_NONE                               = 59,
	EQUIP_ERR_NOT_IN_COMBAT                      = 60,
	EQUIP_ERR_NOT_WHILE_DISARMED                 = 61,
	EQUIP_ERR_BAG_FULL6                          = 62,
	EQUIP_ERR_CANT_EQUIP_RANK                    = 63,
	EQUIP_ERR_CANT_EQUIP_REPUTATION              = 64,
	EQUIP_ERR_TOO_MANY_SPECIAL_BAGS              = 65,
	EQUIP_ERR_LOOT_CANT_LOOT_THAT_NOW            = 66,
	EQUIP_ERR_ITEM_UNIQUE_EQUIPABLE              = 67,
	EQUIP_ERR_VENDOR_MISSING_TURNINS             = 68,
	EQUIP_ERR_NOT_ENOUGH_HONOR_POINTS            = 69,
	EQUIP_ERR_NOT_ENOUGH_ARENA_POINTS            = 70,
	EQUIP_ERR_ITEM_MAX_COUNT_SOCKETED            = 71,
	EQUIP_ERR_MAIL_BOUND_ITEM                    = 72,
	EQUIP_ERR_NO_SPLIT_WHILE_PROSPECTING         = 73,
	EQUIP_ERR_ITEM_MAX_COUNT_EQUIPPED_SOCKETED   = 75,
	EQUIP_ERR_ITEM_UNIQUE_EQUIPPABLE_SOCKETED    = 76,
	EQUIP_ERR_TOO_MUCH_GOLD                      = 77,
	EQUIP_ERR_NOT_DURING_ARENA_MATCH             = 78,
	EQUIP_ERR_CANNOT_TRADE_THAT                  = 79,
	EQUIP_ERR_PERSONAL_ARENA_RATING_TOO_LOW      = 80
	// probably exist more
};

enum BuyFailure
{
	BUY_ERR_CANT_FIND_ITEM                      = 0,
	BUY_ERR_ITEM_ALREADY_SOLD                   = 1,
	BUY_ERR_NOT_ENOUGHT_MONEY                   = 2,
	BUY_ERR_SELLER_DONT_LIKE_YOU                = 4,
	BUY_ERR_DISTANCE_TOO_FAR                    = 5,
	BUY_ERR_ITEM_SOLD_OUT                       = 7,
	BUY_ERR_CANT_CARRY_MORE                     = 8,
	BUY_ERR_RANK_REQUIRE                        = 11,
	BUY_ERR_REPUTATION_REQUIRE                  = 12
};

enum SellFailure
{
	SELL_ERR_CANT_FIND_ITEM                      = 1,
	SELL_ERR_CANT_SELL_ITEM                      = 2,       // merchant doesn't like that item
	SELL_ERR_CANT_FIND_VENDOR                    = 3,       // merchant doesn't like you
	SELL_ERR_YOU_DONT_OWN_THAT_ITEM              = 4,       // you don't own that item
	SELL_ERR_UNK                                 = 5,       // nothing appears...
	SELL_ERR_ONLY_EMPTY_BAG                      = 6        // can only do with empty bags
};

typedef struct tagTradeItem
{
	ui32	entry;
	ui32	displayinfoid;
	ui32	stackcount;			//	��������
	ui64	giftcreator;
	ui64	creator;
	ui32	spellcharge;
	ui32	SuffixFactor;
	ui32	randompropid;			// random properties id
	ui32	maxduration;		//	����;�
	ui32	duration;			//	�;�
	tagTradeItem()
	{
		entry	= 0;
	}
}TradeItem;



enum ItemSpelltriggerType
{
	ITEM_SPELLTRIGGER_ON_USE          = 0,                  // use after equip cooldown
	ITEM_SPELLTRIGGER_ON_EQUIP        = 1,
	ITEM_SPELLTRIGGER_CHANCE_ON_HIT   = 2,
	ITEM_SPELLTRIGGER_SOULSTONE       = 4,
	ITEM_SPELLTRIGGER_ON_NO_DELAY_USE = 5,                  // no equip cooldown
	ITEM_SPELLTRIGGER_LEARN_SPELL_ID  = 6                   // used in item_template.spell_2 with spell_id with SPELL_GENERIC_LEARN in spell_1
};

#define MAX_ITEM_SPELLTRIGGER           7
*/