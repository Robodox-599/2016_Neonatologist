#include "Macros.h"
#include "Drive/Drive.h"
#include "Intake/Intake.h"
#include "Lift/Lift.h"
#include "Shooter/Shooter.h"
#include "Sensor/Sensor.h"

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
	Sensor* sensor;

	Joystick* xbox;
	Joystick* atk3;
	Servo* servo;

	bool disable;

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

		xbox = new Joystick(0);
		atk3 = new Joystick(2);
		drive = new Drive();

		servo = new Servo(0);

		disable = false;

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
		//might need to change dont know if you want to continuously update these two functions
		sensor->RunCamera();
		sensor->getDistance();

		// shooter
		shooter->motorTest(atk3->GetRawButton(SHOOTER_RESET_BUTTON));
		shooter->pistonTest(atk3->GetRawButton(SHOOTER_BUTTON), atk3->GetRawButton(SHOOTER_SAFTEY_MANUAL));
		/*shooter->shoot(xboxstick->GetRawButton(SHOOTER_BUTTON), xboxstick->GetRawButton(SHOOTER_RESET_BUTTON));*/

		// intake
		intake->toggleIntake(xbox->GetRawButton(INTAKE_BUTTON), atk3->GetRawButton(OUTTAKE_BUTTON));
		intake->pivotIntake(xbox->GetRawAxis(INTAKE_PIVOT));

		// drive
		drive->drive(xbox->GetRawAxis(X_AXIS_L), xbox->GetRawAxis(Y_AXIS_L), xbox->GetPOV(AUTO_TURN_BUTTON));
		drive->shiftGears(xbox->GetRawButton(TOGGLE_GEARS));
		drive->toggleGyro(xbox->GetRawButton(GYRO_TOGGLE));

		// print information
		PrintToDashboard();

		//RunCamera();
		servoControl();

		if(xbox->GetRawButton(7) == 1)
		{
			disable = true;
			while(disable == true)
			{
				drive->updateRightMotors(0);
				drive->updateLeftMotors(0);

				shooter->motorTest(false);

				SmartDashboard::PutBoolean("Dead Man Switch", true);

				if(xbox->GetRawButton(8) == 1)
				{
					disable = false;
				}
			}
		}
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

	void servoControl()
	{
		if(atk3->GetX() > 0.1 || atk3->GetX() < -0.1)
		{
			servo->SetAngle(90 *atk3->GetX());
		}
	}

	void PrintToDashboard()
	{
		SmartDashboard::PutNumber("Drive forward speed: ", drive->getForwardSpeed());
		SmartDashboard::PutNumber("Drive turn speed: ", drive->getTurnSpeed());
		SmartDashboard::PutNumber("Intake encoder: ", intake->getIntakeEncoderValue());
		SmartDashboard::PutNumber("Drive encoder: ", drive->getCANTalonEncPos());
		SmartDashboard::PutNumber("Drive encoder2: ", drive->getCANTalonEncVel());

		SmartDashboard::PutNumber("xbox ", xbox->GetRawAxis(5));

		SmartDashboard::PutNumber("shooter encoder: ", shooter->getEncPos());
		//SmartDashboard::PutNumber("encoder ", shooter->shooterEncoder->GetDirection());

		SmartDashboard::PutNumber("to send:", sensor->toSend[0]);
		SmartDashboard::PutNumber("Lidar lite distance:", sensor->distance);

		if(drive->getShiftState())
			SmartDashboard::PutString("Shift state: ", "A");
		else if(!drive->getShiftState())
			SmartDashboard::PutString("Shift state: ", "B");
		else
			SmartDashboard::PutString("Shift state: ", "error in getting shift state");
	}
};

START_ROBOT_CLASS(Neonatologist);
