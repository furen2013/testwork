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
	unsigned long lh_strhash(const char *str);
	bool isAlreadyLogin(unsigned long account);
	bool tryLoginOut(unsigned long account);
	unsigned long tryLogin(const char* mac);

	
public:
	typedef std::map<unsigned long, CLoginUser*> MAPLOGINUSER;
	MAPLOGINUSER m_mapLoginUser;
	boost::mutex m_mutex;


};

#define  LUM LoginUserManager::getSingleton()

#endif