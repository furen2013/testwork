#include "stdafx.h"
#include "../Common/tinyxml/tinyxml.h"
#include <iostream>
#include <fstream>

//dbserver.ini
string CConfig::m_strCSIP;
WORD CConfig::m_wCSPort;
WORD CConfig::m_wListenGTPort;
WORD CConfig::m_wListenGSPort;
ui32	CConfig::m_nGSID;

string CConfig::m_strDBString;
ui32	CConfig::m_nFrameTick = 200;

bool CConfig::Init()
{

	if(!LoadDBServer())
	{
		MyLog::log->error("CConfig::Init()£¬LoadDBServer return false");
		return false;
	}
	return true;
}

bool CConfig::LoadDBServer()
{
	m_strCSIP	= Config.MainConfig.GetStringDefault("CenterServer", "CSIP", "127.0.0.1");
	m_wCSPort	= Config.MainConfig.GetIntDefault("CenterServer", "CSPort", 7103);
	m_wListenGTPort	= Config.MainConfig.GetIntDefault("Listen", "ListenGTPort", 7201);
	m_wListenGSPort	= Config.MainConfig.GetIntDefault("Listen", "ListenGSPort", 7202);
	m_nFrameTick	= Config.MainConfig.GetIntDefault("ServerInfo","FrameTickCount", 200);
	m_nGSID		= Config.MainConfig.GetIntDefault("ServerInfo", "GSID", 1);
	return true;
}