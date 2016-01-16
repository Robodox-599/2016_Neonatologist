#ifndef INTAKE_H_
#define INTAKE_H_

#include "..\Macros.h"

class Intake
{
public:
	Intake();
	~Intake();

	void toggleIntake();
private:
	Talon* leftIntakeMotor;
	Talon* rightIntakeMotor;

};

#endif
