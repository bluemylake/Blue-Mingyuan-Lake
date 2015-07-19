#ifndef __PLAYER1_H__
#define __PLAYER1_H__

#include "cocos2d.h"
#include "Character.h"
#include "Entity.h"
using namespace cocos2d;


class Player1 : public Character{
public:
	CREATE_FUNC(Player1);
	virtual bool init();
	void levelUp();//判断是否升级，升级改属性
	void evolution(int level); //进化，图片和属性变化
	void receiveExp(int exp);
	void fixAbility(int level);//随着等级上升增加技能
	void getProperty();

public:
	int abilityNum[4];
	int myExp;
	int picNum;//进化 图片	
};
#endif