#include "StdAfx.h"
#include "TDResourceManager.h"
using namespace cocos2d;


TDResourceManager::TDResourceManager(void)
{
	_spriteFramCache = CCSpriteFrameCache::sharedSpriteFrameCache();
	CCAnimationCache::purgeSharedAnimationCache();
	_animationCache = CCAnimationCache::sharedAnimationCache();
}


TDResourceManager::~TDResourceManager(void)
{
}


void TDResourceManager::LoadResource()
{
	
	_spriteFramCache->addSpriteFramesWithFile("animations/grossini.plist");
	_spriteFramCache->addSpriteFramesWithFile("animations/grossini_gray.plist", "animations/grossini_gray.png");
	_spriteFramCache->addSpriteFramesWithFile("animations/grossini_blue.plist", "animations/grossini_blue.png");
	_spriteFramCache->addSpriteFramesWithFile("animations/Role.plist", "animations/Role.png");

	// Purge previously loaded animation
	

	_animationCache->addAnimationsWithFile("animations/blueanimations.plist");

}


CCSpriteFrame* TDResourceManager::getSpriteFram(const char* name)
{
	return _spriteFramCache->spriteFrameByName(name);
}

CCAnimation* TDResourceManager::getAnimation(const char* name)
{
	return _animationCache->animationByName(name);
}