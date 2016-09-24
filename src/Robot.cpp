#include "WPILib.h"
#include "Drive.h"
#include "Shooter.h"
#include "Intake.h"
#include "Auto.h"
#include "Macros.h"

class Robot: public IterativeRobot
{
private:
	LiveWindow *lw = LiveWindow::GetInstance();
	/*SendableChooser *chooser;
	const std::string autoNameDefault = "Default";
	const std::string autoNameCustom = "My Auto";
	std::string autoSelected;*/
	SmartDashboard* dash;
	Drive* drive;
	Shooter* shooter;
	Auto* auton;
	Intake* intake;

	Joystick* xBox;
	Joystick* atk3;

	IMAQdxSession session;
	Image *frame;
	IMAQdxError imaqError;

	//SerialPort *serial;

	char sendValue = {1};
	uint16_t distance;
	char buffer[1] = {0};
	char toSend[1] = {0};

	void RobotInit()
	{
		/*chooser = new SendableChooser();
		chooser->AddDefault(autoNameDefault, (void*)&autoNameDefault);
		chooser->AddObject(autoNameCustom, (void*)&autoNameCustom);
		SmartDashboard::PutData("Auto Modes", chooser);*/

		drive = new Drive();
		shooter = new Shooter();
		auton = new Auto();
		intake = new Intake();

		//serial = new SerialPort(4);

		xBox = new Joystick(0);
		atk3 = new Joystick(1);

		CameraServer::GetInstance()->SetQuality(50);
		//the camera name (ex "cam0") can be found through the roborio web interface
		CameraServer::GetInstance()->StartAutomaticCapture("cam0");

		frame = imaqCreateImage(IMAQ_IMAGE_RGB, 0);
		imaqError = IMAQdxOpenCamera("cam0", IMAQdxCameraControlModeController, &session);

		if(imaqError != IMAQdxErrorSuccess)
			DriverStation::ReportError("IMAQdxOpenCamera error: " + std::to_string((long)imaqError) + "\n");

		imaqError = IMAQdxConfigureGrab(session);

		if(imaqError != IMAQdxErrorSuccess)
			DriverStation::ReportError("IMAQdxConfigureGrab error: " + std::to_string((long)imaqError) + "\n");
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

		auton->autonomousForward();
	}

	void AutonomousPeriodic()
	{
		//comment out whicheverone is not used

		//auton->autonomousBackward();
	}

	void TeleopInit()
	{

	}

	void getDistance()
	{
		/*if (serial->Read(buffer, 2))
		distance = (buffer[0] << 8) | buffer[1];*/
	}

	void TeleopPeriodic()
	{


		drive->drive(xBox->GetRawAxis(X_AXIS_XBOX), xBox->GetRawAxis(Y_AXIS_XBOX));
		drive->shifter(xBox->GetRawButton(SHIFTER_BUTTON));
		shooter->catapultReset(atk3->GetRawButton(CATAPULT_RESET_BUTTON));
		shooter->catapultLaunch(atk3->GetRawButton(CATAPULT_LAUNCH_BUTTON_1), atk3->GetRawButton(CATAPULT_LAUNCH_BUTTON_2));
		intake->toggleIntake(atk3->GetRawButton(INTAKE_BUTTON), atk3->GetRawButton(OUTTAKE_BUTTON));
		//intake->pivotIntake(atk3->GetRawButton(PIVOT_BUTTON));
		//intake->intakeRoller(PIVOT_LOCK_BUTTON);//

		IMAQdxStartAcquisition(session);
		{
			IMAQdxGrab(session, frame, true, NULL);
			if(imaqError != IMAQdxErrorSuccess)
			{
				DriverStation::ReportError("IMAQdxGrab error: " + std::to_string((long)imaqError) + "\n");
			}
			else
			{
				CameraServer::GetInstance()->SetImage(frame);
			}
		}

		getDistance();
		SmartDashboard::PutNumber("to send:", toSend[0]);
		SmartDashboard::PutNumber("Lidar lite distance:", distance);
	}

	void TestPeriodic()
	{
		lw->Run();
	}
};

START_ROBOT_CLASS(Robot)
