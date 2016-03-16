#include "Macros.h"
#include "Drive/Drive.h"
#include "Intake/Intake.h"
#include "Lift/Lift.h"
#include "Shooter/Shooter.h"
#include "Sensor/Sensor.h"
#include "AHRS.h"

class Neonatologist: public IterativeRobot
{
private:

	LiveWindow *lw = LiveWindow::GetInstance();

	SmartDashboard* dash;
	/*SendableChooser *chooser;
	 * const std::string autoNameDefault = "Default";
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

	bool autodone;

	int servoPosition;

	void RobotInit()
	{
		drive = new Drive();
		sensor = new Sensor();
		shooter = new Shooter();

		intake = new Intake();
		/*chooser = new SendableChooser();
		 * chooser->AddDefault(autoNameDefault, (void*)&autoNameDefault);
		chooser->AddObject(autoNameCustom, (void*)&autoNameCustom);
		SmartDashboard::PutData("Auto Modes", chooser);*/

		xbox = new Joystick(0);
		atk3 = new Joystick(2);
		servo = new Servo(0);

		disable = false;
		autodone = true;
		servoPosition = 90;

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

		autodone = true;
	}

	void AutonomousPeriodic()
	{
		SmartDashboard::PutBoolean("auto done ", autodone);

		//intake->toggleIntake(true, false);

		if(autodone == true)
		{
			//shooter->shootMotor(true);

			drive->updateLeftMotors(-.8);
			drive->updateRightMotors(-.8);
			Wait(1);
			drive->updateLeftMotors(-1);
			drive->updateRightMotors(-1);
			Wait(1);
			drive->updateLeftMotors(-.5);
			drive->updateRightMotors(-.5);
			Wait(1);
			drive->updateLeftMotors(0);
			drive->updateRightMotors(0);
			autodone = false;
		}
	}

	void TeleopInit()
	{

	}

	void TeleopPeriodic()
	{
		if(xbox->GetRawButton(4))
		{
			drive->turbo = 1;
		}

		else if(xbox->GetRawButton(2))
		{
			drive->turbo = .7;
		}

		//might need to change dont know if you want to continuously update these two functions
		sensor->RunCamera();
		sensor->getDistance();

		// shooter
		shooter->shootMotor(atk3->GetRawButton(SHOOTER_RESET_BUTTON)); // no reset button for now
		shooter->shootPiston(atk3->GetRawButton(SHOOTER_BUTTON), atk3->GetRawButton(SHOOTER_SAFTEY_MANUAL));

		// intake
		intake->toggleIntake(atk3->GetRawButton(INTAKE_BUTTON), atk3->GetRawButton(OUTTAKE_BUTTON));
		intake->pivotIntake(atk3->GetY() * 0.8);

		// drive
		drive->drive(xbox->GetRawAxis(X_AXIS_L), xbox->GetRawAxis(Y_AXIS_L), xbox->GetPOV(AUTO_TURN_BUTTON));
		drive->shiftGears(true);
		drive->toggleGyro(xbox->GetRawButton(GYRO_TOGGLE));

		// print information
		PrintToDashboard();

		sensor->RunCamera();
		//servoControl();

		if(xbox->GetRawButton(7) == 1)
		{
			disable = true;
			while(disable == true)
			{
				drive->updateRightMotors(0);
				drive->updateLeftMotors(0);

				shooter->shootMotor(false);
				shooter->shootPiston(false, false);

				SmartDashboard::PutBoolean("Dead Man Switch", true);

				if(xbox->GetRawButton(8) == 1)
				{
					disable = false;
				}
			}
		}
	}

/* servo is locked
	void servoControl()
	{
		if(atk3->GetRawButton(7))
		{
			servoPosition -= 1;
			servo->SetAngle(servoPosition);
		}
		else if(atk3->GetRawButton(8))
		{
			servoPosition += 1;
			servo->SetAngle(servoPosition);
		}
	}*/

	void PrintToDashboard()
	{
		SmartDashboard::PutNumber("Drive Front Left Input", -(drive->forwardSpeed - drive->turnSpeed));
		SmartDashboard::PutNumber("Drive Back Left Input", -(drive->forwardSpeed - drive->turnSpeed));

		SmartDashboard::PutNumber("Drive Front Right Input", drive->forwardSpeed + drive->turnSpeed);
		SmartDashboard::PutNumber("Drive Back Right Input", drive->forwardSpeed + drive->turnSpeed);

		SmartDashboard::PutNumber("forward speed", drive->forwardSpeed);
		SmartDashboard::PutNumber("turn speed", drive->turnSpeed);

		SmartDashboard::PutNumber("Drive Right", drive->driveRight);
		SmartDashboard::PutNumber("Drive Left", drive->driveLeft);

		SmartDashboard::PutNumber("error 180", drive->error180);
		SmartDashboard::PutNumber("error 360", drive->error360);

		SmartDashboard::PutNumber("Yaw", drive->navX->GetYaw());
		SmartDashboard::PutNumber("Gyro Value", drive->gyroValue);
		SmartDashboard::PutNumber("Reference Angle", drive->referenceAngle);

		SmartDashboard::PutNumber("turbo", drive->turbo);
		SmartDashboard::PutNumber("LeftRight", drive->leftRight);

		SmartDashboard::PutBoolean("Auto Turn", drive->autoTurn);
		SmartDashboard::PutBoolean("Shift State", drive->shiftState);
	}
};

START_ROBOT_CLASS(Neonatologist);
