#include "Auto.h"

Auto::Auto(float speedY, float speedX, bool useShooter, bool useIntake)
{
	intake = new Intake();
	drive = new Drive();
	shooter = new Shooter();

	timer = new Timer();
	timer->Start();

	this->speedY = speedY;
	this->speedX = speedX;
	this->useShooter = useShooter;
	this->useIntake = useIntake;
}

// low goal, turn, shoot
// drive over anything

Auto::~Auto()
{
	delete timer;
	
	timer = nullptr;
}

void Auto::moveBoulder()
{
	intake->toggleIntake(true, true);
}

void Auto::shootBoulder()
{
	shooter->shoot(true, false);
}

void Auto::shootBoulderAuto()
{
	// TODO: figure out length of time for each auto step

	if(timer->Get() > 0 && timer->Get() < 2)
	{
		drive->drive(1.0, 0);	// drive forward
	}
	if(timer->Get() > 2 && timer->Get() < 5)
	{
		drive->drive(0, 0.75);	// turn
	}
	if(timer->Get() > 5 && timer->Get()< 7)
	{
		drive->drive(1.0, 0); 	// drive along turned angle
	}
	if(timer->Get() < 7 && timer->Get() < 10)
	{
		drive->drive(0, 0);
		shootBoulder();	// shoot
	}
}


void Auto::driveForwardAuto()
{
	// TODO: figure out length of time for each auto step

	if(timer->Get() > 0 && timer->Get() < 5)
		drive->drive(1.0, 0);	// drive forward
	if(timer->Get() > 5)
		drive->drive(0,0);		// stop
}
