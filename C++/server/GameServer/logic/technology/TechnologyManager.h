#pragma once
#ifndef	TECHNOLOGYMANAGER_H
#define TECHNOLOGYMANAGER_H
#include "TypeDef.h"

enum enTechResult
{
	TechResult_OK,
	TechResult_NotFoundUser,
	TechResult_LevelNotOpen,
	TechResult_NotHaveReqTech,
	TechResult_NotHaveTechLevel,
	TechResult_NotHaveTech,
	TechResult_NotHaveOwnerTechValue,
	TechResult_AlreadyOpenTechLevel,
	TechResult_Max
};


class Technology;

struct reqtech
{
	int id;
	int reqcount;
};

struct TechSkillConf
{
	typedef map<int, int> mapskill;
	int id;
	mapskill skills;

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
	bool LoadFromStr(string str);

};


struct techLevelconf
{
	typedef map<int, techconf*> maptechinfo;
	int level;
	maptechinfo techinfos;
	int spendgold;
};

class TechnologyManager: public Singleton<TechnologyManager>
{
public:
	typedef map<int,techLevelconf*> maptechLevelconf;
	typedef map<DWORD, Technology*> maptechnology;
	typedef map<int, TechSkillConf*> maptechskillconf;
public:
	TechnologyManager();
	~TechnologyManager();
	bool Load();
	enTechResult AddTechCount(DWORD account, int level, int id, int count = 1);
	enTechResult OpenTechLevel(DWORD account, int level);
	Technology* GetTech(DWORD account); // if null create it
	const techLevelconf* FindTechConfLevel(int level);
	const TechSkillConf* FindSkillConf(int id);
	int FindTechSkill(int id, int n);
protected:
	

protected:
	maptechLevelconf  _techLevelconfs;
	maptechnology _technologys;
	maptechskillconf _techskillconf;

};
#endif