#ifndef __ENEMY_H__
#define __ENEMY_H__

#include "cocos2d.h"
#include "Character.h"
#include "Entity.h"
using namespace cocos2d;

class Enemy:public Character{
public:
	CREATE_FUNC(Enemy);
	virtual bool init();

	int ratity;
	int enemyExp;
public:
	int giveExp();
	int decideAbility(int heroRemainHP,int heroLvl);
	void getProperty();
};
#endif