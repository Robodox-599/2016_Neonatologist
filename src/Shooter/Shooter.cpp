#include "Shooter.h"

Shooter::Shooter()
{
	shooterMotor = new CANTalon(SHOOTER_MOTOR_CHANNEL);
}

Shooter::~Shooter()
{
	delete shooterMotor;

	shooterMotor = NULL;
}

void shoot()
{

}
