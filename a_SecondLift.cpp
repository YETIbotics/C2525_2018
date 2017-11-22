#include "a_SecondLift.h"

// Constructors ////////////////////////////////////////////////////////////////

SecondLift::SecondLift(Robot *p)
{
	robot = p;
}
void SecondLift::init()
{

}


void SecondLift::Task()
{

	if (TriggerAggregate != 0)
		robot->SecondLiftSpeed = TriggerAggregate;
	else
		robot->SecondLiftSpeed = 0;
}

}