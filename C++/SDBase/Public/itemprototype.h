#ifndef _ITEMPROTOTYPE_H
#define _ITEMPROTOTYPE_H
#include "TypeDef.h"
class Spell;

#define GEM_META_SOCKET 1
#define GEM_RED_SOCKET 2
#define GEM_YELLOW_SOCKET 4
#define GEM_BLUE_SOCKET 8

// enum PlayerSlots
// {
// 	// first slot for item stored (in any way in player m_items data)
// 	PLAYER_SLOT_START           = 0,
// 	// last+1 slot for item stored (in any way in player m_items data)
// 	PLAYER_SLOT_END             = 118,
// 	PLAYER_SLOTS_COUNT          = (PLAYER_SLOT_END - PLAYER_SLOT_START)
// };
#define ITEM_NO_SLOT_AVAILABLE  0xFF //works for all kind of slots now
#define INVENTORY_SLOT_NOT_SET  0xFF
#define INVENTORY_SLOT_JINGLIAN	0xFE
#define INVENTORY_SLOT_XIANGQIAN	0xFD

enum InventoryType
{
	INVTYPE_NON_EQUIP       = 0xFF,
	INVTYPE_HEAD			= 0,	/*= 0*/		//ͷ��
	INVTYPE_GLOVES					/*= 1*/,	//����
	INVTYPE_CHEST					/*= 2*/,	//�ز�
	INVTYPE_TROUSERS				/*= 3*/,	//��ϥ
	INVTYPE_BOOTS					/*= 4*/,	//Ь��     
	INVTYPE_WEAPON			= 5,	//����
	INVTYPE_WEAPONMAINHAND = INVTYPE_WEAPON,	//��������
	INVTYPE_WEAPONOFFHAND,						//��������
	INVTYPE_NECK					/*= 7*/,	//����
	INVTYPE_SHOULDERS				/*= 8*/,	//�粿
	INVTYPE_WAIST					/*= 9*/,	//����	               ,
	INVTYPE_FINGER					/*= 10*/,	//��ָ
 	INVTYPE_UNUSER1					/*= 11*/,	//��ָ2		����������,ֻ��ռ��һ��λ��
	INVTYPE_TRINKET					/*= 12*/,	//��Ʒ                     ,
	INVTYPE_UNUSER2					/*= 13*/,	//��Ʒ2     ����������,ֻ��ռ��һ��λ��

	INVTYPE_HOUNTER_BEIBU,				/*14����*/
	INVTYPE_HOUNTER_TOUBU,				/*15ͷ��*/
	INVTYPE_HOUNTER_JIANBANG,			/*16���*/
	INVTYPE_HOUNTER_SHANGYI,			/*17����*/
	INVTYPE_HOUNTER_XIAYI,				/*18����*/
	INVTYPE_HOUNTER_XIEZI,				/*19Ь��*/

	INVTYPE_SHIELD,					/*= 20*/	//����
	INVTYPE_2HWEAPON,				/*= 21*/	//˫������
	INVTYPE_BAG,					/*= 22*/		//����
	INVTYPE_BAOZHU,						//23����
	MAX_INVENTORY_TYPES,
	INVTYPE_RANGED = -3,
};
enum EquipmentSlots
{
	EQUIPMENT_SLOT_START        = 0,
	EQUIPMENT_SLOT_HEAD			= EQUIPMENT_SLOT_START,//ͷ��,���,�۾�(��ʾ)
	EQUIPMENT_SLOT_GLOVES,		//���� (��ʾ)
	EQUIPMENT_SLOT_CHEST,		//�ز� (��ʾ)
	EQUIPMENT_SLOT_TROUSERS,	//���� (��ʾ)
	EQUIPMENT_SLOT_BOOTS,		//Ь�� (��ʾ)
	EQUIPMENT_SLOT_MAINHAND		= 5,		//����
	EQUIPMENT_SLOT_OFFHAND,
	EQUIPMENT_SLOT_NECK,		//���� (��ʾ)
	EQUIPMENT_SLOT_SHOULDERS,	//�粿 (��ʾ)
	EQUIPMENT_SLOT_WAIST,		//���� (��ʾ)
	EQUIPMENT_SLOT_FINGER1,		//��ָ1 (����ʾ)
	EQUIPMENT_SLOT_FINGER2,		//��ָ1 (����ʾ)
	EQUIPMENT_SLOT_TRINKET1,	//��Ʒ1 (����ʾ)
	EQUIPMENT_SLOT_TRINKET2,	//��Ʒ2 (����ʾ)

	EQUIPMENT_HOUNTER_BEIBU,				/*14����*/
	EQUIPMENT_HOUNTER_TOUBU,				/*15ͷ��*/
	EQUIPMENT_HOUNTER_JIANBANG,				/*16���*/
	EQUIPMENT_HOUNTER_SHANGYI,				/*17����*/
	EQUIPMENT_HOUNTER_XIAYI,				/*18����*/
	EQUIPMENT_HOUNTER_XIEZI,				/*19Ь��*/

