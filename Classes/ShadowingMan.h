#ifndef __SHADOWING_MAN_H__
#define __SHADOWING_MAN_H__
#include "cocos2d.h"
#include "WalkingMan.h"
using namespace cocos2d;
//#define STD_WALK_DURATION 0.32f

class ShadowingMan: public WalkingMan
{
public:
    CREATE_FUNC(ShadowingMan);
	bool init();
	void shadow(CCObject* direction);
	~ShadowingMan();
};
#endif

