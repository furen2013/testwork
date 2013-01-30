#ifndef TYPE_DEFINE_HEAD_
#define TYPE_DEFINE_HEAD_

#ifndef _WIN32
typedef long long __int64;
typedef long long int64;
typedef long long i64;
typedef unsigned long long ui64;
//typedef unsigned long long uint64;
typedef unsigned char		ui8;
typedef unsigned short		ui16;
typedef unsigned int		ui32;
typedef char				i8;
typedef short				i16;
typedef int					i32;
typedef float				real;

typedef i32 int32;
typedef i16 int16;
typedef i8 int8;

typedef ui64 uint64;
typedef ui32 uint32;
typedef ui16 uint16;
typedef ui8 uint8;

typedef unsigned long DWORD;
typedef unsigned short WORD;
typedef unsigned char BYTE;
typedef long BOOL;
#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif
#else

typedef unsigned char		ui8;
typedef unsigned short		ui16;
typedef unsigned int		ui32;
typedef unsigned __int64	ui64;

typedef char				i8;
typedef short				i16;
typedef int					i32;
typedef __int64				i64;
typedef float				real;

// Use correct types for x64 platforms, too
typedef signed __int64 int64;
typedef signed __int32 int32;
typedef signed __int16 int16;
typedef signed __int8 int8;

typedef unsigned __int64 uint64;
typedef unsigned __int32 uint32;
typedef unsigned __int16 uint16;
typedef unsigned __int8 uint8;
#endif
const int INVALID_ID		= 0xFFFFFFFF;
#define SY_INVALID_OBJID   0
#include <list>
#include <deque>
#include <vector>
#include <set>
#include <map>
#include <string>

#ifdef _WIN32
#include <hash_map>
#endif
using namespace std;


#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <time.h>
#include <math.h>
#include <errno.h>
#include "assert.h"
#ifdef _WIN32
#include <winsock2.h>
#include <ws2tcpip.h>
#else
#include <sys/time.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <signal.h>
#include <netdb.h>
#endif

#ifdef _WIN32
#  define WIN32_LEAN_AND_MEAN
//#  define _WIN32_WINNT 0x0500
#  define NOMINMAX
#  include <windows.h>
#else
#  include <string.h>
#  define MAX_PATH 1024
#endif


#endif // head