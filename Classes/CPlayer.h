#ifndef __CPLAYER_H__
#define __CPLAYER_H__
#include "Role.h"

using namespace cocos2d;
 
#define PLAYER "player.png"

class CPlayer:public Role
{
public:
	CREATE_FUNC(CPlayer);
public:
	virtual bool init();
	void setPlayer();
	void attack();
private:
	CCSprite* player;
};
#endif 