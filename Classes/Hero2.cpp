#include "Hero2.h"

bool Hero::init() 
{
	setID(0);
	picNo=0;

	WalkingMan::initAnimation();
	initSprite();
	//x+1人往左跑，y+1人向下跑
	sprite->setAnchorPoint(CCPointZero+ccp(0.5,-0.625));
	return true;
}
