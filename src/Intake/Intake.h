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
	int getIntakeEncoderValue();
	int getIntakeEncoderVel();// 2/29

	CANTalon* intakeRollerMotor;
	CANTalon* pivotMotor;
private:


	bool intakeInwards;
};

#endif
