#include "StdAfx.h"
#include "TDResourceManager.h"
using namespace cocos2d;

initialiseSingleton(TDResourceManager);
TDResourceManager::TDResourceManager(void)
{
	_spriteFramCache = CCSpriteFrameCache::sharedSpriteFrameCache();
	CCAnimationCache::purgeSharedAnimationCache();
	_animationCache = CCAnimationCache::sharedAnimationCache();
	_defaultAniName = "default";
	_defaultAniName = "up_walk_fly_48bat.png";
	LoadResource();
}


TDResourceManager::~TDResourceManager(void)
{
}


void TDResourceManager::LoadResource()
{
	
	_spriteFramCache->addSpriteFramesWithFile("../res/animations/grossini_blue.plist", "../res/animations/grossini_blue.png");
	_spriteFramCache->addSpriteFramesWithFile("../res/animations/Role.plist", "../res/animations/Role.png");
	_spriteFramCache->addSpriteFramesWithFile("../res/animations/miko.plist","../res/animations/miko.png");
	_spriteFramCache->addSpriteFramesWithFile("../res/animations/testimage.plist", "../res/animations/fly_048bat.png");
	_spriteFramCache->addSpriteFramesWithFile("../res/animations/grasscell.plist", "../res/animations/grasscell.png" );
	_spriteFramCache->addSpriteFramesWithFile("../res/animations/caverncell.plist", "../res/animations/caverncell.png" );

	// Purge previously loaded animation
	

	_animationCache->addAnimationsWithFile("../res/animations/myanimations.plist");

}


CCSpriteFrame* TDResourceManager::getSpriteFram(const char* name)
{

	CCSpriteFrame* frame = _spriteFramCache->spriteFrameByName(name);
	if (!frame)
	{
		frame = _spriteFramCache->spriteFrameByName(_defaultSpriteFrame.c_str());
	}

	return frame;
}

CCAnimation* TDResourceManager::getAnimation(const char* name)
{
	CCAnimation* pAni = _animationCache->animationByName(name);
	if (!pAni)
	{
		pAni = _animationCache->animationByName(_defaultAniName.c_str());
	}
	return pAni;
}


testsprite::testsprite()
{
	std::string imgae;
	CCAnimation* _Animation = TDResourceManager::getSingletonPtr()->getAnimation(imgae.c_str());

	CCAnimate* _currentAnimate;
	if (_Animation)
	{
		_currentAnimate = CCAnimate::create(_Animation);

		CCActionInterval* p =CCRepeat::create(_currentAnimate, 111);

		CCSprite* _currentSprite = CCSprite::create();
		_currentSprite->runAction(p);
		_currentSprite->setPosition(CCPoint(40.f, 40.f));
		addChild(_currentSprite);
	}


}

testsprite::~testsprite()
{

}