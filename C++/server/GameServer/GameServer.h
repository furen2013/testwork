#pragma once
#ifndef GAMESERVER_H
#define GAMESERVER_H
#include "../../../Common/share/Singleton.h"
//#include "../../../Common/Platform/Timer.h"

class CGameServer : public Singleton<CGameServer>
{
public:
	enum
	{
		UPDATE_RECONN = 0,
		UPDATE_MSG,
		UPDATE_DEBUG,
		UPDATE_COUNT,
	};

public:
	CGameServer(void);
	~CGameServer(void);

public:
	bool Init();
	void Run();
	void _HookSignals();
	void _UnhookSignals();
	static void _OnSignal(int s);

protected:
	static volatile bool m_stopEvent;
	IntervalTimer m_timers[UPDATE_COUNT];
};

#define CGS CGameServer::getSingleton()
#endif