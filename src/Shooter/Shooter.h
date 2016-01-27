#ifndef SHOOTER_H_
#define SHOOTER_H_

#include "..\Macros.h"

class Shooter
{
public:
	Shooter();
	~Shooter();
	void shoot(bool shoot, bool reset);
private:
	 CANTalon* shooterMotor;
	 Encoder* shooterEncoder;
	 DoubleSolenoid* gearPiston;

	 float speed;

};

#endif
