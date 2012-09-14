#include "DatabaseEnv.h"
#include "../CrashHandler.h"
#include <mysql/mysql.h>

std::list<Database*> Database::s_listDatabase;
volatile bool Database::s_IsQuit = false;
boost::thread* Database::s_pThread = NULL;
volatile long Database::s_qcount = 0;
boost::mutex Database::s_mutex;
boost::condition Database::s_cond;

SQLCallbackBase::~SQLCallbackBase()
{

}

Database::Database()
{
	_counter=0;
	ConnectionSync = NULL;
	ConnectionAsync = NULL;
	mConnectionCount = -1;   // Not connected.
	ThreadRunning = true;
}

Database::~Database()
{
	s_listDatabase.remove( this );
	if( s_listDatabase.size() == 0 && s_pThread )
	{
		s_IsQuit = true;
		s_pThread->join();
		delete s_pThread;
		s_pThread = NULL;
	}
}

void Database::_Initialize()
{
	//m_pQueryThread = new boost::thread( boost::bind( &Database::QueryThreadRun, this ) );
	s_listDatabase.push_back( this );
}

DatabaseConnection * Database::GetFreeConnection( bool bIsSync )
{
//	if( bIsSync )
		return ConnectionSync;
//	else
//		return ConnectionAsync;
}


QueryResult * Database::Query(const char* QueryString, ...)
{
	char sql[4096];
	va_list vlist;
	va_start(vlist, QueryString);
	vsnprintf(sql, 4096, QueryString, vlist);
	va_end(vlist);

	// Send the query
	QueryResult * qResult = NULL;
	DatabaseConnection * con = GetFreeConnection();

	qResult = FQuery( sql, con );

	return qResult;
}

QueryResult * Database::QueryNA(const char* QueryString)
{
	// Send the query
	QueryResult * qResult = NULL;
	DatabaseConnection * con = GetFreeConnection();

	qResult = FQuery( QueryString, con );

	return qResult;
}

QueryResult * Database::FQuery(const char * QueryString, DatabaseConnection * con)
{
	// Send the query
	QueryResult * qResult = NULL;
	boost::mutex::scoped_lock lock( m_mutex );
	if( _SendQuery( con, QueryString, false ) )
		qResult = _StoreQueryResult( con );

	return qResult;
}

void Database::FWaitExecute(const char * QueryString, DatabaseConnection * con)
{
	// Send the query
	boost::mutex::scoped_lock lock( m_mutex );
	_SendQuery( con, QueryString, false );
}

void QueryBuffer::AddQuery(const char * format, ...)
{
	char query[4096];
	va_list vlist;
	va_start(vlist, format);
	vsnprintf(query, 4096, format, vlist);
	va_end(vlist);

	queries.push_back( strdup( query ) );
}

void QueryBuffer::AddQueryNA( const char * str )
{
	queries.push_back( strdup( str ) );
}

void QueryBuffer::AddQueryStr(const string& str)
{
	queries.push_back( strdup( str.c_str() ) );
}

void Database::PerformQueryBuffer(QueryBuffer * b, DatabaseConnection * ccon)
{
	if(!b->queries.size())
		return;

    DatabaseConnection * con = ccon;
	if( ccon == NULL )
		con = GetFreeConnection();

	boost::mutex::scoped_lock lock( m_mutex );
	BeginTransaction(con);

	for(vector<char*>::iterator itr = b->queries.begin(); itr != b->queries.end(); ++itr)
	{
		_SendQuery(con, *itr, false);
		free( *itr );
	}

	EndTransaction(con);
}

bool Database::Execute(const char* QueryString, ...)
{
	char query[4096];

	va_list vlist;
	va_start(vlist, QueryString);
	vsnprintf(query, 4096, QueryString, vlist);
	va_end(vlist);
	ExecuteNA( query );
	return true;
}

bool Database::ExecuteNA(const char* QueryString)
{
	char * pBuffer = strdup( QueryString );
	{
		boost::mutex::scoped_lock lock( m_mutexBP );
		m_queueQueryBeforeProc.push( (AsyncQuery*)pBuffer );
	}
	boost::mutex::scoped_lock lock( s_mutex );
	++s_qcount;
	s_cond.notify_one();
	return true;
}

//this will wait for completion
bool Database::WaitExecute(const char* QueryString, ...)
{
	char sql[4096];
	va_list vlist;
	va_start(vlist, QueryString);
	vsnprintf(sql, 4096, QueryString, vlist);
	va_end(vlist);

	return WaitExecuteNA( sql );
}


QueryResult* Database::TransactionQuery( const char* QueryString, ... )
{
	char sql[4096];
	va_list vlist;
	va_start(vlist, QueryString);
	vsnprintf(sql, 4096, QueryString, vlist);
	va_end(vlist);

	// Send the query
	DatabaseConnection * con = GetFreeConnection();
	QueryResult * qResult = NULL;
	if( _SendQuery( con,sql, false ) )
		qResult = _StoreQueryResult( con );

	return qResult;
}

