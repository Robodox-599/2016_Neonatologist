#ifndef AUTO_H_
#define AUTO_H_

#include "..\Macros.h"

class Auto
{
public:
	Auto();
	~Auto();

	void runAuto();
	void driveUnderBar();
	void shootBoulder();
private:
	Timer* timer;
};

#endif