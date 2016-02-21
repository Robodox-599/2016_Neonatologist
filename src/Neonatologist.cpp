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
	Intake* intake;
	Joystick* joy;

#if 0
	IMAQdxSession session;
	Image *frame;
	IMAQdxError imaqError;
#endif

	void RobotInit()
	{
		shooter = new Shooter();
		chooser = new SendableChooser();
		intake = new Intake();
		/*chooser->AddDefault(autoNameDefault, (void*)&autoNameDefault);
		chooser->AddObject(autoNameCustom, (void*)&autoNameCustom);
		SmartDashboard::PutData("Auto Modes", chooser);*/

		joy = new Joystick(0);
		drive = new Drive();

#if 0
		frame = imaqCreateImage(IMAQ_IMAGE_RGB, 0);
		imaqError = IMAQdxOpenCamera("cam0", IMAQdxCameraControlModeController, &session);
		if(imaqError != IMAQdxErrorSuccess)
			DriverStation::ReportError("IMAQdxOpenCamera error: " + std::to_string((long)imaqError) + "\n");
		imaqError = IMAQdxConfigureGrab(session);

		if(imaqError != IMAQdxErrorSuccess)
			DriverStation::ReportError("IMAQdxConfigureGrab error: " + std::to_string((long)imaqError) + "\n");
#endif
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
		// shooter
		shooter->motorTest(joy->GetRawAxis(5));
		//shooter->pistonTest(joy->GetRawButton(PISTON_BUTTON), joy->GetRawButton(REVERSE_PISTON));
		/*shooter->shoot(joystick->GetRawButton(SHOOTER_BUTTON), joystick->GetRawButton(SHOOTER_RESET_BUTTON));*/

		// intake
		intake->toggleIntake(joy->GetRawButton(INTAKE_BUTTON), joy->GetRawButton(OUTTAKE_BUTTON));
		intake->pivotIntake(joy->GetRawAxis(INTAKE_PIVOT));

		// drive
		drive->driveMotors(joy->GetRawAxis(X_AXIS_R), joy->GetRawAxis(Y_AXIS_R));
		drive->shiftGears(joy->GetRawButton(TOGGLE_GEARS));

		// print information
		PrintToDashboard();
		//RunCamera();
	}
#if 0
	void RunCamera()
	{
		IMAQdxStartAcquisition(session);
		{
			IMAQdxGrab(session, frame, true, NULL);
			if(imaqError != IMAQdxErrorSuccess)
			{
				DriverStation::ReportError("IMAQdxGrab error: " + std::to_string((long)imaqError) + "\n");
			}
			else
			{
				imaqDrawShapeOnImage(frame, frame, { 10, 10, 100, 100 }, DrawMode::IMAQ_DRAW_VALUE, ShapeMode::IMAQ_SHAPE_OVAL, 0.0f);
				CameraServer::GetInstance()->SetImage(frame);
			}
		}
	}
#endif

	void PrintToDashboard()
	{
		SmartDashboard::PutNumber("Drive forward speed: ", drive->getForwardSpeed());
		SmartDashboard::PutNumber("Drive turn speed: ", drive->getTurnSpeed());
		SmartDashboard::PutNumber("Intake encoder: ", intake->getIntakeEncoderValue());
		SmartDashboard::PutNumber("Drive encoder: ", drive->getCANTalonEncPos());

		if(drive->getShiftState())
			SmartDashboard::PutString("Shift state: ", "A");
		else if(!drive->getShiftState())
			SmartDashboard::PutString("Shift state: ", "B");
		else
			SmartDashboard::PutString("Shift state: ", "error in getting shift state");
	}

};

START_ROBOT_CLASS(Neonatologist);
