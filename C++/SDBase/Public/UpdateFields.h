#ifndef UPDATEFIELDS_H
#define UPDATEFIELDS_H

enum PLAYER_SHAPE_MOUNT_FLAG
{
	PLAYER_SHAPE_CANTFIGHT = 0x1,
	PLAYER_SHAPE_CANTMOUNT = 0x2,
	PLAYER_MOUNT_CANTFIGHT = 0x4,
};

enum OBJECT_UPDATE_FLAGS
{
	UPDATEFLAG_NONE         = 0x00,
	UPDATEFLAG_SELF         = 0x01,
	UPDATEFLAG_TRANSPORT    = 0x02,
	UPDATEFLAG_FULLGUID     = 0x04,
	UPDATEFLAG_LOWGUID      = 0x08,
	UPDATEFLAG_HIGHGUID     = 0x10,
	UPDATEFLAG_LIVING       = 0x20,
	UPDATEFLAG_HASPOSITION  = 0x40
};

enum
{
	//OBJECT:
	OBJECT_FIELD_GUID                                      	= 0x000,	//  Size: 2, Type: GUID, Flags: 1
	OBJECT_FIELD_GUID_01                                   	,	//  Size: 2, Type: GUID, Flags: 1
	OBJECT_FIELD_TYPE                                      	,	//  Size: 1, Type: Int32, Flags: 1
	OBJECT_FIELD_ENTRY                                     	,	//  Size: 1, Type: Int32, Flags: 1
	OBJECT_FIELD_SCALE_X                                   	,	//  Size: 1, Type: Float, Flags: 1
	OBJECT_FIELD_UNIQUE_ID                                 	,	//  Size: 1, Type: Int32, Flags: 0
	OBJECT_END                                              ,


	//ITEM:
	ITEM_FIELD_OWNER                                       	= OBJECT_END,	//  Size: 2, Type: GUID, Flags: 1
	ITEM_FIELD_CONTAINED                                   	= ITEM_FIELD_OWNER + 0x002,	//  Size: 2, Type: GUID, Flags: 1
	ITEM_FIELD_CREATOR                                     	= ITEM_FIELD_CONTAINED + 0x002,	//  Size: 2, Type: GUID, Flags: 1
	ITEM_FIELD_GIFTCREATOR                                 	= ITEM_FIELD_CREATOR + 0x002,	//  Size: 2, Type: GUID, Flags: 1
	ITEM_FIELD_STACK_COUNT                                 	= ITEM_FIELD_GIFTCREATOR + 0x002,	//  Size: 1, Type: Int32, Flags: 20
	ITEM_FIELD_DURATION                                    	,	//  Size: 1, Type: Int32, Flags: 20
	ITEM_FIELD_SPELL_CHARGES                               	,	//  Size: 5, Type: Int32, Flags: 20
	ITEM_FIELD_SPELL_CHARGES_01                            	,	//  Size: 5, Type: Int32, Flags: 20
	ITEM_FIELD_SPELL_CHARGES_02                            	,	//  Size: 5, Type: Int32, Flags: 20
	ITEM_FIELD_SPELL_CHARGES_03                            	,	//  Size: 5, Type: Int32, Flags: 20
	ITEM_FIELD_SPELL_CHARGES_04                            	,	//  Size: 5, Type: Int32, Flags: 20
	ITEM_FIELD_FLAGS                                       	,	//  Size: 1, Type: Int32, Flags: 1
	/*
	ITEM_FIELD_ENCHANTMENT                                 	,	//  Size: 33, Type: Int32, Flags: 1
		ITEM_FIELD_ENCHANTMENT_01                              	,	//  Size: 33, Type: Int32, Flags: 1
		ITEM_FIELD_ENCHANTMENT_02                              	,	//  Size: 33, Type: Int32, Flags: 1
		ITEM_FIELD_ENCHANTMENT_03                              	,	//  Size: 33, Type: Int32, Flags: 1
		ITEM_FIELD_ENCHANTMENT_04                              	,	//  Size: 33, Type: Int32, Flags: 1
		ITEM_FIELD_ENCHANTMENT_05                              	,	//  Size: 33, Type: Int32, Flags: 1
		ITEM_FIELD_ENCHANTMENT_06                              	,	//  Size: 33, Type: Int32, Flags: 1
		ITEM_FIELD_ENCHANTMENT_07                              	,	//  Size: 33, Type: Int32, Flags: 1
		ITEM_FIELD_ENCHANTMENT_08                              	,	//  Size: 33, Type: Int32, Flags: 1
		ITEM_FIELD_ENCHANTMENT_09                              	,	//  Size: 33, Type: Int32, Flags: 1
		ITEM_FIELD_ENCHANTMENT_10                              	,	//  Size: 33, Type: Int32, Flags: 1
		ITEM_FIELD_ENCHANTMENT_11                              	,	//  Size: 33, Type: Int32, Flags: 1
		ITEM_FIELD_ENCHANTMENT_12                              	,	//  Size: 33, Type: Int32, Flags: 1
		ITEM_FIELD_ENCHANTMENT_13                              	,	//  Size: 33, Type: Int32, Flags: 1
		ITEM_FIELD_ENCHANTMENT_14                              	,	//  Size: 33, Type: Int32, Flags: 1
		ITEM_FIELD_ENCHANTMENT_15                              	,	//  Size: 33, Type: Int32, Flags: 1
		ITEM_FIELD_ENCHANTMENT_16                              	,	//  Size: 33, Type: Int32, Flags: 1
		ITEM_FIELD_ENCHANTMENT_17                              	,	//  Size: 33, Type: Int32, Flags: 1
		ITEM_FIELD_ENCHANTMENT_18                              	,	//  Size: 33, Type: Int32, Flags: 1
		ITEM_FIELD_ENCHANTMENT_19                              	,	//  Size: 33, Type: Int32, Flags: 1
		ITEM_FIELD_ENCHANTMENT_20                              	,	//  Size: 33, Type: Int32, Flags: 1
		ITEM_FIELD_ENCHANTMENT_21                              	,	//  Size: 33, Type: Int32, Flags: 1
		ITEM_FIELD_ENCHANTMENT_22                              	,	//  Size: 33, Type: Int32, Flags: 1
		ITEM_FIELD_ENCHANTMENT_23                              	,	//  Size: 33, Type: Int32, Flags: 1
		ITEM_FIELD_ENCHANTMENT_24                              	,	//  Size: 33, Type: Int32, Flags: 1
		ITEM_FIELD_ENCHANTMENT_25                              	,	//  Size: 33, Type: Int32, Flags: 1
		ITEM_FIELD_ENCHANTMENT_26                              	,	//  Size: 33, Type: Int32, Flags: 1
		ITEM_FIELD_ENCHANTMENT_27                              	,	//  Size: 33, Type: Int32, Flags: 1
		ITEM_FIELD_ENCHANTMENT_28                              	,	//  Size: 33, Type: Int32, Flags: 1
		ITEM_FIELD_ENCHANTMENT_29                              	,	//  Size: 33, Type: Int32, Flags: 1
		ITEM_FIELD_ENCHANTMENT_30                              	,	//  Size: 33, Type: Int32, Flags: 1
		ITEM_FIELD_ENCHANTMENT_31                              	,	//  Size: 33, Type: Int32, Flags: 1
		ITEM_FIELD_ENCHANTMENT_32                              	,	//  Size: 33, Type: Int32, Flags: 1

*/
		ITEM_FIELD_PROPERTY_SEED                               	,	//  Size: 1, Type: Int32, Flags: 1
		ITEM_FIELD_RANDOM_PROPERTIES_ID                        	,	//  Size: 1, Type: Int32, Flags: 1
	
	ITEM_FIELD_VARIABLE_PROPERTIES_01 						,   //  Size: 1, Type: Int32,  //装备随机属性 最大数量8
	ITEM_FIELD_VARIABLE_PROPERTIES_02						,   //  Size: 1, Type: Int32, 
	ITEM_FIELD_ITEM_TEXT_ID                                	,	//  Size: 1, Type: Int32, Flags: 4
	ITEM_FIELD_DURABILITY                                  	,	//  Size: 1, Type: Int32, Flags: 20
	ITEM_FIELD_MAXDURABILITY                               	,	//  Size: 1, Type: Int32, Flags: 20
	ITEM_FIELD_EFFECT										,
	ITEM_FIELD_LIFE_STYLE									,	//0 = 普通道具, 1 = 计时道具(value为lifetime)
	ITEM_FIELD_LIFE_VALUE1									,	
	ITEM_FIELD_LIFE_VALUE2									,	
	ITEM_FIELD_RECORD_MAPID,
	ITEM_FIELD_RECORD_ZONEID,
	ITEM_FIELD_RECORD_POSX,
	ITEM_FIELD_RECORD_POSY,
	ITEM_FIELD_RECORD_POSZ,
	ITEM_FIELD_USE_CNT,
	ITEM_FIELD_GENERATE_TIME,
	ITEM_FIELD_VALID_AFTER_GENERATE_TIME,
	ITEM_FIELD_JINGLIAN_LEVEL,
	ITEM_FIELD_XIANGQIAN_LEVEL,
 	ITEM_FIELD_HOLE_CNT,
 	ITEM_FIELD_HOLE_1,
 	ITEM_FIELD_HOLE_2,
 	ITEM_FIELD_HOLE_3,
	ITEM_END                                                ,


	//CONTAINER:
	CONTAINER_FIELD_NUM_SLOTS                              	= ITEM_END,	//  Size: 1, Type: Int32, Flags: 1
	CONTAINER_ALIGN_PAD                                    	,	//  Size: 1, Type: Bytes, Flags: 0
	CONTAINER_FIELD_SLOT_1                                 	,	// Size: 72, Type: GUID, Flags: 1
	CONTAINER_FIELD_SLOT_01                                	,	// Size: 72, Type: GUID, Flags: 1
	CONTAINER_FIELD_SLOT_02                                	,	// Size: 72, Type: GUID, Flags: 1
	CONTAINER_FIELD_SLOT_03                                	,	// Size: 72, Type: GUID, Flags: 1
	CONTAINER_FIELD_SLOT_04                                	,	// Size: 72, Type: GUID, Flags: 1
	CONTAINER_FIELD_SLOT_05                                	,	// Size: 72, Type: GUID, Flags: 1
	CONTAINER_FIELD_SLOT_06                                	,	// Size: 72, Type: GUID, Flags: 1
	CONTAINER_FIELD_SLOT_07                                	,	// Size: 72, Type: GUID, Flags: 1
	CONTAINER_FIELD_SLOT_08                                	,	// Size: 72, Type: GUID, Flags: 1
	CONTAINER_FIELD_SLOT_09                                	,	// Size: 72, Type: GUID, Flags: 1
	CONTAINER_FIELD_SLOT_10                                	,	// Size: 72, Type: GUID, Flags: 1
	CONTAINER_FIELD_SLOT_11                                	,	// Size: 72, Type: GUID, Flags: 1
	CONTAINER_FIELD_SLOT_12                                	,	// Size: 72, Type: GUID, Flags: 1
	CONTAINER_FIELD_SLOT_13                                	,	// Size: 72, Type: GUID, Flags: 1
	CONTAINER_FIELD_SLOT_14                                	,	// Size: 72, Type: GUID, Flags: 1
	CONTAINER_FIELD_SLOT_15                                	,	// Size: 72, Type: GUID, Flags: 1
	CONTAINER_FIELD_SLOT_16                                	,	// Size: 72, Type: GUID, Flags: 1
	CONTAINER_FIELD_SLOT_17                                	,	// Size: 72, Type: GUID, Flags: 1
	CONTAINER_FIELD_SLOT_18                                	,	// Size: 72, Type: GUID, Flags: 1
	CONTAINER_FIELD_SLOT_19                                	,	// Size: 72, Type: GUID, Flags: 1
	CONTAINER_FIELD_SLOT_20                                	,	// Size: 72, Type: GUID, Flags: 1
	CONTAINER_FIELD_SLOT_21                                	,	// Size: 72, Type: GUID, Flags: 1
	CONTAINER_FIELD_SLOT_22                                	,	// Size: 72, Type: GUID, Flags: 1
	CONTAINER_FIELD_SLOT_23                                	,	// Size: 72, Type: GUID, Flags: 1
	CONTAINER_FIELD_SLOT_24                                	,	// Size: 72, Type: GUID, Flags: 1
	CONTAINER_FIELD_SLOT_25                                	,	// Size: 72, Type: GUID, Flags: 1
	CONTAINER_FIELD_SLOT_26                                	,	// Size: 72, Type: GUID, Flags: 1
	CONTAINER_FIELD_SLOT_27                                	,	// Size: 72, Type: GUID, Flags: 1
	CONTAINER_FIELD_SLOT_28                                	,	// Size: 72, Type: GUID, Flags: 1
	CONTAINER_FIELD_SLOT_29                                	,	// Size: 72, Type: GUID, Flags: 1
	CONTAINER_FIELD_SLOT_30                                	,	// Size: 72, Type: GUID, Flags: 1
	CONTAINER_FIELD_SLOT_31                                	,	// Size: 72, Type: GUID, Flags: 1
	CONTAINER_FIELD_SLOT_32                                	,	// Size: 72, Type: GUID, Flags: 1
	CONTAINER_FIELD_SLOT_33                                	,	// Size: 72, Type: GUID, Flags: 1
	CONTAINER_FIELD_SLOT_34                                	,	// Size: 72, Type: GUID, Flags: 1
	CONTAINER_FIELD_SLOT_35                                	,	// Size: 72, Type: GUID, Flags: 1
	CONTAINER_FIELD_SLOT_36                                	,	// Size: 72, Type: GUID, Flags: 1
	CONTAINER_FIELD_SLOT_37                                	,	// Size: 72, Type: GUID, Flags: 1
	CONTAINER_FIELD_SLOT_38                                	,	// Size: 72, Type: GUID, Flags: 1
	CONTAINER_FIELD_SLOT_39                                	,	// Size: 72, Type: GUID, Flags: 1
	CONTAINER_FIELD_SLOT_40                                	,	// Size: 72, Type: GUID, Flags: 1
	CONTAINER_FIELD_SLOT_41                                	,	// Size: 72, Type: GUID, Flags: 1
	CONTAINER_FIELD_SLOT_42                                	,	// Size: 72, Type: GUID, Flags: 1
	CONTAINER_FIELD_SLOT_43                                	,	// Size: 72, Type: GUID, Flags: 1
	CONTAINER_FIELD_SLOT_44                                	,	// Size: 72, Type: GUID, Flags: 1
	CONTAINER_FIELD_SLOT_45                                	,	// Size: 72, Type: GUID, Flags: 1
	CONTAINER_FIELD_SLOT_46                                	,	// Size: 72, Type: GUID, Flags: 1
	CONTAINER_FIELD_SLOT_47                                	,	// Size: 72, Type: GUID, Flags: 1
	CONTAINER_FIELD_SLOT_48                                	,	// Size: 72, Type: GUID, Flags: 1
	CONTAINER_FIELD_SLOT_49                                	,	// Size: 72, Type: GUID, Flags: 1
	CONTAINER_FIELD_SLOT_50                                	,	// Size: 72, Type: GUID, Flags: 1
	CONTAINER_FIELD_SLOT_51                                	,	// Size: 72, Type: GUID, Flags: 1
	CONTAINER_FIELD_SLOT_52                                	,	// Size: 72, Type: GUID, Flags: 1
	CONTAINER_FIELD_SLOT_53                                	,	// Size: 72, Type: GUID, Flags: 1
	CONTAINER_FIELD_SLOT_54                                	,	// Size: 72, Type: GUID, Flags: 1
	CONTAINER_FIELD_SLOT_55                                	,	// Size: 72, Type: GUID, Flags: 1
	CONTAINER_FIELD_SLOT_56                                	,	// Size: 72, Type: GUID, Flags: 1
	CONTAINER_FIELD_SLOT_57                                	,	// Size: 72, Type: GUID, Flags: 1
	CONTAINER_FIELD_SLOT_58                                	,	// Size: 72, Type: GUID, Flags: 1
	CONTAINER_FIELD_SLOT_59                                	,	// Size: 72, Type: GUID, Flags: 1
	CONTAINER_FIELD_SLOT_60                                	,	// Size: 72, Type: GUID, Flags: 1
	CONTAINER_FIELD_SLOT_61                                	,	// Size: 72, Type: GUID, Flags: 1
	CONTAINER_FIELD_SLOT_62                                	,	// Size: 72, Type: GUID, Flags: 1
	CONTAINER_FIELD_SLOT_63                                	,	// Size: 72, Type: GUID, Flags: 1
	CONTAINER_FIELD_SLOT_64                                	,	// Size: 72, Type: GUID, Flags: 1
	CONTAINER_FIELD_SLOT_65                                	,	// Size: 72, Type: GUID, Flags: 1
	CONTAINER_FIELD_SLOT_66                                	,	// Size: 72, Type: GUID, Flags: 1
	CONTAINER_FIELD_SLOT_67                                	,	// Size: 72, Type: GUID, Flags: 1
	CONTAINER_FIELD_SLOT_68                                	,	// Size: 72, Type: GUID, Flags: 1
	CONTAINER_FIELD_SLOT_69                                	,	// Size: 72, Type: GUID, Flags: 1
	CONTAINER_FIELD_SLOT_70                                	,	// Size: 72, Type: GUID, Flags: 1
	CONTAINER_FIELD_SLOT_71                                	,	// Size: 72, Type: GUID, Flags: 1
	CONTAINER_END                                          	,	// Size: 1, Type: Int32, Flags: 0

