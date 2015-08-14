#include "Welcome.h"
#include "HelloWorldScene.h"
#include "LoadingScene.h"
#include "SMenu.h"
#include "PMenu.h"
//update：2014-10-1 15:59:03
#define READY_TO_WIRTE 0
#define FIRST_STROKE_DONE 1
#define SEC_STROKE_DONE 2

USING_NS_CC;

CCScene* Welcome::scene() 
{
	CCScene *scene = CCScene::create();
	Welcome *layer = Welcome::create();
	scene->addChild(layer);
	return scene;
}

bool Welcome::init() 
{
	if (!CCLayer::init()) 
		return false;

	this->prevTouch=NULL;
	this->setTouchEnabled(true);
	this->state=0;
	sGlobal->init();

	initView();
	return true;
}

void Welcome::ccTouchesBegan(CCSet* pTouches, CCEvent* pEvent)
{
    CCSetIterator it;
    CCTouch* touch;
	for (it = pTouches->begin(); it != pTouches->end(); it++)
    {
        touch = (CCTouch*)(*it);
        if(!touch) break;
        
        CCPoint location = touch->getLocationInView();
        location = CCDirector::sharedDirector()->convertToGL(location);
		mainbackground->doTouch(location, 512, 12);
    }
}

void Welcome::ccTouchesMoved(CCSet* pTouches, CCEvent* pEvent)
{
    CCSetIterator it;
    CCTouch* touch;
	for (it = pTouches->begin(); it != pTouches->end(); it++)
    {
        touch = (CCTouch*)(*it);
        if(!touch) break;
        
        CCPoint location = touch->getLocationInView();
        location = CCDirector::sharedDirector()->convertToGL(location);
		mainbackground->doTouch(location, 512, 12);
    }
}

void Welcome::ccTouchesEnded(CCSet* pTouches, CCEvent *pEvent)
{
	CCTouch* touch=(CCTouch*)pTouches->anyObject();
	int xnd=touch->getLocation().x,xnu=touch->getStartLocation().x;
	int ynd=touch->getLocation().y,ynu=touch->getStartLocation().y;
	if(state==READY_TO_WIRTE)
	{
		bool pie=xnu>xnd&&ynu>ynd&&(xnu-xnd)>((ynu-ynd)/10);
		if(pie)
		{
			state++;
			CC_SAFE_RELEASE(prevTouch);
			prevTouch=touch;
			CC_SAFE_RETAIN(prevTouch);
			//@display here
		}
	}
	else if(state==FIRST_STROKE_DONE)
	{
		int xpd=prevTouch->getLocation().x,xpu=prevTouch->getStartLocation().x;
		int ypd=prevTouch->getLocation().y,ypu=prevTouch->getStartLocation().y;
		bool shu=ypu>ynu&&ypd<ynd&&xnu>xpu&&xnd>xpd&&abs(xnu-xnd)<((ynu-ynd)/2);
		if(shu)
		{
			state++;
			prevTouch->release();
			prevTouch=touch;
			prevTouch->retain();
			//@display here
		}
		else state=READY_TO_WIRTE;
	}
	else if(state==SEC_STROKE_DONE)
	{
		int xpd=prevTouch->getLocation().x,xpu=prevTouch->getStartLocation().x;
		int ypd=prevTouch->getLocation().y,ypu=prevTouch->getStartLocation().y;
		bool shu=ypu<ynu&&ypd>ynd&&xnu>xpu&&xnd>xpd&&abs(xnu-xnd)<((ynu-ynd)/2);
		if(shu)
		{
			sGlobal->superPower->all=true;
			//CCLog("Chuan! ");
			//@display here
		}
		else state=READY_TO_WIRTE;
		prevTouch->release();
	}
}

void Welcome::initView()
{
	mainbackground = new ens::CrippleSprite();
    mainbackground->autorelease();
	mainbackground->init(GATE_PATH,8);
    mainbackground->scheduleUpdate();
    CCSize winSize=CCDirector::sharedDirector()->getWinSize();
	mainbackground->setPosition(ccp(winSize.width/2,winSize.height/2));
    //CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	//mainbackground->setPosition(ccp(CCDirector::sharedDirector()->getVisibleSize().width/2,
		//CCDirector::sharedDirector()->getVisibleSize().height/2));
	addChild(mainbackground,0);

	CCMenu* sMenu=SMenu::create();
	CCMenu* pMenu=PMenu::create();
	sMenu->setPosition(CCPointZero);
	pMenu->setPosition(CCPointZero);
	addChild(sMenu,2);
	addChild(pMenu,2);
	sMenu->setTag(SMENU);
	pMenu->setTag(PMENU);

	pMenu->setVisible(false);
	pMenu->setEnabled(false);
}
