#include "Macros.h"
#include "Drive/Drive.h"
#include "Intake/Intake.h"
#include "Lift/Lift.h"
#include "Shooter/Shooter.h"

class Neonatologist: public IterativeRobot
{
private:

	LiveWindow *lw = LiveWindow::GetInstance();
	SendableChooser *chooser;
	SmartDashboard* dash;
	/*const std::string autoNameDefault = "Default";
	const std::string autoNameCustom = "My Auto";
	std::string autoSelected;*/
	Drive* drive;
	Shooter* shooter;
	Joystick* joy;

	void RobotInit()
	{
		shooter = new Shooter();
		chooser = new SendableChooser();
		dash = new SmartDashboard();
		/*chooser->AddDefault(autoNameDefault, (void*)&autoNameDefault);
		chooser->AddObject(autoNameCustom, (void*)&autoNameCustom);
		SmartDashboard::PutData("Auto Modes", chooser);*/

		joy = new Joystick(0);
		drive = new Drive();

	}

	void AutonomousInit()
	{

		/*autoSelected = *((std::string*)chooser->GetSelected());
		//std::string autoSelected = SmartDashboard::GetString("Auto Selector", autoNameDefault);
		std::cout << "Auto selected: " << autoSelected << std::endl;

		if(autoSelected == autoNameCustom){
			//Custom Auto goes here
		} else {
			//Default Auto goes here
		}*/
	}

	void AutonomousPeriodic()
	{/*
		if(autoSelected == autoNameCustom){
			//Custom Auto goes here
		} else {
			//Default Auto goes here
		}*/
	}

	void TeleopInit()
	{

	}

	void TeleopPeriodic()
	{
		shooter->motorTest(joy->GetRawAxis(5));
		shooter->pistonTest(joy->GetRawButton(PISTON_BUTTON), joy->GetRawButton(REVERSE_PISTON));
		/*shooter->shoot(joystick->GetRawButton(SHOOTER_BUTTON), joystick->GetRawButton(SHOOTER_RESET_BUTTON));*/

		SmartDashboard::PutNumber("Joystick Y: ", shooter->getMotorSpeed());

		// drive functions
		drive->driveMotors(joy->GetRawAxis(X_AXIS_R), joy->GetRawAxis(Y_AXIS_R));
		drive->shiftGears(joy->GetRawButton(SHIFTER_BUTTON_A), joy->GetRawButton(SHIFTER_BUTTON_B));
		PrintToDashboard();
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

};

START_ROBOT_CLASS(Neonatologist);
