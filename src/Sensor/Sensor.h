/*
 * Sensor.h
 *
 *  Created on: Mar 9, 2016
 *      Author: Admin
 */

#ifndef SRC_SENSOR_SENSOR_H_
#define SRC_SENSOR_SENSOR_H_

#include "WPILib.h"
#include "AHRS.h"
class Sensor
{
public:
	Sensor();
	~Sensor();

	void setLidarDistance();
	void RunCamera();
	uint16_t getLidarDistance();

	char toSend[1] = {0};

private:
	Servo *servo;

	IMAQdxSession session;
	Image *frame;
	IMAQdxError imaqError;

	bool gyro;
	bool camera;
	bool lidar;

	float gyroAngle;

	SerialPort *serial;

	char buffer[1] = {0};
	uint16_t distance;

};

#endif /* SRC_SENSOR_SENSOR_H_ */
