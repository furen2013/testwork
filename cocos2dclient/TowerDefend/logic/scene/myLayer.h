#pragma once
#ifndef MYLAYER_H
#define MYLAYER_H
#include "cocos2d.h"
struct ItemImageResource;

class myLayer : public CCLayer
{
public:
	myLayer(void);
	virtual ~myLayer(void);
public:
	virtual void init() = 0;

protected:
	CCMenuItemImage* CreateMenuItemImage(ItemImageResource* p, SEL_MenuHandler selector);
};

#endif