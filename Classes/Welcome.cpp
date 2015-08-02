#include "Welcome.h"
#include "HelloWorldScene.h"
#include "LoadingScene.h"
//update：2014-10-1 15:59:03

USING_NS_CC;

CCScene* Welcome::scene() {
	CCScene *scene = CCScene::create();
	Welcome *layer = Welcome::create();
	scene->addChild(layer);
	return scene;
}

bool Welcome::init() {
	if (!CCLayer::init()) 
		return false;

	this->prevTouch=NULL;
	this->setTouchEnabled(true);
	this->state=0;

	sGlobal->load();

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


void Welcome::menuStartCallback(CCObject* pSender) {
	CCEGLView::sharedOpenGLView()->setDesignResolutionSize(MAP_RESOLUWID,MAP_RESOLUHEI, kResolutionExactFit);
	//CCScene* pScene = Combat::scene();
	//CCScene *pScene = HelloWorld::scene();
	CCScene* pScene=LoadingScene::scene();
	CCTransitionFade *scenetrans = CCTransitionFade::create(0.7, pScene);
	CCDirector::sharedDirector()->pushScene(scenetrans);
}

void Welcome::menuClearCallback(CCObject* pSender) {
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
	CCMenuItemImage *start = CCMenuItemImage::create(START1_PATH,START2_PATH,
		this,menu_selector(Welcome::menuStartCallback));
	CCMenuItemImage *map = CCMenuItemImage::create(MAP1_PATH,MAP2_PATH,
		this,menu_selector(Welcome::menuMapCallback));
	CCMenuItemImage *clear = CCMenuItemImage::create(BUTTONB_PATH,BUTTONBD_PATH,
		this,menu_selector(Welcome::menuClearCallback));
	start->setPosition(ccp(CCDirector::sharedDirector()->getVisibleSize().width/2,
		CCDirector::sharedDirector()->getVisibleSize().height/2+50));
	map->setPosition(ccp(start->getPosition().x,start->getPosition().y-100));
	CCMenu* pMenu = CCMenu::create(start, clear,map, NULL);
	pMenu->setPosition(CCPointZero);
	addChild(pMenu, 2);
}
