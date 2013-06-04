#pragma once
#ifndef WORLD_H
#define WORLD_H
#include "EventableObject.h"
#include "share/Database/Database.h"
#include "share/Database/DatabaseEnv.h"
class World : public Singleton<World>, public EventableObject
{
public:
	World();
	~World();
public:
	void Init();
	void Run();
	bool ExecuteSqlToDBServer( QueryBuffer* buf );
	bool ExecuteSqlToDBServer( const char* sql, ... );
};
#endif