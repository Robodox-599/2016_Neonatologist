#ifndef AUTO_H_
#define AUTO_H_

#include "..\Macros.h"
#include "..\Intake\Intake.h"
#include "..\Drive\Drive.h"

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
	Drive* drive;
	Timer* timer;
};

#endif