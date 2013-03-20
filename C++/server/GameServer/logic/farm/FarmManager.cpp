#include "stdafx.h"
#include "FarmManager.h"
initialiseSingleton(FarmManager);
FarmManager::FarmManager()
{

}

FarmManager::~FarmManager()
{

}

void FarmManager::LoadFarms()
{

}

void FarmManager::Process()
{

}

FarmLogic* FarmManager::GetFarmLogic(DWORD account)
{
	FarmLogic*  pLogic = NULL;
	FARMS::iterator it = _farms.find(account);
	if (it != _farms.end())
	{
		pLogic = it->second;
	}
	return pLogic;
}