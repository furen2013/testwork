#if 0
#include "MD5.h"

MD5Hash::MD5Hash()
{
	MD5_Init(&mC);
}

MD5Hash::~MD5Hash()
{

}

void MD5Hash::UpdateData(const std::string &str)
{
	UpdateData((const uint8*)str.data(), (int)str.length());
}

void MD5Hash::UpdateData(const uint8 *dta, int len)
{
	MD5_Update(&mC, dta, len);
}

void MD5Hash::Finalize()
{
	MD5_Final(mDigest, &mC);
}

void MD5Hash::Initialize()
{
	MD5_Init(&mC);
}

char *hexstr(unsigned char *buf,int len)
{
	const char *set = "0123456789ABCDEF";
	static char str[65],*tmp;
	unsigned char *end;
	if (len > 32)
		len = 32;
	end = buf + len;
	tmp = &str[0];
	while( buf < end )
	{
		*tmp++ = set[ (*buf) >> 4 ];
		*tmp++ = set[ (*buf) & 0xF ];
		buf ++;
	}
	*tmp = 0;
	return str;
}
#endif
