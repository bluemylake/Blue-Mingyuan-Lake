#include "Enemy.h"
using namespace cocos2d;

bool Enemy::init(){
	float chance ;
	chance = CCRANDOM_0_1();

	if (chance<0.4)
	{
		ID = 2;
		sprite = CCSprite::create(ENEMY1_IMG_PATH);
	}
	else if (chance>=0.4&&chance<0.7)
	{
		ID = 3;
		sprite = CCSprite::create(ENEMY2_IMG_PATH);
	}
	else if (chance>=0.7&&chance<0.9)
	{
		ID = 4;
		sprite = CCSprite::create(ENEMY3_IMG_PATH);
	}
	else if (chance>=0.9&&chance<=1)
	{
		ID = 5;
		sprite = CCSprite::create(ENEMY4_IMG_PATH);
	}
	getProperty();
	sprite->setTag(IMGSP);
	this->addChild(sprite);
	return true;
}

int Enemy::giveExp(){
	return 0;
}

int Enemy::decideAbility(int heroRemainHP,int heroLvl)
{
	int n = CCRANDOM_0_1()*4;
	return n;
}

void Enemy::getProperty()
{
	
	name = CsvUtil::sharedCsvUtil()->get(ID, 1,M_CSV_PATH);	
	level = CsvUtil::sharedCsvUtil()->getInt(ID, 2,M_CSV_PATH);
	Hp = CsvUtil::sharedCsvUtil()->getInt(ID, 3,M_CSV_PATH);
	attack = CsvUtil::sharedCsvUtil()->getInt(ID, 4,M_CSV_PATH);
	defence = CsvUtil::sharedCsvUtil()->getInt(ID, 5,M_CSV_PATH);
	speAtt = CsvUtil::sharedCsvUtil()->getInt(ID, 6,M_CSV_PATH);
	speDef = CsvUtil::sharedCsvUtil()->getInt(ID, 7,M_CSV_PATH);
		remainHp = Hp;
		ishero = false;
}