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
	if (DPad == -2 || A == 1)
	{
		speed = -255;
	}
	else if (B == 1)
	{
		speed = 255;
	}
	else
	{
		speed = 0;
	}

	robot->MoGoSpeed = speed;

}
