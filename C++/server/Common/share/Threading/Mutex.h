#ifndef _THREADING_MUTEX_H
#define _THREADING_MUTEX_H

class Mutex
{
public:
	friend class Condition;

	/** Initializes a mutex class, with InitializeCriticalSection / pthread_mutex_init
	 */
	Mutex();

	/** Deletes the associated critical section / mutex
	 */
	~Mutex();

	/** Acquires this mutex. If it cannot be acquired immediately, it will block.
	 */
	SUNYOU_INLINE void Acquire()
	{
#ifndef _WIN32
		pthread_mutex_lock(&mutex);
#else
		EnterCriticalSection(&cs);
#endif
	}

	/** Releases this mutex. No error checking performed
	 */
	SUNYOU_INLINE void Release()
	{
#ifndef _WIN32
		pthread_mutex_unlock(&mutex);
#else
		LeaveCriticalSection(&cs);
#endif
	}

	/** Attempts to acquire this mutex. If it cannot be acquired (held by another thread)
	 * it will return false.
	 * @return false if cannot be acquired, true if it was acquired.
	 */
	SUNYOU_INLINE bool AttemptAcquire()
	{
#ifndef _WIN32
		return (pthread_mutex_trylock(&mutex) == 0);
#else
		return true;/*(TryEnterCriticalSection(&cs) == TRUE ? true : false);*/
#endif
	}

protected:
#ifdef _WIN32
	/** Critical section used for system calls
	 */
	CRITICAL_SECTION cs;

#else
	/** Static mutex attribute
	 */
	static bool attr_initalized;
	static pthread_mutexattr_t attr;

	/** pthread struct used in system calls
	 */
	pthread_mutex_t mutex;
#endif
};

#ifdef _WIN32

class FastMutex
{
	volatile long m_lock;
	DWORD m_recursiveCount;

public:
	SUNYOU_INLINE FastMutex() : m_lock(0),m_recursiveCount(0) {}
	SUNYOU_INLINE ~FastMutex() {}

	SUNYOU_INLINE void Acquire()
	{
		DWORD thread_id = GetCurrentThreadId(), owner;
		if(thread_id == (DWORD)m_lock)
		{
			++m_recursiveCount;
			return;
		}

		for(;;)
		{
			owner = InterlockedCompareExchange(&m_lock, thread_id, 0);
			if(owner == 0)
				break;

			Sleep(0);
		}

		++m_recursiveCount;
	}

	SUNYOU_INLINE bool AttemptAcquire()
	{
		DWORD thread_id = GetCurrentThreadId();
		if(thread_id == (DWORD)m_lock)
		{
			++m_recursiveCount;
			return true;
		}

		DWORD owner = InterlockedCompareExchange(&m_lock, thread_id, 0);
		if(owner == 0)
		{
			++m_recursiveCount;
			return true;
		}

		return false;
	}

	SUNYOU_INLINE void Release()
	{
		if((--m_recursiveCount) == 0)
			InterlockedExchange(&m_lock, 0);
	}
};

#else

#define FastMutex Mutex

#endif

#endif

