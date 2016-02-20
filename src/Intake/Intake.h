#ifndef INTAKE_H_
#define INTAKE_H_

#include "..\Macros.h"

class Intake
{
public:
	Intake();
	~Intake();

	void toggleIntake(bool intakeButton, bool outtakeButton);
	void pivotIntake(bool pivotUp, bool pivotDown);
	void setAngle(Joystick* joystick);
private:
	CANTalon* intakeRollerMotor;
	CANTalon* pivotMotor;

	Encoder* angleChecker;

	bool intakeInwards;
};

#endif
