#include "Event.h"

bool Event::init()
{
	return true;
}

void Event::happen()
{
	CCLog("Event IDed: %d happened!",id);
}

Event::~Event()
{
    dialog->release();
	args->release();
	pres->release();
}
