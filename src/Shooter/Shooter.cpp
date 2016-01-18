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

void Shooter::shoot(Joystick* joystick)
{
	if(joystick->GetRawButton(SHOOTER_BUTTON))
	{
		shooterMotor->Set(speed);
	}
	else if(joystick->GetRawButton(SHOOTER_RESET_BUTTON))
	{
		shooterMotor->Set(-speed);
	}
	else
	{
		shooterMotor->Set(0);
	}
}
