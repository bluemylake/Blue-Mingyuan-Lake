#ifndef _________Welcome__
#define _________Welcome__

#include "cocos2d.h"
#include "GlobalState.h"
#include "AppMacros.h"
#include "CombatScene.h"
using namespace cocos2d;
//update：2014-10-1 15:59:03

class Welcome : public cocos2d::CCLayer
{
public:
    virtual bool init();
    static cocos2d::CCScene* scene();
    CREATE_FUNC(Welcome);
	void ccTouchesEnded(CCSet* pTouches, CCEvent *pEvent);
protected:
    void menuStartCallback(CCObject* pSender);
	void menuClearCallback(CCObject* pSender);
private:
	int state;
	CCTouch* prevTouch;
	void initView();
};

#endif
