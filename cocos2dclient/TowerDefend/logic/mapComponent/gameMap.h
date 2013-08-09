#pragma once
#ifndef GAMEMAP_H
#define GAMEMAP_H
#include "iostream"
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
protected:
	void createMap();

private:
	int _width;
	int _height;
	int _cellwidth;
	int _cellheight;
	int _offsetx;
	int _offsety;
	char* _mapdata;

	tile_map* _tile_map;
	
};




#endif