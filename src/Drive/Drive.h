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

	void shiftGears(bool changeShift);
	
	bool getShiftState();
	float getForwardSpeed();
	float getTurnSpeed();

	int getCANTalonEncPos(CANTalon* motorPos);// 2/29
	int getCANTalonEncVel(CANTalon* motorVel);// 2/29

	//moved on 2/29

	CANTalon* frontLeftDrive;
	CANTalon* backLeftDrive;

	CANTalon* frontRightDrive;
	CANTalon* backRightDrive;

	DoubleSolenoid* shifter;

private:
	float forwardSpeed;
	float turnSpeed;

	float encPosition;
	float encVelocity;

	bool shiftState;

	bool shiftA;
};

#endif
