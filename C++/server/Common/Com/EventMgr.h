/*
 * ArcEmu MMORPG Server
 * Copyright (C) 2005-2007 Ascent Team <http://www.ascentemu.com/>
 * Copyright (C) 2008-2012 <http://www.ArcEmu.org/>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef __EVENTMGR_H
#define __EVENTMGR_H
#include "../share/Singleton.h"
#include "../share/TypeDef.h"
#include "../share/Threading/RWLock.h"
#include "../share/CallBack.h"
enum EventTypes
{
	PLOUGHCELL_BECOME_YOUNG,
	PLOUGHCELL_BECOME_GROWN,
	PLOUGHCELL_DECREASE_WATER,
	FARM_SYNSAVE,
	TECHNOLOGY_SYNSAVE,
    NUM_EVENT_TYPES
};

enum EventFlags
{
    EVENT_FLAG_DO_NOT_EXECUTE_IN_WORLD_CONTEXT = 0x1,
    EVENT_FLAG_DELETES_OBJECT				   = 0x2,
};

struct  TimedEvent
{
	TimedEvent(void* object, CallbackBase* callback, uint32 type, time_t time, uint32 repeat, uint32 flags) :
		obj(object), cb(callback), eventType(type), eventFlag(static_cast<uint16>(flags)), msTime(time), currTime(time), repeats(static_cast<uint16>(repeat)), deleted(false), ref(0) {}

	void* obj;
	CallbackBase* cb;
	uint32 eventType;
	uint16 eventFlag;
	time_t msTime;
	time_t currTime;
	uint16 repeats;
	bool deleted;
	int instanceId;
	AtomicCounter ref;

	static TimedEvent* Allocate(void* object, CallbackBase* callback, uint32 flags, time_t time, uint32 repeat);


	void DecRef()
	{
		if(--ref == 0)
		{
			delete cb;
			delete this;
		}
	}

	void IncRef() { ++ref; }
};

class EventMgr;
class EventableObjectHolder;
typedef map<int32, EventableObjectHolder*> HolderMap;

class  EventMgr : public Singleton < EventMgr >
{
		friend class MiniEventMgr;
	public:
		template <class Class>
		void AddEvent(Class* obj, void (Class::*method)(), uint32 type, time_t time, uint32 repeats, uint32 flags)
		{
			// create a timed event
			TimedEvent* event = new TimedEvent(obj, new CallbackP0<Class>(obj, method), type, time, repeats, flags);

			// add this to the object's list, updating will all be done later on...
			obj->event_AddEvent(event);
		}

		template <class Class, typename P1>
		void AddEvent(Class* obj, void (Class::*method)(P1), P1 p1, uint32 type, time_t time, uint32 repeats, uint32 flags)
		{
			// create a timed event
			TimedEvent* event = new TimedEvent(obj, new CallbackP1<Class, P1>(obj, method, p1), type, time, repeats, flags);

			// add this to the object's list, updating will all be done later on...
			obj->event_AddEvent(event);
		}

		template <class Class, typename P1, typename P2>
		void AddEvent(Class* obj, void (Class::*method)(P1, P2), P1 p1, P2 p2, uint32 type, time_t time, uint32 repeats, uint32 flags)
		{
			// create a timed event
			TimedEvent* event = new TimedEvent(obj, new CallbackP2<Class, P1, P2>(obj, method, p1, p2), type, time, repeats, flags);

			// add this to the object's list, updating will all be done later on...
			obj->event_AddEvent(event);
		}

		template <class Class, typename P1, typename P2, typename P3>
		void AddEvent(Class* obj, void (Class::*method)(P1, P2, P3), P1 p1, P2 p2, P3 p3, uint32 type, time_t time, uint32 repeats, uint32 flags)
		{
			// create a timed event
			TimedEvent* event = new TimedEvent(obj, new CallbackP3<Class, P1, P2, P3>(obj, method, p1, p2, p3), type, time, repeats, flags);

			// add this to the object's list, updating will all be done later on...
			obj->event_AddEvent(event);
		}

		template <class Class, typename P1, typename P2, typename P3, typename P4>
		void AddEvent(Class* obj, void (Class::*method)(P1, P2, P3, P4), P1 p1, P2 p2, P3 p3, P4 p4, uint32 type, time_t time, uint32 repeats, uint32 flags)
		{
			// create a timed event
			TimedEvent* event = new TimedEvent(obj, new CallbackP4<Class, P1, P2, P3, P4>(obj, method, p1, p2, p3, p4), type, time, repeats, flags);

			// add this to the object's list, updating will all be done later on...
			obj->event_AddEvent(event);
		}

		// Please remember the Aura class will call remove events!
		/* Example:
		Aura::Virtual_Destructor calls: EventableObject::Virtual_Destructor & sEventMgr.RemoveEvents( this );
		*/

		template <class Class> void RemoveEvents(Class* obj) { obj->event_RemoveEvents(static_cast<uint32>(-1)); }
		template <class Class> void RemoveEvents(Class* obj, int32 type)
		{
			obj->event_RemoveEvents(type);
		}

		template <class Class> void ModifyEventTimeLeft(Class* obj, uint32 type, time_t time, bool unconditioned = true)
		{
			obj->event_ModifyTimeLeft(type, time, unconditioned);
		}

		template <class Class> void ModifyEventTimeAndTimeLeft(Class* obj, uint32 type, time_t time)
		{
			obj->event_ModifyTimeAndTimeLeft(type, time);
		}

		template <class Class> void ModifyEventTime(Class* obj, uint32 type, time_t time)
		{
			obj->event_ModifyTime(type, time);
		}

		template <class Class> bool HasEvent(Class* obj, uint32 type)
		{
			return obj->event_HasEvent(type);
		}

		EventableObjectHolder* GetEventHolder(int32 InstanceId)
		{
			holderLock.AcquireReadLock();

			HolderMap::iterator itr = mHolders.find(InstanceId);

			if(itr == mHolders.end())
			{
				holderLock.ReleaseReadLock();
				return 0;
			}

			holderLock.ReleaseReadLock();

			return itr->second;
		}

		void AddEventHolder(EventableObjectHolder* holder, int32 InstanceId)
		{
			holderLock.AcquireWriteLock();
			mHolders.insert(HolderMap::value_type(InstanceId, holder));
			holderLock.ReleaseWriteLock();
		}

		void RemoveEventHolder(int32 InstanceId)
		{
			holderLock.AcquireWriteLock();
			mHolders.erase(InstanceId);
			holderLock.ReleaseWriteLock();
		}

		void RemoveEventHolder(EventableObjectHolder* holder)
		{
			holderLock.AcquireWriteLock();
			HolderMap::iterator itr = mHolders.begin();
			for(; itr != mHolders.end(); ++itr)
			{
				if(itr->second == holder)
				{
					mHolders.erase(itr);
					holderLock.ReleaseWriteLock();
					return;
				}
			}
			holderLock.ReleaseWriteLock();
		}

	protected:
		HolderMap mHolders;
		RWLock holderLock;
};

#define sEventMgr EventMgr::getSingleton()

#endif
