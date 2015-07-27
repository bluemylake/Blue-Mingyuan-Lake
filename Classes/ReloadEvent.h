#ifndef _RELOAD_EVENT_H_
#define _RELOAD_EVENT_H_
#include "Event.h"

//Reloads all event on the map after a blink of night
class ReloadEvent: public Event
{
public:
    CREATE_FUNC(ReloadEvent);
public:
    void happen();
};
#endif

