#ifndef DRIVE_H_
#define DRIVE_H_

#include "../Macros.h"
#include "AHRS.h"

class Drive
{
public:
	Drive();
	~Drive();

	void updateLeftMotors(float speed);
	void updateRightMotors(float speed);

	void setForwardSpeed(float rawY);
	void setTurnSpeed(float rawX);
	void setTriggerSpeed(float triggerR, float triggerL);

	void drive(float xAxis, float yAxis, int POV);

	void setReferenceAngle(int angle);
	void edgeCase();
	void shortestPath();
	float linearizeDrive(float driveInput);

	void driveMotors(float turn, float fwd);

	void shiftGears(bool shiftStateA);//, bool shiftStateB);
	void toggleGyro(bool gyro);
	
	bool getShiftState();
	float getForwardSpeed();
	float getTurnSpeed();


	float getCANTalonEncPos();
	float getCANTalonEncVel();
	float getRightInput();
	float getLeftInput();

	int sign(float num);

	AHRS* navX;

	float referenceAngle;

	float turbo;
	float leftRight;

private:


	CANTalon* frontLeftDrive;
	CANTalon* backLeftDrive;
	CANTalon* frontRightDrive;
	CANTalon* backRightDrive;

	DoubleSolenoid* shifter;


	float forwardSpeed;
	float turnSpeed;

	float error360;
	float error180;
	float gyroValue;
	bool autoTurn;

	bool shiftState;
};

#endif

