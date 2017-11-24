#ifndef Drive_h
#define Drive_h

#include <Arduino.h>
#include "a_Robot.h"

class Drive
{
public:
	// CONSTRUCTORS
	Drive(Robot *p); // Default pin selection.

	void Task();
	void init();

	//Floats
	float LeftControllerSpeedY;
	float LeftControllerSpeedX;
	float RightControllerSpeedY;
	float RightControllerSpeedX;

	int TriggerAggregate;

	void DriveLeft(float Speed);
	void DriveRight(float Speed);

private:
	Robot *robot;


};

#endif
