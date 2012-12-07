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

enBindMail LoginUserManager::bindMail(unsigned long account, const char* mail, const char* password, const char* mac)
{
	if (account == 0)
	{
		return BindMail_Error_Unknown;
	}
	if (is_empty_string(mail))
	{
		return BindMail_EmptyMail;
	}
	if (is_empty_string(password))
	{
		return BindMail_EmptyPassword;
	}
	if (is_empty_string(mac))
	{
		return BindMail_EmptyMac;
	}
	CLoginUser* pUser = NULL;
	enBindMail en = BindMail_Error_Unknown;
	{

		CLoginUser* pTempUser = NULL;
		boost::mutex::scoped_lock lock(m_mutex);
		MAPLOGINUSER::iterator it = m_mapLoginUser.begin();
		for (; it != m_mapLoginUser.end(); ++ it)
		{
			if (it->first == account)
			{
				pUser = it->second;
			}
			pTempUser = it->second;
			if (pTempUser->m_Info&&pTempUser->m_Info->mail.compare(mail)==0)
			{
				en = BindMail_MailAlreadyBinded;
				break;;
			}
		}
		if (en == BindMail_Error_Unknown)
		{
			pUser->m_Info->mac = mac;
			pUser->m_Info->mail = mail;
			pUser->m_Info->password = password;
		}

	}
	
	if (pUser&&pUser->m_Info&&en == BindMail_Error_Unknown)
	{
		if (CUserStorage::getSingleton().UpdateUser(pUser->m_Info->account))
		{
			en = BindMail_OK;
		}
	}
	
	return en;

}

unsigned long LoginUserManager::tryLogin(const char* mac)
{

	unsigned long account = lh_strhash(mac);
	tgUserInfo_t* info = CUserStorage::getSingleton().GetUserInfo(account);
	if (info == NULL)
	{
		info = new tgUserInfo_t();
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
			LoginUser->setInfo(info);
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