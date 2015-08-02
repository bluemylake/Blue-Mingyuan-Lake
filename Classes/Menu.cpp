#include "Menu.h"

bool Menu::init()
{
	this->setTouchEnabled(true);
	CCMenuItemImage *sp = CCMenuItemImage::create(MENUSP_IMG_PATH,MENUSP2_IMG_PATH,
		this,menu_selector(Menu::show));
	menuButton=CCMenu::create(sp,NULL);
	menuButton->setOpacity((int)(255*0.6f));
	this->addChild(menuButton);
	const int fontSize=23;
	
	CCLabelTTF *label1 = CCLabelTTF::create("Save", "Heiti SC", fontSize);
	CCLabelTTF *label2 = CCLabelTTF::create("Quit", "Heiti SC", fontSize);
	CCLabelTTF *label3 = CCLabelTTF::create("Back", "Heiti SC", fontSize);
	CCLabelTTF *label4 = CCLabelTTF::create("Info", "Heiti SC", fontSize);
	CCArray* aLabel=CCArray::create(label4,label1,label2,label3,NULL);

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
   //@present diabox to  confirm
   ret(NULL);
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
