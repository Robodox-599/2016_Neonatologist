#ifndef SRC_AUTO_H_
#define SRC_AUTO_H_

#include "WPILib.h"
#include "Drive.h"
#include "Macros.h"

class Auto
{
public:

	Auto();
	~Auto();

	void autonomousForward();
	void autonomousBackward();

private:
	Drive* drive;
};


#endif /* SRC_AUTO_H_ */
