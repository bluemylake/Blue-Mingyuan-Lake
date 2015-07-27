#include "CrossMapEvent.h"
#include "Hero.h"

void CrossMapEvent::happen()
{
	//choose map 
	CCString* path; CCPoint heroTilePos=rGlobal->getHeroTilePos();
	int mapNo=sGlobal->mapState->mapNo; CCPoint delt=ccp(1,0);

	if(mapNo==MAP11) path=CCString::create(MAP11_PATH), delt=ccp(1,0);
	else path=CCString::create(MAP12_PATH), delt=ccp(-1,0);

	//re-create hero
	if(HERO_COVER_MODE)
	{
		rGlobal->hero=Hero::create();
		//rGlobal->hero->gotFocusT();
		rGlobal->hero->setFaceDirection(rGlobal->hero->dir);
	}

	//change map
	Map* map = (Map*)rGlobal->map;
	map->removeAllChildrenWithCleanup(true);
	map=Map::create(path->getCString());
	map->crossMap(heroTilePos,mapNo);
	rGlobal->hero->addChild(map);
	rGlobal->map=map;

	//re-create rGlobal->shadow
	if(rGlobal->shadow==NULL) return;
	rGlobal->shadow = ShadowingMan::create();
	CCPoint heroPos = heroTilePos + delt;
	CCPoint tPos = map->positionFromTileCoord(heroPos);
	rGlobal->shadow->setPosition(tPos);
	map->addChild(rGlobal->shadow,5);
}
