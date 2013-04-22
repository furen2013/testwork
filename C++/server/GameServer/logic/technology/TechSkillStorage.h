#pragma once
#ifndef TECHSKILLSTORAGE_H
#define TECHSKILLSTORAGE_H
struct TechSkillInfo;
class TechSkillStorage
{
	typedef	map<int32, TechSkillInfo*> MAPTECHSKILLINFO;
public:
	TechSkillStorage();
	~TechSkillStorage();
	bool Load();
protected:
	MAPTECHSKILLINFO _mapTechInfo;
};
#endif