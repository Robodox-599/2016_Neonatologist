/*
 * Autonomous.h
 *
 *  Created on: Mar 7, 2016
 *      Author: Admin
 */

#ifndef SRC_AUTONOMOUS_AUTONOMOUS_H_
#define SRC_AUTONOMOUS_AUTONOMOUS_H_

#include "Drive/Drive.h"
#include "DigitalInput.h"

class Autonomous
{
public:

	Autonomous();
	~Autonomous();

	//bool toggleSwitch;

	void auto1(); // goes straight until certain encoder value
	void auto2(); // goes straight then turn
	void auto3();
	void autonomousSelect();

	Drive* drive;
	Sensor* sensor;
	Shooter* shooter;
	Intake* intake;

	DigitalInput* selector0;
	DigitalInput* selector1;
	DigitalInput* selector2;

private:
};


#endif /* SRC_AUTONOMOUS_AUTONOMOUS_H_ */
