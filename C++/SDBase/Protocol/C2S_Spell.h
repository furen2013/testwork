#pragma once

#include "C2S.h"
#include "../Public/SpellDef.h"
namespace MSG_C2S
{
	struct stSpell_Learn_Talent : public PakHead
	{
		stSpell_Learn_Talent(){ wProNO = SPELL_LEARN_TALENT; }
		uint32 talent_id, requested_rank, unk;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << talent_id << requested_rank << unk; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> talent_id >> requested_rank >> unk; return cpu; }
	};	
	struct stSpell_UnLearn_Talent : public PakHead
	{
		stSpell_UnLearn_Talent(){ wProNO = SPELL_UNLEARN_TALENTS; }
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps);  return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu); return cpu; }
	};	
	struct stSkill_UnLearn : public PakHead
	{
		stSkill_UnLearn(){ wProNO = SKILL_UNLEARN; }
		uint32 skill_line;

		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps);  cps << skill_line; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu); cpu >> skill_line;return cpu; }
	};	
	struct stSpell_Cast : public PakHead
	{
		stSpell_Cast(){ wProNO = SPELL_CAST; }
		uint32 spellId;
		uint8 cn;
		SpellCastTargets targets;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps);  cps << spellId << cn << targets; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu); cpu >> spellId >> cn >> targets;return cpu; }
	};	
	struct stSpell_Cancel_Cast : public PakHead
	{
		stSpell_Cancel_Cast(){ wProNO = SPELL_CANCEL_CAST; }
		uint32 spellId;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps);  cps << spellId; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu); cpu >> spellId;return cpu; }
	};	
	struct stSpell_Cancel_Aura : public PakHead
	{
		stSpell_Cancel_Aura(){ wProNO = SPELL_CANCEL_AURA; }
		uint32 spellId;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps);  cps << spellId; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu); cpu >> spellId;return cpu; }
	};	
	struct stSpell_Cancel_Channelling : public PakHead
	{
		stSpell_Cancel_Channelling(){ wProNO = SPELL_CANCEL_CHANNELLING; }
		uint32 spellId;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps);  cps << spellId; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu); cpu >> spellId;return cpu; }
	};	
	struct stSpell_Cancel_Auto_Repeat : public PakHead
	{
		stSpell_Cancel_Auto_Repeat(){ wProNO = SPELL_CANCEL_AUTO_REPEAT; }
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps);  return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu); return cpu; }
	};	
	struct stSpell_Add_Dynamic_Target_Obsolete : public PakHead
	{
		stSpell_Add_Dynamic_Target_Obsolete(){ wProNO = SPELL_ADD_DYNAMIC_TARGET_OBSOLETE; }
		uint64 guid;
		uint32 spellid;

		SpellCastTargets targets;

		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps);  cps << guid << spellid << targets; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu); cpu >> guid >> spellid >> targets; return cpu; }
	};	
	struct stSpell_Self_Resurrect : public PakHead
	{
		stSpell_Self_Resurrect(){ wProNO = SPELL_SELF_RES; }
	};
	struct stAttack_Stop : public PakHead
	{
		stAttack_Stop(){ wProNO = ATTACK_STOP; }
	};
	struct stAttack_Swing : public PakHead
	{
		stAttack_Swing(){ wProNO = ATTACK_SWING; }
		uint64 guid;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps);  cps << guid; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu); cpu >> guid; return cpu; }
	};	
	
}
