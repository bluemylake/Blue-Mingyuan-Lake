#include "TouchScreen.h"
#include "GlobalRes.h"

bool TouchScreen::init()
{
	doShrink=true;
	return true;
}

void TouchScreen::ccTouchesBegan(CCSet* pTouch, CCEvent *pEvent)
{
}

void TouchScreen::ccTouchesEnded(CCSet* pTouch, CCEvent *pEvent)
{
	teleportTo(pTouch,pEvent);
	zoomStroke(pTouch,pEvent);
}

void TouchScreen::ccTouchesMoved(CCSet* pTouch, CCEvent *pEvent)
{
}

void TouchScreen::zoomStroke(CCSet* pTouches, CCEvent *pEvent)
{
	CCTouch* touch=(CCTouch*)pTouches->anyObject();
	if((touch->getLocation()-touch->getStartLocation()).getLength()>ZOOMSTROKELEN)
	{
		CCScaleTo* scaleTo;
		if(doShrink)scaleTo=CCScaleTo::create(1.0f,EGLVIEW);
		else scaleTo=CCScaleTo::create(0.7f,1.0f);
		this->getParent()->getParent()->getChildByTag(MAPLAYER)->runAction(scaleTo);
		doShrink=!doShrink;
	}
}

void TouchScreen::teleportTo(CCSet* pTouch, CCEvent *pEvent)
{
	CCTouch* touch=(CCTouch*)pTouch->anyObject();	
	if((touch->getLocation()-touch->getStartLocation()).getLength()>ZOOMSTROKELEN)return;
	if(doShrink||(!sGlobal->superPower->teleport&&!sGlobal->superPower->all))return;
	if(buttonA->getBoundingBox().containsPoint(getTouchPos(pTouch)))return;
	if(dirButton->getBoundingBox().containsPoint(getTouchPos(pTouch)))return;

	CCPoint BX=touch->getLocation(), BD=rGlobal->map->getPosition();
	CCPoint BA=ccp(CCDirector::sharedDirector()->getWinSize().width/2,CCDirector::sharedDirector()->getWinSize().height/2);
	CCPoint destPlace=BX-BA-(BD-BA)*0.3;
	
	int x=destPlace.x/(rGlobal->map->getTileSize().width*EGLVIEW);
	int y=(((rGlobal->map->getMapSize().height)*rGlobal->map->getTileSize().height*EGLVIEW)
		-destPlace.y)/(rGlobal->map->getTileSize().height*EGLVIEW);
	CCPoint mapTileCoord=ccp(x,y);
	CCPoint touchTilePos=rGlobal->map->tileCoordFromPosition(touch->getLocation());
	CCPoint touchTiledPos=rGlobal->map->positionFromTileCoord(touchTilePos);
	CCPoint mapTileMove=rGlobal->map->humanPosForTileMove(mapTileCoord);

	CCSequence* teleport=CCSequence::create(CCDelayTime::create(0.5f),
		AnimLib::getAction(TELEPORTOUT,hero->getChildByTag(IMGSP)->getContentSize()),
		CCDelayTime::create(0.40f),
		AnimLib::getAction(TELEPORTIN,hero->getChildByTag(IMGSP)->getContentSize()),
		NULL);
	CCScaleTo* mapLayerMove=CCScaleTo::create(0.5f,1.0f);
	CCSequence* mapMove=CCSequence::create(CCDelayTime::create(0.5f),
		CCDelayTime::create(0.2f),CCMoveTo::create(0.3f,mapTileMove),NULL);

	doShrink=!doShrink;
	hero->runAction(teleport);
	rGlobal->map->runAction(mapMove);
	rGlobal->map->getParent()->runAction(mapLayerMove);
	sGlobal->mapState->positionX=hero->getHeroTilePos().x; 
	sGlobal->mapState->positionY=hero->getHeroTilePos().y;
	sGlobal->mapState->faceDir=hero->dir;
}

void TouchScreen::setPointers(Hero* hero, Button* buttonA, Button* dirButton)
{
	this->hero=hero; this->buttonA=buttonA; this->dirButton=dirButton; 
}

//CCPoint heroPos=hero->getPosition()-rGlobal->map->getPosition();
	//CCPoint DX=touchTiledPos-rGlobal->map->getPosition()-ccp(0,86);
	//if(hero->checkCollision(ccp(DX.x,
		//DX.y-rGlobal->map->getTileSize().height/4))==kWall)return;
