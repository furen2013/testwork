#pragma once
#ifndef BASESHOT_H
#define BASESHOT_H

#include "baseobj.h"
class baseShot :
	public baseObj
{
public:
	baseShot(void);
	virtual ~baseShot(void);

public:
	virtual void LoadResource(const char* config);
	


protected:
	float		 _dir;
	float		 _speed;
	std::string _resourceName;
	CCAction*			  _currentAction;
	CCAnimation*          _currentAnimation;
};

#endif