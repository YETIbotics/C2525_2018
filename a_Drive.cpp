#include "a_Drive.h"

// Constructors ////////////////////////////////////////////////////////////////

Drive::Drive(Robot *p)
{
	robot = p;
}
void Drive::init()
{

}

void Drive::DriveLeft(float Speed)
{
	robot->DriveLeftSpeed = Speed;
}

void Drive::DriveRight(float Speed)
{
	robot->DriveRightSpeed = Speed;
}


void Drive::Task()
{


	if (LeftControllerSpeedY != 0 || RightControllerSpeedY != 0 || LeftControllerSpeedX != 0 || RightControllerSpeedX != 0)
	{
		DriveRight(RightControllerSpeedY);
		DriveLeft(LeftControllerSpeedY);
	}
	else
	{
		DriveRight(0);
		DriveLeft(0);
	}

	if (TriggerAggregate <= -100)
	{
		DriveRight(map(-100, 0, -255, 0, -400));
		DriveLeft(map(-100, 0, -255, 0, -400));
	}
	else if (TriggerAggregate >= 100)
	{
		DriveRight(map(100, 0, 255, 0, 400));
		DriveLeft(map(100, 0, 255, 0, 400));
	}

}