	EQUIPMENT_SLOT_END,
// 	EQUIPMENT_SLOT_MAINHAND = INVTYPE_WEAPON,		//	����,��ʱֻ�õ���������
// 	EQUIPMENT_SLOT_OFFHAND = -2,					//	��������,�Ժ���չ?
// 	EQUIPMENT_SLOT_RANGED = -3,
};


enum InventorySlots
{
	INVENTORY_SLOT_BAG_0        = EQUIPMENT_SLOT_END,
	INVENTORY_SLOT_BAG_START    = INVENTORY_SLOT_BAG_0,
	INVENTORY_SLOT_BAG_1        = INVENTORY_SLOT_BAG_START,
	INVENTORY_SLOT_BAG_2       ,
	INVENTORY_SLOT_BAG_3       ,
	INVENTORY_SLOT_BAG_4       ,
	INVENTORY_SLOT_BAG_5	   ,
	INVENTORY_SLOT_BAG_6	   ,
	INVENTORY_SLOT_BAG_7	   ,
	INVENTORY_SLOT_BAG_8	   ,
	INVENTORY_SLOT_BAG_END     ,

	INVENTORY_SLOT_ITEM_START   = INVENTORY_SLOT_BAG_END,
	INVENTORY_SLOT_ITEM_1       = INVENTORY_SLOT_ITEM_START,
	INVENTORY_SLOT_ITEM_2       ,
	INVENTORY_SLOT_ITEM_3       ,
	INVENTORY_SLOT_ITEM_4       ,
	INVENTORY_SLOT_ITEM_5       ,
	INVENTORY_SLOT_ITEM_6       ,
	INVENTORY_SLOT_ITEM_7       ,
	INVENTORY_SLOT_ITEM_8       ,
	INVENTORY_SLOT_ITEM_9       ,
	INVENTORY_SLOT_ITEM_10      ,
	INVENTORY_SLOT_ITEM_11      ,
	INVENTORY_SLOT_ITEM_12      ,
	INVENTORY_SLOT_ITEM_13      ,
	INVENTORY_SLOT_ITEM_14      ,
	INVENTORY_SLOT_ITEM_15      ,
	INVENTORY_SLOT_ITEM_16      ,
	INVENTORY_SLOT_ITEM_17      ,
	INVENTORY_SLOT_ITEM_18      ,
	INVENTORY_SLOT_ITEM_19      ,
	INVENTORY_SLOT_ITEM_20      ,
	INVENTORY_SLOT_ITEM_21      ,
	INVENTORY_SLOT_ITEM_22      ,
	INVENTORY_SLOT_ITEM_23      ,
	INVENTORY_SLOT_ITEM_24      ,
	INVENTORY_SLOT_ITEM_25      ,
	INVENTORY_SLOT_ITEM_26      ,
	INVENTORY_SLOT_ITEM_27      ,
	INVENTORY_SLOT_ITEM_28      ,
	INVENTORY_SLOT_ITEM_29      ,
	INVENTORY_SLOT_ITEM_30      ,
	INVENTORY_SLOT_ITEM_END
};

enum BankSlots
{
	BANK_SLOT_ITEM_START        = INVENTORY_SLOT_ITEM_END,
	BANK_SLOT_ITEM_1            = BANK_SLOT_ITEM_START,
	BANK_SLOT_ITEM_2            ,
	BANK_SLOT_ITEM_3            ,
	BANK_SLOT_ITEM_4            ,
	BANK_SLOT_ITEM_5            ,
	BANK_SLOT_ITEM_6            ,
	BANK_SLOT_ITEM_7            ,
	BANK_SLOT_ITEM_8            ,
	BANK_SLOT_ITEM_9            ,
	BANK_SLOT_ITEM_10           ,
	BANK_SLOT_ITEM_11           ,
	BANK_SLOT_ITEM_12           ,
	BANK_SLOT_ITEM_13           ,
	BANK_SLOT_ITEM_14           ,
	BANK_SLOT_ITEM_15           ,
	BANK_SLOT_ITEM_16           ,
	BANK_SLOT_ITEM_17           ,
	BANK_SLOT_ITEM_18           ,
	BANK_SLOT_ITEM_19           ,
	BANK_SLOT_ITEM_20           ,
	BANK_SLOT_ITEM_21           ,
	BANK_SLOT_ITEM_22           ,
	BANK_SLOT_ITEM_23           ,
	BANK_SLOT_ITEM_24           ,
	BANK_SLOT_ITEM_25           ,
	BANK_SLOT_ITEM_26           ,
	BANK_SLOT_ITEM_27           ,
	BANK_SLOT_ITEM_28          ,
	BANK_SLOT_ITEM_END         ,

