// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 项目特定的包含文件
#pragma once

#include <list>
#include <deque>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

#define _ACTIVITY_PROTOCOL
#include "TypeDef.h"
#include "../Common/share/Common.h"
#include "../Common/Platform/SystemConfig.h"
#include "../Common/Platform/Util.h"

#include "stdio.h"
#include "stdlib.h"
#include "svn_revision.h"
#include "Config/Config.h"

//
//#include "Server.h"
//
//#include "Config.h"
//#include "UserManager.h"

#include "../../new_common/Source/net/tcpclient.h"
#include "../../new_common/Source/log4cpp-1.0/MyLog.h"

extern time_t UNIXTIME;		/* update this every loop to avoid the time() syscall! */
extern tm g_localTime;
extern FILE* g_fpLogConnection;

