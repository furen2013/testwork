#ifndef _THREADING_LOCKED_QUEUE_H
#define _THREADING_LOCKED_QUEUE_H
#include "Common.h"
#include "Mutex.h"
#include <deque>

template<class TYPE>
class LockedQueue
{
public:
	~LockedQueue()
	{

	}

	SUNYOU_INLINE void add(const TYPE& element)
	{
		mutex.Acquire();
		queue.push_back(element);
		mutex.Release();
	}

	SUNYOU_INLINE TYPE next()
	{
		mutex.Acquire();
		assert(queue.size() > 0);
		TYPE t = queue.front();
		queue.pop_front();
		mutex.Release();
		return t;
	}

	SUNYOU_INLINE size_t size()
	{
		mutex.Acquire();
		size_t c = queue.size();
		mutex.Release();
		return c;
	}

	SUNYOU_INLINE TYPE get_first_element()
	{
		mutex.Acquire();
		TYPE t;
		if(queue.size() == 0)
			t = reinterpret_cast<TYPE>(0);
		else
			t = queue.front();
		mutex.Release();
		return t;
	}

	SUNYOU_INLINE void pop()
	{
		mutex.Acquire();
		assert(queue.size() > 0);
		queue.pop_front();
		mutex.Release();
	}

protected:
	std::deque<TYPE> queue;
	Mutex mutex;
};

#endif
