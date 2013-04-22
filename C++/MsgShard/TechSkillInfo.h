#pragma once
#ifndef TECHSKILLINFO_H
#define TECHSKILLINFO_H
enum effectType
{
	effectType_ModifyPetDamage, //add base and max
	effectType_OpenPetWeapon,
	effectType_ModifyPetWeaponSplitDamage,
	effectType_ModifyPetWopeanDotDamage, // ����
	effectType_ModifyPetWopeanPenetrateDamage,//����
	effectType_ModifyPetAllWopeanDamageToBarrier,
	effectType_ModifyPetArmor, //�������з�����ĳһID
	effectType_ModifyPetEquipArmor,//���ķ��߷�������ֵ
	effectType_OpenPetWeaponPropertyDamage, //�����������ӹ���
	effectType_ModifyFarmHarvest, //����ũ������
	effectType_OpenFarmWaterWayTech,//ˮ������
	effectType_ModifyFarmWaterWayEffect, //�޸�ˮ��Ч��
	effectType_OpenFarmMillTech,	//����ĥ��
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