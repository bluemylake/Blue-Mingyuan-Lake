#ifndef _BLOODY_EVENT_H_
#define _BLOODY_EVENT_H_
#include "Event.h"
#include "GlobalRes.h"
#include "AppMacros.h"
class BloodyEvent: public Event
{
public:
    void happen();
};

class WateryEvent: public Event
{
public:
    void happen();
};
#endif
