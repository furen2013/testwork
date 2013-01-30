#include "stdafx.h"
#include "Config.h"
initialiseSingleton(CGTConfig);
bool CGTConfig::Load()
{
	m_nGroupID		= Config.MainConfig.GetIntDefault("ServerInfo", "GroupID", 0);
	if( m_nGroupID == 0 )
	{
		printf( "load GT.conf failed!!!\n" );
		exit( 0 );
		return false;
	}
	m_CTIP			= Config.MainConfig.GetStringDefault("CeneterServer", "IP", "127.0.0.1");
	m_nCTPort		= Config.MainConfig.GetIntDefault("CeneterServer", "Port", 7102);
	m_DBIP			= Config.MainConfig.GetStringDefault("DBServer", "IP", "127.0.0.1");
	m_nDBPort		= Config.MainConfig.GetIntDefault("DBServer", "Port", 7103);
	m_GateIP		= Config.MainConfig.GetStringDefault("GateServer", "IP", "127.0.0.1");
	m_nGatePort		= Config.MainConfig.GetIntDefault("GateServer", "Port", 7001);
	m_nFrameTick	= Config.MainConfig.GetIntDefault("ServerInfo", "FrameTickCount", 200);

	m_nGSNum		= Config.MainConfig.GetIntDefault("GameServer", "Count", 1);
	m_nPlayerLimit	= Config.MainConfig.GetIntDefault("ServerInfo", "PlayerLimit", 3000);

	char szTag[64];
	for (int i = 0; i < m_nGSNum; i++)
	{
		sprintf(szTag, "IP%d", i);
		m_GMIP[i]	= Config.MainConfig.GetStringDefault("GameServer", szTag,  "127.0.0.1");

		sprintf(szTag, "Port%d", i);
		m_nGMPort[i]	= Config.MainConfig.GetIntDefault("GameServer", szTag, 7101);
		m_nGMIndex[i]	= i+1;
	}

	return true;
}
