#pragma once
#ifndef CLOGINUSER_H
#define CLOGINUSER_H
#include "iostream"

struct tgUserInfo_t;
class CLoginUser
{
public:
	CLoginUser(void);
	virtual ~CLoginUser(void);
public:
	void setInfo(tgUserInfo_t* info)
	{
		m_Info = info;
	}

	tgUserInfo_t* getInfo()
	{
		return m_Info;
	}

public:
	tgUserInfo_t* m_Info;
};

#endif