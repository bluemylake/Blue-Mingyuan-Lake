#ifndef _IS_WIN_EVENT_H_
#define _IS_WIN_EVENT_H_
#include "Event.h"
#include "CombatScene.h"

//Decides if is win and sets doneList to undone if lose 
class IsWinEvent: public Event
{
public:
    CREATE_FUNC(IsWinEvent);
public:
    void happen();
};
#endif


