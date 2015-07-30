#ifndef _PLAYER_STATE_H_
#define _PLAYER_STATE_H_
#include "cocos2d.h"
#include "AppMacros.h"

using namespace cocos2d;

//Record of the state of the game in the memory
//contains pointer to playerState of Player
//and pointer to bagRecord of Backpack
class PlayerState
{
public:
	int exp;
};
#endif
