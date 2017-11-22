#ifndef Robot_h
#define Robot_h

#include <Arduino.h>
#include "Usb.h"
//#include "PololuMaestro.h"
#include "MDD10A.h"
//
//#define maestroSerial Serial1

class Robot
{
public:
	// CONSTRUCTORS
	Robot(); // Default pin selection.


	void TaskUSB();
	void Read();
	void Write();
	void init();
	void ServoInit();


	//MiniMaestro maestro(maestroSerial);

	//Readable/Writeable Items

	//Expect -400 through 400
	float DriveRightSpeed;
	float DriveLeftSpeed;
	float SecondLiftSpeed;

	float ChainbarY;
	float ChainbarX;
	float LiftY;

	float ChainbarHat;
	float LiftHats;

	float MoGoSpeed;

	bool HatsOpen = false;
	
	USB Usb;


private:
	//Controller *controller;
	MDD10A mc;

	int servoMin = 500 * 4;
	int servoNeut = 1500 * 4;
	int servoMax = 2608 * 4;

	float prevDriveRightSpeed;
	float prevDriveLeftSpeed;

};

#endif