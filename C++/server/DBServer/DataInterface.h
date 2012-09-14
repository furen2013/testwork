#pragma once

class MySqlAccess
{
public:
	static bool Init();
	static bool LoadAllName();
	static bool LoadRole(ui64 guid, RoleInfo& info);
	static bool LoadAcctRoles(ui32 nAccountID, vector<RoleInfo>& vInfos);
	static bool CreateRole(ui32 nAccountID,const string& strName, ui8 nGender, ui8 nClass, ui8 nRace, RoleInfo& info);
	static bool DelRole(ui32 nAccountID, ui64 guid);

	static bool LoadRoleEquip(ui64 guid, RoleInfo& info);
	static int IsRoleNameUsed(const string& strRoleName);
	static bool CanUseName(const string& strRoleName);

	static ui64	m_hiPlayerGuid;

	static HM_NAMESPACE::hash_set<int> m_hashname;
};