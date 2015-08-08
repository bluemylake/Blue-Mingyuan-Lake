#include "Menu.h"
#include "ButtonA.h"
#include "FileLoadUtil.h"

bool Menu::init()
{
	this->setTouchEnabled(true);
	CCMenuItemImage *sp = CCMenuItemImage::create(MENUSP_IMG_PATH,MENUSP2_IMG_PATH,
		this,menu_selector(Menu::show));
	menuButton=CCMenu::create(sp,NULL);
	menuButton->setOpacity((int)(255*0.6f));
	this->addChild(menuButton);
	const int fontSize=23;
	
	CCArray* lines=FileLoadUtil::sharedFileLoadUtil()->getDataLines(MENU_LABEL_CSV_PATH);
	CCString* firstLine=(CCString*)lines->objectAtIndex(0);
	CCArray* nameList= StringUtil::sharedStrUtil()->split(firstLine->getCString(), ",");
	CCArray* aLabel=CCArray::create();
	for(int i=0;i<nameList->count();i++)
	{
		CCString* str=(CCString*)nameList->objectAtIndex(i);
		aLabel->addObject(CCLabelTTF::create(str->getCString(), "Heiti SC", fontSize));
	}

	CCMenuItemImage *img1=CCMenuItemImage::create(ITEM_IMG_PATH,ITEM2_IMG_PATH,this,menu_selector(Menu::save));
	CCMenuItemImage *img2=CCMenuItemImage::create(ITEM_IMG_PATH,ITEM2_IMG_PATH,this,menu_selector(Menu::quit));
	CCMenuItemImage *img3=CCMenuItemImage::create(ITEM_IMG_PATH,ITEM2_IMG_PATH,this,menu_selector(Menu::ret));
	CCMenuItemImage *img4=CCMenuItemImage::create(ITEM_IMG_PATH,ITEM2_IMG_PATH,this,menu_selector(Menu::info));
	CCArray* aImg=CCArray::create(img4,img1,img2,img3,NULL);
	for(int i=0;i<aLabel->count();i++)
	{
		CCMenuItemImage* img=(CCMenuItemImage*)aImg->objectAtIndex(i);
		CCLabelTTF* label=(CCLabelTTF*)aLabel->objectAtIndex(i);
		label->setPosition(ccp(img->getContentSize().width/2,img->getContentSize().height/2));
		img->addChild(label);
	}

	menu=CCMenu::create(img4,img1,img2,img3,NULL);
	menu->alignItemsVertically();
	menuButton->setPosition(ccp(CCDirector::sharedDirector()->getWinSize().width-
		sp->getContentSize().width/2,CCDirector::sharedDirector()->getWinSize().height-
		sp->getContentSize().height/2));
	menu->setPosition(ccp(CCDirector::sharedDirector()->getWinSize().width-
		sp->getContentSize().width/2,CCDirector::sharedDirector()->getWinSize().height-
		sp->getContentSize().height*aLabel->count()/2));
	this->addChild(menu);
	ret(NULL);
	return true;
}

void Menu::save(CCObject* sender)
{
	sGlobal->save();
	ret(NULL);
	
	//@present diabox to  confirm
	ControllerListener* lst;
	if(sGlobal->isNight)
		lst=eManager->happen(eManager->findEventById(SAVE_SUC_NIGHT_EVT_ID));
	else lst=eManager->happen(eManager->findEventById(SAVE_SUC_DAY_EVT_ID));
	ButtonA* buttonA=(ButtonA*)rGlobal->panel->getChildByTag(BUTTONA);
	if(lst!=NULL) 
	{
		buttonA->setControllerListener(lst);
		buttonA->disableDirButton();
	}
}

void Menu::quit(CCObject* sender)
{
	CCDirector::sharedDirector()->popScene();
}

void Menu::ret(CCObject* sender)
{
	menu->setVisible(false);
	menu->setEnabled(false);
	menuButton->setVisible(true);
	menuButton->setEnabled(true);
}

void Menu::show(CCObject* sender)
{
	menu->setVisible(true);
	menu->setEnabled(true);
	menuButton->setVisible(false);
	menuButton->setEnabled(false);
}

void Menu::setHero(Hero* hero)
{
	this->hero=hero;
}

void Menu::info(CCObject* sender){
	CCScene *pScene = Gallery::scene();
	CCDirector::sharedDirector()->pushScene(pScene);
}
