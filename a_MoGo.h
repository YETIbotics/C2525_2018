#ifndef Drive_h
#define Drive_h

#include <Arduino.h>
#include "a_Robot.h"

class MoGo
{
public:
	// CONSTRUCTORS
	MoGo(Robot *p); // Default pin selection.

	void Task();
	void init();

	float Speed = 0;

	int DPad;
	int A;
	int B;
private:
	Robot *robot;

};

#endif

