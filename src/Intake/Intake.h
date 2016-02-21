#ifndef INTAKE_H_
#define INTAKE_H_

#include "../Macros.h"

class Intake
{
public:
	Intake();
	~Intake();

	void toggleIntake(bool intakeButton, bool outtakeButton);
	void pivotIntake(float pivotSpeed);
	void setAngle(bool lockPivot);
	int getAngleCheckerValue();
private:
	CANTalon* intakeRollerMotor;
	CANTalon* pivotMotor;

	Encoder* angleChecker;

	bool intakeInwards;
};

#endif
