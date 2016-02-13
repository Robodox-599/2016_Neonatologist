#include "Macros.h"
#include "Drive/Drive.h"
#include "Intake/Intake.h"
#include "Lift/Lift.h"
#include "Shooter/Shooter.h"

class Neonatologist: public IterativeRobot
{
private:
	LiveWindow *lw = LiveWindow::GetInstance();
	
	Joystick* joy;
	SmartDashboard* dash;
	Drive* drive;

	void RobotInit()
	{
		joy = new Joystick(0);
		drive = new Drive();
	}

	void AutonomousInit()
	{
		
	}

	void AutonomousPeriodic()
	{

	}

	void TeleopInit()
	{

	}

	void TeleopPeriodic()
	{
		// drive functions
		drive->driveMotors(joy->GetRawAxis(X_AXIS_R), joy->GetRawAxis(Y_AXIS_R));
	}

	void PrintToDashboard()
	{
		dash->PutNumber("Drive forward speed: ", drive->GetForwardSpeed());
		dash->PutNumber("Drive turn speed: ", drive->GetTurnSpeed());
	}

	void TestPeriodic()
	{
		lw->Run();
	}
};

START_ROBOT_CLASS(Neonatologist);
