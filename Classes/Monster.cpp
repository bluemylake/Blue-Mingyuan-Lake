#include "Monster.h"

bool Monster::init()
{
	srand(time(0));
	healthPoint=100;
	currentHp=healthPoint;
	level=11;
	return true;
}
void Monster::setMonster()
{
	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	monster = CCSprite::create(MONSTER);
	monster->setPosition(ccp(visibleSize.width-50,visibleSize.height-200));
	this->addChild(monster);
}

int Monster::chooseButton()
{
	//srand((unsigned)time(NULL));
	//ѡbutton�㷨
	int tag;
	int rdm = CCRANDOM_0_1();
	if (rdm<0.3)
		tag=0;
	if (tag<0.6&&tag>=0.3)
		tag=1;
	if (tag>=0.6&&tag<=1)
		tag=2;
	return tag;
}