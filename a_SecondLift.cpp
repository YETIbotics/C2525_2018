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

void SecondLift::Rotate(int SetPoint)
{
	robot->LiftY = SetPoint;
}

void SecondLift::Lift(float Speed)
{
	robot->SecondLiftSpeed = Speed;
}

void SecondLift::Task()
{

	if (A)
		Lift(400);
	if (B)
		Lift(-400 * LiftLimit);

	if (LR1 == 1)
		Rotate(LiftSetPointMoGo);
	else if (LR1 == -1)
		Rotate(LiftSetPointReceiver);
	
}

