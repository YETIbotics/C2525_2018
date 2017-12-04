#include "c_MoGoExtend.h"

MoGoExtend::MoGoExtend()
{
	
}

void MoGoExtend::GetSubsystems(MoGo *p)
{
	moGo = p;
}

void MoGoExtend::Execute()
{
	moGo->Move(255);
}