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
			CBTimer = 25;
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
			CBTimer = 25;
			CBMove = true;
		}
	}
}

void Chainbar::UpPressed()
{
	/*Grab from front*/
}

void Chainbar::DownPressed()
{
	CBState = 4;
	ArmPos = ChainbarStandby;
}

void Chainbar::Task()
{
	//CBState 0 = Neutral, 1 = LeftStandby, 2 = RightStandby, 3 = FrontStandby, 4 = Standby

	if (DPadLeftRight == 1)
		RightPressed();
	if (DPadLeftRight == -1)
		LeftPressed();
	if (DPadLeftRight == 2)
		UpPressed();
	if (DPadLeftRight == -2)
		DownPressed();


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

	

	
	if (HatButton == 1)
		robot->OpenHats();

	robot->ChainbarX = ArmPos;
	Serial.print("CBState: ");
	Serial.println(CBState);
	Serial.print("Controller: ");
	Serial.println(DPadLeftRight);
	Serial.print("CBTimer: ");
	Serial.println(CBTimer);
	Serial.print("CBMove");
	Serial.println(CBMove);


	CBTimer--;
}
