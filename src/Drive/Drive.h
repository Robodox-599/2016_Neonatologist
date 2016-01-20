#ifndef DRIVE_H_
#define DRIVE_H_

#include "../Macros.h"
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
	CANTalon* frontLeftDrive;
	CANTalon* backLeftDrive;

	CANTalon* frontRightDrive;
	CANTalon* backRightDrive;

	int forwardSpeed;
	int turnSpeed;
};



#endif
