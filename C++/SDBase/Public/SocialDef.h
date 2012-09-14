#pragma once
#include "TypeDef.h"

enum PartyOperation
{
	PARTY_OP_INVITE = 0,
	PARTY_OP_LEAVE = 2
};

enum PartyResult
{
	PARTY_RESULT_OK                   = 0,
	PARTY_RESULT_CANT_FIND_TARGET     = 1,
	PARTY_RESULT_NOT_IN_YOUR_PARTY    = 2,
	PARTY_RESULT_NOT_IN_YOUR_INSTANCE = 3,
	PARTY_RESULT_PARTY_FULL           = 4,
	PARTY_RESULT_ALREADY_IN_GROUP     = 5,
	PARTY_RESULT_YOU_NOT_IN_GROUP     = 6,
	PARTY_RESULT_YOU_NOT_LEADER       = 7,
	PARTY_RESULT_TARGET_UNFRIENDLY    = 8,
	PARTY_RESULT_TARGET_IGNORE_YOU    = 9,
	PARTY_RESULT_INVITE_RESTRICTED    = 13
};


enum GroupMemberOnlineStatus
{
	MEMBER_STATUS_OFFLINE   = 0x0000,
	MEMBER_STATUS_ONLINE    = 0x0001,
	MEMBER_STATUS_PVP       = 0x0002,
	MEMBER_STATUS_UNK0      = 0x0004,                       // dead? (health=0)
	MEMBER_STATUS_UNK1      = 0x0008,                       // ghost? (health=1)
	MEMBER_STATUS_UNK2      = 0x0010,                       // never seen
	MEMBER_STATUS_UNK3      = 0x0020,                       // never seen
	MEMBER_STATUS_UNK4      = 0x0040,                       // appears with dead and ghost flags
	MEMBER_STATUS_UNK5      = 0x0080,                       // never seen
};

enum GroupType
{
	GROUPTYPE_NORMAL = 0,
	GROUPTYPE_RAID   = 1
};

enum GroupUpdateFlags
{
	GROUP_UPDATE_FLAG_NONE              = 0x00000000,       // nothing
	GROUP_UPDATE_FLAG_STATUS            = 0x00000001,       // uint16, flags
	GROUP_UPDATE_FLAG_CUR_HP            = 0x00000002,       // uint16
	GROUP_UPDATE_FLAG_MAX_HP            = 0x00000004,       // uint16
	GROUP_UPDATE_FLAG_POWER_TYPE        = 0x00000008,       // uint8
	GROUP_UPDATE_FLAG_CUR_POWER         = 0x00000010,       // uint16
	GROUP_UPDATE_FLAG_MAX_POWER         = 0x00000020,       // uint16
	GROUP_UPDATE_FLAG_LEVEL             = 0x00000040,       // uint16
	GROUP_UPDATE_FLAG_ZONE              = 0x00000080,       // uint16
	GROUP_UPDATE_FLAG_POSITION          = 0x00000100,       // uint16, uint16
	GROUP_UPDATE_FLAG_AURAS             = 0x00000200,       // uint64 mask, for each bit set uint16 spellid + uint8 unk
	GROUP_UPDATE_FLAG_PET_GUID          = 0x00000400,       // uint64 pet guid
	GROUP_UPDATE_FLAG_PET_NAME          = 0x00000800,       // pet name, NULL terminated string
	GROUP_UPDATE_FLAG_PET_MODEL_ID      = 0x00001000,       // uint16, model id
	GROUP_UPDATE_FLAG_PET_CUR_HP        = 0x00002000,       // uint16 pet cur health
	GROUP_UPDATE_FLAG_PET_MAX_HP        = 0x00004000,       // uint16 pet max health
	GROUP_UPDATE_FLAG_PET_POWER_TYPE    = 0x00008000,       // uint8 pet power type
	GROUP_UPDATE_FLAG_PET_CUR_POWER     = 0x00010000,       // uint16 pet cur power
	GROUP_UPDATE_FLAG_PET_MAX_POWER     = 0x00020000,       // uint16 pet max power
	GROUP_UPDATE_FLAG_PET_AURAS         = 0x00040000,       // uint64 mask, for each bit set uint16 spellid + uint8 unk, pet auras...
	GROUP_UPDATE_PET                    = 0x0007FC00,       // all pet flags
	GROUP_UPDATE_FULL                   = 0x0007FFFF,       // all known flags
};

#define GROUP_UPDATE_FLAGS_COUNT          20
// 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,11,12,13,14,15,16,17,18,19
static const uint8 GroupUpdateLength[GROUP_UPDATE_FLAGS_COUNT] = { 0, 2, 2, 2, 1, 2, 2, 2, 2, 4, 8, 8, 1, 2, 2, 2, 1, 2, 2, 8};
