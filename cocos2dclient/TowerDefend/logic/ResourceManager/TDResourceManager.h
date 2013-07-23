#pragma once
#ifndef TDRESOURCEMANAGER_H
#define TDRESOURCEMANAGER_H
//#include "cocos2d.h"
#include "sprite_nodes/CCSpriteFrameCache.h"
#include "sprite_nodes/CCAnimationCache.h"
#include "share/Singleton.h"
#include "../baseObj.h"
using namespace cocos2d;

class testsprite : public baseObj
{
public:
	testsprite();
	virtual ~testsprite();

protected:
	//CCAnimation*		  _currentAnimation;
	//CCAnimate*			  _currentAnimate;
	//CCSprite*			  _currentSprite;

	//CCPoint			_createPos;
	//bool			_isInWorld;
	//int			   	_maxLife;
	//int				_currentLife;
	//CCPoint			_currentPoint;
};

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
	std::string			_defaultAniName;
	std::string			_defaultSpriteFrame;



};

#endif