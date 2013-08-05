#pragma once
#ifndef GAMESCENE_H
#define GAMESCENE_H
#include "mys"
#include "myLayer.h"

class GameScene  : public cocos2d::CCScene
{
public:
	GameScene(void);
	virtual ~GameScene(void);
public:
	virtual void Init();
protected:

};



#endif