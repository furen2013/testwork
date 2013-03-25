#include "stdafx.h"
#include "Player.h"
#include "PlayerInfoManager.h"
#include "PlayerResourceManager.h"
#include "Database/Database.h"
//#include "MyLog.h"
Player::Player()
{
	_Info = NULL;
	_PlayerResource = NULL;
	
}

Player::~Player()
{

}
void Player::LoadFromDBProc(QueryResultVector & results)
{
	if( !IsValid() ) return;

	uint32 field_index = 2;
#define get_next_field fields[field_index++]

	if(getSession() == NULL || results.size() < 1)
	{
		//RemovePendingPlayer();
		return;
	}


	QueryResult *result = results[0].result;
	if(!result)
	{
		MyLog::log->error("Player login query failed., guid %u\n", getAccount());
	
		return;
	}
	else
	{
		Field *fields = result->Fetch();
		_PlayerResource = new PlayerResource();
		_PlayerResource->_account = fields[0].GetUInt64();
		_PlayerResource->_gold = fields[1].GetInt32();
		_PlayerResource->_ruby = fields[2].GetInt32();
		_PlayerResource->_manure = fields[3].GetInt32();
		_PlayerResource->_seeds[SeedType_Copper] = fields[4].GetInt32();
		_PlayerResource->_seeds[SeedType_Silver] = fields[5].GetInt32();
		_PlayerResource->_seeds[SeedType_Gold] = fields[6].GetInt32();
	}

}
NetSession* Player::getSession()
{
	return _session;
}
bool Player::Load(DWORD account)
{
	bool newPlayer = false;
	_Info = PlayerInfoManager::getSingleton().GetPlayerInfo(account);
	if (_Info == NULL)
	{
		newPlayer = true;
		_Info = PlayerInfoManager::getSingleton().CreatePlayerInfo(account);
	}

	_PlayerResource = PlayerResourceManager::getSingleton().GetPlayerResource(account);
	if (_PlayerResource == NULL)
	{
		if (newPlayer == false)
		{
			SQLCallbackBase* pCallBack = new SQLClassCallbackP0<Player>(this, &Player::LoadFromDBProc);
			AsyncQuery * q = new AsyncQuery( pCallBack );
			//q->AddQuery("SELECT * FROM characters WHERE guid=%u AND forced_rename_pending = 0",guid);
			q->AddQuery("SELECT * FROM PlayerResource WHERE account =%u",account);
			_db->QueueAsyncQuery(q);
		}		
	}



	return true;
}

DWORD Player::getAccount()
{
	if (!IsValid())
	{
		MyLog::log->warn("Player is invalid when getAccount()");
		return 0;
	}
	return _Info->_account;
}
int Player::getLevel()
{
	if (!IsValid())
	{
		MyLog::log->warn("Player is invalid when getLevel()");
		return 0;
	}
	return _Info->_level;
}
const char* Player::getIcon()
{
	if (!IsValid())
	{
		MyLog::log->warn("Player is invalid when getIcon()");
		return 0;
	}
	return _Info->_icon.c_str();
}
const char* Player::getName()
{
	if (!IsValid())
	{
		MyLog::log->warn("Player is invalid when getName()");
		return NULL;
	}

	return _Info->_name.c_str();
}
void Player::setAccount(DWORD account)
{
	if (!IsValid())
	{
		MyLog::log->warn("Player is invalid when setAccount()");
		return;
	}
	_Info->_account = account;
}
