#include "GlobalRes.h"
#include "NPCMoveEvent.h"
#include "Map.h"

void NPCMoveEvent::happen() 
{
	int NPCId=-1, xx=0, yy=0;
	CCInteger* intg0=(CCInteger*)args->objectAtIndex(0);
	if(intg0!=NULL) NPCId=intg0->getValue();
	CCInteger* intg1=(CCInteger*)args->objectAtIndex(1);
	if(intg1!=NULL) xx=intg1->getValue();
	CCInteger* intg2=(CCInteger*)args->objectAtIndex(2);
	if(intg2!=NULL) yy=intg2->getValue();

	Map* map=(Map*)rGlobal->map;
	HumanEntity* man=NPCUtil::findManById(NPCId, map->NPCs);
	if(man==NULL) return;

	CCPoint lastpos=map->tileCoordFromPosition(man->getPosition())+ccp(0,2);
	man->setPosition(map->positionFromTileCoord(ccp(xx,yy)));
	eManager->eAtrgr->takeTile(lastpos,NO_EVENT_FLAG);
	eManager->eAtrgr->takeTile(ccp(xx,yy), man->id);
}
