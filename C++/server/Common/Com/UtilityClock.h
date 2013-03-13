#pragma once
#ifndef UTILITYCLOCK_H
#define UTILITYCLOCK_H
class UtilityTimeEvent
{
public:
	UtilityTimeEvent();
	~UtilityTimeEvent();
public:
	void start();
	void stop();
	void 

protected:
	unsigned long begintime;
	unsigned long duration;
};




#endif