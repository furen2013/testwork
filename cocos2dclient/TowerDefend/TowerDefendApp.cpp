#include "stdafx.h"
#include "TowerDefendApp.h"
#include "CCEGLView.h"
#include "CCDirector.h"
#include <algorithm>
#include "SimpleAudioEngine.h"
#include "script_support/CCScriptSupport.h"
#include "CCLuaEngine.h"
#include "logic/scene/LoginScene.h"
#include "logic/scene/sceneManager.h"

USING_NS_CC;

TowerDefendApp::TowerDefendApp() {

}

TowerDefendApp::~TowerDefendApp() 
{
}

bool TowerDefendApp::applicationDidFinishLaunching() {
	// initialize director
	CCDirector *pDirector = CCDirector::sharedDirector();

	pDirector->setOpenGLView(CCEGLView::sharedOpenGLView());

	// enable High Resource Mode(2x, such as iphone4) and maintains low resource on other devices.
	// pDirector->enableRetinaDisplay(true);

	// turn on display FPS
	pDirector->setDisplayStats(true);

	// set FPS. the default value is 1.0/60 if you don't call this
	pDirector->setAnimationInterval(1.0 / 60);

	sceneManager::getSingleton().init(pDirector);
	sceneManager::getSingleton().enterScene(Login_Scene);
	// ready to add my scence;
	// create a scene. it's an autorelease object
	//CCScene *pScene = HelloWorld::scene();

	// run
	//pDirector->runWithScene(pScene);


	//CCScene * pScene = CCScene::create();
	//CCLayer * pLayer = new LoginController();
	//pLayer->autorelease();

	//GameScene * pGameScene = new GameScene();

	//pScene->addChild(pLayer);
	//pDirector->runWithScene(pScene);



	return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void TowerDefendApp::applicationDidEnterBackground() {
	CCDirector::sharedDirector()->stopAnimation();

	// if you use SimpleAudioEngine, it must be pause
	// SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void TowerDefendApp::applicationWillEnterForeground() {
	CCDirector::sharedDirector()->startAnimation();

	// if you use SimpleAudioEngine, it must resume here
	// SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
}
