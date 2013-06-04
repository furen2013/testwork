#pragma once
#ifndef TECHNOLOGY_H
#define TECHNOLOGY_H
#include "TypeDef.h"
extern 	enum enTechResult;
struct techconf;
class Player;
class TechSkill;
struct TechInfo
{
	int id;
	int currentCount;
};
struct TechLevel
{
	TechLevel()
	{

	}
	typedef map<int, TechInfo*> maptechinfo;
	int level;
	maptechinfo TechInfos;

};
class Technology
{
public:
	typedef map<int, TechLevel*> maptechlevel;
	typedef map<int, TechSkill*> maptechskill;
public:
	Technology();
	~Technology();
	bool IsHaveTechLevel(int level);
	int GetTechCount(int level,int id);
	int GetTechValue();
	

	bool LoadTechlevelsFromStr(string str);
	bool loadSkillsFromStr(string str);
	inline void setAccount(DWORD account){_account = account;}
	inline DWORD getAccount(){return _account;}
	string techlevelstoString();
	string skillstoString();
	inline const int GetTechvalue(){return _techvalue;}
	maptechlevel::const_iterator itTechBegin();
	maptechlevel::const_iterator itTechEnd();
public:
	void sendTechnologyState();
	void addTechValue(int Techvalue);
	void openTechLevel(int level);
	void addTech(int level, int id, int count = 1);
	inline void setTechValue(int techvalue)
	{
		_techvalue = techvalue;
	}
protected:
	bool _addTechValue(int nValue);
	bool _openTechLevel(int level);
	void _addTech(int level, int id, int ncount, const techconf* pconf);
	void addSkill(int skillid);
	inline void setModify(bool b)
	{
		_modify = b;
	}
	inline bool modify()
	{
		return _modify;
	}

protected:
	maptechlevel _techlevels;
	maptechskill _techskill;
	DWORD _account;
	volatile int _techvalue;
	Player* _player;
	bool _modify;
	
};

#endif