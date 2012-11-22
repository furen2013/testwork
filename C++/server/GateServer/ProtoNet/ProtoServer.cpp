#include "StdAfx.h"
#include "ProtoServer.h"
#include <signal.h>
#include "MyNetGlobleObj.h"
#include "CListenProtoSocket.h"
#include "GProtoSocket.h"


#include "../../new_common/Source/new_common.h"

#ifdef WIN32
#include "../Common/Platform/ServiceWin32.h"
extern int m_ServiceStatus;
#endif

extern CGProtoSocket* p2LoginSocket;
volatile bool CProtoServer::m_stopEvent = false;
zip_compress_strategy impcs;
initialiseSingleton(CProtoServer);
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
	int HeadLen = sizeof(unsigned short);
	MyNetGlobleObj::InitMsg(HeadLen, 0);
//
//	//载入所有配置文件的信息
	//if (!sGTConfig.Load())
	//{
	//	return false;
	//}
//	m_nGroupID = sGTConfig.m_nGroupID;

#ifdef _WIN32
	if( !CCListenProtoSocket::getSingleton().create( 95501, 50, 2 ) )
#else
	if( !CCListenProtoSocket::getSingleton().create( 95501, sGTConfig.m_nPlayerLimit, 16 ) )
#endif
	{
		MyLog::log->error("Start Listen Client on port[%u]", 95501);
		return false;
	}
	CCListenProtoSocket::getSingleton().set_limit_mode( true );
	MyLog::log->notice("Start Listen Client on port[%u]", 95501);

	connectLG();

//	if(!ConnectCS()) return false;
//	if(!ConnectDB()) return false;
//	if(!ConnectGS()) return false;
//
//	MyLog::log->info("========================Sunyou LS Init OK!========================");

	return true;
}

void CProtoServer::Run()
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
		for(int i = 0; i < PROTO_UPDATE_COUNT; i++)
			if(m_timers[i].GetCurrent()>=0)
				m_timers[i].Update( realCurrTime - realPrevTime );
			else m_timers[i].SetCurrent(0);

			if (m_timers[PROTO_UPDATE_RECONN].Passed())
			{
				//重连
				m_timers[PROTO_UPDATE_RECONN].Reset();
			}

			if( m_timers[PROTO_UPDATE_MSG].Passed() )
			{
				m_timers[UPDATE_MSG].Reset();
				//for( int i = 0; i < 4; ++i )
				//	g_gssocket[i]->run_no_wait();
				//sCSSocket.run_no_wait();
				//sDBSocket.run_no_wait();
				CCListenProtoSocket::getSingleton().run_no_wait();
				if (p2LoginSocket != NULL)
				{
					p2LoginSocket->run_no_wait();
				}
				//sCLS.run_no_wait();
			}

			//sCParser.m_nTimePass += realCurrTime - realPrevTime;
			//sGSParser.m_nTimePass += realCurrTime - realPrevTime;
			if( m_timers[PROTO_UPDATE_DEBUG].Passed() )
			{
				m_timers[PROTO_UPDATE_DEBUG].Reset();
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

bool CProtoServer::connectLG()
{
	if (!p2LoginSocket)
	{
		p2LoginSocket = new CGProtoSocket(*MyNetGlobleObj::get_io_service());
		p2LoginSocket->setServerName("LoginServerName");
	}
	p2LoginSocket->connect("127.0.0.1", 95502);
	return true;
}