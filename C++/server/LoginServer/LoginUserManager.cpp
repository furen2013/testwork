#include "StdAfx.h"
#include "LoginUserManager.h"
initialiseSingleton(LoginUserManager);

LoginUserManager::LoginUserManager(void)
{
}


LoginUserManager::~LoginUserManager(void)
{
}

unsigned long LoginUserManager::lh_strhash(char *c)
{
	unsigned long ret=0; 
	long n; 
	unsigned long v; 
	int r; 

	if ((c == NULL) || (*c == '\0')) 
		return(ret); 
	/* 
	unsigned char b[16]; 
	MD5(c,strlen(c),b); 
	return(b[0]|(b[1]<<|(b[2]<<16)|(b[3]<<24)); 
	*/ 

	n=0x100; 
	while (*c) 
	{ 
		v=n|(*c); 
		n+=0x100; 
		r= (int)((v>>2)^v)&0x0f; 
		ret=32 - r;//ret=(ret(32-r)); 
		ret&=0xFFFFFFFFL; 
		ret^=v*v; 
		c++; 
	} 
	return((ret>>16)^ret); 

}