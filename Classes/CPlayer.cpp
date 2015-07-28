#include "CPlayer.h"

bool CPlayer::init()
{
	level=10;
	healthPoint=100+level*2;
	currentHp=healthPoint;
	
	return true;
}
void CPlayer::setPlayer()
{
	 CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	player = CCSprite::create(PLAYER);
	player->setPosition(ccp(100,visibleSize.height-200));
	this->addChild(player);
}