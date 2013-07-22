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
public:
	CreatureStorage(void);
	virtual ~CreatureStorage(void);
public:
	baseCreature* CreateCreature(const char* name);

private:

};

#endif