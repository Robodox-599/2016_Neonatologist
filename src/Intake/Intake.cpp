#include "Intake.h"

Intake::Intake()
{
	leftIntakeMotor = new Talon(LEFT_INTAKE_MOTOR_CHANNEL);
	rightIntakeMotor = new Talon(RIGHT_INTAKE_MOTOR_CHANNEL);

	intakeInwards = false;
}

Intake::~Intake()
{
	delete leftIntakeMotor;
	delete rightIntakeMotor;

	leftIntakeMotor = nullptr;
	rightIntakeMotor = nullptr;
}

void Intake::toggleIntake(Joystick* joystick)
{
	if(joystick->GetRawButton(INTAKE_BUTTON) && !intakeInwards)
	{
		leftIntakeMotor->Set(INTAKE_SPEED);
		rightIntakeMotor->Set(-INTAKE_SPEED);
		intakeInwards = true;
	}
	else if(joystick->GetRawButton(INTAKE_BUTTON) && intakeInwards)
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
