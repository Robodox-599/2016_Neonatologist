#ifndef AUTO_H_
#define AUTO_H_

#include "..\Macros.h"
#include "..\Intake\Intake.h"

class Auto
{
public:
	Auto();
	~Auto();

	void runAuto();
	void moveBoulder();
	void driveUnderBar();
	void shootBoulder();
private:
	Intake* intake;
	Timer* timer;
};

#endif