#include "a_Robot.h"
#include "a_Controller.h"
#include "a_Drive.h"
#include "SimpleTimer.h"
#include "a_SecondLift.h"
#include "a_Chainbar.h"
#include "a_MoGo.h"

Robot Robot;
Controller Controller(&Robot.Usb);
Drive Drive(&Robot);
SecondLift SecondLift(&Robot);
Chainbar Chainbar(&Robot);
MoGo MoGo(&Robot);

SimpleTimer timer;

void setup()
{

	Robot.init();
	Drive.init();
	SecondLift.init();

	timer.setInterval(1, taskController);

	timer.setInterval(20, runRobot);
}

void loop()
{
	timer.run();
}


void taskController()
{
	Robot.TaskUSB();
}


void runRobot()
{
	Robot.Read();

	Controller.Task();

	MapRobot();

	Drive.Task();
	SecondLift.Task();

	Robot.Write();

}

void MapRobot()
{
	Drive.LeftControllerSpeedY = Controller.LeftJoystickY;
	Drive.LeftControllerSpeedX = Controller.LeftJoystickX;
	Drive.RightControllerSpeedY = Controller.RightJoystickY;
	Drive.RightControllerSpeedX = Controller.RightJoystickX;
	Drive.DPad = Controller.DPadLeftRight;

	MoGo.DPad = Controller.DPadLeftRight;
	MoGo.A = Controller.APress;
	MoGo.B = Controller.BPress;

	SecondLift.TriggerAggregate = Controller.TriggerAggregate;
	SecondLift.HatButton = Controller.XPress;

	Chainbar.DPadLeftRight = Controller.DPadLeftRight;
	Chainbar.HatButton = Controller.XPress;



}
