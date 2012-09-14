#pragma once

#include "C2S.h"
namespace MSG_C2S
{
	struct stPet_Action : public PakHead
	{
		stPet_Action(){ wProNO = PET_ACTION; }
		uint64 petGuid;
		uint16 misc;
		uint16 action;
		uint64 targetguid;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << petGuid << misc << action << targetguid; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> petGuid >> misc >> action >> targetguid; return cpu; }
	};
	struct stPet_Request_Info : public PakHead
	{
		stPet_Request_Info(){ wProNO = PET_REQUEST_INFO; }
	};
	struct stPet_Buy_Stable_Slot : public PakHead
	{
		stPet_Buy_Stable_Slot(){ wProNO = PET_BUY_STABLE_SLOT; }
	};
	struct stPet_Set_Action : public PakHead
	{
		stPet_Set_Action(){ wProNO = PET_SET_ACTION; }
		uint32 unk1;
		uint32 unk2;
		uint32 slot;
		uint16 spell;
		uint16 state;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << unk1 << unk2 << slot << spell << state; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> unk1 >> unk2 >> slot >> spell >> state; return cpu; }
	};
	struct stPet_Rename : public PakHead
	{
		stPet_Rename(){ wProNO = PET_RENAME; }
		uint64 guid;
		string name;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << guid << name; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> guid >> name; return cpu; }
	};
	struct stPet_Abandon : public PakHead
	{
		stPet_Abandon(){ wProNO = PET_ABANDON; }
	};
	struct stPet_Stable : public PakHead
	{
		stPet_Stable(){ wProNO = PET_STABLE; }
	};
	struct stPet_Unlearn : public PakHead
	{
		stPet_Unlearn(){ wProNO = PET_UNLEARN; }
		uint64 guid;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << guid; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> guid; return cpu; }
	};
	struct stPets_List_Stabled : public PakHead
	{
		stPets_List_Stabled(){ wProNO = PETS_LIST_STABLED; }
		uint64 npc_guid;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << npc_guid; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> npc_guid; return cpu; }
	};
	struct stPet_UnStable : public PakHead
	{
		stPet_UnStable(){ wProNO = PET_UNSTABLE; }
		uint64 npcguid;
		ui32	pet_number;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << npcguid << pet_number; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> npcguid >> pet_number; return cpu; }
	};
	struct stPet_Stable_Swap : public PakHead
	{
		stPet_Stable_Swap(){ wProNO = PET_STABLE_SWAP; }
		uint64 npcguid;
		ui32	pet_number;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << npcguid << pet_number; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> npcguid >> pet_number; return cpu; }
	};

}
