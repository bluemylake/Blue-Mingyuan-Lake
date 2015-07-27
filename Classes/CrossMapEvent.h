#ifndef _CROSS_MAP_EVENT_H_
#define _CROSS_MAP_EVENT_H_
#include "Event.h"

//re-init resources after map crossing
class CrossMapEvent //: public Event
{
public:
    static void happen();
};
#endif

