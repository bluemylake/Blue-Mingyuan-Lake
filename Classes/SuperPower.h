#ifndef _SUPER_POWER_H_
#define _SUPER_POWER_H_
#include "cocos2d.h"

class SuperPower
{
public:
	float speed;
	bool teleport;
	bool stealth;
	bool surf;
	bool flash;
	bool all;
	SuperPower();
	SuperPower(float sp,bool tl,bool st,bool sf,bool fl);
};
#endif