	//UNIT:
	UNIT_FIELD_CHARM                                       	= OBJECT_END,	//  Size: 2, Type: GUID, Flags: 1
	UNIT_FIELD_SUMMON                                      	= OBJECT_END + 0x002,	//  Size: 2, Type: GUID, Flags: 1
	UNIT_FIELD_CHARMEDBY                                   	= OBJECT_END + 0x004,	//  Size: 2, Type: GUID, Flags: 1
	UNIT_FIELD_SUMMONEDBY                                  	= OBJECT_END + 0x006,	//  Size: 2, Type: GUID, Flags: 1
	UNIT_FIELD_CREATEDBY                                   	= OBJECT_END + 0x008,	//  Size: 2, Type: GUID, Flags: 1
	UNIT_FIELD_TARGET                                      	= OBJECT_END + 0x00A,	//  Size: 2, Type: GUID, Flags: 1
	UNIT_FIELD_PERSUADED                                   	= OBJECT_END + 0x00C,	//  Size: 2, Type: GUID, Flags: 1
	UNIT_FIELD_CHANNEL_OBJECT                              	= OBJECT_END + 0x00E,	//  Size: 2, Type: GUID, Flags: 1
	UNIT_FIELD_HEALTH										= OBJECT_END + 0x010,	//  Size: 1, Type: Int32, Flags: 256
	UNIT_FIELD_POWER1                                      	,	//  Size: 1, Type: Int32, Flags: 1
// 	UNIT_FIELD_POWER2                                      	,	//  Size: 1, Type: Int32, Flags: 1
// 	UNIT_FIELD_POWER3                                      	,	//  Size: 1, Type: Int32, Flags: 1
// 	UNIT_FIELD_POWER4                                      	,	//  Size: 1, Type: Int32, Flags: 1
// 	UNIT_FIELD_POWER5                                      	,	//  Size: 1, Type: Int32, Flags: 1
	UNIT_FIELD_MAXHEALTH                                   	,	//  Size: 1, Type: Int32, Flags: 256
	UNIT_FIELD_MAXPOWER1                                   	,	//  Size: 1, Type: Int32, Flags: 1
// 	UNIT_FIELD_MAXPOWER2                                   	,	//  Size: 1, Type: Int32, Flags: 1
// 	UNIT_FIELD_MAXPOWER3                                   	,	//  Size: 1, Type: Int32, Flags: 1
// 	UNIT_FIELD_MAXPOWER4                                   	,	//  Size: 1, Type: Int32, Flags: 1
// 	UNIT_FIELD_MAXPOWER5                                   	,	//  Size: 1, Type: Int32, Flags: 1
	UNIT_FIELD_LEVEL                                       	,	//  Size: 1, Type: Int32, Flags: 1
	UNIT_FIELD_FACTIONTEMPLATE                             	,	//  Size: 1, Type: Int32, Flags: 1
	UNIT_FIELD_BYTES_0                                     	,	//  Size: 1, Type: Bytes, Flags: 1		0byte=race,1byte=class,2byte=gender,3byte=powertype
	UNIT_VIRTUAL_ITEM_SLOT_DISPLAY                         	,	//  Size: 3, Type: Int32, Flags: 1
	UNIT_VIRTUAL_ITEM_SLOT_DISPLAY_01                      	,	//  Size: 3, Type: Int32, Flags: 1
// 	UNIT_VIRTUAL_ITEM_SLOT_DISPLAY_02                      	,	//  Size: 3, Type: Int32, Flags: 1
	UNIT_VIRTUAL_ITEM_INFO                                 	,	//  Size: 6, Type: Bytes, Flags: 1
	UNIT_VIRTUAL_ITEM_INFO_01                              	,	//  Size: 6, Type: Bytes, Flags: 1
// 	UNIT_VIRTUAL_ITEM_INFO_02                              	,	//  Size: 6, Type: Bytes, Flags: 1
// 	UNIT_VIRTUAL_ITEM_INFO_03                              	,	//  Size: 6, Type: Bytes, Flags: 1
// 	UNIT_VIRTUAL_ITEM_INFO_04                              	,	//  Size: 6, Type: Bytes, Flags: 1
// 	UNIT_VIRTUAL_ITEM_INFO_05                              	,	//  Size: 6, Type: Bytes, Flags: 1
	UNIT_FIELD_FLAGS                                       	,	//  Size: 1, Type: Int32, Flags: 1
	UNIT_FIELD_FLAGS_2                                     	,	//  Size: 1, Type: Int32, Flags: 1
	UNIT_FIELD_AURA                                        	,	//  spellid Size: 56, Type: Int32, Flags: 1
	UNIT_FIELD_AURA_01                                     	,	//  Size: 56, Type: Int32, Flags: 1
	UNIT_FIELD_AURA_02                                     	,	//  Size: 56, Type: Int32, Flags: 1
	UNIT_FIELD_AURA_03                                     	,	//  Size: 56, Type: Int32, Flags: 1
	UNIT_FIELD_AURA_04                                     	,	//  Size: 56, Type: Int32, Flags: 1
	UNIT_FIELD_AURA_05                                     	,	//  Size: 56, Type: Int32, Flags: 1
	UNIT_FIELD_AURA_06                                     	,	//  Size: 56, Type: Int32, Flags: 1
	UNIT_FIELD_AURA_07                                     	,	//  Size: 56, Type: Int32, Flags: 1
	UNIT_FIELD_AURA_08                                     	,	//  Size: 56, Type: Int32, Flags: 1
	UNIT_FIELD_AURA_09                                     	,	//  Size: 56, Type: Int32, Flags: 1
	UNIT_FIELD_AURA_10                                     	,	//  Size: 56, Type: Int32, Flags: 1
	UNIT_FIELD_AURA_11                                     	,	//  Size: 56, Type: Int32, Flags: 1
	UNIT_FIELD_AURA_12                                     	,	//  Size: 56, Type: Int32, Flags: 1
	UNIT_FIELD_AURA_13                                     	,	//  Size: 56, Type: Int32, Flags: 1
	UNIT_FIELD_AURA_14                                     	,	//  Size: 56, Type: Int32, Flags: 1
	UNIT_FIELD_AURA_15                                     	,	//  Size: 56, Type: Int32, Flags: 1
	UNIT_FIELD_AURA_16                                     	,	//  Size: 56, Type: Int32, Flags: 1
	UNIT_FIELD_AURA_17                                     	,	//  Size: 56, Type: Int32, Flags: 1
	UNIT_FIELD_AURA_18                                     	,	//  Size: 56, Type: Int32, Flags: 1
	UNIT_FIELD_AURA_19                                     	,	//  Size: 56, Type: Int32, Flags: 1
	UNIT_FIELD_AURA_20                                     	,	//  Size: 56, Type: Int32, Flags: 1
	UNIT_FIELD_AURA_21                                     	,	//  Size: 56, Type: Int32, Flags: 1
	UNIT_FIELD_AURA_22                                     	,	//  Size: 56, Type: Int32, Flags: 1
	UNIT_FIELD_AURA_23                                     	,	//  Size: 56, Type: Int32, Flags: 1
	UNIT_FIELD_AURA_24                                     	,	//  Size: 56, Type: Int32, Flags: 1
	UNIT_FIELD_AURA_25                                     	,	//  Size: 56, Type: Int32, Flags: 1
	UNIT_FIELD_AURA_26                                     	,	//  Size: 56, Type: Int32, Flags: 1
	UNIT_FIELD_AURA_27                                     	,	//  Size: 56, Type: Int32, Flags: 1
	UNIT_FIELD_AURA_28                                     	,	//  Size: 56, Type: Int32, Flags: 1
	UNIT_FIELD_AURA_29                                     	,	//  Size: 56, Type: Int32, Flags: 1
	UNIT_FIELD_AURA_30                                     	,	//  Size: 56, Type: Int32, Flags: 1
	UNIT_FIELD_AURA_31                                     	,	//  Size: 56, Type: Int32, Flags: 1
	UNIT_FIELD_AURA_32                                     	,	//  Size: 56, Type: Int32, Flags: 1
	UNIT_FIELD_AURA_33                                     	,	//  Size: 56, Type: Int32, Flags: 1
	UNIT_FIELD_AURA_34                                     	,	//  Size: 56, Type: Int32, Flags: 1
	UNIT_FIELD_AURA_35                                     	,	//  Size: 56, Type: Int32, Flags: 1
	UNIT_FIELD_AURA_36                                     	,	//  Size: 56, Type: Int32, Flags: 1
	UNIT_FIELD_AURA_37                                     	,	//  Size: 56, Type: Int32, Flags: 1
	UNIT_FIELD_AURA_38                                     	,	//  Size: 56, Type: Int32, Flags: 1
	UNIT_FIELD_AURA_39                                     	,	//  Size: 56, Type: Int32, Flags: 1
	UNIT_FIELD_AURA_40                                     	,	//  Size: 56, Type: Int32, Flags: 1
	UNIT_FIELD_AURA_41                                     	,	//  Size: 56, Type: Int32, Flags: 1
	UNIT_FIELD_AURA_42                                     	,	//  Size: 56, Type: Int32, Flags: 1
	UNIT_FIELD_AURA_43                                     	,	//  Size: 56, Type: Int32, Flags: 1
	UNIT_FIELD_AURA_44                                     	,	//  Size: 56, Type: Int32, Flags: 1
	UNIT_FIELD_AURA_45                                     	,	//  Size: 56, Type: Int32, Flags: 1
	UNIT_FIELD_AURA_46                                     	,	//  Size: 56, Type: Int32, Flags: 1
	UNIT_FIELD_AURA_47                                     	,	//  Size: 56, Type: Int32, Flags: 1
	UNIT_FIELD_AURA_48                                     	,	//  Size: 56, Type: Int32, Flags: 1
	UNIT_FIELD_AURA_49                                     	,	//  Size: 56, Type: Int32, Flags: 1
	UNIT_FIELD_AURA_50                                     	,	//  Size: 56, Type: Int32, Flags: 1
	UNIT_FIELD_AURA_51                                     	,	//  Size: 56, Type: Int32, Flags: 1
	UNIT_FIELD_AURA_52                                     	,	//  Size: 56, Type: Int32, Flags: 1
	UNIT_FIELD_AURA_53                                     	,	//  Size: 56, Type: Int32, Flags: 1
	UNIT_FIELD_AURA_54                                     	,	//  Size: 56, Type: Int32, Flags: 1
	UNIT_FIELD_AURA_55                                     	,	//  Size: 56, Type: Int32, Flags: 1
	UNIT_FIELD_AURAFLAGS                                   	,	//  Size: 14, Type: Bytes, Flags: 1
	UNIT_FIELD_AURAFLAGS_01                                	,	//  Size: 14, Type: Bytes, Flags: 1
	UNIT_FIELD_AURAFLAGS_02                                	,	//  Size: 14, Type: Bytes, Flags: 1
	UNIT_FIELD_AURAFLAGS_03                                	,	//  Size: 14, Type: Bytes, Flags: 1
	UNIT_FIELD_AURAFLAGS_04                                	,	//  Size: 14, Type: Bytes, Flags: 1
	UNIT_FIELD_AURAFLAGS_05                                	,	//  Size: 14, Type: Bytes, Flags: 1
	UNIT_FIELD_AURAFLAGS_06                                	,	//  Size: 14, Type: Bytes, Flags: 1
	UNIT_FIELD_AURAFLAGS_07                                	,	//  Size: 14, Type: Bytes, Flags: 1
	UNIT_FIELD_AURAFLAGS_08                                	,	//  Size: 14, Type: Bytes, Flags: 1
	UNIT_FIELD_AURAFLAGS_09                                	,	//  Size: 14, Type: Bytes, Flags: 1
	UNIT_FIELD_AURAFLAGS_10                                	,	//  Size: 14, Type: Bytes, Flags: 1
	UNIT_FIELD_AURAFLAGS_11                                	,	//  Size: 14, Type: Bytes, Flags: 1
	UNIT_FIELD_AURAFLAGS_12                                	,	//  Size: 14, Type: Bytes, Flags: 1
	UNIT_FIELD_AURAFLAGS_13                                	,	//  Size: 14, Type: Bytes, Flags: 1
	UNIT_FIELD_AURALEVELS                                  	,	//  Size: 14, Type: Bytes, Flags: 1
	UNIT_FIELD_AURALEVELS_01                               	,	//  Size: 14, Type: Bytes, Flags: 1
	UNIT_FIELD_AURALEVELS_02                               	,	//  Size: 14, Type: Bytes, Flags: 1
	UNIT_FIELD_AURALEVELS_03                               	,	//  Size: 14, Type: Bytes, Flags: 1
	UNIT_FIELD_AURALEVELS_04                               	,	//  Size: 14, Type: Bytes, Flags: 1
	UNIT_FIELD_AURALEVELS_05                               	,	//  Size: 14, Type: Bytes, Flags: 1
	UNIT_FIELD_AURALEVELS_06                               	,	//  Size: 14, Type: Bytes, Flags: 1
	UNIT_FIELD_AURALEVELS_07                               	,	//  Size: 14, Type: Bytes, Flags: 1
	UNIT_FIELD_AURALEVELS_08                               	,	//  Size: 14, Type: Bytes, Flags: 1
	UNIT_FIELD_AURALEVELS_09                               	,	//  Size: 14, Type: Bytes, Flags: 1
	UNIT_FIELD_AURALEVELS_10                               	,	//  Size: 14, Type: Bytes, Flags: 1
	UNIT_FIELD_AURALEVELS_11                               	,	//  Size: 14, Type: Bytes, Flags: 1
	UNIT_FIELD_AURALEVELS_12                               	,	//  Size: 14, Type: Bytes, Flags: 1
	UNIT_FIELD_AURALEVELS_13                               	,	//  Size: 14, Type: Bytes, Flags: 1
	UNIT_FIELD_AURAAPPLICATIONS                            	,	//  Size: 14, Type: Bytes, Flags: 1
	UNIT_FIELD_AURAAPPLICATIONS_01                         	,	//  Size: 14, Type: Bytes, Flags: 1
	UNIT_FIELD_AURAAPPLICATIONS_02                         	,	//  Size: 14, Type: Bytes, Flags: 1
	UNIT_FIELD_AURAAPPLICATIONS_03                         	,	//  Size: 14, Type: Bytes, Flags: 1
	UNIT_FIELD_AURAAPPLICATIONS_04                         	,	//  Size: 14, Type: Bytes, Flags: 1
	UNIT_FIELD_AURAAPPLICATIONS_05                         	,	//  Size: 14, Type: Bytes, Flags: 1
	UNIT_FIELD_AURAAPPLICATIONS_06                         	,	//  Size: 14, Type: Bytes, Flags: 1
	UNIT_FIELD_AURAAPPLICATIONS_07                         	,	//  Size: 14, Type: Bytes, Flags: 1
	UNIT_FIELD_AURAAPPLICATIONS_08                         	,	//  Size: 14, Type: Bytes, Flags: 1
	UNIT_FIELD_AURAAPPLICATIONS_09                         	,	//  Size: 14, Type: Bytes, Flags: 1
	UNIT_FIELD_AURAAPPLICATIONS_10                         	,	//  Size: 14, Type: Bytes, Flags: 1
	UNIT_FIELD_AURAAPPLICATIONS_11                         	,	//  Size: 14, Type: Bytes, Flags: 1
	UNIT_FIELD_AURAAPPLICATIONS_12                         	,	//  Size: 14, Type: Bytes, Flags: 1
	UNIT_FIELD_AURAAPPLICATIONS_13                         	,	//  Size: 14, Type: Bytes, Flags: 1
	UNIT_FIELD_AURASTATE                                   	,	//  Size: 1, Type: Int32, Flags: 1
	UNIT_FIELD_BASEATTACKTIME                              	,	//  Size: 2, Type: Int32, Flags: 1
	UNIT_FIELD_BASEATTACKTIME_01                           	,	//  Size: 2, Type: Int32, Flags: 1
	UNIT_FIELD_RANGEDATTACKTIME                            	,	//  Size: 1, Type: Int32, Flags: 2
	UNIT_FIELD_BOUNDINGRADIUS                              	,	//  Size: 1, Type: Float, Flags: 1
	UNIT_FIELD_COMBATREACH                                 	,	//  Size: 1, Type: Float, Flags: 1
	UNIT_FIELD_DISPLAYID                                   	,	//  Size: 1, Type: Int32, Flags: 1
	UNIT_FIELD_NATIVEDISPLAYID                             	,	//  Size: 1, Type: Int32, Flags: 1
	UNIT_FIELD_MOUNTDISPLAYID                              	,	//  Size: 1, Type: Int32, Flags: 1
	UNIT_FIELD_FORMDISPLAYID                              	,	//  Size: 1, Type: Int32, Flags: 1
	UNIT_FIELD_MINDAMAGE                                   	,	//  Size: 1, Type: Float, Flags: 38
	UNIT_FIELD_MAXDAMAGE                                   	,	//  Size: 1, Type: Float, Flags: 38
	UNIT_FIELD_MINOFFHANDDAMAGE                            	,	//  Size: 1, Type: Float, Flags: 38
	UNIT_FIELD_MAXOFFHANDDAMAGE                            	,	//  Size: 1, Type: Float, Flags: 38
	UNIT_FIELD_SPELLDAMAGE,
	UNIT_FIELD_BYTES_1                                     	,	//  Size: 1, Type: Bytes, Flags: 1
	UNIT_FIELD_PETNUMBER                                   	,	//  Size: 1, Type: Int32, Flags: 1
	UNIT_FIELD_PET_NAME_TIMESTAMP                          	,	//  Size: 1, Type: Int32, Flags: 1
	UNIT_FIELD_PETEXPERIENCE                               	,	//  Size: 1, Type: Int32, Flags: 4
	UNIT_FIELD_PETNEXTLEVELEXP                             	,	//  Size: 1, Type: Int32, Flags: 4
	UNIT_FIELD_PET_FEED_TIME,
	UNIT_DYNAMIC_FLAGS                                     	,	//  Size: 1, Type: Int32, Flags: 256
	UNIT_CHANNEL_SPELL                                     	,	//  Size: 1, Type: Int32, Flags: 1
	UNIT_MOD_CAST_SPEED                                    	,	//  Size: 1, Type: Float, Flags: 1
	UNIT_CREATED_BY_SPELL                                  	,	//  Size: 1, Type: Int32, Flags: 1
	UNIT_NPC_FLAGS                                         	,	//  Size: 1, Type: Int32, Flags: 256
	UNIT_NPC_EMOTESTATE                                    	,	//  Size: 1, Type: Int32, Flags: 1
	UNIT_TRAINING_POINTS                                   	,	//  Size: 1, Type: Chars?, Flags: 4
	UNIT_FIELD_STAT0                                       	,	//  Size: 1, Type: Int32, Flags: 6
	UNIT_FIELD_STAT1                                       	,	//  Size: 1, Type: Int32, Flags: 6
	UNIT_FIELD_STAT2                                       	,	//  Size: 1, Type: Int32, Flags: 6
	UNIT_FIELD_STAT3                                       	,	//  Size: 1, Type: Int32, Flags: 6
	UNIT_FIELD_STAT4                                       	,	//  Size: 1, Type: Int32, Flags: 6
	UNIT_FIELD_STAT5										,	//	Size: 1, Type: Int32, Flags: 6
	UNIT_FIELD_POSSTAT0                                    	,	//  Size: 1, Type: Int32, Flags: 6
	UNIT_FIELD_POSSTAT1                                    	,	//  Size: 1, Type: Int32, Flags: 6
	UNIT_FIELD_POSSTAT2                                    	,	//  Size: 1, Type: Int32, Flags: 6
	UNIT_FIELD_POSSTAT3                                    	,	//  Size: 1, Type: Int32, Flags: 6
	UNIT_FIELD_POSSTAT4                                    	,	//  Size: 1, Type: Int32, Flags: 6
	UNIT_FIELD_POSSTAT5                                    	,	//  Size: 1, Type: Int32, Flags: 6
	UNIT_FIELD_NEGSTAT0                                    	,	//  Size: 1, Type: Int32, Flags: 6
	UNIT_FIELD_NEGSTAT1                                    	,	//  Size: 1, Type: Int32, Flags: 6
	UNIT_FIELD_NEGSTAT2                                    	,	//  Size: 1, Type: Int32, Flags: 6
	UNIT_FIELD_NEGSTAT3                                    	,	//  Size: 1, Type: Int32, Flags: 6
	UNIT_FIELD_NEGSTAT4                                    	,	//  Size: 1, Type: Int32, Flags: 6
	UNIT_FIELD_NEGSTAT5                                    	,	//  Size: 1, Type: Int32, Flags: 6
	UNIT_FIELD_RESISTANCES                                 	,	//  Size: 7, Type: Int32, Flags: 38
	UNIT_FIELD_RESISTANCES_01                              	,	//  Size: 7, Type: Int32, Flags: 38
	UNIT_FIELD_RESISTANCES_02                              	,	//  Size: 7, Type: Int32, Flags: 38
	UNIT_FIELD_RESISTANCES_03                              	,	//  Size: 7, Type: Int32, Flags: 38
	UNIT_FIELD_RESISTANCES_04                              	,	//  Size: 7, Type: Int32, Flags: 38
	UNIT_FIELD_RESISTANCES_05                              	,	//  Size: 7, Type: Int32, Flags: 38
	UNIT_FIELD_RESISTANCES_06                              	,	//  Size: 7, Type: Int32, Flags: 38
	UNIT_FIELD_RESISTANCEBUFFMODSPOSITIVE                  	,	//  Size: 7, Type: Int32, Flags: 6
	UNIT_FIELD_RESISTANCEBUFFMODSPOSITIVE_01               	,	//  Size: 7, Type: Int32, Flags: 6
	UNIT_FIELD_RESISTANCEBUFFMODSPOSITIVE_02               	,	//  Size: 7, Type: Int32, Flags: 6
	UNIT_FIELD_RESISTANCEBUFFMODSPOSITIVE_03               	,	//  Size: 7, Type: Int32, Flags: 6
	UNIT_FIELD_RESISTANCEBUFFMODSPOSITIVE_04               	,	//  Size: 7, Type: Int32, Flags: 6
	UNIT_FIELD_RESISTANCEBUFFMODSPOSITIVE_05               	,	//  Size: 7, Type: Int32, Flags: 6
	UNIT_FIELD_RESISTANCEBUFFMODSPOSITIVE_06               	,	//  Size: 7, Type: Int32, Flags: 6
	UNIT_FIELD_RESISTANCEBUFFMODSNEGATIVE                  	,	//  Size: 7, Type: Int32, Flags: 6
	UNIT_FIELD_RESISTANCEBUFFMODSNEGATIVE_01               	,	//  Size: 7, Type: Int32, Flags: 6
	UNIT_FIELD_RESISTANCEBUFFMODSNEGATIVE_02               	,	//  Size: 7, Type: Int32, Flags: 6
	UNIT_FIELD_RESISTANCEBUFFMODSNEGATIVE_03               	,	//  Size: 7, Type: Int32, Flags: 6
	UNIT_FIELD_RESISTANCEBUFFMODSNEGATIVE_04               	,	//  Size: 7, Type: Int32, Flags: 6
	UNIT_FIELD_RESISTANCEBUFFMODSNEGATIVE_05               	,	//  Size: 7, Type: Int32, Flags: 6
	UNIT_FIELD_RESISTANCEBUFFMODSNEGATIVE_06               	,	//  Size: 7, Type: Int32, Flags: 6
	UNIT_FIELD_BASE_MANA                                   	,	//  Size: 1, Type: Int32, Flags: 6
	UNIT_FIELD_BASE_HEALTH                                 	,	//  Size: 1, Type: Int32, Flags: 6
	UNIT_FIELD_BYTES_2                                     	,	//  Size: 1, Type: Bytes, Flags: 1
	UNIT_FIELD_ATTACK_POWER                                	,	//  Size: 1, Type: Int32, Flags: 6
	UNIT_FIELD_ATTACK_POWER_MODS                           	,	//  Size: 1, Type: Chars?, Flags: 6
	UNIT_FIELD_ATTACK_POWER_MULTIPLIER                     	,	//  Size: 1, Type: Float, Flags: 6
	UNIT_FIELD_RANGED_ATTACK_POWER                         	,	//  Size: 1, Type: Int32, Flags: 6
	UNIT_FIELD_RANGED_ATTACK_POWER_MODS                    	,	//  Size: 1, Type: Chars?, Flags: 6
	UNIT_FIELD_RANGED_ATTACK_POWER_MULTIPLIER              	,	//  Size: 1, Type: Float, Flags: 6
	UNIT_FIELD_MINRANGEDDAMAGE                             	,	//  Size: 1, Type: Float, Flags: 6
	UNIT_FIELD_MAXRANGEDDAMAGE                             	,	//  Size: 1, Type: Float, Flags: 6
	UNIT_FIELD_POWER_COST_MODIFIER                         	,	//  Size: 7, Type: Int32, Flags: 6
	UNIT_FIELD_POWER_COST_MODIFIER_01                      	,	//  Size: 7, Type: Int32, Flags: 6
	UNIT_FIELD_POWER_COST_MODIFIER_02                      	,	//  Size: 7, Type: Int32, Flags: 6
	UNIT_FIELD_POWER_COST_MODIFIER_03                      	,	//  Size: 7, Type: Int32, Flags: 6
	UNIT_FIELD_POWER_COST_MODIFIER_04                      	,	//  Size: 7, Type: Int32, Flags: 6
	UNIT_FIELD_POWER_COST_MODIFIER_05                      	,	//  Size: 7, Type: Int32, Flags: 6
	UNIT_FIELD_POWER_COST_MODIFIER_06                      	,	//  Size: 7, Type: Int32, Flags: 6
	UNIT_FIELD_POWER_COST_MULTIPLIER                       	,	//  Size: 7, Type: Float, Flags: 6
	UNIT_FIELD_POWER_COST_MULTIPLIER_01                    	,	//  Size: 7, Type: Float, Flags: 6
	UNIT_FIELD_POWER_COST_MULTIPLIER_02                    	,	//  Size: 7, Type: Float, Flags: 6
	UNIT_FIELD_POWER_COST_MULTIPLIER_03                    	,	//  Size: 7, Type: Float, Flags: 6
	UNIT_FIELD_POWER_COST_MULTIPLIER_04                    	,	//  Size: 7, Type: Float, Flags: 6
	UNIT_FIELD_POWER_COST_MULTIPLIER_05                    	,	//  Size: 7, Type: Float, Flags: 6
	UNIT_FIELD_POWER_COST_MULTIPLIER_06                    	,	//  Size: 7, Type: Float, Flags: 6
	UNIT_FIELD_MAXHEALTHMODIFIER                           	,	//  Size: 1, Type: Float, Flags: 6
	UNIT_FIELD_PADDING                                     	,	//  Size: 1, Type: Int32, Flags: 0
	UNIT_FIELD_ICE_BLOCK,
	UNIT_FIELD_DEATH_STATE,
	UNIT_END                                                ,

