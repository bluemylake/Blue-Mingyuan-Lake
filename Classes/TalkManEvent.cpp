#include "TalkManEvent.h"

void TalkManEvent::happen()
{
    Map* map=(Map*)rGlobal->map;
	CCArray* NPCs=map->NPCs;
    HumanEntity* man=NPCUtil::findManById(id,NPCs);
    man->respond(3-rGlobal->hero->dir); //action go 

    rGlobal->diawindow->setControllerListener(man); //prepare 
    rGlobal->diawindow->load(dialog);
    rGlobal->diawindow->respond(); //action go
}
