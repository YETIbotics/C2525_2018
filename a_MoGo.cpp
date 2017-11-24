#include "a_MoGo.h"

// Constructors ////////////////////////////////////////////////////////////////

MoGo::MoGo(Robot *p)
{
	robot = p;
}
void MoGo::init()
{

}

void MoGo::Task()
{
	if (TriggerAggregate >= 100 || RL1 == -1)
	{
		speed = 400;
	}
	else if (TriggerAggregate <= -100 || RL1 == 1)
	{
		speed = -400;
	}
	else
	{
		speed = 0;
	}

	robot->MoGoSpeed = speed;

}
