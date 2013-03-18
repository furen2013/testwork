#pragma once
#ifndef TECHNOLOGY_H
#define TECHNOLOGY_H
struct TechInfo
{
	int id;
	int currentCount;
};
struct TechLevel
{
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
protected:
	maptechlevel techlevels;
	DWORD account;
	int techvalue;

};

#endif