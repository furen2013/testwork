#pragma once
#ifndef USERSTORAGE_H
#define USERSTORAGE_H
class Database;
#include "../../../Common/share/Singleton.h"
extern Database* phoneDatabase;
struct tgUserInfo_t
{
	long account;
	string mac;
	string mail;
	string password;
};
class CUserStorage: public Singleton<CUserStorage>
{
public:
	CUserStorage(void);
	virtual ~CUserStorage(void);
protected:
	bool Init();
public:
	void LoadAll();
	void Clear();
	tgUserInfo_t* GetUserInfo(long account);
	void addUser(tgUserInfo_t* p);

protected:
	std::map<long, tgUserInfo_t*> m_storageUser;
	boost::mutex m_mutex;

};

#endif 