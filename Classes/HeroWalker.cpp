#include "HeroWalker.h"
#include "GlobalRes.h"

HeroWalker::HeroWalker()
{
	isWalking = false;
	focus = true;
	_stepCnt = 0;
	_map = (Map*) rGlobal->map;
	_hero = (Hero*) rGlobal->hero;
}

void HeroWalker::respond(int direction)
{
	if( isWalking || !focus ) { return; }

	_isStopping = false;
	_direction = direction;
	_hero->dir = direction;
	initMovement( direction );
	this->isWalking = true;
	this->schduleUpdate();
}

void HeroWalker::initMovement(int direction)
{
	switch(direction)
	{
		case Down:  _moveByPosition = ccp(0, -1); break; 
		case Left:  _moveByPosition = ccp(-1, 0); break; 
		case Right: _moveByPosition = ccp(+1, 0); break; 
		case Up:    _moveByPosition = ccp(0, +1); break; 
	}
	const int speed = 1;
	_moveByPosition *= speed;
	hero->move = _moveByPosition;
}

void HeroWalker::endRespond()
{
	_isStopping = true
}

void HeroWalker::update(float dt)
{
	//Affect first step
	if(_stepCnt == 0)
		if( checkCollision(getHeroTilePos()) )
			_isStopping = true;

	if(!_isStopping || _stepCnt>0 )
	{
		//Map rev move
		_map->setPosition( _map->getPosition() + _moveByPosition );
		//Man take step
		_hero->setFrame( _stepCnt / 8 );

		_stepCnt++;
		if(_stepCnt >= _map->getTileSize().height)
		{
			_stepCnt = 0;
			//Does not affect first step
			if( _checkEvent(getHeroTilePos()) )
				_doEvent( getHeroTilePos() );
			_isStopping = true;
		}
	}
	else
	{
		_updateGlobalPosInfo();
		this->isWalking = false;
		this->unscheduleUpdate();
	}
}

CCPoint HeroWalker::getHeroTilePos()
{
	return _map->tileCoordFromPosition(getPosition()-_map->getPosition());
}




bool HeroWalker::checkCollision(CCPoint tileCoord)
{
	const bool COLLIDE = true, PASS = false;
	//Out of map block
	if( tileCoord.x<0 || tileCoord.x>map->getMapSize().width-1 || 
			tileCoord.y>map->getMapSize().height-2 || tileCoord.y<0 )
		return COLLIDE;
	//Barricade block
	string layerNames[] = { WATER_MLYR, BUILDING_MLYR, 
		BUILDING2_MLYR, WATER_MLYR, EVENT_MLYR };
	for(const auto& name: layerNames)
		if( map->layerNamed( name )->tilegidat( tilecoord ) )
			return COLLIDE;
	//Dynamic Talking Men block the way
	if(eManager->eAtrgr->tileAt(tileCoord)>NO_EVENT_FLAG) return COLLIDE;
	return PASS;
}

bool HeroWalker::_checkEvent(CCPoint tileCoord)
{
	int tileGid = map->layerNamed(EVENT_MLYR)->tileGIDAt(tileCoord);
	if (tileGid) return true;  
	if (eManager->eStand->tileAt(tileCoord) > NO_EVENT_FLAG) return true;  
	return false;
}

void HeroWalker::_doEvent(CCPoint tileCoord)
{
	mapEvtMgr->doEvent( tileCoord );
}

void HeroWalker::_updateGlobalPosInfo()
{
	sGlobal->mapState->positionX = getHeroTilePos().x; 
	sGlobal->mapState->positionY = getHeroTilePos().y;
	sGlobal->mapState->faceDir = _direction;
}
