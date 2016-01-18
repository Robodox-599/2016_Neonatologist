#include "Shooter.h"

Shooter::Shooter()
{
	shooterMotor = new CANTalon(SHOOTER_MOTOR_CHANNEL);
	speed = 0;
}

Shooter::~Shooter()
{
	delete shooterMotor;

	shooterMotor = NULL;
}

void Shooter::shoot(bool shoot, bool reset)
{
	if(shoot)
	{
		shooterMotor->Set(speed);
	}
	else if(reset)
	{
		shooterMotor->Set(-speed);
	}
	else
	{
		shooterMotor->Set(0);
	}
}
