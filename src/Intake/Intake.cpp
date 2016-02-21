#include "Intake.h"

Intake::Intake()
{
	intakeRollerMotor = new CANTalon(INTAKE_ROLLER_MOTOR_CHANNEL);
	pivotMotor = new CANTalon(PIVOT_MOTOR_CHANNEL);

	angleChecker = new Encoder(PIVOT_ENCODER_CHANNEL_A, PIVOT_ENCODER_CHANNEL_B);

	intakeInwards = false;
}

Intake::~Intake()
{
	delete intakeRollerMotor;
	delete pivotMotor;
	delete angleChecker;

	intakeRollerMotor = nullptr;
	pivotMotor = nullptr;
	angleChecker = nullptr;
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
	if(intakeButton && !intakeInwards) // if we want to intake something, we have to make sure nothing has already been taken in
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
	}
}

/**
 * pivotIntake: uses the intake motors to change the angle of the intake
 * @param pivotUp commands the intake to pivot upwards - used with a joystick button
 * @param pivotDown commands the intake to pivot downwards - used with a joystick button
 */
void Intake::pivotIntake(float pivotSpeed)
{
	// while statements allow the button to be held down. hopefully.
	pivotMotor->Set(pivotSpeed*0.75);
}

/**
 * setAngle: puts the intake at a certain angle
 * @param joystick is the joystick used to get the angle setting button
 */
void Intake::setAngle(bool lockPivot)
{
	if(angleChecker->Get() >= 0 &&  angleChecker->Get() < 1000 && lockPivot)
	{
		while(angleChecker->Get() < 1000) // TODO: get enc value when intake pivots to the desired angle
			pivotIntake(0.8); // go up
	}
	else if(angleChecker->Get() > 1000 && lockPivot)
	{
		while(angleChecker->Get() > 1000) // go down
			pivotIntake(0.8);
	}
	angleChecker->Reset();
}

int Intake::getAngleCheckerValue()
{
	return angleChecker->Get();
}
