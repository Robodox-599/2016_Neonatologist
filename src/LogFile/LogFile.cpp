/*
 * LogFile.cpp
 *
 *  Created on: Feb 29, 2016
 *      Author: Admin
 */
#include "LogFile.h"

LogFile::LogFile()
{
	ofstream myfile(strftime (buffer,80,"%a %Hh_%Mm_%Ss",timeinfo) + ".txt", ios::in);
	time (&rawtime);
	timeinfo = localtime (&rawtime);

	driveLF = new Drive();
	intakeLF = new Intake();
	liftLF = new Lift();
	shooterLF = new Shooter();

	rightDriveVel = "false";
	leftDriveVel = "false";

	intakeVel = "false";

}

LogFile::~LogFile()
{
	driveLF = NULL;
	intakeLF = NULL;
	liftLF = NULL;
	shooterLF = NULL;

	delete driveLF;
	delete intakeLF;
	delete liftLF;
	delete shooterLF;
}

void LogFile::printFile()
{
	myfile.open("example.txt");
	myfile << "LOG FILE" << endl;
	myfile << "DATE: " + strftime (buffer,80,"%F",timeinfo)<< endl;
	myfile << "TIME: " + strftime (buffer,80,"%Hh_%Mm_%Ss",timeinfo)<< endl;
	myfile << "-------------------------------------------------------------Drive" << endl;
	myfile << "Right Drive:			" + to_string(/*driveLF->getCANTalonEncVel(driveLF->backRightDrive)*/12) + 	"		" + rightDriveVel << endl;
	myfile << "Left Drive: 			" + to_string(16/*driveLF->getCANTalonEncVel(driveLF->backLeftDrive)*/) + 	"		" + leftDriveVel << endl;
	myfile << "Shift State:			koff" /*driveLF->shifter->Get()*/ << endl;
	myfile << "-------------------------------------------------------------Intake" << endl;
	myfile << "Intake Pivot: 	" + to_string(/*intakeLF->getIntakeEncoderVel()*/36) + 	"		" + intakeVel << endl;
	myfile.close();
}

void LogFile::setStatus()
{
	driveLF->backRightDrive->Set(.1);
	Wait(0.1);
	if(driveLF->getCANTalonEncVel(driveLF->backRightDrive) > 0)
	{
		rightDriveVel = "true";
	}
	driveLF->backRightDrive->Set(0);

	driveLF->backLeftDrive->Set(.1);
	Wait(0.1);
	if(driveLF->getCANTalonEncVel(driveLF->backLeftDrive) > 0)
	{
		leftDriveVel = "true";
	}
	driveLF->backLeftDrive->Set(0);

	intakeLF->pivotMotor->Set(0.1);
	Wait(0.1);
	if(intakeLF->getIntakeEncoderVel() > 0)
	{
		intakeVel = "true";
	}
	intakeLF->pivotMotor->Set(0);

	printFile();
}
