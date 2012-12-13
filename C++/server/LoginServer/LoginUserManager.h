#pragma once
#ifndef LOGINUSERMANAGER_H
#define LOGINUSERMANAGER_H
#include <map>
#include "../../../Common/share/Singleton.h"
#include <boost/thread.hpp>
class CLoginUser;
enum enBindResult
{
	BindResultOK,
	BindResultError_Unknown,
	BindResultMailAlreadyBinded,
	BindResultMacAlreadyBinded,
	BindResultNotFoundAccount,
	BindResultEmptyMac,
	BindResultEmptyPassword,
	BindResultEmptyMail,
	BindResultErrorPassword,
	BindResultErrorMac,
	BindResultErrorMail,
	BindResultNotFoundUser,
};

struct tgUserInfo_t;

enum enLoginMailResult
{	
	LoginMailResult_OK,
	LoginMailResult_EmptyMail,
	LoginMailResult_EmptryPassword,
	LoginMailResult_NotFoundMail,
	LoginMailResult_ErrorPassword,
	LoginMailResult_ErrorAlreadyLogin,
};
struct tgLoginMail
{
	enLoginMailResult en;
	unsigned long account;
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
	tgLoginMail tryLogin(const char* mail, const char* password);
	enBindResult bindMail(unsigned long account, const char* mail, const char* password, const char* mac);
	enBindResult UnbindMac(unsigned long account, const char* mail, const char* password, const char* mac);
	enBindResult bindMac(unsigned long account, const char* mail, const char* password, const char* mac);
	unsigned long tryLogin(const char* mac);
	CLoginUser* GetLoginUser(const char* mac);
	CLoginUser* GetLoginUser(unsigned long account);

private:
	enBindResult checkBindArgument(unsigned long account, const char* mail, const char* password, const char* mac);
	enBindResult checkUserInfo(tgUserInfo_t* pInfo, const char* mail, const char* password, const char* mac);
	enBindResult checkUserInfo(tgUserInfo_t* pInfo, const char* mail, const char* password);
	
public:
	typedef std::map<unsigned long, CLoginUser*> MAPLOGINUSER;
	MAPLOGINUSER m_mapLoginUser;
	boost::mutex m_mutex;


};

#define  LUM LoginUserManager::getSingleton()

#endif