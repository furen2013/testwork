// LoginServer.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "iostream"
#include "../../../MsgShard/MsgHead.pb.h"
#include "../../../new_common/Source/log4cpp-1.0/MyLog.h"
#include "../../Common/share/Config/Config.h"
//#include "ProtoNet/CListenProtoSocket.h"
//#include "ProtoNet/ProtoServer.h"
#ifdef WIN32
#include "../Common/Platform/ServiceWin32.h"
char serviceName[] = "phone GS";
char serviceLongName[] = "phone GS service";
char serviceDescription[] = "phone GS Network Server";
/*
* -1 - not in service mode
*  0 - stopped
*  1 - running
*  2 - paused
*/
int m_ServiceStatus = -1;
#endif


FILE* g_fpLogConnection = NULL;


/// Print out the usage string for this program on the console.
void usage(const char *prog)
{
	MyLog::log->info("Usage: \n %s [<options>]\n"
		"    -c config_file           use config_file as configuration file\n\r"
#ifdef WIN32
		"    Running as service functions:\n\r"
		"    --service                run as service\n\r"
		"    -s install               install service\n\r"
		"    -s uninstall             uninstall service\n\r"
#endif
		,prog);
}

int _tmain(int argc, _TCHAR* argv[])
{
	MyLog::Init();

	g_fpLogConnection = fopen( "user_connection.log", "a" );
	if( !g_fpLogConnection )
	{
		printf( "cannot open user_connection.log\n" );
		return -1;
	}

	char const* cfg_file = "GT.conf";

#ifdef WIN32
	HANDLE g_hIn  = GetStdHandle( STD_INPUT_HANDLE );
	HANDLE g_hOut = GetStdHandle( STD_OUTPUT_HANDLE );

	// prevent mouse input( it may cause some error )
	{
		DWORD	dwMode = 0;
		GetConsoleMode( g_hIn, &dwMode );
		dwMode &= ~ENABLE_MOUSE_INPUT;
		SetConsoleMode(g_hIn, dwMode);
	}
#endif
	int c=1;
	while( c < argc )
	{
		if( strcmp(argv[c],"-c") == 0)
		{
			if( ++c >= argc )
			{
				MyLog::log->error("Runtime-Error: -c option requires an input argument");
				usage(argv[0]);
				return 1;
			}
			else
				cfg_file = argv[c];
		}

#ifdef WIN32
		////////////
		//Services//
		////////////
		if( strcmp(argv[c],"-s") == 0)
		{
			if( ++c >= argc )
			{
				MyLog::log->error("Runtime-Error: -s option requires an input argument");
				usage(argv[0]);
				return 1;
			}
			if( strcmp(argv[c],"install") == 0)
			{
				if (WinServiceInstall())
					MyLog::log->info("Installing service");
				return 1;
			}
			else if( strcmp(argv[c],"uninstall") == 0)
			{
				if(WinServiceUninstall())
					MyLog::log->info("Uninstalling service");
				return 1;
			}
			else
			{
				MyLog::log->error("Runtime-Error: unsupported option %s",argv[c]);
				usage(argv[0]);
				return 1;
			}
		}
		if( strcmp(argv[c],"--service") == 0)
		{
			WinServiceRun();
		}
		////
#endif
		++c;
	}

	if( !Config.MainConfig.SetSource(cfg_file) )
	{
		MyLog::log->error("Could not find configuration file %s.", cfg_file);
		return 1;
	}
	MyLog::log->info("Using configuration file %s.", cfg_file);

	//if (!CGS.Init())
	//{
	//	return -1;
	//}

	//CGS.Run();

	//if(!sServer.Init())
	//{
	//	return -1;
	//}

	//sServer.Run();
	fclose( g_fpLogConnection );
	MyLog::Release();


	return 0;
}

