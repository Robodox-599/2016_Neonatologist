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

	// camera 1
	IMAQdxSession session;
	Image *frame;
	IMAQdxError imaqError;

	void RobotInit()
	{

	//	chooser->AddDefault("Autonomous One", chooser->(void *shootBoulder()));
	//	chooser->AddObject("Autonomous Two",  chooser->(void* shootBoulder()));
		SmartDashboard::PutData("Auto Modes", chooser);

		frame = imaqCreateImage(IMAQ_IMAGE_RGB, 0);
		imaqError = IMAQdxOpenCamera("cam0", IMAQdxCameraControlModeController, &session);
		if(imaqError != IMAQdxErrorSuccess)
			DriverStation::ReportError("IMAQdxOpenCamera error: " + std::to_string((long)imaqError) + "\n");
		imaqError = IMAQdxConfigureGrab(session);

		if(imaqError != IMAQdxErrorSuccess)
			DriverStation::ReportError("IMAQdxConfigureGrab error: " + std::to_string((long)imaqError) + "\n");
	}

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
		// camera 1
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

};

START_ROBOT_CLASS(Neonatologist);
