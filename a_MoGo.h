#ifndef MoGo_h
#define MoGo_h

#include <Arduino.h>
#include "a_Robot.h"

class MoGo
{
public:
	// CONSTRUCTORS
	MoGo(Robot *p); // Default pin selection.

	void Task();
	void init();

	float speed = 0;

	int TriggerAggregate;
	int RL1;

private:
	Robot *robot;

};

#endif

