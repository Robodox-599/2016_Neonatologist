#include "Intake.h"

Intake::Intake()
{
	intakeRollerMotor = new CANTalon(INTAKE_ROLLER_PORT);
	//pivotPiston = new DoubleSolenoid(PIVOT_PISTON_PORT_A,PIVOT_PISTON_PORT_B);

	intakeInwards = false;
	rollerSpeed = 0;

	//pivotPiston->Set(DoubleSolenoid::Value::kReverse);
}

Intake::~Intake()
{
	delete intakeRollerMotor;
	//delete pivotPiston;

	intakeRollerMotor = nullptr;
	//pivotPiston = nullptr;
}

/*void Intake::setIntakeMotor(float speed)
{
	intakeRollerMotor->Set(speed);
}*/

void Intake::toggleIntake(bool intakeButton, bool outtakeButton)//parameters are nothing
{
	//intakeRollerMotor->Set(-0.7);

	if(intakeButton)
	{
		intakeRollerMotor->Set(0.8);
	}
	else if(outtakeButton)
	{
		intakeRollerMotor->Set(-0.8);
	}
	else
	{
		intakeRollerMotor->Set(0);
	}
}

/*void Intake::pivotIntake(float pivotSpeed)
{
	if(pivotSpeed > .2 || pivotSpeed < -.2)
	{
		pivotPiston->Set(DoubleSolenoid::Value::kForward);
	}
	else
	{
		pivotPiston->Set(DoubleSolenoid::Value::kReverse);
	}
}*/ //took out piston code because we are taking piston out -Sam 9/23/16 2041

void Intake::intakeRoller(bool lockPivot)
{
	/*if(intakeRollerMotor->GetEncPosition() >= 0 && intakeRollerMotor->GetEncPosition() < 1000 && lockPivot)
	{
		pivotIntake(0.8);
	}
	else if(intakeRollerMotor->GetPosition() > 100 && lockPivot)
	{
		pivotIntake(0.8);
	}
	pivotPiston->Set(DoubleSolenoid::Value::kReverse);*/
}
