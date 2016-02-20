#ifndef DRIVE_H_
#define DRIVE_H_

#include "../Macros.h"


class Drive
{
public:
	Drive();
	~Drive();

	void updateLeftMotors(float speed);
	void updateRightMotors(float speed);

	void setForwardSpeed(float rawY);
	void setTurnSpeed(float rawX);

	void drive(float xAxis, float yAxis, int POV);

	void setReferenceAngle(int angle);
	void edgeCase();
	float shortestPath();
	float linearizeDrive(float driveInput);

	//void driveMotors(float turn, float fwd);

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

	//AHRS* navX;

	DoubleSolenoid* shifter;


	float forwardSpeed;
	float turnSpeed;
/*
	float error360;
	float error180;

	bool autoTurn;
	float gyroValue;
	int referenceAngle;*/

	float encPosition;
	float encVelocity;

	bool shiftState;
};

#endif
