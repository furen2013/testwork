#pragma once
#ifndef PLOUGHMILL_H
#define PLOUGHMILL_H
class PloughCell;
class PloughMill
{
public:
	PloughMill();
	~PloughMill();
	int GatherModify(int gather);
	int	getLevel();
	void setLevel(int level);
protected:
	void changeLevel( ); // Ä¥·»¸Ä±äÅäÖÃ

protected:
	PloughCell* _ploughCell;
	int32 _modifyHavestPct;
	int32 _modifyHavest;
	int32 _level;
	
};
#endif