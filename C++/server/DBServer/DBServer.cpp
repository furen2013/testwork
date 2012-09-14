#include "stdafx.h"

#ifdef WIN32
#include "../Common/Platform/ServiceWin32.h"
char serviceName[] = "Sunyou DB";
char serviceLongName[] = "Sunyou DB service";
char serviceDescription[] = "Sunyou DB Network Server";
/*
* -1 - not in service mode
*  0 - stopped
*  1 - running
*  2 - paused
*/
int m_ServiceStatus = -1;
#endif


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

int main(int argc, char **argv)
{
	MyLog::Init();

	char const* cfg_file = "DB.conf";

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

	if(!sServer.Init())
	{
		return -1;
	}

	sServer.Run();
	MyLog::Release();
}
