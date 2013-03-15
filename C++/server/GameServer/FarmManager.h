#pragma once
#ifndef FARMMANAGER_H
#define FARMMANAGER_H
class FarmLogic;
typedef map<DWORD account, FarmLogic*> FARMS;
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