#include "Shooter.h"

Shooter::Shooter()
{
	shooterMotor = new CANTalon(6);//SHOOTER_MOTOR_CHANNEL);
	//shooterEncoder = new Encoder(SHOOTER_ENCODER_CHANNEL_A, SHOOTER_ENCODER_CHANNEL_B);
	gearPiston = new DoubleSolenoid(GEAR_PISTON_CHANNEL_A, GEAR_PISTON_CHANNEL_B);

	Limit = new DigitalInput(8);

	speed = 0;

	//shooterMotor->SetEncPosition(0);
	shooterMotor->ConfigFwdLimitSwitchNormallyOpen(true);
	safetyPressed = false;
}

Shooter::~Shooter()
{
	delete shooterMotor;
	//delete shooterEncoder;
	delete gearPiston;
	delete Limit;


	shooterMotor = nullptr; 
	//shooterEncoder = nullptr;
	gearPiston = nullptr;
	Limit = nullptr;
}

//auto reset after a shot 
//hold safety button then click trigger to shoot. have to have both pressed

// right bumper is safety button 
// right trigger is the shoot button
/*
void Shooter::shoot(bool shoot, bool reset)
{
	if(shoot && (shooterEncoder->Get() < 2000) && !safetyPressed) // TODO: get actual encoder value
	{
		gearPiston->Set(DoubleSolenoid::Value::kForward);
		shooterEncoder->Reset();
		safetyPressed = true;
	}
	else if(reset)
	{
		shooterMotor->Set(speed);
		gearPiston->Set(DoubleSolenoid::Value::kReverse);
		shooterEncoder->Reset();
	}
	else
	{
		gearPiston->Set(DoubleSolenoid::Value::kOff);
		shooterMotor->Set(0);
	}
}
*/
//add into neonatologist and make sure that the joysticks are mapped properly to this function
/*void Shooter::shoot(bool shoot, bool reset)
{
	if(shoot && shooterMotor->IsFwdLimitSwitchClosed() != 1)
	{
		gearPiston->Set(DoubleSolenoid::Value::kForward);
	}
	else if(reset)
	{
		shooterMotor->Set(speed);
		gearPiston->Set(DoubleSolenoid::Value::kReverse);
	}
	else if(shoot && (shooterMotor->IsFwdLimitSwitchClosed() == 1))
	{
		gearPiston->Set(DoubleSolenoid::Value::kOff);
		shooterMotor->Set(0);
	}
	else
	{
		gearPiston->Set(DoubleSolenoid::Value::kOff);
		shooterMotor->Set(0);
	}
}*/

void Shooter::catapultReset(bool reset)
{
	/*if(shooterMotor->GetEncPosition() > 10)
	{
		shooterMotor->Set(0);
	}*/
	if(reset == true && Limit->Get() != true)
	{
		shooterMotor->Set(.1); //WARNING: DO NOT MAKE NEGATIVE (and may need to change value)
	}
	else
	{
		shooterMotor->Set(0);
	}
}

void Shooter::catapultLaunch(bool fwdPiston, bool safety)
{
	if(fwdPiston and safety)
	{
		gearPiston->Set(DoubleSolenoid::Value::kForward);
		Wait(2);
		gearPiston->Set(DoubleSolenoid::Value::kReverse);
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

