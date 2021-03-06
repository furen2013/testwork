#ifndef COMMON_H
#define COMMON_H

#include "TypeDef.h"
#include "PacketDef.h"
#include "Timer.h"
#include "Singleton.h"
#ifdef _WIN32
#pragma warning(disable:4996)
#define _CRT_SECURE_NO_DEPRECATE 1
#define _CRT_SECURE_COPP_OVERLOAD_STANDARD_NAMES 1
#pragma warning(disable:4251)		// dll-interface bullshit
#endif

#ifdef _WIN32
enum TimeVariables
{
	TIME_SECOND = 1,
	TIME_MINUTE = TIME_SECOND * 60,
	TIME_HOUR   = TIME_MINUTE * 60,
	TIME_DAY	= TIME_HOUR * 24,
	TIME_MONTH	= TIME_DAY * 30,
	TIME_YEAR	= TIME_MONTH * 12,
};
#else
enum TimeVariables
{
	TIME_SECOND = 1,
	TIME_MINUTE = TIME_SECOND * 60,
	TIME_HOUR   = TIME_MINUTE * 60,
	TIME_DAY	= TIME_HOUR * 24,
	TIME_MONTH	= TIME_DAY * 30,
	TIME_YEAR	= TIME_MONTH * 12,
};
#endif

enum MsTimeVariables
{
	MSTIME_SECOND = 1000,
	MSTIME_MINUTE = MSTIME_SECOND * 60,
	MSTIME_HOUR   = MSTIME_MINUTE * 60,
	MSTIME_DAY	= MSTIME_HOUR * 24,
};

#ifdef _WIN32
// #define SUNYOU_INLINE /*__forceinline*/
#define SUNYOU_INLINE inline
#else
#define SUNYOU_INLINE inline
#endif

#ifdef HAVE_CONFIG_H
# include <config.h>
#endif

#include "SunyouConfig.h"

/* Define this if you're using a big-endian machine */
#ifdef USING_BIG_ENDIAN
#include <machine/byte_order.h>
#define bswap_16(x) NXSwapShort(x)
#define bswap_32(x) NXSwapInt(x)
#define bswap_64(x) NXSwapLongLong(x)
#endif

#ifdef min
#undef min
#endif

#ifdef max
#undef max
#endif

#ifdef CONFIG_USE_SELECT
#undef FD_SETSIZE
#define FD_SETSIZE 2048
#endif


// current platform and compiler
#define PLATFORM_WIN32 0
#define PLATFORM_UNIX  1
#define PLATFORM_APPLE 2

#define UNIX_FLAVOUR_LINUX 1
#define UNIX_FLAVOUR_BSD 2
#define UNIX_FLAVOUR_OTHER 3
#define UNIX_FLAVOUR_OSX 4

#define COMPILER_MICROSOFT 0
#define COMPILER_GNU	   1
#define COMPILER_BORLAND   2

#ifdef _MSC_VER
#  define COMPILER COMPILER_MICROSOFT
#define SERVER_DECL
#elif defined( __BORLANDC__ )
#  define COMPILER COMPILER_BORLAND
#elif defined( __GNUC__ )
#  define COMPILER COMPILER_GNU
#else
#  pragma error "FATAL ERROR: Unknown compiler."
#endif

#if PLATFORM == PLATFORM_UNIX || PLATFORM == PLATFORM_APPLE
#ifdef HAVE_DARWIN
#define PLATFORM_TEXT "MacOSX"
#define UNIX_FLAVOUR UNIX_FLAVOUR_OSX
#else
#ifdef USE_KQUEUE
#define PLATFORM_TEXT "FreeBSD"
#define UNIX_FLAVOUR UNIX_FLAVOUR_BSD
#else
#define PLATFORM_TEXT "Linux"
#define UNIX_FLAVOUR UNIX_FLAVOUR_LINUX
#endif
#endif
#endif

#if PLATFORM == PLATFORM_WIN32
#define PLATFORM_TEXT "Win32"
#endif

#ifdef _DEBUG
#define CONFIG "Debug"
#else
#define CONFIG "Release"
#endif

#ifdef USING_BIG_ENDIAN
#define ARCH "PPC"
#else
#ifdef X64
#define ARCH "X64"
#else
#define ARCH "X86"
#endif
#endif

/*#if COMPILER == COMPILER_MICROSOFT
#  pragma warning( disable : 4267 ) // conversion from 'size_t' to 'int', possible loss of data
#  pragma warning( disable : 4311 ) // 'type cast': pointer truncation from HMODULE to uint32
#  pragma warning( disable : 4786 ) // identifier was truncated to '255' characters in the debug information
#  pragma warning( disable : 4146 )
#  pragma warning( disable : 4800 )
#endif*/

