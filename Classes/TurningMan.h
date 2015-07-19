#include "cocos2d.h"
#include "HumanEntity.h"
using namespace cocos2d;

#ifndef __TURNING_MAN_H__
#define __TURNING_MAN_H__
class TurningMan: public HumanEntity
{
public:
	CREATE_FUNC(TurningMan);
	static TurningMan* create(int picNo,int id);
	void respond(int dir);
	void endRespond();
private:
	bool init();
	void initAnim(int dir);
	void goWalking(float dt);
private:
	CCFiniteTimeAction* forever;
};
#endif
