#include "stdafx.h"
#include "TechSkill.h"

pSkillEffect handle[effectType_Max] ={
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
void TechSkill::ModifyPetWopeanDotDamage( )// ����
{

}
void TechSkill::ModifyPetWopeanPenetrateDamage()//����
{

}
void TechSkill::ModifyPetAllWopeanDamageToBarrier()
{

}
void TechSkill::ModifyPetArmor() //�������з�����ĳһID
{

}
void TechSkill::ModifyPetEquipArmor()//���ķ��߷�������ֵ
{

}
void TechSkill::OpenPetWeaponPropertyDamage() //�����������ӹ���
{

}
void TechSkill::ModifyFarmHarvest()//����ũ������
{

}
void TechSkill::OpenFarmWaterWayTech()//ˮ������
{

}
void TechSkill::ModifyFarmWaterWayEffect() //�޸�ˮ��Ч��
{

}
void TechSkill::OpenFarmMillTech()	//����ĥ��
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