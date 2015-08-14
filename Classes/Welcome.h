#ifndef _________Welcome__
#define _________Welcome__

#include "cocos2d.h"
#include "GlobalState.h"
#include "AppMacros.h"
#include "CombatScene.h"
#include "cocos-ext.h"
#include "ensRippleNode.h"

USING_NS_CC;
USING_NS_CC_EXT; 
//update：2014-10-1 15:59:03

class Welcome : public cocos2d::CCLayer
{
public:
    virtual bool init();
    static cocos2d::CCScene* scene();
    CREATE_FUNC(Welcome);
	void ccTouchesBegan(CCSet* pTouches, CCEvent *pEvent);
	void ccTouchesMoved(CCSet* pTouches, CCEvent *pEvent);
	void ccTouchesEnded(CCSet* pTouches, CCEvent *pEvent);
private:
	int state;
	CCTouch* prevTouch;
	void initView();
	CCMenu* sMenu, *pMenu;
	ens::CrippleSprite* mainbackground;
};

#endif
