#ifndef __MONSTER_H__
#define __MONSTER_H__
#include "Role.h"
#include "cocos-ext.h"
#include "time.h"
using namespace cocos2d;
USING_NS_CC_EXT; 

#define MONSTER "monster.png"
class Monster:public Role
{
public:
	CREATE_FUNC(Monster);
public:
	int monsterNo;
	virtual bool init();
	void setMonster(int monType);
	int chooseButton();
	//void attack();
private:
	CCSprite* monster;
};
#endif 