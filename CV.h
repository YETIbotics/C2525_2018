#ifndef CV_h
#define CV_h

#include <SPI.h>  
#include "Pixy.h"


class CV
{
public:
	void init();
	void Task();

	bool LeftLinedUp = false;
	bool RightLinedUp = false;

private:
	Pixy pixy;
	
};

#endif

