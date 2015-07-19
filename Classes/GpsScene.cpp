#include "GpsScene.h"
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#include <jni.h>
#include "platform/android/jni/JniHelper.h"
#endif
USING_NS_CC;

CCScene* Gps::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    Gps *layer = Gps::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool Gps::init()
{
    if ( !CCLayer::init() )
    {
        return false;
    }
	//csv文件读取数据
	CsvUtil::sharedCsvUtil()->loadFile("map.csv");


    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();
	//longitude latitude
	longitude = 0;
	latitude = 0;
	pLabel = CCLabelTTF::create("", "Arial", 60);
    pLabel->setPosition(ccp(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - pLabel->getContentSize().height-150));
	pLabel2 = CCLabelTTF::create("", "Arial", 60);
	pLabel2->setPosition(ccp(origin.x + visibleSize.width/2,
		origin.y + visibleSize.height - pLabel2->getContentSize().height-50));
	
	
	this->addChild(pLabel,10);
	this->addChild(pLabel2,10);

	this->schedule(schedule_selector(Gps::updateView),3.0f);

	//加载地图
	wholeMap = CCSprite::create("map/wholemap.png");
	wholeMap->setAnchorPoint(CCPointZero);
	wholeMap->setPosition(CCPointZero);
	this->addChild(wholeMap);
	//加载位置指针
    mapPoint = CCSprite::create("mappoint.png");
	mapPoint->setPosition(ccp(200,150));
	this->addChild(mapPoint,10);
	touchPoint = CCSprite::create("touchpoint.png");
	touchPoint->setPosition(ccp(200,150));
	this->addChild(touchPoint,10);
	
	pLabel3 = CCLabelTTF::create("", "Arial", 40);
	pLabel3->setPosition(ccp(touchPoint->getPosition().x,touchPoint->getPosition().y+80));
	this->addChild(pLabel3,10);

	CCSprite* m1 = CCSprite::create("mapinfo/menu3.png");
	CCSprite* m2 = CCSprite::create("mapinfo/menu3_select.png");
	CCSprite* m3 = CCSprite::create("mapinfo/menu3.png");
	CCMenuItemSprite* menu3= CCMenuItemSprite::create(m1,m2,m3,this,menu_selector(Gps::menu3CallBack));
	CCMenu* returnMenu = CCMenu::create(menu3,NULL);
	returnMenu->alignItemsHorizontally();
	returnMenu->setPosition(ccp(610,420));
	this->addChild(returnMenu);

	//触摸事件
	this->setTouchEnabled(true);

    return true;
}


void Gps::updateView(float dt)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	int num;
	JniMethodInfo minfo;
	bool isHave = JniHelper::getStaticMethodInfo(minfo,"com/xing/game/hello_cocos","getInstance","()Lcom/xing/game/hello_cocos;");
	jobject jobj;//存对象
	if (isHave) {
		//这里的调用getInstance，返回Test类的对象。
		jobj = minfo.env->CallStaticObjectMethod(minfo.classID, minfo.methodID);

		isHave = JniHelper::getMethodInfo(minfo,"com/xing/game/hello_cocos","getLocationJ","()D");
		if (isHave) {
			//调用openWebview, 参数1：Test对象   参数2：方法ID
			longitude = minfo.env->CallDoubleMethod(jobj, minfo.methodID);
		}
		isHave = JniHelper::getMethodInfo(minfo,"com/xing/game/hello_cocos","getLocationW","()D");
		if (isHave) {
			//调用openWebview, 参数1：Test对象   参数2：方法ID
			latitude = minfo.env->CallDoubleMethod(jobj, minfo.methodID);
		}	
	}
	//CCString* str = CCString::createWithFormat("%f",(float)longitude);
	//pLabel->setString(str->getCString());

	/*CCString* str2 = CCString::createWithFormat("%f",(float)latitude);
	pLabel2->setString(str2->getCString());*/
	num = Distance();
	showPoint(num);
#else
	//CCString* str = CCString::createWithFormat("%f",(float)longitude);
	//pLabel->setString(str->getCString());
#endif
	
}

void Gps::showPoint(int num)
{
	CCPoint pointPos;
	pointPos = getpointPos(num);
	CCMoveTo* movTo = CCMoveTo::create(0.2,pointPos);
	mapPoint->runAction(movTo);
	showPosName(num);
}

void Gps::showPosName(int num)
{
	const char* name;
	name = CsvUtil::sharedCsvUtil()->get(num,1,"map.csv");
	pLabel2->setString(name);
}


CCPoint Gps::getpointPos(int num)
{
	CCPoint pos;
	pos.x = CsvUtil::sharedCsvUtil()->getInt(num,4,"map.csv");
	pos.y = CsvUtil::sharedCsvUtil()->getInt(num,5,"map.csv");
	CCLOG("坐标：%d,%d",pos.x,pos.y);
	return pos;
}


int Gps::Distance()
{//算与经纬度确定的点距离最短的点的序号
	int i;
	int num=0;
	double lon,lat;
	double d;
	double mindis=10.0;
	int n=70;
	for (i=0;i<n;i++)
	{
		lat = (double)CsvUtil::sharedCsvUtil()->getFloat(i,2,"map.csv");
		lon = (double)CsvUtil::sharedCsvUtil()->getFloat(i,3,"map.csv");
		d = sqrt((lat-latitude)*(lat-latitude)+(lon-longitude)*(lon-longitude));
		CCLOG("%d,%lf",num,d);

		if (d<mindis)
		{
			mindis = d;
			num = i;
		}
	}
	return num;
}





void Gps::menu3CallBack(CCObject* pSender){
	CsvUtil::sharedCsvUtil()->releaseFile("map.csv");
	CCDirector::sharedDirector()->popScene();
}


//触摸事件
void Gps::ccTouchesEnded(CCSet *pTouches, CCEvent *pEvent)
{
	int num;
	CCTouch* touch = (CCTouch*)pTouches->anyObject();
	CCPoint touchPos = touch->getLocationInView();
	num=touchDistance(touchPos);
	showTouchPoint(num);
}

//得到触摸点距离最短的点
int Gps::touchDistance(CCPoint touchPos)
{
	int i;
	int num=0;
	double mapx,mapy;
	double d;
	double mindis=1000.0;
	int n=70;
	CCPoint pos;
	for (i=0;i<n;i++)
	{
		mapx = (double)CsvUtil::sharedCsvUtil()->getInt(i,4,"map.csv");
		mapy = (double)CsvUtil::sharedCsvUtil()->getInt(i,5,"map.csv");
		d = sqrt((mapx-touchPos.x)*(mapx-touchPos.x)+(mapy-(448-touchPos.y))*(mapy-(448-touchPos.y)));
		//CCLOG("%d,%f",num,d);

		if (d<mindis)
		{
			mindis = d;
			num=i;
		}
	}
	return num;
}

//显示touchpoint
void Gps::showTouchPoint(int num)
{
	CCPoint pointPos;
	pointPos = getpointPos(num);
	CCMoveTo* movTo = CCMoveTo::create(0.2,pointPos);
	touchPoint->runAction(movTo);
	showTouchPosName(num,pointPos);
}

void Gps::showTouchPosName(int num,CCPoint pos)
{
	const char* name;
	name = CsvUtil::sharedCsvUtil()->get(num,1,"map.csv");
	pLabel3->setString(name);
	if (pos.y>300)
		pLabel3->setPosition(ccp(pos.x+30,pos.y));
	else
		pLabel3->setPosition(ccp(pos.x,pos.y+80));
}