#include "Player1.h"
using namespace cocos2d;

bool Player1::init(){
	getProperty();
	sprite = CCSprite::create(PLAYER_IMG_PATH);
	sprite->setTag(IMGSP);
	this->addChild(sprite);
	return true;
}

void Player1::levelUp(){

}

void Player1::receiveExp(int exp){

}

void Player1::fixAbility(int level){

}
void Player1::evolution(int level){

}

void Player1::getProperty()
{
	ID =  CsvUtil::sharedCsvUtil()->getInt(1, 0,M_CSV_PATH);
	name = CsvUtil::sharedCsvUtil()->get(1, 1,M_CSV_PATH);	
	level = CsvUtil::sharedCsvUtil()->getInt(1, 2,M_CSV_PATH);
	Hp = CsvUtil::sharedCsvUtil()->getInt(1, 3,M_CSV_PATH);
	attack = CsvUtil::sharedCsvUtil()->getInt(1, 4,M_CSV_PATH);
	defence = CsvUtil::sharedCsvUtil()->getInt(1, 5,M_CSV_PATH);
	speAtt = CsvUtil::sharedCsvUtil()->getInt(1, 6,M_CSV_PATH);
	speDef = CsvUtil::sharedCsvUtil()->getInt(1, 7,M_CSV_PATH);
	speed = CsvUtil::sharedCsvUtil()->getInt(1, 8,M_CSV_PATH);
	abilityNum[0] = CsvUtil::sharedCsvUtil()->getInt(1, 10,M_CSV_PATH);
	abilityNum[1] = CsvUtil::sharedCsvUtil()->getInt(1, 11,M_CSV_PATH);
	abilityNum[2] = CsvUtil::sharedCsvUtil()->getInt(1, 12,M_CSV_PATH);
	abilityNum[3] = CsvUtil::sharedCsvUtil()->getInt(1, 13,M_CSV_PATH);
	remainHp = Hp;
	ishero = true;
}