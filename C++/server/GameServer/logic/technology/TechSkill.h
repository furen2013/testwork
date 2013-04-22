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
	void ModifyPetWopeanDotDamage(); // ����
	void ModifyPetWopeanPenetrateDamage();//����
	void ModifyPetAllWopeanDamageToBarrier();
	void ModifyPetArmor(); //�������з�����ĳһID
	void ModifyPetEquipArmor();//���ķ��߷�������ֵ
	void OpenPetWeaponPropertyDamage(); //�����������ӹ���
	void ModifyFarmHarvest(); //����ũ������
	void OpenFarmWaterWayTech();//ˮ������
	void ModifyFarmWaterWayEffect(); //�޸�ˮ��Ч��
	void OpenFarmMillTech();	//����ĥ��
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