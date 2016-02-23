#ifndef SHOOTER_H_
#define SHOOTER_H_

#include "../Macros.h"

class Shooter
{
public:
	Shooter();
	~Shooter();
	/*void shoot(bool shoot, bool reset);*/

	void motorTest(float yAxis);
	void pistonTest(bool fwdPiston, bool revPiston);

	double getMotorSpeed();

	CANTalon* shooterMotor;
private:

	 Encoder* shooterEncoder;
	 DoubleSolenoid* gearPiston;

	 float speed;

	 bool safetyPressed;

};

#endif
