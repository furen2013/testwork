#include "StdAfx.h"
#include "LoginUserManager.h"
#include "UserStorage.h"
#include "LoginUser.h"
initialiseSingleton(LoginUserManager);

LoginUserManager::LoginUserManager(void)
{
}


LoginUserManager::~LoginUserManager(void)
{
}

bool LoginUserManager::isAlreadyLogin(const char* mac)
{
	unsigned long account = lh_strhash(mac);
	return isAlreadyLogin(account);
}

bool LoginUserManager::isAlreadyLogin(unsigned long account)
{
	boost::mutex::scoped_lock lock(m_mutex);
	MAPLOGINUSER::iterator it = m_mapLoginUser.find(account);
	if (it != m_mapLoginUser.end())
	{
		return true;
	}
	return false;

}


bool LoginUserManager::tryLoginOut(unsigned long account)
{

	boost::mutex::scoped_lock lock(m_mutex);
	MAPLOGINUSER::iterator it = m_mapLoginUser.find(account);
	if (it != m_mapLoginUser.end())
	{
		delete it->second;
		m_mapLoginUser.erase(it);
		return true;
	}
	return false;
}

CLoginUser* LoginUserManager::GetLoginUser(unsigned long account)
{
	CLoginUser* p = NULL;
	{
		boost::mutex::scoped_lock lock(m_mutex);

		MAPLOGINUSER::iterator it = m_mapLoginUser.find(account);
		if (it != m_mapLoginUser.end())
		{
			p = it->second;
		}
	}
	return p;
}

CLoginUser* LoginUserManager::GetLoginUser(const char* mac)
{
	unsigned long account = lh_strhash(mac);
	return GetLoginUser(account);
}

unsigned long LoginUserManager::tryLogin(const char* mac)
{

	unsigned long account = lh_strhash(mac);
	if (CUserStorage::getSingleton().GetUserInfo(account) == NULL)
	{
		tgUserInfo_t* info = new tgUserInfo_t();
		info->account = account;
		info->mac = mac;
		CUserStorage::getSingleton().addUser(info);
	}
	bool b = false;
	{
		boost::mutex::scoped_lock lock(m_mutex);
		MAPLOGINUSER::iterator it = m_mapLoginUser.find(account);
		if (it == m_mapLoginUser.end())
		{
			b = true;
			CLoginUser* LoginUser = new CLoginUser();
			LoginUser->setmac(mac);
			LoginUser->setAccount(account);
			m_mapLoginUser.insert(MAPLOGINUSER::value_type(account, LoginUser));

		}
	}
	if (b)
	{
		return account;
	}
	return 0;
}
unsigned long LoginUserManager::lh_strhash(const char *c)
{
	unsigned long ret=0; 
	long n; 
	unsigned long v; 
	int r; 

	if ((c == NULL) || (*c == '\0')) 
		return(ret); 
	/* 
	unsigned char b[16]; 
	MD5(c,strlen(c),b); 
	return(b[0]|(b[1]<<|(b[2]<<16)|(b[3]<<24)); 
	*/ 

	n=0x100; 
	while (*c) 
	{ 
		v=n|(*c); 
		n+=0x100; 
		r= (int)((v>>2)^v)&0x0f; 
		ret=32 - r;//ret=(ret(32-r)); 
		ret&=0xFFFFFFFFL; 
		ret^=v*v; 
		c++; 
	} 
	return((ret>>16)^ret); 

}