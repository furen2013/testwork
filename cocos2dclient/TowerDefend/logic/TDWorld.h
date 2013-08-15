#pragma once
#ifndef TDWORLD_H
#define TDWORLD_H
#include "share/Singleton.h"
class baseMapCell;
class gameMap;
class baseCreature;
class baseObj;
class TDWorld : public CCNode , public Singleton<TDWorld>
{
public:
	TDWorld(void);
	virtual ~TDWorld(void);
public:
	void LoadResource(const char* xmlpath);
	void addcell(baseMapCell* cell);
	virtual void update(float dt);
	gameMap* get_gameMap();;
protected:
	std::vector<baseMapCell*> _mapObjs;
	std::vector<baseCreature*> _creatures;
	std::vector<baseObj*> _objs;
	gameMap* _gameMap;

};

#endif