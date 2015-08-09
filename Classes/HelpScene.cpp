#include "HelpScene.h"

#define View_Num 6

using namespace cocos2d;
USING_NS_CC_EXT;

CCScene* HelpScene::scene()
{
    CCScene * scene = NULL;
    do 
    {
        // 'scene' is an autorelease object
        scene = CCScene::create();
        CC_BREAK_IF(! scene);

        // 'layer' is an autorelease object
        HelpScene *layer = HelpScene::create();
        CC_BREAK_IF(! layer);

        // add layer as a child to scene
        scene->addChild(layer);
    } while (0);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelpScene::init()
{
       if(!CCLayer::init())
	   {
		   return false;
	   };
	   page = 1;
	   CCSize size = CCDirector::sharedDirector()->getVisibleSize();
	   CCLOG("sizex:%f",size.width);
	   CCSprite *bg = CCSprite::create(STAFF_BG_PATH);
	   bg->setScaleX(2.0f);
	   bg->setAnchorPoint(CCPointZero);
	   bg->setPosition(CCPointZero);
	   this->addChild(bg);

	   // CCScrollView
	   scrollView = CCScrollView::create();
	   CCLayer *layer = CCLayer::create();
	   	   layer->setContentSize(CCSizeMake(672*6, 448));
	   layer->setAnchorPoint(CCPointZero);
	   layer->setPosition(CCPointZero);

	   char helpstr[30] = {0};
	   for (int i=1;i<=View_Num;i++)
	   {
		   sprintf(helpstr,HELP_IMG_PATH,i);
		   CCSprite *sprite = CCSprite::create(helpstr);
		   //sprite->setPosition(ccp(100,100));
		   sprite->setPosition(ccp(size.width*(i-0.5),size.height/2+25));
		   layer->addChild(sprite,10);
	   }
	   
	   scrollView->setPosition(CCPointZero);
	   scrollView->setContentOffset(CCPointZero);
	 
	   scrollView->setContentSize(CCSizeMake(672, 448));
	   scrollView->setViewSize(CCSizeMake(672, 448));
	   scrollView->setContainer(layer);
	   scrollView->setTouchEnabled(false);
	   scrollView->setDelegate(this);
	   scrollView->setDirection(kCCScrollViewDirectionHorizontal);
	   
	   this->addChild(scrollView);

	   CCSpriteFrameCache *cache =  CCSpriteFrameCache::sharedSpriteFrameCache();
   
	   cache->addSpriteFrame(CCSpriteFrame::create("Help/Help_Point01.png",CCRectMake(0,0,32,32)),"Help_Point01.png");
	   cache->addSpriteFrame(CCSpriteFrame::create("Help/Help_Point02.png",CCRectMake(0,0,32,32)),"Help_Point02.png");
	   for (int i=1;i<=View_Num;i++)
	   {
		   CCSprite *point = CCSprite::createWithSpriteFrameName("Help_Point01.png");
		   point->setTag(100+i);
		   point->setPosition(ccp(200+40*i,30));
		   this->addChild(point,0);
	   }
		CCSprite *point = (CCSprite *)this->getChildByTag(101);
		point->setDisplayFrame(cache->spriteFrameByName("Help_Point02.png"));


		CCMenuItemImage *backToWelcome = CCMenuItemImage::create("mapinfo/menu3.png","mapinfo/menu3_select.png",
			this,menu_selector(HelpScene::menuCloseCallback));
		backToWelcome->setPosition(ccp(size.width-70,30));
		CCMenu* menu = CCMenu::create(backToWelcome,NULL);
		menu->setPosition(CCPointZero);
		this->addChild(menu,10);
    return true;
}

void HelpScene::menuCloseCallback(CCObject* pSender)
{
	CCDirector::sharedDirector()->popScene();
}

void HelpScene::scrollViewDidScroll(cocos2d::extension::CCScrollView *view)
{
}

void HelpScene::scrollViewDidZoom(cocos2d::extension::CCScrollView *view)
{
}

void HelpScene::onEnter()
{
	CCLayer::onEnter();
	CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 1, false);
}

void HelpScene::onExit()
{
	CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(this);
	CCLayer::onExit();
}


bool HelpScene::ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
	CCLOG("begin");
	touchPoint = CCDirector::sharedDirector()->convertToGL(pTouch->getLocationInView());
	return true;
}

void HelpScene::ccTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
	
}

void HelpScene::ccTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
		CCLOG("end");
		CCPoint endPoint = CCDirector::sharedDirector()->convertToGL(pTouch->getLocationInView());
		adjustScrollView(endPoint.x-touchPoint.x);
}

void HelpScene::ccTouchCancelled(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
	CCPoint endPoint = CCDirector::sharedDirector()->convertToGL(pTouch->getLocationInView());
	adjustScrollView(endPoint.x-touchPoint.x);
}

void HelpScene::adjustScrollView(float offset)
{
	CCSize size =CCDirector::sharedDirector()->getWinSize();
	 CCSpriteFrameCache *cache =  CCSpriteFrameCache::sharedSpriteFrameCache();
	CCSprite *point = (CCSprite *)this->getChildByTag(100+page);
	point->setDisplayFrame(cache->spriteFrameByName("Help_Point01.png"));
	if (offset<0)
	{
		page ++;
		
	}else
	{
		page --;
	}

	if (page <1)
	{
		page = 1;
	}else if(page > View_Num)
	{
		page =View_Num;
	}

	point = (CCSprite *)this->getChildByTag(100+page);
	point->setDisplayFrame(cache->spriteFrameByName("Help_Point02.png"));

	CCPoint  adjustPos = ccp(-size.width*(page-1),0);
	scrollView->setContentOffset(adjustPos, true);
}