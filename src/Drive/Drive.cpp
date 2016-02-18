#include "Drive.h"


Drive::Drive()
{
	//left drive
	frontLeftDrive = new CANTalon(FRONT_LEFT_MOTOR_PORT);
	backLeftDrive = new CANTalon(BACK_LEFT_MOTOR_PORT);
	frontRightDrive = new CANTalon(FRONT_RIGHT_MOTOR_PORT); // right motors are reversed
	backRightDrive = new CANTalon(BACK_RIGHT_MOTOR_PORT);

	shifter = new DoubleSolenoid(SHIFTER_PORT_A, SHIFTER_PORT_B);

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

	shiftState = true; 
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
	delete shifter;

	navX = nullptr;

	//left drive
	frontLeftDrive = nullptr;
	backLeftDrive = nullptr;

	//right drive
	frontRightDrive = nullptr;
	backRightDrive = nullptr;

	shifter = nullptr;
}


/*************************************************/


/**
 * updateLeftMotors: set left motors to desired speed
 * @param speed is the desired speed input
 */
void Drive::updateLeftMotors(float speed)
{
	frontLeftDrive->Set(speed);
	backLeftDrive->Set(speed);
}

/**
 * updateRightMotors: set right motors to desired speed; reverses right motors
 * @param speed is the desired speed input
 */
void Drive::updateRightMotors(float speed)
{
	frontRightDrive->Set(-speed);
	backRightDrive->Set(-speed);
}

/**
 * setForwardSpeed: update forward speed with joystick input
 * @param speed is the joystick y-axis
 */
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

/**
 * setTurnSpeed: update turn speed with joystick input and does PID (straight drive)
 * @param turn is the joystick x-axis
 */
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

/**
 * drive: get desired speed values and assign them to motors
 * @param turn is the turn speed
 * @param fwd is the fwd/backward speed
 *
 */
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


/*
void Drive::driveMotors(float turn, float fwd)
{
	setForwardSpeed(fwd);
	setTurnSpeed(turn);

	updateLeftMotors(forwardSpeed + turnSpeed);
	updateRightMotors(forwardSpeed - turnSpeed);
}
*/

//Returns the tick the encoder is currently at (0 - 1023)
float Drive::getCANTalonEncPos()
{
	return  frontLeftDrive->GetEncPosition();
}

//Returns the velocity at which the encoder is currently going at
float Drive::getCANTalonEncVel()
{
	return  frontLeftDrive->GetEncVel();
}

/**
 * shiftGears: switches gears, i guess, and changes a bool to signal current state
 * @param shiftStateA is a button that switches to the first gear state
 * @param shiftStateB is a button that switches to the second gear state
 * TODO: actually understand what this means
 */
void Drive::shiftGears(bool shiftStateA, bool shiftStateB)
{
	if(shiftStateA)
	{
		shifter->Set(DoubleSolenoid::Value::kForward);
		shiftState = true;
	}
	else if(shiftStateB)
	{
		shifter->Set(DoubleSolenoid::Value::kReverse);
		shiftState = false;
	}
}

float Drive::getForwardSpeed()
{
	return forwardSpeed;
}

float Drive::getTurnSpeed()
{
	return turnSpeed;
}

bool Drive::getShiftState()
{
	return shiftState;
}
