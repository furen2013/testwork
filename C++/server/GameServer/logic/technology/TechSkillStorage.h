#pragma once
#ifndef TECHSKILLSTORAGE_H
#define TECHSKILLSTORAGE_H
struct TechSkillInfo;
class TechSkillStorage : public Singleton<TechSkillStorage>
{
	typedef	map<int32, TechSkillInfo*> MAPTECHSKILLINFO;
public:
	TechSkillStorage();
	~TechSkillStorage();
	bool init();
	TechSkillInfo* FindSkillInfo(int32 id);
protected:
	MAPTECHSKILLINFO _mapTechInfo;
};
#endif