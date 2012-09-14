#ifndef _LZMA_COMPRESSION_STRATEGY_HEAD
#define _LZMA_COMPRESSION_STRATEGY_HEAD

#include "LzmaLib.h"
#include "../../net/asiodef.h"

class lzma_compress_strategy : public compress_strategy
{
public:
	virtual bool compress( char* dest, unsigned int* destlen, const char* src, unsigned int srclen )
	{
		return SZ_OK == ::LzmaCompress( (unsigned char*)dest, destlen, (const unsigned char*)src, srclen );
	}
	virtual bool uncompress( char* dest, unsigned int* destlen, const char* src, unsigned int srclen )
	{
		return SZ_OK == ::LzmaUncompress( (unsigned char*)dest, destlen, (const unsigned char*)src, &srclen );
	}
};


#endif
