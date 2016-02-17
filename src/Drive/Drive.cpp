#include "Drive.h"


Drive::Drive()
{


	//left drive
	frontLeftDrive = new CANTalon(FRONT_LEFT_MOTOR_CHANNEL);
	backLeftDrive = new CANTalon(BACK_LEFT_MOTOR_CHANNEL);

	//right drive REVERSED MOTORS
	frontRightDrive = new CANTalon(FRONT_RIGHT_MOTOR_CHANNEL);
	backRightDrive = new CANTalon(BACK_RIGHT_MOTOR_CHANNEL);

	navX = new AHRS(SPI::Port::kMXP);

	forwardSpeed = 0;
	turnSpeed = 0;

	error360 = 0;
	error180 = 0;

	autoTurn = false;
	gyroValue = navX->GetYaw();
	referenceAngle = 0;

	encPosition = 0;
	encVelocity = 0;
}


Drive::~Drive()
{
	delete navX;

	//left drive
	delete frontLeftDrive;
	delete backLeftDrive;

	//right drive
	delete frontRightDrive;
	delete backRightDrive;

	navX = NULL;

	//left drive
	frontLeftDrive = NULL;
	backLeftDrive = NULL;

	//right drive
	frontRightDrive = NULL;
	backRightDrive = NULL;

}


/*************************************************/


//this function updates the left motors
void Drive::updateLeftMotors(float speed)
{
	frontLeftDrive->Set(speed);
	backLeftDrive->Set(speed);
}

//this function updates the right motors
void Drive::updateRightMotors(float speed)
{
	frontRightDrive->Set(-speed);
	backRightDrive->Set(-speed);
}

//this sets the forward speed
void Drive::setForwardSpeed(float forward)
{
	if(forward >= DEADZONE || forward <= -DEADZONE)
	{
		forwardSpeed = forward;
	}
	else
	{
		forwardSpeed = 0;
	}
}

//this sets the turn speed and does PID (straight drive)
void Drive::setTurnSpeed(float turn)
{

	if(turn >= DEADZONE || turn <= -DEADZONE)
	{
		turnSpeed = turn;

		autoTurn = false;

		referenceAngle = 0;
		navX->ZeroYaw();
	}
	else if((error360 <= -.5 || error360 >= .5) && (error180 <= -.5 || error180 >= .5))
	{
		turnSpeed = KP * shortestPath();
	}
	else if(gyroValue == referenceAngle || navX->GetYaw() == referenceAngle)
	{
		turnSpeed = 0;
		autoTurn = false;
		navX->ZeroYaw();
		gyroValue = 0;
		referenceAngle = 0;
	}
}

//this is the main drive function
void Drive::drive(float xAxis, float yAxis, int POV)
{
	gyroValue = navX->GetYaw();
	edgeCase();
	setReferenceAngle(POV);
	setForwardSpeed(xAxis);

	error360 = referenceAngle - gyroValue;
	error180 = referenceAngle - navX->GetYaw();

	setTurnSpeed(yAxis);

	updateLeftMotors(linearizeDrive(forwardSpeed - turnSpeed));
	updateRightMotors(linearizeDrive(forwardSpeed + turnSpeed));
}


/*******************************************************************/


//this function sets the desired angle from the D-Pad
void Drive::setReferenceAngle(int angle)
{
		switch(angle)
		{
			case 270 :
				navX->ZeroYaw();
				referenceAngle = -90;
				autoTurn = true;
				break;
			case 180 :
			case 90 :
			case 0 :
				navX->ZeroYaw();
				referenceAngle = angle;
				autoTurn = true;
				break;
			default :
				break;
		}
}

//this function compensates for the edge cases on the gyro
void Drive::edgeCase()
{
	if(gyroValue < 0)
	{
		gyroValue += 360;
	}
}

//this function determines the shortest path to the desired angle
float Drive::shortestPath()
{
	if(std::abs(error180) < std::abs(error360))
	{
		return error180;
	}

	return error360;
}

//This function scales the motor input
float Drive::linearizeDrive(float driveInput)
{
	return driveInput * SLOPE_ADJUSTMENT;
}


/************************************************************************/


//Returns the tick the encoder is currently at (0 - 1023)
float Drive::getCANTalonEncPosition()
{
	encPosition = frontLeftDrive->GetEncPosition();
	return encPosition;
}

//Returns the velocity at which the encoder is currently going at
float Drive::getCANTalonEncVelocity()
{
	encVelocity = frontLeftDrive->GetEncVel();
	return encVelocity;
}
