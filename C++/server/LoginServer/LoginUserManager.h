#pragma once
#ifndef LOGINUSERMANAGER_H
#define LOGINUSERMANAGER_H
#include <map>
#include "../../../Common/share/Singleton.h"
#include <boost/thread.hpp>
class CLoginUser;
enum enBindMail
{
	BindMail_OK,
	BindMail_Error_Unknown,
	BindMail_MailAlreadyBinded,
	BindMail_NotFoundAccount,
	BindMail_EmptyMac,
	BindMail_EmptyPassword,
	BindMail_EmptyMail,
};

class LoginUserManager : public Singleton<LoginUserManager>
{
public:
	LoginUserManager(void);
	virtual ~LoginUserManager(void);
	unsigned long lh_strhash(const char *str);
	bool isAlreadyLogin(unsigned long account);
	bool isAlreadyLogin(const char* mac);
	bool tryLoginOut(unsigned long account);
	enBindMail bindMail(unsigned long account, const char* mail, const char* password, const char* mac);
	unsigned long tryLogin(const char* mac);
	CLoginUser* GetLoginUser(const char* mac);
	CLoginUser* GetLoginUser(unsigned long account);

	
public:
	typedef std::map<unsigned long, CLoginUser*> MAPLOGINUSER;
	MAPLOGINUSER m_mapLoginUser;
	boost::mutex m_mutex;


};

#define  LUM LoginUserManager::getSingleton()

#endif