#ifndef _GET_SHADOW_EVENT_H_
#define _GET_SHADOW_EVENT_H_
#include "Event.h"

//Hero gets Shadowing Boyfriend instantly after event
class GetShdwEvent: public Event
{
public:
    CREATE_FUNC(GetShdwEvent);
public:
    void happen();
};
#endif
