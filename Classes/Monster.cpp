#include "Monster.h"

bool Monster::init()
{
	cc_timeval psv;
	CCTime::gettimeofdayCocos2d(&psv,NULL);
	unsigned long int rand_seed = psv.tv_sec*1000+psv.tv_usec/1000;
	srand(rand_seed);
	
	return true;
}
void Monster::setMonster(int monType)
{
	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	char monPath[20];
	if (monType==0)
	{
		monsterNo = (int)(CCRANDOM_0_1()*6);
		sprintf(monPath,"monster%d.png",monsterNo);
		monster = CCSprite::create(monPath);
		level = (int)(CCRANDOM_0_1()*20);
	}
	else
	{
		sprintf(monPath,"monster%d.png",monType);
		monster = CCSprite::create(monPath);
		level = 30;
	}

	healthPoint=100+level*2;
	currentHp=healthPoint;
	
	
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