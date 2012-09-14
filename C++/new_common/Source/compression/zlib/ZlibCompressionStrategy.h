#ifndef _ZLIB_COMPRESS_STRATEGY_HEAD_
#define _ZLIB_COMPRESS_STRATEGY_HEAD_

#include "zlib.h"

class zip_compress_strategy : public compress_strategy
{
public:
	virtual bool compress( char* dest, unsigned int* destlen, const char* src, unsigned int srclen )
	{
		return Z_OK == ::compress( (Bytef*)dest, (uLongf*)destlen, (const Bytef*)src, srclen );
	}
	virtual bool uncompress( char* dest, unsigned int* destlen, const char* src, unsigned int srclen )
	{
		return Z_OK == ::uncompress( (Bytef*)dest, (uLongf*)destlen, (const Bytef*)src, srclen );
	}
};


#endif // _ZLIB_COMPRESS_STRATEGY_HEAD_