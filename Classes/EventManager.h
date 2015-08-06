#ifndef _EVENT_MANAGER_H_
#define _EVENT_MANAGER_H_
#include "cocos2d.h"
#include "GlobalState.h"
#include "Singleton.hpp"
#include "EventLoader.h"
#include "Emap.h"
#include "ControllerListener.h"
using namespace cocos2d;
//loads the Events in memory
//executes the Events for Hero and ButtonA
class EventManager
{
public:
    void load(int fnmapNo, int weekday);
    ControllerListener* happen(CCPoint coord, int ent);//entrance through hero or buttonA
	ControllerListener* happen(Event* event);
	ControllerListener* next();
	void loadNight(int fnmapNo);
	int isInstant(Event* event);
	void redoEvent(int type);
	void redoAll();
	void release();
    ~EventManager();
public:
    CCArray* events;
    Emap* eStand;
    Emap* eAtrgr;
	Event* onGoing;

	Event* findEventById(int id);
    ControllerListener* listener(int type);
    void loadAllEvents(CCString* fpath);
    void loadEmap();
    void markHappened(Event* event);
};
typedef Singleton<EventManager> sEventManager;
#define eManager sEventManager::instance()
#endif
