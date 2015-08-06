#include "InitUtil.h"
#include "GlobalState.h"
#include "GlobalRes.h"
#include "TimeUtil.h"

void InitUtil::initiate()
{
	//initiate according to current system time 
	CCSprite* murkBg=rGlobal->murkBg;
	bool isNight=TimeUtil::isNightNow();
	if(isNight)
		murkBg->setOpacity(NIGHTTIME_OPACITY);
	else 
		murkBg->setOpacity(DAYTIME_OPACITY);
}
