#include "ControlPanel.h"

//last: 2014-9-26 01:34:13
//update£º2014-11-17 18:07:12

bool ControlPanel::init()
{
	setTouchEnabled(true);
	return true;
}

ControlPanel* ControlPanel::create(Map* map)
{
	ControlPanel* panel=ControlPanel::create();
	panel->setMap(map);
	panel->initControllerListeners();
	panel->initControllers();
	return panel;
}

void ControlPanel::setMap(Map* map)
{
	this->map=map;
}

void ControlPanel::ccTouchesBegan(CCSet* pTouch, CCEvent *pEvent)
{
	int distr;
	dirButton->ccTouchesBegan(pTouch,pEvent);
	buttonA->ccTouchesBegan(pTouch,pEvent);
	distr=buttonA->getDisaDistr();
	touchScreen->ccTouchesBegan(pTouch,pEvent);
	int time=BUTTONA/DIRBUTTON;
	dirButton->enable=(((distr%(DIRBUTTON*time))/DIRBUTTON)==0)?true:false;
	buttonA->enable=((distr%(BUTTONA*time)/BUTTONA)==0)?true:false;
}

void ControlPanel::ccTouchesEnded(CCSet* pTouch, CCEvent *pEvent)
{
	dirButton->ccTouchesEnded(pTouch,pEvent);
	buttonA->ccTouchesEnded(pTouch,pEvent);
	touchScreen->ccTouchesEnded(pTouch,pEvent);
}

void ControlPanel::ccTouchesMoved(CCSet* pTouch, CCEvent *pEvent)
{
	dirButton->ccTouchesMoved(pTouch,pEvent);
	buttonA->ccTouchesMoved(pTouch,pEvent);
}

void ControlPanel::initControllerListeners()
{
	//´´½¨Ó¢ÐÛ
	hero=Hero::create();
	hero->gotFocusT();
	rGlobal->hero=hero;//@
	hero->setFaceDirection(hero->dir);
	hero->setPosition(
		ccp(CCDirector::sharedDirector()->getWinSize().width/2,
		CCDirector::sharedDirector()->getWinSize().height/2)-ccp(0,hero->map->getTileSize().height/2));

	PlacenameWindow* rwindow=PlacenameWindow::create();
	rwindow->setPosition(ccp(CCDirector::sharedDirector()->getWinSize().width/2,
		CCDirector::sharedDirector()->getWinSize().height/2));
	rGlobal->rwindow=rwindow;
	this->addChild(rwindow,11);

	//bigwindow=BigWindow::create();
	//this->setTag(BIGWINDOW);this->addChild(bigwindow,11);
	bigwindow=NULL;

	diawindow=DiaWindow::create();
	rGlobal->diawindow=diawindow;
	this->setTag(DIAWINDOW);this->addChild(diawindow,11);
}

void ControlPanel::initControllers()
{
	this->dirButton=DirButton::create();
	dirButton->setPosition(ccp(dirButton->buttonImg->getContentSize().width/2,
		dirButton->buttonImg->getContentSize().height/2));
	dirButton->setControllerListener(hero);
	dirButton->setTag(DIRBUTTON);this->addChild(dirButton);

	this->buttonA=ButtonA::create();
	buttonA->setPosition(ccp(CCDirector::sharedDirector()->getWinSize().width-
		buttonA->buttonImg->getContentSize().width,
		buttonA->buttonImg->getContentSize().height));
	buttonA->setPointers(hero,diawindow,bigwindow);
	buttonA->setTag(BUTTONA);this->addChild(buttonA);

	this->touchScreen=TouchScreen::create();
	touchScreen->setPointers(hero,buttonA,dirButton);
	touchScreen->setTag(TOUCHSCREEN);this->addChild(touchScreen);

	Menu* menu=Menu::create();
	menu->setHero(hero);
	this->addChild(menu);
}
