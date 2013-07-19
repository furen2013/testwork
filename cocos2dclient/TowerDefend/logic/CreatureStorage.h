#pragma once
#ifndef CREATURESTORAGE_H
#define CREATURESTORAGE_H
class baseCreature;

class CreatureStorage
{
public:
	CreatureStorage(void);
	virtual ~CreatureStorage(void);
public:
	baseCreature* CreateCreature(const char* name);
};

#endif