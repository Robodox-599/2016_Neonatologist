#ifndef SHOOTER_H_
#define SHOOTER_H_

#include "../Macros.h"

class Shooter
{
public:
	Shooter();
	~Shooter();
	void shoot(bool shoot, bool reset);

	void motorTest(bool reset);
	void pistonTest(bool fwdPiston, bool safety);

	double getMotorSpeed();
	int getEncPos();

	bool limitSwitchIsPressed();


private:
	//Encoder* shooterEncoder;
	DoubleSolenoid* gearPiston;
	CANTalon* shooterMotor;
	AnalogInput* ai;


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
