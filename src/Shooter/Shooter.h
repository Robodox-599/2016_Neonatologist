#ifndef SHOOTER_H_
#define SHOOTER_H_

#include "../Macros.h"

class Shooter
{
public:
	Shooter();
	~Shooter();
	/*void shoot(bool shoot, bool reset);*/

	void motorTest(bool reset);
	void pistonTest(bool fwdPiston, bool safety);

	double getMotorSpeed();
	int getEncPos();
	CANTalon* shooterMotor;
private:
	Encoder* shooterEncoder;
	DoubleSolenoid* gearPiston;

	float speed;

	bool safetyPressed;

};

#endif
