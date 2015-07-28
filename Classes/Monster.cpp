#include "Monster.h"

bool Monster::init()
{
	cc_timeval psv;
	CCTime::gettimeofdayCocos2d(&psv,NULL);
	unsigned long int rand_seed = psv.tv_sec*1000+psv.tv_usec/1000;
	srand(rand_seed);
	healthPoint=100;
	currentHp=healthPoint;
	level=11;
	return true;
}
void Monster::setMonster()
{
	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	monster = CCSprite::create(MONSTER);
	monster->setPosition(ccp(visibleSize.width-100,visibleSize.height-200));
	this->addChild(monster);
}

int Monster::chooseButton()
{
	//srand((unsigned)time(NULL));
	//ѡbutton�㷨
	int tag;
	float rdm = CCRANDOM_0_1();
	CCLOG("%f",rdm);
	if (rdm<0.3)
		tag=0;
	else if (rdm>=0.3&&rdm<0.6)
		tag=1;
	else if (rdm>=0.6&&rdm<=1)
		tag=2;
	return tag;
}