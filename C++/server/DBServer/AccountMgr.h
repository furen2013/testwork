#pragma once

#include "../../../SDBase/Public/UpdateFields.h"
#include "../../../SDBase/Public/SkillDef.h"
#include "../../../SDBase/Public/ItemDef.h"
#include "../../Common/Public/playerdef.h"
#include "../../../SDBase/Protocol/S2C.h"
#define   REMOVE_USER_INTERVAL	300		//从下线后多久将账号数据从内存移除（单位秒 ）

#define MAX_ROLE_COUNT 5
enum EUserState
{
	eNone = 1,
	eRoleSelecting,
	eInGameServer,
	eLogOut,//小退,
	eJumpGameServer,
	eStateEnd,//不要使用这个状态，该状态仅仅是用于方便书写程序
};

extern EUserState g_StateTransMap[eStateEnd-eNone][eStateEnd-eNone+1];

typedef MSG_S2C::RoleInfo RoleInfo;

struct Account
{
	ui32	m_nAccountID;
	ui32	m_nRoleCnt;
	EUserState m_eState;
	class CGTSocket* m_pGTSocket;
	Account(ui32 nAccountID):m_nAccountID(nAccountID)
	{
		Reset();
	}
	void Reset();
};

typedef hash_map<ui32, Account*> Account_Map;
class AccountMgr : public Singleton<AccountMgr>
{
public:
	AccountMgr(void){}
	~AccountMgr(void){}
	bool Init();
	bool Destroy(){
		Account_Map::iterator itr = m_mAccount.begin();
		for(; itr != m_mAccount.end(); itr++ )
		{
			Account* pAcct = itr->second;;
			if(pAcct)
				delete pAcct;
		}
		m_mAccount.clear();
		return true;
	}

	//内存账号数据映射的操作函数

	Account_Map m_mAccount;
	void	AddAccount(Account* pNewAccount);
	bool	RemoveAccount(ui32 nAccountID);
	Account* GetAccount(ui32 nAccountID);
};
#define sAccountMgr AccountMgr::getSingleton()