/*
 * Drive.cpp
 *
 *  Created on: Jan 9, 2016
 *      Author: Admin
 */

#include "Drive.h"

Drive::Drive()
{
	//left drive
	frontLeftDrive = new CANTalon(FRONT_LEFT_MOTOR_CHANNEL);
	rearLeftDrive = new CANTalon(BACK_LEFT_MOTOR_CHANNEL);

	//right drive
	frontRightDrive = new CANTalon(FRONT_RIGHT_MOTOR_CHANNEL);
	rearRightDrive = new CANTalon(BACK_RIGHT_MOTOR_CHANNEL);

	forwardSpeed = 0;
	turnSpeed = 0;
}

Drive::~Drive()
{
	//left drive
	delete frontLeftDrive;
	delete rearLeftDrive;

	//right drive
	delete frontRightDrive;
	delete rearRightDrive;

	//left drive
	frontLeftDrive = NULL;
	rearLeftDrive = NULL;

	//right drive
	frontRightDrive = NULL;
	rearRightDrive = NULL;

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
	rearLeftDrive->Set(speed);
}

void Drive::updateRightMotors(float speed)
{
	frontRightDrive->Set(speed);
	rearRightDrive->Set(speed);
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


