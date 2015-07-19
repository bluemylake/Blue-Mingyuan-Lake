#ifndef _TALKMAN_EVENT_H_
#define _TALKMAN_EVENT_H_
#include "Event.h"
#include "Map.h"
#include "NPCUtil.h"
#include <vector>

//practically execute Event of Talking
class TalkManEvent: public Event
{
public:
    CREATE_FUNC(TalkManEvent);
public:
    void happen();
};
#endif
