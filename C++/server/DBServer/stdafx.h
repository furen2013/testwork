// stdafx.h : ��׼ϵͳ�����ļ��İ����ļ���
// ���Ǿ���ʹ�õ��������ĵ�
// ��Ŀ�ض��İ����ļ�

#pragma once

#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN		// �� Windows ��ͷ���ų�����ʹ�õ�����
#endif

// ���������ʹ��������ָ����ƽ̨֮ǰ��ƽ̨�����޸�����Ķ��塣
// �йز�ͬƽ̨����Ӧֵ��������Ϣ����ο� MSDN��
#ifdef _WIN32
#ifndef WINVER				// ����ʹ�� Windows 95 �� Windows NT 4 ����߰汾���ض����ܡ�
#define WINVER 0x0400		//Ϊ Windows98 �� Windows 2000 �����°汾�ı�Ϊ�ʵ���ֵ��
#endif

#ifndef _WIN32_WINNT		// ����ʹ�� Windows NT 4 ����߰汾���ض����ܡ�
#define _WIN32_WINNT 0x0400		//Ϊ Windows98 �� Windows 2000 �����°汾�ı�Ϊ�ʵ���ֵ��
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
