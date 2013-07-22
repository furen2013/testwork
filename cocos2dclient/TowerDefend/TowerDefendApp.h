#pragma once
#ifndef __CC_TOWERDEFENDAPP_WIN32_H__
#define __CC_TOWERDEFENDAPP_WIN32_H__

//#include "cocos2d.h"

/**
@brief    The cocos2d Application.

The reason for implement as private inheritance is to hide some interface call by CCDirector.
*/
class  TowerDefendApp : private cocos2d::CCApplication
{
public:
    TowerDefendApp();
    virtual ~TowerDefendApp();

    /**
    @brief    Implement CCDirector and CCScene init code here.
    @return true    Initialize success, app continue.
    @return false   Initialize failed, app terminate.
    */
    virtual bool applicationDidFinishLaunching();

    /**
    @brief  The function be called when the application enter background
    @param  the pointer of the application
    */
    virtual void applicationDidEnterBackground();

    /**
    @brief  The function be called when the application enter foreground
    @param  the pointer of the application
    */
    virtual void applicationWillEnterForeground();
};

#endif    // __CC_APPLICATION_WIN32_H__
