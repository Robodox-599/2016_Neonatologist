#ifndef INTAKE_H_
#define INTAKE_H_

#include "..\Macros.h"

class Intake
{
public:
	Intake();
	~Intake();

	void toggleIntake(bool isPressed);
private:
	Talon* leftIntakeMotor;
	Talon* rightIntakeMotor;

	bool intakeInwards;

};

#endif
