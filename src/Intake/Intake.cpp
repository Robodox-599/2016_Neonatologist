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
