#include "Intake.h"

Intake::Intake()
{
	leftIntakeMotor = new CANTalon(LEFT_INTAKE_MOTOR_CHANNEL);
	rightIntakeMotor = new CANTalon(RIGHT_INTAKE_MOTOR_CHANNEL);
	pivotMotor = new CANTalon(PIVOT_MOTOR_CHANNEL);

	angleChecker = new Encoder(PIVOT_ENCODER_CHANNEL_A, PIVOT_ENCODER_CHANNEL_B);

	intakeInwards = false;
}

Intake::~Intake()
{
	delete leftIntakeMotor;
	delete rightIntakeMotor;
	delete pivotMotor;
	delete angleChecker;

	leftIntakeMotor = nullptr;
	rightIntakeMotor = nullptr;
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
		leftIntakeMotor->Set(INTAKE_SPEED);
		rightIntakeMotor->Set(-INTAKE_SPEED);
		intakeInwards = true;
	}
	else if(outtakeButton && intakeInwards) // but if we want to do the outake thing, we should only do it if something has already been taken in
	{
		leftIntakeMotor->Set(-INTAKE_SPEED);
		rightIntakeMotor->Set(INTAKE_SPEED);
		intakeInwards = false;
	}
	else // don't do anything if we don't tell the motors anything
	{
		leftIntakeMotor->Set(0);
		rightIntakeMotor->Set(0);
	}
}

/**
 * pivotIntake: uses the intake motors to change the angle of the intake
 * @param pivotUp commands the intake to pivot upwards - used with a joystick button
 * @param pivotDown commands the intake to pivot downwards - used with a joystick button
 */
void Intake::pivotIntake(bool pivotUp, bool pivotDown)
{
	// while statements allow the button to be held down. hopefully.
	while(pivotUp)
			pivotMotor->Set(PIVOT_SPEED);
	while(pivotDown)
			pivotMotor->Set(-PIVOT_SPEED);
	pivotMotor->Set(0);
}

/**
 * setAngle: puts the intake at a certain angle
 * @param joystick is the joystick used to get the angle setting button
 */
void Intake::setAngle(Joystick* joystick)
{
	if(angleChecker->Get() >= 0 &&  anglechecker->Get() < 1000 && joystick->GetRawButton(LOCK_PIVOT_BUTTON))
	{
		while(angleChecker->Get() < 1000) // TODO: get enc value when intake pivots to the desired angle
			pivotIntake(true, false); // go up
	}
	else if(angleChecker->Get() > 1000 && joystick->GetRawButton(LOCK_PIVOT_BUTTON))
	{
		while(angleChecker->Get() > 1000) // go down
			pivotIntake(false, true);
	}
	angleChecker->Reset();
}
