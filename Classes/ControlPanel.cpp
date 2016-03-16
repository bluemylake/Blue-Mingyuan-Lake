#include "ControlPanel.h"
#include "InitUtil.h"

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
	panel->initNightBg();
	return panel;
}

void ControlPanel::setMap(Map* map)
{
	this->map=map;
}

void ControlPanel::ccTouchesBegan(CCSet* pTouches, CCEvent *pEvent)
{
	int distr;
	Menu* menu=(Menu*)this->getChildByTag(MENU);
	menu->ret(NULL);

	dirButton->ccTouchesBegan(pTouches,pEvent);
	CCTouch* pTouch=(CCTouch*)pTouches->anyObject();
	buttonA->ccTouchBegan(pTouch,pEvent);

	distr=buttonA->getDisaDistr();
	touchScreen->ccTouchesBegan(pTouches,pEvent);
	int time=BUTTONA/DIRBUTTON;
	dirButton->enable=(((distr%(DIRBUTTON*time))/DIRBUTTON)==0)?true:false;
	buttonA->enable=((distr%(BUTTONA*time)/BUTTONA)==0)?true:false;
}

void ControlPanel::ccTouchesEnded(CCSet* pTouches, CCEvent *pEvent)
{
	dirButton->ccTouchesEnded(pTouches,pEvent);
	CCTouch* pTouch=(CCTouch*)pTouches->anyObject();
	buttonA->ccTouchEnded(pTouch,pEvent);
	touchScreen->ccTouchesEnded(pTouches,pEvent);
}

void ControlPanel::ccTouchesMoved(CCSet* pTouch, CCEvent *pEvent)
{
	dirButton->ccTouchesMoved(pTouch,pEvent);
	buttonA->ccTouchesMoved(pTouch,pEvent);
}

void ControlPanel::initControllerListeners()
{
	hero = Hero::create();
	rGlobal->hero = hero;
	hero->setFaceDirection(hero->dir);
	hero->setPosition(
		ccp(CCDirector::sharedDirector()->getWinSize().width/2,
		CCDirector::sharedDirector()->getWinSize().height/2)-
		ccp(0,rGlobal->map->getTileSize().height/2));

	PlacenameWindow* rwindow = PlacenameWindow::create();
	rwindow->setPosition(ccp(CCDirector::sharedDirector()->getWinSize().width/2,
		CCDirector::sharedDirector()->getWinSize().height/2));
	rGlobal->rwindow = rwindow;
	this->addChild(rwindow,WIN_ON_PANEL_ZOR);

	//bigwindow=BigWindow::create();
	//this->setTag(BIGWINDOW);this->addChild(bigwindow,11);
	bigwindow = NULL;

	diawindow = DiaWindow::create();
	rGlobal->diawindow = diawindow;
	this->setTag(DIAWINDOW); this->addChild(diawindow,WIN_ON_PANEL_ZOR);
}

void ControlPanel::initControllers()
{
	this->dirButton = DirButton::create();
	dirButton->setPosition(ccp(dirButton->buttonImg->getContentSize().width/2,
		dirButton->buttonImg->getContentSize().height/2));
	dirButton->setControllerListener( heroWalker );
	dirButton->setTag(DIRBUTTON); this->addChild(dirButton, BTN_ON_PANEL_ZOR);

	this->buttonA = ButtonA::create();
	buttonA->setPosition(ccp(CCDirector::sharedDirector()->getWinSize().width-
		buttonA->buttonImg->getContentSize().width,
		buttonA->buttonImg->getContentSize().height*2));
	buttonA->setPointers(heroWalker, diawindow, bigwindow);
	buttonA->setTag(BUTTONA); this->addChild(buttonA, BTN_ON_PANEL_ZOR);

	this->touchScreen = TouchScreen::create();
	touchScreen->setPointers(heroWalker, buttonA, dirButton);
	touchScreen->setTag(TOUCHSCREEN);
	this->addChild(touchScreen, BTN_ON_PANEL_ZOR);

	Menu* menu = Menu::create();
	menu->setHero(hero);
	menu->setTag(MENU);
	this->addChild(menu, BTN_ON_PANEL_ZOR);
}

void ControlPanel::initNightBg()
{
	//the Night is Dark
	CCSprite* nightBg = CCSprite::create(NIGHTBG_IMG_PATH);
	rGlobal->nightBg = nightBg;
	nightBg->setPosition(ccp(nightBg->getContentSize().width / 2, nightBg->getContentSize().height / 2));
	nightBg->setOpacity(0);
	this->addChild(nightBg,NIGHT_ON_PANEL_ZOR);

	CCSprite* murkBg = CCSprite::create(MURKBG_IMG_PATH);
	rGlobal->murkBg = murkBg;
	murkBg->setPosition(ccp(murkBg->getContentSize().width / 2, murkBg->getContentSize().height / 2));
	this->addChild(murkBg,MURK_ON_PANEL_ZOR);

	InitUtil::initiate();
}