	//PLAYER:
	PLAYER_DUEL_ARBITER                                    	= UNIT_END + 0x000,	//  Size: 2, Type: GUID, Flags: 1
	PLAYER_FLAGS                                           	= UNIT_END + 0x002,	//  Size: 1, Type: Int32, Flags: 1
	PLAYER_GUILDID                                         	,	//  Size: 1, Type: Int32, Flags: 1
	PLAYER_GUILDRANK                                       	,	//  Size: 1, Type: Int32, Flags: 1
	PLAYER_BYTES                                           	,	//  Size: 1, Type: Bytes, Flags: 1
	PLAYER_BYTES_2                                         	,	//  Size: 1, Type: Bytes, Flags: 1
	PLAYER_BYTES_3                                         	,	//  Size: 1, Type: Bytes, Flags: 1
	PLAYER_DUEL_TEAM                                       	,	//  Size: 1, Type: Int32, Flags: 1
	PLAYER_GUILD_TIMESTAMP                                 	,	//  Size: 1, Type: Int32, Flags: 1
	PLAYER_QUEST_LOG_1_1                                   	,	//  Size: 1, Type: Int32, Flags: 64
	PLAYER_QUEST_LOG_1_2                                   	,	//  Size: 1, Type: Int32, Flags: 2
	PLAYER_QUEST_LOG_1_3                                   	,	//  Size: 1, Type: Bytes, Flags: 2
	PLAYER_QUEST_LOG_1_4                                   	,	//  Size: 1, Type: Int32, Flags: 2
	PLAYER_QUEST_LOG_2_1                                   	,	//  Size: 1, Type: Int32, Flags: 64
	PLAYER_QUEST_LOG_2_2                                   	,	//  Size: 1, Type: Int32, Flags: 2
	PLAYER_QUEST_LOG_2_3                                   	,	//  Size: 1, Type: Bytes, Flags: 2
	PLAYER_QUEST_LOG_2_4                                   	,	//  Size: 1, Type: Int32, Flags: 2
	PLAYER_QUEST_LOG_3_1                                   	,	//  Size: 1, Type: Int32, Flags: 64
	PLAYER_QUEST_LOG_3_2                                   	,	//  Size: 1, Type: Int32, Flags: 2
	PLAYER_QUEST_LOG_3_3                                   	,	//  Size: 1, Type: Bytes, Flags: 2
	PLAYER_QUEST_LOG_3_4                                   	,	//  Size: 1, Type: Int32, Flags: 2
	PLAYER_QUEST_LOG_4_1                                   	,	//  Size: 1, Type: Int32, Flags: 64
	PLAYER_QUEST_LOG_4_2                                   	,	//  Size: 1, Type: Int32, Flags: 2
	PLAYER_QUEST_LOG_4_3                                   	,	//  Size: 1, Type: Bytes, Flags: 2
	PLAYER_QUEST_LOG_4_4                                   	,	//  Size: 1, Type: Int32, Flags: 2
	PLAYER_QUEST_LOG_5_1                                   	,	//  Size: 1, Type: Int32, Flags: 64
	PLAYER_QUEST_LOG_5_2                                   	,	//  Size: 1, Type: Int32, Flags: 2
	PLAYER_QUEST_LOG_5_3                                   	,	//  Size: 1, Type: Bytes, Flags: 2
	PLAYER_QUEST_LOG_5_4                                   	,	//  Size: 1, Type: Int32, Flags: 2
	PLAYER_QUEST_LOG_6_1                                   	,	//  Size: 1, Type: Int32, Flags: 64
	PLAYER_QUEST_LOG_6_2                                   	,	//  Size: 1, Type: Int32, Flags: 2
	PLAYER_QUEST_LOG_6_3                                   	,	//  Size: 1, Type: Bytes, Flags: 2
	PLAYER_QUEST_LOG_6_4                                   	,	//  Size: 1, Type: Int32, Flags: 2
	PLAYER_QUEST_LOG_7_1                                   	,	//  Size: 1, Type: Int32, Flags: 64
	PLAYER_QUEST_LOG_7_2                                   	,	//  Size: 1, Type: Int32, Flags: 2
	PLAYER_QUEST_LOG_7_3                                   	,	//  Size: 1, Type: Bytes, Flags: 2
	PLAYER_QUEST_LOG_7_4                                   	,	//  Size: 1, Type: Int32, Flags: 2
	PLAYER_QUEST_LOG_8_1                                   	,	//  Size: 1, Type: Int32, Flags: 64
	PLAYER_QUEST_LOG_8_2                                   	,	//  Size: 1, Type: Int32, Flags: 2
	PLAYER_QUEST_LOG_8_3                                   	,	//  Size: 1, Type: Bytes, Flags: 2
	PLAYER_QUEST_LOG_8_4                                   	,	//  Size: 1, Type: Int32, Flags: 2
	PLAYER_QUEST_LOG_9_1                                   	,	//  Size: 1, Type: Int32, Flags: 64
	PLAYER_QUEST_LOG_9_2                                   	,	//  Size: 1, Type: Int32, Flags: 2
	PLAYER_QUEST_LOG_9_3                                   	,	//  Size: 1, Type: Bytes, Flags: 2
	PLAYER_QUEST_LOG_9_4                                   	,	//  Size: 1, Type: Int32, Flags: 2
	PLAYER_QUEST_LOG_10_1                                  	,	//  Size: 1, Type: Int32, Flags: 64
	PLAYER_QUEST_LOG_10_2                                  	,	//  Size: 1, Type: Int32, Flags: 2
	PLAYER_QUEST_LOG_10_3                                  	,	//  Size: 1, Type: Bytes, Flags: 2
	PLAYER_QUEST_LOG_10_4                                  	,	//  Size: 1, Type: Int32, Flags: 2
	PLAYER_QUEST_LOG_11_1                                  	,	//  Size: 1, Type: Int32, Flags: 64
	PLAYER_QUEST_LOG_11_2                                  	,	//  Size: 1, Type: Int32, Flags: 2
	PLAYER_QUEST_LOG_11_3                                  	,	//  Size: 1, Type: Bytes, Flags: 2
	PLAYER_QUEST_LOG_11_4                                  	,	//  Size: 1, Type: Int32, Flags: 2
	PLAYER_QUEST_LOG_12_1                                  	,	//  Size: 1, Type: Int32, Flags: 64
	PLAYER_QUEST_LOG_12_2                                  	,	//  Size: 1, Type: Int32, Flags: 2
	PLAYER_QUEST_LOG_12_3                                  	,	//  Size: 1, Type: Bytes, Flags: 2
	PLAYER_QUEST_LOG_12_4                                  	,	//  Size: 1, Type: Int32, Flags: 2
	PLAYER_QUEST_LOG_13_1                                  	,	//  Size: 1, Type: Int32, Flags: 64
	PLAYER_QUEST_LOG_13_2                                  	,	//  Size: 1, Type: Int32, Flags: 2
	PLAYER_QUEST_LOG_13_3                                  	,	//  Size: 1, Type: Bytes, Flags: 2
	PLAYER_QUEST_LOG_13_4                                  	,	//  Size: 1, Type: Int32, Flags: 2
	PLAYER_QUEST_LOG_14_1                                  	,	//  Size: 1, Type: Int32, Flags: 64
	PLAYER_QUEST_LOG_14_2                                  	,	//  Size: 1, Type: Int32, Flags: 2
	PLAYER_QUEST_LOG_14_3                                  	,	//  Size: 1, Type: Bytes, Flags: 2
	PLAYER_QUEST_LOG_14_4                                  	,	//  Size: 1, Type: Int32, Flags: 2
	PLAYER_QUEST_LOG_15_1                                  	,	//  Size: 1, Type: Int32, Flags: 64
	PLAYER_QUEST_LOG_15_2                                  	,	//  Size: 1, Type: Int32, Flags: 2
	PLAYER_QUEST_LOG_15_3                                  	,	//  Size: 1, Type: Bytes, Flags: 2
	PLAYER_QUEST_LOG_15_4                                  	,	//  Size: 1, Type: Int32, Flags: 2
	PLAYER_QUEST_LOG_16_1                                  	,	//  Size: 1, Type: Int32, Flags: 64
	PLAYER_QUEST_LOG_16_2                                  	,	//  Size: 1, Type: Int32, Flags: 2
	PLAYER_QUEST_LOG_16_3                                  	,	//  Size: 1, Type: Bytes, Flags: 2
	PLAYER_QUEST_LOG_16_4                                  	,	//  Size: 1, Type: Int32, Flags: 2
	PLAYER_QUEST_LOG_17_1                                  	,	//  Size: 1, Type: Int32, Flags: 64
	PLAYER_QUEST_LOG_17_2                                  	,	//  Size: 1, Type: Int32, Flags: 2
	PLAYER_QUEST_LOG_17_3                                  	,	//  Size: 1, Type: Bytes, Flags: 2
	PLAYER_QUEST_LOG_17_4                                  	,	//  Size: 1, Type: Int32, Flags: 2
	PLAYER_QUEST_LOG_18_1                                  	,	//  Size: 1, Type: Int32, Flags: 64
	PLAYER_QUEST_LOG_18_2                                  	,	//  Size: 1, Type: Int32, Flags: 2
	PLAYER_QUEST_LOG_18_3                                  	,	//  Size: 1, Type: Bytes, Flags: 2
	PLAYER_QUEST_LOG_18_4                                  	,	//  Size: 1, Type: Int32, Flags: 2
	PLAYER_QUEST_LOG_19_1                                  	,	//  Size: 1, Type: Int32, Flags: 64
	PLAYER_QUEST_LOG_19_2                                  	,	//  Size: 1, Type: Int32, Flags: 2
	PLAYER_QUEST_LOG_19_3                                  	,	//  Size: 1, Type: Bytes, Flags: 2
	PLAYER_QUEST_LOG_19_4                                  	,	//  Size: 1, Type: Int32, Flags: 2
	PLAYER_QUEST_LOG_20_1                                  	,	//  Size: 1, Type: Int32, Flags: 64
	PLAYER_QUEST_LOG_20_2                                  	,	//  Size: 1, Type: Int32, Flags: 2
	PLAYER_QUEST_LOG_20_3                                  	,	//  Size: 1, Type: Bytes, Flags: 2
	PLAYER_QUEST_LOG_20_4                                  	,	//  Size: 1, Type: Int32, Flags: 2
	PLAYER_QUEST_LOG_21_1                                  	,	//  Size: 1, Type: Int32, Flags: 64
	PLAYER_QUEST_LOG_21_2                                  	,	//  Size: 1, Type: Int32, Flags: 2
	PLAYER_QUEST_LOG_21_3                                  	,	//  Size: 1, Type: Bytes, Flags: 2
	PLAYER_QUEST_LOG_21_4                                  	,	//  Size: 1, Type: Int32, Flags: 2
	PLAYER_QUEST_LOG_22_1                                  	,	//  Size: 1, Type: Int32, Flags: 64
	PLAYER_QUEST_LOG_22_2                                  	,	//  Size: 1, Type: Int32, Flags: 2
	PLAYER_QUEST_LOG_22_3                                  	,	//  Size: 1, Type: Bytes, Flags: 2
	PLAYER_QUEST_LOG_22_4                                  	,	//  Size: 1, Type: Int32, Flags: 2
	PLAYER_QUEST_LOG_23_1                                  	,	//  Size: 1, Type: Int32, Flags: 64
	PLAYER_QUEST_LOG_23_2                                  	,	//  Size: 1, Type: Int32, Flags: 2
	PLAYER_QUEST_LOG_23_3                                  	,	//  Size: 1, Type: Bytes, Flags: 2
	PLAYER_QUEST_LOG_23_4                                  	,	//  Size: 1, Type: Int32, Flags: 2
	PLAYER_QUEST_LOG_24_1                                  	,	//  Size: 1, Type: Int32, Flags: 64
	PLAYER_QUEST_LOG_24_2                                  	,	//  Size: 1, Type: Int32, Flags: 2
	PLAYER_QUEST_LOG_24_3                                  	,	//  Size: 1, Type: Bytes, Flags: 2
	PLAYER_QUEST_LOG_24_4                                  	,	//  Size: 1, Type: Int32, Flags: 2
	PLAYER_QUEST_LOG_25_1                                  	,	//  Size: 1, Type: Int32, Flags: 64
	PLAYER_QUEST_LOG_25_2                                  	,	//  Size: 1, Type: Int32, Flags: 2
	PLAYER_QUEST_LOG_25_3                                  	,	//  Size: 1, Type: Bytes, Flags: 2
	PLAYER_QUEST_LOG_25_4                                  	,	//  Size: 1, Type: Int32, Flags: 2
	PLAYER_QUEST_LOG_26_1                                  	,	//  Size: 1, Type: Int32, Flags: 64
	PLAYER_QUEST_LOG_26_2                                  	,	//  Size: 1, Type: Int32, Flags: 2
	PLAYER_QUEST_LOG_26_3                                  	,	//  Size: 1, Type: Bytes, Flags: 2
	PLAYER_QUEST_LOG_26_4                                  	,	//  Size: 1, Type: Int32, Flags: 2
	PLAYER_QUEST_LOG_27_1                                  	,	//  Size: 1, Type: Int32, Flags: 64
	PLAYER_QUEST_LOG_27_2                                  	,	//  Size: 1, Type: Int32, Flags: 2
	PLAYER_QUEST_LOG_27_3                                  	,	//  Size: 1, Type: Bytes, Flags: 2
	PLAYER_QUEST_LOG_27_4                                  	,	//  Size: 1, Type: Int32, Flags: 2
	PLAYER_QUEST_LOG_28_1                                  	,	//  Size: 1, Type: Int32, Flags: 64
	PLAYER_QUEST_LOG_28_2                                  	,	//  Size: 1, Type: Int32, Flags: 2
	PLAYER_QUEST_LOG_28_3                                  	,	//  Size: 1, Type: Bytes, Flags: 2
	PLAYER_QUEST_LOG_28_4                                  	,	//  Size: 1, Type: Int32, Flags: 2
	PLAYER_QUEST_LOG_29_1                                  	,	//  Size: 1, Type: Int32, Flags: 64
	PLAYER_QUEST_LOG_29_2                                  	,	//  Size: 1, Type: Int32, Flags: 2
	PLAYER_QUEST_LOG_29_3                                  	,	//  Size: 1, Type: Bytes, Flags: 2
	PLAYER_QUEST_LOG_29_4                                  	,	//  Size: 1, Type: Int32, Flags: 2
	PLAYER_QUEST_LOG_30_1                                  	,	//  Size: 1, Type: Int32, Flags: 64
	PLAYER_QUEST_LOG_30_2                                  	,	//  Size: 1, Type: Int32, Flags: 2
	PLAYER_QUEST_LOG_30_3                                  	,	//  Size: 1, Type: Bytes, Flags: 2
	PLAYER_QUEST_LOG_30_4                                  	,	//  Size: 1, Type: Int32, Flags: 2
	PLAYER_QUEST_LOG_31_1                                  	,	//  Size: 1, Type: Int32, Flags: 64
	PLAYER_QUEST_LOG_31_2                                  	,	//  Size: 1, Type: Int32, Flags: 2
	PLAYER_QUEST_LOG_31_3                                  	,	//  Size: 1, Type: Bytes, Flags: 2
	PLAYER_QUEST_LOG_31_4                                  	,	//  Size: 1, Type: Int32, Flags: 2
	PLAYER_QUEST_LOG_32_1                                  	,	//  Size: 1, Type: Int32, Flags: 64
	PLAYER_QUEST_LOG_32_2                                  	,	//  Size: 1, Type: Int32, Flags: 2
	PLAYER_QUEST_LOG_32_3                                  	,	//  Size: 1, Type: Bytes, Flags: 2
	PLAYER_QUEST_LOG_32_4                                  	,	//  Size: 1, Type: Int32, Flags: 2
	PLAYER_QUEST_LOG_33_1                                  	,	//  Size: 1, Type: Int32, Flags: 64
	PLAYER_QUEST_LOG_33_2                                  	,	//  Size: 1, Type: Int32, Flags: 2
	PLAYER_QUEST_LOG_33_3                                  	,	//  Size: 1, Type: Bytes, Flags: 2
	PLAYER_QUEST_LOG_33_4                                  	,	//  Size: 1, Type: Int32, Flags: 2
	PLAYER_QUEST_LOG_34_1                                  	,	//  Size: 1, Type: Int32, Flags: 64
	PLAYER_QUEST_LOG_34_2                                  	,	//  Size: 1, Type: Int32, Flags: 2
	PLAYER_QUEST_LOG_34_3                                  	,	//  Size: 1, Type: Bytes, Flags: 2
	PLAYER_QUEST_LOG_34_4                                  	,	//  Size: 1, Type: Int32, Flags: 2
	PLAYER_QUEST_LOG_35_1                                  	,	//  Size: 1, Type: Int32, Flags: 64
	PLAYER_QUEST_LOG_35_2                                  	,	//  Size: 1, Type: Int32, Flags: 2
	PLAYER_QUEST_LOG_35_3                                  	,	//  Size: 1, Type: Bytes, Flags: 2
	PLAYER_QUEST_LOG_35_4                                  	,	//  Size: 1, Type: Int32, Flags: 2
	PLAYER_QUEST_LOG_36_1                                  	,	//  Size: 1, Type: Int32, Flags: 64
	PLAYER_QUEST_LOG_36_2                                  	,	//  Size: 1, Type: Int32, Flags: 2
	PLAYER_QUEST_LOG_36_3                                  	,	//  Size: 1, Type: Bytes, Flags: 2
	PLAYER_QUEST_LOG_36_4                                  	,	//  Size: 1, Type: Int32, Flags: 2
	PLAYER_QUEST_LOG_37_1                                  	,	//  Size: 1, Type: Int32, Flags: 64
	PLAYER_QUEST_LOG_37_2                                  	,	//  Size: 1, Type: Int32, Flags: 2
	PLAYER_QUEST_LOG_37_3                                  	,	//  Size: 1, Type: Bytes, Flags: 2
	PLAYER_QUEST_LOG_37_4                                  	,	//  Size: 1, Type: Int32, Flags: 2
	PLAYER_QUEST_LOG_38_1                                  	,	//  Size: 1, Type: Int32, Flags: 64
	PLAYER_QUEST_LOG_38_2                                  	,	//  Size: 1, Type: Int32, Flags: 2
	PLAYER_QUEST_LOG_38_3                                  	,	//  Size: 1, Type: Bytes, Flags: 2
	PLAYER_QUEST_LOG_38_4                                  	,	//  Size: 1, Type: Int32, Flags: 2
	PLAYER_QUEST_LOG_39_1                                  	,	//  Size: 1, Type: Int32, Flags: 64
	PLAYER_QUEST_LOG_39_2                                  	,	//  Size: 1, Type: Int32, Flags: 2
	PLAYER_QUEST_LOG_39_3                                  	,	//  Size: 1, Type: Bytes, Flags: 2
	PLAYER_QUEST_LOG_39_4                                  	,	//  Size: 1, Type: Int32, Flags: 2
	PLAYER_QUEST_LOG_40_1                                  	,	//  Size: 1, Type: Int32, Flags: 64
	PLAYER_QUEST_LOG_40_2                                  	,	//  Size: 1, Type: Int32, Flags: 2
	PLAYER_QUEST_LOG_40_3                                  	,	//  Size: 1, Type: Bytes, Flags: 2
	PLAYER_QUEST_LOG_40_4                                  	,	//  Size: 1, Type: Int32, Flags: 2
	PLAYER_QUEST_LOG_41_1                                  	,	//  Size: 1, Type: Int32, Flags: 64
	PLAYER_QUEST_LOG_41_2                                  	,	//  Size: 1, Type: Int32, Flags: 2
	PLAYER_QUEST_LOG_41_3                                  	,	//  Size: 1, Type: Bytes, Flags: 2
	PLAYER_QUEST_LOG_41_4                                  	,	//  Size: 1, Type: Int32, Flags: 2
	PLAYER_QUEST_LOG_42_1                                  	,	//  Size: 1, Type: Int32, Flags: 64
	PLAYER_QUEST_LOG_42_2                                  	,	//  Size: 1, Type: Int32, Flags: 2
	PLAYER_QUEST_LOG_42_3                                  	,	//  Size: 1, Type: Bytes, Flags: 2
	PLAYER_QUEST_LOG_42_4                                  	,	//  Size: 1, Type: Int32, Flags: 2
	PLAYER_QUEST_LOG_43_1                                  	,	//  Size: 1, Type: Int32, Flags: 64
	PLAYER_QUEST_LOG_43_2                                  	,	//  Size: 1, Type: Int32, Flags: 2
	PLAYER_QUEST_LOG_43_3                                  	,	//  Size: 1, Type: Bytes, Flags: 2
	PLAYER_QUEST_LOG_43_4                                  	,	//  Size: 1, Type: Int32, Flags: 2
	PLAYER_QUEST_LOG_44_1                                  	,	//  Size: 1, Type: Int32, Flags: 64
	PLAYER_QUEST_LOG_44_2                                  	,	//  Size: 1, Type: Int32, Flags: 2
	PLAYER_QUEST_LOG_44_3                                  	,	//  Size: 1, Type: Bytes, Flags: 2
	PLAYER_QUEST_LOG_44_4                                  	,	//  Size: 1, Type: Int32, Flags: 2
	PLAYER_QUEST_LOG_45_1                                  	,	//  Size: 1, Type: Int32, Flags: 64
	PLAYER_QUEST_LOG_45_2                                  	,	//  Size: 1, Type: Int32, Flags: 2
	PLAYER_QUEST_LOG_45_3                                  	,	//  Size: 1, Type: Bytes, Flags: 2
	PLAYER_QUEST_LOG_45_4                                  	,	//  Size: 1, Type: Int32, Flags: 2
	PLAYER_QUEST_LOG_46_1                                  	,	//  Size: 1, Type: Int32, Flags: 64
	PLAYER_QUEST_LOG_46_2                                  	,	//  Size: 1, Type: Int32, Flags: 2
	PLAYER_QUEST_LOG_46_3                                  	,	//  Size: 1, Type: Bytes, Flags: 2
	PLAYER_QUEST_LOG_46_4                                  	,	//  Size: 1, Type: Int32, Flags: 2
	PLAYER_QUEST_LOG_47_1                                  	,	//  Size: 1, Type: Int32, Flags: 64
	PLAYER_QUEST_LOG_47_2                                  	,	//  Size: 1, Type: Int32, Flags: 2
	PLAYER_QUEST_LOG_47_3                                  	,	//  Size: 1, Type: Bytes, Flags: 2
	PLAYER_QUEST_LOG_47_4                                  	,	//  Size: 1, Type: Int32, Flags: 2
	PLAYER_QUEST_LOG_48_1                                  	,	//  Size: 1, Type: Int32, Flags: 64
	PLAYER_QUEST_LOG_48_2                                  	,	//  Size: 1, Type: Int32, Flags: 2
	PLAYER_QUEST_LOG_48_3                                  	,	//  Size: 1, Type: Bytes, Flags: 2
	PLAYER_QUEST_LOG_48_4                                  	,	//  Size: 1, Type: Int32, Flags: 2
	PLAYER_QUEST_LOG_49_1                                  	,	//  Size: 1, Type: Int32, Flags: 64
	PLAYER_QUEST_LOG_49_2                                  	,	//  Size: 1, Type: Int32, Flags: 2
	PLAYER_QUEST_LOG_49_3                                  	,	//  Size: 1, Type: Bytes, Flags: 2
	PLAYER_QUEST_LOG_49_4                                  	,	//  Size: 1, Type: Int32, Flags: 2
	PLAYER_QUEST_LOG_50_1                                  	,	//  Size: 1, Type: Int32, Flags: 64
	PLAYER_QUEST_LOG_50_2                                  	,	//  Size: 1, Type: Int32, Flags: 2
	PLAYER_QUEST_LOG_50_3                                  	,	//  Size: 1, Type: Bytes, Flags: 2
	PLAYER_QUEST_LOG_50_4                                  	,	//  Size: 1, Type: Int32, Flags: 2
	PLAYER_VISIBLE_ITEM_1_CREATOR                          	,	//  Size: 2, Type: GUID, Flags: 1