	BANK_SLOT_BAG_START         = BANK_SLOT_ITEM_END,
	BANK_SLOT_BAG_1             = BANK_SLOT_BAG_START,
	BANK_SLOT_BAG_2             ,
	BANK_SLOT_BAG_3             ,
	BANK_SLOT_BAG_4             ,
	BANK_SLOT_BAG_5             ,
	BANK_SLOT_BAG_6             ,
	BANK_SLOT_BAG_7             ,
	BANK_SLOT_BAG_END           
};
#define EXTRA_INVENTORY_SLOT_COUNT 18
#define MAX_INVENTORY_SLOT ( BANK_SLOT_BAG_END - EQUIPMENT_SLOT_START + EXTRA_INVENTORY_SLOT_COUNT )
#define INVENTORY_SLOT_JINGLIAN_BEGIN ( BANK_SLOT_BAG_END - EQUIPMENT_SLOT_START )
#define INVENTORY_SLOT_XIANGQIAN_BEGIN INVENTORY_SLOT_JINGLIAN_BEGIN + 6

enum BuyBackSlots
{
	// stored in m_buybackitems
	BUYBACK_SLOT_START          = BANK_SLOT_BAG_END,
	BUYBACK_SLOT_1              = BUYBACK_SLOT_START,
	BUYBACK_SLOT_2             ,
	BUYBACK_SLOT_3             ,
	BUYBACK_SLOT_4             ,
	BUYBACK_SLOT_5             ,
	BUYBACK_SLOT_6             ,
	BUYBACK_SLOT_7             ,
	BUYBACK_SLOT_8             ,
	BUYBACK_SLOT_9             ,
	BUYBACK_SLOT_10            ,
	BUYBACK_SLOT_11            ,
	BUYBACK_SLOT_12            ,
	BUYBACK_SLOT_END           ,
};


#define MAX_BUYBACK_SLOT BUYBACK_SLOT_END - BUYBACK_SLOT_START
enum TradeSlots
{
	TRADE_SLOT_COUNT            = 12,
	TRADE_SLOT_TRADED_COUNT     = 6,
	TRADE_SLOT_NONTRADED        = 6
};
enum ITEM_DAMAGE_TYPE
{
	NORMAL_DAMAGE	= 0,
	//HOLY_DAMAGE		= 1,
	//FIRE_DAMAGE		= 2,
	//NATURE_DAMAGE	= 3,
	//FROST_DAMAGE	= 4,
	//SHADOW_DAMAGE	= 5,
	//ARCANE_DAMAGE	= 6,
};

enum ITEM_SPELLTRIGGER_TYPE
{
	USE				= 0,
	ON_EQUIP		= 1,
	CHANCE_ON_HIT	= 2,
	SOULSTONE		= 3,
	LEARNING		= 4,
	ON_UNEQUIP		= 5,
};

enum ITEM_BONDING_TYPE
{
	ITEM_BIND_NONE		=   0, 
	ITEM_BIND_ON_PICKUP =   1,
	ITEM_BIND_ON_EQUIP  =   2,
	ITEM_BIND_ON_USE	=   3,
	ITEM_BIND_QUEST_TRIGGER	    =   4,
	ITEM_BIND_QUEST_DROP    =   5,
	ITEM_BIND_NOEXSTRANGE = 6,
	ITEM_BIND_QUEST_DROP_AND_TRIGGER/* = 6*/,
};

enum ITEM_CLASS
{
	ITEM_CLASS_INVALID		= 0xFF,
	ITEM_CLASS_CONSUMABLE	= 0,			//	����Ʒ
	ITEM_CLASS_CONTAINER	= 1,			//	����,����=
	ITEM_CLASS_WEAPON		= 2,			//	����
	ITEM_CLASS_JEWELRY		= 3,			//	��ȸʯ==,ԭ��
	ITEM_CLASS_ARMOR		= 4,			//	װ��
	ITEM_CLASS_REAGENT		= 5,			//	ҩ��
	ITEM_CLASS_RECIPE		= 6,			//	������,�䷽,ͼ��
	ITEM_CLASS_MONEY		= 7,			//	���
	ITEM_CLASS_QUEST		= 8,			//	�������
	ITEM_CLASS_MISCELLANEOUS= 9,			//	������Ʒ
	ITEM_CLASS_USE			= 10,			//	�ظ�ʹ�õĵ���
	ITEM_CLASS_MAX,
	//ITEM_CLASS_PROJECTILE	= 6,
	//ITEM_CLASS_TRADEGOODS	= 7,			//	�ӹ����Ʒ
	//ITEM_CLASS_GENERIC		= 8,	
	//ITEM_CLASS_QUIVER		= 11,
	//ITEM_CLASS_KEY			= 13,
	//ITEM_CLASS_PERMANENT	= 14,
};

