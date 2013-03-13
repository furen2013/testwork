#include "stdafx.h"
#include "PloughCell.h"
#include "EventMgr.h"

PloughCell::PloughCell()
{
	BecomeSeeding();
}
PloughCell::~PloughCell()
{

}

void PloughCell::BecomeYoung()
{
	enType = growstate_young;
	EventMgr::getSingleton().AddEvent(this,&PloughCell::BecomeGrown, PLOUGHCELL_BECOME_GROWN, time[growstate_grown], 0, 0);
	
}

void PloughCell::BecomeGrown()
{
	enType = growstate_grown;
}

void PloughCell::BecomeSeeding()
{
	enType = growstate_seeding;
	EventMgr::getSingleton().AddEvent(this,&PloughCell::BecomeYoung, PLOUGHCELL_BECOME_YOUNG, time[growstate_young], 0, 0);
}