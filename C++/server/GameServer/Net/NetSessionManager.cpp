#include "stdafx.h"
#include "NetSessionManager.h"
initialiseSingleton(NetSessionManager);
NetSessionManager::NetSessionManager()
{

}

NetSessionManager::~NetSessionManager()
{

}

NetSession* NetSessionManager::FindSession(DWORD account)
{
	NetSession* pSession = NULL;
	mapsession::iterator it = _sessions.find(account);
	if (it != _sessions.end())
	{
		pSession = it->second;
	}

	return pSession;
}