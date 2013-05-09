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
	void ModifyPetWopeanDotDamage(bool b); // ����
	void ModifyPetWopeanPenetrateDamage(bool b);//����
	void ModifyPetAllWopeanDamageToBarrier(bool b);
	void ModifyPetArmor(bool b); //�������з�����ĳһID
	void ModifyPetEquipArmor(bool b);//���ķ��߷�������ֵ
	void OpenPetWeaponPropertyDamage(bool b); //�����������ӹ���
	void ModifyFarmHarvest(bool b); //����ũ������
	void OpenFarmWaterWayTech(bool b);//ˮ������
	void ModifyFarmWaterWayEffect(bool b); //�޸�ˮ��Ч��
	void OpenFarmMillTech(bool b);	//����ĥ��
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