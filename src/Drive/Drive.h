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

private:
	//left drive
	CANTalon* frontLeftDrive;
	CANTalon* backLeftDrive;

	//right drive
	CANTalon* frontRightDrive;
	CANTalon* backRightDrive;

	int forwardSpeed;
	int turnSpeed;
};



#endif /* SRC_DRIVE_H_ */
