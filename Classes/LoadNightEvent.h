#ifndef _LOAD_NIGHT_EVENT_H_
#define _LOAD_NIGHT_EVENT_H_
#include "Event.h"
#include "AudioPlayer.h"

//Load night scene and event 
class LoadNightEvent: public Event
{
public:
    CREATE_FUNC(LoadNightEvent);
    void happen();
private:
	void delayedLoad(float dt);
};
#endif


