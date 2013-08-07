#pragma once
#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H
#include "myLayer.h"

class GameController : public myLayer
{
public:
	GameController(void);
	virtual ~GameController(void);
public:
	virtual void init();
	void onBackToLogin(CCObject* pSender);
	void onRestart(CCObject* pSender);
	void onExitGame(CCObject* pSender);
	void onPauseGame(CCObject* pSender);
	void onResumGame(CCObject* pSender);
};

#endif