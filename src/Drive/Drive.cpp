#include "Drive.h"

Drive::Drive()
{
	frontLeftDrive = new CANTalon(FRONT_LEFT_MOTOR_PORT);
	backLeftDrive = new CANTalon(BACK_LEFT_MOTOR_PORT);
	frontRightDrive = new CANTalon(FRONT_RIGHT_MOTOR_PORT); // right motors are reversed
	backRightDrive = new CANTalon(BACK_RIGHT_MOTOR_PORT);

	shifter = new DoubleSolenoid(SHIFTER_PORT_A, SHIFTER_PORT_B);

	navX = new AHRS(SPI::Port::kMXP);

	forwardSpeed = 0;//
	turnSpeed = 0;//

	driveLeft = 0;
	driveRight = 0;

	error360 = 0;//
	error180 = 0;//

	navX->ZeroYaw();//
	autoTurn = false;//
	gyroValue = navX->GetYaw();//
	referenceAngle = navX->GetYaw();//

	trigR = 0;
	trigL = 0;

	shiftState = true;//
	turbo = 1;//
	leftRight = 1;//
}

Drive::~Drive()
{
	delete frontLeftDrive;
	delete backLeftDrive;
	delete frontRightDrive;
	delete backRightDrive;
	delete shifter;
	delete navX;

	frontLeftDrive = nullptr;
	backLeftDrive = nullptr;
	frontRightDrive = nullptr;
	backRightDrive = nullptr;
	shifter = nullptr;
	navX = nullptr;
}

/**
 * updateLeftMotors: set left motors to desired speed
 * @param speed is the desired speed input
 */
void Drive::updateLeftMotors(float speed)
{
	frontLeftDrive->Set(-speed /* * 0.7*/);
	backLeftDrive->Set(-speed /* * 0.7*/);
}

/**
 * updateRightMotors: set right motors to desired speed; reverses right motors
 * @param speed is the desired speed input
 */
void Drive::updateRightMotors(float speed)
{
	frontRightDrive->Set(speed /* * 0.7*/);
	backRightDrive->Set(speed /* * 0.7*/);
}

void Drive::setTriggerSpeed(float triggerR, float triggerL)
{
	if(triggerR > DEADZONE)
	{
		trigR = triggerR;
	}
	else
	{
		trigR = 0;
	}

	if(triggerL > DEADZONE)
	{
		trigL = triggerL;
	}
	else
	{
		trigL = 0;
	}
}

/*void Drive::increment(float motorLeftInput, float motorRightInput)
{
	if(motorRightInput - driveRight > 1 || motorRightInput - driveRight < -1)
	{
		driveRight += sign(motorRightInput - driveRight) * .1;
	}

	if(motorLeftInput - driveLeft > 1 || motorLeftInput - driveLeft < -1)
	{
		driveLeft += sign(motorLeftInput - driveLeft) * .1;//input variables to smart dashboard printout
	}
}*/

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
/*void Drive::setTurnSpeed(float turn)
{
	if(turn >= DEADZONE || turn <= -DEADZONE)
	{
<<<<<<< HEAD
		turnSpeed = turn * turbo;
		autoTurn = false;

		referenceAngle = navX->GetYaw();
	}
	else if((error360 >= 1 || error360 <= -1) && (error180 >= 1 || error180 <= -1))
	{
		autoTurn = true;
		turnSpeed = 0.3 * leftRight;
	}
	else
	{
		turnSpeed = 0;
		autoTurn = false;
	}
}*/

void Drive::setTurnSpeed(float turn)
{
	if(/*autoTurn == false &&*/ turn >= DEADZONE || turn <= -DEADZONE)
	{
		turnSpeed = turn * turbo;

		autoTurn = false;

		referenceAngle = 0;
		navX->ZeroYaw();
	}
	else if((error360 <= -.5 || error360 >= .5) && (error180 <= -.5 || error180 >= .5))//added the equal signs
	{
		turnSpeed = KP * shortestPath();
	}
	else //if((error360 > -.5 && error360 < .5) || (error180 > -.5 && error180 < .5)) if(gyroValue == referenceAngle || navX->GetYaw() == referenceAngle)
	{
		turnSpeed = 0;
		autoTurn = false;
		navX->ZeroYaw();
		gyroValue = 0;
		referenceAngle = 0;
		//Testing relative turns for Auto Turning 2/6/16
	}
}

/**
 * drive: get desired speed values and assign them to motors
 * @param turn is the turn speed
 * @param fwd is the fwd/backward speed
 *
 */
void Drive::drive(float xAxis, float yAxis, int POV)//make sure POV is on the scale from -180 to 180
{
	gyroValue = navX->GetYaw();

	//edgeCase();
	//setReferenceAngle(POV);

	//error360 = referenceAngle - gyroValue;
	//error180 = referenceAngle - navX->GetYaw();

	shortestPath();

	setForwardSpeed(yAxis);
	setTurnSpeed(xAxis);

	updateLeftMotors(forwardSpeed - turnSpeed - trigL);
	updateRightMotors(forwardSpeed + turnSpeed - trigR);

	//increment(forwardSpeed - turnSpeed, forwardSpeed + turnSpeed);//undo this
}

//this function sets the desired angle from the D-Pad
void Drive::setReferenceAngle(int angle)//make sure angle is on the scale from -180 to 180
{
	if(angle == -1)
	{

	}
	else if(angle > 180)
	{
		referenceAngle = angle - 360;
		autoTurn = true;
	}
	else if(angle <= 180)
	{
		referenceAngle = angle;
		autoTurn = true;
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
		return error180; //leftRight = sign(error180);
	}

	return error360;//leftRight = sign(error360);
}


/************************************************************************/
/*

void Drive::driveMotors(float turn, float fwd)
{
	setForwardSpeed(fwd);
	setTurnSpeed(turn);

	updateLeftMotors(forwardSpeed + turnSpeed);
	updateRightMotors(forwardSpeed - turnSpeed);
}*/


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
 * TODO: actually understand what this means
 */
void Drive::shiftGears(bool shiftStateA)//, bool shiftStateB)
{
	if(shiftStateA == true/* && shiftState == false*/) // low gear
	{
		shifter->Set(DoubleSolenoid::Value::kForward);
		shiftState = true;
		Wait(.1);
	}/*
	else if(shiftStateA == true && shiftState == true)//shiftStateB)
	{
		shifter->Set(DoubleSolenoid::Value::kReverse);
		shiftState = false;
		Wait(.1);
	}*/
}

/**
 * toggleGyro: turns on or off the use of PID
 * @param gyro is a button that toggles the use of PID
 */
void Drive::toggleGyro(bool gyro)
{

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

float Drive::getLeftInput()
{
	return frontLeftDrive->Get();
}
float Drive::getRightInput()
{
	return frontRightDrive->Get();
}

int Drive::sign(float num)
{
	if(num >= 0)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}
