#include "WPILib.h"
#include "AHRS.h"

// joystick values
#define X_AXIS_R						(0)
#define Y_AXIS_R						(1)
#define SHIFTER_BUTTON_A				(2)
#define SHIFTER_BUTTON_B				(1)

// drive variables
#define DEADZONE 	(.15)

//PID
#define SLOPE_ADJUSTMENT				(.9)//TODO: get correct number
#define KP 								(.09)

// TODO: fix later if the front/left things are off? otherwise should be good
#define FRONT_LEFT_MOTOR_PORT			(3)
#define FRONT_RIGHT_MOTOR_PORT			(1)
#define BACK_LEFT_MOTOR_PORT			(4)
#define BACK_RIGHT_MOTOR_PORT			(2)

// TODO: get shifter ports hopefully please salgado and corine liSTEN TO ME
#define SHIFTER_PORT_A					(2)
#define SHIFTER_PORT_B					(3)