enum Item_Subclass
{
	ITEM_SUBCLASS_CONSUMABLE_POTION			= 0,
	ITEM_SUBCLASS_CONSUMABLE_FOOD			= 1,
	ITEM_SUBCLASS_CONSUMABLE_OTHER			= 2,
	ITEM_SUBCLASS_CONSUMABLE_MAX,
	// Weapon
	ITEM_SUBCLASS_WEAPON_AXE					= 0,
	ITEM_SUBCLASS_WEAPON_TWOHAND_AXE			= 1,
	ITEM_SUBCLASS_WEAPON_SWORD				= 2,
	ITEM_SUBCLASS_WEAPON_TWOHAND_SWORD		= 3,
	ITEM_SUBCLASS_WEAPON_BOW					= 4,
	ITEM_SUBCLASS_WEAPON_CROSSBOW			= 5,
	ITEM_SUBCLASS_WEAPON_STAFF				= 6,
	ITEM_SUBCLASS_WEAPON_TWOHAND_STAFF,
	ITEM_SUBCLASS_WEAPON_HAMMER,
	ITEM_SUBCLASS_WEAPON_TWOHAND_HAMMER,
	ITEM_SUBCLASS_WEAPON_BLADE,
	ITEM_SUBCLASS_WEAPON_TWOBLADE,
	ITEM_SUBCLASS_WEAPON_SHIELD,
	ITEM_SUBCLASS_WEAPON_GUN,
	ITEM_SUBCLASS_WEAPON_KNIFE,
	ITEM_SUBCLASS_WEAPON_BAOZHU,
	ITEM_SUBCLASS_WEAPON_MAX,
	// Armor
	ITEM_SUBCLASS_ARMOR_HEAD 				= 0,		//ͷ��
	ITEM_SUBCLASS_ARMOR_SHOULDER				,	//�粿
	ITEM_SUBCLASS_ARMOR_CHEST				,		//�ز�
	ITEM_SUBCLASS_ARMOR_WAIST				,		//����
	ITEM_SUBCLASS_ARMOR_FINGER				,		//��ָ
	ITEM_SUBCLASS_ARMOR_NECK				,	//����
	ITEM_SUBCLASS_ARMOR_TRINKET				,		//��Ʒ 

	ITEM_SUBCLASS_ARMOR_HAIR					,	//����
	ITEM_SUBCLASS_ARMOR_GLOVES				,		//����
	ITEM_SUBCLASS_ARMOR_WEAR				,	//����,
	ITEM_SUBCLASS_ARMOR_TROUSERS			,	//����
	ITEM_SUBCLASS_ARMOR_BOOTS				,		//Ь�� 
	ITEM_SUBCLASS_ARMOR_GUAIWUBEIBU					,	//���ﱳ��
	ITEM_SUBCLASS_ARMOR_GUAIWUTOUBU				,		//����ͷ��
	ITEM_SUBCLASS_ARMOR_GUAIWUJIANBANG				,		//������
	ITEM_SUBCLASS_ARMOR_GUAIWUSHANGYI			,		//��������
	ITEM_SUBCLASS_ARMOR_GUAIWUXIAYI				,		//�������� 
	ITEM_SUBCLASS_ARMOR_GUAIWUXIEZI				,		//����Ь�� 
	ITEM_SUBCLASS_ARMOR_SUIT				,		// ʱװ��װ
ITEM_SUBCLASS_ARMOR_MAX,
	// Trade goods
	ITEM_SUBCLASS_PROJECTILE_TRADE_GOODS		= 0,
	ITEM_SUBCLASS_PROJECTILE_PARTS			= 1,
	ITEM_SUBCLASS_PROJECTILE_EXPLOSIVES      = 2,
	ITEM_SUBCLASS_PROJECTILE_DEVICES			= 3,

	// Recipe
	ITEM_SUBCLASS_RECIPE_BOOK				= 0,
	ITEM_SUBCLASS_RECIPE_LEATHERWORKING		= 1,
	ITEM_SUBCLASS_RECIPE_TAILORING			= 2,
	ITEM_SUBCLASS_RECIPE_ENGINEERING			= 3,
	ITEM_SUBCLASS_RECIPE_BLACKSMITHING		= 4,
	ITEM_SUBCLASS_RECIPE_COOKING				= 5,
	ITEM_SUBCLASS_RECIPE_ALCHEMY				= 6,
	ITEM_SUBCLASS_RECIPE_FIRST_AID			= 7,
	ITEM_SUBCLASS_RECIPE_ENCHANTING			= 8,
	ITEM_SUBCLASS_RECIPE_FISNING				= 9,

	// Quiver
	ITEM_SUBCLASS_QUIVER_AMMO_POUCH			= 0,
	ITEM_SUBCLASS_QUIVER_QUIVER				= 1,

