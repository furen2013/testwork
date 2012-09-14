#ifndef __MYSQLDATABASE_H
#define __MYSQLDATABASE_H

#include <mysql/mysql.h>

struct MySQLDatabaseConnection : public DatabaseConnection
{
	MYSQL * MySql;
};

class MySQLDatabase : public Database
{
	friend class QueryThread;
	friend class AsyncQuery;
public:
	MySQLDatabase();
	virtual ~MySQLDatabase();

	virtual bool Initialize(const char* Hostname, unsigned int port,
		const char* Username, const char* Password, const char* DatabaseName,
		uint32 ConnectionCount, uint32 BufferSize);

	virtual void Shutdown();

	string EscapeString(string Escape);
	void EscapeLongString(const char * str, uint32 len, stringstream& out);
	string EscapeString(const char * esc, DatabaseConnection * con);

	bool SupportsReplaceInto() { return true; }
	bool SupportsTableLocking() { return true; }

	virtual void BeginTransaction(DatabaseConnection* conn);
	virtual void EndTransaction(DatabaseConnection* conn);
	virtual void RollbackTransaction(DatabaseConnection* conn);


protected:

	bool _HandleError(MySQLDatabaseConnection*, uint32 ErrorNumber);
	bool _SendQuery(DatabaseConnection *con, const char* Sql, bool Self = false);

	bool _Reconnect(MySQLDatabaseConnection * conn);

	QueryResult * _StoreQueryResult(DatabaseConnection * con);
};

class MySQLQueryResult : public QueryResult
{
public:
	MySQLQueryResult(MYSQL_RES* res, uint32 FieldCount, uint32 RowCount);
	~MySQLQueryResult();

	bool NextRow();

protected:
	MYSQL_RES* mResult;
};

#endif		// __MYSQLDATABASE_H
