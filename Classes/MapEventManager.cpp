#include "MapEventManager.h"

bool MapEventManager::init()
{
	//_functionMap = {}; 
	_map = rGlobal->map;
	_hero = rGlobal->hero;
}

void MapEventManager::doEvent(CCPoint heroTilePos)
{
	//获取脚下event层tile id
	int tileGid = _map->layerNamed(EVENT_MLYR)->tileGIDAt(heroTilePos); 
	CCDictionary *properties = _map->propertiesForGID(tileGid);
	const CCString *eventScene = properties->valueForKey("stand");

	if(!eventScene->compare("place name"))
		_doPlaceNameEvent();
	else if(!eventScene->compare("change scene"))
		_doChangeSceneEvent();
	else if(!eventScene->compare("combat"))
		_doCombatEvent()
	else if(!eventScene->compare("portal"))
		_doPortalEvent();
}

void MapEventManager::_doPlaceNameEvent()
{
	int curPlaceID=properties->valueForKey("id")->intValue();
	rGlobal->rwindow->load(map, properties);
	rGlobal->rwindow->respond(curPlaceID);
}

void MapEventManager::_doChangeSceneEvent()
{
	// TODO: focus
	int id = properties->valueForKey("id")->intValue();
	switch(id)
	{
		case 0: case 1: case 2: case 3: case 4: 
		case 5: case 6: case 7: case 8: case 9: 
			if(sGlobal->isNight) return;
			if(id==sGlobal->mapState->storyCnt)
			{
				//this->focus=false;
				CCEGLView::sharedOpenGLView()->setDesignResolutionSize(
						JX_RESOLUWID, JX_RESOLUHEI, kResolutionExactFit);
				CCScene* story=StoryWorld::scene();
				CCTransitionScene *scenetrans = CCTransitionCrossFade::
					create(1.45, story);
				CCDirector::sharedDirector()->pushScene(scenetrans);
				//this->gotFocusT();
				sGlobal->mapState->storyCnt++;
				sGlobal->save();
			}
			break;

		case MAP11: crossToMap(MAP12); break;
		case MAP12: crossToMap(MAP11); break;
		default: break;
	}
}

void MapEventManager::_doCombatEvent()
{
	// TODO: focus
	if(!sGlobal->isNight)return;
	float i = CCRANDOM_0_1();
	if (i<0.2)
	{	
		//this->focus=false;

		CCScene* pScene = Combat::scene();
		Combat* pLayer = (Combat*)pScene->getChildByTag(COMBATLAYER);
		// Pass args here 
		if(pLayer != NULL) pLayer->setMonsterType( 0 );
		else CCLog("Combat Layer get fail. ");
		CCTransitionFade *scenetrans = CCTransitionFade::create(0.7, pScene);
		CCDirector::sharedDirector()->pushScene(scenetrans);
	}
	//this->focus=true;
}

void MapEventManager::_doPortalEvent()
{
	// TODO: focus, Shouldn't manwalker make the fly?
	//this->focus=false;
	int x = properties->valueForKey("idx")->intValue();
	int y = properties->valueForKey("idy")->intValue();
	CCPoint dest = ccp(x,y);
	CCAnimate* spin = CCAnimate::create(this->createAnimationForDirection(5));
	CCRepeat* spinM = CCRepeat::create(spin, 6);
	//CCCallFunc* regotF = CCCallFunc::create(this,callfunc_selector(Hero::gotFocusT));
	//CCSequence* goSpin = CCSequence::create(spinM, regotF, NULL);
	CCDelayTime* delay = CCDelayTime::create(1);
	CCPlace* mov = CCPlace::create(_map->humanPosForTileMove(dest));
	CCSequence* fly = CCSequence::create(delay, mov, NULL);
	//sprite->runAction(goSpin);
	_map->runAction(fly);
}     

void MapEventManager::_crossToMap(int mapNo)
{
	// TODO: make it concise
	//choose map 
	CCString* path; CCPoint heroTilePos = getHeroTilePos();
	CCPoint delt = ccp(1,0);
	if(mapNo == MAP11) //arrive at MAP11
		path = CCString::create(MAP11_PATH), delt = ccp(1,0);
	else 
		path = CCString::create(MAP12_PATH), delt = ccp(-1,0);

	//change map
	_map->removeAllChildrenWithCleanup(true);
	_map = Map::create(path->getCString());
	rGlobal->map = map;
	_map->crossMap(heroTilePos, mapNo);
	eManager->redoAll();
	this->getParent()->addChild(map);

	//re-create rGlobal->shadow
	if(rGlobal->shadow == NULL) return;
	rGlobal->shadow = ShadowingMan::create();
	CCPoint heroPos = getHeroTilePos() + delt;
	CCPoint tPos = _map->positionFromTileCoord(heroPos);
	rGlobal->shadow->setPosition(tPos);
	_map->addChild(rGlobal->shadow, 5);
}
