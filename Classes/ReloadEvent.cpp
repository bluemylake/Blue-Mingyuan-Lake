#include "ReloadEvent.h"
#include "GlobalRes.h"
#include "Animation.h"
#include "EventManager.h"
#include "TimeUtil.h"
#include "Map.h"

void ReloadEvent::happen()
{
	CCSequence* blinkOfNight=CCSequence::create(
			Animation::getAction(FADEIN,CCSize()),
			CCDelayTime::create(1.5f),
			Animation::getAction(FADEOUT,CCSize()),
			NULL);
	rGlobal->nightBg->runAction(blinkOfNight);

	Map* map=(Map*)rGlobal->map;
	for (int i = 0; i < map->NPCs->count(); i++)
	{
		CCNode* npc=(CCNode*)map->NPCs->objectAtIndex(i);
		npc->removeFromParent();
	}
	map->NPCs->release();
	sGlobal->mapState->sTime++;
	eManager->release();
	int mapNo=sGlobal->mapState->mapNo;
	eManager->load(mapNo-MAP10,TimeUtil::getWeekDay());
	map->initNPC();
}
