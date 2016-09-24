#include "Macros.h"
#include "Drive/Drive.h"
#include "Intake/Intake.h"
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

	Joystick* xbox;
	Joystick* atk3;
	bool disable;

	void RobotInit()
	{
		shooter = new Shooter();
		chooser = new SendableChooser();
		intake = new Intake();
		/*chooser->AddDefault(autoNameDefault, (void*)&autoNameDefault);
		chooser->AddObject(autoNameCustom, (void*)&autoNameCustom);
		SmartDashboard::PutData("Auto Modes", chooser);*/

		xbox = new Joystick(XBOX_JOYSTICK_PORT);
		atk3 = new Joystick(ATK3_JOYSTICK_PORT);
		drive = new Drive();

		disable = false;
		//CameraServer::GetInstance()->SetQuality(50);
		//the camera name (ex "cam0") can be found through the roborio web interface
		//CameraServer::GetInstance()->StartAutomaticCapture("cam0");
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
		drive->navX->ZeroYaw();
		drive->referenceAngle = drive->navX->GetYaw();
		drive->gyroValue = drive->navX->GetYaw();
		drive->autoTurn = false;
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
		SmartDashboard::PutBoolean("Limit Switch: ", shooter->getLimit());
		//SmartDashboard::PutNumber("encoder ", shooter->shooterEncoder->GetDirection());

		SmartDashboard::PutNumber("Gyro Value:", (double)drive->navX->GetYaw());
		SmartDashboard::PutNumber("Reference Angle", drive->referenceAngle);

		if(drive->getShiftState())
			SmartDashboard::PutString("Shift state: ", "A");
		else if(!drive->getShiftState())
			SmartDashboard::PutString("Shift state: ", "B");
		else
			SmartDashboard::PutString("Shift state: ", "error in getting shift state");
	}

	void TeleopPeriodic()
	{
		// shooter
		shooter->catapultReset(atk3->GetRawButton(SHOOTER_RESET_BUTTON));//SHOOTER_RESET_BUTTON));
		shooter->catapultLaunch(atk3->GetRawButton(SHOOTER_BUTTON), atk3->GetRawButton(SHOOTER_SAFTEY_MANUAL));

		// intake
		intake->toggleIntake(atk3->GetRawButton(INTAKE_BUTTON), atk3->GetRawButton(OUTTAKE_BUTTON));
		//intake->pivotIntake(atk3->GetY());

		// drive
		drive->drive(xbox->GetRawAxis(X_AXIS_R), xbox->GetRawAxis(Y_AXIS_L), xbox->GetPOV(AUTO_TURN_BUTTON));
		drive->shiftGears(xbox->GetRawButton(TOGGLE_GEARS));
		//drive->toggleGyro(xbox->GetRawButton(GYRO_TOGGLE));

		//drive->setTriggerSpeed(xbox->GetRawAxis(3), xbox->GetRawAxis(2));

		// print informatioedfzsw n
		PrintToDashboard();

		if(xbox->GetRawButton(7) == 1)
		{
			disable = true;
			while(disable == true)
			{
				drive->updateRightMotors(0);
				drive->updateLeftMotors(0);

				shooter->catapultReset(false);

				SmartDashboard::PutBoolean("Dead Man Switch", true);

				if(xbox->GetRawButton(8) == 1)
				{
					disable = false;
				}
			}
		}
	}
};

START_ROBOT_CLASS(Neonatologist);
