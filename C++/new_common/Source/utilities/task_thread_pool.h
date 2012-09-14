#ifndef _TASK_THREAD_POOL_HEAD_
#define _TASK_THREAD_POOL_HEAD_

#include <boost/thread.hpp>
#include <boost/thread/condition.hpp>
#include <queue>

struct task
{
	virtual ~task() {}
	virtual void execute() = 0;
	virtual void end() = 0;
	virtual int get_thread_index() = 0;
};

class task_thread_pool;

class task_thread
{
public:
	task_thread();
	~task_thread();

public:
	void set_father( int index, task_thread_pool* father );
	void run();
	void push( task* p );
	
private:
	std::queue<task*> m_tasks;
	std::queue<task*> m_swap_tasks;
	boost::thread* m_thread;
	boost::mutex m_mutex;
	boost::condition m_cond;
	volatile bool m_exit;
	task_thread_pool* m_father;
	int m_index;
};


class task_thread_pool
{
public:
	task_thread_pool();
	~task_thread_pool();

public:
	void startup( int thread_count );
	void shutdown();
	void push_task( task* p );

private:
	int m_thread_count;
	task_thread* m_threads;
	std::queue<task*> m_swap_tasks;
	std::queue<task*> m_waiting_tasks;
	boost::mutex m_mutex;
};


#endif // _TASK_THREAD_POOL_HEAD_