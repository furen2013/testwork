#pragma once
#ifndef FARMMANAGER_H
#define FARMMANAGER_H
#include "TypeDef.h"
class FarmLogic;
typedef map<DWORD, FarmLogic*> FARMS;
class FarmManager
{
public:
	FarmManager();
	~FarmManager();
	void LoadFarms();
	void Process();
protected:
	FARMS _farms;
};
#endif