#include "a_Robot.h"
#include "a_Controller.h"
#include "a_Drive.h"
#include "SimpleTimer.h"
#include "a_SecondLift.h"
#include "a_Chainbar.h"
#include "a_MoGo.h"
//#include "Adafruit_BNO055.h"
#include "Autonomous.h"
#include <Wire.h>
#define LightSensorPin A6


Robot robot;
Controller controller(&robot.Usb);
Drive drive(&robot);
SecondLift secondLift(&robot);
Chainbar chainbar(&robot);
MoGo moGo(&robot);

SimpleTimer timer;


//Adafruit_BNO055 gyro = Adafruit_BNO055(55);
Autonomous autonomous(&robot, &secondLift, &drive, &moGo, &chainbar);


void setup()
{

	Serial.begin(115200);
	
	while (!Serial); // Wait for serial port to connect - used on Leonardo, Teensy and other boards with built-in USB CDC serial connection

					 //gyroLift in INO 
//	if (!gyro.begin())
	//{
		/* There was a problem detecting the BNO055 ... check your connections */
//		Serial.print("Ooops, no BNO055 detected ... Check your wiring or I2C ADDR!");
	
//	}
	

	//delay(1000);

	//gyro.setExtCrystalUse(true);

	robot.init();
	drive.init();
	secondLift.init();
	moGo.init();
	chainbar.init();
	autonomous.init();
	//cv.init();

	timer.setInterval(20, runRobot);

}

void loop()
{
	robot.TaskUSB();
	timer.run();
}


void runRobot()
{
	/*String readString, funcName;
	int funcVal;

	while (Serial.available()) {
		delay(10);  //delay to allow buffer to fill 
		if (Serial.available() > 0) {
			char c = Serial.read();  //gets one byte from serial buffer
			readString += c; //makes the string readString
		}
	}

	if (readString.length() > 0) {
		Serial.println(readString); //see what was received

									// expect a string like XX #### containing the two servo positions      
		funcName = readString.substring(0, 2); //get the first four characters
		String tmpFuncVal = readString.substring(3, 7); //get the next four characters 

		char carray[tmpFuncVal.length() + 1]; //determine size of the array
		tmpFuncVal.toCharArray(carray, sizeof(carray)); //put readStringinto an array
		funcVal = atof(carray); //convert the array into a float
	
	}
	Serial.flush();
	//Drive
	if (funcName == "DT")
	{
		drive.driveSetPoint += funcVal * 10;
	}
	else if (funcName == "LT")
	{
		robot.LiftY = funcVal;
	}*/
	

	/* Get a new sensor event */
	//sensors_event_t event;
	//gyro.getEvent(&event);

	/* Display the floating point data */

	//Serial.print(" Gyro X: ");
	//Serial.print(event.orientation.x);

	//Serial.print(" Gyro Y: ");
	//Serial.print(event.orientation.y);

	//Serial.print(" Gyro Z: ");
	//Serial.print(event.orientation.z);

	robot.Read();
	MapRobot();

	drive.Task();
	secondLift.Task();
	moGo.Task();
	chainbar.Task();

	controller.Task();

	if(controller.XBoxClick != -1)
		robot.Write();
	//cv.Task();

	autonomous.Task();
	
	Serial.print(" Light Sensor: ");
	Serial.print(analogRead(LightSensorPin));
	

}

void MapRobot()
{
	drive.LeftControllerSpeedY = controller.LeftJoystickY;
	drive.LeftControllerSpeedX = controller.LeftJoystickX;
	drive.RightControllerSpeedY = controller.RightJoystickY;
	drive.RightControllerSpeedX = controller.RightJoystickX;

	moGo.TriggerAggregate = controller.TriggerAggregate;
	moGo.RL1 = controller.LR2Aggregate;
	
	secondLift.X = controller.XClick;
	secondLift.A = controller.APress;
	secondLift.B = controller.BPress;
	secondLift.XBox = controller.BackClick;
	secondLift.CBState = chainbar.CBState;

	chainbar.DPadLeftRight = controller.DPadLeftRightClick;
	chainbar.HatButton = controller.YClick;

	if (controller.XBoxClick == 1)
	{
		autonomous.StartAutonomous(1, millis());
		//drive.DrivePIDEnabled = !drive.DrivePIDEnabled;
		//drive.driveSetPoint = drive.driveCurPos;
	}

	if (controller.StartButton)
	{
		drive.DrivePIDEnabled = false;
		secondLift.PIDEnabled = false;
	}


}
