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
	//SmartDashboard* dash;
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
		joy->SetRumble(Joystick::kLeftRumble, .2);
		joy->SetRumble(Joystick::kRightRumble, .2);

		// drive functions
		drive->drive(joy->GetRawAxis(X_AXIS_R), joy->GetRawAxis(Y_AXIS_R), joy->GetPOV(0));
		drive->shiftGears(joy->GetRawButton(SHIFTER_BUTTON_A), joy->GetRawButton(SHIFTER_BUTTON_B));
	}

	void PrintToDashboard()
	{
		SmartDashboard::PutNumber("Drive forward speed: ", drive->getForwardSpeed());
		SmartDashboard::PutNumber("Drive turn speed: ", drive->getTurnSpeed());
		
		if(drive->getShiftState())
			SmartDashboard::PutString("Shift state: ", "A");
		else if(!drive->getShiftState())
			SmartDashboard::PutString("Shift state: ", "B");
		else
			SmartDashboard::PutString("Shift state: ", "error in getting shift state");
	}

	void TestPeriodic()
	{
		lw->Run();
	}
};

START_ROBOT_CLASS(Neonatologist);
