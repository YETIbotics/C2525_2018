#include "a_Chainbar.h"

// Constructors ////////////////////////////////////////////////////////////////

Chainbar::Chainbar(Robot *p)
{
	robot = p;
}
void Chainbar::init()
{

}

void Chainbar::LeftPressed()
{
	if (!CBMove)
	{
		if (CBState == 0 || CBState == 4 || CBState == 2)
		{
			ArmPos = ChainbarLeftStandby;
			CBState = 1;
		}
		else if (CBState == 3)
		{
			ArmPos = ChainbarCenter;
			CBState = 0;
			//ChainbarY = ChainbarForward(Something)
		}
		else
		{
			ArmPos = ChainbarLeftGrab;
			CBTimer = 400;
			CBMove = true;
		}
	}
	
}

void Chainbar::RightPressed()
{

	if (!CBMove)
	{
		if (CBState == 0 || CBState == 4 || CBState == 1)
		{
			ArmPos = ChainbarRightStandby;
			CBState = 2;
		}
		else if (CBState == 3)
		{
			ArmPos = ChainbarCenter;
			//ChainbarY = ChainbarForward(Something)
		}
		else
		{
			ArmPos = ChainbarRightGrab;
			CBTimer = 400;
			CBMove = true;
		}
	}
}

void Chainbar::Task()
{
	if (CBTimer <= 0)
	{
		CBTimer = 0;
		if (CBMove)
		{
			CBState = 0;
			CBMove = false;
			ArmPos = ChainbarCenter;
		}
	}

	if (DPadLeftRight == 1)
		RightPressed();
	if (DPadLeftRight == -1)
		LeftPressed();

	if (HatButton == 1)
		robot->HatsOpen = !robot->HatsOpen;

	robot->ChainbarX = ArmPos;
}
