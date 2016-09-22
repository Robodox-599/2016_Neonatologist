/*#include "Auto.h"

Autonomous::Autonomous()
{
	//bool toggleSwitch = false;
	drive = new Drive;
	sensor = new Sensor;
	shooter = new Shooter;
	intake = new Intake;
	selector0 = new DigitalInput(0);
	selector1 = new DigitalInput(1);
	selector2 = new DigitalInput(2);
	selector3 = new DigitalInput(3);
	selector4 = new DigitalInput(4);
}

Autonomous::~Autonomous()
{
	selector0 = nullptr;
	selector1 = nullptr;
	selector2 = nullptr;
	selector3 = nullptr;
	selector4 = nullptr;

	delete selector0;
	delete selector1;
	delete selector2;
	delete selector3;
	delete selector4;
}

void Autonomous::autonomousSelect() // TODO: switch on will make the boolean false - need to confirm
{
	if (!selector0->Get())
	{
	}
	else if (!selector1->Get())
	{
		auto1();
	}
	else if(!selector2->Get())
	{
		auto2();
	}
	else if(!selector3->Get())
	{
		auto3();
	}
	else if(!selector4->Get())
	{
		auto4();
	}
}

void Autonomous::auto1()
{
	if(drive->getCANTalonEncPos() < 100)
	{
		drive->setForwardSpeed(1);
	}
	else
	{
		drive->setTurnSpeed(0);
		drive->setForwardSpeed(0);
	}
}

void Autonomous::auto2()
{
	if(drive->getCANTalonEncPos() < -100)
	{
		drive->setForwardSpeed(-1);
	}
	else
	{
		drive->setTurnSpeed(0);
		drive->setForwardSpeed(0);
	}
}

void Autonomous::auto3()
{
	if(drive->backLeftDrive->GetEncPosition() < 100)
	{
		drive->setTurnSpeed(1);
		drive->setForwardSpeed(1);
	}
	else if(drive->backLeftDrive->GetEncPosition() < 150)
	{
		drive->setTurnSpeed(0.5);
		drive->setForwardSpeed(1);
	}
	else
	{
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
