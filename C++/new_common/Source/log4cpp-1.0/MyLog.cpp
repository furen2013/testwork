#include "MyLog.h"
#include "log4cpp/FileAppender.hh"
#include "log4cpp/BasicLayout.hh"
#include "log4cpp/PropertyConfigurator.hh"
#include "log4cpp/OstreamAppender.hh"
log4cpp::Category* MyLog::log = NULL;
log4cpp::Category* MyLog::gmlog = NULL;
log4cpp::Category* MyLog::yunyinglog = NULL;
FILE* MyLog::serverlog = NULL;
#ifdef _WIN32
	HANDLE MyLog::stderr_handle = INVALID_HANDLE_VALUE;
	HANDLE MyLog::stdout_handle = INVALID_HANDLE_VALUE;
#endif

bool MyLog::Init()
{
	try
	{
		log4cpp::PropertyConfigurator::configure("./log.conf");
	}
	catch( const std::runtime_error& e )
	{
		printf( "ConfigureFailure: %s\n", e.what() );
		printf( "press any key to exit..." );
		getchar();
		abort();
		return false;
	}

	log = &log4cpp::Category::getRoot();
	gmlog = &log4cpp::Category::getInstance(std::string("gmcategory"));
	yunyinglog = &log4cpp::Category::getInstance(std::string("yunyingcategory"));

	serverlog = fopen("ServerStat.log", "w+");
	if(!serverlog)
	{
		MyLog::log->error("open ServerStat.log failed!");
		return false;
	}

#ifdef _WIN32
	stderr_handle = GetStdHandle(STD_ERROR_HANDLE);
	stdout_handle = GetStdHandle(STD_OUTPUT_HANDLE);
#endif
	return true;
}

bool MyLog::Release()
{
	fclose(serverlog);
	return true;
}

void MyLog::SetColor(int color)
{
#ifdef _WIN32
	SetConsoleTextAttribute(stdout_handle, color);
#else
	//printf(colorstrings[color]);
#endif
}

void MyLog::ResetColor()
{
	SetColor(TNORMAL);
}
