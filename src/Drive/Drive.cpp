#include "Drive.h"

Drive::Drive()
{
	frontLeftDrive = new CANTalon(FRONT_LEFT_MOTOR_CHANNEL);
	backLeftDrive = new CANTalon(BACK_LEFT_MOTOR_CHANNEL);

	// these motors are reversed
	frontRightDrive = new CANTalon(FRONT_RIGHT_MOTOR_CHANNEL);
	backRightDrive = new CANTalon(BACK_RIGHT_MOTOR_CHANNEL);

	forwardSpeed = 0;
	turnSpeed = 0;
}

Drive::~Drive()
{
	delete frontLeftDrive;
	delete backLeftDrive;

	delete frontRightDrive;
	delete backRightDrive;

	frontLeftDrive = NULL;
	backLeftDrive = NULL;

	frontRightDrive = NULL;
	backRightDrive = NULL;
}

void Drive::setForwardSpeed(float rawY)
{
	if(rawY > DEADZONE || rawY < -DEADZONE)
	{
		forwardSpeed = rawY;
	}
}

void Drive::setTurnSpeed(float rawX)
{
	if(rawX > DEADZONE || rawX < -DEADZONE)
	{
		turnSpeed = rawX;
	}
}

void Drive::updateLeftMotors(float speed)
{
	frontLeftDrive->Set(speed);
	backLeftDrive->Set(speed);
}

void Drive::updateRightMotors(float speed)
{
	frontRightDrive->Set(-speed);
	backRightDrive->Set(-speed);
}

void Drive::drive(float x, float y)
{
	setForwardSpeed(y);
	setTurnSpeed(x);

	// Add values to avoid constant switch between setting x and y joy stick values to motors
	updateLeftMotors(forwardSpeed + turnSpeed);
	updateRightMotors(forwardSpeed - turnSpeed);
}
