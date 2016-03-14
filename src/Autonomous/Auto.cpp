/*
 * Autonomous.cpp
 *
 *  Created on: Mar 7, 2016
 *      Author: Admin
 */

#include "Auto.h"

Autonomous::Autonomous()
{
	//bool toggleSwitch = false;
	drive = new Drive;
	shooter = new Shooter();

	selector0 = new DigitalInput(0);
	selector1 = new DigitalInput(1);
	selector2 = new DigitalInput(2);

	cocked = false;
}

Autonomous::~Autonomous()
{
	drive = nullptr;
	shooter = nullptr;

	selector0 = nullptr;
	selector1 = nullptr;
	selector2 = nullptr;

	delete drive;
	delete shooter;

	delete selector0;
	delete selector1;
	delete selector2;
}

void Autonomous::autonomousSelect()
{
	if (selector0->Get() == true)
	{
	}
	else if (selector1->Get() == true)
	{
		auto1();
	}
	else if(selector2->Get() == true)
	{
		auto2();
	}
}

void Autonomous::forward()
{
	drive->setForwardSpeed(-0.5);
}

void Autonomous::auto1()
{
	/*if(!cocked)
	{
		shooter->motorTest(true);
		Wait(2);
		shooter->motorTest(false);
		cocked = true;
	}*/

	if(!cocked)
	{
		drive->setForwardSpeed(.5);
		Wait(2.5);
		drive->setForwardSpeed(0);
		cocked = true;
	}

	/*if(drive->backLeftDrive->GetEncPosition() < 1023)//162in forward turn 60 deg up 20in shoot
	{
		drive->setTurnSpeed(0);
		drive->setForwardSpeed(.8);
	}
	else
	{
		drive->setTurnSpeed(0);
		drive->setForwardSpeed(0);
	}*/
}

void Autonomous::auto2()
{
	if(drive->getCANTalonEncPos() < 100)
	{
		drive->setTurnSpeed(0);
		drive->setForwardSpeed(1);
	}
	else if(drive->getCANTalonEncPos() < 150)
	{
		drive->setTurnSpeed(0.5);
	}
	else if(drive->getCANTalonEncPos() > 150)
	{
		drive->setForwardSpeed(1);
	}
	else
	{
		drive->setTurnSpeed(0);
		drive->setForwardSpeed(0);
	}

}
