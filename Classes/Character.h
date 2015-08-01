#include <cstdlib>
#include "cocos2d.h"
#include "AppMacros.h"
#include "CombatUnit.h"
#include "Entity.h"
//#include "Animation.h"
#include "Ability.h"
using namespace cocos2d;

#ifndef __CHARACTER_H__
#define __CHARACTER_H__

class Character :public Entity, public CombatUnit
{
public:
	virtual bool init();
	bool ishero;
	int ID;
	Ability* ability;
public:	
	void getability(int num);
	int	giveHurt(int abilityNum,int& type);//²ÎÊý£º
	CCFiniteTimeAction* getGiveHurtAction(int abilityNum);
	CCFiniteTimeAction* getRecvHurtAction(int abilityNum);
	CCFiniteTimeAction* Character::exitAction();
	void receiveHurt(int hurt,int& type);
	bool isDead();

};
#endif