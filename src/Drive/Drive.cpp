#include "Drive.h"

Drive::Drive()
{
	frontLeftDrive = new CANTalon(FRONT_LEFT_MOTOR_PORT);
	backLeftDrive = new CANTalon(BACK_LEFT_MOTOR_PORT);
	frontRightDrive = new CANTalon(FRONT_RIGHT_MOTOR_PORT); // right motors are reversed
	backRightDrive = new CANTalon(BACK_RIGHT_MOTOR_PORT);

	forwardSpeed = 0;
	turnSpeed = 0;

	encPosition = 0;
	encVelocity = 0;
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

void Drive::drive(float X, float Y)
{
	//update motor speeds
	setForwardSpeed(Y);
	setTurnSpeed(X);

	// Add values to avoid constant switch between setting x and y joy stick values to motors
	updateLeftMotors(forwardSpeed + turnSpeed);
	updateRightMotors(forwardSpeed - turnSpeed);
}

float Drive::getCANTalonEncPosition()
{
	//Returns the tick the encoder is currently at (0 - 1023)
	encPosition = frontLeftDrive->GetEncPosition();
	return encPosition;
}

float Drive::getCANTalonEncVelocity()
{
	encVelocity = frontLeftDrive->GetEncVel();
	return encVelocity;
}





