#ifndef _GET_SUPER_POWER_EVENT_H_
#define _GET_SUPER_POWER_EVENT_H_
#include "Event.h"

//Man acquires all Super Power after the event 
class GetSuPEvent: public Event
{
public:
    CREATE_FUNC(GetSuPEvent);
public:
    void happen();
};
#endif
