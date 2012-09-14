#pragma once
const int MAX_GS_NUM = 3;
class CGTConfig : public Singleton<CGTConfig>
{
public:
	CGTConfig(void){}
	~CGTConfig(void){}

	bool Load();
	bool LoadGateServer();

	int			m_nGroupID;
	string		m_CTIP;
	string		m_DBIP;
	string		m_GMIP[MAX_GS_NUM];
	string		m_GateIP;
	int			m_nCTPort;
	int			m_nDBPort;
	int			m_nGMPort[MAX_GS_NUM];
	int			m_nGMIndex[MAX_GS_NUM];
	int			m_nGatePort;
	int			m_nGSNum;
	ui32		m_nFrameTick;
	ui32		m_nPlayerLimit;
};
#define sGTConfig CGTConfig::getSingleton()