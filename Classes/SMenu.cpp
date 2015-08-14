#include "SMenu.h"
#include "HelpScene.h"
#include "StaffScene.h"
#include "GlobalState.h"
#include "GalleryScene.h"
#include "HelloWorldScene.h"
#include "LoadingScene.h"

bool SMenu::init()
{
	CCMenuItemImage *start, *map, *settings, *quitGame;

	//init item
	start = CCMenuItemImage::create(START1_PATH,START2_PATH,
		this,menu_selector(SMenu::menuStartCallback));
	map = CCMenuItemImage::create(MAP1_PATH,MAP2_PATH,
		this,menu_selector(SMenu::menuMapCallback));
	settings = CCMenuItemImage::create(BUTTON_SYS_PATH,BUTTON_SYSD_PATH,
		this,menu_selector(SMenu::menuSetCallback));
	quitGame = CCMenuItemImage::create(BUTTON_QUIT_PATH,BUTTON_QUITD_PATH,
		this,menu_selector(SMenu::menuQuitCallback));

	//set menu position
	start->setPosition(ccp(CCDirector::sharedDirector()->getVisibleSize().width/2,
		CCDirector::sharedDirector()->getVisibleSize().height/2+40));
	map->setPosition(ccp(start->getPosition().x,start->getPosition().y-55));
	settings->setPosition(ccp(map->getPosition().x,map->getPosition().y-55));
	quitGame->setPosition(ccp(settings->getPosition().x,settings->getPosition().y-55));
	
	CCArray* arr = CCArray::createWithObject(start);
	arr->addObject(map);
	arr->addObject(settings);
	arr->addObject(quitGame);
	this->initWithArray(arr);
	return true;
}

void SMenu::menuStartCallback(CCObject* pSender) 
{
	CCEGLView::sharedOpenGLView()->setDesignResolutionSize(MAP_RESOLUWID,MAP_RESOLUHEI, kResolutionExactFit);
	sGlobal->load();

	CCScene* pScene; // = Combat::scene();
	if (CCTextureCache::sharedTextureCache()->textureForKey(VDRAWING_IMG_PATH)==NULL)
		pScene=LoadingScene::scene();
	else
		pScene = HelloWorld::scene();

	CCTransitionFade *scenetrans = CCTransitionFade::create(0.7, pScene);
	CCDirector::sharedDirector()->pushScene(scenetrans);
}

void SMenu::menuMapCallback(CCObject* pSender)
{
	CCEGLView::sharedOpenGLView()->setDesignResolutionSize(MAP_RESOLUWID,MAP_RESOLUHEI, kResolutionExactFit);
	CCScene* pScene=Gallery::scene();
	CCTransitionFade *scenetrans = CCTransitionFade::create(0.7, pScene);
	CCDirector::sharedDirector()->pushScene(scenetrans);
}

void SMenu::menuSetCallback(CCObject* pSender)
{
	this->setVisible(false);
	this->setEnabled(false);

	CCMenu* pMenu=(CCMenu*)this->getParent()->getChildByTag(PMENU);
	pMenu->setVisible(true);
	pMenu->setEnabled(true);
}

void SMenu::menuQuitCallback(CCObject* pSender)
{
	CCDirector::sharedDirector()->popScene();
}
