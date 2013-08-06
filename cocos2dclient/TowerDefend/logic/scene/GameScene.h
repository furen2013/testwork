#pragma once
#ifndef GAMESCENE_H
#define GAMESCENE_H
#include "myScene.h"
#include "myLayer.h"

class GameScene  : public myScene
{
public:
	GameScene(void);
	virtual ~GameScene(void);
public:
	virtual void Init();
protected:

};



#endif