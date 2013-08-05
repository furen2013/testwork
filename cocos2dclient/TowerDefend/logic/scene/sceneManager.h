#pragma once
#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H
enum SceneType
{
	Login_Scene,
	Game_Scene
};
class sceneManager
{
public:
	typedef std::map<SceneType, cocos2d::CCScene*> MAPSCENE;
public:
	sceneManager(void);
	virtual ~sceneManager(void);
public:
	void init(CCDirector * director);
protected:
	MAPSCENE _scene;
	cocos2d::CCScene* _currentScene;
	CCDirector *_Director;
};

#endif