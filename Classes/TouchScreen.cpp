#include "TouchScreen.h"

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

	CCPoint BX=touch->getLocation(),BD=hero->map->getPosition();
	CCPoint BA=ccp(CCDirector::sharedDirector()->getWinSize().width/2,CCDirector::sharedDirector()->getWinSize().height/2);
	CCPoint destPlace=BX-BA-(BD-BA)*0.3;
	
	int x=destPlace.x/(hero->map->getTileSize().width*EGLVIEW);
	int y=(((hero->map->getMapSize().height)*hero->map->getTileSize().height*EGLVIEW)
		-destPlace.y)/(hero->map->getTileSize().height*EGLVIEW);
	CCPoint mapTileCoord=ccp(x,y);
	CCPoint touchTilePos=hero->map->tileCoordFromPosition(touch->getLocation());
	CCPoint touchTiledPos=hero->map->positionFromTileCoord(touchTilePos);
	CCPoint mapTileMove=hero->map->humanPosForTileMove(mapTileCoord);

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
	hero->map->runAction(mapMove);
	hero->map->getParent()->runAction(mapLayerMove);
	sGlobal->mapState->positionX=hero->getHeroTilePos().x; 
	sGlobal->mapState->positionY=hero->getHeroTilePos().y;
	sGlobal->mapState->faceDir=hero->dir;
}

void TouchScreen::setPointers(Hero* hero,Button* buttonA, Button* dirButton)
{
	this->hero=hero;this->buttonA=buttonA;this->dirButton=dirButton;
}

//CCPoint heroPos=hero->getPosition()-hero->map->getPosition();
	//CCPoint DX=touchTiledPos-hero->map->getPosition()-ccp(0,86);
	//if(hero->checkCollision(ccp(DX.x,
		//DX.y-hero->map->getTileSize().height/4))==kWall)return;