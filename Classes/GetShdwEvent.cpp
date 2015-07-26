#include "GlobalState.h"
#include "GetShdwEvent.h"
#include "ShadowingMan.h"
#include "Map.h"

void GetShdwEvent::happen() 
{
	//extract starting pos
	CCInteger* intgx=(CCInteger*)args->lastObject();
	int dir=-1;
	if(intgx!=NULL) dir=intgx->getValue();
	CCPoint pos=ccp(1,0);
	switch(dir)
	{
		case Down: pos=ccp(0,1); break;
		case Left: pos=ccp(-1,0); break;
		case Right: pos=ccp(1,0); break;
		case Up: pos=ccp(0,-1); break;
		default: CCLog("Unexpected Shadow pos. Using default.");
	}

	Map* map = (Map*)rGlobal->map;
	rGlobal->shadow = ShadowingMan::create(); 
	CCPoint  heroTilePos=map->tileCoordFromPosition(
			rGlobal->hero->getPosition() - map->getPosition() );
	CCPoint heroPos = heroTilePos + pos;
	CCPoint tPos = map->positionFromTileCoord(heroPos);
	rGlobal->shadow->setPosition(tPos);
	rGlobal->map->addChild(rGlobal->shadow,5);
}
