#include "a_Drive.h"

// Constructors ////////////////////////////////////////////////////////////////

Drive::Drive(Robot *p)
{
	robot = p;
}
void Drive::init()
{

}


void Drive::Task()
{

	
	if (LeftControllerSpeedY != 0 || RightControllerSpeedY != 0 || LeftControllerSpeedX != 0 || RightControllerSpeedX != 0)
	{
		robot->DriveRightSpeed = RightControllerSpeedY;
		robot->DriveLeftSpeed = LeftControllerSpeedY;
	}		
	else
	{
		robot->DriveRightSpeed = 0;
		robot->DriveLeftSpeed = 0;
	}

	if (DPad == -2)
	{
		robot->DriveRightSpeed = 100;
		robot->DriveRightSpeed = -100;
	}

}