	// Misc
	ITEM_SUBCLASS_MISC_JUNK					= 0,

	ITEM_SUBCLASS_GEM_BLUE                      = 1,
	ITEM_SUBCLASS_GEM_GREEN                     = 2,
	ITEM_SUBCLASS_GEM_ORANGE                    = 3,
	ITEM_SUBCLASS_GEM_CHANGE_1                  = 4,
	ITEM_SUBCLASS_GEM_CHANGE_2                  = 5,
	ITEM_SUBCLASS_GEM_PROTECT                   = 6,

	ITEM_SUBCLASS_GOLD                         = 0,
	ITEM_SUBCLASS_YUANBAO					   = 1,

	ITEM_SUBCLASS_QUEST                         = 0,

ITEM_SUBCLASS_QUEST_MAX,
};

enum ITEM_QUALITY
{
	ITEM_QUALITY_POOR_GREY             = 0,//����
	ITEM_QUALITY_NORMAL_WHITE          = 1,//��ͨ
	ITEM_QUALITY_UNCOMMON_GREEN        = 2,//����
	ITEM_QUALITY_RARE_BLUE             = 3,//����
	ITEM_QUALITY_EPIC_PURPLE           = 4,//ʷʫ
	ITEM_QUALITY_LEGENDARY_ORANGE      = 5,//��˵
};
enum ITEM_FLAG
{
	ITEM_FLAG_SOULBOUND    = 0x1,      // not used in proto
	ITEM_FLAG_CONJURED     = 0x2,
	ITEM_FLAG_LOOTABLE     = 0x4,
	ITEM_FLAG_WRAP_GIFT    = 0x200,
	ITEM_FLAG_CREATE_ITEM  = 0x400,
	ITEM_FLAG_QUEST        = 0x800,
	ITEM_FLAG_SIGNABLE     = 0x2000,
	ITEM_FLAG_READABLE     = 0x4000,
	ITEM_FLAG_EVENT_REQ    = 0x10000,
	ITEM_FLAG_PROSPECTABLE = 0x40000,
	ITEM_FLAG_UNIQUE_EQUIP = 0x80000,
	ITEM_FLAG_THROWN       = 0x400000,
	ITEM_FLAG_SHAPESHIFT_OK= 0x800000,
 };
// 
// enum SPECIAL_ITEM_TYPE
// {
// 	ITEM_TYPE_SOULSHARD     = 3,	// Soul Shards
// 	ITEM_TYPE_LEATHERWORK   = 4,	// Leatherworking Supplies
// 	ITEM_TYPE_HERBALISM     = 6,	// Herbs
// 	ITEM_TYPE_ENCHANTMENT   = 7,	// Enchanting Supplies
// 	ITEM_TYPE_ENGINEERING   = 8,	// Engineering Supplies
// 	ITEM_TYPE_GEMS   	    = 10,	// Gems
// 	ITEM_TYPE_MINING	    = 11,	// Mining Supplies
// 	ITEM_TYPE_SBEQUIPMENT   = 12,	// Soulbound Equipment
// 	ITEM_TYPE_VANITYPETS    = 13	// Vanity Pets
// };

enum SOCKET_GEM_COLOR
{
	META_SOCKET = 1,
	RED_SOCKET = 2,
	YELLOW_SOCKET = 4,
	BLUE_SOCKET = 8
};

struct SocketInfo {
	uint32 SocketColor;			//	�����ɫ
	uint32 Unk;					
};

struct ItemSpell
{
	uint32 Id;					//	����ID 
	uint32 Trigger;				//	ʹ�� 
	int32 Charges;				//	��ȴʱ��
	int32 Cooldown;				//	CDʱ��
	uint32 Category;			//	��������
	int32 CategoryCooldown;		//	����������ȴʱ��
};

struct ItemDamage
{
	float Min;
	float Max;
	uint32 Type;
};

struct ItemStat
{
	uint32 Type;
	int32 Value;
};

