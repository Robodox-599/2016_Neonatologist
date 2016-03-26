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
	float shortestPath();
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

	//create an incriment function to control sensitivity of drive motor input
	void incriment(float motorLeftInput, float motorRightInput);

	AHRS* navX;

	float referenceAngle;

	float turbo;
	float leftRight;

	float forwardSpeed;
	float turnSpeed;

	float driveLeft;
	float driveRight;

	float trigL;
	float trigR;

	float error360;
	float error180;
	float gyroValue;
	bool autoTurn;

	bool shiftState;

private:


	CANTalon* frontLeftDrive;
	CANTalon* backLeftDrive;
	CANTalon* frontRightDrive;
	CANTalon* backRightDrive;

	DoubleSolenoid* shifter;

};

#endif

