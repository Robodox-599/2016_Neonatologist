/*
 * Drive.h
 *
 *  Created on: Jan 9, 2016
 *      Author: Admin
 */
#ifndef SRC_DRIVE_H_
#define SRC_DRIVE_H_

#include "Macros.h"
#include "Drive.h"
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

	void drive(float xAxis, float yAxis, int POV);

	void setReferenceAngle(int angle);
	void edgeCase();
	float shortestPath();
	float linearizeDrive(float driveInput);

	float getCANTalonEncPosition();
	float getCANTalonEncVelocity();

private:
	//left drive
	CANTalon* frontLeftDrive;
	CANTalon* backLeftDrive;

	//right drive
	CANTalon* frontRightDrive;
	CANTalon* backRightDrive;

	AHRS* navX;

	float forwardSpeed;
	float turnSpeed;

	float error360;
	float error180;

	bool autoTurn;
	float gyroValue;
	int referenceAngle;

	float encPosition;
	float encVelocity;
};



#endif /* SRC_DRIVE_H_ */
