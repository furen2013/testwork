#pragma once


#include "time.h"

#include <string>
#include <vector>
#include <map>
#include <list>

extern time_t UNIXTIME;		/* update this every loop to avoid the time() syscall! */
extern tm g_localTime;

using namespace std;


