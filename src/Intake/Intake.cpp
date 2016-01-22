#include "Intake.h"

Intake::Intake()
{
	leftIntakeMotor = new CANTalon(LEFT_INTAKE_MOTOR_CHANNEL);
	rightIntakeMotor = new CANTalon(RIGHT_INTAKE_MOTOR_CHANNEL);
	pivotMotor = new CANTalon(PIVOT_MOTOR_CHANNEL);

	intakeInwards = false;
}

Intake::~Intake()
{
	delete leftIntakeMotor;
	delete rightIntakeMotor;
	delete pivotMotor;

	leftIntakeMotor = nullptr;
	rightIntakeMotor = nullptr;
	pivotMotor = nullptr;
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
	if(joystick->GetPOV() == 0)
	{
		while(joystick->GetPOV() == 0)
			pivotMotor->Set(PIVOT_SPEED);
	}
	else if (joystick->GetPOV() == 180)
	{
		while(joystick->GetPOV() == 180)
			pivotMotor->Set(-PIVOT_SPEED);
	}
	else
		pivotMotor->Set(0);
}