	PLAYER_VISIBLE_ITEM_1_0                                	= PLAYER_VISIBLE_ITEM_1_CREATOR + 0x002,	//  Size: 12, Type: Int32, Flags: 1 
	PLAYER_VISIBLE_ITEM_1_01                               	,	//  Size: 12, Type: Int32, Flags: 1											hole_cnt
	PLAYER_VISIBLE_ITEM_1_02                               	,	//  Size: 12, Type: Int32, Flags: 1											hole_1
	PLAYER_VISIBLE_ITEM_1_03                               	,	//  Size: 12, Type: Int32, Flags: 1											hole_2
	PLAYER_VISIBLE_ITEM_1_04                               	,	//  Size: 12, Type: Int32, Flags: 1											hole_3
	PLAYER_VISIBLE_ITEM_1_05                               	,	//  Size: 12, Type: Int32, Flags: 1											jinglian_level
	PLAYER_VISIBLE_ITEM_1_06                               	,	//  Size: 12, Type: Int32, Flags: 1											xiangqian_level
	PLAYER_VISIBLE_ITEM_1_07                               	,	//  Size: 12, Type: Int32, Flags: 1											property_1
	PLAYER_VISIBLE_ITEM_1_08                               	,	//  Size: 12, Type: Int32, Flags: 1											property_2
	PLAYER_VISIBLE_ITEM_1_09                               	,	//  Size: 12, Type: Int32, Flags: 1
//	PLAYER_VISIBLE_ITEM_1_10                               	,	//  Size: 12, Type: Int32, Flags: 1
//	PLAYER_VISIBLE_ITEM_1_11                               	,	//  Size: 12, Type: Int32, Flags: 1
//	PLAYER_VISIBLE_ITEM_1_PROPERTIES                       	,	//  Size: 1, Type: Chars?, Flags: 1
//	PLAYER_VISIBLE_ITEM_1_PAD                              	,	//  Size: 1, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_2_CREATOR                          	,	//  Size: 2, Type: GUID, Flags: 1
	PLAYER_VISIBLE_ITEM_2_0                                	= PLAYER_VISIBLE_ITEM_2_CREATOR + 2,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_2_01                               	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_2_02                               	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_2_03                               	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_2_04                               	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_2_05                               	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_2_06                               	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_2_07                               	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_2_08                               	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_2_09                               	,	//  Size: 12, Type: Int32, Flags: 1
// 	PLAYER_VISIBLE_ITEM_2_10                               	,	//  Size: 12, Type: Int32, Flags: 1
// 	PLAYER_VISIBLE_ITEM_2_11                               	,	//  Size: 12, Type: Int32, Flags: 1
// 	PLAYER_VISIBLE_ITEM_2_PROPERTIES                       	,	//  Size: 1, Type: Chars?, Flags: 1
// 	PLAYER_VISIBLE_ITEM_2_PAD                              	,	//  Size: 1, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_3_CREATOR                          	,	//  Size: 2, Type: GUID, Flags: 1
	PLAYER_VISIBLE_ITEM_3_0                                	= PLAYER_VISIBLE_ITEM_3_CREATOR + 2,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_3_01                               	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_3_02                               	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_3_03                               	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_3_04                               	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_3_05                               	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_3_06                               	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_3_07                               	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_3_08                               	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_3_09                               	,	//  Size: 12, Type: Int32, Flags: 1
// 	PLAYER_VISIBLE_ITEM_3_10                               	,	//  Size: 12, Type: Int32, Flags: 1
// 	PLAYER_VISIBLE_ITEM_3_11                               	,	//  Size: 12, Type: Int32, Flags: 1
// 	PLAYER_VISIBLE_ITEM_3_PROPERTIES                       	,	//  Size: 1, Type: Chars?, Flags: 1
// 	PLAYER_VISIBLE_ITEM_3_PAD                              	,	//  Size: 1, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_4_CREATOR                          	,	//  Size: 2, Type: GUID, Flags: 1
	PLAYER_VISIBLE_ITEM_4_0                                	= PLAYER_VISIBLE_ITEM_4_CREATOR + 2,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_4_01                               	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_4_02                               	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_4_03                               	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_4_04                               	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_4_05                               	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_4_06                               	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_4_07                               	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_4_08                               	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_4_09                               	,	//  Size: 12, Type: Int32, Flags: 1
// 	PLAYER_VISIBLE_ITEM_4_10                               	,	//  Size: 12, Type: Int32, Flags: 1
// 	PLAYER_VISIBLE_ITEM_4_11                               	,	//  Size: 12, Type: Int32, Flags: 1
// 	PLAYER_VISIBLE_ITEM_4_PROPERTIES                       	,	//  Size: 1, Type: Chars?, Flags: 1
// 	PLAYER_VISIBLE_ITEM_4_PAD                              	,	//  Size: 1, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_5_CREATOR                          	,	//  Size: 2, Type: GUID, Flags: 1
	PLAYER_VISIBLE_ITEM_5_0                                	= PLAYER_VISIBLE_ITEM_5_CREATOR + 2,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_5_01                               	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_5_02                               	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_5_03                               	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_5_04                               	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_5_05                               	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_5_06                               	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_5_07                               	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_5_08                               	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_5_09                               	,	//  Size: 12, Type: Int32, Flags: 1
// 	PLAYER_VISIBLE_ITEM_5_10                               	,	//  Size: 12, Type: Int32, Flags: 1
// 	PLAYER_VISIBLE_ITEM_5_11                               	,	//  Size: 12, Type: Int32, Flags: 1
// 	PLAYER_VISIBLE_ITEM_5_PROPERTIES                       	,	//  Size: 1, Type: Chars?, Flags: 1
// 	PLAYER_VISIBLE_ITEM_5_PAD                              	,	//  Size: 1, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_6_CREATOR                          	,	//  Size: 2, Type: GUID, Flags: 1
	PLAYER_VISIBLE_ITEM_6_0                                	= PLAYER_VISIBLE_ITEM_6_CREATOR + 2,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_6_01                               	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_6_02                               	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_6_03                               	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_6_04                               	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_6_05                               	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_6_06                               	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_6_07                               	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_6_08                               	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_6_09                               	,	//  Size: 12, Type: Int32, Flags: 1
// 	PLAYER_VISIBLE_ITEM_6_10                               	,	//  Size: 12, Type: Int32, Flags: 1
// 	PLAYER_VISIBLE_ITEM_6_11                               	,	//  Size: 12, Type: Int32, Flags: 1
// 	PLAYER_VISIBLE_ITEM_6_PROPERTIES                       	,	//  Size: 1, Type: Chars?, Flags: 1
// 	PLAYER_VISIBLE_ITEM_6_PAD                              	,	//  Size: 1, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_7_CREATOR                          	,	//  Size: 2, Type: GUID, Flags: 1
	PLAYER_VISIBLE_ITEM_7_0                                	= PLAYER_VISIBLE_ITEM_7_CREATOR + 2,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_7_01                               	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_7_02                               	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_7_03                               	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_7_04                               	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_7_05                               	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_7_06                               	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_7_07                               	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_7_08                               	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_7_09                               	,	//  Size: 12, Type: Int32, Flags: 1
// 	PLAYER_VISIBLE_ITEM_7_10                               	,	//  Size: 12, Type: Int32, Flags: 1
// 	PLAYER_VISIBLE_ITEM_7_11                               	,	//  Size: 12, Type: Int32, Flags: 1
// 	PLAYER_VISIBLE_ITEM_7_PROPERTIES                       	,	//  Size: 1, Type: Chars?, Flags: 1
// 	PLAYER_VISIBLE_ITEM_7_PAD                              	,	//  Size: 1, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_8_CREATOR                          	,	//  Size: 2, Type: GUID, Flags: 1
	PLAYER_VISIBLE_ITEM_8_0                                	= PLAYER_VISIBLE_ITEM_8_CREATOR + 2,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_8_01                               	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_8_02                               	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_8_03                               	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_8_04                               	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_8_05                               	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_8_06                               	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_8_07                               	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_8_08                               	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_8_09                               	,	//  Size: 12, Type: Int32, Flags: 1
// 	PLAYER_VISIBLE_ITEM_8_10                               	,	//  Size: 12, Type: Int32, Flags: 1
// 	PLAYER_VISIBLE_ITEM_8_11                               	,	//  Size: 12, Type: Int32, Flags: 1
// 	PLAYER_VISIBLE_ITEM_8_PROPERTIES                       	,	//  Size: 1, Type: Chars?, Flags: 1
// 	PLAYER_VISIBLE_ITEM_8_PAD                              	,	//  Size: 1, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_9_CREATOR                          	,	//  Size: 2, Type: GUID, Flags: 1
	PLAYER_VISIBLE_ITEM_9_0                                	= PLAYER_VISIBLE_ITEM_9_CREATOR + 2,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_9_01                               	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_9_02                               	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_9_03                               	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_9_04                               	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_9_05                               	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_9_06                               	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_9_07                               	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_9_08                               	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_9_09                               	,	//  Size: 12, Type: Int32, Flags: 1
// 	PLAYER_VISIBLE_ITEM_9_10                               	,	//  Size: 12, Type: Int32, Flags: 1
// 	PLAYER_VISIBLE_ITEM_9_11                               	,	//  Size: 12, Type: Int32, Flags: 1
// 	PLAYER_VISIBLE_ITEM_9_PROPERTIES                       	,	//  Size: 1, Type: Chars?, Flags: 1
// 	PLAYER_VISIBLE_ITEM_9_PAD                              	,	//  Size: 1, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_10_CREATOR                         	,	//  Size: 2, Type: GUID, Flags: 1
	PLAYER_VISIBLE_ITEM_10_0                               	= PLAYER_VISIBLE_ITEM_10_CREATOR + 2,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_10_01                              	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_10_02                              	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_10_03                              	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_10_04                              	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_10_05                              	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_10_06                              	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_10_07                              	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_10_08                              	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_10_09                              	,	//  Size: 12, Type: Int32, Flags: 1
// 	PLAYER_VISIBLE_ITEM_10_10                              	,	//  Size: 12, Type: Int32, Flags: 1
// 	PLAYER_VISIBLE_ITEM_10_11                              	,	//  Size: 12, Type: Int32, Flags: 1
// 	PLAYER_VISIBLE_ITEM_10_PROPERTIES                      	,	//  Size: 1, Type: Chars?, Flags: 1
// 	PLAYER_VISIBLE_ITEM_10_PAD                             	,	//  Size: 1, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_11_CREATOR                         	,	//  Size: 2, Type: GUID, Flags: 1
	PLAYER_VISIBLE_ITEM_11_0                               	= PLAYER_VISIBLE_ITEM_11_CREATOR + 2,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_11_01                              	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_11_02                              	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_11_03                              	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_11_04                              	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_11_05                              	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_11_06                              	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_11_07                              	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_11_08                              	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_11_09                              	,	//  Size: 12, Type: Int32, Flags: 1
// 	PLAYER_VISIBLE_ITEM_11_10                              	,	//  Size: 12, Type: Int32, Flags: 1
// 	PLAYER_VISIBLE_ITEM_11_11                              	,	//  Size: 12, Type: Int32, Flags: 1
// 	PLAYER_VISIBLE_ITEM_11_PROPERTIES                      	,	//  Size: 1, Type: Chars?, Flags: 1
// 	PLAYER_VISIBLE_ITEM_11_PAD                             	,	//  Size: 1, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_12_CREATOR                         	,	//  Size: 2, Type: GUID, Flags: 1
	PLAYER_VISIBLE_ITEM_12_0                               	= PLAYER_VISIBLE_ITEM_12_CREATOR + 2,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_12_01                              	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_12_02                              	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_12_03                              	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_12_04                              	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_12_05                              	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_12_06                              	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_12_07                              	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_12_08                              	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_12_09                              	,	//  Size: 12, Type: Int32, Flags: 1
// 	PLAYER_VISIBLE_ITEM_12_10                              	,	//  Size: 12, Type: Int32, Flags: 1
// 	PLAYER_VISIBLE_ITEM_12_11                              	,	//  Size: 12, Type: Int32, Flags: 1
// 	PLAYER_VISIBLE_ITEM_12_PROPERTIES                      	,	//  Size: 1, Type: Chars?, Flags: 1
// 	PLAYER_VISIBLE_ITEM_12_PAD                             	,	//  Size: 1, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_13_CREATOR                         	,	//  Size: 2, Type: GUID, Flags: 1
	PLAYER_VISIBLE_ITEM_13_0                               	= PLAYER_VISIBLE_ITEM_13_CREATOR + 2,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_13_01                              	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_13_02                              	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_13_03                              	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_13_04                              	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_13_05                              	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_13_06                              	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_13_07                              	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_13_08                              	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_13_09                              	,	//  Size: 12, Type: Int32, Flags: 1
// 	PLAYER_VISIBLE_ITEM_13_10                              	,	//  Size: 12, Type: Int32, Flags: 1
// 	PLAYER_VISIBLE_ITEM_13_11                              	,	//  Size: 12, Type: Int32, Flags: 1
// 	PLAYER_VISIBLE_ITEM_13_PROPERTIES                      	,	//  Size: 1, Type: Chars?, Flags: 1
// 	PLAYER_VISIBLE_ITEM_13_PAD                             	,	//  Size: 1, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_14_CREATOR                         	,	//  Size: 2, Type: GUID, Flags: 1
	PLAYER_VISIBLE_ITEM_14_0                               	= PLAYER_VISIBLE_ITEM_14_CREATOR + 2,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_14_01                              	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_14_02                              	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_14_03                              	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_14_04                              	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_14_05                              	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_14_06                              	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_14_07                              	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_14_08                              	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_14_09                              	,	//  Size: 12, Type: Int32, Flags: 1
// 	PLAYER_VISIBLE_ITEM_14_10                              	,	//  Size: 12, Type: Int32, Flags: 1
// 	PLAYER_VISIBLE_ITEM_14_11                              	,	//  Size: 12, Type: Int32, Flags: 1
// 	PLAYER_VISIBLE_ITEM_14_PROPERTIES                      	,	//  Size: 1, Type: Chars?, Flags: 1
// 	PLAYER_VISIBLE_ITEM_14_PAD                             	,	//  Size: 1, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_15_CREATOR                         	,	//  Size: 2, Type: GUID, Flags: 1
	PLAYER_VISIBLE_ITEM_15_0                               	= PLAYER_VISIBLE_ITEM_15_CREATOR + 2,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_15_01                              	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_15_02                              	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_15_03                              	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_15_04                              	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_15_05                              	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_15_06                              	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_15_07                              	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_15_08                              	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_15_09                              	,	//  Size: 12, Type: Int32, Flags: 1
// 	PLAYER_VISIBLE_ITEM_15_10                              	,	//  Size: 12, Type: Int32, Flags: 1
// 	PLAYER_VISIBLE_ITEM_15_11                              	,	//  Size: 12, Type: Int32, Flags: 1
// 	PLAYER_VISIBLE_ITEM_15_PROPERTIES                      	,	//  Size: 1, Type: Chars?, Flags: 1
// 	PLAYER_VISIBLE_ITEM_15_PAD                             	,	//  Size: 1, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_16_CREATOR                         	,	//  Size: 2, Type: GUID, Flags: 1
	PLAYER_VISIBLE_ITEM_16_0                               	= PLAYER_VISIBLE_ITEM_16_CREATOR + 2,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_16_01                              	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_16_02                              	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_16_03                              	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_16_04                              	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_16_05                              	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_16_06                              	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_16_07                              	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_16_08                              	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_16_09                              	,	//  Size: 12, Type: Int32, Flags: 1
// 	PLAYER_VISIBLE_ITEM_16_10                              	,	//  Size: 12, Type: Int32, Flags: 1
// 	PLAYER_VISIBLE_ITEM_16_11                              	,	//  Size: 12, Type: Int32, Flags: 1
// 	PLAYER_VISIBLE_ITEM_16_PROPERTIES                      	,	//  Size: 1, Type: Chars?, Flags: 1
// 	PLAYER_VISIBLE_ITEM_16_PAD                             	,	//  Size: 1, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_17_CREATOR                         	,	//  Size: 2, Type: GUID, Flags: 1
	PLAYER_VISIBLE_ITEM_17_0                               	= PLAYER_VISIBLE_ITEM_17_CREATOR + 2,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_17_01                              	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_17_02                              	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_17_03                              	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_17_04                              	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_17_05                              	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_17_06                              	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_17_07                              	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_17_08                              	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_17_09                              	,	//  Size: 12, Type: Int32, Flags: 1
// 	PLAYER_VISIBLE_ITEM_17_10                              	,	//  Size: 12, Type: Int32, Flags: 1
// 	PLAYER_VISIBLE_ITEM_17_11                              	,	//  Size: 12, Type: Int32, Flags: 1
// 	PLAYER_VISIBLE_ITEM_17_PROPERTIES                      	,	//  Size: 1, Type: Chars?, Flags: 1
// 	PLAYER_VISIBLE_ITEM_17_PAD                             	,	//  Size: 1, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_18_CREATOR                         	,	//  Size: 2, Type: GUID, Flags: 1
	PLAYER_VISIBLE_ITEM_18_0                               	= PLAYER_VISIBLE_ITEM_18_CREATOR + 2,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_18_01                              	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_18_02                              	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_18_03                              	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_18_04                              	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_18_05                              	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_18_06                              	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_18_07                              	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_18_08                              	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_18_09                              	,	//  Size: 12, Type: Int32, Flags: 1
// 	PLAYER_VISIBLE_ITEM_18_10                              	,	//  Size: 12, Type: Int32, Flags: 1
// 	PLAYER_VISIBLE_ITEM_18_11                              	,	//  Size: 12, Type: Int32, Flags: 1
// 	PLAYER_VISIBLE_ITEM_18_PROPERTIES                      	,	//  Size: 1, Type: Chars?, Flags: 1
// 	PLAYER_VISIBLE_ITEM_18_PAD                             	,	//  Size: 1, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_19_CREATOR                         	,	//  Size: 2, Type: GUID, Flags: 1
	PLAYER_VISIBLE_ITEM_19_0                               	= PLAYER_VISIBLE_ITEM_19_CREATOR + 2,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_19_01                              	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_19_02                              	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_19_03                              	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_19_04                              	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_19_05                              	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_19_06                              	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_19_07                              	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_19_08                              	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_19_09                              	,	//  Size: 12, Type: Int32, Flags: 1
// 	PLAYER_VISIBLE_ITEM_19_10                              	,	//  Size: 12, Type: Int32, Flags: 1
// 	PLAYER_VISIBLE_ITEM_19_11                              	,	//  Size: 12, Type: Int32, Flags: 1
// 	PLAYER_VISIBLE_ITEM_19_PROPERTIES                      	,	//  Size: 1, Type: Chars?, Flags: 1
// 	PLAYER_VISIBLE_ITEM_19_PAD                             	,	//  Size: 1, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_20_CREATOR                         	,	//  Size: 2, Type: GUID, Flags: 1
	PLAYER_VISIBLE_ITEM_20_0                               	= PLAYER_VISIBLE_ITEM_20_CREATOR + 2,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_20_01                              	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_20_02                              	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_20_03                              	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_20_04                              	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_20_05                              	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_20_06                              	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_20_07                              	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_20_08                              	,	//  Size: 12, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_20_09                              	,	//  Size: 12, Type: Int32, Flags: 1
// 	PLAYER_VISIBLE_ITEM_20_10                              	,	//  Size: 12, Type: Int32, Flags: 1
// 	PLAYER_VISIBLE_ITEM_20_11                              	,	//  Size: 12, Type: Int32, Flags: 1
// 	PLAYER_VISIBLE_ITEM_20_PROPERTIES                      	,	//  Size: 1, Type: Chars?, Flags: 1
// 	PLAYER_VISIBLE_ITEM_20_PAD                             	,	//  Size: 1, Type: Int32, Flags: 1
	PLAYER_VISIBLE_ITEM_SHOW_SHIZHUANG,
	PLAYER_CHOSEN_TITLE                                    	,	//  Size: 1, Type: Int32, Flags: 1
	PLAYER_FIELD_PAD_0                                     	,	//  Size: 1, Type: Int32, Flags: 0
	PLAYER_FIELD_INV_SLOT_HEAD                             	,	//  Size: 46, Type: GUID, Flags: 2
	PLAYER_FIELD_PACK_SLOT_1                               	= PLAYER_FIELD_INV_SLOT_HEAD + 40,//UNIT_END + 0x1CE	//  Size: 32, Type: GUID, Flags: 2
	PLAYER_FIELD_BANK_SLOT_1                               	= PLAYER_FIELD_PACK_SLOT_1 + 60,//UNIT_END + 0x1EE	//  Size: 56, Type: GUID, Flags: 2
	PLAYER_FIELD_BANKBAG_SLOT_1                            	= PLAYER_FIELD_BANK_SLOT_1 + 56,//UNIT_END + 0x226	//  Size: 14, Type: GUID, Flags: 2
	PLAYER_FIELD_VENDORBUYBACK_SLOT_1                      	= PLAYER_FIELD_BANKBAG_SLOT_1 + 14,//UNIT_END + 0x234	//  Size: 24, Type: GUID, Flags: 2
	PLAYER_FIELD_KEYRING_SLOT_1                            	= PLAYER_FIELD_VENDORBUYBACK_SLOT_1 + 24,//UNIT_END + 0x24C	//  Size: 64, Type: GUID, Flags: 2
	PLAYER_FIELD_VANITYPET_SLOT_1                          	= PLAYER_FIELD_KEYRING_SLOT_1 + 64,//UNIT_END + 0x28C	//  Size: 36, Type: GUID, Flags: 2
	PLAYER_FARSIGHT                                        	= PLAYER_FIELD_VANITYPET_SLOT_1 + 36,//UNIT_END + 0x2B0	//  Size: 2, Type: GUID, Flags: 2
	PLAYER__FIELD_KNOWN_TITLES                             	= PLAYER_FARSIGHT + 2,//UNIT_END + 0x2B2	//  Size: 2, Type: GUID, Flags: 2
	PLAYER_XP                                              	= PLAYER__FIELD_KNOWN_TITLES + 2,//UNIT_END + 0x2B4	//  Size: 1, Type: Int32, Flags: 2
	PLAYER_NEXT_LEVEL_XP                                   	,	//  Size: 1, Type: Int32, Flags: 2
	/*
	PLAYER_SKILL_INFO_1_1                                  	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_01                                 	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_02                                 	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_03                                 	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_04                                 	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_05                                 	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_06                                 	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_07                                 	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_08                                 	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_09                                 	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_10                                 	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_11                                 	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_12                                 	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_13                                 	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_14                                 	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_15                                 	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_16                                 	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_17                                 	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_18                                 	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_19                                 	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_20                                 	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_21                                 	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_22                                 	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_23                                 	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_24                                 	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_25                                 	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_26                                 	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_27                                 	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_28                                 	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_29                                 	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_30                                 	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_31                                 	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_32                                 	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_33                                 	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_34                                 	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_35                                 	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_36                                 	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_37                                 	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_38                                 	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_39                                 	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_40                                 	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_41                                 	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_42                                 	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_43                                 	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_44                                 	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_45                                 	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_46                                 	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_47                                 	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_48                                 	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_49                                 	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_50                                 	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_51                                 	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_52                                 	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_53                                 	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_54                                 	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_55                                 	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_56                                 	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_57                                 	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_58                                 	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_59                                 	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_60                                 	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_61                                 	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_62                                 	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_63                                 	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_64                                 	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_65                                 	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_66                                 	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_67                                 	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_68                                 	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_69                                 	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_70                                 	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_71                                 	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_72                                 	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_73                                 	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_74                                 	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_75                                 	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_76                                 	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_77                                 	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_78                                 	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_79                                 	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_80                                 	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_81                                 	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_82                                 	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_83                                 	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_84                                 	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_85                                 	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_86                                 	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_87                                 	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_88                                 	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_89                                 	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_90                                 	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_91                                 	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_92                                 	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_93                                 	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_94                                 	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_95                                 	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_96                                 	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_97                                 	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_98                                 	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_99                                 	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_100                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_101                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_102                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_103                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_104                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_105                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_106                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_107                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_108                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_109                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_110                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_111                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_112                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_113                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_114                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_115                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_116                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_117                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_118                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_119                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_120                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_121                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_122                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_123                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_124                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_125                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_126                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_127                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_128                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_129                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_130                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_131                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_132                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_133                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_134                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_135                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_136                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_137                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_138                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_139                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_140                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_141                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_142                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_143                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_144                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_145                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_146                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_147                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_148                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_149                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_150                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_151                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_152                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_153                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_154                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_155                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_156                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_157                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_158                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_159                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_160                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_161                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_162                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_163                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_164                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_165                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_166                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_167                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_168                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_169                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_170                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_171                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_172                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_173                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_174                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_175                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_176                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_177                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_178                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_179                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_180                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_181                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_182                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_183                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_184                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_185                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_186                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_187                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_188                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_189                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_190                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_191                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_192                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_193                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_194                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_195                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_196                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_197                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_198                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_199                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_200                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_201                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_202                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_203                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_204                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_205                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_206                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_207                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_208                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_209                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_210                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_211                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_212                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_213                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_214                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_215                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_216                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_217                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_218                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_219                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_220                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_221                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_222                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_223                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_224                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_225                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_226                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_227                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_228                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_229                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_230                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_231                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_232                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_233                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_234                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_235                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_236                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_237                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_238                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_239                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_240                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_241                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_242                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_243                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_244                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_245                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_246                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_247                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_248                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_249                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_250                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_251                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_252                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_253                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_254                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_255                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_256                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_257                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_258                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_259                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_260                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_261                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_262                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_263                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_264                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_265                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_266                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_267                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_268                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_269                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_270                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_271                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_272                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_273                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_274                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_275                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_276                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_277                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_278                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_279                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_280                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_281                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_282                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_283                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_284                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_285                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_286                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_287                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_288                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_289                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_290                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_291                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_292                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_293                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_294                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_295                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_296                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_297                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_298                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_299                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_300                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_301                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_302                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_303                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_304                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_305                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_306                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_307                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_308                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_309                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_310                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_311                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_312                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_313                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_314                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_315                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_316                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_317                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_318                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_319                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_320                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_321                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_322                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_323                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_324                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_325                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_326                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_327                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_328                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_329                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_330                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_331                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_332                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_333                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_334                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_335                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_336                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_337                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_338                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_339                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_340                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_341                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_342                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_343                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_344                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_345                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_346                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_347                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_348                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_349                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_350                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_351                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_352                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_353                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_354                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_355                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_356                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_357                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_358                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_359                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_360                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_361                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_362                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_363                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_364                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_365                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_366                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_367                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_368                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_369                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_370                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_371                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_372                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_373                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_374                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_375                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_376                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_377                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_378                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_379                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_380                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_381                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_382                                	,	//  Size: 384, Type: Chars?, Flags: 2
	PLAYER_SKILL_INFO_1_383                                	,//UNIT_END + 0x435	//  Size: 384, Type: Chars?, Flags: 2
*/
	PLAYER_CHARACTER_POINTS1                               	,	//  Size: 1, Type: Int32, Flags: 2
	PLAYER_CHARACTER_POINTS2                               	,	//  Size: 1, Type: Int32, Flags: 2
	PLAYER_TRACK_CREATURES                                 	,	//  Size: 1, Type: Int32, Flags: 2
	PLAYER_TRACK_RESOURCES                                 	,	//  Size: 1, Type: Int32, Flags: 2
	PLAYER_BLOCK_PERCENTAGE                                	,	//  Size: 1, Type: Float, Flags: 2
	PLAYER_DODGE_PERCENTAGE                                	,	//  Size: 1, Type: Float, Flags: 2
	PLAYER_PARRY_PERCENTAGE                                	,	//  Size: 1, Type: Float, Flags: 2
	PLAYER_EXPERTISE                                       	,	//  Size: 1, Type: Int32, Flags: 2
	PLAYER_OFFHAND_EXPERTISE                               	,	//  Size: 1, Type: Int32, Flags: 2
	PLAYER_CRIT_PERCENTAGE                                 	,	//  Size: 1, Type: Float, Flags: 2
	PLAYER_RANGED_CRIT_PERCENTAGE                          	,	//  Size: 1, Type: Float, Flags: 2
	PLAYER_OFFHAND_CRIT_PERCENTAGE                         	,	//  Size: 1, Type: Float, Flags: 2
	PLAYER_SPELL_CRIT_PERCENTAGE1                          	,	//  Size: 7, Type: Float, Flags: 2
// 	PLAYER_SPELL_CRIT_PERCENTAGE01                         	,	//  Size: 7, Type: Float, Flags: 2
// 	PLAYER_SPELL_CRIT_PERCENTAGE02                         	,	//  Size: 7, Type: Float, Flags: 2
// 	PLAYER_SPELL_CRIT_PERCENTAGE03                         	,	//  Size: 7, Type: Float, Flags: 2
// 	PLAYER_SPELL_CRIT_PERCENTAGE04                         	,	//  Size: 7, Type: Float, Flags: 2
// 	PLAYER_SPELL_CRIT_PERCENTAGE05                         	,	//  Size: 7, Type: Float, Flags: 2
// 	PLAYER_SPELL_CRIT_PERCENTAGE06                         	,	//  Size: 7, Type: Float, Flags: 2
	PLAYER_SHIELD_BLOCK                                    	,	//  Size: 1, Type: Int32, Flags: 2
	PLAYER_EXPLORED_ZONES_1                                	,	//  Size: 64, Type: Bytes, Flags: 2
	//PLAYER_EXPLORED_ZONES_01                               	,	//  Size: 64, Type: Bytes, Flags: 2
	//PLAYER_EXPLORED_ZONES_02                               	,	//  Size: 64, Type: Bytes, Flags: 2
	//PLAYER_EXPLORED_ZONES_03                               	,	//  Size: 64, Type: Bytes, Flags: 2
	//PLAYER_EXPLORED_ZONES_04                               	,	//  Size: 64, Type: Bytes, Flags: 2
	//PLAYER_EXPLORED_ZONES_05                               	,	//  Size: 64, Type: Bytes, Flags: 2
	//PLAYER_EXPLORED_ZONES_06                               	,	//  Size: 64, Type: Bytes, Flags: 2
	//PLAYER_EXPLORED_ZONES_07                               	,	//  Size: 64, Type: Bytes, Flags: 2
	//PLAYER_EXPLORED_ZONES_08                               	,	//  Size: 64, Type: Bytes, Flags: 2
	//PLAYER_EXPLORED_ZONES_09                               	,	//  Size: 64, Type: Bytes, Flags: 2
	//PLAYER_EXPLORED_ZONES_10                               	,	//  Size: 64, Type: Bytes, Flags: 2
	//PLAYER_EXPLORED_ZONES_11                               	,	//  Size: 64, Type: Bytes, Flags: 2
	//PLAYER_EXPLORED_ZONES_12                               	,	//  Size: 64, Type: Bytes, Flags: 2
	//PLAYER_EXPLORED_ZONES_13                               	,	//  Size: 64, Type: Bytes, Flags: 2
	//PLAYER_EXPLORED_ZONES_14                               	,	//  Size: 64, Type: Bytes, Flags: 2
	//PLAYER_EXPLORED_ZONES_15                               	,	//  Size: 64, Type: Bytes, Flags: 2
	//PLAYER_EXPLORED_ZONES_16                               	,	//  Size: 64, Type: Bytes, Flags: 2
	//PLAYER_EXPLORED_ZONES_17                               	,	//  Size: 64, Type: Bytes, Flags: 2
	//PLAYER_EXPLORED_ZONES_18                               	,	//  Size: 64, Type: Bytes, Flags: 2
	//PLAYER_EXPLORED_ZONES_19                               	,	//  Size: 64, Type: Bytes, Flags: 2
	//PLAYER_EXPLORED_ZONES_20                               	,	//  Size: 64, Type: Bytes, Flags: 2
	//PLAYER_EXPLORED_ZONES_21                               	,	//  Size: 64, Type: Bytes, Flags: 2
	//PLAYER_EXPLORED_ZONES_22                               	,	//  Size: 64, Type: Bytes, Flags: 2
	//PLAYER_EXPLORED_ZONES_23                               	,	//  Size: 64, Type: Bytes, Flags: 2
	//PLAYER_EXPLORED_ZONES_24                               	,	//  Size: 64, Type: Bytes, Flags: 2
	//PLAYER_EXPLORED_ZONES_25                               	,	//  Size: 64, Type: Bytes, Flags: 2
	//PLAYER_EXPLORED_ZONES_26                               	,	//  Size: 64, Type: Bytes, Flags: 2
	//PLAYER_EXPLORED_ZONES_27                               	,	//  Size: 64, Type: Bytes, Flags: 2
	//PLAYER_EXPLORED_ZONES_28                               	,	//  Size: 64, Type: Bytes, Flags: 2
	//PLAYER_EXPLORED_ZONES_29                               	,	//  Size: 64, Type: Bytes, Flags: 2
	//PLAYER_EXPLORED_ZONES_30                               	,	//  Size: 64, Type: Bytes, Flags: 2
	//PLAYER_EXPLORED_ZONES_31                               	,	//  Size: 64, Type: Bytes, Flags: 2
	//PLAYER_EXPLORED_ZONES_32                               	,	//  Size: 64, Type: Bytes, Flags: 2
	//PLAYER_EXPLORED_ZONES_33                               	,	//  Size: 64, Type: Bytes, Flags: 2
	//PLAYER_EXPLORED_ZONES_34                               	,	//  Size: 64, Type: Bytes, Flags: 2
	//PLAYER_EXPLORED_ZONES_35                               	,	//  Size: 64, Type: Bytes, Flags: 2
	//PLAYER_EXPLORED_ZONES_36                               	,	//  Size: 64, Type: Bytes, Flags: 2
	//PLAYER_EXPLORED_ZONES_37                               	,	//  Size: 64, Type: Bytes, Flags: 2
	//PLAYER_EXPLORED_ZONES_38                               	,	//  Size: 64, Type: Bytes, Flags: 2
	//PLAYER_EXPLORED_ZONES_39                               	,	//  Size: 64, Type: Bytes, Flags: 2
	//PLAYER_EXPLORED_ZONES_40                               	,	//  Size: 64, Type: Bytes, Flags: 2
	//PLAYER_EXPLORED_ZONES_41                               	,	//  Size: 64, Type: Bytes, Flags: 2
	//PLAYER_EXPLORED_ZONES_42                               	,	//  Size: 64, Type: Bytes, Flags: 2
	//PLAYER_EXPLORED_ZONES_43                               	,	//  Size: 64, Type: Bytes, Flags: 2
	//PLAYER_EXPLORED_ZONES_44                               	,	//  Size: 64, Type: Bytes, Flags: 2
	//PLAYER_EXPLORED_ZONES_45                               	,	//  Size: 64, Type: Bytes, Flags: 2
	//PLAYER_EXPLORED_ZONES_46                               	,	//  Size: 64, Type: Bytes, Flags: 2
	//PLAYER_EXPLORED_ZONES_47                               	,	//  Size: 64, Type: Bytes, Flags: 2
	//PLAYER_EXPLORED_ZONES_48                               	,	//  Size: 64, Type: Bytes, Flags: 2
	//PLAYER_EXPLORED_ZONES_49                               	,	//  Size: 64, Type: Bytes, Flags: 2
	//PLAYER_EXPLORED_ZONES_50                               	,	//  Size: 64, Type: Bytes, Flags: 2
	//PLAYER_EXPLORED_ZONES_51                               	,	//  Size: 64, Type: Bytes, Flags: 2
	//PLAYER_EXPLORED_ZONES_52                               	,	//  Size: 64, Type: Bytes, Flags: 2
	//PLAYER_EXPLORED_ZONES_53                               	,	//  Size: 64, Type: Bytes, Flags: 2
	//PLAYER_EXPLORED_ZONES_54                               	,	//  Size: 64, Type: Bytes, Flags: 2
	//PLAYER_EXPLORED_ZONES_55                               	,	//  Size: 64, Type: Bytes, Flags: 2
	//PLAYER_EXPLORED_ZONES_56                               	,	//  Size: 64, Type: Bytes, Flags: 2
	//PLAYER_EXPLORED_ZONES_57                               	,	//  Size: 64, Type: Bytes, Flags: 2
	//PLAYER_EXPLORED_ZONES_58                               	,	//  Size: 64, Type: Bytes, Flags: 2
	//PLAYER_EXPLORED_ZONES_59                               	,	//  Size: 64, Type: Bytes, Flags: 2
	//PLAYER_EXPLORED_ZONES_60                               	,	//  Size: 64, Type: Bytes, Flags: 2
	//PLAYER_EXPLORED_ZONES_61                               	,	//  Size: 64, Type: Bytes, Flags: 2
	//PLAYER_EXPLORED_ZONES_62                               	,	//  Size: 64, Type: Bytes, Flags: 2
	//PLAYER_EXPLORED_ZONES_63                               	,	//  Size: 64, Type: Bytes, Flags: 2

