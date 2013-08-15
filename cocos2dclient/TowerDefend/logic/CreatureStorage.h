#pragma once
#ifndef CREATURESTORAGE_H
#define CREATURESTORAGE_H
#include "assert.h"
#include "share/Singleton.h"
#include "baseCreature.h"
extern std::string _defaultStateImageKey[CreatureState_Max];
extern std::string _defaultDirImageKey[CreatureDir_Max];
class CreatureStorage : public Singleton<CreatureStorage>
{
	typedef std::map<int, creatureInfo*> MAPCREATURES;
public:
	CreatureStorage(void);
	virtual ~CreatureStorage(void);
public:
	void loadXml(const char* xmlPath);
	baseCreature* CreateCreature(const char* name);
	baseCreature* CreateCreature(int id);


private:
	MAPCREATURES _creatureInfos;

};

#endif