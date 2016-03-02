#ifndef AUTO_H_
#define AUTO_H_

#include "../Macros.h"
#include "../Intake/Intake.h"
#include "../Drive/Drive.h"
#include "../Shooter/Shooter.h"

class Auto
{
public:
	Auto(float speedY, float speedX, bool useShooter, bool useIntake);
	~Auto();

	void shootBoulderAuto();
	void driveForwardAuto();
	void moveBoulder();
	void shootBoulder();
private:
	Intake* intake;
	Drive* drive;
	Shooter* shooter;
	
	Timer* timer;

	float speedY;
	float speedX;
	bool useShooter;
	bool useIntake;
};

#endif
