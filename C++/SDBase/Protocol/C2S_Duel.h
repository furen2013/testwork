#pragma once

#include "C2S.h"
namespace MSG_C2S
{
	struct stDuel_Cancel : public PakHead
	{
		stDuel_Cancel(){ wProNO = DUEL_CANCELLED; }
	};

	struct stDuel_Accept : public PakHead
	{
		stDuel_Accept(){ wProNO = DUEL_ACCEPTED; }
	};


}
