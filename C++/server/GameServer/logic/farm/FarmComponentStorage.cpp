#include "stdafx.h"
#include "FarmComponentStorage.h"
#include "share/Database/Database.h"
#include "share/Database/DatabaseEnv.h"
initialiseSingleton(FarmComponentStorage);
FarmComponentStorage::FarmComponentStorage()
{
	//Load();
}

FarmComponentStorage::~FarmComponentStorage()
{

}


void FarmComponentStorage::Load()
{
	QueryResult * result;
	result = phoneDatabase->Query("SELECT * FROM millconf");
	if (result)
	{
		if (result->GetRowCount() > 0)
		{
			do 
			{
				Field * fields = result->Fetch();
				MillConf* conf = new MillConf();
				conf->level = fields[0].GetInt32();
				conf->spendgold = fields[1].GetInt32();
				conf->modify = fields[2].GetInt32();
				conf->modifyPct = fields[3].GetInt32();
				_millConfs.insert(MILLCONFS::value_type(conf->level, conf));
			} while (result->NextRow());
		}
		delete result;
	}
	else
	{
		MyLog::log->warn("no millconf be loaded");
	}
	result = phoneDatabase->Query("SELECT * FROM waterwayconf");
	if (result)
	{
		if (result->GetRowCount() > 0)
		{
			do 
			{
				Field * fields = result->Fetch();
				WaterWayConf* conf = new WaterWayConf();
				conf->level = fields[0].GetInt32();
				conf->spendgold = fields[1].GetInt32();
				conf->modify = fields[2].GetInt32();
				conf->modifyPct = fields[3].GetInt32();
				_waterWays.insert(WATERWAYCONFS::value_type(conf->level, conf));
			} while (result->NextRow());
		}

		delete result;
	}
	else
	{
		MyLog::log->warn("no waterwayconf be loaded");
	}

}

const MillConf* FarmComponentStorage::getMillConf(int level)
{

	MillConf* p = NULL;
	MILLCONFS::iterator it = _millConfs.find(level);
	if (it != _millConfs.end())
	{
		p = it->second;
	}
	return p;
}

const WaterWayConf* FarmComponentStorage::getWaterWayConf(int level)
{
	WaterWayConf* p = NULL;
	WATERWAYCONFS::iterator it = _waterWays.find(level);
	if (it != _waterWays.end())
	{
		p = it->second;
	}
	return p;
}

