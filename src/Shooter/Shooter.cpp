#include "Shooter.h"

Shooter::Shooter()
{
	shooterMotor = new CANTalon(6);//SHOOTER_MOTOR_CHANNEL);
	gearPiston = new DoubleSolenoid(GEAR_PISTON_CHANNEL_A, GEAR_PISTON_CHANNEL_B);

	limitSwitch = new DigitalInput(LIMIT_SWITCH_CHANNEL);

}

Shooter::~Shooter()
{
	delete shooterMotor;
	delete gearPiston;
	delete limitSwitch;


	shooterMotor = nullptr; 
	gearPiston = nullptr;
	limitSwitch = nullptr;
}

void Shooter::shootMotor(bool reset)
{
	if(reset && !limitSwitch->Get())
	{
		shooterMotor->Set(.8); //WARNING: DO NOT MAKE NEGATIVE (and may need to change value)
	}
	else
	{
		shooterMotor->Set(0);
	}
}

void Shooter::shootPiston(bool fwdPiston, bool safety)
{
	if(fwdPiston && safety)
	{
		gearPiston->Set(DoubleSolenoid::Value::kReverse);
		Wait(2);
		gearPiston->Set(DoubleSolenoid::Value::kForward);
	}

	/*else if(revPiston)
	{
		gearPiston->Set(DoubleSolenoid::Value::kReverse);
	}
	else
	{
		gearPiston->Set(DoubleSolenoid::Value::kOff);
	}*/
}

double Shooter::getMotorSpeed()
{
	return shooterMotor->GetSpeed();
}

int Shooter::getEncPos()
{
	return shooterMotor->GetEncPosition();
}

