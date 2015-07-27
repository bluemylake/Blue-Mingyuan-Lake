#include "CPlayer.h"

bool CPlayer::init()
{
	healthPoint=100;
	currentHp=healthPoint;
	level=10;
	return true;
}
void CPlayer::setPlayer()
{
	 CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	player = CCSprite::create(PLAYER);
	player->setPosition(ccp(50,visibleSize.height-200));
	this->addChild(player);
}