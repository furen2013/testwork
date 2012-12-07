#ifndef ASIO_DEF_HEAD
#define ASIO_DEF_HEAD

#include "../utilities/utilities.h"
#define NET_FLOW_RATE_LOG			// define this macro for recording net flow rate log to file

#include "../utilities/mt_buffer.h"
#include "../utilities/call_back.h"

using boost::asio::ip::tcp;

class tcp_session;
class tcp_basesession;

struct message_t
{
	message_t() : from( NULL ), data( NULL ), len( 0 ) {}
//	message_t( const message_t& msg ) : data( msg.data ), len( msg.len ), from( msg.from ) {}
//	message_t( const char* p, unsigned int l, tcp_session* f ) : data( (char*)p ), len( l ), from( f ) {}

	tcp_basesession* from;
	char* data;
	unsigned int len;
};




static const int MAX_MESSAGE_LEN = 65000;
static const int MESSAGE_HEAD_LEN = 12;
static const int MESSAGE_BASIC_HEAD_LEN = 8;
static const int QUEUE_MESSAGE_LIMIT_SIZE = MAX_MESSAGE_LEN * 10;

struct compress_strategy
{
	virtual bool compress( char* dest, unsigned int* destlen, const char* src, unsigned int srclen ) = 0;
	virtual bool uncompress( char* dest, unsigned int* destlen, const char* src, unsigned int srclen ) = 0;
};

struct net_global
{
	class net_obj
	{
	public:
		virtual ~net_obj(){}
		virtual void thread_run_asio() = 0;
	};
	// internal
	static compress_strategy* get_compress_strategy();
	static bool is_need_max_speed();
	static void add_net_obj( net_obj* obj );
	static void del_net_obj( net_obj* obj );
	static void init_memory_for_speed();
	static void free_memory_for_speed();

	// external
	static boost::asio::io_service* get_io_service();
	static void set_compress_strategy( compress_strategy* imp );
	static void init_net_service( int thread_count, int proc_interval, compress_strategy* cs_imp, bool need_max_speed, int msg_pool_size );
	static message_t* get_message( unsigned short size );
	static message_t* messageclone(const message_t& p);
	static void free_message( message_t* p );
	static boost::uint32_t get_message_pool_used();
	static void free_net_service();
	static void stop_net_service();
	static long get_asio_thread_alive_count();
	static void write_close_log( const char* txt, ... );

	class asio_run_timer
	{
	public:
		asio_run_timer( boost::asio::io_service& io, int interval ) : m_t( io, boost::posix_time::milliseconds( interval ) ), m_exit( false ), m_interval( interval )
		{
			m_t.async_wait( boost::bind( &asio_run_timer::t_run, this ) );
		}
		virtual ~asio_run_timer()
		{
			stop();
		}

		void stop()
		{
			m_exit = true;
		}
		virtual void v_call() = 0;

		void t_run()
		{
			v_call();
			if( !m_exit )
			{
				m_t.expires_at( m_t.expires_at() + boost::posix_time::milliseconds( m_interval ) );
				m_t.async_wait( boost::bind( &asio_run_timer::t_run, this ) );
			}
		}
	private:
		volatile bool m_exit;
		boost::asio::deadline_timer m_t;
		int m_interval;
	};

	enum ban_reason_t
	{
		BAN_REASON_WRONG_CHECK_SUM,
		BAN_REASON_TOO_MANY_AUTH_FAIL,
		BAN_REASON_UNCOMPRESS_FAIL,
		BAN_REASON_HACK_PACKET,
		BAN_REASON_TOO_MANY_PACKET,
		BAN_REASON_TOO_MANY_IDLE_CONNECTION
	};
};

//using namespace net_global;

#endif
