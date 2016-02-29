/*
 * LogFile.h
 *
 *  Created on: Feb 29, 2016
 *      Author: Admin
 */
#ifndef SRC_LOGFILE_LOGFILE_H_
#define SRC_LOGFILE_LOGFILE_H_

#include "Drive/Drive.h"
#include "Intake/Intake.h"
#include "Lift/Lift.h"
#include "Shooter/Shooter.h"

#include "iostream"
#include "fstream"
#include "string"
#include "ctime"

using namespace std;

class LogFile
{
public:
	LogFile();
	~LogFile();

	void printFile();

private:
	ofstream myfile;
	time_t rawtime;
	struct tm * timeinfo;
	char buffer [80];
};

#endif /* SRC_LOGFILE_LOGFILE_H_ */
