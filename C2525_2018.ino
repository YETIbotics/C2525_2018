#include "a_Robot.h"
#include "a_Controller.h"
#include "a_Drive.h"
#include "SimpleTimer.h"
#include "a_SecondLift.h"
#include "a_Chainbar.h"
#include "a_MoGo.h"

Robot robot;
Controller controller(&robot.Usb);
Drive drive(&robot);
SecondLift secondLift(&robot);
Chainbar chainbar(&robot);
MoGo moGo(&robot);

SimpleTimer timer;

void setup()
{

	robot.init();
	drive.init();
	secondLift.init();

	timer.setInterval(1, taskController);

	timer.setInterval(20, runRobot);
}

void loop()
{
	timer.run();
}


void taskController()
{
	robot.TaskUSB();
}


void runRobot()
{
	robot.Read();

	controller.Task();

	MapRobot();

	drive.Task();
	secondLift.Task();

	robot.Write();

}

void MapRobot()
{
	drive.LeftControllerSpeedY = controller.LeftJoystickY;
	drive.LeftControllerSpeedX = controller.LeftJoystickX;
	drive.RightControllerSpeedY = controller.RightJoystickY;
	drive.RightControllerSpeedX = controller.RightJoystickX;
	drive.DPad = controller.DPadLeftRight;

	moGo.DPad = controller.DPadLeftRight;
	moGo.A = controller.APress;
	moGo.B = controller.BPress;

	secondLift.TriggerAggregate = controller.TriggerAggregate;
	secondLift.HatOpen = controller.XPress;

	chainbar.DPadLeftRight = controller.DPadLeftRight;
	chainbar.HatButton = controller.XPress;
}
