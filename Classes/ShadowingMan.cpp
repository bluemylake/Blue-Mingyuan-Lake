#include "ShadowingMan.h"
#include "GlobalRes.h"
#include "Map.h"

bool ShadowingMan::init()
{
	CCNotificationCenter::sharedNotificationCenter()->addObserver(this,callfuncO_selector(ShadowingMan::shadow),"shadow",NULL);
	this->picNo=25;
	//this->setID(SHADOWN_FLAG_ID);
	this->initSprite();
	this->initAnimation();
	//sprite->setOpacity(120);
	return true;
}

void ShadowingMan::shadow(CCObject* heroPos)
{
	CCArray* coords = (CCArray*)heroPos;
	CCInteger* intgx = (CCInteger*)coords->objectAtIndex(0);
	CCInteger* intgy = (CCInteger*)coords->objectAtIndex(1);
	CCPoint pos = ccp(intgx->getValue(),intgy->getValue());
	pos = pos - ccp(0, 2);
		
	Map* map = (Map*)rGlobal->map;
	CCPoint myPos = this->getPosition();
	CCPoint inTile = map->tileCoordFromPosition(myPos);
	CCPoint vect= ccp((pos.x-inTile.x), -(pos.y-inTile.y))*32;

	int dir=Down;
	if(vect.y==0)
	{
		if(vect.x>0) dir=Right;
		else if(vect.x<0) dir=Left;
		else return; //Hero moves not
	}
	else if(vect.x==0)
	{
		if(vect.y>0) dir=Up;
		else dir=Down;
	}
	else
		CCLog("Strange vect: (%f,%f)", vect.x, vect.y);

	CCMoveBy* move=CCMoveBy::create(STD_WALK_DURATION*0.45,vect);
	CCAnimate* anim=CCAnimate::create(walkAnimations[dir]);//行走
	sprite->runAction(anim); this->runAction(move);
}
