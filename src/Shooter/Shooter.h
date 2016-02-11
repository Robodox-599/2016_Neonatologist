#ifndef SHOOTER_H_
#define SHOOTER_H_

#include "..\Macros.h"

class Shooter
{
public:
	Shooter();
	~Shooter();
	void shoot(bool shoot, bool reset);

	void motorTest();
	void pistonTest();

	double getMotorSpeed();
private:
	 CANTalon* shooterMotor;
	 Encoder* shooterEncoder;
	 DoubleSolenoid* gearPiston;

	 Joystick* joy;

	 float speed;

	 bool safetyPressed;

};

#endif
