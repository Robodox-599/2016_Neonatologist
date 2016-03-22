#ifndef SHOOTER_H_
#define SHOOTER_H_

#include "../Macros.h"
#include "DigitalInput.h"

class Shooter
{
public:
	Shooter();
	~Shooter();

	void getLimit();
	void shoot(bool shoot, bool reset);

	void catapultReset(bool reset);
	void catapultLaunch(bool fwdPiston, bool safety);

	double getMotorSpeed();
	int getEncPos();
private:
	DigitalInput* limit;
	DoubleSolenoid* gearPiston;
	CANTalon* shooterMotor;

	bool safetyPressed;

	float speed;
};

#endif