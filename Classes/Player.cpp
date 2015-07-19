//
//  Player.cpp
//  血色明远湖
//
//  Created by Ring King on 14-4-26.
//
//

#include "Player.h"

Player::Player() {
	
    blood = DEFAULT_BLOOD;
}

void Player::init() {
	playerlevel=10;
	blood = DEFAULT_BLOOD+playerlevel*10;
	totalBlood=DEFAULT_BLOOD+playerlevel*10;
	
}

int Player::getBlood() {
    return blood;
}



bool Player::playerGetAttack(int type)
{
	int hurt = 0;

	switch (type) {
	case 0:
		hurt = 50;
		break;
	case 1:
		hurt = 150*CCRANDOM_0_1();
		break;
	case 2:
		
		hurt = 250*CCRANDOM_0_1();
		break;
	case 3:
		hurt = 350*CCRANDOM_0_1();
		
		break;

	default:
		break;
	}
	blood -= hurt;
	if (blood>0) {
		//Not Dead yet!
		return false;
	}
	return true;
}

bool Player::getAttackWithMethod(int type) {
    int hurt = 0;

    switch (type) {
        case 0:
            hurt = 50;
            break;
        case 1:
            hurt = 250*CCRANDOM_0_1();
            break;
		case 2:
			if (CCRANDOM_0_1()<0.8)
			{
				hurt=10;
			}
			else hurt=600;
			
			break;
		case 3:
			if (CCRANDOM_0_1()<0.7)
			{
				hurt=20;
			}
			else hurt=300;
			break;
            
        default:
            break;
    }
    blood -= hurt;
    if (blood>0) {
        //Not Dead yet!
        return false;
    }
    return true;
}

//Enemy::Enemy() {
//	blood = DEFAULT_BLOOD;
//}
//
//void Enemy::init()
//{
//	 blood = DEFAULT_BLOOD;
//}
//
//int Enemy::getEnemyBlood()
//{
//	return blood;
//}

