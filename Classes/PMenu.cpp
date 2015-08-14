#include "PMenu.h"
#include "GalleryScene.h"
#include "GlobalState.h"
#include "GlobalPath.h"
#include "HelloWorldScene.h"
#include "LoadingScene.h"

bool PMenu::init()
{
	CCMenuItemImage *clear, *staff, *instruction, *backToPMenu;

	//init item
	clear = CCMenuItemImage::create(BUTTON_CLEAR_PATH, BUTTON_CLEARD_PATH,
		this, menu_selector(PMenu::menuClearCallback));
	staff = CCMenuItemImage::create(BUTTON_STAFF_PATH,BUTTON_STAFFD_PATH,
		this,menu_selector(PMenu::menuStaffCallback));
	instruction = CCMenuItemImage::create(BUTTON_INS_PATH,BUTTON_INSD_PATH,
		this,menu_selector(PMenu::menuInstructionCallback));
	backToPMenu = CCMenuItemImage::create(BUTTON_BACK_PATH,BUTTON_BACKD_PATH,
		this,menu_selector(PMenu::menuBackCallback));

	//set menu position
	clear->setPosition(ccp(CCDirector::sharedDirector()->getVisibleSize().width/2,
		CCDirector::sharedDirector()->getVisibleSize().height/2+40));
	staff->setPosition(ccp(clear->getPosition().x,clear->getPosition().y-55));
	instruction->setPosition(ccp(staff->getPosition().x,staff->getPosition().y-55));
	backToPMenu->setPosition(ccp(instruction->getPosition().x,instruction->getPosition().y-55));

	CCArray* arr = CCArray::createWithObject(clear);
	arr->addObject(staff);
	arr->addObject(instruction);
	arr->addObject(backToPMenu);
	this->initWithArray(arr);
	return true;
}

void PMenu::menuClearCallback(CCObject* pSender) 
{
	sGlobal->newr();
}

void PMenu::menuStaffCallback(CCObject* pSender)
{
	CCScene *pScene = Staff::scene();
	CCTransitionFade *scenetrans = CCTransitionFade::create(0.7, pScene);
	CCDirector::sharedDirector()->pushScene(scenetrans);
}

void PMenu::menuInstructionCallback(CCObject* pSender)
{
	CCScene *pScene = HelpScene::scene();
	CCTransitionFade *scenetrans = CCTransitionFade::create(0.7, pScene);
	CCDirector::sharedDirector()->pushScene(scenetrans);
}

void PMenu::menuBackCallback(CCObject* pSender)
{
	this->setVisible(false);
	this->setEnabled(false);

	CCMenu* sMenu=(CCMenu*)this->getParent()->getChildByTag(SMENU);
	sMenu->setVisible(true);
	sMenu->setEnabled(true);
}
