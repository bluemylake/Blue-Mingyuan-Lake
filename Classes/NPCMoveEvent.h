#ifndef _NPC_MOVE_EVENT_H_
#define _NPC_MOVE_EVENT_H_
#include "Event.h"

//NPC moves to another pos
class NPCMoveEvent: public Event
{
public:
    CREATE_FUNC(NPCMoveEvent);
public:
    void happen();
};
#endif