	PLAYER_REST_STATE_EXPERIENCE                           	,	//  Size: 1, Type: Int32, Flags: 2
	PLAYER_FIELD_COINAGE                                   	,	//  Size: 1, Type: Int32, Flags: 2
	PLAYER_FIELD_MOD_DAMAGE_DONE_POS                       	,	//  Size: 7, Type: Int32, Flags: 2
 	PLAYER_FIELD_MOD_DAMAGE_DONE_POS_01                    	,	//  Size: 7, Type: Int32, Flags: 2
 	PLAYER_FIELD_MOD_DAMAGE_DONE_POS_02                    	,	//  Size: 7, Type: Int32, Flags: 2
 	PLAYER_FIELD_MOD_DAMAGE_DONE_POS_03                    	,	//  Size: 7, Type: Int32, Flags: 2
 	PLAYER_FIELD_MOD_DAMAGE_DONE_POS_04                    	,	//  Size: 7, Type: Int32, Flags: 2
 	PLAYER_FIELD_MOD_DAMAGE_DONE_POS_05                    	,	//  Size: 7, Type: Int32, Flags: 2
 	PLAYER_FIELD_MOD_DAMAGE_DONE_POS_06                    	,	//  Size: 7, Type: Int32, Flags: 2
	PLAYER_FIELD_MOD_DAMAGE_DONE_NEG                       	,	//  Size: 7, Type: Int32, Flags: 2
 	PLAYER_FIELD_MOD_DAMAGE_DONE_NEG_01                    	,	//  Size: 7, Type: Int32, Flags: 2
 	PLAYER_FIELD_MOD_DAMAGE_DONE_NEG_02                    	,	//  Size: 7, Type: Int32, Flags: 2
 	PLAYER_FIELD_MOD_DAMAGE_DONE_NEG_03                    	,	//  Size: 7, Type: Int32, Flags: 2
 	PLAYER_FIELD_MOD_DAMAGE_DONE_NEG_04                    	,	//  Size: 7, Type: Int32, Flags: 2
 	PLAYER_FIELD_MOD_DAMAGE_DONE_NEG_05                    	,	//  Size: 7, Type: Int32, Flags: 2
 	PLAYER_FIELD_MOD_DAMAGE_DONE_NEG_06                    	,	//  Size: 7, Type: Int32, Flags: 2
	PLAYER_FIELD_MOD_DAMAGE_DONE_PCT                       	,	//  Size: 7, Type: Int32, Flags: 2
 	PLAYER_FIELD_MOD_DAMAGE_DONE_PCT_01                    	,	//  Size: 7, Type: Int32, Flags: 2
 	PLAYER_FIELD_MOD_DAMAGE_DONE_PCT_02                    	,	//  Size: 7, Type: Int32, Flags: 2
 	PLAYER_FIELD_MOD_DAMAGE_DONE_PCT_03                    	,	//  Size: 7, Type: Int32, Flags: 2
 	PLAYER_FIELD_MOD_DAMAGE_DONE_PCT_04                    	,	//  Size: 7, Type: Int32, Flags: 2
 	PLAYER_FIELD_MOD_DAMAGE_DONE_PCT_05                    	,	//  Size: 7, Type: Int32, Flags: 2
 	PLAYER_FIELD_MOD_DAMAGE_DONE_PCT_06                    	,	//  Size: 7, Type: Int32, Flags: 2
	PLAYER_FIELD_MOD_HEALING_DONE_POS                      	,	//  Size: 1, Type: Int32, Flags: 2
	PLAYER_FIELD_MOD_TARGET_RESISTANCE                     	,	//  Size: 1, Type: Int32, Flags: 2
	PLAYER_FIELD_MOD_TARGET_PHYSICAL_RESISTANCE            	,	//  Size: 1, Type: Int32, Flags: 2
	PLAYER_FIELD_BYTES                                     	,	//  Size: 1, Type: Bytes, Flags: 2
	PLAYER_AMMO_ID                                         	,	//  Size: 1, Type: Int32, Flags: 2
	PLAYER_SELF_RES_SPELL                                  	,	//  Size: 1, Type: Int32, Flags: 2
	PLAYER_FIELD_PVP_MEDALS                                	,	//  Size: 1, Type: Int32, Flags: 2
	PLAYER_FIELD_BUYBACK_PRICE_1                           	,	//  Size: 12, Type: Int32, Flags: 2
	PLAYER_FIELD_BUYBACK_PRICE_01                          	,	//  Size: 12, Type: Int32, Flags: 2
	PLAYER_FIELD_BUYBACK_PRICE_02                          	,	//  Size: 12, Type: Int32, Flags: 2
	PLAYER_FIELD_BUYBACK_PRICE_03                          	,	//  Size: 12, Type: Int32, Flags: 2
	PLAYER_FIELD_BUYBACK_PRICE_04                          	,	//  Size: 12, Type: Int32, Flags: 2
	PLAYER_FIELD_BUYBACK_PRICE_05                          	,	//  Size: 12, Type: Int32, Flags: 2
	PLAYER_FIELD_BUYBACK_PRICE_06                          	,	//  Size: 12, Type: Int32, Flags: 2
	PLAYER_FIELD_BUYBACK_PRICE_07                          	,	//  Size: 12, Type: Int32, Flags: 2
	PLAYER_FIELD_BUYBACK_PRICE_08                          	,	//  Size: 12, Type: Int32, Flags: 2
	PLAYER_FIELD_BUYBACK_PRICE_09                          	,	//  Size: 12, Type: Int32, Flags: 2
	PLAYER_FIELD_BUYBACK_PRICE_10                          	,	//  Size: 12, Type: Int32, Flags: 2
	PLAYER_FIELD_BUYBACK_PRICE_11                          	,	//  Size: 12, Type: Int32, Flags: 2
	PLAYER_FIELD_BUYBACK_TIMESTAMP_1                       	,	//  Size: 12, Type: Int32, Flags: 2
	PLAYER_FIELD_BUYBACK_TIMESTAMP_01                      	,	//  Size: 12, Type: Int32, Flags: 2
	PLAYER_FIELD_BUYBACK_TIMESTAMP_02                      	,	//  Size: 12, Type: Int32, Flags: 2
	PLAYER_FIELD_BUYBACK_TIMESTAMP_03                      	,	//  Size: 12, Type: Int32, Flags: 2
	PLAYER_FIELD_BUYBACK_TIMESTAMP_04                      	,	//  Size: 12, Type: Int32, Flags: 2
	PLAYER_FIELD_BUYBACK_TIMESTAMP_05                      	,	//  Size: 12, Type: Int32, Flags: 2
	PLAYER_FIELD_BUYBACK_TIMESTAMP_06                      	,	//  Size: 12, Type: Int32, Flags: 2
	PLAYER_FIELD_BUYBACK_TIMESTAMP_07                      	,	//  Size: 12, Type: Int32, Flags: 2
	PLAYER_FIELD_BUYBACK_TIMESTAMP_08                      	,	//  Size: 12, Type: Int32, Flags: 2
	PLAYER_FIELD_BUYBACK_TIMESTAMP_09                      	,	//  Size: 12, Type: Int32, Flags: 2
	PLAYER_FIELD_BUYBACK_TIMESTAMP_10                      	,	//  Size: 12, Type: Int32, Flags: 2
	PLAYER_FIELD_BUYBACK_TIMESTAMP_11                      	,	//  Size: 12, Type: Int32, Flags: 2
	PLAYER_FIELD_KILLS                                     	,	//  Size: 1, Type: Chars?, Flags: 2
	PLAYER_FIELD_TODAY_CONTRIBUTION                        	,	//  Size: 1, Type: Int32, Flags: 2
	PLAYER_FIELD_YESTERDAY_CONTRIBUTION                    	,	//  Size: 1, Type: Int32, Flags: 2
	PLAYER_FIELD_LIFETIME_HONORBALE_KILLS                  	,	//  Size: 1, Type: Int32, Flags: 2
	PLAYER_FIELD_BYTES2                                    	,	//  Size: 1, Type: Bytes, Flags: 2
	PLAYER_FIELD_WATCHED_FACTION_INDEX                     	,	//  Size: 1, Type: Int32, Flags: 2
	PLAYER_FIELD_COMBAT_RATING_1                           	,	//  Size: 24, Type: Int32, Flags: 2
 	PLAYER_FIELD_COMBAT_RATING_2,
 	PLAYER_FIELD_COMBAT_RATING_3,
 	PLAYER_FIELD_COMBAT_RATING_4,
 	PLAYER_FIELD_COMBAT_RATING_5,
 	PLAYER_FIELD_COMBAT_RATING_6,
 	PLAYER_FIELD_COMBAT_RATING_7,
 	PLAYER_FIELD_COMBAT_RATING_8,
 	PLAYER_FIELD_COMBAT_RATING_9,
 	PLAYER_FIELD_COMBAT_RATING_10,
 	PLAYER_FIELD_COMBAT_RATING_11,
 	PLAYER_FIELD_COMBAT_RATING_12,
 	PLAYER_FIELD_COMBAT_RATING_13,
 	PLAYER_FIELD_COMBAT_RATING_14,
 	PLAYER_FIELD_COMBAT_RATING_15,
 	PLAYER_FIELD_COMBAT_RATING_16,
 	PLAYER_FIELD_COMBAT_RATING_17,
 	PLAYER_FIELD_COMBAT_RATING_18,
 	PLAYER_FIELD_COMBAT_RATING_19,
 	PLAYER_FIELD_COMBAT_RATING_20,
 	PLAYER_FIELD_COMBAT_RATING_21,
 	PLAYER_FIELD_COMBAT_RATING_22,
 	PLAYER_FIELD_COMBAT_RATING_23,
 	PLAYER_FIELD_COMBAT_RATING_24,
// 
	PLAYER_FIELD_KILL_COUNT,
	PLAYER_FIELD_BE_KILL_COUNT,
	PLAYER_FIELD_TOTAL_HONOR,
	PLAYER_FIELD_HONOR_CURRENCY                            	,	//  Size: 1, Type: Int32, Flags: 2
	PLAYER_FIELD_MOD_MANA_REGEN                            	,	//  Size: 1, Type: Float, Flags: 2
	PLAYER_FIELD_MOD_MANA_REGEN_INTERRUPT                  	,	//  Size: 1, Type: Float, Flags: 2
	PLAYER_FIELD_MAX_LEVEL                                 	,	//  Size: 1, Type: Int32, Flags: 2
//	PLAYER_FIELD_DAILY_QUESTS_1                            	,	//  Size: 25, Type: Int32, Flags: 2
//	PLAYER_FIELD_DAILY_QUESTS_01                           	,	//  Size: 25, Type: Int32, Flags: 2
//	PLAYER_FIELD_DAILY_QUESTS_02                           	,	//  Size: 25, Type: Int32, Flags: 2
//	PLAYER_FIELD_DAILY_QUESTS_03                           	,	//  Size: 25, Type: Int32, Flags: 2
//	PLAYER_FIELD_DAILY_QUESTS_04                           	,	//  Size: 25, Type: Int32, Flags: 2
//	PLAYER_FIELD_DAILY_QUESTS_05                           	,	//  Size: 25, Type: Int32, Flags: 2
//	PLAYER_FIELD_DAILY_QUESTS_06                           	,	//  Size: 25, Type: Int32, Flags: 2
//	PLAYER_FIELD_DAILY_QUESTS_07                           	,	//  Size: 25, Type: Int32, Flags: 2
//	PLAYER_FIELD_DAILY_QUESTS_08                           	,	//  Size: 25, Type: Int32, Flags: 2
//	PLAYER_FIELD_DAILY_QUESTS_09                           	,	//  Size: 25, Type: Int32, Flags: 2
//	PLAYER_FIELD_DAILY_QUESTS_10                           	,	//  Size: 25, Type: Int32, Flags: 2
//	PLAYER_FIELD_DAILY_QUESTS_11                           	,	//  Size: 25, Type: Int32, Flags: 2
//	PLAYER_FIELD_DAILY_QUESTS_12                           	,	//  Size: 25, Type: Int32, Flags: 2
//	PLAYER_FIELD_DAILY_QUESTS_13                           	,	//  Size: 25, Type: Int32, Flags: 2
//	PLAYER_FIELD_DAILY_QUESTS_14                           	,	//  Size: 25, Type: Int32, Flags: 2
//	PLAYER_FIELD_DAILY_QUESTS_15                           	,	//  Size: 25, Type: Int32, Flags: 2
//	PLAYER_FIELD_DAILY_QUESTS_16                           	,	//  Size: 25, Type: Int32, Flags: 2
//	PLAYER_FIELD_DAILY_QUESTS_17                           	,	//  Size: 25, Type: Int32, Flags: 2
//	PLAYER_FIELD_DAILY_QUESTS_18                           	,	//  Size: 25, Type: Int32, Flags: 2
//	PLAYER_FIELD_DAILY_QUESTS_19                           	,	//  Size: 25, Type: Int32, Flags: 2
//	PLAYER_FIELD_DAILY_QUESTS_20                           	,	//  Size: 25, Type: Int32, Flags: 2
//	PLAYER_FIELD_DAILY_QUESTS_21                           	,	//  Size: 25, Type: Int32, Flags: 2
//	PLAYER_FIELD_DAILY_QUESTS_22                           	,	//  Size: 25, Type: Int32, Flags: 2
//	PLAYER_FIELD_DAILY_QUESTS_23                           	,	//  Size: 25, Type: Int32, Flags: 2
//	PLAYER_FIELD_DAILY_QUESTS_24                           	,	//  Size: 25, Type: Int32, Flags: 2
	PLAYER_HEAD,
	PLAYER_HEAD1,
	PLAYER_FOOT,
	PLAYER_FOOT1,
	PLAYER_XP_TRIGGER,
	PLAYER_FIELD_YUANBAO,
	PLAYER_FIELD_SHAPE_MOUNT_FLAG,
	PLAYER_FIELD_FFA,
	PLAYER_FIELD_HOSTILE_GUILDID,

