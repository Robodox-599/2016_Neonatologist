#ifndef SRC_AUTONOMOUS_AUTONOMOUS_H_
#define SRC_AUTONOMOUS_AUTONOMOUS_H_

#include "../Drive/Drive.h"
#include "../Shooter/Shooter.h"
#include "../Intake/Intake.h"
#include "DigitalInput.h"

class Autonomous
{
public:

	Autonomous();
	~Autonomous();

	//bool toggleSwitch;

	DigitalInput* selector1;
	DigitalInput* selector8;

private:
	Drive* drive;
	Shooter* shooter;
	Intake* intake;
};

#endif /* SRC_AUTONOMOUS_AUTONOMOUS_H_ */
