#include "Intake.h"

Intake::Intake()
{
	leftIntakeMotor = new Talon(LEFT_INTAKE_MOTOR_CHANNEL);
	rightIntakeMotor = new Talon(RIGHT_INTAKE_MOTOR_CHANNEL); 
}

Intake::~Intake()
{
	delete leftIntakeMotor;
	delete rightIntakeMotor;

	leftIntakeMotor = NULL;
	rightIntakeMotor = NULL;
}

void Intake::toggleIntake(Joystick* joystick)
{
	if(joystick->GetRawButton(INTAKE_BUTTON_A))
	{
		leftIntakeMotor->Set(INTAKE_SPEED);
		rightIntakeMotor->Set(-INTAKE_SPEED);
	}
	else if(joystick->GetRawButton(INTAKE_BUTTON_B))
	{
		leftIntakeMotor->Set(-INTAKE_SPEED);
		rightIntakeMotor->Set(INTAKE_SPEED);
	}
	else
	{
		leftIntakeMotor->Set(0);
		rightIntakeMotor->Set(0);
	}
}