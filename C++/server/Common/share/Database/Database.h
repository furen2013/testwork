#ifndef _DATABASE_H
#define _DATABASE_H

#include <string>
#include "CThreads.h"
#include "../Threading/Queue.h"
#include "../CallBack.h"
#include "Field.h"
#include <boost/thread/thread.hpp>
#include <boost/thread/condition.hpp>

using namespace std;
class QueryResult;
class Database;

struct DatabaseConnection
{
	//FastMutex Busy;
};

struct AsyncQueryResult
{
	QueryResult * result;
	char * query;
};

class AsyncQuery
{
	friend class Database;
	char type_recognise;
	SQLCallbackBase * func;
	vector<AsyncQueryResult> queries;
	Database * db;
public:
	AsyncQuery(SQLCallbackBase * f) : func(f), type_recognise( 0 ) {}
	~AsyncQuery();
	void AddQuery(const char * format, ...);
	void Perform();
	void Callback();
	SUNYOU_INLINE void SetDB(Database * dbb) { db = dbb; }
};

class QueryBuffer
{
	vector<char*> queries;
public:
	friend class Database;
	void AddQuery( const char * format, ... );
	void AddQueryNA( const char * str );
	void AddQueryStr(const string& str);
};

class Database
{
	friend class AsyncQuery;
public:
	Database();
	virtual ~Database();

	/************************************************************************/
	/* Virtual Functions                                                    */
	/************************************************************************/
	virtual bool Initialize(const char* Hostname, unsigned int port,
		const char* Username, const char* Password, const char* DatabaseName,
		uint32 ConnectionCount, uint32 BufferSize) = 0;

	virtual void Shutdown() = 0;

	virtual QueryResult* Query(const char* QueryString, ...);
	virtual QueryResult* QueryNA(const char* QueryString);
	virtual QueryResult * FQuery(const char * QueryString, DatabaseConnection * con);
	virtual void FWaitExecute(const char * QueryString, DatabaseConnection * con);
	virtual bool WaitExecute(const char* QueryString, ...);//Wait For Request Completion
	virtual bool WaitExecuteNA(const char* QueryString);//Wait For Request Completion
	virtual bool Execute(const char* QueryString, ...);
	virtual bool ExecuteNA(const char* QueryString);

	QueryResult* TransactionQuery( const char* QueryString, ... );
	bool TransactionExecute( const char* QueryString, ... );

	bool ThreadRunning;

	SUNYOU_INLINE const string& GetHostName() { return mHostname; }
	SUNYOU_INLINE const string& GetDatabaseName() { return mDatabaseName; }
	SUNYOU_INLINE const uint32 GetQueueSize() { return queries_queue.get_size(); }

	virtual string EscapeString(string Escape) = 0;
	virtual void EscapeLongString(const char * str, uint32 len, stringstream& out) = 0;
	virtual string EscapeString(const char * esc, DatabaseConnection * con) = 0;

	void QueueAsyncQuery(AsyncQuery * query);
	template<class Class> bool PAsyncQuery(Class *object, void (Class::*method)(QueryResultVector&), const char *sql);
	template<class Class, typename ParamType1> bool PAsyncQuery(Class *object, void (Class::*method)(QueryResultVector&, ParamType1), ParamType1 param1, const char *sql);

	void EndThreads();

	void thread_proc_query();
	void FreeQueryResult(QueryResult * p);

	DatabaseConnection * GetFreeConnection( bool bIsSync = true );

	void PerformQueryBuffer(QueryBuffer * b, DatabaseConnection * ccon);
	void AddQueryBuffer(QueryBuffer * b);

	static Database * CreateDatabaseInterface(uint32 uType);
	boost::mutex& GetMutex() { return m_mutex; }

	virtual bool SupportsReplaceInto() = 0;
	virtual bool SupportsTableLocking() = 0;

	virtual void BeginTransaction(DatabaseConnection* conn) = 0;
	virtual void EndTransaction(DatabaseConnection* conn) = 0;
	virtual void RollbackTransaction(DatabaseConnection* conn) = 0;

protected:

	// spawn threads and shizzle
	void _Initialize();

	// actual query function
	virtual bool _SendQuery(DatabaseConnection *con, const char* Sql, bool Self) = 0;
	virtual QueryResult * _StoreQueryResult(DatabaseConnection * con) = 0;

	////////////////////////////////
	FQueue<QueryBuffer*> query_buffer;

	////////////////////////////////
	FQueue<char*> queries_queue;
	DatabaseConnection* ConnectionSync;
	DatabaseConnection* ConnectionAsync;

