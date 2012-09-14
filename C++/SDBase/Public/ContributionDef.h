#ifndef _CONTRIBUTION_DEF_HEAD
#define _CONTRIBUTION_DEF_HEAD

#include "PacketDef.h"

struct ContributionHistory
{
	uint32 acct;
	uint32 guid;
	std::string name;
	uint32 coins;
	uint32 points;
	uint32 reputation;
	uint32 unixtime;
	bool yp;
	CPacketSn& Sn(CPacketSn& cps) const { cps << coins << points << reputation << unixtime << yp; return cps; }
	CPacketUsn& Usn(CPacketUsn& cpu)	{ cpu >> coins >> points >> reputation >> unixtime >> yp; return cpu; }
};

struct HistoryCompare : public std::binary_function<ContributionHistory*, ContributionHistory*, bool>
{
	bool operator()( ContributionHistory* a, ContributionHistory* b )
	{
		return a->unixtime > b->unixtime;
	}
};


typedef std::vector<ContributionHistory> ContributionHistoryVector;

struct ContributionSummary
{
	uint32 acct;
	uint32 guid;
	std::string name;
	uint32 coins;
	uint32 points;
	uint32 reputation;
	uint32 rank;
	CPacketSn& Sn(CPacketSn& cps) const { cps << acct << guid << name << coins << points << reputation << rank; return cps; }
	CPacketUsn& Usn(CPacketUsn& cpu)	{ cpu >> acct >> guid >> name >> coins >> points >> reputation >> rank; return cpu; }
};

struct ContributionCompare : public std::binary_function<ContributionSummary*, ContributionSummary*, bool>
{
	bool operator()( ContributionSummary* a, ContributionSummary* b )
	{
		return a->points > b->points;
	}
};

#endif