#if PLATFORM == PLATFORM_WIN32
#define STRCASECMP stricmp
#else
#define STRCASECMP strcasecmp
#endif

#if PLATFORM == PLATFORM_WIN32
	#define ASYNC_NET
#endif

#ifdef USE_EPOLL
	#define CONFIG_USE_EPOLL
#endif
#ifdef USE_KQUEUE
	#define CONFIG_USE_KQUEUE
#endif
#ifdef USE_SELECT
	#define CONFIG_USE_SELECT
#endif
#ifdef USE_POLL
	#define CONFIG_USE_POLL
#endif

#ifdef min
#undef min
#endif

#ifdef max
#undef max
#endif

#include <set>
#include <list>
#include <string>
#include <map>
#include <queue>
#include <sstream>
#include <algorithm>
//#include <iostream>

#if defined (__GNUC__)
#  define GCC_VERSION (__GNUC__ * 10000 \
					   + __GNUC_MINOR__ * 100 \
					   + __GNUC_PATCHLEVEL__)
#endif


#ifndef _WIN32
#ifndef X64
#  if defined (__GNUC__)
#	if GCC_VERSION >= 30400
#         ifdef HAVE_DARWIN
#	      define __fastcall
#         else
#    	      define __fastcall __attribute__((__fastcall__))
#         endif
#	else
#	  define __fastcall __attribute__((__regparm__(3)))
#	endif
#  else
#	define __fastcall __attribute__((__fastcall__))
#  endif
#else
#define __fastcall
#endif
#endif

#if COMPILER == COMPILER_GNU && __GNUC__ >= 3
#include <ext/hash_map>
#include <ext/hash_set>
#else
#include <hash_map>
#include <hash_set>
#endif



#ifdef _STLPORT_VERSION
#define HM_NAMESPACE std
using std::hash_map;
using std::hash_set;
#elif COMPILER == COMPILER_MICROSOFT && _MSC_VER >= 1300
#define HM_NAMESPACE stdext
using stdext::hash_map;
using stdext::hash_set;
#define ENABLE_SHITTY_STL_HACKS 1

// hacky stuff for vc++
#define snprintf _snprintf
#define vsnprintf _vsnprintf

#elif COMPILER == COMPILER_INTEL
#define HM_NAMESPACE std
using std::hash_map;
using std::hash_set;
#elif COMPILER == COMPILER_GNU && __GNUC__ >= 3
#define HM_NAMESPACE __gnu_cxx
using __gnu_cxx::hash_map;
using __gnu_cxx::hash_set;

namespace __gnu_cxx
{
	template<> struct hash<unsigned long long>
	{
		size_t operator()(const unsigned long long &__x) const { return (size_t)__x; }
	};
	template<typename T> struct hash<T *>
	{
		size_t operator()(T * const &__x) const { return (size_t)__x; }
	};

};

#else
#define HM_NAMESPACE std
using std::hash_map;
#endif


/* these can be optimized into assembly */
#ifdef USING_BIG_ENDIAN

/*SUNYOU_INLINE static void swap16(uint16* p) { *p = ((*p >> 8) & 0xff) | (*p << 8); }
SUNYOU_INLINE static void swap32(uint32* p) { *p = ((*p >> 24 & 0xff)) | ((*p >> 8) & 0xff00) | ((*p << 8) & 0xff0000) | (*p << 24); }
SUNYOU_INLINE static void swap64(uint64* p) { *p = ((*p >> 56)) | ((*p >> 40) & 0x000000000000ff00ULL) | ((*p >> 24) & 0x0000000000ff0000ULL) | ((*p >> 8 ) & 0x00000000ff000000ULL) |
								((*p << 8 ) & 0x000000ff00000000ULL) | ((*p << 24) & 0x0000ff0000000000ULL) | ((*p << 40) & 0x00ff000000000000ULL) | ((*p << 56)); }*/

SUNYOU_INLINE static void swap16(uint16* p) { *p = bswap_16((uint16_t)*p); }
SUNYOU_INLINE static void swap32(uint32* p) { *p = bswap_32((uint32_t)*p); }
SUNYOU_INLINE static void swap64(uint64* p) { *p = bswap_64((uint64_t)*p);; }

