#pragma once
#ifndef GAMEMAP_H
#define GAMEMAP_H
#include "iostream"
#include "../astar/Astar.h"
class baseMapCell;
struct tile_map;
class gameMap
{
public:
	gameMap();
	~gameMap();

public:
	void Create(const char* xml);
	bool setRoadBlock(int row, int col, bool block);
	bool getNextRoad(CCPoint startPoint, CCPoint& nextPoint);
	bool getFullWay(CCPoint startPoint, std::vector<CCPoint>& way);
	bool isArrived(CCPoint pos);
	CCPoint getStartPt();
	CCPoint getEndPt();
	CCPoint getCellCenterPoint(int posX, int posY);
	tile_map* _tile_map;
protected:
	void createMap();
	
	aPoint getCell(CCPoint point);

private:
	int _width;
	int _height;
	int _cellwidth;
	int _cellheight;
	int _offsetx;
	int _offsety;
	char* _mapdata;

	
	aPoint _endPoint;
	CCPoint	_endCellCenterPoint;
	CCPoint _startPoint;
	CCPoint _startCellCenterPoint;
	
};




#endif