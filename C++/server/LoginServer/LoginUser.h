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
protected:
	std::string m_mac;
	long m_account;
};

#endif