#ifndef __CC_TOWERDEFENDAPP_WIN32_H__
#define __CC_TOWERDEFENDAPP_WIN32_H__

#include <Windows.h>
#include "platform/CCCommon.h"
#include "platform/CCApplicationProtocol.h"
#include <string>

NS_CC_BEGIN

class CCRect;

class  TowerDefendApp : public CCApplicationProtocol
{
public:
    TowerDefendApp();
    virtual ~TowerDefendApp();

    /**
    @brief    Run the message loop.
    */
    int run();

    /**
    @brief    Get current applicaiton instance.
    @return Current application instance pointer.
    */
    static TowerDefendApp* sharedApplication();

    /* override functions */
    virtual void setAnimationInterval(double interval);
    virtual ccLanguageType getCurrentLanguage();
    
    /**
     @brief Get target platform
     */
    virtual TargetPlatform getTargetPlatform();

    /* set the Resource root path */
    void setResourceRootPath(const std::string& rootResDir);

    /* get the Resource root path */
    const std::string& getResourceRootPath(void)
    {
        return m_resourceRootPath;
    }

    void setStartupScriptFilename(const std::string& startupScriptFile);

    const std::string& getStartupScriptFilename(void)
    {
        return m_startupScriptFilename;
    }

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
protected:
    HINSTANCE           m_hInstance;
    HACCEL              m_hAccelTable;
    LARGE_INTEGER       m_nAnimationInterval;
    std::string         m_resourceRootPath;
    std::string         m_startupScriptFilename;

    static TowerDefendApp * sm_pSharedApplication;
};

NS_CC_END

#endif    // __CC_APPLICATION_WIN32_H__
