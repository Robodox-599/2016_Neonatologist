#include "Macros.h"
#include "Drive/Drive.h"
#include "Intake/Intake.h"
#include "Lift/Lift.h"
#include "Shooter/Shooter.h"
#include "Sensor/Sensor.h"
#include "Autonomous/Auto.h"

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
	Autonomous* automode;

	Joystick* xbox;
	Joystick* atk3;
	Servo* servo;

	bool disable;

	void RobotInit()
	{
		sensor = new Sensor();
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

		automode = new Autonomous();

		disable = false;
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
		SmartDashboard::PutBoolean("Auto Selector Position 1:", automode->selector0->Get());
		SmartDashboard::PutBoolean("Auto Selector Position 2:", automode->selector1->Get());
		SmartDashboard::PutBoolean("Auto Selector Position 3:", automode->selector2->Get());
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
		shooter->catapultReset(atk3->GetRawButton(SHOOTER_RESET_BUTTON));//SHOOTER_RESET_BUTTON));
		shooter->catapultLaunch(atk3->GetRawButton(SHOOTER_BUTTON), atk3->GetRawButton(SHOOTER_SAFTEY_MANUAL));
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

				shooter->catapultReset(false);

				SmartDashboard::PutBoolean("Dead Man Switch", true);

				if(xbox->GetRawButton(8) == 1)
				{
					disable = false;
				}
			}
		}
	}

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
		SmartDashboard::PutBoolean("Limit Switch: ", shooter->getLimit());
		//SmartDashboard::PutNumber("encoder ", shooter->shooterEncoder->GetDirection());

		SmartDashboard::PutNumber("to send:", sensor->toSend[0]);
		SmartDashboard::PutNumber("Lidar lite distance:", sensor->distance);
		SmartDashboard::PutNumber("Gyro Value:", drive->navX->GetYaw());
		SmartDashboard::PutNumber("Reference Angle", drive->referenceAngle);

		if(drive->getShiftState())
			SmartDashboard::PutString("Shift state: ", "A");
		else if(!drive->getShiftState())
			SmartDashboard::PutString("Shift state: ", "B");
		else
			SmartDashboard::PutString("Shift state: ", "error in getting shift state");
	}
};

START_ROBOT_CLASS(Neonatologist);