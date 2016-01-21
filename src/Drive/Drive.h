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

	void setForwardSpeed(float rawY);
	void setTurnSpeed(float rawX);

	void updateLeftMotors(float speed);
	void updateRightMotors(float speed);

	void drive(float X, float Y);

	float getCANTalonEncPosition();
	float getCANTalonEncVelocity();

private:
	//left drive
	CANTalon* frontLeftDrive;
	CANTalon* backLeftDrive;

	//right drive
	CANTalon* frontRightDrive;
	CANTalon* backRightDrive;

	float forwardSpeed;
	float turnSpeed;

	float encPosition;
	float encVelocity;
};



#endif /* SRC_DRIVE_H_ */
