#include "DatabaseEnv.h"
#include "../CrashHandler.h"
#include "MyLog.h"

#if defined(ENABLE_DATABASE_MYSQL)

#include "MySQLDatabase.h"

MySQLDatabase::~MySQLDatabase()
{
//	for(int32 i = 0; i < mConnectionCount; ++i)
//		delete Connections[i];

//	delete [] Connections;
	if( ConnectionSync )
		delete ConnectionSync;
	if( ConnectionAsync )
		delete ConnectionAsync;
}

MySQLDatabase::MySQLDatabase() : Database()
{

}

void MySQLDatabase::BeginTransaction(DatabaseConnection* conn)
{
	_SendQuery( conn, "START TRANSACTION", false );
}

void MySQLDatabase::EndTransaction(DatabaseConnection* conn)
{
	_SendQuery( conn, "COMMIT", false );
}

void MySQLDatabase::RollbackTransaction(DatabaseConnection* conn)
{
	_SendQuery( conn, "ROLLBACK", false );
}

bool MySQLDatabase::Initialize(const char* Hostname, unsigned int port, const char* Username, const char* Password, const char* DatabaseName, uint32 ConnectionCount, uint32 BufferSize)
{
//	uint32 i;
	static bool is_lib_inited = false;
	MYSQL *temp, *temp2;
//	MySQLDatabaseConnection ** conns;
	my_bool my_true = true;

	mHostname = string(Hostname);
	mConnectionCount = ConnectionCount;
	mUsername = string(Username);
	mPassword = string(Password);
	mDatabaseName = string(DatabaseName);
	mPort = port;

	MyLog::log->notice("Connecting to `%s`, database `%s`...\n", Hostname, DatabaseName);

//	conns = new MySQLDatabaseConnection*[ConnectionCount];
//	Connections = ((DatabaseConnection**)conns);
	static char *server_args[] = {
	  "this_program",       /* this string is not used */
	  "--datadir=.",
	  "--key_buffer_size=32M"
	};
	static char *server_groups[] = {
	  "embedded",
	  "server",
	  "this_program_SERVER",
	  (char *)NULL
	};

	if( !is_lib_inited )
	{
		int e = mysql_library_init(sizeof(server_args) / sizeof(char *), server_args, server_groups);
		if( e )
			MyLog::log->notice( "mysql_library_init failed, error code is : %d\n", e );
		is_lib_inited = true;
	}
	temp = mysql_init( NULL );
	if(mysql_options(temp, MYSQL_SET_CHARSET_NAME, "utf8"))
		MyLog::log->notice("Could not set utf8 character set.\n");

	if(mysql_options(temp, MYSQL_OPT_COMPRESS, &my_true))
		MyLog::log->notice( "MYSQL_OPT_COMPRESS, could not be set\n" );

	if (mysql_options(temp, MYSQL_OPT_RECONNECT, &my_true))
		MyLog::log->notice("MYSQL_OPT_RECONNECT could not be set, connection drops may occur but will be counteracted.\n");
	temp2 = mysql_real_connect( temp, Hostname, Username, Password, DatabaseName, port, NULL, 0 );
	if( temp2 == NULL )
	{
		MyLog::log->notice("Connection failed due to: `%s`\n", mysql_error( temp ) );
		return false;
	}
	ConnectionSync = new MySQLDatabaseConnection;
	((MySQLDatabaseConnection*)ConnectionSync)->MySql = temp2;
/*
	temp = mysql_init( NULL );
	if(mysql_options(temp, MYSQL_SET_CHARSET_NAME, "utf8"))
		MyLog::log->notice("Could not set utf8 character set.");

	if (mysql_options(temp, MYSQL_OPT_RECONNECT, &my_true))
		MyLog::log->notice("MYSQL_OPT_RECONNECT could not be set, connection drops may occur but will be counteracted.");
	temp2 = mysql_real_connect( temp, Hostname, Username, Password, DatabaseName, port, NULL, 0 );
	if( temp2 == NULL )
	{
		MyLog::log->notice("Connection failed due to: `%s`", mysql_error( temp ) );
		return false;
	}
	ConnectionAsync = new MySQLDatabaseConnection;
	((MySQLDatabaseConnection*)ConnectionAsync)->MySql = temp2;
*/
	/*
	for( i = 0; i < ConnectionCount; ++i )
	{
		temp = mysql_init( NULL );
		if(mysql_options(temp, MYSQL_SET_CHARSET_NAME, "utf8"))
			Log.Error("MySQLDatabase", "Could not set utf8 character set.");

		if (mysql_options(temp, MYSQL_OPT_RECONNECT, &my_true))
			Log.Error("MySQLDatabase", "MYSQL_OPT_RECONNECT could not be set, connection drops may occur but will be counteracted.");

		temp2 = mysql_real_connect( temp, Hostname, Username, Password, DatabaseName, port, NULL, 0 );
		if( temp2 == NULL )
		{
			Log.Error("MySQLDatabase", "Connection failed due to: `%s`", mysql_error( temp ) );
			return false;
		}

		conns[i] = new MySQLDatabaseConnection;
		conns[i]->MySql = temp2;
	}
	*/
	Database::_Initialize();
	return true;
}

