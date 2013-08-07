#include "StdAfx.h"
#include "GameController.h"
#include "../TDWorld.h"


GameController::GameController(void)
{
}


GameController::~GameController(void)
{
}



void GameController::init()
{
	//myLayer::init();
	TDWorld::getSingleton().LoadResource("../res/map/map.xml");
	addChild(TDWorld::getSingletonPtr());
}

void GameController::onBackToLogin(CCObject* pSender)
{

}

void GameController::onRestart(CCObject* pSender)
{

}


void GameController::onExitGame(CCObject* pSender)
{

}


void GameController::onPauseGame(CCObject* pSender)
{

}


void GameController::onResumGame(CCObject* pSender)
{

}