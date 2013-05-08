#include "stdafx.h"
#include "TechSkill.h"
#include "../farm/FarmLogic.h"
#include "../farm/FarmManager.h"
#include "Technology.h"

pSkillEffect Skillhandle[effectType_Max] ={
	&TechSkill::ModifyPetDamage, //add base and max
	&TechSkill::OpenPetWeapon,
	&TechSkill::ModifyPetWeaponSplitDamage,
	&TechSkill::ModifyPetWopeanDotDamage, // ����
	&TechSkill::ModifyPetWopeanPenetrateDamage,//����
	&TechSkill::ModifyPetAllWopeanDamageToBarrier,
	&TechSkill::ModifyPetArmor,//�������з�����ĳһID
	&TechSkill::ModifyPetEquipArmor,//���ķ��߷�������ֵ
	&TechSkill::OpenPetWeaponPropertyDamage,//�����������ӹ���
	&TechSkill::ModifyFarmHarvest,//����ũ������
	&TechSkill::OpenFarmWaterWayTech,//ˮ������
	&TechSkill::ModifyFarmWaterWayEffect,//�޸�ˮ��Ч��
	&TechSkill::OpenFarmMillTech,//����ĥ��
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
void TechSkill::ModifyPetWopeanDotDamage(bool b )// ����
{

}
void TechSkill::ModifyPetWopeanPenetrateDamage(bool b)//����
{

}
void TechSkill::ModifyPetAllWopeanDamageToBarrier(bool b)
{

}
void TechSkill::ModifyPetArmor(bool b) //�������з�����ĳһID
{

}
void TechSkill::ModifyPetEquipArmor(bool b)//���ķ��߷�������ֵ
{

}
void TechSkill::OpenPetWeaponPropertyDamage(bool b) //�����������ӹ���
{

}
void TechSkill::ModifyFarmHarvest(bool b)//����ũ������
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
void TechSkill::OpenFarmWaterWayTech(bool b)//ˮ������
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
void TechSkill::ModifyFarmWaterWayEffect(bool b) //�޸�ˮ��Ч��
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
void TechSkill::OpenFarmMillTech(bool b)	//����ĥ��
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