#ifndef _________Welcome__
#define _________Welcome__

#include "cocos2d.h"
#include "GlobalState.h"
#include "AppMacros.h"
#include "CombatScene.h"
#include "cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT; 


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
	void menuMapCallback(CCObject* pSender);
	void menuSetCallback(CCObject* pSender);
	void menuStaffCallback(CCObject* pSender);
	void menuBackCallback(CCObject* pSender);
	void menuQuitCallback(CCObject* pSender);
	void menuInstructionCallback(CCObject* pSender);

private:
	int state;
	CCTouch* prevTouch;
	CCScene *pScene;
	CCMenuItemImage *settings;
	CCMenuItemImage *start;
	CCMenuItemImage *map;
	CCMenuItemImage *quitGame;

	CCMenuItemImage *clear;
	CCMenuItemImage *backToWelcome;
	CCMenuItemImage *staff;
	CCMenuItemImage *instruction;
	CCMenu* pMenu ;
	CCMenu* sMenu;
	CCSprite* staffName;

	void initView();
	

};

#endif
