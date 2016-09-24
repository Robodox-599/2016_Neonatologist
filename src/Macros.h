#ifndef SRC_MACROS_H_
#define SRC_MACROS_H_

#include "WPILib.h"

// Xbox Joystick

#define X_AXIS_XBOX							(0)
#define Y_AXIS_XBOX							(1)

// Attack 3 Joystick

#define CATAPULT_RESET_BUTTON				(8)
#define CATAPULT_LAUNCH_BUTTON_1			(1)
#define CATAPULT_LAUNCH_BUTTON_2			(4)
#define INTAKE_BUTTON						(2)
#define OUTTAKE_BUTTON						(3)

//Drive

#define DEADZONE							(0.3)
#define FRONT_LEFT_MOTOR_PORT				(0)
#define	FRONT_RIGHT_MOTOR_PORT				(2)
#define BACK_LEFT_MOTOR_PORT				(1)
#define BACK_RIGHT_MOTOR_PORT				(3)
#define SHIFTER_BUTTON						(1)

//Intake

#define INTAKE_ROLLER_PORT					(5)
//#define PIVOT_PISTON_PORT_A					(1)
//#define PIVOT_PISTON_PORT_B					(6)

#define TOGGLE_INTAKE_BUTTON				(6)		//not an accurate val
#define TOGGLE_OUTTAKE_BUTTON				(7)		//not an accurate val
#define PIVOT_LOCK_BUTTON					(3)		//not an accurate val
#define PIVOT_BUTTON						(2)	//not an accurate val

//Shooter

#define SHOOTER_MOTOR_PORT					(4)
#define GEAR_PISTON_PORT_A					(3)
#define GEAR_PISTON_PORT_B					(4)
#define LIMIT_SWTICH_PORT					(0)

//Autonomous

#define AUTONOMOUS_TIME						(5)		//amount of time autonomous lasts
#define AUTONOMOUS_MOTOR_VAL				(0.5) 	//power input of the motor

#endif /* SRC_MACROS_H_ */
