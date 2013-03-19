#pragma once
#ifndef NETSESSION_H
#define NETSESSION_H
#include "TypeDef.h"
class NetSession
{
public:
	NetSession();
	~NetSession();
protected:
	DWORD account;
};
#endif