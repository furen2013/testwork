#ifndef NGLOG_H
#define NGLOG_H
#include "../../SDBase/Public/Timer.h"

class WorldPacket;
class WorldSession;

#ifdef _WIN32

#define TRED FOREGROUND_RED | FOREGROUND_INTENSITY
#define TGREEN FOREGROUND_GREEN | FOREGROUND_INTENSITY
#define TYELLOW FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY
#define TNORMAL FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE
#define TWHITE TNORMAL | FOREGROUND_INTENSITY
#define TBLUE FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY

#else

#define TRED 1
#define TGREEN 2
#define TYELLOW 3
#define TNORMAL 4
#define TWHITE 5
#define TBLUE 6

#endif

#if 0

#include <boost/thread/thread.hpp>
#define LOG_USE_MUTEX

class CLog : public Singleton< CLog >
{
#ifdef LOG_USE_MUTEX
	boost::mutex mutex;
#define LOCK_LOG mutex.lock()
#define UNLOCK_LOG mutex.unlock();
#else
#define LOCK_LOG
#define UNLOCK_LOG
#endif

public:
#ifdef _WIN32
	HANDLE stdout_handle, stderr_handle;
#endif
	int32 log_level;

	CLog()
	{
		log_level = 3;
#ifdef _WIN32
		stderr_handle = GetStdHandle(STD_ERROR_HANDLE);
		stdout_handle = GetStdHandle(STD_OUTPUT_HANDLE);
#endif
	}

	void Color(unsigned int color)
	{
#ifndef _WIN32
		static const char* colorstrings[TBLUE+1] = {
			"",
				"\033[22;31m",
				"\033[22;32m",
				"\033[01;33m",
				//"\033[22;37m",
				"\033[0m",
				"\033[01;37m",
				"\033[1;34m",
		};
		fputs(colorstrings[color], stdout);
#else
        SetConsoleTextAttribute(stdout_handle, (WORD)color);
#endif
	}

	SUNYOU_INLINE void Time()
	{
        /*tm * t = localtime(&UNIXTIME);
		printf("%02u:%02u ", t->tm_hour, t->tm_min);*/
		printf("%02u:%02u ", g_localTime.tm_hour, g_localTime.tm_min);
	}

	void Notice(const char * source, const char * format, ...)
	{
		/* notice is old loglevel 0/string */
		LOCK_LOG;
		va_list ap;
		va_start(ap, format);
		Time();
		fputs("N ", stdout);
		if(*source)
		{
			Color(TWHITE);
			fputs(source, stdout);
			putchar(':');
			putchar(' ');
			Color(TNORMAL);
		}

		vprintf(format, ap);
		putchar('\n');
		va_end(ap);
		Color(TNORMAL);
		UNLOCK_LOG;
	}

	void Warning(const char * source, const char * format, ...)
	{
		if(log_level < 2)
			return;

		/* warning is old loglevel 2/detail */
		LOCK_LOG;
		va_list ap;
		va_start(ap, format);
		Time();
		Color(TYELLOW);
		fputs("W ", stdout);
		if(*source)
		{
			Color(TWHITE);
			fputs(source, stdout);
			putchar(':');
			putchar(' ');
			Color(TYELLOW);
		}

		vprintf(format, ap);
		putchar('\n');
		va_end(ap);
		Color(TNORMAL);
		UNLOCK_LOG;
	}

	void Success(const char * source, const char * format, ...)
	{
		if(log_level < 2)
			return;

		LOCK_LOG;
		va_list ap;
		va_start(ap, format);
		Time();
		Color(TGREEN);
		fputs("S ", stdout);
		if(*source)
		{
			Color(TWHITE);
			fputs(source, stdout);
			putchar(':');
			putchar(' ');
			Color(TGREEN);
		}

		vprintf(format, ap);
		putchar('\n');
		va_end(ap);
		Color(TNORMAL);
		UNLOCK_LOG;
	}

	void Error(const char * source, const char * format, ...)
	{
		if(log_level < 1)
			return;

		LOCK_LOG;
		va_list ap;
		va_start(ap, format);
		Time();
		Color(TRED);
		fputs("E ", stdout);
		if(*source)
		{
			Color(TWHITE);
			fputs(source, stdout);
			putchar(':');
			putchar(' ');
			Color(TRED);
		}

		vprintf(format, ap);
		putchar('\n');
		va_end(ap);
		Color(TNORMAL);
		UNLOCK_LOG;
	}

	void Line()
	{
		LOCK_LOG;
		putchar('\n');
		UNLOCK_LOG;
	}

	void Debug(const char * source, const char * format, ...)
	{
		if(log_level < 3)
			return;

		LOCK_LOG;
		va_list ap;
		va_start(ap, format);
		Time();
		Color(TBLUE);
		fputs("D ", stdout);
		if(*source)
		{
			Color(TWHITE);
			fputs(source, stdout);
			putchar(':');
			putchar(' ');
			Color(TBLUE);
		}

		vprintf(format, ap);
		putchar('\n');
		va_end(ap);
		Color(TNORMAL);
		UNLOCK_LOG;
	}

#define LARGERRORMESSAGE_ERROR 1
#define LARGERRORMESSAGE_WARNING 2

	void LargeErrorMessage(uint32 Colour, ...)
	{
		std::vector<char*> lines;
		char * pointer;
		va_list ap;
		va_start(ap, Colour);

		size_t i,j,k;
		pointer = va_arg(ap, char*);
		while( pointer != NULL )
		{
			lines.push_back( pointer );
			pointer = va_arg(ap, char*);
		}

		LOCK_LOG;

		if( Colour == LARGERRORMESSAGE_ERROR )
			Color(TRED);
		else
			Color(TYELLOW);

		printf("*********************************************************************\n");
		printf("*                        MAJOR ERROR/WARNING                        *\n");
		printf("*                        ===================                        *\n");

		for(std::vector<char*>::iterator itr = lines.begin(); itr != lines.end(); ++itr)
		{
			i = strlen(*itr);
			j = (i<=65) ? 65 - i : 0;

			printf("* %s", *itr);
			for( k = 0; k < j; ++k )
			{
				printf(" ");
			}

			printf(" *\n");
		}

		printf("*********************************************************************\n");

#ifdef _WIN32
		std::string str = "MAJOR ERROR/WARNING:\n";
		for(std::vector<char*>::iterator itr = lines.begin(); itr != lines.end(); ++itr)
		{
			str += *itr;
			str += "\n";
		}
#ifdef UNICODE
		MessageBox(0, (LPWSTR)str.c_str(), TEXT("Error"), MB_OK);
#else
		MessageBox(0, str.c_str(), TEXT("Error"), MB_OK);
#endif
#else
		printf("Sleeping for 5 seconds.\n");
		Sleep(5000);
#endif

		Color(TNORMAL);
		UNLOCK_LOG;
	}
};

#define Log CLog::getSingleton()
#endif
#endif

