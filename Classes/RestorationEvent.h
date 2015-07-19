#ifndef _RESTORATION_EVENT_H_
#define _RESTORATION_EVENT_H_
#include "Event.h"
#include "CombatUnit.h"
#include "GlobalState.h"
#define NUM_ATTALT_INDEX 0
#define RESTHP_FIXED_ID 0
#define INCRXP_FIXED_ID 2

class RestorationEvent: public Event
{
public:
    void happen();
};
#endif
