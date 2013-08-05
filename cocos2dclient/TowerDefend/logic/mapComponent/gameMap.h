#pragma once
#ifndef GAMEMAP_H
#define GAMEMAP_H
#include "iostream"
class baseMapCell;
class gameMap
{
public:
	gameMap();
	~gameMap();

public:
	void Create(const char* xml);
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
	std::vector<baseMapCell*> _mapObjs;
};




#endif