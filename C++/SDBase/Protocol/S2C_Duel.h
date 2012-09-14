#pragma once
#include "S2C.h"

namespace MSG_S2C
{

	struct stDuel_CountDown : public PakHead
	{
		stDuel_CountDown(){ wProNO = DUEL_COUNTDOWN; }
		ui32	duelCountdownTimer;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << duelCountdownTimer; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> duelCountdownTimer; return cpu; }

	};
	struct stDuel_Complete : public PakHead
	{
		stDuel_Complete(){ wProNO = DUEL_COMPLETE; }
		ui8	unk;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << unk; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> unk; return cpu; }

	};
	struct stDuel_OutOfBounds : public PakHead
	{
		stDuel_OutOfBounds(){ wProNO = DUEL_OUTOFBOUNDS; }
		ui32	duelCountdownTimer;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << duelCountdownTimer; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> duelCountdownTimer; return cpu; }

	};
	struct stDuel_InBounds : public PakHead
	{
		stDuel_InBounds(){ wProNO = DUEL_INBOUNDS; }
	};
	struct stDuel_Winner : public PakHead
	{
		stDuel_Winner(){ wProNO = DUEL_WINNER; }
		ui8	WinCondition;
		string winner_name;
		string DuelingWith_name;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << WinCondition << winner_name << DuelingWith_name; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> WinCondition >> winner_name >> DuelingWith_name; return cpu; }

	};
	struct stDuel_Request : public PakHead
	{
		stDuel_Request(){ wProNO = DUEL_REQUESTED; }
		ui64	flag_guid;
		ui64	player_guid;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << flag_guid << player_guid; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> flag_guid >> player_guid; return cpu; }
	};
}
