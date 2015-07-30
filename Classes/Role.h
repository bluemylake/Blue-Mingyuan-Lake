#ifndef __Role_H__
#define __Role_H__
#include "cocos2d.h"
#include "cocos-ext.h"
using namespace cocos2d;
USING_NS_CC_EXT; 
class Role:public CCNode
{
public:
	CREATE_FUNC(Role);
public:
	virtual bool init();
	//int getHp();
	int exp;
	int level;
	int healthPoint;
	int currentHp;
};
#endif 