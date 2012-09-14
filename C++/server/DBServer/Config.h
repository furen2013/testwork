#pragma once

class CConfig
{
private:
	CConfig(void);
	~CConfig(void);

public:
	static bool Init();
	static bool LoadDBServer();
public:
	//dbserver.ini
	static string m_strCSIP;
	static WORD m_wCSPort;
	static WORD m_wListenGTPort;
	static WORD m_wListenGSPort;
	static string m_strDBString;
	static ui32 m_nFrameTick;

	static ui32	m_nGSID;//	用于gt转发不同gs消息，每个组的gs有一个唯一id
};