	uint32 _counter;
	///////////////////////////////

	int32 mConnectionCount;

	// For reconnecting a broken connection
	string mHostname;
	string mUsername;
	string mPassword;
	string mDatabaseName;
	uint32 mPort;
	// added by guixiaoyu
public:
	static void DatabaseThreadRun();
	static std::list<Database*> s_listDatabase;
	static volatile bool s_IsQuit;
	static boost::thread* s_pThread;
	static boost::mutex s_mutex;
	static boost::condition s_cond;
	static volatile long s_qcount;
	static void StartThread();

public:
	void QueryTaskRun();

protected:
	void QueryThreadRun();
	boost::mutex m_mutexBP;
	boost::mutex m_mutexAP;
	boost::mutex m_mutex;
	boost::thread* m_pQueryThread;
	std::queue<AsyncQuery*> m_queueQueryBeforeProc;
	std::queue<AsyncQuery*> m_queueQueryAfterProc;
};
template<class Class>
bool
Database::PAsyncQuery(Class *object, void (Class::*method)(QueryResultVector&), const char *sql)
{
	if (!sql) return false;
	AsyncQuery * q = new AsyncQuery( new SQLClassCallbackP0<Class>(object, method) );
	q->AddQuery(sql);
	this->QueueAsyncQuery(q);
	return true;
}
template<class Class, typename ParamType1>
bool
Database::PAsyncQuery(Class *object, void (Class::*method)(QueryResultVector&, ParamType1), ParamType1 param1, const char *sql)
{
	if (!sql) return false;
	AsyncQuery * q = new AsyncQuery( new SQLClassCallbackP1<Class, ParamType1>(object, method, param1) );
	q->AddQuery(sql, param1);
	this->QueueAsyncQuery(q);
	return true;
}


class QueryResult
{
public:
	QueryResult(uint32 fields, uint32 rows) : mFieldCount(fields), mRowCount(rows), mCurrentRow(NULL) {}
	virtual ~QueryResult() {}

	virtual bool NextRow() = 0;
	void Delete() { delete this; }

	SUNYOU_INLINE Field* Fetch() { return mCurrentRow; }
	SUNYOU_INLINE uint32 GetFieldCount() const { return mFieldCount; }
	SUNYOU_INLINE uint32 GetRowCount() const { return mRowCount; }
	SUNYOU_INLINE Field* operator []( int i ) { return &mCurrentRow[i]; }

protected:
	uint32 mFieldCount;
	uint32 mRowCount;
        Field *mCurrentRow;
};

// for security reason - gui
class scoped_sql_transaction_proc : public boost::noncopyable
{
public:
	scoped_sql_transaction_proc( Database* p1 ) : m_success( false )
	{
		m_list_db.push_back( p1 );
		start();
	}
	scoped_sql_transaction_proc( Database* p1, Database* p2 ) : m_success( false )
	{
		m_list_db.push_back( p1 );
		m_list_db.push_back( p2 );
		start();
	}
	scoped_sql_transaction_proc( Database* p1, Database* p2, Database* p3 ) : m_success( false )
	{
		m_list_db.push_back( p1 );
		m_list_db.push_back( p2 );
		m_list_db.push_back( p3 );
		start();
	}
	~scoped_sql_transaction_proc()
	{
		if( m_success )
		{
			for( std::list<Database*>::iterator it = m_list_db.begin(); it != m_list_db.end(); ++it )
				(*it)->EndTransaction( (*it)->GetFreeConnection() );
		}
		else
		{
			for( std::list<Database*>::iterator it = m_list_db.begin(); it != m_list_db.end(); ++it )
				(*it)->RollbackTransaction( (*it)->GetFreeConnection() );
		}
		for( std::list<boost::mutex::scoped_lock*>::iterator it = m_list_lock.begin(); it != m_list_lock.end(); ++it )
			delete *it;
	}
	void success()
	{
		m_success = true;
	}

private:
	void start()
	{
		for( std::list<Database*>::iterator it = m_list_db.begin(); it != m_list_db.end(); ++it )
		{
			Database* db = *it;
			boost::mutex::scoped_lock* lock = new boost::mutex::scoped_lock( db->GetMutex() );
			db->BeginTransaction( db->GetFreeConnection() );
			m_list_lock.push_back( lock );
		}
	}
	bool m_success;
	std::list<Database*> m_list_db;
	std::list<boost::mutex::scoped_lock*> m_list_lock;
};

#endif
