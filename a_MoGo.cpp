#include "a_MoGo.h"

// Constructors ////////////////////////////////////////////////////////////////

MoGo::MoGo(Robot *p)
{
	robot = p;
}
void MoGo::init()
{

}

void MoGo::Move(float Speed)
{
	robot->MoGoSpeed = Speed;
}

void MoGo::Task()
{
	if (TriggerAggregate >= 100 || RL1 == -1)
	{
		Move(400);
	}
	else if (TriggerAggregate <= -100 || RL1 == 1)
	{
		Move(-400);
	}
	else
	{
		Move(0);
	}

}
