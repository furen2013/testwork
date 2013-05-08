#include "stdafx.h"
#include "TechSkill.h"
#include "../farm/FarmLogic.h"
#include "../farm/FarmManager.h"
#include "Technology.h"

pSkillEffect Skillhandle[effectType_Max] ={
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
TechSkill::TechSkill(TechSkillInfo* info, Technology* technology)
{
	_info = info;
	_technology = technology;
}
TechSkill::~TechSkill()
{

}

void TechSkill::ParseSkill()
{
	if (_info)
	{
		(*this.*Skillhandle[_info->effect])(true);
	}

}
void TechSkill::ModifyPetDamage(bool b) //add base and max
{

}
void TechSkill::OpenPetWeapon(bool b)
{

}
void TechSkill::ModifyPetWeaponSplitDamage(bool b)
{

}
void TechSkill::ModifyPetWopeanDotDamage(bool b )// 棒类
{

}
void TechSkill::ModifyPetWopeanPenetrateDamage(bool b)//钉类
{

}
void TechSkill::ModifyPetAllWopeanDamageToBarrier(bool b)
{

}
void TechSkill::ModifyPetArmor(bool b) //更换所有防御到某一ID
{

}
void TechSkill::ModifyPetEquipArmor(bool b)//更改防具防御防御值
{

}
void TechSkill::OpenPetWeaponPropertyDamage(bool b) //开启武器附加攻击
{

}
void TechSkill::ModifyFarmHarvest(bool b)//增加农场产量
{	
	FarmLogic* farm =  FarmManager::getSingleton().GetFarmLogic(_technology->getAccount());
	if (farm)
	{
		if (b)
		{
			farm->modifyCellBaseHavest(_info->parameter);
		}
		else
		{
			farm->modifyCellBaseHavest(-_info->parameter);
		}
	}
}
void TechSkill::OpenFarmWaterWayTech(bool b)//水道开启
{
	FarmLogic* farm =  FarmManager::getSingleton().GetFarmLogic(_technology->getAccount());
	if (farm)
	{
		if (b)
		{
			farm->modifyallowBuildWaterWay(_info->parameter);
		}
		else
		{
			farm->modifyallowBuildWaterWay(-_info->parameter);
		}
	}
}
void TechSkill::ModifyFarmWaterWayEffect(bool b) //修改水道效果
{
	FarmLogic* farm =  FarmManager::getSingleton().GetFarmLogic(_technology->getAccount());
	if (farm)
	{
		if (b)
		{
			farm->modifyWaterWayEffect(_info->parameter);
		}
		else
		{
			farm->modifyWaterWayEffect(-_info->parameter);
		}
	}
}
void TechSkill::OpenFarmMillTech(bool b)	//开启磨坊
{
	FarmLogic* farm =  FarmManager::getSingleton().GetFarmLogic(_technology->getAccount());
	if (farm)
	{
		if (b)
		{
			farm->modifyallowBuildMill(_info->parameter);
		}
		else
		{
			farm->modifyallowBuildMill(-_info->parameter);
		}
	}
	
}
void TechSkill::ModifyFarmMillEffect(bool b)
{
	FarmLogic* farm =  FarmManager::getSingleton().GetFarmLogic(_technology->getAccount());
	if (farm)
	{
		if (b)
		{
			farm->modifyMillEffect(_info->parameter);
		}
		else
		{
			farm->modifyMillEffect(-_info->parameter);
		}
	}
}
void TechSkill::ModifyFarmWaterRecovery(bool b)
{

}
void TechSkill::ModifyFarmWaterWayPrice(bool b)
{

}
void TechSkill::ModifyFarmMillPrice(bool b)
{

}