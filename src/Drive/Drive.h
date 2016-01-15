#ifndef DRIVE_H_
#define DRIVE_H_

#include "..\Macros.h"

class Drive
{
public:
	Drive();
	~Drive();
private:
	Talon* frontLeftMotor;
	Talon* frontRightMotor;
	Talon* backLeftMotor;
	Talon* backRightMotor;
};

#endif
