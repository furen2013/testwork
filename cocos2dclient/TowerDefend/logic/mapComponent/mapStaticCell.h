#pragma once
#include "basemapcell.h"
class mapStaticCell :
	public baseMapCell
{
public:
	mapStaticCell(void);
	virtual ~mapStaticCell(void);
public:
	virtual void LoadResource(const char* config);
	virtual void onAddToWorld();
	virtual void setPosition(float x, float y);


protected:
	CCSprite*			  _currentSprite;
	CCActionInterval*	  _actionInterval;
};

