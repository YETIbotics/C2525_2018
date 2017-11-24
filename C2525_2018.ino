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

	Serial.begin(115200);
	robot.init();
	drive.init();
	secondLift.init();
	moGo.init();
	chainbar.init();

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
	MapRobot();

	drive.Task();
	secondLift.Task();
	moGo.Task();
	chainbar.Task();

	controller.Task();

	robot.Write();

}

void MapRobot()
{
	drive.LeftControllerSpeedY = controller.LeftJoystickY;
	drive.LeftControllerSpeedX = controller.LeftJoystickX;
	drive.RightControllerSpeedY = controller.RightJoystickY;
	drive.RightControllerSpeedX = controller.RightJoystickX;
	drive.TriggerAggregate = controller.TriggerAggregate;

	moGo.TriggerAggregate = controller.TriggerAggregate;
	moGo.RL1 = controller.LR2Aggregate;
	
	secondLift.HatOpen = controller.XClick;
	secondLift.LR1 = controller.LR2Aggregate;
	secondLift.A = controller.APress;
	secondLift.B = controller.BPress;

	chainbar.DPadLeftRight = controller.DPadLeftRightClick;
	chainbar.HatButton = controller.XClick;
}