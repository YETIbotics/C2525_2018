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

	if (TriggerAggregate <= -100)
	{
		robot->DriveRightSpeed = map(-100, 0, -255, 0, -400);
		robot->DriveLeftSpeed = map(-100, 0, -255, 0, -400);
	}
	else if (TriggerAggregate >= 100)
	{
		robot->DriveRightSpeed = map(100, 0, 255, 0, 400);
		robot->DriveLeftSpeed = map(100, 0, 255, 0, 400);
	}

}