#pragma once
#ifndef WORLD_H
#define WORLD_H
#include "EventableObject.h"
#include "share/Database/Database.h"
#include "share/Database/DatabaseEnv.h"
class EventableObjectHolder;
class World : public Singleton<World>, public EventableObject
{
public:
	World();
	~World();
public:
	void Init();
	void Run(uint32 time_difference);
	bool ExecuteSqlToDBServer( QueryBuffer* buf );
	bool ExecuteSqlToDBServer( const char* sql, ... );
protected:
	EventableObjectHolder* _holder;
};
#endif