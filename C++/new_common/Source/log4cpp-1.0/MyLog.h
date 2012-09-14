#ifndef _MY_LOG_HEAD
#define _MY_LOG_HEAD

#ifndef _WIN32
#include "log4cpp/config.h"
#else
#include "log4cpp/config-win32.h"
#endif

#include "log4cpp/Category.hh"

class MyLog
{
public:
	static bool Init();
	static bool Release();

	static void SetColor(int color);
	static void ResetColor();
	static log4cpp::Category* log ;
	static log4cpp::Category* gmlog;
	static log4cpp::Category* yunyinglog;
	static FILE* serverlog;
#ifdef _WIN32
	static HANDLE stderr_handle;
	static HANDLE stdout_handle;
#endif
};

#endif
