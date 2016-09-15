#ifndef SHOOTER_H_
#define SHOOTER_H_

#include "../Macros.h"
<<<<<<< HEAD
=======
#include "DigitalInput.h"
>>>>>>> 58341f612214fa77bd11cca382acc04f44106a7d

class Shooter
{
public:
	Shooter();
	~Shooter();

	bool getLimit();
	void shoot(bool shoot, bool reset);

	void catapultReset(bool reset);
	void catapultLaunch(bool fwdPiston, bool safety);

	double getMotorSpeed();
	int getEncPos();

	DoubleSolenoid* gearPiston;
private:
	DigitalInput* limit;
	CANTalon* shooterMotor;

	bool safetyPressed;

	float speed;
};

#endif

