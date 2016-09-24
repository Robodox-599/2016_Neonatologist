/*#include "Auto.h"

Autonomous::Autonomous()
{
	//bool toggleSwitch = false;
	drive = new Drive;

	shooter = new Shooter;
	intake = new Intake;

	selector1 = new DigitalInput(1);
	selector8 = new DigitalInput(8);
}

Autonomous::~Autonomous()
{
	selector8 = nullptr;
	selector1 = nullptr;

	delete selector8;
	delete selector1;
}


void Autonomous::autonomousSelect() // TODO: switch on will make the boolean false - need to confirm
{
	if(selector1->Get())
	{
		drive->updateLeftMotors(-0.5); // negative for fwd when facing obstacle
		drive->updateRightMotors(-0.5); // negative for fwd when facing obstacle
		Wait(2.5);
		drive->updateLeftMotors(0);
		drive->updateRightMotors(0);
	}
	else if(selector8->Get())
	{
		drive->updateLeftMotors(0.5); // positive for rev when facing obstacle
		drive->updateRightMotors(0.5); // positive for rev when facing obstacle
		Wait(2.5);
		drive->updateLeftMotors(0);
		drive->updateRightMotors(0);
	}
	else
	{
<<<<<<< HEAD
		drive->setTurnSpeed(0);
		drive->setForwardSpeed(0);
	}

}

void Autonomous::auto4()
{
	drive->navX->ZeroYaw();
	intake->intakeRollerMotor(1);
	if(drive->getCANTalonEncPos() < 150) // move approximate getLidarDistance() so that it could go above the defense
	{
		drive->setForwardSpeed(1);
	}
	else if(sensor->getLidarDistance() < 100 && (drive->navX->GetYaw() > -AUTO_DEADZONE && drive->navX->GetYaw() < AUTO_DEADZONE)) //TODO find correct lidar getLidarDistance()
	{
		drive->setForwardSpeed(1);
	}
	else if(drive->navX->GetYaw() < 52 && sensor->getLidarDistance() == 100)
	{
		drive->setForwardSpeed(0);
		drive->setTurnSpeed(-1);
	}
	else if(drive->navX->GetYaw() < 52.5 && drive->navX->GetYaw() > 51.5 && drive->getCANTalonEncPos() < 100)
	{
		drive->setTurnSpeed(0);
		drive->setForwardSpeed(1);
	}
	else if(drive->getCANTalonEncPos() == 100/*&& if pixy sees high goal)
	{
		drive->setForwardSpeed(0);
		intake->pivotIntake(1);
		shooter->gearPiston->Set(DoubleSolenoid::Value::kForward);
		Wait(1);
		shooter->gearPiston->Set(DoubleSolenoid::Value::kReverse);
	}
	//check gyro value
	//adjust angle using gyro
	//use pixy camera to ensure that we are on target
	//check lidar getLidarDistance()
	//adjust getLidarDistance() using lidar
	//turn using gyro
	//go forward until it goes near the castle (adjust lidar getLidarDistance())
	//double check the angle with the pixy camera
	//shoot the ball
	//yey
}*/
=======
		drive->updateLeftMotors(0);
		drive->updateRightMotors(0);
	}
}
>>>>>>> 59396bf37b2521563125c36375afef0f82caf856