class GossipScript;
struct ItemExtendedCostEntry;
struct ItemPrototype
{
	uint32 ItemId;
	uint32 Class;
	uint32 SubClass;
// 	uint32 unknown_bc;
	char * Name1;
// 	char * Name2;
// 	char * Name3;
// 	char * Name4;
	uint32 DisplayInfoID[3][2];
	uint32 Quality;
	uint32 Flags;
	uint32 BuyPrice;
	uint32 SellPrice;
	uint32 InventoryType;
	uint32 AllowableClass;
	uint32 AllowableRace;
	uint32 ItemLevel;
	uint32 RequiredLevel;
	uint32 RequiredSkill;
	uint32 RequiredSkillRank;
	uint32 RequiredSkillSubRank;
	uint32 RequiredPlayerRank1;		//	����ƺ�
	uint32 RequiredPlayerRank2;
	uint32 RequiredFaction;
	uint32 RequiredFactionStanding;
	uint32 Unique;					//	Я������
	uint32 MaxCount;				//	����������
	uint32 ContainerSlots;			//	������Ʒ�ĸ�������
	ItemStat Stats[10];	
	ItemDamage Damage[5];
	uint32 Armor;
// 	uint32 HolyRes;
// 	uint32 FireRes;
// 	uint32 NatureRes;
// 	uint32 FrostRes;
// 	uint32 ShadowRes;
// 	uint32 ArcaneRes;
	//uint32 Delay;					//	���������ٶ�(����)
// 	uint32 AmmoType;
	float  Range;
	ItemSpell Spells[5];
	uint32 Bonding;					//	��
	char * Description;
	uint32 PageId;
	//uint32 PageLanguage;
	//uint32 PageMaterial;
	uint32 QuestId;
	uint32 LockId;
	uint32 LockMaterial;			//	��Ʒ���� ��Ʒ�����ʹ�õ�����
	uint32 sheathID ;				//	�������õ�λ�ã���ۣ�
	uint32 RandomPropId;			//	�����ĸ�������
	uint32 RandomSuffixId;			//	�����ĸ�ħ
	uint32 Block;					//	���Ƶĸ�
	uint32 ItemSet;					//	��װID	
	uint32 MaxDurability;			//	�;ö�
	uint32 ZoneNameID;				//	ʹ����������ID����
	uint32 MapID;					//	ʹ�õ�ͼ����
	//uint32 BagFamily;				//	
	//uint32 TotemCategory;
	SocketInfo Sockets[3];
	uint32 SocketBonus;				//	��۽���
	uint32 GemProperties;			//	��ʯ����
	int32 DisenchantReqSkill;		//	��Ҫ��ħ����ֵ
	uint32 LifeStyle;
	uint32 LifeValue;
	char* Icon;
	uint32 usecnt;
	//uint32 ArmorDamageModifier;

	string lowercase_name;	// used in auctions
	uint32 FoodType;		//pet food type
	GossipScript * gossip_script;
	int32 ForcedPetId;

	ItemPrototype(){
		gossip_script = NULL;
		extended_cost = NULL;
	}

	ItemExtendedCostEntry * extended_cost;
};

typedef struct {
	uint32 setid;
	uint32 itemscount;
	//Spell* spell[8];
}ItemSet;

enum ITEM_PRICE_TYPE
{
	PRICE_TYPE_GOLD = 1,
	PRICE_TYPE_YUANBAO = 2,
	PRICE_TYPE_ITEM = 3,
	PRICE_TYPE_HORNOR,
	PRICE_TYPE_GUILD_SCORE,
	PRICE_TYPE_GUILD_CONTRIBUTE,
};

