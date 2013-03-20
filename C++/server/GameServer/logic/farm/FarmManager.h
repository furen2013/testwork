#pragma once
#ifndef FARMMANAGER_H
#define FARMMANAGER_H
#include "TypeDef.h"
class FarmLogic;
typedef map<DWORD, FarmLogic*> FARMS;
class FarmManager : public Singleton<FarmManager>
{
public:
	FarmManager();
	~FarmManager();
	void LoadFarms();
	void Process();
	FarmLogic* GetFarmLogic(DWORD account);
protected:
	FARMS _farms;
};
#endif