#ifndef _DIA_EVENT_H_
#define _DIA_EVENT_H_
#include "Event.h"

//practically execute Event of Talking
class DiaEvent: public Event
{
public:
    CREATE_FUNC(DiaEvent);
public:
    void happen();
};
#endif

