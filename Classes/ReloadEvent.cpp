#include "ReloadEvent.h"
#include "GlobalRes.h"
#include "AnimLib.h"
#include "EventManager.h"
#include "TimeUtil.h"
#include "Map.h"

#define BLACK_DELAY_TIME 1.25f

void ReloadEvent::happen()
{
	action();
	rGlobal->map->scheduleOnce(schedule_selector(ReloadEvent::delayedLoad), 0.6f);
}

void ReloadEvent::action()
{
	int opacity=DAYTIME_OPACITY;
	if(sGlobal->isNight) opacity=NIGHTTIME_OPACITY;
	CCSprite* blackBg=CCSprite::create(BLACKBG_IMG_PATH);
	blackBg->setPosition(ccp(blackBg->getContentSize().width / 2, blackBg->getContentSize().height / 2));
	blackBg->setOpacity(0);
	rGlobal->map->getParent()->getParent()->getChildByTag(CONTROLPANELLAYER)->addChild(blackBg);

	CCSequence* blinkOfBlack=CCSequence::create(
			AnimLib::getAction(FADEIN,CCSize()),
			CCDelayTime::create(BLACK_DELAY_TIME),
			AnimLib::getAction(FADEOUT,CCSizeMake(0, 0)), 
			NULL);
	CCSequence* blinkOfNight=CCSequence::create(
			AnimLib::getAction(FADEIN,CCSize()),
			CCDelayTime::create(BLACK_DELAY_TIME),
			AnimLib::getAction(FADEOUT,CCSizeMake(opacity, 0)), 
			NULL);
	blackBg->runAction(blinkOfBlack);
	rGlobal->nightBg->runAction(blinkOfNight);
}

void ReloadEvent::delayedLoad(float dt)
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

	if(!sGlobal->isNight)
	{
		sGlobal->mapState->dTime++;
		eManager->load(mapNo-MAP10,TimeUtil::getWeekDay());
	}
	else 
	{
		sGlobal->mapState->nTime++;
		eManager->loadNight(mapNo-MAP10);
	}
	map->initNPC();
}
