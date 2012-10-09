#include "StdAfx.h"
#include "ProtoServer.h"
#include <signal.h>
#include "MyNetGlobleObj.h"


#include "../../new_common/Source/new_common.h"

#ifdef WIN32
#include "../Common/Platform/ServiceWin32.h"
extern int m_ServiceStatus;
#endif
volatile bool CProtoServer::m_stopEvent = false;
zip_compress_strategy impcs;
CProtoServer::CProtoServer(void)
{
}


CProtoServer::~CProtoServer(void)
{
}

bool CProtoServer::Init()
{

	MyLog::log->info( "my GT daemon %s", _FULLVERSION );
	MyLog::log->info( "<Ctrl-C> to stop.\n\n" );

	m_timers[PROTO_UPDATE_RECONN].SetInterval(4000);
	m_timers[PROTO_UPDATE_MSG].SetInterval(0);
	m_timers[PROTO_UPDATE_DEBUG].SetInterval( 1*30*1000 );

	///- Catch termination signals
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

	// 初始化WS2_32.dll
	//	WSADATA wsaData;
	//	WORD sockVersion = MAKEWORD(2, 2);

	//	::WSAStartup(sockVersion, &wsaData);

	//g_css = new CCSSocket;
#ifdef _WIN32
	MyNetGlobleObj::init_net_service( 2, 5, &impcs, true, 100 );
#else
	MyNetGlobleObj::init_net_service( 32, 5, &impcs, true, 9000 );
#endif
//
//	//载入所有配置文件的信息
//	if (!sGTConfig.Load())
//	{
//		return false;
//	}
//	m_nGroupID = sGTConfig.m_nGroupID;
//
//#ifdef _WIN32
//	if( !sCLS.create( sGTConfig.m_nGatePort, 50, 2 ) )
//#else
//	if( !sCLS.create( sGTConfig.m_nGatePort, sGTConfig.m_nPlayerLimit, 16 ) )
//#endif
//	{
//		MyLog::log->error("Start Listen Client on port[%u]", sGTConfig.m_nGatePort);
//		return false;
//	}
//	sCLS.set_limit_mode( true );
//	MyLog::log->notice("Start Listen Client on port[%u]", sGTConfig.m_nGatePort);
//
//	if(!ConnectCS()) return false;
//	if(!ConnectDB()) return false;
//	if(!ConnectGS()) return false;
//
//	MyLog::log->info("========================Sunyou LS Init OK!========================");

	return true;
}

void CProtoServer::_OnSignal(int s)
{
	switch (s)
	{
	case SIGINT:
	case SIGTERM:
	case SIGABRT:
#ifdef _WIN32
	case SIGBREAK:
#else
	case SIGQUIT:
#endif
		m_stopEvent = true;
		break;
	}

	signal(s, _OnSignal);
}

/// Define hook '_OnSignal' for all termination signals
void CProtoServer::_HookSignals()
{
	signal(SIGINT, _OnSignal);
	signal(SIGTERM, _OnSignal);
	signal(SIGABRT, _OnSignal);
#ifdef _WIN32
	signal(SIGBREAK, _OnSignal);
#else
	signal(SIGQUIT, _OnSignal);
#endif
}

/// Unhook the signals before leaving
void CProtoServer::_UnhookSignals()
{
	signal(SIGINT, 0);
	signal(SIGTERM, 0);
	signal(SIGABRT, 0);
#ifdef _WIN32
	signal(SIGBREAK, 0);
#else
	signal(SIGQUIT, 0);
#endif
}