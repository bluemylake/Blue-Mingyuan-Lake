#include "cocos2d.h"
#include "HumanEntity.h"
using namespace cocos2d;

//update: 20140926.0009
#ifndef __STANDING_MAN_H__
#define __STANDING_MAN_H__
class StandingMan: public HumanEntity
{
public:
	CREATE_FUNC(StandingMan);
	static StandingMan* create(int picNo,int id);
	void respond(int dir);
	void endRespond();
private:
	bool init();
	void goWalking(float dt);
};
#endif
