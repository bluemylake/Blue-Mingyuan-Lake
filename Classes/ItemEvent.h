#ifndef _ITEM_EVENT_H_
#define _ITEM_EVENT_H_
#include "Event.h"
#include "GlobalRes.h"
#define ITEM_ID_INDEX 0
#define ACQUIRE_ITEM_DIA "Congratulations! You have found ...! "
class ItemEvent: public Event
{
public:
    void happen();
};
#endif
