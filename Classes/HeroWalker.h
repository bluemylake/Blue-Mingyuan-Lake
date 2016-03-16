#ifndef _HERO_WALKER_H_
#define _HERO_WALKER_H_

#include "Map.h"
#include "Hero2.h"
#include "MapEventManager.h"

//A class of controlling methods, in charge of hero movement
//Walk the Hero in a given direction until told otherwise
//Walk the Hero to a given position
//Fly Hero to a given position
class HeroWalker: public ControllerListener
{
public:
	HeroWalker();
	void respond(int direction);
	void endRespond();
	void update(float dt);
	CCPoint getHeroTilePos();
	bool checkCollision(CCPoint tileCoord);

	bool isWalking, focus;

private:
	void _initMovement(int direction);
	void _updateGlobalPosInfo();
	bool _checkEvent(CCPoint tileCoord);
	void _doEvent(CCPoint tileCoord);

	MapEventManager _mapEvtMgr;
	int _stepCnt;
	int _direction;
	bool _isStopping;
	CCPoint _moveByPosition;
	Map* _map;
	Hero* _hero;
};
#endif
