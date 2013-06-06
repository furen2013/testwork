#include "stdafx.h"
#include "world.h"
#include "share/Database/Database.h"
#include "share/Database/DatabaseEnv.h"
#include "technology/TechnologyManager.h"
#include "PlayerResourceManager.h"
#include "technology/TechSkillStorage.h"
#include "farm/FarmComponentStorage.h"
#include "farm/FarmManager.h"
#include "Com/EventMgr.h"

initialiseSingleton( World );
World::World()
{

}
World::~World()
{

}

void World::Init()
{
	phoneDatabase = Database::CreateDatabaseInterface(1);
	if (!phoneDatabase->Initialize("127.0.0.1", 3306, "root", "7283933", "phone", 5, 16384))
	{
		MyLog::log->error("Game Server can not connect mysql");
		return;
	}
	TechnologyManager::getSingleton().init();
	PlayerResourceManager::getSingleton().Init();
	FarmManager::getSingleton().init();
	_holder = new EventableObjectHolder(-1);
	sEventMgr.AddEventHolder(_holder, -1);
}

void World::Run(uint32 time_difference)
{

	_holder->Update(time_difference);
  //every process
}

bool World::ExecuteSqlToDBServer( QueryBuffer* buf )
{
	phoneDatabase->AddQueryBuffer(buf);
	//if( sDSSocket && sDSSocket->is_connected() )
	//{
	//	MSG_GS2DB::stSave MsgSave;
	//	for( size_t i = 0; i < buf->queries.size(); ++i )
	//	{
	//		char* p = buf->queries[i];
	//		MsgSave.sqls.push_back( p );
	//		free( p );
	//	}
	//	delete buf;
	//	sDSSocket->PostSend( MsgSave );
	//}
	//else
	//{
		//scoped_sql_transaction_proc sstp( &phoneDatabase );
		//for( size_t i = 0; i < buf->queries.size(); ++i )
		//{
		//	char* p = buf->queries[i];
		//	phoneDatabase->ExecuteNA( p );
		//	free( p );
		//}
		//sstp.success();
		//delete buf;
		/*}*/

	return true;
}

static char QueryString[65536];

bool World::ExecuteSqlToDBServer( const char* sql, ... )
{
	va_list vlist;
	va_start(vlist, sql);
	vsnprintf(QueryString, 65536, sql, vlist);
	va_end(vlist);

	//if( sDSSocket && sDSSocket->is_connected() )
	//{
	//	MSG_GS2DB::stSave MsgSave;
	//	MsgSave.sqls.push_back( QueryString );
	//	sDSSocket->PostSend( MsgSave );
	//}
	//else
	//{
		phoneDatabase->WaitExecuteNA( QueryString );
	//}
	return true;
}
