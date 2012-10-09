#pragma once

using namespace std;
const int ReconnectEventID = 1;
const int ReconnectElapse = 2000;

enum
{
	UPDATE_RECONN = 0,
	UPDATE_MSG,
	UPDATE_DEBUG,
	UPDATE_COUNT,
};
class CServer : public Singleton<CServer>
{
public:
	bool Init();
	void Release();
	void Run();

	bool ConnectCS();
	bool ConnectDB();
	bool ConnectGS();

	void OnConnectedCS(string strIP);
	void OnConnectedDB(string strIP);
	void OnConnectedGS(const char * strIP);
	void OnDisconnectedGS(const char * strIP);
	void OnClientNum(int nNum);
public:

	void _HookSignals();
	void _UnhookSignals();
	static void _OnSignal(int s);

	void ProcessMsg();
	static volatile bool m_stopEvent;
	IntervalTimer m_timers[UPDATE_COUNT];

	int				m_nGroupID;
};
#define sServer CServer::getSingleton()
