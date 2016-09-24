#include "Auto.h"

Auto::Auto()
{
	drive = new Drive();
}

Auto::~Auto()
{
	drive = nullptr;

	delete drive;
}

void Auto::autonomousForward()
{
	drive->updateLeftMotors(-AUTONOMOUS_MOTOR_VAL);
	drive->updateRightMotors(-AUTONOMOUS_MOTOR_VAL);
	Wait(AUTONOMOUS_TIME);
	drive->updateLeftMotors(0);
	drive->updateRightMotors(0);

	Wait(1);
}

void Auto::autonomousBackward()
{
	drive->updateLeftMotors(AUTONOMOUS_MOTOR_VAL);
	drive->updateRightMotors(AUTONOMOUS_MOTOR_VAL);
	Wait(AUTONOMOUS_TIME);
	drive->updateLeftMotors(0);
	drive->updateRightMotors(0);
}

