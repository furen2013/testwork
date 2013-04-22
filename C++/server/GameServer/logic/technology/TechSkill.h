#pragma once
#ifndef TECHSKILL
#define TECHSKILL
#include "TechSkillInfo.h"
class Technology;
class TechSkill
{
public:
	TechSkill();
	~TechSkill();
	void ModifyPetDamage(); //add base and max
	void OpenPetWeapon();
	void ModifyPetWeaponSplitDamage();
	void ModifyPetWopeanDotDamage(); // 棒类
	void ModifyPetWopeanPenetrateDamage();//钉类
	void ModifyPetAllWopeanDamageToBarrier();
	void ModifyPetArmor(); //更换所有防御到某一ID
	void ModifyPetEquipArmor();//更改防具防御防御值
	void OpenPetWeaponPropertyDamage(); //开启武器附加攻击
	void ModifyFarmHarvest(); //增加农场产量
	void OpenFarmWaterWayTech();//水道开启
	void ModifyFarmWaterWayEffect(); //修改水道效果
	void OpenFarmMillTech();	//开启磨坊
	void ModifyFarmMillEffect();
	void ModifyFarmWaterRecovery();
	void ModifyFarmWaterWayPrice();
	void ModifyFarmMillPrice();
public:
	TechSkillInfo* _info;
	Technology*	_technology;
};


typedef void(TechSkill::*pSkillEffect)();

#endif