#include "Hero.h"

bool Hero::init() 
{
	setID(0); picNo=0; isWalking=false; 
	map=(Map*)rGlobal->map;
	dir=sGlobal->mapState->faceDir;

	WalkingMan::initAnimation();
	initSprite();
	initAction(dir);
	sprite->setAnchorPoint(CCPointZero+ccp(0.5,-0.625));//x+1人往左跑，y+1人向下跑
	return true;
}

void Hero::doEvent(CCPoint heroTilePos)
{
	//@EventManager takes over from here
	CCPoint facingTile = getHeroTilePos()+
		ccp((move/(map->getTileSize().height)).x,
				-(move/(map->getTileSize().height)).y);
	ControllerListener* lst=eManager->happen(facingTile,STAND_TRIG);

	//获取脚下event层tile id
	int tileGid = map->layerNamed(EVENT_MLYR)->tileGIDAt(heroTilePos); 
	if (!tileGid)return;

	CCDictionary *properties = map->propertiesForGID(tileGid);
	if (!properties)return;

	const CCString *eventScene = properties->valueForKey("stand");
	//路名事件
	if(!eventScene->compare("place name"))
	{
		int curPlaceID=properties->valueForKey("id")->intValue();
		rGlobal->rwindow->load(map,properties);
		rGlobal->rwindow->respond(curPlaceID);
	}
	//场景切换事件inte
	else if(!eventScene->compare("change scene"))
	{
		
		int id=properties->valueForKey("id")->intValue();
		switch(id)
		{
			case 0:case 1:case 2:case 3:case 4:
			case 5:case 6:case 7:case 8:case 9:
				if(sGlobal->isNight) return;
				if(id==sGlobal->mapState->storyCnt)
				{
					touchEnded=dir;walkEnd();//endWalking
					this->focus=false;
					CCEGLView::sharedOpenGLView()->setDesignResolutionSize(JX_RESOLUWID, JX_RESOLUHEI, kResolutionExactFit);
					CCScene* story=StoryWorld::scene();
					CCTransitionScene *scenetrans = CCTransitionCrossFade::create(1.45, story);
					CCDirector::sharedDirector()->pushScene(scenetrans);
					this->gotFocusT();
					sGlobal->mapState->storyCnt++;
					sGlobal->save();
				}
				break;

			case MAP11: crossToMap(MAP12); break;
			case MAP12: crossToMap(MAP11); break;
			default:break;
		}
	}
	else if(!eventScene->compare("combat"))
	{
		float i = CCRANDOM_0_1();
		if (i<0.3)
		{	
			touchEnded=dir;walkEnd();//endWalking
			this->focus=false;

			CCScene* pScene = Combat::scene();
			Combat* pLayer = (Combat*)pScene->getChildByTag(COMBATLAYER);
			//pass args here 
			if(pLayer!=NULL) pLayer->setMonsterType( 0 );
			else CCLog("Combat Layer get fail. ");
			//CCEGLView::sharedOpenGLView()->setDesignResolutionSize(JX_RESOLUWID, JX_RESOLUHEI, kResolutionExactFit);
			CCTransitionFade *scenetrans = CCTransitionFade::create(0.7, pScene);
			CCDirector::sharedDirector()->pushScene(scenetrans);//@
		}
		this->focus=true;
		;}
	else if(!eventScene->compare("portal"))
	{
		touchEnded=dir;walkEnd();//endWalking
		this->focus=false;
		int x=properties->valueForKey("idx")->intValue();//@
		int y=properties->valueForKey("idy")->intValue();
		CCPoint dest=ccp(x,y);
		CCAnimate* spin=CCAnimate::create(this->createAnimationForDirection(5));//行走
		CCRepeat* spinM=CCRepeat::create(spin,6);
		CCCallFunc* regotF=CCCallFunc::create(this,callfunc_selector(Hero::gotFocusT));
		CCSequence* goSpin=CCSequence::create(spinM,regotF,NULL);
		CCDelayTime* delay=CCDelayTime::create(1);
		CCPlace* mov=CCPlace::create(map->humanPosForTileMove(dest));
		CCSequence* fly=CCSequence::create(delay,mov,NULL);
		sprite->runAction(goSpin);
		map->runAction(fly);
	}     
}








void Hero::respond(int dir) 
{
	if(isWalking||!focus){return;}
	touchEnded=-1;
	initAction(dir);
	letsGo(0);
}

void Hero::endRespond()
{
	touchEnded=dir;
}

void Hero::walkEnd()
{
	if(touchEnded>-1)
	{
		map->stopAction(moveMap);
		sprite->stopAction(moveLegs);
		moveMap=NULL,moveLegs=NULL;
		setFaceDirection(dir);
		isWalking=false;

		sGlobal->mapState->positionX=getHeroTilePos().x; 
		sGlobal->mapState->positionY=getHeroTilePos().y;
		sGlobal->mapState->faceDir=dir;
	}
}

void Hero::letsGo(float dt)
{
	isWalking = true;
	map->runAction(moveMap);
	sprite->runAction(moveLegs);
}

