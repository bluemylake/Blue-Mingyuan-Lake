#include "AppMacros.h"
#include "EventManager.h"

void EventManager::load(int fnmapNo, int weekday)
{
	events=CCArray::create();
	events->retain();
	loadAllEvents(fnmapNo*MAP_SCALER+weekday);
	loadAllEvents(fnmapNo*MAP_SCALER+DAY_MAP_STATIC);
	loadAllEvents(fnmapNo*MAP_SCALER+sGlobal->mapState->dTime);
	loadEmap();
}

ControllerListener* EventManager::happen(CCPoint coord, int ent)
{
	//get eventId
	int eventId=(ent==STAND_TRIG)?eStand->tileAt(coord):eAtrgr->tileAt(coord);
	if(eventId<=NO_EVENT_FLAG)
	    return NULL;

	//get event
	Event* event=findEventById(eventId);
	if(event==NULL)
	{
	    CCLog("Unexpected value in Emap or problem with CCArray* events. ");
	    return NULL;
	}

	//check pres
	for(int i=0;i<(event->nPre);i++)
	{
		CCInteger* intg=(CCInteger*)event->pres->objectAtIndex(i);//pres
		if(!sGlobal->doneList[intg->getValue()])return NULL;
	}

	//check repeat: do not repeat && is done
	if(!event->repeat && sGlobal->doneList[event->id]==true) 
		return NULL;

	return happen(event);
}

ControllerListener* EventManager::happen(Event* event)
{
	//event happen
	Event* curPtr=event;
	ControllerListener* subject=NULL;
	do
	{
		curPtr->happen();
		onGoing=curPtr;
		if(!curPtr->repeat)markHappened(curPtr);
		if(listener(onGoing->type)!=NULL) subject=listener(onGoing->type);
		if(!isInstant(curPtr)) break;

		curPtr=findEventById(curPtr->next);
	}
	while(curPtr!=NULL);

	return subject;
}

ControllerListener* EventManager::next()
{
	Event* nextEvent=findEventById(onGoing->next);
	if(nextEvent==NULL) return NULL;
	return happen(nextEvent);
}

void EventManager::loadNight(int fnmapNo)
{
	events=CCArray::create();
	events->retain();
	loadAllEvents(fnmapNo*MAP_SCALER+NIGHT_MAP_STATIC);
	loadAllEvents(fnmapNo*MAP_SCALER+sGlobal->mapState->nTime);
	loadEmap();
}

void EventManager::release()
{
	delete eStand;
	delete eAtrgr;
	events->release();
	eStand=NULL,eAtrgr=NULL,events=NULL;
}

EventManager::~EventManager()
{
	release();
}




Event* EventManager::findEventById(int id)
{
	for(int i=0;i<(events->count());i++)
	{
	    Event* event=(Event*)events->objectAtIndex(i);
		if(event->id==id)
			return event;
	}
	return NULL;
}

void EventManager::markHappened(Event* event)
{
    sGlobal->doneList[event->id]=true;
    //events->removeObject(event);
}

ControllerListener* EventManager::listener(int type)
{
    switch(type)
    {
	case TALKMAN_EVT:
	    return rGlobal->diawindow;
	case DIALOG_EVT:
	    return rGlobal->diawindow;
	default:return NULL;
    }
    return NULL;
}

void EventManager::loadAllEvents(int fileCode)
{
	CCString* str=CCString::createWithFormat(EVENT_CSV_PATH,fileCode);
	events->addObjectsFromArray(EventLoader::start(str->getCString())); 
}

void EventManager::loadEmap()
{
	eStand=new Emap;eAtrgr=new Emap;
	for(int i=0;i<(events->count());i++)
	{
		Event* event=(Event*)events->objectAtIndex(i);
		if(event->imgNo==STAND_TRIG_IMGNO)//stand
			eStand->takeTile(event->coord,event->id);
		else
			eAtrgr->takeTile(event->coord,event->id);
	}
} 

int EventManager::isInstant(Event* event)
{
	const int nn=2;
	const int notInstant[nn]={ TALKMAN_EVT, DIALOG_EVT };
	for(int i=0;i<nn;i++)
		if(event->type==notInstant[i])
			return FALSE;
	return TRUE;
}