enum INV_ERR
{
	INV_ERR_OK,
	INV_ERR_YOU_MUST_REACH_LEVEL_N,
	INV_ERR_SKILL_ISNT_HIGH_ENOUGH,
	INV_ERR_ITEM_DOESNT_GO_TO_SLOT,
	INV_ERR_BAG_FULL,
	INV_ERR_NONEMPTY_BAG_OVER_OTHER_BAG,
	INV_ERR_CANT_TRADE_EQUIP_BAGS,
	INV_ERR_ONLY_AMMO_CAN_GO_HERE,
	INV_ERR_NO_REQUIRED_PROFICIENCY,
	INV_ERR_NO_EQUIPMENT_SLOT_AVAILABLE,
	INV_ERR_YOU_CAN_NEVER_USE_THAT_ITEM,
	INV_ERR_YOU_CAN_NEVER_USE_THAT_ITEM2,
	INV_ERR_NO_EQUIPMENT_SLOT_AVAILABLE2,
	INV_ERR_CANT_EQUIP_WITH_TWOHANDED,
	INV_ERR_CANT_DUAL_WIELD,
	INV_ERR_ITEM_DOESNT_GO_INTO_BAG,
	INV_ERR_ITEM_DOESNT_GO_INTO_BAG2,
	INV_ERR_CANT_CARRY_MORE_OF_THIS,
	INV_ERR_NO_EQUIPMENT_SLOT_AVAILABLE3,
	INV_ERR_ITEM_CANT_STACK,
	INV_ERR_ITEM_CANT_BE_EQUIPPED,
	INV_ERR_ITEMS_CANT_BE_SWAPPED,
	INV_ERR_SLOT_IS_EMPTY,
	INV_ERR_ITEM_NOT_FOUND,
	INV_ERR_CANT_DROP_SOULBOUND,
	INV_ERR_OUT_OF_RANGE,
	INV_ERR_TRIED_TO_SPLIT_MORE_THAN_COUNT,
	INV_ERR_COULDNT_SPLIT_ITEMS,
	INV_ERR_MISSING_REAGENT,
	INV_ERR_NOT_ENOUGH_MONEY,
	INV_ERR_NOT_ENOUGH_ITEM,
	INV_ERR_NOT_ENOUGH_HORNOR,
	INV_ERR_NOT_ENOUGH_GUILD_CONTRIBUTE,
	INV_ERR_NOT_ENOUGH_ONLY_GUILDLEADER,
	INV_ERR_NOT_ENOUGH_NOT_IN_GUILD,
	INV_ERR_NOT_ENOUGH_YUANBAO,
	INV_ERR_NOT_A_BAG,
	INV_ERR_CAN_ONLY_DO_WITH_EMPTY_BAGS,
	INV_ERR_DONT_OWN_THAT_ITEM,
	INV_ERR_CAN_EQUIP_ONLY1_QUIVER,
	INV_ERR_MUST_PURCHASE_THAT_BAG_SLOT,
	INV_ERR_TOO_FAR_AWAY_FROM_BANK,
	INV_ERR_ITEM_LOCKED,
	INV_ERR_YOU_ARE_STUNNED,
	INV_ERR_YOU_ARE_DEAD,
	INV_ERR_CANT_DO_RIGHT_NOW,
	INV_ERR_BAG_FULL2,
	INV_ERR_CAN_EQUIP_ONLY1_QUIVER2,
	INV_ERR_CAN_EQUIP_ONLY1_AMMOPOUCH,
	INV_ERR_STACKABLE_CANT_BE_WRAPPED,
	INV_ERR_EQUIPPED_CANT_BE_WRAPPED,
	INV_ERR_WRAPPED_CANT_BE_WRAPPED,
	INV_ERR_BOUND_CANT_BE_WRAPPED,
	INV_ERR_UNIQUE_CANT_BE_WRAPPED,
	INV_ERR_BAGS_CANT_BE_WRAPPED,
	INV_ERR_ALREADY_LOOTED,
	INV_ERR_INVENTORY_FULL,
	INV_ERR_BANK_FULL,
	INV_ERR_ITEM_IS_CURRENTLY_SOLD_OUT,
	INV_ERR_BAG_FULL3,
	INV_ERR_ITEM_NOT_FOUND2,
	INV_ERR_ITEM_CANT_STACK2,
	INV_ERR_BAG_FULL4,
	INV_ERR_ITEM_SOLD_OUT,
	INV_ERR_OBJECT_IS_BUSY,
	INV_ERR_NONE,
	INV_ERR_CANT_DO_IN_COMBAT,
	INV_ERR_CANT_DO_WHILE_DISARMED,
	INV_ERR_BAG_FULL6,
	INV_ERR_ITEM_RANK_NOT_ENOUGH,
	INV_ERR_ITEM_REPUTATION_NOT_ENOUGH,
	INV_ERR_MORE_THAN1_SPECIAL_BAG,
	INV_ERR_LOOT_CANT_LOOT_THAT_NOW,	// "You can't loot that item now."
	INV_ERR_ITEM_UNIQUE_EQUIPPABLE,	// "You cannot equip more than one of those."
	INV_ERR_VENDOR_MISSING_TURNINS,	// "You do not have the required items for that purchase"
	INV_ERR_NOT_ENOUGH_HONOR_POINTS,	// "You don't have enough honor points"
	INV_ERR_NOT_ENOUGH_ARENA_POINTS,	// "You don't have enough arena points"
	INV_ERR_ITEM_MAX_COUNT_SOCKETED,	// "You have the maximum number of those gems in your inventory or socketed into items."
	INV_ERR_MAIL_BOUND_ITEM,	// "You can't mail soulbound items."
	INV_ERR_INTERNAL_BAG_ERROR,	// "Internal Bag Error"
	INV_ERR_BAG_FULL7,	// "That bag is full."
	INV_ERR_ITEM_MAX_COUNT_EQUIPPED_SOCKETED,	// "You have the maximum number of those gems socketed into equipped items."
	INV_ERR_ITEM_UNIQUE_EQUIPPABLE_SOCKETED,	// "You cannot socket more than one of those gems into a single item."
	INV_ERR_TOO_MUCH_GOLD,	// "At gold limit"; -- When trading money to a player and the trade would put them over the gold limit
	INV_ERR_NOT_DURING_ARENA_MATCH,	// "You can't do that while in an arena match"
	INV_ERR_TRADE_BOUND_ITEM,	// "You can't trade a soulbound item."
	INV_ERR_CANT_EQUIP_RATING,	// "Your personal or team arena rating is too low for that item"
	INV_ERR_CANT_USE_ON_MOUNT,
	INV_ERR_CANT_USE_ON_INSTACE,
	IVN_ERR_CANT_DESTORY,
	IVN_ERR_CANT_SELL,
	IVN_ERR_CANT_TRADE,
	IVN_ERR_BUILD_OK,
	INV_ERR_NO_TITLE,
};

