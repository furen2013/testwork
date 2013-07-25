#pragma once
#ifndef MAPCELLINFO_H
#define MAPCELLINFO_H
#include "iostream"
class mapCellInfo
{
public:
	mapCellInfo(void);
	virtual ~mapCellInfo(void);
};

class gameMap
{
public:
	gameMap();
	~gameMap();

public:
	void Create(const char* xml);

private:
	int _width;
	int _height;
};




#endif