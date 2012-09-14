#pragma once

#include <map>
#include <boost/thread.hpp>

class CCSocket;

typedef std::map<DWORD, CCSocket*> MAP_C;
typedef MAP_C::iterator MAP_C_ITER;
class CUserManager : public Singleton<CUserManager>
{
public:
	CUserManager(void);
	~CUserManager(void){}

	CCSocket * GetClient(DWORD dwKey);
	CCSocket* GetClientByTransID( uint32 transid );
	void DeleteClient(CCSocket * pClient);
	void InsertClient(CCSocket * pClient);

	CCSocket * GetLoginClient(DWORD dwKey);
	void DeleteLoginClient(CCSocket * pClient);
	void InsertLoginClient(DWORD dwKey, CCSocket * pClient);

	CCSocket * GetFirstClient();
	CCSocket * GetNextClient();

private:
	MAP_C			m_mapClient;
	MAP_C_ITER	m_itrClient;
	MAP_C	m_mapLoginClient;
	boost::mutex m_mutex;
};
#define sUserMgr CUserManager::getSingleton()
