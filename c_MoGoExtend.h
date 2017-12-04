#ifndef MoGoExtend_h
#define MoGoExtend_h

#include "a_MoGo.h"

class MoGoExtend
{
public:
	// CONSTRUCTORS
	MoGoExtend(); // Default pin selection.
	
	void Execute();
	void GetSubsystems(MoGo *p);

private:
	//Subsystem
	MoGo *moGo;

};

#endif
