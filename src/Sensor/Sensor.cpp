/*
 * Sensor.cpp
 *
 *  Created on: Mar 9, 2016
 *      Author: Admin
 */
#include "Sensor.h"

Sensor::Sensor()
{
	//navX = new AHRS(SPI::Port::kMXP);
	servo = new Servo(0);
	serial = new SerialPort (9600, SerialPort::kMXP);
	gyro = true;
	camera = true;
	lidar = false;
	gyroAngle = 0;

	distance = 0;

	//camera
	frame = imaqCreateImage(IMAQ_IMAGE_RGB, 0);
	imaqError = IMAQdxOpenCamera("cam0", IMAQdxCameraControlModeController, &session);
	if(imaqError != IMAQdxErrorSuccess)
	DriverStation::ReportError("IMAQdxOpenCamera error: " + std::to_string((long)imaqError) + "\n");
	imaqError = IMAQdxConfigureGrab(session);
	if(imaqError != IMAQdxErrorSuccess)
	DriverStation::ReportError("IMAQdxConfigureGrab error: " + std::to_string((long)imaqError) + "\n");
}

Sensor::~Sensor()
{
	servo = nullptr;
	serial = nullptr;

	delete servo;
	delete serial;

}

void Sensor::setDistance()
{
	if (lidar == true)
	{
		if (serial->Read(buffer, 2))
		distance = (buffer[0] << 8) | buffer[1];
	}
}


uint16_t Sensor::getDistance()
{
	return distance;
}

//Camera
void Sensor::RunCamera(){
	if (camera == true)
	{
		IMAQdxStartAcquisition(session);
		{
			IMAQdxGrab(session, frame, true, nullptr);
			if(imaqError != IMAQdxErrorSuccess)
			{
				DriverStation::ReportError("IMAQdxGrab error: " + std::to_string((long)imaqError) + "\n");
			}
			else
			{
				imaqDrawShapeOnImage(frame, frame, { 10, 10, 100, 100 }, DrawMode::IMAQ_DRAW_VALUE, ShapeMode::IMAQ_SHAPE_OVAL, 0.0f);
				CameraServer::GetInstance()->SetImage(frame);
			}
		}
	}
}


