#include "Welcome.h"
#include "HelloWorldScene.h"
#include "HelpScene.h"
#include "LoadingScene.h"
#include "StaffScene.h"
//update：2014-10-1 15:59:03

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

	initView();
	return true;
}

void Welcome::menuMapCallback(CCObject* pSender)
{
	CCEGLView::sharedOpenGLView()->setDesignResolutionSize(MAP_RESOLUWID,MAP_RESOLUHEI, kResolutionExactFit);
	//CCScene* pScene = Combat::scene();
	//CCScene *pScene = HelloWorld::scene();
	CCScene* pScene=Gallery::scene();
	CCTransitionFade *scenetrans = CCTransitionFade::create(0.7, pScene);
	CCDirector::sharedDirector()->pushScene(scenetrans);
}


void Welcome::menuStartCallback(CCObject* pSender) 
{
	CCEGLView::sharedOpenGLView()->setDesignResolutionSize(MAP_RESOLUWID,MAP_RESOLUHEI, kResolutionExactFit);
	sGlobal->load();
	
	//CCScene* pScene = Combat::scene();
	if (CCTextureCache::sharedTextureCache()->textureForKey(VDRAWING_IMG_PATH)==NULL)
		pScene=LoadingScene::scene();
	else
		pScene = HelloWorld::scene();
	
	CCTransitionFade *scenetrans = CCTransitionFade::create(0.7, pScene);
	CCDirector::sharedDirector()->pushScene(scenetrans);
}

void Welcome::menuClearCallback(CCObject* pSender) 
{
	sGlobal->newr();
	sGlobal->load();
}

void Welcome::ccTouchesEnded(CCSet* pTouches, CCEvent *pEvent)
{
	CCTouch* touch=(CCTouch*)pTouches->anyObject();
	int xnd=touch->getLocation().x,xnu=touch->getStartLocation().x;
	int ynd=touch->getLocation().y,ynu=touch->getStartLocation().y;
	if(state==0)
	{
		bool pie=xnu>xnd&&ynu>ynd&&(xnu-xnd)>((ynu-ynd)/10);
		if(pie)
		{
			state++;
			CC_SAFE_RELEASE(prevTouch);
			prevTouch=touch;
			CC_SAFE_RETAIN(prevTouch);
		}
	}
	else if(state==1)
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
		}
		else state=0;
	}
	else if(state==2)
	{
		int xpd=prevTouch->getLocation().x,xpu=prevTouch->getStartLocation().x;
		int ypd=prevTouch->getLocation().y,ypu=prevTouch->getStartLocation().y;
		bool shu=ypu<ynu&&ypd>ynd&&xnu>xpu&&xnd>xpd&&abs(xnu-xnd)<((ynu-ynd)/2);
		if(shu)
		{
			sGlobal->superPower->all=true;
			CCLog("Chuan! ");
			prevTouch->release();
			return;
		}
		state=0;
		prevTouch->release();
	}
	sGlobal->superPower->all=false;
}

void Welcome::initView()
{
	CCSprite *mainbackground = CCSprite::create(GATE_PATH);
	mainbackground->setPosition(ccp(CCDirector::sharedDirector()->getVisibleSize().width/2,
		CCDirector::sharedDirector()->getVisibleSize().height/2));
	addChild(mainbackground,0);
	//set menu
	start = CCMenuItemImage::create(START1_PATH,START2_PATH,
		this,menu_selector(Welcome::menuStartCallback));
	map = CCMenuItemImage::create(MAP1_PATH,MAP2_PATH,
		this,menu_selector(Welcome::menuMapCallback));
	
	settings = CCMenuItemImage::create(BUTTON_SYS_PATH,BUTTON_SYSD_PATH,
		this,menu_selector(Welcome::menuSetCallback));

	quitGame = CCMenuItemImage::create(BUTTON_QUIT_PATH,BUTTON_QUITD_PATH,
		this,menu_selector(Welcome::menuQuitCallback));

	//set menu position
	start->setPosition(ccp(CCDirector::sharedDirector()->getVisibleSize().width/2,
		CCDirector::sharedDirector()->getVisibleSize().height/2+40));
	map->setPosition(ccp(start->getPosition().x,start->getPosition().y-55));
	settings->setPosition(ccp(map->getPosition().x,map->getPosition().y-55));
	quitGame->setPosition(ccp(settings->getPosition().x,settings->getPosition().y-55));
	//set second choice 
	staff = CCMenuItemImage::create(BUTTON_STAFF_PATH,BUTTON_STAFFD_PATH,
		this,menu_selector(Welcome::menuStaffCallback));
	clear = CCMenuItemImage::create(BUTTON_CLEAR_PATH,BUTTON_CLEARD_PATH,
		this,menu_selector(Welcome::menuClearCallback));
	instruction = CCMenuItemImage::create(BUTTON_INS_PATH,BUTTON_INSD_PATH,
		this,menu_selector(Welcome::menuInstructionCallback));
	backToWelcome = CCMenuItemImage::create(BUTTON_BACK_PATH,BUTTON_BACKD_PATH,
		this,menu_selector(Welcome::menuBackCallback));



	clear->setPosition(ccp(CCDirector::sharedDirector()->getVisibleSize().width/2,
		CCDirector::sharedDirector()->getVisibleSize().height/2+40));
	staff->setPosition(ccp(clear->getPosition().x,clear->getPosition().y-55));
	instruction->setPosition(ccp(staff->getPosition().x,staff->getPosition().y-55));
	backToWelcome->setPosition(ccp(instruction->getPosition().x,instruction->getPosition().y-55));

	pMenu = CCMenu::create(start,map,settings,quitGame,NULL);
	pMenu->setPosition(CCPointZero);
	addChild(pMenu,2);
	sMenu = CCMenu::create(clear,staff,instruction,backToWelcome,NULL);
	sMenu->setPosition(CCPointZero);
	addChild(sMenu, 2);
	sMenu->setVisible(false);
	sMenu->setEnabled(false);
}


void Welcome::menuSetCallback(CCObject* pSender)
{
	pMenu->setVisible(false);
	pMenu->setEnabled(false);
	sMenu->setVisible(true);
	sMenu->setEnabled(true);

}


void Welcome::menuInstructionCallback(CCObject* pSender)
{
	CCScene *pScene = HelpScene::scene();
	CCTransitionFade *scenetrans = CCTransitionFade::create(0.7, pScene);
	CCDirector::sharedDirector()->pushScene(scenetrans);
}


void Welcome::menuStaffCallback(CCObject* pSender)
{
	CCScene *pScene = Staff::scene();
	CCTransitionFade *scenetrans = CCTransitionFade::create(0.7, pScene);
	CCDirector::sharedDirector()->pushScene(scenetrans);
}

void Welcome::menuBackCallback(CCObject* pSender)
{
	pMenu->setVisible(true);
	pMenu->setEnabled(true);
	sMenu->setVisible(false);
	sMenu->setEnabled(false);
}

void Welcome::menuQuitCallback(CCObject* pSender)
{
    CCDirector::sharedDirector()->popScene();
}
