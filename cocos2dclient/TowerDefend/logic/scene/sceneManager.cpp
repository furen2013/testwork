#include "StdAfx.h"
#include "sceneManager.h"
#include "myScene.h"
#include "LoginScene.h"
#include "GameScene.h"
#include "GameController.h"
#include "../mapComponent/mapComponentStorage.h"
#include "../CreatureStorage.h"
initialiseSingleton(sceneManager);

sceneManager::sceneManager(void):_currentScene(NULL),
	_director(NULL)
{

}


sceneManager::~sceneManager(void)
{
}

void sceneManager::init(CCDirector * director)
{
	mapComponentStorage::getSingleton().LoadXml("../../../../../testwork/cocos2dclient/TowerDefend/res/map/mapcells.xml");
	CreatureStorage::getSingleton().loadXml("../../../../../testwork/cocos2dclient/TowerDefend/res/creatures/creatureinfos.xml");

	
	_director = director;
	LoginScene* pLoginScene = new LoginScene();
	
	LoginController* pLoginController = new LoginController();
	pLoginScene->init(pLoginController);
	_scene.insert(MAPSCENE::value_type(Login_Scene, pLoginScene));
	GameScene* pGameScene = new GameScene();
	GameController* pGameController = new GameController();

	pGameScene->init(pGameController);
	
	_scene.insert(MAPSCENE::value_type(Game_Scene, pGameScene));
}

void sceneManager::enterScene(SceneType enType)
{
	myScene* scene = NULL;
	MAPSCENE::iterator it = _scene.find(enType);
	if(it != _scene.end())
	{
		scene = it->second;
	}
	if (scene)
	{
		if (_currentScene == NULL)
		{
			_director->runWithScene(scene);
		}
		else
		{
			_director->replaceScene(scene);
		}
		_currentScene = scene;

	}
}
