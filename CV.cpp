#include "CV.h"

void CV::init()
{
	pixy.init();
}

void CV::Task()
{
	uint16_t blocks;
	blocks = pixy.getBlocks();

	for (int i = 0; i < blocks; i++)
	{
		Serial.print("Block ");
		Serial.print(i + 1);
		Serial.print(" X: ");
		Serial.print(pixy.blocks[i].x);
		Serial.print(" Y: ");
		Serial.print(pixy.blocks[i].y);
		Serial.print(" Width: ");
		Serial.print(pixy.blocks[i].width);
		Serial.print(" Height: ");
		Serial.println(pixy.blocks[i].height);
	}

}