string MySQLDatabase::EscapeString(string Escape)
{
	char a2[10240] = {0};

	DatabaseConnection * con = GetFreeConnection();
	const char * ret;
	if(mysql_real_escape_string(static_cast<MySQLDatabaseConnection*>(con)->MySql, a2, Escape.c_str(), (unsigned long)Escape.length()) == 0)
		ret = Escape.c_str();
	else
		ret = a2;

	//con->Busy.Release();
	return string(ret);
}

void MySQLDatabase::EscapeLongString(const char * str, uint32 len, stringstream& out)
{
	char a2[10240] = {0};

	DatabaseConnection * con = GetFreeConnection();
	const char * ret;
	if(mysql_real_escape_string(static_cast<MySQLDatabaseConnection*>(con)->MySql, a2, str, (unsigned long)len) == 0)
		ret = str;
	else
		ret = a2;

	out.write(a2, (std::streamsize)strlen(a2));
	//con->Busy.Release();
}

string MySQLDatabase::EscapeString(const char * esc, DatabaseConnection * con)
{
	char a2[10240] = {0};
	const char * ret;
	if(mysql_real_escape_string(static_cast<MySQLDatabaseConnection*>(con)->MySql, a2, (char*)esc, (unsigned long)strlen(esc)) == 0)
		ret = esc;
	else
		ret = a2;

	return string(ret);
}

void MySQLDatabase::Shutdown()
{
	// TODO
}

bool MySQLDatabase::_SendQuery(DatabaseConnection *con, const char* Sql, bool Self)
{
	//MyLog::log->notice( "_SendQuery:[%s]", Sql );
	//dunno what it does ...leaving untouched
	int result = mysql_query(static_cast<MySQLDatabaseConnection*>(con)->MySql, Sql);
	if(result > 0)
	{
		if( Self == false && _HandleError(static_cast<MySQLDatabaseConnection*>(con), mysql_errno( static_cast<MySQLDatabaseConnection*>(con)->MySql ) ) )
		{
			// Re-send the query, the connection was successful.
			// The true on the end will prevent an endless loop here, as it will
			// stop after sending the query twice.
			result = _SendQuery(con, Sql, true);
		}
		else
			MyLog::log->notice("Sql query failed due to [%s], Query: [%s]\n", mysql_error( static_cast<MySQLDatabaseConnection*>(con)->MySql ), Sql);
	}

	return (result == 0 ? true : false);
}

bool MySQLDatabase::_HandleError(MySQLDatabaseConnection * con, uint32 ErrorNumber)
{
	// Handle errors that should cause a reconnect to the Database.
	switch(ErrorNumber)
	{
	case 2006:  // Mysql server has gone away
	case 2008:  // Client ran out of memory
	case 2013:  // Lost connection to sql server during query
	case 2055:  // Lost connection to sql server - system error
		{
			// Let's instruct a reconnect to the db when we encounter these errors.
			return _Reconnect( con );
		}break;
	}

	return false;
}

MySQLQueryResult::MySQLQueryResult(MYSQL_RES* res, uint32 FieldCount, uint32 RowCount) : QueryResult(FieldCount, RowCount), mResult( res )
{
	mCurrentRow = new Field[FieldCount];
}

MySQLQueryResult::~MySQLQueryResult()
{
	mysql_free_result(mResult);
	delete [] mCurrentRow;
}

bool MySQLQueryResult::NextRow()
{
	MYSQL_ROW row = mysql_fetch_row(mResult);
	if(row == NULL)
		return false;

	for(uint32 i = 0; i < mFieldCount; ++i)
		mCurrentRow[i].SetValue(row[i]);

	return true;
}

QueryResult * MySQLDatabase::_StoreQueryResult(DatabaseConnection * con)
{
	MySQLQueryResult * res;
	MySQLDatabaseConnection * db = static_cast<MySQLDatabaseConnection*>(con);
	MYSQL_RES * pRes = mysql_store_result( db->MySql );
	uint32 uRows = (uint32)mysql_affected_rows( db->MySql );
	uint32 uFields = (uint32)mysql_field_count( db->MySql );

	if( uRows == 0 || uFields == 0 || pRes == 0 )
	{
		if( pRes != NULL )
			mysql_free_result( pRes );

		return NULL;
	}

	res = new MySQLQueryResult( pRes, uFields, uRows );
	res->NextRow();

	return res;
}

bool MySQLDatabase::_Reconnect(MySQLDatabaseConnection * conn)
{
	MYSQL * temp, *temp2;

	temp = mysql_init( NULL );
	temp2 = mysql_real_connect( temp, mHostname.c_str(), mUsername.c_str(), mPassword.c_str(), mDatabaseName.c_str(), mPort, NULL , 0 );
	if( temp2 == NULL )
	{
		MyLog::log->notice("Could not reconnect to database because of `%s`", mysql_error( temp ) );
		mysql_close( temp );
		return false;
	}

	if( conn->MySql != NULL )
		mysql_close( conn->MySql );

	conn->MySql = temp;

	MyLog::log->notice( "reconnect database succeed! ip:%s", mHostname.c_str() );
	return true;
}

#endif
