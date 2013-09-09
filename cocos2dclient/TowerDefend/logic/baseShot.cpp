#include "StdAfx.h"
#include "baseShot.h"
#include "ResourceManager/TDResourceManager.h"


baseShot::baseShot(void)
{
}


baseShot::~baseShot(void)
{
}


void baseShot::LoadResource(const char* config)
{
	_resourceName = config;
	TDResourceManager::getSingleton()->getAnimation()
}