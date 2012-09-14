#include "stdafx.h"

//帐号状态转换合法图
//新状态，合法的老状态
EUserState g_StateTransMap[eStateEnd-eNone][eStateEnd-eNone+1] =
{
	{eNone, eNone, eRoleSelecting, eInGameServer},
	{eRoleSelecting, eRoleSelecting, eNone, eLogOut},
	{eInGameServer, eInGameServer, eRoleSelecting, eJumpGameServer},
	{eLogOut, eInGameServer},
	{eJumpGameServer, eJumpGameServer, eInGameServer},
};

//////////////////////////////////////////////////////////////////////////
//	Account
//////////////////////////////////////////////////////////////////////////
void Account::Reset()
{
	m_eState = eNone;
	m_nRoleCnt = 0;
	m_pGTSocket = NULL;
}

//////////////////////////////////////////////////////////////////////////
//	AccountMgr
//////////////////////////////////////////////////////////////////////////

initialiseSingleton(AccountMgr);

/* FOR 1.10.1
SMSG_CHAR_CREATE Error Codes:
0x00 Success
0x01 Failure
0x02 Canceled
0x03 Disconnect from server
0x04 Failed to connect
0x05 Connected
0x06 Wrong client version
0x07 Connecting to server
0x08 Negotiating security
0x09 Negotiating security complete
0x0A Negotiating security failed
0x0B Authenticating
0x0C Authentication successful
0x0D Authentication failed
0x0E Login unavailable - Please contact Tech Support
0x0F Server is not valid
0x10 System unavailable
0x11 System error
0x12 Billing system error
0x13 Account billing has expired
0x14 Wrong client version
0x15 Unknown account
0x16 Incorrect password
0x17 Session expired
0x18 Server Shutting Down
0x19 Already logged in
0x1A Invalid login server
0x1B Position in Queue: 0
0x1C This account has been banned
0x1D This character is still logged on
0x1E Your WoW subscription has expired
0x1F This session has timed out
0x20 This account has been temporarily suspended
0x21 Access to this account blocked by parental controls
0x22 Retrieving realmlist
0x23 Realmlist retrieved
0x24 Unable to connect to realmlist server
0x25 Invalid realmlist
0x26 The game server is currently down
0x27 Creating account
0x28 Account created
0x29 Account creation failed
0x2A Retrieving character list
0x2B Character list retrieved
0x2C Error retrieving character list
0x2D Creating character
0x2E Character created
0x2F Error creating character
0x30 Character creation failed
0x31 That name is unavailable
0x32 Creation of that race/class is disabled
0x33 You cannot have both horde and alliance character at pvp realm
0x33 All characters on a PVP realm must be on the same team
0x34 You already have maximum number of characters
0x35 You already have maximum number of characters
0x36 The server is currently queued
0x37 Only players who have characters on this realm..
0x38 Creation of that race requires an account that has been upgraded to the approciate expansion
0x39 Deleting character
0x3A Character deleted
0x3B Char deletion failed
0x3c Entering world of warcraft
0x3D Login successful
0x3E World server is down
0x3F A character with that name already exists
0x40 No instance server available
0x41 Login failed
0x42 Login for that race/class is disabled
0x43 Character not found
0x44 Enter a name for your character
0x45 Names must be atleast 2 characters long
0x46 Names must be no more then 12 characters
0x47 Names can only contain letters
0x48 Names must contain only one language
0x49 That name contains profanity
0x4A That name is unavailable
0x4B You cannot use an apostrophe
0x4C You can only have one apostrophe
0x4D You cannot use the same letter three times consecutively
0x4E You cannit use space as the first or last character of your name
0x4F <Blank>
0x50 Invalid character name
0x51 <Blank>
All further codes give the number in dec.
*/

//byErrCode:0=成功，1=重名，2＝数据库异常,3=角色数达到上限,4=其它情况

void AccountMgr::AddAccount(Account* pNewAccount)
{
	if( m_mAccount.find( pNewAccount->m_nAccountID ) != m_mAccount.end() )
	{
		MyLog::log->error("sAccountMgr already has account[%d]", pNewAccount->m_nAccountID);
		return;
	}
	MyLog::log->debug("AccountMgr insert account[%d]", pNewAccount->m_nAccountID);
	m_mAccount.insert(make_pair(pNewAccount->m_nAccountID, pNewAccount));
}
bool AccountMgr::RemoveAccount(ui32 nAccountID)
{
	m_mAccount.erase(nAccountID);
	MyLog::log->debug("AccountMgr remove account[%d]", nAccountID);
	return true;
}
Account* AccountMgr::GetAccount(ui32 nAccountID)
{
	Account_Map::iterator itr = m_mAccount.find( nAccountID );
	if( itr != m_mAccount.end() )
	{
		return itr->second;
	}
	return NULL;
}
