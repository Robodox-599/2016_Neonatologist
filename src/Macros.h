#include "WPILib.h"

// ~~~~~ joystick ~~~~~ Xbox					Value	Button							Status
#define JOYSTICK_PORT							(0)
#define X_AXIS_L								(4)		// Joystick Right X Axis Drive	Done
#define Y_AXIS_L								(1)		// Joystick Left Y Axis Drive	Done changed 3/11/16 lunch


#define LOCK_PIVOT_BUTTON						()		// not implemented yet
#define AUTO_TURN_BUTTON						(0)
#define GYRO_TOGGLE								(3)		// X							Done
#define TOGGLE_GEARS							(4)		// Y							Done
// ~~~~~ joystick ~~~~~ Attack 3
#define OUTTAKE_BUTTON							(3)		// 3							Done
#define INTAKE_PIVOT							()		// Attack 3 y axis 	Done changed 3/11/16 lunch
#define INTAKE_BUTTON							(2)		// LB 							Done changed 3/11/16 lunch
//#define SHOOTER_BUTTON						(1)		// 1 							Done
//#define SHOOTER_RESET_BUTTON					(8)		// 8 							Done
//#define SHOOTER_SAFTEY_MANUAL					(4)		// 4 							Done
//#define SHOOTER_SAFTEY_AUTO					(2)		// 2 							Done

// ~~~~~ Drive
#define DEADZONE								(.20)
#define GEAR_PISTON_CHANNEL_A					(2)
#define GEAR_PISTON_CHANNEL_B					(3)
#define FRONT_LEFT_MOTOR_PORT					(3)
#define FRONT_RIGHT_MOTOR_PORT					(1)
#define BACK_LEFT_MOTOR_PORT					(4)
#define BACK_RIGHT_MOTOR_PORT					(2)
#define SHIFTER_PORT_A							(0)
#define SHIFTER_PORT_B							(1)
#define TRIGGER_DEADZONE						(.1)
// ~~~~~ Drive ~~~~~ PID
#define KP 										(.9)
#define SLOPE_ADJUSTMENT						(162)

// ~~~~~ Intake
#define INTAKE_ROLLER_MOTOR_CHANNEL				(8)
#define PIVOT_MOTOR_CHANNEL						(0)
#define INTAKE_SPEED							(0.65)
#define PIVOT_SPEED								(2)


// ~~~~~ Shooter
#define SHOOTER_MOTOR_CHANNEL					(5)		// has the limit switch
#define SHOOTER_BUTTON							(1)		// 1 Done
#define SHOOTER_RESET_BUTTON					(8)		// 8 Done
#define SHOOTER_SAFTEY_MANUAL					(4)		// 4 Done
#define SHOOTER_SAFTEY_AUTO						()		// 2 Done
#define SHOOTER_ENCODER_CHANNEL_A				(1)
#define SHOOTER_ENCODER_CHANNEL_B				(1)
#define LIMIT_SWITCH_CHANNEL					(8)
