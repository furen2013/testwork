#pragma once


#include "../../new_common/Source/net/tcpsession.h"
#include "../../../SDBase/Protocol/S2C.h"

enum ERoleDataStatus
{
	eRDS_USE = 0,
	eRDS_CREATE_NOT_USE,
	eRDS_DELETE,
};

class CCSocket :
	public tcp_session
{
public:
	CCSocket( boost::asio::io_service& is );
	virtual ~CCSocket(void);

	virtual void reset();
	virtual void on_close( const boost::system::error_code& error );
	virtual void on_accept( tcp_server* p );
	virtual void proc_message( const message_t& msg );
	virtual void run();

	void PostSend( const void* data, uint16 len );
	void PostSend( const PakHead& msg );

	void SetSessionID(DWORD dwSessionID) { m_dwSessionID = dwSessionID;}
	DWORD GetSessionID() { return m_dwSessionID;}
	void SetAccount(ui32 AccountID) { m_nAccountID = AccountID;}
	ui32 GetAccount() { return m_nAccountID;}
	void SetClientDesKey( const string& strClientDesKey) { m_strClientDesKey = strClientDesKey;}
	const string& GetClientDesKey() { return m_strClientDesKey;}
	const string& GetCurrRole() { return m_strCurrRole;}
	void SetCurrRole( const string& strRole ) { m_strCurrRole = strRole;}
	DWORD GetGUID() { return guid;}
	void SetGUID(ui64 id) { guid = id;}
	bool DispatchSession( uint32 nAccountID );

	static CCSocket* GetSocketByTransID( uint32 transid );
	static uint32 GetAccountIDByTransID( uint32 transid );

public:
	ui32			m_dwSessionID;
	ui32			m_nAccountID;
	string			m_strClientDesKey;
	string			m_strCurrRole;
	int				m_nCurrGS;
	ui64			guid;

	string m_strIP;
	DWORD  m_dwIP;
	int m_iPort;

	string	m_GMFlags;
	ui32	m_Muted;
	ui32	m_Baned;

	//////////////////////////////////////////////////////////////////////////时间戳
	ui32    m_HeatCount;
	ui32    m_lastC2STime;
	int32   m_C2SAddTime;
	int32   m_lastIndex; 
	ui32    m_baseTime;
	int32    m_StartTime;
	ui32    m_firststamp;
	//////////////////////////////////////////////////////////////////////////

	bool m_bFangchenmiAccount;//是否是未成年人账号
	uint32 m_LastLogout;
	uint32	m_ChenmiTime;//沉迷的游戏时间累积

	bool	m_bReqEnterGS;
	bool	m_bReqRoleList;

	uint32 m_LoginTime;
	uint32 idx;

	uint32 m_nMsgSize;
	uint32 m_nMsgCleanTime;
	bool m_bAuthSuccess;
	uint32 m_last_ping_time;
	uint32 m_ping_count;
	uint32 m_accept_time;
	bool m_is_valid_connection;
};
