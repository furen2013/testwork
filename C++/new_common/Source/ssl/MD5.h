#ifndef _MD5_H
#define _MD5_H

#include <cstdlib>
#include <string>

struct md5_context
{
    unsigned long total[2];             // number of bytes processed
    unsigned long state[4];             // intermediate digest state
    unsigned char buffer[64];           // data block being processed
};

#define MD5_DIGEST_LENGTH 16
class MD5Hash
{
public:
	MD5Hash();
	~MD5Hash();

	void UpdateData(const unsigned char *dta, int len);
	void UpdateData(const std::string &str);

	void Initialize();
	void Finalize();

	unsigned char *GetDigest(void) { return mDigest; };
	int GetLength(void) { return MD5_DIGEST_LENGTH; };

	static std::string _make_md5_pwd( const char* pwd );

private:
	md5_context mC;
	unsigned char mDigest[MD5_DIGEST_LENGTH];
};

extern char *hexstr(unsigned char *buf,int len);

#endif
