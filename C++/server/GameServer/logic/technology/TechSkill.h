#pragma once
#ifndef TECHSKILL
#define TECHSKILL
#include "TechSkillInfo.h"
class Technology;
class TechSkill
{
public:
	TechSkill(	TechSkillInfo* info, Technology* technology);
	~TechSkill();
public:
	void ParseSkill();
public:
	void ModifyPetDamage(bool b); //add base and max
	void OpenPetWeapon(bool b);
	void ModifyPetWeaponSplitDamage(bool b);
	void ModifyPetWopeanDotDamage(bool b); // 棒类
	void ModifyPetWopeanPenetrateDamage(bool b);//钉类
	void ModifyPetAllWopeanDamageToBarrier(bool b);
	void ModifyPetArmor(bool b); //更换所有防御到某一ID
	void ModifyPetEquipArmor(bool b);//更改防具防御防御值
	void OpenPetWeaponPropertyDamage(bool b); //开启武器附加攻击
	void ModifyFarmHarvest(bool b); //增加农场产量
	void OpenFarmWaterWayTech(bool b);//水道开启
	void ModifyFarmWaterWayEffect(bool b); //修改水道效果
	void OpenFarmMillTech(bool b);	//开启磨坊
	void ModifyFarmMillEffect(bool b);
	void ModifyFarmWaterRecovery(bool b);
	void ModifyFarmWaterWayPrice(bool b);
	void ModifyFarmMillPrice(bool b);

	inline int getID()
	{
		if (_info)
		{
			return _info->id;
		}
		return 0;
	}
protected:
	TechSkillInfo* _info;
	Technology*	_technology;
};


typedef void(TechSkill::*pSkillEffect)(bool b);

#endif