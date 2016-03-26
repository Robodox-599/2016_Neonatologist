#include "WPILib.h"
#include "AHRS.h"

// ~~~~~ joystick ~~~~~ Xbox					Value	Button							Status
#define XBOX_JOYSTICK_PORT						(0)
#define ATK3_JOYSTICK_PORT						(2)
#define X_AXIS_L								(4)		// Joystick Left X Axis Drive	Done
#define Y_AXIS_L								(1)		// Joystick Left Y Axis Drive	Done
#define INTAKE_BUTTON							(2)		// atk3 						Done
#define OUTTAKE_BUTTON							(3)		// 3							Done
#define INTAKE_PIVOT							(5)		// Joystick Right Y Axis Manip 	Done
#define LOCK_PIVOT_BUTTON						()		// not implemented yet
#define AUTO_TURN_BUTTON						(0)
#define GYRO_TOGGLE								(3)		// X							Done
#define TOGGLE_GEARS							(4)		// Y							Done

// ~~~~~ joystick ~~~~~ Attack 3
#define SHOOTER_BUTTON							(1)		// 1 							Done
#define SHOOTER_RESET_BUTTON					(8)		// 8 							Done
#define SHOOTER_SAFTEY_MANUAL					(4)		// 4 							Done
#define SHOOTER_SAFTEY_AUTO						(2)		// 2 							Done

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
#define KP 										(0)
#define SLOPE_ADJUSTMENT						(162)

// ~~~~~ Intake
#define INTAKE_ROLLER_MOTOR_CHANNEL				(8)
#define PIVOT_MOTOR_CHANNEL						(0)
#define INTAKE_SPEED							(0.7)
#define PIVOT_SPEED								(2)

// ~~~~~ Shooter
#define SHOOTER_MOTOR_CHANNEL					(5)		// has the limit switch
#define SHOOTER_ENCODER_CHANNEL_A				(1)
#define SHOOTER_ENCODER_CHANNEL_B				(1)

// ~~~~~ Misc
#define AUTO_DEADZONE							(2)
#define PIXY_DEADZONE							(5)

#define PIXY_I2C_DEFAULT_ADDR           0x54

// Communication/misc parameters
#define PIXY_INITIAL_ARRAYSIZE      30
#define PIXY_MAXIMUM_ARRAYSIZE      130
#define PIXY_START_WORD             0xaa55
#define PIXY_START_WORD_CC          0xaa56
#define PIXY_START_WORDX            0x55aa
#define PIXY_MAX_SIGNATURE          7
#define PIXY_DEFAULT_ARGVAL         0xffff

// Pixy x-y position values
#define PIXY_MIN_X                  0L
#define PIXY_MAX_X                  319L
#define PIXY_MIN_Y                  0L
#define PIXY_MAX_Y                  199L

// RC-servo values
#define PIXY_RCS_MIN_POS            0L
#define PIXY_RCS_MAX_POS            1000L
#define PIXY_RCS_CENTER_POS         ((PIXY_RCS_MAX_POS-PIXY_RCS_MIN_POS)/2)

