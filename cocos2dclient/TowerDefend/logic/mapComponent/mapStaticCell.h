#pragma once
#include "basemapcell.h"
class mapStaticCell :
	public baseMapCell
{
public:
	mapStaticCell(void);
	virtual ~mapStaticCell(void);
public:
	virtual void CreateCell(mapComponentTG* tg);
	virtual void LoadResource(const char* config);
	virtual void onAddToWorld();
	virtual void setPosition(float x, float y);
	virtual void actionChange();
protected:
	CCSprite*			  _currentSprite;
};

