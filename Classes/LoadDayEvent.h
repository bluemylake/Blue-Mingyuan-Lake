#ifndef _LOAD_DAY_EVENT_H_
#define _LOAD_DAY_EVENT_H_
#include "Event.h"

//Load day scene and event 
class LoadDayEvent: public Event
{
public:
    CREATE_FUNC(LoadDayEvent);
    void happen();
private:
	void delayedLoad(float dt);
};
#endif