	PLAYER_FIELD_JINGLIAN_COST,

	PLAYER_FIELD_JINGLIAN_SLOT_ITEM,
	PLAYER_FIELD_JINGLIAN_SLOT_ITEM_,

	PLAYER_FIELD_JINGLIAN_SLOT_MAINGEM,
	PLAYER_FIELD_JINGLIAN_SLOT_MAINGEM_,


	PLAYER_FIELD_JINGLIAN_SLOT_GEM1,
	PLAYER_FIELD_JINGLIAN_SLOT_GEM1_,

	PLAYER_FIELD_JINGLIAN_SLOT_GEM2,
	PLAYER_FIELD_JINGLIAN_SLOT_GEM2_,

	PLAYER_FIELD_JINGLIAN_SLOT_GEM3,
	PLAYER_FIELD_JINGLIAN_SLOT_GEM3_,

	PLAYER_FIELD_JINGLIAN_SLOT_GEM4,
	PLAYER_FIELD_JINGLIAN_SLOT_GEM4_,

	PLAYER_FIELD_XIANGQIAN_COST,

	PLAYER_FIELD_XIANGQIAN_SLOT_MAIN_ITEM,
	PLAYER_FIELD_XIANGQIAN_SLOT_MAIN_ITEM_,

	PLAYER_FIELD_XIANGQIAN_SLOT_MATERIAL1,
	PLAYER_FIELD_XIANGQIAN_SLOT_MATERIAL1_,

