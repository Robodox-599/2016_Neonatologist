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

	Shooter* shooter;

	Joystick* joystick;

	void RobotInit()
	{
		shooter = new Shooter();
		chooser = new SendableChooser();
		dash = new SmartDashboard();
		/*chooser->AddDefault(autoNameDefault, (void*)&autoNameDefault);
		chooser->AddObject(autoNameCustom, (void*)&autoNameCustom);
		SmartDashboard::PutData("Auto Modes", chooser);*/

		joystick = new Joystick(JOYSTICK_PORT);
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
		shooter->motorTest(joystick->GetRawAxis(5));
		shooter->pistonTest(joystick->GetRawButton(PISTON_BUTTON), joystick->GetRawButton(REVERSE_PISTON));
		/*shooter->shoot(joystick->GetRawButton(SHOOTER_BUTTON), joystick->GetRawButton(SHOOTER_RESET_BUTTON));*/

		dash->PutNumber("Joystick Y: ", shooter->getMotorSpeed());

	}

	void TestPeriodic()
	{
		lw->Run();
	}
};

START_ROBOT_CLASS(Neonatologist);
