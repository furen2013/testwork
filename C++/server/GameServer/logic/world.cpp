#include "stdafx.h"
#include "world.h"
#include "share/Database/Database.h"
#include "share/Database/DatabaseEnv.h"
initialiseSingleton( World );
World::World()
{

}
World::~World()
{

}

void World::Init()
{

}

void World::Run()
{

}

bool World::ExecuteSqlToDBServer( QueryBuffer* buf )
{
	CharacterDatabase.AddQueryBuffer(buf);
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
		//scoped_sql_transaction_proc sstp( &CharacterDatabase );
		//for( size_t i = 0; i < buf->queries.size(); ++i )
		//{
		//	char* p = buf->queries[i];
		//	CharacterDatabase.ExecuteNA( p );
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
		CharacterDatabase.WaitExecuteNA( QueryString );
	//}
	return true;
}