	PLAYER_FIELD_XIANGQIAN_SLOT_MATERIAL2,
	PLAYER_FIELD_XIANGQIAN_SLOT_MATERIAL2_,

	PLAYER_FIELD_XIANGQIAN_SLOT_MATERIAL3,
	PLAYER_FIELD_XIANGQIAN_SLOT_MATERIAL3_,

	PLAYER_FIELD_XIANGQIAN_SLOT_MATERIAL4,
	PLAYER_FIELD_XIANGQIAN_SLOT_MATERIAL4_,

	PLAYER_FIELD_XIANGQIAN_SLOT_MAINMATERIAL,
	PLAYER_FIELD_XIANGQIAN_SLOT_MAINMATERIAL_,

	PLAYER_FIELD_TEACHER,
	PLAYER_FIELD_STUDENT,
	PLAYER_FIELD_ENCHANT_TEACHER_CHARGES,

	PLAYER_FIELD_GUILD_SCORE,

	PLAYER_FIELD_SHENGXIAO,

//	PLAYER_FIELD_GUILD_EMBLEM_STYLE,
//	PLAYER_FIELD_GUILD_EMBLEM_COLOR,

	PLAYER_FIELD_ARENA_1V1_WIN,
	PLAYER_FIELD_ARENA_2V2_WIN,
	PLAYER_FIELD_ARENA_3V3_WIN,
	PLAYER_FIELD_ARENA_4V4_WIN,
	PLAYER_FIELD_ARENA_5V5_WIN,

	PLAYER_FIELD_ARENA_1V1_LOSE,
	PLAYER_FIELD_ARENA_2V2_LOSE,
	PLAYER_FIELD_ARENA_3V3_LOSE,
	PLAYER_FIELD_ARENA_4V4_LOSE,
	PLAYER_FIELD_ARENA_5V5_LOSE,

	PLAYER_FIELD_ARENA_LV80_1V1_WIN,
	PLAYER_FIELD_ARENA_LV80_2V2_WIN,
	PLAYER_FIELD_ARENA_LV80_3V3_WIN,
	PLAYER_FIELD_ARENA_LV80_4V4_WIN,
	PLAYER_FIELD_ARENA_LV80_5V5_WIN,

	PLAYER_FIELD_ARENA_LV80_1V1_LOSE,
	PLAYER_FIELD_ARENA_LV80_2V2_LOSE,
	PLAYER_FIELD_ARENA_LV80_3V3_LOSE,
	PLAYER_FIELD_ARENA_LV80_4V4_LOSE,
	PLAYER_FIELD_ARENA_LV80_5V5_LOSE,

	PLAYER_FIELD_IS_FLYING,

	PLAYER_FIELD_INSTANCE_BUSY,

	PLAYER_FIELD_CREDIT_AVAILABLE,				// 可用额度
	PLAYER_FIELD_LINE_OF_CREDIT,				// 最大额度
	PLAYER_FIELD_CREDIT_RESTORE,				// 本期还款额
	PLAYER_FIELD_CREDIT_APPLY_DATE,				// 申请日期(UNIXTIME)
	PLAYER_FIELD_CREDIT_BILL_DATE,				// 账单日期(UNIXTIME)
	PLAYER_FIELD_CREDIT_RESTORE_MATURITY,		// 到期还款日(UNIXTIME)
	PLAYER_FIELD_CREDIT_BANNED,					// 信用卡被封停的日期(UNIXTIME) 如果是0则未被封停
	
	PLAYER_END                                              ,   //  UNIT_END + 0x50E


	//OBJECT:
	OBJECT_FIELD_CREATED_BY                                	= OBJECT_END,	//  Size: 2, Type: GUID, Flags: 1
	//GAMEOBJECT:
	GAMEOBJECT_DISPLAYID                                   	= OBJECT_FIELD_CREATED_BY + 0x002,	//  Size: 1, Type: Int32, Flags: 1
	GAMEOBJECT_FLAGS                                       	,	//  Size: 1, Type: Int32, Flags: 1
	GAMEOBJECT_ROTATION                                    	,	//  Size: 4, Type: Float, Flags: 1
	GAMEOBJECT_ROTATION_01                                 	,	//  Size: 4, Type: Float, Flags: 1
	GAMEOBJECT_ROTATION_02                                 	,	//  Size: 4, Type: Float, Flags: 1
	GAMEOBJECT_ROTATION_03                                 	,	//  Size: 4, Type: Float, Flags: 1
	GAMEOBJECT_STATE                                       	,	//  Size: 1, Type: Int32, Flags: 1
	GAMEOBJECT_POS_X                                       	,	//  Size: 1, Type: Float, Flags: 1
	GAMEOBJECT_POS_Y                                       	,	//  Size: 1, Type: Float, Flags: 1
	GAMEOBJECT_POS_Z                                       	,	//  Size: 1, Type: Float, Flags: 1
	GAMEOBJECT_FACING                                      	,	//  Size: 1, Type: Float, Flags: 1
	GAMEOBJECT_DYN_FLAGS                                   	,	//  Size: 1, Type: Int32, Flags: 256
	GAMEOBJECT_FACTION                                     	,	//  Size: 1, Type: Int32, Flags: 1
	GAMEOBJECT_TYPE_ID                                     	,	//  Size: 1, Type: Int32, Flags: 1
	GAMEOBJECT_LEVEL                                       	,	//  Size: 1, Type: Int32, Flags: 1
	GAMEOBJECT_ARTKIT                                      	,	//  Size: 1, Type: Int32, Flags: 1
	GAMEOBJECT_ANIMPROGRESS                                	,	//  Size: 1, Type: Int32, Flags: 256
	GAMEOBJECT_PADDING                                     	,	//  Size: 1, Type: Int32, Flags: 0
	GAMEOBJECT_END                                          ,


