#ifndef _COMBAT_EVENT_H_
#define _COMBAT_EVENT_H_
#include "Event.h"
#include "CombatScene.h"

class CombatEvent: public Event
{
public:
    void happen();
};
#endif
