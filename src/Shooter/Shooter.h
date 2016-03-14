#ifndef SHOOTER_H_
#define SHOOTER_H_

#include "../Macros.h"

#include "DigitalInput.h"

class Shooter
{
public:
	Shooter();
	~Shooter();

	void shootMotor(bool reset);
	void shootPiston(bool fwdPiston, bool safety);

	double getMotorSpeed();
	int getEncPos();
	DigitalInput* limitSwitch;

private:
	DoubleSolenoid* gearPiston;
	CANTalon* shooterMotor;

};

#endif
