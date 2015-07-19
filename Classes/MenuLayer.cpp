#include "MenuLayer.h"
#include "Map.h"
USING_NS_CC;


CCScene* MenuLayer::scene()
{
    CCScene *scene = CCScene::create();
    MenuLayer *layer = MenuLayer::create();
    scene->addChild(layer);
    return scene;
}


bool MenuLayer::init()
{
    if ( !CCLayer::init() )
        return false;

	sGlobal->load();

	Map* map=Map::create(MAP11_PATH);
	sGlobalRes::instance()->map=map;//@
	WalkingMan* hero=WalkingMan::create();
	sGlobalRes::instance()->hero=hero;//@
	DiaWindow* diawindow=DiaWindow::create();
	diawindow->setControllerListener(hero);
	addChild(diawindow,5);
	sGlobalRes::instance()->diawindow=diawindow;//@
	eManager->load(0);

	map->initNPC();
	map->setGameStartPos();

	map->setTag(MAP);
	this->addChild(map);

	eManager->happen(ccp(62,97),STAND_TRIG);
	eManager->happen(ccp(62,97),A_TRIG);

	//touch×¢²á
	this->setTouchEnabled(true);
	CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this,0,true);

	return true;
}

bool MenuLayer::ccTouchBegan(CCTouch *pTouch,CCEvent *pEvent)
{
	return true;
}

void MenuLayer::ccTouchEnded(CCTouch *pTouch,CCEvent *pEvent)
{
}

void MenuLayer::ccTouchMoved(CCTouch *pTouch,CCEvent *pEvent)
{
}
