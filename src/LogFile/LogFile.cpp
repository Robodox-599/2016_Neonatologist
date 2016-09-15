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
}

LogFile::~LogFile()
{

}

void LogFile::printFile()
{
	myfile.open("example.php");
	myfile << "LOG FILE" << endl;
	myfile << "DATE: " + strftime (buffer,80,"%F",timeinfo)<< endl;
	myfile << "TIME: " + strftime (buffer,80,"%Hh_%Mm_%Ss",timeinfo)<< endl;
	myfile << "-------------------------------------------------------------" << endl;
	myfile << "GYRO: ";
	myfile.close();
}
