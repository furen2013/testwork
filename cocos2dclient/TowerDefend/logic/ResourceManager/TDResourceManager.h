#pragma once
#ifndef TDRESOURCEMANAGER_H
#define TDRESOURCEMANAGER_H
#include "cocos2d.h"
#include "sprite_nodes/CCSpriteFrameCache.h"
#include "sprite_nodes/CCAnimationCache.h"
#include "../../utility/Singleton.h"
using namespace cocos2d;


class TDResourceManager : public Singleton<TDResourceManager>
{
public:
	TDResourceManager(void);
	virtual ~TDResourceManager(void);
public:
	void LoadResource();
	CCAnimation* getAnimation(const char* name);
	CCSpriteFrame* getSpriteFram(const char* name); 

private:
	CCSpriteFrameCache* _spriteFramCache;
	CCAnimationCache*   _animationCache;



};

#endif