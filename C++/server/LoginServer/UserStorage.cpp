#include "StdAfx.h"
#include "UserStorage.h"
#include "share/Database/Database.h"

Database* phoneDatabase = NULL; 
initialiseSingleton(CUserStorage);
CUserStorage::CUserStorage(void)
{
	Init();
}


CUserStorage::~CUserStorage(void)
{
}

bool CUserStorage::Init()
{
	phoneDatabase = Database::CreateDatabaseInterface(1);
	if (!phoneDatabase->Initialize("127.0.0.1", 3306, "root", "7283933", "phone", 5, 16384))
	{
		MyLog::log->error("Login Server can not connect mysql");
		return false;
	}
	LoadAll();
	return true;
}

bool CUserStorage::UpdateMac(long account)
{
	tgUserInfo_t* p = NULL;
	bool breturn = false;
	{

		boost::mutex::scoped_lock lock(m_mutex);
		std::map<long, tgUserInfo_t*>::iterator it = m_storageUser.find(account);
		if (it != m_storageUser.end())
		{
			p = it->second;
			breturn = true;
		}
	}
	if(breturn == true&&p)
	{
		phoneDatabase->WaitExecute( "update account set mac='%s' where account=ld%",p->mac.c_str(),p->account );
	}
	return breturn;
}

bool CUserStorage::UpdateUser(long account)
{
	tgUserInfo_t* p = NULL;
	bool breturn = false;
	{
		
		boost::mutex::scoped_lock lock(m_mutex);
		std::map<long, tgUserInfo_t*>::iterator it = m_storageUser.find(account);
		if (it != m_storageUser.end())
		{
			p = it->second;
			breturn = true;
		}
	}
	if(breturn == true&&p)
	{
		phoneDatabase->WaitExecute( "update account set mac='%s',Password='%s',Mail='%s' where account=ld%",p->mac.c_str(),
			p->password.c_str(), p->mail.c_str(),p->account );
	}
	return breturn;

}

void CUserStorage::addUser(tgUserInfo_t* p)
{
	if(p->mac.empty() || p->account == 0)
	{
		return;
	}
	bool b = true;
	{
		
		boost::mutex::scoped_lock lock(m_mutex);
		std::map<long, tgUserInfo_t*>::iterator it = m_storageUser.begin();
		for (; it != m_storageUser.end(); ++ it)
		{
			tgUserInfo_t* temp = it->second;
			if (temp->account == p->account || temp->mac == p->mac || (temp->mail.empty()&&p->mail == temp->mail))
			{
				b = false;
				break;
			}
		}

		if (b)
		{
			m_storageUser.insert(std::map<long, tgUserInfo_t*>::value_type(p->account, p));

			phoneDatabase->WaitExecute( "insert into `account` (`account`, `mac`, `Password`, `Mail`) values('%ld', '%s', '%s', '%s')", 
				p->account, p->mac.c_str()
				, p->password.c_str(), p->mail.c_str() );

		}
		
	}

}

void CUserStorage::Clear()
{
	boost::mutex::scoped_lock lock(m_mutex);
	std::map<long, tgUserInfo_t*>::iterator it = m_storageUser.begin();
	for (; it != m_storageUser.end(); ++ it)
	{
		delete it->second;

	}

	m_storageUser.clear();
}

tgUserInfo_t* CUserStorage::GetUserInfoByMail(const char* Mail)
{
	tgUserInfo_t* pTemp = NULL;
	{
		boost::mutex::scoped_lock lock(m_mutex);
		std::map<long, tgUserInfo_t*>::iterator it = m_storageUser.begin();
		for (; it != m_storageUser.end(); ++ it)
		{
			tgUserInfo_t* p = it->second;
			if (p->mail.compare(Mail)==0)
			{
				pTemp = p;
				break;
			}
		}

	}

	return pTemp;
}

tgUserInfo_t* CUserStorage::GetUserInfoByMac(const char* szMac)
{
	tgUserInfo_t* pTemp = NULL;
	{
		boost::mutex::scoped_lock lock(m_mutex);
		std::map<long, tgUserInfo_t*>::iterator it = m_storageUser.begin();
		for (; it != m_storageUser.end(); ++ it)
		{
			tgUserInfo_t* p = it->second;
			if (p->mac.compare(szMac)==0)
			{
				pTemp = p;
				break;
			}
		}
	}


	return pTemp;
}

tgUserInfo_t* CUserStorage::GetUserInfo(long account)
{
	boost::mutex::scoped_lock lock(m_mutex);
	std::map<long, tgUserInfo_t*>::iterator it = m_storageUser.find(account);
	if (it != m_storageUser.end())
	{
		return it->second;
	}
	return NULL;
}


void CUserStorage::LoadAll()
{
	Clear();
	boost::mutex::scoped_lock lock(m_mutex);
	QueryResult* qr = phoneDatabase->Query( "select * from account" );
	if( qr )
	{
		do
		{
			Field* f = qr->Fetch();
			tgUserInfo_t* p = new tgUserInfo_t;
			p->account = f[0].GetUInt64();
			p->mac = f[1].GetString();
			p->password = f[2].GetString();
			p->mail = f[3].GetString();
			m_storageUser.insert(std::map<long, tgUserInfo_t*>::value_type(p->account,p));
		}
		while( qr->NextRow() );

		delete qr;
	}

}