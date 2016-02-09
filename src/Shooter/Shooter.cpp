#include "Shooter.h"

Shooter::Shooter()
{
	shooterMotor = new CANTalon(SHOOTER_MOTOR_CHANNEL);
	shooterEncoder = new Encoder(SHOOTER_ENCODER_CHANNEL_A, SHOOTER_ENCODER_CHANNEL_B);
	gearPiston = new DoubleSolenoid(GEAR_PISTON_CHANNEL_A, GEAR_PISTON_CHANNEL_B);

	speed = 0;
}

Shooter::~Shooter()
{
	delete shooterMotor;
	delete shooterEncoder;
	delete gearPiston;

	shooterMotor = nullptr; 
	shooterEncoder = nullptr;
	gearPiston = nullptr;
}

//auto reset after a shot 
//hold safety button then click trigger to shoot. have to have both pressed

// right bumper is safety button 
// right trigger is the shoot button

void Shooter::shoot(bool shoot, bool reset)
{
	while(joystick->GetRawButton(SAFETY_BUTTON))
	{
		if(shoot && shooterEncoder->Get() < 2000) // TODO: get actual encoder value
		{
			gearPiston->Set(DoubleSolenoid::Value::kForward);
			shooterEncoder->Reset();
		}
		else if(reset)
		{
			shooterMotor->Set(speed);
			gearPiston->Set(DoubleSolenoid::Value::kReverse);
			shooterEncoder->Reset();
		}
	}
	else
	{
		gearPiston->Set(DoubleSolenoid::Value::kOff);
		shooterMotor->Set(0);
	}
}