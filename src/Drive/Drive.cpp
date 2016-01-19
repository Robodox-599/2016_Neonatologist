#include "Drive.h"

Drive::Drive()
{
	//left drive
	frontLeftDrive = new CANTalon(FRONT_LEFT_MOTOR_CHANNEL);
	backLeftDrive = new CANTalon(BACK_LEFT_MOTOR_CHANNEL);

	//right drive REVERSED MOTORS
	frontRightDrive = new CANTalon(FRONT_RIGHT_MOTOR_CHANNEL);
	backRightDrive = new CANTalon(BACK_RIGHT_MOTOR_CHANNEL);

	forwardSpeed = 0;
	turnSpeed = 0;
}

Drive::~Drive()
{
	//left drive
	delete frontLeftDrive;
	delete backLeftDrive;

	//right drive
	delete frontRightDrive;
	delete backRightDrive;

	//left drive
	frontLeftDrive = NULL;
	backLeftDrive = NULL;

	//right drive
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

void Drive::TestCANTalonEnc()
{
	frontLeftDrive->GetEncPosition();// 0 - 1023 ticks
	frontLeftDrive->GetEncVel();// ticks / 100ms
	//TODO: find out wheel radius + thickness of tread
	//http://robotpy.readthedocs.org/en/latest/wpilib/CANTalon.html
	//http://www.ctr-electronics.com/Talon%20SRX%20Software%20Reference%20Manual.pdf
	//http://first.wpi.edu/FRC/roborio/release/docs/cpp/classCANTalon.html#abc68589c199f4e968b7e74c2dc3a110a
}
