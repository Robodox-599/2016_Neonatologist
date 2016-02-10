#ifndef AUTO_H_
#define AUTO_H_

#include "../Macros.h"
#include "../Intake/Intake.h"
#include "../Drive/Drive.h"
#include "../Shooter/Shooter.h"

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
	Shooter* shooter;
	
	Timer* timer;
};

#endif
