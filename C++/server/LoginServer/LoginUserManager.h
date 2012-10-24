#pragma once
#ifndef LOGINUSERMANAGER_H
#define LOGINUSERMANAGER_H
#include <map>
#include "../../../Common/share/Singleton.h"
#include <boost/thread.hpp>
class CLoginUser;

class LoginUserManager : public Singleton<LoginUserManager>
{
public:
	LoginUserManager(void);
	virtual ~LoginUserManager(void);
	unsigned long lh_strhash(char *str); 
	
public:
	std::map<unsigned long, CLoginUser*> m_mapLoginUser;


};

#define  LUM LoginUserManager::getSingleton()

#endif