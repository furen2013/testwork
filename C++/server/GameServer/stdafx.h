// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>


#include "../Common/Platform/SystemConfig.h"
#include "../Common/Platform/Util.h"
#include "../Common/share/Common.h"
#include "stdio.h"
#include "stdlib.h"
#include "svn_revision.h"
#include "Config/Config.h"


//#include "Server.h"

//#include "Config.h"
//#include "UserManager.h"

#include "../../new_common/Source/net/tcpclient.h"
#include "../../new_common/Source/log4cpp-1.0/MyLog.h"
// TODO: reference additional headers your program requires here
extern time_t UNIXTIME;		/* update this every loop to avoid the time() syscall! */
extern tm g_localTime;
extern FILE* g_fpLogConnection;
