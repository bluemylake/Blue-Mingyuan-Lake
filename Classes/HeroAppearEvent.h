#ifndef _HERO_APPEAR_EVENT_H_
#define _HERO_APPEAR_EVENT_H_
#include "Event.h"

//Hero appear 
class HeroAppearEvent: public Event
{
public:
    CREATE_FUNC(HeroAppearEvent);
public:
    void happen();
};
#endif


