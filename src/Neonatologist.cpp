#include "Macros.h"
#include "Drive/Drive.h"
#include "Intake/Intake.h"
#include "Lift/Lift.h"
#include "Shooter/Shooter.h"
#include "Auto/Auto.h"

class Neonatologist: public IterativeRobot
{
private:
	Command* autonomousCommand;
	LiveWindow *lw = LiveWindow::GetInstance();
	SendableChooser *chooser;
	const std::string autoNameDefault = "Default";
	const std::string autoNameCustom = "My Auto";
	std::string autoSelected;

	void RobotInit()
	{

	//	chooser->AddDefault("Autonomous One", chooser->(void *shootBoulder()));
	//	chooser->AddObject("Autonomous Two",  chooser->(void* shootBoulder()));
		SmartDashboard::PutData("Auto Modes", chooser);
	}


	/**
	 * This autonomous (along with the chooser code above) shows how to select between different autonomous modes
	 * using the dashboard. The sendable chooser code works with the Java SmartDashboard. If you prefer the LabVIEW
	 * Dashboard, remove all of the chooser code and uncomment the GetString line to get the auto name from the text box
	 * below the Gyro
	 *
	 * You can add additional auto modes by adding additional comparisons to the if-else structure below with additional strings.
	 * If using the SendableChooser make sure to add them to the chooser code above as well.
	 */
	void AutonomousInit()
	{
		autonomousCommand = (Command *) chooser->GetSelected();
		autonomousCommand->Start();

		/*
		autoSelected = *((std::string*)chooser->GetSelected());
		//std::string autoSelected = SmartDashboard::GetString("Auto Selector", autoNameDefault);
		std::cout << "Auto selected: " << autoSelected << std::endl;

		if(autoSelected == autoNameCustom){
			//Custom Auto goes here
		} else {
			//Default Auto goes here
		}
		*/
	}

	void AutonomousPeriodic()
	{
		Scheduler::GetInstance()->Run();
		/*
		if(autoSelected == autoNameCustom){
			//Custom Auto goes here
		} else {
			//Default Auto goes here
		}
		*/
	}

	void TeleopInit()
	{

	}

	void TeleopPeriodic()
	{

	}

	void TestPeriodic()
	{
		lw->Run();
	}
};

START_ROBOT_CLASS(Neonatologist)
