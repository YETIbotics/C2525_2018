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

	int LR1;
	int A;
	int B;

	//Bools
	bool HatOpen = false;


private:
	Robot *robot;

	int LiftSetPointReceiver = 10424;
	int LiftSetPointMoGo = 6000;

	float LiftLimit;

};

#endif

