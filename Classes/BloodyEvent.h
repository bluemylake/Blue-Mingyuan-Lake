#ifndef _BLOODY_EVENT_H_
#define _BLOODY_EVENT_H_
#include "Event.h"
#include "GlobalRes.h"
#include "AppMacros.h"
class BloodyEvent: public Event
{
public:
	CREATE_FUNC(BloodyEvent);
    void happen();
};

class WateryEvent: public Event
{
public:
	CREATE_FUNC(WateryEvent);
    void happen();
};
#endif
