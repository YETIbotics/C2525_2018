#include "a_SecondLift.h"

// Constructors ////////////////////////////////////////////////////////////////

SecondLift::SecondLift(Robot *p)
{
	robot = p;
}
void SecondLift::init()
{
	LiftLimit = 0.5;
}

void SecondLift::Task()
{

	if (A)
		robot->SecondLiftSpeed = 400;
	if (B)
		robot->SecondLiftSpeed = -400 * LiftLimit;

	if (LR1 == 1)
		robot->LiftY = LiftSetPointMoGo;
	else if (LR1 == -1)
		robot->LiftY = LiftSetPointReceiver;
	
}

