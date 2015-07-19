#ifndef _NPC_UTIL_H_
#define _NPC_UTIL_H_
#include "GlobalRes.h"
#include "HumanEntity.h"
#include "EventManager.h"
#include "Map.h"
#include "cocos2d.h"
using namespace cocos2d;

//translate the arguments of events to attributes of NPCs
//use with map->NPCs to find man by id
class NPCUtil
{
public:
    static CCArray* initNPC();
    static HumanEntity* findManById(int id, CCArray* NPCs);
};
#endif
