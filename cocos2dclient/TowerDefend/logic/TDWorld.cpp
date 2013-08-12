#include "StdAfx.h"
#include "TDWorld.h"
#include "mapComponent/BaseMapCell.h"
#include "mapComponent/gameMap.h"

initialiseSingleton(TDWorld);
TDWorld::TDWorld(void)
	:_gameMap(NULL)
{
}


TDWorld::~TDWorld(void)
{
}

void TDWorld::LoadResource(const char* xmlpath)
{
	if (_gameMap == NULL)
	{
		_gameMap = new gameMap();
		_gameMap->Create(xmlpath);
	}
}


void TDWorld::addcell(baseMapCell* cell)
{
	_mapObjs.push_back(cell);
	cell->onAddToWorld();
	addChild(cell);
}

void TDWorld::update(float dt)
{
	CCNode::update(dt);
}

gameMap* TDWorld::get_gameMap()
{
	return _gameMap;
}