#include "stdafx.h"

#include "Net/CListenSocket.h"
#include "Net/CSSocket.h"
#include "Net/GSSocket.h"
#include "Net/CParser.h"
#include <signal.h>


#include "../../new_common/Source/new_common.h"

#ifdef WIN32
#include "../Common/Platform/ServiceWin32.h"
extern int m_ServiceStatus;
#endif

zip_compress_strategy cs;

/// \todo Warning disabling not useful under VC++2005. Can somebody say on which compiler it is useful?
#pragma warning(disable:4305)

volatile bool CServer::m_stopEvent = false;
initialiseSingleton(CServer);
bool CServer::Init()
{
	MyLog::log->info( "Sunyou GT daemon %s", _FULLVERSION );
	MyLog::log->info( "<Ctrl-C> to stop.\n\n" );

	m_timers[UPDATE_RECONN].SetInterval(4000);
	m_timers[UPDATE_MSG].SetInterval(0);
	m_timers[UPDATE_DEBUG].SetInterval( 1*30*1000 );

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

	g_css = new CCSSocket;
#ifdef _WIN32
	net_global::init_net_service( 2, 5, &cs, true, 100 );
#else
	net_global::init_net_service( 32, 5, &cs, true, 9000 );
#endif

	//载入所有配置文件的信息
	if (!sGTConfig.Load())
	{
		return false;
	}
	m_nGroupID = sGTConfig.m_nGroupID;

#ifdef _WIN32
	if( !sCLS.create( sGTConfig.m_nGatePort, 50, 2 ) )
#else
	if( !sCLS.create( sGTConfig.m_nGatePort, sGTConfig.m_nPlayerLimit, 16 ) )
#endif
	{
		MyLog::log->error("Start Listen Client on port[%u]", sGTConfig.m_nGatePort);
		return false;
	}
	sCLS.set_limit_mode( true );
	MyLog::log->notice("Start Listen Client on port[%u]", sGTConfig.m_nGatePort);

	if(!ConnectCS()) return false;
	if(!ConnectDB()) return false;
	if(!ConnectGS()) return false;

	MyLog::log->info("========================Sunyou LS Init OK!========================");

	return true;
}
void CServer::Run()
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
				for( int i = 0; i < 4; ++i )
					g_gssocket[i]->run_no_wait();
				sCSSocket.run_no_wait();
				//sDBSocket.run_no_wait();
				sCLS.run_no_wait();
			}

			sCParser.m_nTimePass += realCurrTime - realPrevTime;
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

	Release();
}

void CServer::Release()
{
	///- Remove signal handling before leaving
	_UnhookSignals();

	for( int i = 0; i < 4; ++i )
		safe_delete( g_gssocket[i] );
	net_global::free_net_service();

	sCLS.stop();
	sCSSocket.close();
	//sDBSocket.close();
// 	delete &sCLS;
// 	delete &sCSSocket;
// 	delete &sDBSocket;

//	::WSACleanup();

	MyLog::log->info( "Halting process..." );

#ifdef WIN32
	if (Config.MainConfig.GetBoolDefault("","Console.Enable", true))
	{
		// this only way to terminate CLI thread exist at Win32 (alt. way exist only in Windows Vista API)
		//_exit(1);
		// send keyboard input to safely unblock the CLI thread
		INPUT_RECORD b[5];
		HANDLE hStdIn = GetStdHandle(STD_INPUT_HANDLE);
		b[0].EventType = KEY_EVENT;
		b[0].Event.KeyEvent.bKeyDown = TRUE;
		b[0].Event.KeyEvent.uChar.AsciiChar = 'X';
		b[0].Event.KeyEvent.wVirtualKeyCode = 'X';
		b[0].Event.KeyEvent.wRepeatCount = 1;

		b[1].EventType = KEY_EVENT;
		b[1].Event.KeyEvent.bKeyDown = FALSE;
		b[1].Event.KeyEvent.uChar.AsciiChar = 'X';
		b[1].Event.KeyEvent.wVirtualKeyCode = 'X';
		b[1].Event.KeyEvent.wRepeatCount = 1;

		b[2].EventType = KEY_EVENT;
		b[2].Event.KeyEvent.bKeyDown = TRUE;
		b[2].Event.KeyEvent.dwControlKeyState = 0;
		b[2].Event.KeyEvent.uChar.AsciiChar = '\r';
		b[2].Event.KeyEvent.wVirtualKeyCode = VK_RETURN;
		b[2].Event.KeyEvent.wRepeatCount = 1;
		b[2].Event.KeyEvent.wVirtualScanCode = 0x1c;

		b[3].EventType = KEY_EVENT;
		b[3].Event.KeyEvent.bKeyDown = FALSE;
		b[3].Event.KeyEvent.dwControlKeyState = 0;
		b[3].Event.KeyEvent.uChar.AsciiChar = '\r';
		b[3].Event.KeyEvent.wVirtualKeyCode = VK_RETURN;
		b[3].Event.KeyEvent.wVirtualScanCode = 0x1c;
		b[3].Event.KeyEvent.wRepeatCount = 1;
		DWORD numb;
		BOOL ret = WriteConsoleInput(hStdIn, b, 4, &numb);
	}
#endif
	exit(0);
}

/// Handle termination signals
/** Put the World::m_stopEvent to 'true' if a termination signal is caught **/
void CServer::_OnSignal(int s)
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
void CServer::_HookSignals()
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
void CServer::_UnhookSignals()
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

void OnCrash(bool Terminate)
{

}

bool CServer::ConnectCS()
{
	sCSSocket.connect(sGTConfig.m_CTIP.c_str(), sGTConfig.m_nCTPort);
	MyLog::log->notice("Connect : Connecting CenterServer[%s][%d]", sGTConfig.m_CTIP.c_str(), sGTConfig.m_nCTPort);
	return true;
}

bool CServer::ConnectDB()
{
	//sDBSocket.connect(sGTConfig.m_DBIP.c_str(), sGTConfig.m_nDBPort);
	MyLog::log->notice("Connect : Connecting DBServer[%s][%d]", sGTConfig.m_DBIP.c_str(), sGTConfig.m_nDBPort);
	return true;
}

bool CServer::ConnectGS()
{
	for( int i = 0; i < 4; ++i )
	{
		g_gssocket[i] = new CGSSocket;
		g_gssocket[i]->m_dwIndex = i;
		g_gssocket[i]->connect( sGTConfig.m_GMIP[0].c_str(), sGTConfig.m_nGMPort[0] );
	}
	MyLog::log->notice("Connect : Connecting GSServer[%s][%d]", sGTConfig.m_GMIP[0].c_str(), sGTConfig.m_nGMPort[0]);
	return true;
}

void CServer::OnConnectedCS(string strIP)
{
	MyLog::log->info("Connect CS[%s] ok!", strIP.c_str());
}
void CServer::OnConnectedDB(string strIP)
{
	MyLog::log->info("Connect DB[%s] ok!", strIP.c_str());
}
void CServer::OnConnectedGS(const char * strIP)
{
	MyLog::log->info("Connect GS[%s] ok! GroupID:%d sent to GS!!!", strIP, sGTConfig.m_nGroupID);
}
void CServer::OnDisconnectedGS(const char * strIP)
{
	MyLog::log->error("GS[%s] disconnect!", strIP);
}
void CServer::OnClientNum(int nNum)
{
	MyLog::log->notice("Player online[%d]\n", nNum);
}
