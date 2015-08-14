#include "GlobalPath.h"
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
	char monPath[80];
	if (monType==0)
	{
		monsterNo = (int)(CCRANDOM_0_1()*6);
		CCLOG("monster:%d",monsterNo);
		sprintf(monPath,MONSTER_IMG_PATH,monsterNo);
		monster = CCSprite::create(monPath);
		level = (int)(CCRANDOM_0_1()*10);
	}
	else
	{
		if (monType==5)
		{
			monster = CCSprite::create("img/new combat/char/boss5.png");
			level = 25;
		}
		else 
		{
			monster = CCSprite::create("img/new combat/char/boss1.png");
			level = 15;
		}
	}

	healthPoint=100+level*2;//change
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
