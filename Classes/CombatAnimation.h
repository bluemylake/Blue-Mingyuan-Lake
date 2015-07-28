#ifndef __COMBAT_ANIMATION_H__
#define __COMBAT_ANIMATION_H__
#include "cocos2d.h"
#include "cocos-ext.h"
using namespace cocos2d;
USING_NS_CC_EXT; 
class CombatAnimation:public CCNode
{
public:
	CREATE_FUNC(CombatAnimation);
public:
	void fireParticle(int direction);
};
#endif 