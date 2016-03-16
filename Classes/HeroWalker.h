#ifndef _HERO_WALKER_H_
#define _HERO_WALKER_H_

//#include "CCPoint.h"

//A class of controlling methods, in charge of hero movement
//Walk the Hero in a given direction until told otherwise
//Walk the Hero to a given position
//Fly Hero to a given position
class HeroWalker
{
public:
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

	int _stepCnt;
	int _direction;
	bool _isStopping;
	CCPoint _moveBytileCoord;
	Map* _map;
	Hero* _hero;
};
#endif
