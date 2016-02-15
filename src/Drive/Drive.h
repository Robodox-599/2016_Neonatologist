#ifndef DRIVE_H_
#define DRIVE_H_

#include "../Macros.h"

class Drive
{
public:
	Drive();
	~Drive();

	void setForwardSpeed(float rawY);
	void setTurnSpeed(float rawX);

	void updateLeftMotors(float speed);
	void updateRightMotors(float speed);

	void driveMotors(float turn, float fwd);

	void shiftGears(bool shiftStateA, bool shiftStateB);
	
	bool getShiftState();
	float getForwardSpeed();
	float getTurnSpeed();

	float getCANTalonEncPos();
	float getCANTalonEncVel();

private:
	CANTalon* frontLeftDrive;
	CANTalon* backLeftDrive;
	CANTalon* frontRightDrive;
	CANTalon* backRightDrive;

	DoubleSolenoid* shifter;

	float forwardSpeed;
	float turnSpeed;

	float encPosition;
	float encVelocity;

	bool shiftState;
};

#endif
