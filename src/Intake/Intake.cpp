#include "Intake.h"

Intake::Intake()
{
	intakeRollerMotor = new CANTalon(INTAKE_ROLLER_MOTOR_CHANNEL);
	pivotMotor = new CANTalon(PIVOT_MOTOR_CHANNEL);

	intakeInwards = false;

	pivotMotor->SetEncPosition(0);
}

Intake::~Intake()
{
	delete intakeRollerMotor;
	delete pivotMotor;

	intakeRollerMotor = nullptr;
	pivotMotor = nullptr;
}

//there has to be a god angle in which it automattically goes there in order to fit under the low goal 
//toggle manual button
//automatic button to self set to certain angle
//intake and outake buttons 

/**
 * toggleIntake: change whether the intake is in 'intake' or 'outtake mode'
 * @param intakeButton is the joystick button to start intake
 * @param outtakeButton is the joystick button to start outtake
 */
void Intake::toggleIntake(bool intakeButton, bool outtakeButton)
{
	/*if(intakeButton && !intakeInwards) // if we want to intake something, we have to make sure nothing has already been taken in
	{
		intakeRollerMotor->Set(INTAKE_SPEED);
		intakeInwards = true;
	}
	else if(outtakeButton && intakeInwards) // but if we want to do the outake thing, we should only do it if something has already been taken in
	{
		intakeRollerMotor->Set(-INTAKE_SPEED);
		intakeInwards = false;
	}
	else // don't do anything if we don't tell the motors anything
	{
		intakeRollerMotor->Set(0);
	}*/
	if(intakeButton)
	{
		//while(intakeButton)
			intakeRollerMotor->Set(INTAKE_SPEED);
	}
	else if(outtakeButton)
	{
		//while(outtakeButton)
			intakeRollerMotor->Set(-INTAKE_SPEED);
	}
	else
	{
		intakeRollerMotor->Set(0);
	}
}

/**
 * pivotIntake: uses the intake motors to change the angle of the intake
 * @param pivotSpeed is the speed that the intake should go up or down, taken from joystick input
 */
void Intake::pivotIntake(float pivotSpeed)
{
	if(pivotSpeed > DEADZONE || pivotSpeed < -DEADZONE)//pivotMotor->GetEncPosition() > -83)
	{
		pivotMotor->Set(pivotSpeed*0.75);
	}
	else
	{
		pivotMotor->Set(0);
	}
}

/**
 * setAngle: puts the intake at a certain angle
 * @param joystick is the joystick used to get the angle setting button
 */
void Intake::setAngle(bool lockPivot)
{
	if(intakeRollerMotor->GetEncPosition() >= 0 &&  intakeRollerMotor->GetEncPosition() < 1000 && lockPivot)
	{
		pivotIntake(0.8); // go up
	}
	else if(intakeRollerMotor->GetPosition() > 1000 && lockPivot)
	{
		pivotIntake(0.8);
	}
	intakeRollerMotor->SetEncPosition(0);
}

int Intake::getIntakeEncoderValue ()
{
	return pivotMotor->GetEncPosition();
}
