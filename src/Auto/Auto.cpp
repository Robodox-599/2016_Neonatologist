#include "Auto.h"

Auto::Auto()
{
	intake = new Intake();
	drive = new Drive();
	shooter = new Shooter();

	timer = new Timer();
	timer->Start();
}

Auto::~Auto()
{
	delete timer;
	
	timer = nullptr;
}

void Auto::moveBoulder()
{
	intake->toggleIntake(true);
}

void Auto::driveUnderBar()
{
	drive->drive(1,1);
}

void Auto::shootBoulder()
{
	shooter->shoot(true, false);
}

void Auto::runAuto()
{
	// TODO: figure out length of time for each auto step
}
