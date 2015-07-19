#ifndef __MAP_H__
#define __MAP_H__
#include "cocos2d.h"
#include "GlobalState.h"
#include "TurningMan.h"
#include "StandingMan.h"
#include "WalkingMan.h"
#include "NPCUtil.h"
#include "Emap.h"
using namespace cocos2d;
//displays the game Map and NPCs
//stores the NPCs to respond to Events

#define STANDING 0
#define TURNING 1
#define WALKING 2
#define INDEX_ZERO 0
#define INDEX_ONE 1

class Map : public CCTMXTiledMap
{
public:
	static Map* create(const char *tmxFile);
	void setGameStartPos();
	void initNPC();
	Map* crossMap(CCPoint tileBirthPoint,int mapNo);
	virtual void removeAllChildrenWithCleanup(bool cleanup);
	~Map();

	CCPoint tileCoordFromPosition(CCPoint pos);
	CCPoint positionFromTileCoord(CCPoint tileCoord);
	CCPoint humanPosForTileMove(CCPoint tileCoord);
public:
    CCArray* NPCs; 
};
#endif
