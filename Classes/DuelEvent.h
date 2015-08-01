#ifndef _DUEL_EVENT_H_
#define _DUEL_EVENT_H_
#include "Event.h"
#include "CombatScene.h"

//pushes Combat scene & passes args 
class DuelEvent: public Event
{
public:
    CREATE_FUNC(DuelEvent);
public:
    void happen();
};
#endif

