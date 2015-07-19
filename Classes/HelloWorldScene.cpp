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

	//��ʼ��
	Map* map=initMap();
	initControlPanel(map);

	return true;
}






//��ʼ��Ӣ�ۺ͵�ͼ
Map* HelloWorld::initMap()
{
	//������ͼ
	int mapNo=sGlobal->mapState->mapNo;
	Map* map;
	if(mapNo==MAP11)map=Map::create(MAP11_PATH);//��ȡ��ͼ��map11
	else map=Map::create(MAP12_PATH);//��ȡ��ͼ��map12	
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
	this->getChildByTag(MAPLAYER)->addChild(panel->hero,3);
	this->addChild(panel,15);
}

