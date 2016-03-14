#ifndef SHOOTER_H_
#define SHOOTER_H_

#include "../Macros.h"

#include "DigitalInput.h"

class Shooter
{
public:
	Shooter();
	~Shooter();
	void shoot(bool shoot, bool reset);

	void catapultReset(bool reset);
	void catapultLaunch(bool fwdPiston, bool safety);

	double getMotorSpeed();
	int getEncPos();
	DigitalInput* Limit;

private:
	//Encoder* shooterEncoder;
	DoubleSolenoid* gearPiston;
	CANTalon* shooterMotor;


	float speed;

	bool safetyPressed;

};

#endif



/*

#ifndef SHOOTER_H_
#define SHOOTER_H_

#include "../Macros.h"

class Shooter
{
public:
	Shooter();
	~Shooter();

	void shoot(bool shoot, bool reset);

	double getMotorSpeed();
	bool limitSwitchIsPressed();

private:
	 CANTalon* shooterMotor;
	 DoubleSolenoid* gearPiston;
	 AnalogInput* ai;

	 float speed;

};

#endif

*/
