/* LzmaLib.c -- LZMA library wrapper
2008-08-05
Igor Pavlov
Public domain */

#include "LzmaEnc.h"
#include "LzmaDec.h"
#include "Alloc.h"
#include "LzmaLib.h"

static void *SzAlloc(void *p, size_t size) { return MyAlloc( size ); }
static void SzFree(void *p, void *address) { MyFree( address ); }
//static void *SzAlloc(void *p, size_t size) { return malloc( size ); }
//static void SzFree(void *p, void *address) { free( address ); }

static ISzAlloc g_Alloc = { SzAlloc, SzFree };

static unsigned char inProps[LZMA_PROPS_SIZE] = { 93, 0, 0, 1, 0 };

#define COMPRESS_NORMAL 1
#define COMPRESS_FAST 0

static CLzmaEncProps props = { 2, 65536, 3, 0, 2, COMPRESS_FAST, 32, -1, -1, 0, 0, 1 };

MY_STDAPI LzmaSetCompressSpeed( long IsFast )
{
	if( IsFast )
		props.algo = COMPRESS_FAST;
	else
		props.algo = COMPRESS_NORMAL;
	return IsFast;
}

MY_STDAPI LzmaCompress(unsigned char *dest, size_t  *destLen, const unsigned char *src, size_t srcLen )
{
	//CLzmaEncProps props;
	unsigned char outProps[LZMA_PROPS_SIZE];
	size_t propsSize = LZMA_PROPS_SIZE;

	//LzmaEncProps_Init(&props);
	//props.level = 2;
	//props.dictSize = 65536;
	//props.lc = 3;
	//props.lp = 0;
	//props.pb = 2;
	//props.fb = 32;
	//props.numThreads = 1;

	return LzmaEncode(dest, destLen, src, srcLen, &props, outProps, &propsSize, 0,
		NULL, &g_Alloc, &g_Alloc);
}

MY_STDAPI LzmaUncompress(unsigned char *dest, size_t  *destLen, const unsigned char *src, size_t  *srcLen )
{
	ELzmaStatus status;
	return LzmaDecode(dest, destLen, src, srcLen, inProps, LZMA_PROPS_SIZE, LZMA_FINISH_ANY, &status, &g_Alloc);
}
