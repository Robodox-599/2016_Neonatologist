#include "Auto.h"

Auto::Auto()
{
	intake = new Intake();
	drive = new Drive();
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
	
}

void Auto::runAuto()
{

}
