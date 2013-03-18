#pragma once
#ifndef	TECHNOLOGYMANAGER_H
#define TECHNOLOGYMANAGER_H
class Technology;

struct reqtech
{
	int id;
	int reqcount;
};
struct techconf
{
	typedef vector<reqtech*> vcreqtechs;
	techconf()
	{
		id = 0;
		maxCount = 0;
		reqtechs.clear();

	}
	int id;
	int maxCount;
	vcreqtechs reqtechs;
};


struct techLevelconf
{
	typedef map<int, techconf*> maptechinfo;
	int level;
	maptechinfo techinfos;
	int spendgold;
};

class TechnologyManager
{
public:
	enum enAddTechResult
	{
		AddTechResult_OK,
		AddTechResult_NotFoundUser,
		AddTechResult_LevelNotOpen,
		AddTechResult_NotHaveReqTech,
		AddTechResult_NotHaveTechLevel,
		AddTechResult_NotHaveTech,
		AddTechResult_NotHaveOwnerTechValue,
		AddTechResult_Max
	};
public:
	typedef map<int,techLevelconf*> maptechLevelconf;
	typedef map<DWORD, Technology*> maptechnology;
public:
	TechnologyManager();
	~TechnologyManager();
	bool Load();
	enAddTechResult IsCanAddTechCount(DWORD account, int level, int id, int count = 1);
protected:
	maptechLevelconf  techLevelconfs;
	maptechnology technologys;

};
#endif