#pragma once
#ifndef MAPCOMPONENTSTORAGE_H
#define MAPCOMPONENTSTORAGE_H
class baseMapCell;
#include "share/Singleton.h"
struct mapComponentTG{
	int _id;
	int _life;
	bool _block;
	bool _canattack;
	std::string _animation;
	std::string _deadanimation;
	int _randomdeadbox;
};
class mapComponentStorage : public Singleton<mapComponentStorage>
{
	typedef map<int, mapComponentTG*> MAPDATAS;
public:
	mapComponentStorage(void);
	virtual ~mapComponentStorage(void);
public:
	void LoadXml(const char* xmlpath);
	baseMapCell* CreateMapComponent(int id);
private:
	MAPDATAS	_Data;
};

#endif