	//DYNAMICOBJECT:
	DYNAMICOBJECT_CASTER                                   	= OBJECT_END,	//  Size: 2, Type: GUID, Flags: 1
	DYNAMICOBJECT_BYTES                                    	= DYNAMICOBJECT_CASTER + 0x002,	//  Size: 1, Type: Bytes, Flags: 1
	DYNAMICOBJECT_SPELLID                                  	,	//  Size: 1, Type: Int32, Flags: 1
	DYNAMICOBJECT_RADIUS                                   	,	//  Size: 1, Type: Float, Flags: 1
	DYNAMICOBJECT_POS_X                                    	,	//  Size: 1, Type: Float, Flags: 1
	DYNAMICOBJECT_POS_Y                                    	,	//  Size: 1, Type: Float, Flags: 1
	DYNAMICOBJECT_POS_Z                                    	,	//  Size: 1, Type: Float, Flags: 1
	DYNAMICOBJECT_FACING                                   	,	//  Size: 1, Type: Float, Flags: 1
	DYNAMICOBJECT_CASTTIME                                 	,	//  Size: 1, Type: Int32, Flags: 1
	DYNAMICOBJECT_END                                       ,

	//CORPSE:
	CORPSE_FIELD_OWNER                                     	= OBJECT_END,	//  Size: 2, Type: GUID, Flags: 1
	CORPSE_FIELD_FACING                                    	= CORPSE_FIELD_OWNER + 0x002,	//  Size: 1, Type: Float, Flags: 1
	CORPSE_FIELD_POS_X                                     	,	//  Size: 1, Type: Float, Flags: 1
	CORPSE_FIELD_POS_Y                                     	,	//  Size: 1, Type: Float, Flags: 1
	CORPSE_FIELD_POS_Z                                     	,	//  Size: 1, Type: Float, Flags: 1
	CORPSE_FIELD_DISPLAY_ID                                	,	//  Size: 1, Type: Int32, Flags: 1
	CORPSE_FIELD_ITEM                                      	,	//  Size: 19, Type: Int32, Flags: 1
	CORPSE_FIELD_ITEM_01                                   	,	//  Size: 19, Type: Int32, Flags: 1
	CORPSE_FIELD_ITEM_02                                   	,	//  Size: 19, Type: Int32, Flags: 1
	CORPSE_FIELD_ITEM_03                                   	,	//  Size: 19, Type: Int32, Flags: 1
	CORPSE_FIELD_ITEM_04                                   	,	//  Size: 19, Type: Int32, Flags: 1
	CORPSE_FIELD_ITEM_05                                   	,	//  Size: 19, Type: Int32, Flags: 1
	CORPSE_FIELD_ITEM_06                                   	,	//  Size: 19, Type: Int32, Flags: 1
	CORPSE_FIELD_ITEM_07                                   	,	//  Size: 19, Type: Int32, Flags: 1
	CORPSE_FIELD_ITEM_08                                   	,	//  Size: 19, Type: Int32, Flags: 1
	CORPSE_FIELD_ITEM_09                                   	,	//  Size: 19, Type: Int32, Flags: 1
	CORPSE_FIELD_ITEM_10                                   	,	//  Size: 19, Type: Int32, Flags: 1
	CORPSE_FIELD_ITEM_11                                   	,	//  Size: 19, Type: Int32, Flags: 1
	CORPSE_FIELD_ITEM_12                                   	,	//  Size: 19, Type: Int32, Flags: 1
	CORPSE_FIELD_ITEM_13                                   	,	//  Size: 19, Type: Int32, Flags: 1
	CORPSE_FIELD_ITEM_14                                   	,	//  Size: 19, Type: Int32, Flags: 1
	CORPSE_FIELD_ITEM_15                                   	,	//  Size: 19, Type: Int32, Flags: 1
	CORPSE_FIELD_ITEM_16                                   	,	//  Size: 19, Type: Int32, Flags: 1
	CORPSE_FIELD_ITEM_17                                   	,	//  Size: 19, Type: Int32, Flags: 1
	CORPSE_FIELD_ITEM_18                                   	,	//  Size: 19, Type: Int32, Flags: 1
	CORPSE_FIELD_BYTES_1                                   	,	//  Size: 1, Type: Bytes, Flags: 1
	CORPSE_FIELD_BYTES_2                                   	,	//  Size: 1, Type: Bytes, Flags: 1
	CORPSE_FIELD_GUILD                                     	,	//  Size: 1, Type: Int32, Flags: 1
	CORPSE_FIELD_FLAGS                                     	,	//  Size: 1, Type: Int32, Flags: 1
	CORPSE_FIELD_DYNAMIC_FLAGS                             	,	//  Size: 1, Type: Int32, Flags: 256
	CORPSE_END                                              ,
};



// custom                                               // client names:
#define PLAYER_FIELD_ALL_WEAPONS_SKILL_RATING      PLAYER_FIELD_COMBAT_RATING_1
#define PLAYER_FIELD_DEFENCE_RATING                PLAYER_FIELD_COMBAT_RATING_1+1
#define PLAYER_FIELD_DODGE_RATING                  PLAYER_FIELD_COMBAT_RATING_1+2
#define PLAYER_FIELD_PARRY_RATING                  PLAYER_FIELD_COMBAT_RATING_1+3
#define PLAYER_FIELD_BLOCK_RATING                  PLAYER_FIELD_COMBAT_RATING_1+4
#define PLAYER_FIELD_MELEE_HIT_RATING              PLAYER_FIELD_COMBAT_RATING_1+5
#define PLAYER_FIELD_RANGED_HIT_RATING             PLAYER_FIELD_COMBAT_RATING_1+6
#define PLAYER_FIELD_SPELL_HIT_RATING              PLAYER_FIELD_COMBAT_RATING_1+7
#define PLAYER_FIELD_MELEE_CRIT_RATING             PLAYER_FIELD_COMBAT_RATING_1+8
#define PLAYER_FIELD_RANGED_CRIT_RATING            PLAYER_FIELD_COMBAT_RATING_1+9
#define PLAYER_FIELD_SPELL_CRIT_RATING             PLAYER_FIELD_COMBAT_RATING_1+10
#define PLAYER_FIELD_HIT_TAKEN_MELEE_RATING        PLAYER_FIELD_COMBAT_RATING_1+11
#define PLAYER_FIELD_HIT_TAKEN_RANGED_RATING       PLAYER_FIELD_COMBAT_RATING_1+12
#define PLAYER_FIELD_HIT_TAKEN_SPELL_RATING        PLAYER_FIELD_COMBAT_RATING_1+13
#define PLAYER_FIELD_CRIT_TAKEN_MELEE_RATING       PLAYER_FIELD_COMBAT_RATING_1+14
#define PLAYER_FIELD_CRIT_TAKEN_RANGED_RATING      PLAYER_FIELD_COMBAT_RATING_1+15
#define PLAYER_FIELD_CRIT_TAKEN_SPELL_RATING       PLAYER_FIELD_COMBAT_RATING_1+16
#define PLAYER_FIELD_MELEE_HASTE_RATING            PLAYER_FIELD_COMBAT_RATING_1+17
#define PLAYER_FIELD_RANGED_HASTE_RATING           PLAYER_FIELD_COMBAT_RATING_1+18
#define PLAYER_FIELD_SPELL_HASTE_RATING            PLAYER_FIELD_COMBAT_RATING_1+19
#define PLAYER_FIELD_MELEE_WEAPON_SKILL_RATING     PLAYER_FIELD_COMBAT_RATING_1+20
#define PLAYER_FIELD_OFFHAND_WEAPON_SKILL_RATING   PLAYER_FIELD_COMBAT_RATING_1+21
#define PLAYER_FIELD_RANGED_WEAPON_SKILL_RATING    PLAYER_FIELD_COMBAT_RATING_1+22
#define PLAYER_FIELD_EXPERTISE_RATING              PLAYER_FIELD_COMBAT_RATING_1+23






enum UnitFieldFlags // UNIT_FIELD_FLAGS #46 - these are client flags
{	//                                            Hex    Bit     Decimal  Comments
	UNIT_FLAG_ARMED		                 = 0x00000001, // 1            1
	UNIT_FLAG_NOT_ATTACKABLE_2           = 0x00000002, // 2            2  client won't let you attack them
	UNIT_FLAG_LOCK_PLAYER                = 0x00000004, // 3            4  ? does nothing to client (probably wrong) - only taxi code checks this
	UNIT_FLAG_PLAYER_CONTROLLED          = 0x00000008, // 4            8  makes players and NPCs attackable / not attackable
	UNIT_FLAG_ROOT		                 = 0x00000010, // 5           16  定住
	UNIT_FLAG_FROZEN                     = 0x00000020, // 6           32  冰冻
	UNIT_FLAG_PLUS_MOB                   = 0x00000040, // 7           64  ? some NPCs have this (Rare/Elite/Boss?)
	UNIT_FLAG_SLEEP	                     = 0x00000080, // 8          128  睡眠
	UNIT_FLAG_NOT_ATTACKABLE_9           = 0x00000100, // 9          256  changes attackable status
	UNIT_FLAG_UNKNOWN_10                 = 0x00000200, // 10         512  ? some NPCs have this
	UNIT_FLAG_LOOTING                    = 0x00000400, // 11        1024
	UNIT_FLAG_SELF_RES                   = 0x00000800, // 12        2048  ? some NPCs have this
	UNIT_FLAG_PVP                        = 0x00001000, // 13        4096  sets PvP flag
	UNIT_FLAG_SILENCED                   = 0x00002000, // 14        8192  沉默
	UNIT_FLAG_DEAD                       = 0x00004000, // 15       16384  used for special "dead" NPCs like Withered Corpses
	UNIT_FLAG_UNKNOWN_16                 = 0x00008000, // 16       32768  ? some NPCs have this
	UNIT_FLAG_ALIVE                      = 0x00010000, // 17       65536  ?
	UNIT_FLAG_PACIFIED                   = 0x00020000, // 18      131072
	UNIT_FLAG_STUNNED                    = 0x00040000, // 19      262144  眩晕
	UNIT_FLAG_COMBAT                     = 0x00080000, // 20      524288  sets combat flag
	UNIT_FLAG_MOUNTED_TAXI               = 0x00100000, // 21     1048576  mounted on a taxi
	UNIT_FLAG_DISARMED                   = 0x00200000, // 22     2097152
	UNIT_FLAG_CONFUSED                   = 0x00400000, // 23     4194304  魅惑
	UNIT_FLAG_FLEEING                    = 0x00800000, // 24     8388608  fear恐惧
	UNIT_FLAG_PLAYER_CONTROLLED_CREATURE = 0x01000000, // 25    16777216
	UNIT_FLAG_NOT_SELECTABLE             = 0x02000000, // 26    33554432  cannot select the unit
	UNIT_FLAG_SKINNABLE                  = 0x04000000, // 27    67108864
	UNIT_FLAG_STORM		                 = 0x08000000, // 28   134217728  ? was MAKE_CHAR_UNTOUCHABLE (probably wrong), nothing ever set it
	UNIT_FLAG_UNKNOWN_29                 = 0x10000000, // 29   268435456
	UNIT_FLAG_FEIGN_DEATH                = 0x20000000, // 30   536870912
	UNIT_FLAG_UNKNOWN_31                 = 0x40000000, // 31  1073741824  ? was WEAPON_OFF and being used for disarm
	UNIT_FLAG_UNKNOWN_32                 = 0x80000000, // 32  2147483648
};


enum HIGHGUID_TYPE
{
	HIGHGUID_TYPE_UNIT				= 0xF1300000,
	HIGHGUID_TYPE_PET				= 0xF1400000,
	HIGHGUID_TYPE_GAMEOBJECT		= 0xF1100000,
	HIGHGUID_TYPE_ITEM				= 0x40000000,
	HIGHGUID_TYPE_CONTAINER			= 0x50000000,			// confirm this pl0x
	HIGHGUID_TYPE_PLAYER			= 0x00000000,
	HIGHGUID_TYPE_DYNAMICOBJECT		= 0x60000000,
	HIGHGUID_TYPE_TRANSPORTER		= 0x1FC00000,
	HIGHGUID_TYPE_WAYPOINT			= 0x10000000,
	HIGHGUID_TYPE_CORPSE			= 0x30000000,
	//===============================================
	HIGHGUID_TYPE_MASK				= 0xFFF00000,
	LOWGUID_ENTRY_MASK				= 0x00FFFFFF,
};
#define GUID_HIPART(x) (*(((uint32*)&(x))+1))
#define GUID_LOPART(x) (*((uint32*)&(x)))

#define GET_TYPE_FROM_GUID(x) (GUID_HIPART((x)) & HIGHGUID_TYPE_MASK)
#define GET_LOWGUID_PART(x) (GUID_LOPART((x)) & LOWGUID_ENTRY_MASK)

// TODO: fix that type mess

enum TYPE {
	TYPE_OBJECT		 = 1,
	TYPE_ITEM		   = 2,
	TYPE_CONTAINER	  = 4,
	TYPE_UNIT		   = 8,
	TYPE_PLAYER		 = 16,
	TYPE_GAMEOBJECT	 = 32,
	TYPE_DYNAMICOBJECT  = 64,
	TYPE_CORPSE		 = 128,
	TYPE_AIGROUP		= 256,
	TYPE_AREATRIGGER	= 512,
};

enum TYPEID {
	TYPEID_OBJECT		= 0,
	TYPEID_ITEM		  = 1,
	TYPEID_CONTAINER	 = 2,
	TYPEID_UNIT		  = 3,
	TYPEID_PLAYER		= 4,
	TYPEID_GAMEOBJECT	= 5,
	TYPEID_DYNAMICOBJECT = 6,
	TYPEID_CORPSE		= 7,
	TYPEID_AIGROUP	   = 8,
	TYPEID_AREATRIGGER   = 9,
	TYPEID_UNUSED			= 10,//used to signal invalid reference (object dealocated but someone is still using it)
};

enum OBJECT_UPDATE_TYPE {
	UPDATETYPE_VALUES = 0,
	//  8 bytes - GUID
	//  Goto Update Block
	UPDATETYPE_MOVEMENT = 1,
	//  8 bytes - GUID
	//  Goto Position Update
	UPDATETYPE_CREATE_OBJECT = 2,
	//  8 bytes - GUID
	//  1 byte - Object Type (*)
	//  Goto Position Update
	//  Goto Update Block
	UPDATETYPE_CREATE_YOURSELF = 3, // looks like 3 & 4 do the same thing
	//  4 bytes - Count
	//  Loop Count Times:
	//  8 bytes - GUID
	UPDATETYPE_OUT_OF_RANGE_OBJECTS = 4, // <- this is correct, not sure about 3
	//  4 bytes - Count
	//  Loop Count Times:
	//  8 bytes - GUID
	UPDATETYPE_NEAR_OBJECTS         = 5

};

enum TUTORIAL_FLAG
{
	TUTORIAL_FLAG_HOW_TO_MOVE,			//1.如何移动
	TUTORIAL_FLAG_HOW_TO_SCROLL,		//2.如何转动视角
	TUTORIAL_FLAG_QA1,					//3.操作考试题
	TUTORIAL_FLAG_QA2,					//4.操作考试题
	TUTORIAL_FLAG_QA3,					//5.操作考试题
	TUTORIAL_FLAG_HOW_TO_OPENBAG,		//6.如何打开背包
	TUTORIAL_FLAG_HOW_TO_EQUIP,			//7.如何装备物品
	TUTORIAL_FLAG_QUEST_TIP,			//8.	初始任务提示
	TUTORIAL_FLAG_QUEST_LOG,			//9.	如何打开任务栏
	TUTORIAL_FLAG_QUEST_QA1,			//10.	任务考试
	TUTORIAL_FLAG_QUEST_QA2,			//11.	任务考试
	TUTORIAL_FLAG_HOW_TO_BUY,			//12.如何购买物品
	TUTORIAL_FLAG_HOW_TO_LEARN_SPELL,	//13.如何学习技能
	TUTORIAL_FLAG_HOW_TO_USE_SPELL,		//14.如何使用技能 
	TUTORIAL_FLAG_HOW_TO_FIGHT,			//15.如何战斗 
	TUTORIAL_FLAG_HOW_TO_PICK,			//16.如何拾取物品 
	TUTORIAL_FLAG_HOW_TO_USE_MEDICAL,	//17.如何使用药品
	TUTORIAL_FLAG_HOW_TO_CHAT,			//18.如何聊天
	TUTORIAL_FLAG_HOW_TO_HELP,			//19.如何使用帮助系统。
	TUTORIAL_FLAG_HOW_TO_ENTER_INSTANCE,//20.如何进入副本。
	TUTORIAL_FLAG_HOW_TO_RIDE,			//21.如何使用骑乘
	TUTORIAL_FLAG_HOW_TO_SHAPESHIFT,	//22.如何使用变身
	TUTORIAL_FLAG_HOW_TO_HOME,			//23.如何进入家园
	TUTORIAL_FLAG_MONTER_CLOTH,			//24.如何获得狩猎装
	TUTORIAL_FLAG_GUILD,				//25.部族的加入与建立
	TUTORIAL_FLAG_MAILBOX,				//26.如何使用邮箱
	TUTORIAL_FLAG_BANK,					//27.如何使用银行
	TUTORIAL_FLAG_AUCTION,				//28.如何使用拍卖	
	TUTORIAL_FLAG_START_ANIMATION,		//29.开场动画
};

inline void SetTurorialFlag(uint8* flag, uint32 index)
{
	uint32 i = index/8;
	uint32 n = index%8;

	flag[i] |= 1<<n;
}

inline bool GetTurorialFlag(uint8* flag, uint32 index)
{
	uint32 i = index/8;
	uint32 n = index%8;

	return flag[i] & 1<<n;
}

#endif		// __UPDATEFIELDS_H
