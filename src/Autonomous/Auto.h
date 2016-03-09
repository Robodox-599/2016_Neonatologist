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

	void auto1();
	void auto2();
	void autonomousSelect();

	Drive* drive;



private:
	DigitalInput* selector0;
	DigitalInput* selector1;
	DigitalInput* selector2;
};


#endif /* SRC_AUTONOMOUS_AUTONOMOUS_H_ */
