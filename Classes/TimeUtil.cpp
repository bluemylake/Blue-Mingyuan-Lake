#include "TimeUtil.h"

#define NIGHT_START_TIME 19
#define NIGHT_FINISH_TIME 7

using namespace cocos2d;

int TimeUtil::getHour()
{
	int hour=8;
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID || CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	struct cc_timeval now;
	CCTime::gettimeofdayCocos2d(&now,NULL);
	struct tm* tmm = localtime((const time_t*)&now.tv_sec);
	if(tmm!=NULL) hour = tmm->tm_hour;
#elif ( CC_TARGET_PLATFORM == CC_PLATFORM_WIN32 )
	time_t timep;
	time(&timep);
	struct tm* tmm = localtime(&timep);
	if (tmm != NULL) hour = tmm->tm_hour;
#endif
	return hour;
}

int TimeUtil::getWeekDay()
{
	int weekday=0;
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID || CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	struct cc_timeval now;
	CCTime::gettimeofdayCocos2d(&now,NULL);
	struct tm* tmm = localtime((const time_t*)&now.tv_sec);
	if(tmm!=NULL) weekday = tmm->tm_wday;
#elif ( CC_TARGET_PLATFORM == CC_PLATFORM_WIN32 )
	time_t timep;
	time(&timep);
	struct tm* tmm = localtime(&timep);
	if (tmm != NULL) weekday = tmm->tm_wday;
#endif
	return weekday;
}

bool TimeUtil::isNightNow()
{
	int hh = getHour();
	return hh >= NIGHT_START_TIME || hh <= NIGHT_FINISH_TIME;
}

/*void TimeUtil::timeInitiate()
{
	//initiate according to current system time 
	CCSprite* nightBg=rGlobal->nightBg;
	sGlobal->isNight=isNight(getHour());
	if(sGlobal->isNight)
		nightBg->setOpacity(NIGHTTIME_OPACITY);
	else 
		nightBg->setOpacity(DAYTIME_OPACITY);
}*/