enum ITEM_STAT_TYPE
{
	STAT_NONE = 0,
	HEALTH,							//	����
	MANA,							//	ħ��
	STRENGTH,						//	����
	AGILITY	,						//	����
	STAMINA,						//	����
	INTELLECT ,						//	����
	SPIRIT	,						//	����
	VITALITY,						//	����
	DEFENSE_RATING ,				//	��������
	DODGE_RATING,					//	���ܼ���
	PARRY_RATING,					//	�мܼ���
	SHIELD_BLOCK_RATING,			//	���Ƹ񵲼���
	EXPERTISE_RATING,				//	�����ٶ�
	HP_RESILIENCE_RATING,			//	�����ظ��ٶ�
	MP_RESTLIENCE_RATING,			//	ħ���ظ��ٶ�
 	/*MELEE_*/HIT_RATING,			//	���м���
	/*MELEE_*/HASTE_RATING,			//	Miss����
	/*MELEE_*/CRITICAL_STRIKE_RATING,//	��������
	//WEAPON_SKILL_RATING = 11,
// 	SPELL_HIT_RATING	= 18,
// 	RANGED_HIT_RATING   = 17,
// 	RANGED_CRITICAL_STRIKE_RATING = 20,
//  RANGED_HIT_AVOIDANCE_RATING   = 23,
// 	SPELL_CRITICAL_STRIKE_RATING  = 21,
// MELEE_HIT_AVOIDANCE_RATING	= 22,
// 	SPELL_HIT_AVOIDANCE_RATING	= 24,
// 	MELEE_CRITICAL_AVOIDANCE_RATING = 25,
// 	RANGED_CRITICAL_AVOIDANCE_RATING = 26,
// 	SPELL_CRITICAL_AVOIDANCE_RATING  = 27,
// 	RANGED_HASTE_RATING			  = 29,
// 	SPELL_HASTE_RATING			   = 30,
// 	HIT_RATING					   = 31,
// 	CRITICAL_STRIKE_RATING		   = 32,
// 	HIT_AVOIDANCE_RATING			 = 33,
// 	HASTE_RATING					 = 36,
// 	EXPERTISE_RATING_2				 = 37,
};

#define MAX_TRADE_SLOT 12

enum jinglian_result_t
{
	JINGLIAN_RESULT_SUCCESS,
	JINGLIAN_RESULT_FAILED,
	JINGLIAN_RESULT_NO_MATCH_GEM,
	JINGLIAN_RESULT_NOT_ENOUGH_GOLD,
	JINGLIAN_RESULT_INVALID_ITEM,
	JINGLIAN_RESULT_ALREADY_MAX_LEVEL,
	JINGLIAN_RESULT_CHECK_SUCCESS,
};

enum jinglian_gem_t
{
// 	JINGLIAN_GEM_TYPE_UPGRADE_GREEN,
// 	JINGLIAN_GEM_TYPE_UPGRADE_BLUE,
// 	JINGLIAN_GEM_TYPE_UPGRADE_ZI,
	JINGLIAN_GEM_TYPE_MAIN,
	JINGLIAN_GEM_TYPE_CHANCE_LOW,
	JINGLIAN_GEM_TYPE_CHANCE_HIGH,
	JINGLIAN_GEM_TYPE_PROTECT,
};

static const uint32 MAX_JINGLIAN_SLOT = 6;


enum xiangqian_result_t
{
	XIANGQIAN_RESULT_SUCCESS,
	XIANGQIAN_RESULT_FAILED,
	XIANGQIAN_RESULT_NO_MATCH_MATERIAL,
	XIANGQIAN_RESULT_NOT_ENOUGH_GOLD,
	XIANGQIAN_RESULT_INVALID_ITEM,
	XIANGQIAN_RESULT_ALREADY_MAX_LEVEL,
	XIANGQIAN_RESULT_CHECK_SUCCESS,
};

enum jinglian_material_level_t
{
	XIANGQIAN_MATERIAL_LOW,
	XIANGQIAN_MATERIAL_MEDIUM,
	XIANGQIAN_MATERIAL_HIGH,
	XIANGQIAN_MATERIAL_SUPER,
};

enum item_life_style
{
	ITEM_LIFE_STYLE_NONE,
	ITEM_LIFE_STYLE_TIME,
};
static const uint32 MAX_XIANGQIAN_SLOT = 6;

//������ߵ�id

#define SPECIAL_ITEM_RESURRECT 10 //����ʯ
#define SPECIAL_ITEM_XIAOLABA 8	//С����
#define SPECIAL_ITEM_DALABA	9	//������

static const uint32 jinglian_property[ITEM_QUALITY_LEGENDARY_ORANGE+1][3] = 
{
	0,0,0,
	3,1,0,
	5,2,1,
	7,3,2,
	9,4,3,
	12,5,4,
};

#endif
