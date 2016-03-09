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
	selector0 = new DigitalInput(0);
	selector1 = new DigitalInput(1);
	selector2 = new DigitalInput(2);
}

Autonomous::~Autonomous()
{
	selector0 = nullptr;
	selector1 = nullptr;
	selector2 = nullptr;

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

void Autonomous::auto1()
{
	if(drive->backLeftDrive->GetEncPosition() < 100)
	{
		drive->setTurnSpeed(1);
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
