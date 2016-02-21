#include "WPILib.h"

// ~~~~~ joystick
#define JOYSTICK_PORT					(0)
#define X_AXIS_R						(4)
#define Y_AXIS_R						(5)
#define INTAKE_BUTTON					(1)		// A
#define OUTTAKE_BUTTON					(3)		// X
#define INTAKE_PIVOT					(1)
#define TOGGLE_GEARS					(2)		// B
#define LOCK_PIVOT_BUTTON				(0)		// not implemented yet

// ~~~~~ Drive
#define DEADZONE						(.25)
#define GEAR_PISTON_CHANNEL_A			(0)
#define GEAR_PISTON_CHANNEL_B			(1)
#define FRONT_LEFT_MOTOR_PORT			(3)
#define FRONT_RIGHT_MOTOR_PORT			(1)
#define BACK_LEFT_MOTOR_PORT			(4)
#define BACK_RIGHT_MOTOR_PORT			(2)
#define SHIFTER_PORT_A					(2)
#define SHIFTER_PORT_B					(3)

// ~~~~~ Intake
#define INTAKE_ROLLER_MOTOR_CHANNEL		(8)
#define PIVOT_MOTOR_CHANNEL				(0)
#define INTAKE_SPEED					(0.5)
#define PIVOT_SPEED						(2)


// ~~~~~ Shooter
#define SHOOTER_MOTOR_CHANNEL			(5)
#define SHOOTER_BUTTON					(2)
#define SHOOTER_RESET_BUTTON			(1)
#define SHOOTER_ENCODER_CHANNEL_A		(1)
#define SHOOTER_ENCODER_CHANNEL_B		(1)
