#if !defined(DATABASEENV_H)
#define DATABASEENV_H

//! Other libs we depend on.
#include "Common.h"
#include "Singleton.h"
#include "CThreads.h"

//! Our own includes.
#include "Field.h"
#include "Database.h"

extern Database * Database_World;
extern Database * Database_Character;

#define WorldDatabase (*Database_World)
#define CharacterDatabase (*Database_Character)

#endif
