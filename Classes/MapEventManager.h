#ifndef _MAP_EVENT_MANAGER_H_
#define _MAP_EVENT_MANAGER_H_

#include "cocos2d.h"
#include "Map.h"
#include "Hero2.h"
using namespace cocos2d;

//description of the class here
class MapEventManager
{
public:
	MapEventManager();
	void doEvent(CCPoint heroTilePos);
	void _doPlaceNameEvent(CCDictionary* properties);
	void _doChangeSceneEvent(CCDictionary* properties);
	void _doCombatEvent(CCDictionary* properties);
	void _doPortalEvent(CCDictionary* properties);
	void _crossToMap(int mapNo);
private:
	Map* _map;
	Hero* _hero;
};
#endif
