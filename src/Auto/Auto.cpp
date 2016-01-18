#include "Auto.h"

Auto::Auto()
{
	timer = new Timer();
	timer->Start();
}

Auto::~Auto()
{
	delete timer;
	
	timer = nullptr;
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
