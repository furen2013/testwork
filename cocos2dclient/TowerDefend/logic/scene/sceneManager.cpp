#include "StdAfx.h"
#include "sceneManager.h"


sceneManager::sceneManager(void):_currentScene(NULL),
	_Director(NULL)
{

}


sceneManager::~sceneManager(void)
{
}

void sceneManager::init(CCDirector * director)
{
	_Director = director;
	LoginScene* pLoginScene = new LoginScene();
	pLoginScene->init();
	LoginController* pLoginController = new LoginController();
	pLoginController->autorelease();
	pLoginScene->addChild(pLoginController);
	_scene.insert(MAPSCENE::value_type(Login_Scene, pLoginScene));
	GameScene* pGameScene = new GameScene();
	GameController* pGameController = new GameController();
	pGameScene->init();
	pGameScene->addChild(pGameController);
	_scene.insert(MAPSCENE::value_type(Login_Scene, pGameController));
	

}
