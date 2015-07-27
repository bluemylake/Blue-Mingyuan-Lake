#ifndef _ANIMATION_H_
#define _ANIMATION_H_
#include "cocos2d.h"
using namespace cocos2d;

#define TAISHANYADING 1
#define STAGGER 2
#define STRIKE 3
#define DOWN 5
#define UP 4
#define ATTACK 0
#define STEALTH 6
#define TELEPORTOUT 7
#define TELEPORTIN 8
#define STEALTHOUT 9
#define STEALTHIN 10
#define SWAY 11
#define FADEOUT 12
#define FADEIN 13


class Animation
{
public:
	static CCFiniteTimeAction* getAction(int choice,CCSize size);
};

#endif
