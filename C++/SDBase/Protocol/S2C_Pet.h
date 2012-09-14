#pragma once
#include "S2C.h"
namespace MSG_S2C
{
	struct stPet_Stable_Result : public PakHead
	{
		stPet_Stable_Result(){ wProNO = PET_STABLE_RESULT; }
		ui8	result;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << result; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> result; return cpu; }
	};

	struct stPet_Spells : public PakHead
	{
		struct stActionBar
		{
			union
			{
				ui32	ActionBar;
				struct{
					ui16	ActionBar;
					ui16	SpellState;
				}bar_spell;

			};
			CPacketSn& Sn(CPacketSn& cps) const {	cps << ActionBar; return cps; }
			CPacketUsn& Usn(CPacketUsn& cpu)	{	cpu >> ActionBar; return cpu; }
		};

		struct stSpell
		{
			ui16	spell_id;
			ui16	spell_stat;
			CPacketSn& Sn(CPacketSn& cps) const {	cps << spell_id << spell_stat; return cps; }
			CPacketUsn& Usn(CPacketUsn& cpu)	{	cpu >> spell_id >> spell_stat; return cpu; }
		};
		stPet_Spells(){ wProNO = PET_SPELLS_MSG; }
		ui64	target_guid;
		vector<stActionBar> vActionBar;
		vector<stSpell> vSpells;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << target_guid << vActionBar << vSpells; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> target_guid >> vActionBar >> vSpells; return cpu; }
	};

	struct stPet_Action_Sound : public PakHead
	{
		ui64	pet_guid;
		ui32	unk;
		stPet_Action_Sound(){ wProNO = PET_ACTION_SOUND; }
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << pet_guid << unk; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> pet_guid >> unk; return cpu; }
	};
	struct stPet_Name_Query_Response : public PakHead
	{
		ui64	pet_guid;
		string	pet_name;
		ui32	unk_timestamp;
		stPet_Name_Query_Response(){ wProNO = QUERY_PET_NAME_RESPONSE; }
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << pet_guid << pet_name << unk_timestamp; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> pet_guid >> pet_name >> unk_timestamp; return cpu; }
	};
	struct stPets_List_Stabled : public PakHead
	{
		stPets_List_Stabled(){ wProNO = PETS_LIST_STABLED; }
		uint64 npc_guid;
		ui8		StableSlotCount;
		struct stPet
		{
			ui32	pet_no;
			ui32	entry_id;
			ui32	level;
			ui32	loyaltylvl;
			string	name;
			ui32	state;
			CPacketSn& Sn(CPacketSn& cps) const {	cps << pet_no << entry_id << level << loyaltylvl << name << state; return cps; }
			CPacketUsn& Usn(CPacketUsn& cpu)	{	cpu >> pet_no >> entry_id >> level >> loyaltylvl >> name >> state; return cpu; }
		};
		vector<stPet> vPets;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << npc_guid << StableSlotCount << vPets; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> npc_guid >> StableSlotCount >> vPets; return cpu; }
	};
	struct stPet_UnLearn_Confirm : public PakHead
	{
		ui64	pet_guid;
		ui32	unlearn_cost;
		stPet_UnLearn_Confirm(){ wProNO = PET_UNLEARN_CONFIRM; }
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << pet_guid << unlearn_cost; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> pet_guid >> unlearn_cost; return cpu; }
	};

}
enum PET_SPELL
{
	PET_SPELL_PASSIVE = 0x06000000,
	PET_SPELL_DEFENSIVE,
	PET_SPELL_AGRESSIVE,
	PET_SPELL_STAY = 0x07000000,
	PET_SPELL_FOLLOW,
	PET_SPELL_ATTACK
};
