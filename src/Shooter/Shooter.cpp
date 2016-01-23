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
	shooterEncoder = nullptr;
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