#include "stdafx.h"
#include "TechSkill.h"

pSkillEffect handle[effectType_Max] ={
	&TechSkill::ModifyPetDamage, //add base and max
	&TechSkill::OpenPetWeapon,
	&TechSkill::ModifyPetWeaponSplitDamage,
	&TechSkill::ModifyPetWopeanDotDamage, // 棒类
	&TechSkill::ModifyPetWopeanPenetrateDamage,//钉类
	&TechSkill::ModifyPetAllWopeanDamageToBarrier,
	&TechSkill::ModifyPetArmor,//更换所有防御到某一ID
	&TechSkill::ModifyPetEquipArmor,//更改防具防御防御值
	&TechSkill::OpenPetWeaponPropertyDamage,//开启武器附加攻击
	&TechSkill::ModifyFarmHarvest,//增加农场产量
	&TechSkill::OpenFarmWaterWayTech,//水道开启
	&TechSkill::ModifyFarmWaterWayEffect,//修改水道效果
	&TechSkill::OpenFarmMillTech,//开启磨坊
	&TechSkill::ModifyFarmMillEffect,
	&TechSkill::ModifyFarmWaterRecovery,
	&TechSkill::ModifyFarmWaterWayPrice,
	&TechSkill::ModifyFarmMillPrice

};
TechSkill::TechSkill()
{

}
TechSkill::~TechSkill()
{

}


void TechSkill::ModifyPetDamage() //add base and max
{

}
void TechSkill::OpenPetWeapon()
{

}
void TechSkill::ModifyPetWeaponSplitDamage()
{

}
void TechSkill::ModifyPetWopeanDotDamage( )// 棒类
{

}
void TechSkill::ModifyPetWopeanPenetrateDamage()//钉类
{

}
void TechSkill::ModifyPetAllWopeanDamageToBarrier()
{

}
void TechSkill::ModifyPetArmor() //更换所有防御到某一ID
{

}
void TechSkill::ModifyPetEquipArmor()//更改防具防御防御值
{

}
void TechSkill::OpenPetWeaponPropertyDamage() //开启武器附加攻击
{

}
void TechSkill::ModifyFarmHarvest()//增加农场产量
{

}
void TechSkill::OpenFarmWaterWayTech()//水道开启
{

}
void TechSkill::ModifyFarmWaterWayEffect() //修改水道效果
{

}
void TechSkill::OpenFarmMillTech()	//开启磨坊
{

}
void TechSkill::ModifyFarmMillEffect()
{

}
void TechSkill::ModifyFarmWaterRecovery()
{

}
void TechSkill::ModifyFarmWaterWayPrice()
{

}
void TechSkill::ModifyFarmMillPrice()
{

}