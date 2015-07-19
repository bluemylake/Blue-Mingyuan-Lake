#ifndef _SCENECH_EVENT_H_
#define _SCENECH_EVENT_H_
#include "Event.h"
#define SCENE_ID_INDEX 0
class SceneChEvent: public Event
{
public:
    void happen();
};
#endif
