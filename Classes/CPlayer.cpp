#include "CPlayer.h"

bool CPlayer::init()
{
	exp = sGlobal->playerState->exp;
	CCLOG("exp:%d",exp);
	exp2Level(exp);
	healthPoint=100+level*2;
	currentHp=healthPoint;
	
	return true;
}

void CPlayer::setPlayer()
{
	 CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	player = CCSprite::create(PLAYER_IMG_PATH);
	player->setPosition(ccp(100,visibleSize.height-200));
	this->addChild(player);
}

void CPlayer::exp2Level(int exp)
{
	if (exp<2)
		level=1;
	else if (exp>=2&&exp<=30)
		level=1+exp/2;
	else if(exp>30&&exp<=60)
		level = 16+(exp-30)/3;
	else if(exp>60&&exp<=180)
		level = 26+(exp-60)/5;
	else
		level = 50;
}
