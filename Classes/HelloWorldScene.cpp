#include "HelloWorldScene.h"
USING_NS_CC;

//last: 20140925.2257
//update: 2014-11-17 18:07:38

CCScene* HelloWorld::scene()
{
	CCScene *scene = CCScene::create();
	HelloWorld *layer = HelloWorld::create();
	layer->setTag(HELLOWORLDLAYER);
	scene->addChild(layer);
	return scene;
}

bool HelloWorld::init()
{
	if ( !CCLayer::init() )
		return false;

	//初始化
	Map* map=initMap();
	initControlPanel(map);

	return true;
}






//初始化英雄和地图
Map* HelloWorld::initMap()
{
	//创建地图
	int mapNo=sGlobal->mapState->mapNo;
	Map* map;
	if(mapNo==MAP11)map=Map::create(MAP11_PATH);//读取地图号map11
	else map=Map::create(MAP12_PATH);//读取地图号map12	
	//@eManager
	sGlobalRes::instance()->map=map;
	eManager->load(0);//@rGlobal->mapState->sTime
	map->initNPC();
	map->setGameStartPos();

	CCLayer* mapLayer=CCLayer::create();
	map->setTag(MAP);
	mapLayer->addChild(map);
	mapLayer->setTag(MAPLAYER);
	this->addChild(mapLayer);
	return map;
}

void HelloWorld::initControlPanel(Map* map)
{
	ControlPanel* panel=ControlPanel::create(map);
	//rGlobal->panel=panel;
	panel->hero->setTag(HERO);
	this->addChild(panel,PANEL_ON_MAPLYR_ZOR);

	if(HERO_COVER_MODE)
		map->addChild(panel->hero,HERO_ON_MAP_ZOR);
	else 
		this->getChildByTag(MAPLAYER)->addChild(panel->hero,HERO_ON_PANEL_ZOR);

	//shadow init
	Hero* hero = panel->hero;
	rGlobal->shadow=NULL;
	if(!sGlobal->mapState->hasSh) return;
	rGlobal->shadow = ShadowingMan::create();
	CCPoint heroPos = hero->getHeroTilePos() + ccp(1, 0);
	CCPoint tPos = map->positionFromTileCoord(heroPos);
	rGlobal->shadow->setPosition(tPos);
	map->addChild(rGlobal->shadow,HERO_ON_MAP_ZOR);
}