SUNYOU_INLINE static float swapfloat(float p)
{
	union { float asfloat; uint8 asbytes[4]; } u1, u2;
	u1.asfloat = p;
	/* swap! */
	u2.asbytes[0] = u1.asbytes[3];
	u2.asbytes[1] = u1.asbytes[2];
	u2.asbytes[2] = u1.asbytes[1];
	u2.asbytes[3] = u1.asbytes[0];

	return u2.asfloat;
}

SUNYOU_INLINE static double swapdouble(double p)
{
	union { double asfloat; uint8 asbytes[8]; } u1, u2;
	u1.asfloat = p;
	/* swap! */
	u2.asbytes[0] = u1.asbytes[7];
	u2.asbytes[1] = u1.asbytes[6];
	u2.asbytes[2] = u1.asbytes[5];
	u2.asbytes[3] = u1.asbytes[4];
	u2.asbytes[4] = u1.asbytes[3];
	u2.asbytes[5] = u1.asbytes[2];
	u2.asbytes[6] = u1.asbytes[1];
	u2.asbytes[7] = u1.asbytes[0];

	return u2.asfloat;
}

SUNYOU_INLINE static void swapfloat(float * p)
{
	union { float asfloat; uint8 asbytes[4]; } u1, u2;
	u1.asfloat = *p;
	/* swap! */
	u2.asbytes[0] = u1.asbytes[3];
	u2.asbytes[1] = u1.asbytes[2];
	u2.asbytes[2] = u1.asbytes[1];
	u2.asbytes[3] = u1.asbytes[0];
	*p = u2.asfloat;
}

SUNYOU_INLINE static void swapdouble(double * p)
{
	union { double asfloat; uint8 asbytes[8]; } u1, u2;
	u1.asfloat = *p;
	/* swap! */
	u2.asbytes[0] = u1.asbytes[7];
	u2.asbytes[1] = u1.asbytes[6];
	u2.asbytes[2] = u1.asbytes[5];
	u2.asbytes[3] = u1.asbytes[4];
	u2.asbytes[4] = u1.asbytes[3];
	u2.asbytes[5] = u1.asbytes[2];
	u2.asbytes[6] = u1.asbytes[1];
	u2.asbytes[7] = u1.asbytes[0];
	*p = u2.asfloat;
}

/*SUNYOU_INLINE static uint16 swap16(uint16 p) { return ((p >> 8) & 0xff) | (p << 8); }
SUNYOU_INLINE static uint32 swap32(uint32 p) { return ((p >> 24) & 0xff) | ((p >> 8) & 0xff00) | ((p << 8) & 0xff0000) | (p << 24); }
SUNYOU_INLINE static uint64 swap64(uint64 p)  { p = (((p >> 56) & 0xff)) | ((p >> 40) & 0x000000000000ff00ULL) | ((p >> 24) & 0x0000000000ff0000ULL) | ((p >> 8 ) & 0x00000000ff000000ULL) |
								((p << 8 ) & 0x000000ff00000000ULL) | ((p << 24) & 0x0000ff0000000000ULL) | ((p << 40) & 0x00ff000000000000ULL) | ((p << 56)); }

SUNYOU_INLINE static void swap16(int16* p) { *p = ((*p >> 8) & 0xff) | (*p << 8); }
SUNYOU_INLINE static void swap32(int32* p) { *p = ((*p >> 24) & 0xff) | ((*p >> 8) & 0xff00) | ((*p << 8) & 0xff0000) | (*p << 24); }
SUNYOU_INLINE static void swap64(int64* p) { *p = ((*p >> 56) & 0xff) | ((*p >> 40) & 0x000000000000ff00ULL) | ((*p >> 24) & 0x0000000000ff0000ULL) | ((*p >> 8 ) & 0x00000000ff000000ULL) |
								((*p << 8 ) & 0x000000ff00000000ULL) | ((*p << 24) & 0x0000ff0000000000ULL) | ((*p << 40) & 0x00ff000000000000ULL) | ((*p << 56)); }

SUNYOU_INLINE static int16 swap16(int16 p) { return ((p >> 8) & 0xff) | (p << 8); }
SUNYOU_INLINE static int32 swap32(int32 p) { return ((p >> 24) & 0xff) | ((p >> 8) & 0xff00) | ((p << 8) & 0xff0000) | (p << 24); }
SUNYOU_INLINE static int64 swap64(int64 p)  { return ((((p >> 56) & 0xff)) | ((p >> 40) & 0x000000000000ff00ULL) | ((p >> 24) & 0x0000000000ff0000ULL) | ((p >> 8 ) & 0x00000000ff000000ULL) |
								((p << 8 ) & 0x000000ff00000000ULL) | ((p << 24) & 0x0000ff0000000000ULL) | ((p << 40) & 0x00ff000000000000ULL) | ((p << 56))); }*/

