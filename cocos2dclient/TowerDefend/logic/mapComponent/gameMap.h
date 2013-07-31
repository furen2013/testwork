#pragma once
#ifndef GAMEMAP_H
#define GAMEMAP_H
#include "iostream"
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