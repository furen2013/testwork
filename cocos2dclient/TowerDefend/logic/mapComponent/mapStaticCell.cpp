#include "StdAfx.h"
#include "mapStaticCell.h"
#include "../ResourceManager/TDResourceManager.h"


mapStaticCell::mapStaticCell(void)
{
}


mapStaticCell::~mapStaticCell(void)
{
}


void mapStaticCell::LoadResource(const char* config)
{
	baseMapCell::LoadResource(config);

	_currentPoint = _createPos;
	//_resourseName = config;
	CCAnimation* animation = TDResourceManager::getSingletonPtr()->getAnimation(config);
	if (animation)
	{
		_actionInterval = CCRepeat::create(CCAnimate::create(animation), 111);
		_currentSprite =  CCSprite::create();
		_currentSprite->setPosition(_currentPoint);
		addChild(_currentSprite);
	}
}


void mapStaticCell::onAddToWorld()
{
	baseMapCell::onAddToWorld();
	_currentSprite->setPosition(_currentPoint);
	_currentSprite->runAction(_actionInterval);
}


void mapStaticCell::setPosition(float x, float y)
{
	baseMapCell::setPosition(x, y);
	_currentSprite->setPosition(_currentPoint);
}