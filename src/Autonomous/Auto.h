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
	void auto2(); // goes straight backward
	void auto3(); // goes straight then turn
	void auto4(); // low-bar to high-goal (shoot)
	void autonomousSelect();

	DigitalInput* selector0;
	DigitalInput* selector1;
	DigitalInput* selector2;
	DigitalInput* selector3;
	DigitalInput* selector4;

private:
	Drive* drive;
	Sensor* sensor;
	Shooter* shooter;
	Intake* intake;
};

#endif /* SRC_AUTONOMOUS_AUTONOMOUS_H_ */