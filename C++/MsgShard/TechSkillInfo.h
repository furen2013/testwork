#pragma once
#ifndef TECHSKILLINFO_H
#define TECHSKILLINFO_H
enum effectType
{
	effectType_ModifyPetDamage, //add base and max
	effectType_OpenPetWeapon,
	effectType_ModifyPetWeaponSplitDamage,
	effectType_ModifyPetWopeanDotDamage, // 棒类
	effectType_ModifyPetWopeanPenetrateDamage,//钉类
	effectType_ModifyPetAllWopeanDamageToBarrier,
	effectType_ModifyPetArmor, //更换所有防御到某一ID
	effectType_ModifyPetEquipArmor,//更改防具防御防御值
	effectType_OpenPetWeaponPropertyDamage, //开启武器附加攻击
	effectType_ModifyFarmHarvest, //增加农场产量
	effectType_OpenFarmWaterWayTech,//水道开启
	effectType_ModifyFarmWaterWayEffect, //修改水道效果
	effectType_OpenFarmMillTech,	//开启磨坊
	effectType_ModifyFarmMillEffect,
	effectType_ModifyFarmWaterRecovery,
	effectType_ModifyFarmWaterWayPrice,
	effectType_ModifyFarmMillPrice,
	effectType_Max
};

struct TechSkillInfo
{
	int id;
	int effect;
	int parameter;
	int parameter1;
};
#endif