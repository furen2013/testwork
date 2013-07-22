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
}


TDResourceManager::~TDResourceManager(void)
{
}


void TDResourceManager::LoadResource()
{
	
	_spriteFramCache->addSpriteFramesWithFile("res/animations/grossini_blue.plist", "res/animations/grossini_blue.png");
	_spriteFramCache->addSpriteFramesWithFile("res/animations/Role.plist", "res/animations/Role.png");

	// Purge previously loaded animation
	

	_animationCache->addAnimationsWithFile("res/animations/myanimations.plist");

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