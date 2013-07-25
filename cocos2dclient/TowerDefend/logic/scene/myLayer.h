#pragma once
#ifndef MYLAYER_H
#define MYLAYER_H

class myLayer : public CCLayer
{
public:
	myLayer(void);
	virtual ~myLayer(void);

protected:
	CCMenuItemImage* CreateMenuItemImage(ItemImageResource* p, SEL_MenuHandler selector);
};

#endif