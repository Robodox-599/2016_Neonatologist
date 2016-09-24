#include "Shooter.h"
// fix
Shooter::Shooter()
{
	shooterMotor = new CANTalon(SHOOTER_MOTOR_PORT);//SHOOTER_MOTOR_CHANNEL); // change ports
	gearPiston = new DoubleSolenoid(GEAR_PISTON_PORT_A,GEAR_PISTON_PORT_B);//change ports
	limit = new DigitalInput(LIMIT_SWTICH_PORT);

	shooterMotor->ConfigFwdLimitSwitchNormallyOpen(true);
	safetyPressed = false;

	speed = 0;
}

Shooter::~Shooter()
{
	delete shooterMotor;
	delete gearPiston;
	delete limit;

	shooterMotor = nullptr; 
	gearPiston = nullptr;
	limit = nullptr;
}

bool Shooter::getLimit()
{
	return limit->Get();
}

void Shooter::catapultReset(bool reset)
{
	/*if(shooterMotor->GetEncPosition() > 10)
	{
		shooterMotor->Set(0);
	}*/
	if(reset == true && !getLimit())
	{
		shooterMotor->Set(.7); //WARNING: DO NOT MAKE NEGATIVE (and may need to change value)
	}
	else
	{
		shooterMotor->Set(0);
	}
}

void Shooter::catapultLaunch(bool fwdPiston, bool safety)
{
	if(fwdPiston && safety)
	{
		gearPiston->Set(DoubleSolenoid::Value::kReverse);
		Wait(1);
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
