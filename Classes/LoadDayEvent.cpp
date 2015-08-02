#include "LoadDayEvent.h"
#include "GlobalRes.h"
#include "AnimLib.h"
#include "EventManager.h"
#include "TimeUtil.h"
#include "Map.h"
#include "ReloadEvent.h"

void LoadDayEvent::happen()
{
	sGlobal->isNight=false;
	rGlobal->map->scheduleOnce(schedule_selector(LoadDayEvent::delayedLoad), 0.6f);
	ReloadEvent::action();
}

void LoadDayEvent::delayedLoad(float dt)
{
	Map* map=(Map*)rGlobal->map;
	int mapNo=sGlobal->mapState->mapNo;
	for (int i = 0; i < map->NPCs->count(); i++)
	{
		CCNode* npc=(CCNode*)map->NPCs->objectAtIndex(i);
		npc->removeFromParent();
	}
	map->NPCs->release();
	eManager->release();
	eManager->load(mapNo-MAP10,TimeUtil::getWeekDay());
	map->initNPC();
}

