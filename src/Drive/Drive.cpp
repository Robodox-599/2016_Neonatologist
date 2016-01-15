#include "Drive.h"

Drive::Drive()
{
	frontLeftMotor = new Talon(FRONT_LEFT_MOTOR_CHANNEL);
	frontRightMotor = new Talon(FRONT_RIGHT_MOTOR_CHANNEL);
	backLeftMotor = new Talon(BACK_LEFT_MOTOR_CHANNEL);
	backRightMotor = new Talon(BACK_RIGHT_MOTOR_CHANNEL);

}

Drive::~Drive()
{
	delete frontLeftMotor;
	delete frontRightMotor;
	delete backLeftMotor;
	delete backRightMotor;

	frontLeftMotor = NULL;
	frontRightMotor = NULL;
	backLeftMotor = NULL;
	backRightMotor = NULL;
}
