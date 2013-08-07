#pragma once
#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H
#include "share/Singleton.h"
class myScene;
enum SceneType
{
	Login_Scene,
	Game_Scene
};
class sceneManager: public Singleton<sceneManager>
{
public:
	typedef std::map<SceneType, myScene*> MAPSCENE;
public:
	sceneManager(void);
	virtual ~sceneManager(void);
public:
	void init(CCDirector * director);
	void enterScene(SceneType enType);

protected:
	MAPSCENE _scene;
	myScene* _currentScene;
	CCDirector *_director;
};

#endif