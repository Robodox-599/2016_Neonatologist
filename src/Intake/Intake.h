#ifndef INTAKE_H_
#define INTAKE_H_

#include "..\Macros.h"

class Intake
{
public:
	Intake();
	~Intake();

	void toggleIntake(bool isPressed);
	void pivotIntake(Joystick* joystick);
private:
	CANTalon* leftIntakeMotor;
	CANTalon* rightIntakeMotor;
	CANTalon* pivotMotor;

	bool intakeInwards;

};

#endif
