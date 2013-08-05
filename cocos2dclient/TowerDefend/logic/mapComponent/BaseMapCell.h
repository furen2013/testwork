#pragma once
#ifndef BASEMAPCELL_H
#define BASEMAPCELL_H
#include "cocos2d.h"
#include "../baseObj.h"
struct mapComponentTG;
class baseMapCell : public baseObj
{
public:
	baseMapCell(void);
	virtual ~baseMapCell(void);
public:
	virtual void CreateCell(mapComponentTG* tg) = 0;
protected:
	std::string _animation;
	std::string _deadanimation;
	
};

#endif