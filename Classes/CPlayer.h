#ifndef __CPLAYER_H__
#define __CPLAYER_H__
#include "Role.h"
#include "GlobalState.h"

using namespace cocos2d;

class CPlayer:public Role
{
public:
	CREATE_FUNC(CPlayer);
public:
	virtual bool init();
	void setPlayer();
	void attack();
	void exp2Level(int exp);
private:
	CCSprite* player;
};
#endif 
