#include "stdafx.h"
#include "FarmManager.h"
#include "FarmLogic.h"
#include "share/Database/Database.h"
#include "share/Database/DatabaseEnv.h"
#include "FarmComponentStorage.h"
initialiseSingleton(FarmManager);
FarmManager::FarmManager()
{

}

FarmManager::~FarmManager()
{

}

void FarmManager::init()
{
	FarmComponentStorage::getSingleton().Load();
	LoadFarms();
}

FarmLogic* FarmManager::CreateFarm(DWORD account)
{
	FarmLogic*  pLogic = NULL;
	FARMS::iterator it = _farms.find(account);
	if (it == _farms.end())
	{
		pLogic = new FarmLogic();
		pLogic->setAccount(account);
		pLogic->createCell(0);
		_farms.insert(FARMS::value_type(account, pLogic));
	}

	return pLogic;
}

void FarmManager::LoadFarms()
{
	QueryResult * result;
	result = phoneDatabase->Query("SELECT * FROM %s", "PlayerFarm");
	if (result)
	{
		int ncount = 0;
		if (result->GetRowCount() > 0)
		{
			do 
			{
				ncount ++;
				Field * fields = result->Fetch();
				FarmLogic* farm = new FarmLogic();
				farm->setAccount(fields[0].GetUInt64());
				farm->LoadCells(fields[1].GetString());
				_farms.insert(FARMS::value_type(farm->getAccount(),farm));

			} while (result->NextRow());
		}
		result->Delete();
		MyLog::log->notice("%d farm be loaded", ncount);
	}
	else
	{
		MyLog::log->warn("no farm be loaded");
	}
	


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