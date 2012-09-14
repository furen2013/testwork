#pragma once

#include "S2C.h"
namespace MSG_S2C
{
	struct stSpells_Initial : public PakHead
	{
		struct stCoolDown
		{
			stCoolDown(){}
			stCoolDown(ui32 sid, ui32 iid, ui32 scg, ui32 sc, ui32 scc):spellid(sid),itemid(iid),spell_category(scg),spell_cd(sc),spell_category_cd(scc){}
			ui32 spellid;
			ui32 itemid;
			ui32 spell_category;
			ui32 spell_cd;//cooldown remaining in ms (for spell)
			ui32 spell_category_cd;// cooldown remaining in ms (for category)
			CPacketSn& Sn(CPacketSn& cps) const {	cps << spellid << itemid << spell_category << spell_cd << spell_category_cd; return cps; }
			CPacketUsn& Usn(CPacketUsn& cpu)	{	cpu >> spellid >> itemid >> spell_category >> spell_cd >> spell_category_cd; return cpu; }
		};
		stSpells_Initial(){ wProNO = SPELLS_INITIAL; }
		uint16 spellCount;
		vector<ui32> vSpells;
		uint16	itemCount;

		vector<stCoolDown> vSpellCDs;
		vector<stCoolDown> vSpellCategoryCDs;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << spellCount << vSpells << itemCount << vSpellCDs << vSpellCategoryCDs; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> spellCount >> vSpells >> itemCount >> vSpellCDs >> vSpellCategoryCDs; return cpu; }
	};
}