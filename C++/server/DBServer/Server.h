#ifndef SERVER_H
#define SERVER_H

enum
{
	UPDATE_RECONN = 0,
	UPDATE_MSG,
	UPDATE_COUNT,
};
class CServer : public Singleton<CServer>
{
public:
	bool Init();
	void Release();
	void Run();
	void Shundown();

	bool _StartDB();
	void _StopDB();
private:
	void _HookSignals();
	void _UnhookSignals();
	static void _OnSignal(int s);

	void ProcessMsg();
	static volatile bool m_stopEvent;
	IntervalTimer m_timers[UPDATE_COUNT];
};
#define sServer CServer::getSingleton()

#endif