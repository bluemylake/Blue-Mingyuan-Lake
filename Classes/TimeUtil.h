#ifndef __TIME_UTIL_H__
#define __TIME_UTIL_H__
#include "cocos2d.h"

class TimeUtil
{
public:
	static int getHour();
	static int getWeekDay();
	static bool isNightNow();
	//static void timeInitiate();
};
#endif
