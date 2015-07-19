//
//  Player.h
//  血色明远湖
//
//  Created by Ring King on 14-4-26.
//
//

#ifndef _________Player__
#define _________Player__
#include <cstdlib>
#include "cocos2d.h"
#define DEFAULT_BLOOD 1000

class Player {
public:	
		int playerlevel;
		int totalBlood;
    Player();
    void init();
    int getBlood();
    bool getAttackWithMethod(int type);
	bool playerGetAttack(int type);
    int type;
private:
    int blood;
};

//class Enemy {
//public:	
//	Enemy();
//	void init();
//	int getEnemyBlood();
//	int chooseAttackMethod();
//	bool getAttackWithMethod(int type);
//	int type;
//private:
//	int blood;
//};

#endif /* defined(_________Player__) */
