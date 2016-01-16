#ifndef SHOOTER_H_
#define SHOOTER_H_

#include "..\Macros.h"

class Shooter
{
public:
	Shooter();
	~Shooter();
	void shoot(Joystick* joystick);
private:
	 CANTalon* shooterMotor;

	 float speed;

};

#endif
