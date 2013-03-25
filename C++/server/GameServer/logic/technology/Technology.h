#pragma once
#ifndef TECHNOLOGY_H
#define TECHNOLOGY_H
#include "TypeDef.h"
extern 	enum enTechResult;
class techconf;
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
	
	typedef map<int, TechLevel*> maptechlevel;
public:
	Technology();
	~Technology();
	bool IsHaveTechLevel(int level);
	int GetTechCount(int level,int id);
	int GetTechValue();
	enTechResult addTech(int level, int id, int ncount, const techconf* pconf);
	bool addTechValue(int nValue);
	bool openTechLevel(int level);
	bool LoadFromStr(string str);
	inline void setAccount(DWORD account){_account = account;}
	inline DWORD getAccount(){return _account;}
	string toString();
protected:
	
protected:
	maptechlevel _techlevels;
	DWORD _account;
	volatile int _techvalue;

};

#endif