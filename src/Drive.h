/*
 * Drive.h
 *
 *  Created on: Mar 27, 2016
 *      Author: Robodox 599
 */

#ifndef SRC_DRIVE_DRIVE_H_
#define SRC_DRIVE_DRIVE_H_

#include "WPILib.h"
#include "Macros.h"

//#include "../Macros.h"

class Drive
{
public:
	Drive();
	~Drive();

	void drive(float xAxis, float yAxis);

	void setForwardSpeed(float forward);
	void setTurnSpeed(float turn);

	void updateLeftMotors(float speed);
	void updateRightMotors(float speed);

	void shifter(bool shift);

private:
	CANTalon* frontLeftDrive;
	CANTalon* backLeftDrive;
	CANTalon* frontRightDrive;
	CANTalon* backRightDrive;

	DoubleSolenoid* driveShifter;

	float forwardSpeed;
	float turnSpeed;
};



#endif /* SRC_DRIVE_DRIVE_H_ */
