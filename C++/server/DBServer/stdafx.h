// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 项目特定的包含文件

#pragma once

#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN		// 从 Windows 标头中排除不常使用的资料
#endif

// 如果您必须使用下列所指定的平台之前的平台，则修改下面的定义。
// 有关不同平台的相应值的最新信息，请参考 MSDN。
#ifdef _WIN32
#ifndef WINVER				// 允许使用 Windows 95 和 Windows NT 4 或更高版本的特定功能。
#define WINVER 0x0400		//为 Windows98 和 Windows 2000 及更新版本改变为适当的值。
#endif

#ifndef _WIN32_WINNT		// 允许使用 Windows NT 4 或更高版本的特定功能。
#define _WIN32_WINNT 0x0400		//为 Windows98 和 Windows 2000 及更新版本改变为适当的值。
#endif
#endif

#include "../../SDBase/Public/TypeDef.h"
#include "../../SDBase/Public/Timer.h"
#include "../../SDBase/Public/UnitDef.h"
#include "../Common/Platform/SystemConfig.h"
#include "Config/Config.h"
#include "Database/Database.h"
#include "Database/DatabaseEnv.h"
#include "Singleton.h"
#include "stdio.h"
#include "stdlib.h"
#include "Com/Utility.h"


#include "Server.h"
#include "WorldInfo.h"
#include "Config.h"
#include "AccountMgr.h"
#include "../../new_common/Source/log4cpp-1.0/MyLog.h"

extern time_t UNIXTIME;		/* update this every loop to avoid the time() syscall! */
extern tm g_localTime;
