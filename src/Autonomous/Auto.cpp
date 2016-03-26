#include "Auto.h"

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
		drive->updateLeftMotors(0);
		drive->updateRightMotors(0);
	}
}
