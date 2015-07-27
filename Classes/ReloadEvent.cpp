#include "ReloadEvent.h"
#include "GlobalRes.h"
#include "Animation.h"
#include "EventManager.h"
#include "TimeUtil.h"

void ReloadEvent::happen()
{
	CCSequence* blinkOfNight=CCSequence::create(
			Animation::getAction(FADEIN,CCSize()),
			CCDelayTime::create(1.5f),
			Animation::getAction(FADEOUT,CCSize()));
	rGlobal->nightBg->runAction(blinkOfNight);

	eManager->release();
	int mapNo=sGlobal->mapState->mapNo;
	eManager->load(mapNo-MAP10,TimeUtil::getWeekDay());
}
