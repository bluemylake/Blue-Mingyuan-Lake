#include "NPCUtil.h"

CCArray* NPCUtil::initNPC()
{
	CCArray* events=eManager->events;
	CCArray* NPCs=CCArray::create();
	NPCs->retain();
	Map* map=(Map*)rGlobal->map;
	for(int i=0;i<events->count();i++)
	{
		Event* event=(Event*)eManager->events->objectAtIndex(i);
		CCArray* args=event->args;
		if(event->imgNo>=0)
		{
			int cat=event->category;
			int arg0;
			HumanEntity* man;
			CCInteger* intg=(CCInteger*)args->objectAtIndex(INDEX_ZERO);
			switch(cat)
			{
			case STANDING:
				arg0=intg->getValue();//arg0=faceDir
				man=StandingMan::create(event->imgNo,event->id);
				man->setFaceDirection(arg0);
				man->dir=arg0;
				man->setPosition(map->positionFromTileCoord(event->coord));
				break;
			case TURNING:
				man=TurningMan::create(event->imgNo,event->id);
				man->setPosition(map->positionFromTileCoord(event->coord));
				break;
			case WALKING:
				{
				    WalkingMan* theMan=WalkingMan::create(event->imgNo,event->id);
				    theMan->setRoute(VectorLoader::start(args));
					int x=intg->getValue();intg=(CCInteger*)args->objectAtIndex(INDEX_ONE);
					theMan->setPosition(map->positionFromTileCoord(ccp(x,intg->getValue())));
				    man=theMan;
				}
				break;
			default:break;
			}
			man->setTag(MAN_START+event->id);
			rGlobal->map->addChild(man,NPC_ON_MAP_BACK_ZOR);
			NPCs->addObject(man);
		}
	}
	return NPCs;
}

HumanEntity* NPCUtil::findManById(int id, CCArray* NPCs)
{
	for(int i=0;i<NPCs->count();i++)
	{
		HumanEntity* man=(HumanEntity*)NPCs->objectAtIndex(i);
		if(man->id==id)return man;
	}
	return NULL;
}
