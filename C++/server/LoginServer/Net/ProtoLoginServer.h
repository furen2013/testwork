#pragma once
#ifndef PROTOLOGINSERVER_H
#define PROTOLOGINSERVER_H
#include "../../../Common/share/Singleton.h"
//#include "../../../Common/Platform/Timer.h"

class CProtoLoginServer : public Singleton<CProtoLoginServer>
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
	CProtoLoginServer(void);
	~CProtoLoginServer(void);

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

#define CLGSERVER CProtoLoginServer::getSingleton()
#endif