#include "Auto.h"

Auto::Auto()
{
	intake = new Intake();
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

}

void Auto::shootBoulder()
{

}

void Auto::runAuto()
{

}
