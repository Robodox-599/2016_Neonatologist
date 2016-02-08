#ifndef INTAKE_H_
#define INTAKE_H_

#include "..\Macros.h"

class Intake
{
public:
	Intake();
	~Intake();

	void toggleIntake(bool intakeButton, bool outtakeButton);
	void pivotIntake(Joystick* joystick);
	void setAngle(Joystick* joystick);
private:
	CANTalon* leftIntakeMotor;
	CANTalon* rightIntakeMotor;
	CANTalon* pivotMotor;

	Encoder* angleChecker;

	bool intakeInwards;
};

#endif
