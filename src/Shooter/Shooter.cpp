#include "Shooter.h"

Shooter::Shooter()
{
	shooterMotor = new CANTalon(SHOOTER_MOTOR_CHANNEL);
	shooterEncoder = new Encoder(SHOOTER_ENCODER_CHANNEL_A, SHOOTER_ENCODER_CHANNEL_B);
	speed = 0;
}

Shooter::~Shooter()
{
	delete shooterMotor;
	delete shooterEncoder;

	shooterMotor = nullptr;
<<<<<<< HEAD
=======
	shooterEncoder = nullptr;
>>>>>>> 8c0b0289fbf7358d0722cac93b3a7c679cf66ab7
}

void Shooter::shoot(bool shoot, bool reset)
{
	if(shoot && shooterEncoder->Get() < 2000) // TODO: get actual encoder value
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