SUNYOU_INLINE static uint16 swap16(uint16 p) { return bswap_16((uint16_t)p); }
SUNYOU_INLINE static uint32 swap32(uint32 p) { return bswap_32((uint32_t)p); }
SUNYOU_INLINE static uint64 swap64(uint64 p)  { return bswap_64((uint64_t)p); }

SUNYOU_INLINE static void swap16(int16* p) { *p = bswap_16((uint16_t)*p); }
SUNYOU_INLINE static void swap32(int32* p) { *p = bswap_32((uint32_t)*p); }
SUNYOU_INLINE static void swap64(int64* p) { *p = bswap_64((uint64_t)*p); }

SUNYOU_INLINE static int16 swap16(int16 p) { return bswap_16((uint16_t)p); }
SUNYOU_INLINE static int32 swap32(int32 p) { return bswap_32((uint32_t)p); }
SUNYOU_INLINE static int64 swap64(int64 p)  { return bswap_64((uint64_t)p); }

#endif
/*
Scripting system exports/imports
*/

#ifdef _WIN32
	#ifndef SCRIPTLIB
		#define __declspec(dllexport)
		#define SCRIPT_DECL __declspec(dllimport)
	#else
		#define __declspec(dllimport)
		#define SCRIPT_DECL __declspec(dllexport)
	#endif
#else
	#define SERVER_DECL
	#define SCRIPT_DECL
#endif

// Include all threading files
#include <assert.h>
#include "Threading/Threading.h"

#include "MersenneTwister.h"

#if COMPILER == COMPILER_MICROSOFT

#define I64FMT "%016I64X"
#define I64FMTD "%I64u"
#define SI64FMTD "%I64d"
#define snprintf _snprintf
#define atoll __atoi64

#else

#define stricmp strcasecmp
#define strnicmp strncasecmp
#define I64FMT "%016llX"
#define I64FMTD "%llu"
#define SI64FMTD "%lld"

#endif

//#ifndef _WIN32
//#ifdef USING_BIG_ENDIAN
////#define GUID_HIPART(x) (*((uint32*)&(x)))
////#define GUID_LOPART(x) (*(((uint32*)&(x))+1))
//#define GUID_LOPART(x) ( ( x >> 32 ) )
//#define GUID_HIPART(x) ( ( x & 0x00000000ffffffff ) )
//#else
//#define GUID_HIPART(x) ( ( x >> 32 ) )
//#define GUID_LOPART(x) ( ( x & 0x00000000ffffffff ) )
//#endif
//#else
//#define GUID_HIPART(x) (*(((uint32*)&(x))+1))
//#define GUID_LOPART(x) (*((uint32*)&(x)))
//#endif

#define atol(a) strtoul( a, NULL, 10)

#define STRINGIZE(a) #a

// fix buggy MSVC's for variable scoping to be reliable =S
#define for if(true) for

#if COMPILER == COMPILER_MICROSOFT && _MSC_VER >= 1400
#pragma float_control(push)
#pragma float_control(precise, on)
#endif

// fast int abs
static inline int int32abs( const int value )
{
	return (value ^ (value >> 31)) - (value >> 31);
}

// fast int abs and recast to unsigned
static inline uint32 int32abs2uint32( const int value )
{
	return (uint32)(value ^ (value >> 31)) - (value >> 31);
}

/// Fastest Method of float2int32
static inline int float2int32(const float value)
{
#if !defined(X64) && COMPILER == COMPILER_MICROSOFT && !defined(USING_BIG_ENDIAN)
	int i;
	__asm {
		fld value
		frndint
		fistp i
	}
	return i;
#else
	union { int asInt[2]; double asDouble; } n;
	n.asDouble = value + 6755399441055744.0;

#if USING_BIG_ENDIAN
	return n.asInt [1];
#else
	return n.asInt [0];
#endif
#endif
}

/// Fastest Method of long2int32
static inline int long2int32(const double value)
{
#if !defined(X64) && COMPILER == COMPILER_MICROSOFT && !defined(USING_BIG_ENDIAN)
	int i;
	__asm {
		fld value
		frndint
		fistp i
	}
	return i;
#else
  union { int asInt[2]; double asDouble; } n;
  n.asDouble = value + 6755399441055744.0;

#if USING_BIG_ENDIAN
  return n.asInt [1];
#else
  return n.asInt [0];
#endif
#endif
}

#if COMPILER == COMPILER_MICROSOFT && _MSC_VER >= 1400
#pragma float_control(pop)
#endif

