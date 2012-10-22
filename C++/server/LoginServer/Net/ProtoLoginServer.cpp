#include "StdAfx.h"
#include "ProtoLoginServer.h"
#include "MyLog.h"
#ifdef WIN32
extern int m_ServiceStatus;
#endif

CProtoLoginServer::CProtoLoginServer(void)
{
}


CProtoLoginServer::~CProtoLoginServer(void)
{
}

bool CProtoLoginServer::Init()
{
	MyLog::log->info( "Sunyou Login daemon %s", _FULLVERSION );
	MyLog::log->info( "<Ctrl-C> to stop.\n\n" );
	m_timers[UPDATE_RECONN].SetInterval(4000);
	m_timers[UPDATE_MSG].SetInterval(0);
	m_timers[UPDATE_DEBUG].SetInterval( 1*30*1000 );

	_HookSignals();

#ifdef WIN32
	if (Config.MainConfig.GetBoolDefault("","Console.Enable", true) && (m_ServiceStatus == -1)/* need disable console in service mode*/)
#else
	if (Config.MainConfig.GetBoolDefault("","Console.Enable", true))
#endif
		///- Handle affinity for multiple processors and process priority on Windows
#ifdef WIN32
	{
		HANDLE hProcess = GetCurrentProcess();

		uint32 Aff = Config.MainConfig.GetIntDefault("","UseProcessors", 0);
		if(Aff > 0)
		{
			ULONG_PTR appAff;
			ULONG_PTR sysAff;

			if(GetProcessAffinityMask(hProcess,&appAff,&sysAff))
			{
				ULONG_PTR curAff = Aff & appAff;            // remove non accessible processors

				if(!curAff )
				{
					MyLog::log->error("Processors marked in UseProcessors bitmask (hex) %x not accessible for sunyougt. Accessible processors bitmask (hex): %x",Aff,appAff);
				}
				else
				{
					if(SetProcessAffinityMask(hProcess,curAff))
						MyLog::log->info("Using processors (bitmask, hex): %x", curAff);
					else
						MyLog::log->error("Can't set used processors (hex): %x",curAff);
				}
			}
			MyLog::log->info("");
		}

		bool Prio = Config.MainConfig.GetBoolDefault("","ProcessPriority", false);

		//        if(Prio && (m_ServiceStatus == -1)/* need set to default process priority class in service mode*/)
		if(Prio)
		{
			if(SetPriorityClass(hProcess,HIGH_PRIORITY_CLASS))
				MyLog::log->info("sunyougt process priority class set to HIGH");
			else
				MyLog::log->error("ERROR: Can't set sunyougt process priority class.");
			MyLog::log->info("");
		}
	}
#endif

	// ≥ı ºªØWS2_32.dll
	//	WSADATA wsaData;
	//	WORD sockVersion = MAKEWORD(2, 2);

	//	::WSAStartup(sockVersion, &wsaData);

//	g_css = new CCSSocket;
//#ifdef _WIN32
//	net_global::init_net_service( 2, 5, &cs, true, 100 );
//#else
//	net_global::init_net_service( 32, 5, &cs, true, 9000 );
//#endif
//
}