void Hero::initAction(int dir)
{
	CCPoint moveByPosition;
	switch(dir)
	{
		case Down:moveByPosition=ccp(0,-32);break;
		case Left:moveByPosition=ccp(-32,0);break;
		case Right:moveByPosition=ccp(32,0);break;
		case Up:moveByPosition=ccp(0,32);break;
		default:break;
	}
	CCPoint revMoveByPosition=-moveByPosition;
	this->move=moveByPosition,this->dir=dir;

	//行走和位移两个动作
	const float duration=STD_WALK_DURATION/sGlobal->superPower->speed;
	//CCJumpBy* jump=CCJumpBy::create(duration,ccp(0,0),16,1);
	CCMoveBy* revShift=CCMoveBy::create(duration,revMoveByPosition);
	CCAnimate* anim=CCAnimate::create(walkAnimations[dir]);//行走
	CCDelayTime* delay=CCDelayTime::create(1.5f/32.0f*duration*1.8);
	CCCallFunc* stepU=CCCallFunc::create(this,callfunc_selector(Hero::stepUp));
	CCCallFunc* follM=CCCallFunc::create(this,callfunc_selector(Hero::followMe));
	CCCallFunc* stepD=CCCallFunc::create(this,callfunc_selector(Hero::stepDown));
	//CCSpawn* animJ=CCSpawn::create(anim,jump,NULL);
	CCSequence* revAct = CCSequence::create(stepU, delay, follM, revShift, stepD, NULL);

	moveLegs=CCRepeatForever::create(anim);
	moveMap=CCRepeatForever::create(revAct);
}





void Hero::stepUp()
{
	CCPoint heroCoord=getHeroTilePos();
	CCPoint moveCoord=move/map->getTileSize().height;
	if(checkCollision(ccp(heroCoord.x+moveCoord.x,
					heroCoord.y-moveCoord.y))==kWall)
	{
		touchEnded=dir; walkEnd();
	}
}

void Hero::followMe()
{
	if(touchEnded<=-1)
	{
		CCArray* heroPos = CCArray::create();
		CCPoint heroCoord=getHeroTilePos();
		heroPos->addObject(CCInteger::create(heroCoord.x));
		heroPos->addObject(CCInteger::create(heroCoord.y));
		CCNotificationCenter::sharedNotificationCenter()->postNotification(HERO_STEP_UP_MSG, (CCObject*)heroPos);
	}
}

void Hero::stepDown()
{
	if (checkEvent(getHeroTilePos())==kEvent)
		doEvent(getHeroTilePos());
	walkEnd();
}








//地图事件检测
CollisionType Hero::checkEvent(CCPoint tileCoord)
{
	int tileGid = map->layerNamed(EVENT_MLYR)->tileGIDAt(tileCoord);
	if (tileGid)return kEvent;  
	if (eManager->eStand->tileAt(tileCoord)>NO_EVENT_FLAG)return kEvent;  
	return kNone;
}

//碰撞检测
CollisionType Hero::checkCollision(CCPoint tileCoord)
{
	//超过地图边界返回kWall
	if (tileCoord.x<0||tileCoord.x>map->getMapSize().width-1||
			tileCoord.y>map->getMapSize().height-2||tileCoord.y<0)
		return kWall;

	int wTileGid= map->layerNamed(WALL_MLYR)->tileGIDAt(tileCoord);
	int bTileGid= map->layerNamed(BUILDING_MLYR)->tileGIDAt(tileCoord);
	int b2TileGid= map->layerNamed(BUILDING2_MLYR)->tileGIDAt(tileCoord);
	int wtTileGid= map->layerNamed(WATER_MLYR)->tileGIDAt(tileCoord);
	int eTileGid= map->layerNamed(EVENT_MLYR)->tileGIDAt(tileCoord);bool batrg=false;
	if(eTileGid)batrg=map->propertiesForGID(eTileGid)->valueForKey("atrg")->compare("")!=0;
	if(wTileGid||bTileGid||b2TileGid||batrg||wtTileGid)return kWall;
	if(eManager->eAtrgr->tileAt(tileCoord)>NO_EVENT_FLAG)return kWall;
	return kNone;
}

CCPoint Hero::getHeroTilePos()
{
	return map->tileCoordFromPosition(getPosition()-map->getPosition());
}

void Hero::gotFocusT()
{
	focus=true;
}

void Hero::crossToMap(int mapNo)
{
	//choose map 
	CCString* path; CCPoint heroTilePos=getHeroTilePos();
	CCPoint delt=ccp(1,0);
	if(mapNo==MAP11) //arrive at MAP11
		path=CCString::create(MAP11_PATH), delt=ccp(1,0);
	else 
		path=CCString::create(MAP12_PATH), delt=ccp(-1,0);

	//change map
	touchEnded=dir;walkEnd();
	map->removeAllChildrenWithCleanup(true);
	map=Map::create(path->getCString());
	rGlobal->map=map;
	map->crossMap(heroTilePos,mapNo);
	eManager->redoAll();
	this->getParent()->addChild(map);

	//re-create rGlobal->shadow
	if(rGlobal->shadow==NULL) return;
	rGlobal->shadow = ShadowingMan::create();
	CCPoint heroPos = getHeroTilePos() + delt;
	CCPoint tPos = map->positionFromTileCoord(heroPos);
	rGlobal->shadow->setPosition(tPos);
	map->addChild(rGlobal->shadow,5);
}
