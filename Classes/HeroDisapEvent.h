#ifndef _HERO_DISAPPEAR_EVENT_H_
#define _HERO_DISAPPEAR_EVENT_H_
#include "Event.h"

//Hero disppear
class HeroDisapEvent: public Event
{
public:
    CREATE_FUNC(HeroDisapEvent);
public:
    void happen();
};
#endif

