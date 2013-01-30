#ifndef SUNYOU_DEFINE_H
#define SUNYOU_DEFINE_H

#include "../../share/TypeDef.h"
#include "CompilerDefs.h"
#include <sys/types.h>

#if PLATFORM == PLATFORM_WINDOWS
#define SUNYOU_EXPORT __declspec(dllexport)
#define SUNYOU_LIBRARY_HANDLE HMODULE
#define SUNYOU_LOAD_LIBRARY(a) LoadLibrary(a)
#define SUNYOU_CLOSE_LIBRARY FreeLibrary
#define SUNYOU_GET_PROC_ADDR GetProcAddress
#define SUNYOU_IMPORT __cdecl
#define SUNYOU_SCRIPT_EXT ".dll"
#define SUNYOU_SCRIPT_NAME "MaNGOSScript"
#define SIGQUIT 3
#else
#define SUNYOU_LIBRARY_HANDLE void*
#define SUNYOU_EXPORT export
#define SUNYOU_LOAD_LIBRARY(a) dlopen(a,RTLD_NOW)
#define SUNYOU_CLOSE_LIBRARY dlclose
#define SUNYOU_GET_PROC_ADDR dlsym

#if defined(__APPLE_CC__) && defined(BIG_ENDIAN)
#define SUNYOU_IMPORT __attribute__ ((longcall))
#else
#define SUNYOU_IMPORT __attribute__ ((cdecl))
#endif

#define SUNYOU_SCRIPT_EXT ".so"
#define SUNYOU_SCRIPT_NAME "libmangosscript"
#endif

#ifdef _WIN32
#ifdef SUNYOU_WIN32_DLL_IMPORT

#define SUNYOU_DLL_DECL __declspec(dllimport)
#else
#ifdef SUNYOU_WIND_DLL_EXPORT
#define SUNYOU_DLL_DECL __declspec(dllexport)
#else
#define SUNYOU_DLL_DECL
#endif
#endif

#else
#define SUNYOU_DLL_DECL
#endif

#ifndef DEBUG
#define SUNYOU_INLINE inline
#else
#ifndef SUNYOU_DEBUG
#define SUNYOU_DEBUG
#endif
#define SUNYOU_INLINE
#endif
//
//#if COMPILER == COMPILER_MICROSOFT
//typedef __int64            int64;
//typedef __int32            int32;
//typedef __int16            int16;
//typedef __int8             int8;
//typedef unsigned __int64   uint64;
//typedef unsigned __int32   uint32;
//typedef unsigned __int16   uint16;
//typedef unsigned __int8    uint8;
//#else
//typedef __int64_t   int64;
//typedef __int32_t   int32;
//typedef __int16_t   int16;
//typedef __int8_t    int8;
//typedef __uint64_t  uint64;
//typedef __uint32_t  uint32;
//typedef __uint16_t  uint16;
//typedef __uint8_t   uint8;
//typedef uint16      WORD;
//typedef uint32      DWORD;
//#endif
typedef uint64      OBJECT_HANDLE;

#if PLATFORM == PLATFORM_WINDOWS
#  define __declspec(dllexport)
#  ifndef DECLSPEC_NORETURN
#    define DECLSPEC_NORETURN __declspec(noreturn)
#  endif
#else
#  define SUNYOU_DLL_SPEC
#  define DECLSPEC_NORETURN
#endif

#if COMPILER == COMPILER_GNU
#  define ATTR_NORETURN __attribute__((noreturn))
#  define ATTR_PRINTF(F,V) __attribute__ ((format (printf, F, V)))
#else
#  define ATTR_NORETURN
#  define ATTR_PRINTF(F,V)
#endif
#endif
