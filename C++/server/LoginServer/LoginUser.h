#pragma once
#ifndef CLOGINUSER_H
#define CLOGINUSER_H
#include "iostream"

class CLoginUser
{
public:
	CLoginUser(void);
	virtual ~CLoginUser(void);
public:
	void setmac(const char* sz);
	void setAccount(unsigned long account);
	inline const char*getmac(){return m_mac.c_str();}
	inline unsigned long getAccount(){return m_account;}
protected:
	std::string m_mac;
	unsigned long m_account;
};

#endif