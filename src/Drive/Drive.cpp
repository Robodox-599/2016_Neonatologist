#include "Drive.h"

Drive::Drive()
{
	frontLeftDrive = new CANTalon(FRONT_LEFT_MOTOR_PORT);
	backLeftDrive = new CANTalon(BACK_LEFT_MOTOR_PORT);
	frontRightDrive = new CANTalon(FRONT_RIGHT_MOTOR_PORT); // right motors are reversed
	backRightDrive = new CANTalon(BACK_RIGHT_MOTOR_PORT);

	shifter = new DoubleSolenoid(SHIFTER_PORT_A, SHIFTER_PORT_B);

	forwardSpeed = 0;
	turnSpeed = 0;

	encPosition = 0;
	encVelocity = 0;

	shiftA = true;
	shiftState = true; 
}

Drive::~Drive()
{
	delete frontLeftDrive;
	delete backLeftDrive;
	delete frontRightDrive;
	delete backRightDrive;
	delete shifter;

	frontLeftDrive = nullptr;
	backLeftDrive = nullptr;
	frontRightDrive = nullptr;
	backRightDrive = nullptr;
	shifter = nullptr;
}

/**
 * setForwardSpeed: update forward speed with joystick input
 * @param rawY is the joystick y-axis
 */
void Drive::setForwardSpeed(float rawY)
{
	if(rawY > DEADZONE || rawY < -DEADZONE)
	{
		forwardSpeed = rawY;
	}
	else forwardSpeed = 0;
}

/**
 * setTurnSpeed: update turn speed with joystick input
 * @param rawX is the joystick x-axis
 */
void Drive::setTurnSpeed(float rawX)
{
	if(rawX > DEADZONE || rawX < -DEADZONE)
	{
		turnSpeed = rawX;
	}
	else forwardSpeed = 0;
}

/*
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
 * drive: get desired speed values and assign them to motors
 * @param turn is the turn speed
 * @param fwd is the fwd/backward speed
 */
void Drive::driveMotors(float turn, float fwd)
{
	turn *= 0.75;
	setForwardSpeed(fwd);
	setTurnSpeed(turn);

	updateLeftMotors(forwardSpeed + turnSpeed);
	updateRightMotors(forwardSpeed - turnSpeed);
}

/**
 * shiftGears: switches gears, i guess, and changes a bool to signal current state
 * @param shiftStateA is a button that switches to the first gear state
 * @param shiftStateB is a button that switches to the second gear state
 * TODO: actually understand what this means
 */
void Drive::shiftGears(bool changeShift)
{
	if(changeShift && shiftA)
	{
		shifter->Set(DoubleSolenoid::Value::kReverse);
		shiftA = false;
	}
	else if(changeShift && !shiftA)
	{
		shifter->Set(DoubleSolenoid::Value::kForward);
		shiftA = true;
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
	return shiftA;
}

float Drive::getCANTalonEncPos()
{
	return  frontLeftDrive->GetEncPosition();
}

float Drive::getCANTalonEncVel()
{
	return  frontLeftDrive->GetEncVel();
}
