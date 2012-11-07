#include "StdAfx.h"
#include "LoginUser.h"


CLoginUser::CLoginUser(void):m_account(0)
{
}


CLoginUser::~CLoginUser(void)
{
}

void CLoginUser::setmac(const char* sz)
{
	m_mac = sz;		
}

void CLoginUser::setAccount(unsigned long account)
{
	m_account = account;
}