#ifndef _WIN32
#include <sys/timeb.h>
#endif

#ifndef _WIN32
#define FALSE   0
#define TRUE	1
#endif

#ifndef _WIN32
#define Sleep(ms) usleep(1000*ms)
#endif

/*#ifdef _WIN32
#ifndef __SHOW_STUPID_WARNINGS__
#pragma warning(disable:4018)
#pragma warning(disable:4244)
#pragma warning(disable:4305)
#pragma warning(disable:4748)
#pragma warning(disable:4800)
#pragma warning(disable:4996)
#pragma warning(disable:4251)
#endif
#endif

#undef INTEL_COMPILER
#ifdef INTEL_COMPILER
#pragma warning(disable:279)
#pragma warning(disable:1744)
#pragma warning(disable:1740)
#endif*/

#include "Util.h"
struct WayPoint
{
	WayPoint()
	{
		o = 0.0f;
	}
	uint32 id;
	float x;
	float y;
	float z;
	float o;
	uint32 waittime; //ms
	uint32 flags;
	bool forwardemoteoneshot;
	uint32 forwardemoteid;
	bool backwardemoteoneshot;
	uint32 backwardemoteid;
	uint32 forwardskinid;
	uint32 backwardskinid;

};

SUNYOU_INLINE void reverse_array(uint8 * pointer, size_t count)
{
	size_t x;
	uint8 * temp = (uint8*)malloc(count);
	memcpy(temp, pointer, count);
	for(x = 0; x < count; ++x)
		pointer[x] = temp[count-x-1];
	free(temp);
}

typedef std::vector<WayPoint*> WayPointMap;

int32 GetTimePeriodFromString(const char * str);
std::string ConvertTimeStampToString(uint32 timestamp);
std::string ConvertTimeStampToDataTime(uint32 timestamp);

SUNYOU_INLINE void ASCENT_TOLOWER(std::string& str)
{
	for(size_t i = 0; i < str.length(); ++i)
		str[i] = (char)tolower(str[i]);
};

SUNYOU_INLINE void ASCENT_TOUPPER(std::string& str)
{
	for(size_t i = 0; i < str.length(); ++i)
		str[i] = (char)toupper(str[i]);
};

// returns true if the ip hits the mask, otherwise false
static bool ParseCIDRBan(unsigned int IP, unsigned int Mask, unsigned int MaskBits)
{
	// CIDR bans are a compacted form of IP / Submask
	// So 192.168.1.0/255.255.255.0 would be 192.168.1.0/24
	// IP's in the 192.168l.1.x range would be hit, others not.
	unsigned char * source_ip = (unsigned char*)&IP;
	unsigned char * mask = (unsigned char*)&Mask;
	int full_bytes = MaskBits / 8;
	int leftover_bits = MaskBits % 8;
	//int byte;

	// sanity checks for the data first
	if( MaskBits > 32 )
		return false;

	// this is the table for comparing leftover bits
	static const unsigned char leftover_bits_compare[9] = {
		0x00,			// 00000000
		0x80,			// 10000000
		0xC0,			// 11000000
		0xE0,			// 11100000
		0xF0,			// 11110000
		0xF8,			// 11111000
		0xFC,			// 11111100
		0xFE,			// 11111110
		0xFF,			// 11111111 - This one isn't used
	};

	// if we have any full bytes, compare them with memcpy
	if( full_bytes > 0 )
	{
		if( memcmp( source_ip, mask, full_bytes ) != 0 )
			return false;
	}

	// compare the left over bits
	if( leftover_bits > 0 )
	{
		if( ( source_ip[full_bytes] & leftover_bits_compare[leftover_bits] ) !=
			( mask[full_bytes] & leftover_bits_compare[leftover_bits] ) )
		{
			// one of the bits does not match
			return false;
		}
	}

	// all of the bits match that were testable
	return true;
}

static unsigned int MakeIP(const char * str)
{
	unsigned int bytes[4];
	unsigned int res;
	if( sscanf(str, "%u.%u.%u.%u", &bytes[0], &bytes[1], &bytes[2], &bytes[3]) != 4 )
		return 0;

	res = bytes[0] | (bytes[1] << 8) | (bytes[2] << 16) | (bytes[3] << 24);
	return res;
}

#include "Threading/Threading.h"

#include "Threading/AtomicULong.h"
#include "Threading/AtomicFloat.h"
#include "Threading/AtomicCounter.h"
#include "Threading/AtomicBoolean.h"
#include "Threading/ConditionVariable.h"
#include "TypeDef.h"

#endif
