#include "Map.h"
#include "cocos2d.h"
USING_NS_CC;

Map* Map::create(const char *tmxFile)
{
	Map *pRet = new Map();
	if (pRet->initWithTMXFile(tmxFile))
	{
		pRet->autorelease();
		return pRet;
	}
	CC_SAFE_DELETE(pRet);
	return NULL;
}

void Map::setGameStartPos()
{
	int x,y;
	x=sGlobal->mapState->positionX;
	y=sGlobal->mapState->positionY;

	//设置地图位置
	CCPoint tileBirthPoint=ccp(x,y);
	this->setPosition(humanPosForTileMove(tileBirthPoint));
}

void Map::removeAllChildrenWithCleanup(bool cleanup)
{
	CCTMXTiledMap::removeAllChildrenWithCleanup(cleanup);
}

void Map::initNPC()
{
    NPCs=NPCUtil::initNPC();
    if(NPCs==NULL) CCLog("NPC Loading failed! ");
	//open a new func if necessary for bloody init
	if(sGlobal->mapState->isBloody && sGlobal->isNight)
		this->layerNamed(WATER_MLYR)->setVisible(false);
}

Map* Map::crossMap(CCPoint tileBirthPoint,int mapNo)
{
	if(mapNo==MAP12) //Arriving to the right piece: MAP12
		tileBirthPoint=ccp(2+3,tileBirthPoint.y);
	else
		tileBirthPoint=ccp(this->getMapSize().width-3-3,tileBirthPoint.y);
	sGlobal->mapState->mapNo=mapNo;
	eManager->release();
	if(!sGlobal->isNight)
		eManager->load(mapNo-MAP10,TimeUtil::getWeekDay());
	else eManager->loadNight(mapNo-MAP10);
	this->setPosition(this->humanPosForTileMove(tileBirthPoint));
	initNPC();
	return this;
}

Map::~Map()
{
    NPCs->release();
}

//内部工具函数Tilemap坐标转2dx坐标
CCPoint Map::positionFromTileCoord(CCPoint tileCoord)
{
	CCPoint pos=ccp(((tileCoord.x+0.5)*this->getTileSize().width),((this->getMapSize().height-
		tileCoord.y)*this->getTileSize().height+this->getTileSize().height*3/16));//站在地板中央！
	return pos;
}
//内部工具函数2dx坐标转Tilemap坐标
CCPoint Map::tileCoordFromPosition(CCPoint position)
{
	int x=position.x/this->getTileSize().width;
	int y=(((this->getMapSize().height-1)*this->getTileSize().height)-position.y)/this->getTileSize().height;
	return ccp(x,y);
}
//初始化地图时的转换工具
CCPoint Map::humanPosForTileMove(CCPoint tileCoord)
{
	CCPoint deltaMiddle;
	deltaMiddle.x=(int)(CCDirector::sharedDirector()->getWinSize().width/2/this->getTileSize().width);
	deltaMiddle.y=this->getMapSize().height-(int)(CCDirector::sharedDirector()->getWinSize().height/2/this->getTileSize().height)-1;
	CCPoint position=tileCoord-deltaMiddle;//ccp(7,14);
	return ccp(-position.x*this->getTileSize().width,position.y*this->getTileSize().height);
}
