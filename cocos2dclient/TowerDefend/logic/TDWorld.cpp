#include "StdAfx.h"
#include "TDWorld.h"
#include "mapComponent/BaseMapCell.h"
#include "mapComponent/gameMap.h"
#include "CreatureStorage.h"

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

		baseCreature* p = CreatureStorage::getSingleton().CreateCreature(1);
		//CCPoint pt = _gameMap->getCellCenterPoint(_gameMap->getEndPt().x,i);
		//p->setPosition(_gameMap->getEndPt().x, _gameMap->getEndPt().y);
		//_objs.push_back(p);
		//_creatures.push_back(p);
		addChild(p);

		//if (_gameMap->_tile_map->column > 0&&_gameMap->_tile_map->row > 0)
		//{
		//	for (int i = 0; i < _gameMap->_tile_map->row; i ++)
		//	{
		//		for (int j = 0; j < _gameMap->_tile_map->column; j ++)
		//		{
		//			if (_gameMap->_tile_map->map[i][j] == EMPTY)
		//			{
		//				CCPoint pt = _gameMap->getCellCenterPoint(i,j);
		//				baseCreature* p = CreatureStorage::getSingleton().CreateCreature(1);
		//				p->setPosition(pt.x, pt.y);
		//				_objs.push_back(p);
		//				_creatures.push_back(p);
		//				addChild(p);

		//			}
		//		}
		//	}
		//	
		//	//return true;
		//}
	}


	//baseCreature* p = CreatureStorage::getSingleton().CreateCreature(1);
	////p->onAddToWorld();

	//for (int i = 0; i < p->_mapWay._vcFullWay.size(); i ++)
	//{
	//	baseCreature* p2 = CreatureStorage::getSingleton().CreateCreature(1);
	//	if (p2)
	//	{
	//		p2->setPosition(p->_mapWay._vcFullWay[i].x, p->_mapWay._vcFullWay[i].y);
	//		TDWorld::getSingleton().addChild(p2);
	//	}

	//}

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