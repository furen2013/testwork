#include "stdafx.h"
#include <signal.h>

#include "Net/GTListenSocket.h"
#include "Net/GSListenSocket.h"
#include "DataInterface.h"

#include "../../new_common/Source/new_common.h"
#include <mysql/mysql.h>

#ifdef WIN32
#include "../Common/Platform/ServiceWin32.h"
extern int m_ServiceStatus;
#endif

zip_compress_strategy cs;


/// \todo Warning disabling not useful under VC++2005. Can somebody say on which compiler it is useful?
#pragma warning(disable:4305)
// Database defines.
SERVER_DECL Database* Database_Character;
SERVER_DECL Database* Database_World;

volatile bool CServer::m_stopEvent = false;

initialiseSingleton(CServer);
bool CServer::Init()
{
	MyLog::log->info( "Sunyou DB daemon %s", _FULLVERSION );
	MyLog::log->info( "<Ctrl-C> to stop.\n\n" );

	m_timers[UPDATE_RECONN].SetInterval(1000);
	m_timers[UPDATE_MSG].SetInterval(200);

	///- Catch termination signals
	_HookSignals();

#ifdef WIN32
	if (Config.MainConfig.GetBoolDefault("", "Console.Enable", true) && (m_ServiceStatus == -1)/* need disable console in service mode*/)
#else
	if (Config.MainConfig.GetBoolDefault("", "Console.Enable", true))
#endif
		///- Handle affinity for multiple processors and process priority on Windows
#ifdef WIN32
	{
		HANDLE hProcess = GetCurrentProcess();

		uint32 Aff = Config.MainConfig.GetIntDefault("", "UseProcessors", 0);
		if(Aff > 0)
		{
			ULONG_PTR appAff;
			ULONG_PTR sysAff;

			if(GetProcessAffinityMask(hProcess,&appAff,&sysAff))
			{
				ULONG_PTR curAff = Aff & appAff;            // remove non accessible processors

				if(!curAff )
				{
					MyLog::log->error("Processors marked in UseProcessors bitmask (hex) %x not accessible for mangosd. Accessible processors bitmask (hex): %x",Aff,appAff);
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

		bool Prio = Config.MainConfig.GetBoolDefault("", "ProcessPriority", false);

		//        if(Prio && (m_ServiceStatus == -1)/* need set to default process priority class in service mode*/)
		if(Prio)
		{
			if(SetPriorityClass(hProcess,HIGH_PRIORITY_CLASS))
				MyLog::log->info("mangosd process priority class set to HIGH");
			else
				MyLog::log->error("ERROR: Can't set mangosd process priority class.");
			MyLog::log->info("");
		}
	}
#endif

	// 初始化WS2_32.dll
//	WSADATA wsaData;
//	WORD sockVersion = MAKEWORD(2, 2);
//	::WSAStartup(sockVersion, &wsaData);
#ifdef _WIN32
	net_global::init_net_service( 4, 2, &cs, true, 100 );
#else
	net_global::init_net_service( 4, 2, &cs, true, 1024 );
#endif

	//载入所有配置文件的信息
	if(!CConfig::Init())
	{
		MyLog::log->error("DB Server启动失败：CConfig::Init()");
		return false;
	}
	MyLog::log->info("CConfig::Init() ok!");

	if( !_StartDB() )
	{
		return false;
	}

	MyLog::log->info("Load PlayerCreateInfo... ");
	sWorldInfo.LoadPlayerCreateInfo();

	if(!MySqlAccess::Init())
	{
		MyLog::log->error("DB Server启动失败：MySqlAccess::Init()");
		return false;
	}

	//程序版本号获取并显示
//	CModuleVersion ver;

//	if(!CIOCPManager::Init())
//	{
//		MyLog::log->error("DB Server启动失败：CIOCPManager::Init()");
//		return FALSE;
//	}
//	MyLog::log->info("CIOCPManager::Init() ok!");

	if( !sGTLS.create( CConfig::m_wListenGTPort, 15, 2 ) )
	{
		MyLog::log->error("DB Server启动失败：sGTLS.Start");
		return FALSE;
	}
	MyLog::log->info("sGTLS::Start() on port[%u]ok!", CConfig::m_wListenGTPort);

	if( !sGSLS.create(CConfig::m_wListenGSPort, 15, 2 ) )
	{
		MyLog::log->error("DB Server启动失败：sGSLS.Start");
		return FALSE;
	}
	MyLog::log->info("sGSLS::Start() on port[%u]ok!", CConfig::m_wListenGSPort);

	unsigned int mysqlthreadsafe = mysql_thread_safe();
	if( !mysqlthreadsafe )
		MyLog::log->error( "mysql lib is not a thread safe mode!!!!!!!!!" );
	Database::StartThread();
	MyLog::log->notice( "database thread has been started...\n" );

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
		UNIXTIME = time(NULL);
		g_localTime = *localtime(&UNIXTIME);

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
				m_timers[UPDATE_RECONN].Reset();
			}

			if( m_timers[UPDATE_MSG].Passed() )
			{
				m_timers[UPDATE_MSG].Reset();
				sGSLS.run();
				sGTLS.run();
			}
			CharacterDatabase.QueryTaskRun();

			realCurrTime = getMSTime();

			if( realCurrTime - realPrevTime < CConfig::m_nFrameTick )
			{
				Sleep( CConfig::m_nFrameTick + realPrevTime - realCurrTime );
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

	sGSLS.stop();
	sGTLS.stop();
	sAccountMgr.Destroy();

	_StopDB();
	net_global::free_net_service();
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


bool CServer::_StartDB()
{
	string hostname, username, password, database;
	int port = 0;
	int type = 1;
	//string lhostname, lusername, lpassword, ldatabase;
	//int lport = 0;
	//int ltype = 1;
	// Configure Main Database
	bool result = Config.MainConfig.GetString( "WorldDatabase", "Username", &username );
	Config.MainConfig.GetString( "WorldDatabase", "Password", &password );
	result = !result ? result : Config.MainConfig.GetString( "WorldDatabase", "Hostname", &hostname );
	result = !result ? result : Config.MainConfig.GetString( "WorldDatabase", "Name", &database );
	result = !result ? result : Config.MainConfig.GetInt( "WorldDatabase", "Port", &port );
	result = !result ? result : Config.MainConfig.GetInt( "WorldDatabase", "Type", &type );
	Database_World = Database::CreateDatabaseInterface(type);

	if(result == false)
	{
		MyLog::log->error("sql","One or more parameters were missing from WorldDatabase directive.");
		return false;
	}

	// Initialize it
	if( !WorldDatabase.Initialize(hostname.c_str(), (unsigned int)port, username.c_str(),
		password.c_str(), database.c_str(), Config.MainConfig.GetIntDefault( "WorldDatabase", "ConnectionCount", 3 ), 16384 ) )
	{
		MyLog::log->error("sql : Main database initialization failed. Exiting.");
		return false;
	}


	result = Config.MainConfig.GetString( "CharacterDatabase", "Username", &username );
	Config.MainConfig.GetString( "CharacterDatabase", "Password", &password );
	result = !result ? result : Config.MainConfig.GetString( "CharacterDatabase", "Hostname", &hostname );
	result = !result ? result : Config.MainConfig.GetString( "CharacterDatabase", "Name", &database );
	result = !result ? result : Config.MainConfig.GetInt( "CharacterDatabase", "Port", &port );
	result = !result ? result : Config.MainConfig.GetInt( "CharacterDatabase", "Type", &type );
	Database_Character = Database::CreateDatabaseInterface(type);

	if(result == false)
	{
		MyLog::log->error("sql : One or more parameters were missing from Database directive.");
		return false;
	}

	// Initialize it
	if( !CharacterDatabase.Initialize( hostname.c_str(), (unsigned int)port, username.c_str(),
		password.c_str(), database.c_str(), Config.MainConfig.GetIntDefault( "CharacterDatabase", "ConnectionCount", 5 ), 16384 ) )
	{
		MyLog::log->error("sql : Main database initialization failed. Exiting.");
		return false;
	}

	return true;
}

void CServer::_StopDB()
{
	delete Database_Character;
	delete Database_World;
}
