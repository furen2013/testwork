#include "StdAfx.h"
#include "GameScene.h"
#include "../mapComponent/mapComponentStorage.h"


GameScene::GameScene(void)
{
}


GameScene::~GameScene(void)
{
}


void GameScene::Init()
{
	mapComponentStorage::getSingleton().LoadXml("../res/map/mapcells.xml");
}