bool Database::TransactionExecute( const char* QueryString, ... )
{
	char sql[4096];
	va_list vlist;
	va_start(vlist, QueryString);
	vsnprintf(sql, 4096, QueryString, vlist);
	va_end(vlist);
	DatabaseConnection* con = GetFreeConnection();
	return _SendQuery( con, sql, false );
}

bool Database::WaitExecuteNA(const char* QueryString)
{
	DatabaseConnection * con = GetFreeConnection();
	boost::mutex::scoped_lock lock( m_mutex );
	return _SendQuery(con, QueryString, false);
}

void AsyncQuery::AddQuery(const char * format, ...)
{
	AsyncQueryResult res;
	va_list ap;
	char buffer[4096];
	va_start(ap, format);
	vsnprintf(buffer, 4096, format, ap);
	va_end(ap);
	res.query = strdup( buffer );
	res.result = NULL;
	queries.push_back(res);
}

void AsyncQuery::Perform()
{
	DatabaseConnection * conn = db->GetFreeConnection( false );
	for(vector<AsyncQueryResult>::iterator itr = queries.begin(); itr != queries.end(); ++itr)
		itr->result = db->FQuery(itr->query, conn);
}

void AsyncQuery::Callback()
{
	try
	{
		func->run( queries );
	}
	catch( ... )
	{

	}
	delete this;
}

AsyncQuery::~AsyncQuery()
{
	delete func;
	for(vector<AsyncQueryResult>::iterator itr = queries.begin(); itr != queries.end(); ++itr)
	{
		if(itr->result)
			delete itr->result;

		free( itr->query );
	}
}

void Database::EndThreads()
{
}

void Database::thread_proc_query()
{
}

void Database::QueueAsyncQuery(AsyncQuery * query)
{
	query->db = this;
	{
		boost::mutex::scoped_lock lock( m_mutexBP );
		m_queueQueryBeforeProc.push( query );
	}
	boost::mutex::scoped_lock lock( s_mutex );
	++s_qcount;
	s_cond.notify_one();
}

void Database::AddQueryBuffer(QueryBuffer * b)
{
	PerformQueryBuffer( b, NULL );
	delete b;
}

void Database::FreeQueryResult(QueryResult * p)
{
	delete p;
}

// added by guixiaoyu

void Database::QueryTaskRun()
{
	std::queue<AsyncQuery*> q;
	{
		boost::mutex::scoped_lock lock( m_mutexAP );
		if( !m_queueQueryAfterProc.empty() )
			std::swap( q, m_queueQueryAfterProc );
	}
	while( !q.empty() )
	{
		AsyncQuery* p = q.front();
		q.pop();
		p->Callback();
	}
}

void Database::QueryThreadRun()
{
	std::queue<AsyncQuery*> q;
	{
		boost::mutex::scoped_lock sl( m_mutexBP );
		if( !m_queueQueryBeforeProc.empty() )
			std::swap( q, m_queueQueryBeforeProc );
		else
			return;
	}

	{
		boost::mutex::scoped_lock lock( s_mutex );
		s_qcount -= q.size();
	}
	std::vector<char*> v;
	while( !q.empty() )
	{
		AsyncQuery* p = q.front();
		q.pop();
		if( p->type_recognise == 0 )
		{
			p->Perform();
			boost::mutex::scoped_lock sl( m_mutexAP );
			m_queueQueryAfterProc.push( p );
		}
		else
			v.push_back( (char*)p );
	}
	if( v.size() == 0 )
		return;

	scoped_sql_transaction_proc sstp( this );
	DatabaseConnection * con = GetFreeConnection( false );
	for( size_t i = 0; i < v.size(); ++i )
	{
		char* p = v[i];
		{
			if( 0 != strnicmp( p, "select", 6 ) )
			{
				_SendQuery(con, p, false);
			}
			else
				assert( 0 && "execute a select command" );
		}
		free( p );
	}
	sstp.success();
}

void Database::DatabaseThreadRun()
{
	mysql_thread_init();
	while( !s_IsQuit )
	{
		{
			boost::mutex::scoped_lock lock( s_mutex );
			if( !s_qcount )
			{
				boost::xtime xt;
				boost::xtime_get( &xt, boost::TIME_UTC_ );
				xt.nsec += 10000000;
				if( !s_cond.timed_wait( lock, xt ) )
					continue;
			}
		}
		std::for_each( s_listDatabase.begin(), s_listDatabase.end(), std::mem_fun( &Database::QueryThreadRun ) );
	}
	mysql_thread_end();
}

void Database::StartThread()
{
	if( !s_pThread )
	{
		s_IsQuit = false;
		s_pThread = new boost::thread( &Database::DatabaseThreadRun );
	}
}
