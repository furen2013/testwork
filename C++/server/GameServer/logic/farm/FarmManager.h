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
public:
	void init();
	// if return null is already have farm;
	FarmLogic* CreateFarm(DWORD account);
	void Process();
	FarmLogic* GetFarmLogic(DWORD account);
protected:
	void LoadFarms();
protected:
	FARMS _farms;

};
#endif