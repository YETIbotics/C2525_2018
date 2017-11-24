#ifndef Chainbar_h
#define Chainbar_h

#include <Arduino.h>
#include "a_Robot.h"

class Chainbar
{
public:
	// CONSTRUCTORS
	Chainbar(Robot *p); // Default pin selection.

	void Task();
	void init();
	
	int DPadLeftRight;

	//Floats
	float ArmPos;

	//Bools
	bool HatOpen = false;

	int HatButton;


private:
	Robot *robot;

	//Set Points

	int ChainbarLeftStandby = 3460;
	int ChainbarLeftGrab = 2500;
	int ChainbarRightStandby = 8250;
	int ChainbarRightGrab = 9000;
	int ChainbarCenter = 5770;
	int ChainbarStandby = 7000;

	int CBState = 0;

	int CBTimer = 0;

	bool CBMove = false;


	void RightPressed();
	void LeftPressed();
	void UpPressed();
	void DownPressed();


};

#endif

