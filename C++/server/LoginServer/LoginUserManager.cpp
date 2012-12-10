#include "StdAfx.h"
#include "LoginUserManager.h"
#include "UserStorage.h"
#include "LoginUser.h"
#include "ssl/MD5.h"
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

enBindResult LoginUserManager::UnbindMac(unsigned long account, const char* mail, const char* password, const char* mac)
{
	enBindResult en = checkBindArgument(account, mail, password, mac);
	if (en != BindResultOK)
	{
		return en;
	}
	CLoginUser* pUser = NULL;
	en = BindResultError_Unknown;
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
			//pTempUser = it->second;
			if (pUser)
			{
				if (pUser->m_Info)
				{
					en = checkUserInfo(pUser->m_Info, mail, password, mac);
					if (en == BindResultOK)
					{
						pUser->m_Info->mac.clear();
					}
				}

				break;
			}

		}

	}
	if (pUser != NULL && en == BindResultOK)
	{
		CUserStorage::getSingleton().UpdateMac(pUser->m_Info->account);
	}
	return en;
}

enBindResult LoginUserManager::bindMac(unsigned long account, const char* mail, const char* password, const char* mac)
{
	enBindResult en = checkBindArgument(account, mail, password, mac);
	if (en != BindResultOK)
	{
		return en;
	}
	CLoginUser* pUser = GetLoginUser(account);
	if (pUser)
	{
		if (pUser->m_Info)
		{
			if (pUser->m_Info->mac.empty())
			{
				en = checkUserInfo(pUser->m_Info, mail, password);
				if (en == BindResultOK)
				{
					pUser->m_Info->mac = mac;
					CUserStorage::getSingleton().UpdateMac(pUser->m_Info->account);
				}
			}
			else
			{
				en = BindResultMacAlreadyBinded;
			}
		}
		else
		{
			en = BindResultError_Unknown;
			MyLog::log->warn("bind mac not found user info account[%ld]", account);
		}
	}
	else
	{
		MyLog::log->warn("bind mac not found user account[%ld]", account);
		en = BindResultNotFoundAccount;
	}

	return en;
	
}
enBindResult LoginUserManager::checkUserInfo(tgUserInfo_t* pInfo, const char* mail, const char* password)
{
	if (pInfo->mail.compare(mail)!=0)
	{
		return BindResultEmptyMail;
	}
	else if (pInfo->password != MD5Hash::_make_md5_pwd(password))
	{
		return BindResultErrorPassword;
	}

	return BindResultOK;

}

enBindResult LoginUserManager::checkUserInfo(tgUserInfo_t* pInfo, const char* mail, const char* password, const char* mac)
{
	if (pInfo->mac.compare(mac)!=0)
	{
		return BindResultErrorMac;
	}
	return checkUserInfo(pInfo, mail, password);
}
enBindResult LoginUserManager::checkBindArgument(unsigned long account, const char* mail, const char* password, const char* mac)
{
	if (account == 0)
	{
		return BindResultError_Unknown;
	}
	if (is_empty_string(mail))
	{
		return BindResultEmptyMail;
	}
	if (is_empty_string(password))
	{
		return BindResultEmptyPassword;
	}
	if (is_empty_string(mac))
	{
		return BindResultEmptyMac;
	}
	return BindResultOK;
}

enBindResult LoginUserManager::bindMail(unsigned long account, const char* mail, const char* password, const char* mac)
{
	enBindResult en = checkBindArgument(account, mail, password, mac);
	if (en != BindResultOK)
	{
		return en;
	}

	CLoginUser* pUser = NULL;
	en = BindResultError_Unknown;
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
			if (pTempUser->m_Info)
			{
				if (pTempUser->m_Info->mail.compare(mail)==0)
				{
					en = BindResultMailAlreadyBinded;
				}
				if (pUser != pTempUser && pTempUser->m_Info->mac.compare(mac)==0)
				{
					en = BindResultMacAlreadyBinded;

				}
				break;;
			}
		}
		if (en == BindResultError_Unknown)
		{
			pUser->m_Info->mac = mac;
			pUser->m_Info->mail = mail;
			pUser->m_Info->password = MD5Hash::_make_md5_pwd(password);
		}

	}
	
	if (pUser&&pUser->m_Info&&en == BindResultError_Unknown)
	{
		if (CUserStorage::getSingleton().UpdateUser(pUser->m_Info->account))
		{
			en = BindResultOK;
		}
	}
	
	return en;

}

unsigned long LoginUserManager::tryLogin(const char* mac)
{
	char sz[512];
	unsigned long account = 0;
	tgUserInfo_t* info = CUserStorage::getSingleton().GetUserInfoByMac(mac);
	if (info == NULL)
	{
		printf(sz,"%s_%ui", mac,getMSTime());
		account = lh_strhash(sz);
		info = new tgUserInfo_t();
		info->account = account;
		info->mac = mac;
		CUserStorage::getSingleton().addUser(info);
	}
	account = info->account;
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