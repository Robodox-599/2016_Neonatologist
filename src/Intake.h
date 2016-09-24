#ifndef SRC_INTAKE_H_
#define SRC_INTAKE_H_

#include "WPILib.h"
#include "Macros.h"

class Intake
{
public:
	Intake();
	~Intake();

	void setIntakeMotor(float speed);
	void toggleIntake(bool intakeButton, bool outtakeButton);
	void pivotIntake(float pivotSpeed);
	void intakeRoller(bool lockPivot); //setAngle
	int getIntakeEncVal(); //ENCODER VALUE

private:
	CANTalon* intakeRollerMotor;
	//DoubleSolenoid* pivotPiston;

	bool intakeInwards;
	float rollerSpeed;
};



#endif
