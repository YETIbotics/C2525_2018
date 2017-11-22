#ifndef SecondLift_h
#define SecondLift_h

#include <Arduino.h>
#include "a_Robot.h"

class SecondLift
{
public:
	// CONSTRUCTORS
	SecondLift(Robot *p); // Default pin selection.

	void Task();
	void init();

	//Floats
	float LiftSpeed;
	float TriggerAggregate;

	//Bools
	bool HatOpen = false;


private:
	Robot *robot;


};

#endif

