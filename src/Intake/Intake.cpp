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

void Intake::toggleIntake(bool isPressed)
{
	if(isPressed && !intakeInwards)
	{
		leftIntakeMotor->Set(INTAKE_SPEED);
		rightIntakeMotor->Set(-INTAKE_SPEED);
		intakeInwards = true;
	}
	else if(isPressed && intakeInwards)
	{
		leftIntakeMotor->Set(-INTAKE_SPEED);
		rightIntakeMotor->Set(INTAKE_SPEED);
		intakeInwards = false;
	}
	else
	{
		leftIntakeMotor->Set(0);
		rightIntakeMotor->Set(0);
	}
}

void Intake::pivotIntake(Joystick* joystick)
{
	while(joystick->GetPOV() == 0) // POV is the d-pad on the xbox controller
			pivotMotor->Set(PIVOT_SPEED);
	while(joystick->GetPOV() == 180)
			pivotMotor->Set(-PIVOT_SPEED);
	pivotMotor->Set(0);
}

void Intake::set45Deg(Joystick* joystick)
{
	if(angleChecker->Get() >= 0 &&  anglechecker->Get() < 1000 && joystick->GetRawButton(LOCK_PIVOT_BUTTON))
	{
		while(angleChecker->Get() < 1000) // TODO: get enc value when intake pivots to 45 deg
			pivotMotor->Set(PIVOT_SPEED);
	}
	else if(angleChecker->Get() > 1000 && joystick->GetRawButton(LOCK_PIVOT_BUTTON))
	{
		while(angleChecker->Get() > 1000)
			pivotMotor->Set(-PIVOT_SPEED);
	}
	angleChecker->Reset();
}