#include "StdAfx.h"
#include <signal.h>
#include "ProtoLoginServer.h"
#include "../../../../new_common/Source/log4cpp-1.0/MyLog.h"
#include "../../../../new_common/Source/compression/zlib/ZlibCompressionStrategy.h"
#include "../../../Common/Platform/SystemConfig.h"
#include "../../../Common/share/Config/Config.h"
#include "LoginGateListener.h"
#include "MyNetGlobleObj.h"
#ifdef WIN32
extern int m_ServiceStatus;
#endif
initialiseSingleton(CProtoLoginServer);
volatile bool CProtoLoginServer::m_stopEvent = false;
zip_compress_strategy impcs;
CProtoLoginServer::CProtoLoginServer(void)
{
}


CProtoLoginServer::~CProtoLoginServer(void)
{
}


void CProtoLoginServer::_HookSignals()
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

void CProtoLoginServer::_UnhookSignals()
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
void CProtoLoginServer::_OnSignal(int s)
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

void CProtoLoginServer::Run()
{
	MyLog::log->info("========================Sunyou Start!========================");
	uint32 realCurrTime, realPrevTime;
	realCurrTime = realPrevTime = getMSTime();

	///- Wait for termination signal
	while (!m_stopEvent)
	{
		if (realPrevTime > realCurrTime)
			realPrevTime = 0;

		realCurrTime = getMSTime();
		//if( UNIXTIME != realCurrTime )
		{
			UNIXTIME = time(NULL);
			g_localTime = *localtime(&UNIXTIME);
		}

#ifdef WIN32
		if (m_ServiceStatus == 0) m_stopEvent = true;
		while (m_ServiceStatus == 2) Sleep(1000);
#endif
		///- Update the different timers
		for(int i = 0; i < UPDATE_COUNT; i++)
			if(m_timers[i].GetCurrent()>=0)
				m_timers[i].Update( realCurrTime - realPrevTime );
			else m_timers[i].SetCurrent(0);

			if (m_timers[UPDATE_RECONN].Passed())
			{
				//重连
				m_timers[UPDATE_RECONN].Reset();
			}

			if( m_timers[UPDATE_MSG].Passed() )
			{
				m_timers[UPDATE_MSG].Reset();
				//for( int i = 0; i < 4; ++i )
				//	g_gssocket[i]->run_no_wait();
				//sCSSocket.run_no_wait();
				//sDBSocket.run_no_wait();
				LGLISTENER.run_no_wait();
				//sCLS.run_no_wait();
			}

			//sCParser.m_nTimePass += realCurrTime - realPrevTime;
			//sGSParser.m_nTimePass += realCurrTime - realPrevTime;
			if( m_timers[UPDATE_DEBUG].Passed() )
			{
				m_timers[UPDATE_DEBUG].Reset();
				if( g_fpLogConnection )
					fflush( g_fpLogConnection );
				//MyLog::log->debug("Recv C MsgSize[%d]..............SizePerS[%2d%]\n       Recv GS MsgSize[%d]..............SizePerS[%2d%]", sCParser.m_nMsgSize, sCParser.m_nMsgSize*1000/sCParser.m_nTimePass, sGSParser.m_nMsgSize, sGSParser.m_nMsgSize*1000/sGSParser.m_nTimePass);

				//MyLog::log->notice( "asio thread alive count = %d", get_asio_thread_alive_count() );
			}
			realCurrTime = getMSTime();

			if( realCurrTime - realPrevTime < 5/*sGTConfig.m_nFrameTick*/ )
			{
				Sleep( 5/*sGTConfig.m_nFrameTick*/ + realPrevTime - realCurrTime );
			}

			realPrevTime = realCurrTime;
	}

	MyLog::log->info("========================Sunyou Stop!========================");
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

	// 初始化WS2_32.dll
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

#ifdef _WIN32
	MyNetGlobleObj::init_net_service( 2, 5, &impcs, true, 100 );
#else
	MyNetGlobleObj::init_net_service( 32, 5, &impcs, true, 9000 );
#endif
	int HeadLen = sizeof(unsigned short);
	MyNetGlobleObj::InitMsg(HeadLen, 0);



#ifdef _WIN32
	if( !LGLISTENER.create( 95502, 50, 2 ) )
#else
	if( !LGLISTENER.create( 95502, sGTConfig.m_nPlayerLimit, 16 ) )
#endif
	{
		MyLog::log->error("Start Listen Client on port[%u]", 95502);
		return false;
	}
	LGLISTENER.set_limit_mode( true );
	MyLog::log->notice("Start Listen Client on port[%u]", 95502);


	return true;
}

