#pragma once
enum
{
	PROTO_UPDATE_RECONN = 0,
	PROTO_UPDATE_MSG,
	PROTO_UPDATE_DEBUG,
	PROTO_UPDATE_COUNT,
};

class CProtoServer
{
public:
	CProtoServer(void);
	~CProtoServer(void);


public:
	bool Init();
	void _HookSignals();
	void _UnhookSignals();
	static void _OnSignal(int s);

protected:
	static volatile bool m_stopEvent;
	IntervalTimer m_timers[PROTO_UPDATE_COUNT];
};

