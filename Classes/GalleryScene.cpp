#include "GalleryScene.h"

USING_NS_CC_EXT;
using namespace cocos2d;

CCScene* Gallery::scene()
{
	CCScene * scene = NULL;
	do 
	{
		// 'scene' is an autorelease object
		scene = CCScene::create();
		CC_BREAK_IF(! scene);

		// 'layer' is an autorelease object
		Gallery *layer = Gallery::create();
		CC_BREAK_IF(! layer);
		//	CCLayerColor *layer2 = CCLayerColor::create(ccc4(222,222,221,90));
		// add layer as a child to scene
		scene->addChild(layer);

	} while (0);

	// return the scene
	return scene;
}

bool Gallery::init()
{
	//////////////////////////////
	// 1. super init first
	if ( !CCLayer::init() )
	{
		return false;
	}
	//set menuNum
	count = 0;
	menuNum = 0;
	menuEnable = false;

	CCSize visibSize=CCDirector::sharedDirector()->getVisibleSize();

	CCTableView *tableView=CCTableView::create(this, CCSizeMake(visibSize.width, visibSize.height));

	tableView->setDirection(kCCScrollViewDirectionVertical);

	tableView->setPosition(CCPointZero);

	// tableView->setAnchorPoint(ccp(0, 0));
	tableView->setDelegate(this);

	tableView->setVerticalFillOrder(kCCTableViewFillTopDown);


	this->addChild(tableView,1);

	tableView->reloadData();

	//this->addChild(map1);

	//选择菜单
	CCSprite* m11 = CCSprite::create("mapinfo/menu1.png");
	CCSprite* m12 = CCSprite::create("mapinfo/menu1_select.png");
	CCSprite* m13 = CCSprite::create("mapinfo/menu1.png");
	CCMenuItemSprite* menu1= CCMenuItemSprite::create(m11,m12,m13,this,menu_selector(Gallery::menu1CallBack));

	CCSprite* m21 = CCSprite::create("mapinfo/menu2.png");
	CCSprite* m22 = CCSprite::create("mapinfo/menu2_select.png");
	CCSprite* m23 = CCSprite::create("mapinfo/menu2.png");
	CCMenuItemSprite* menu2= CCMenuItemSprite::create(m21,m22,m23,this,menu_selector(Gallery::menu2CallBack));
	CCSprite* m31 = CCSprite::create("mapinfo/menu3.png");
	CCSprite* m32 = CCSprite::create("mapinfo/menu3_select.png");
	CCSprite* m33 = CCSprite::create("mapinfo/menu3.png");
	CCMenuItemSprite* menu3= CCMenuItemSprite::create(m31,m32,m33,this,menu_selector(Gallery::menu3CallBack));
	CCMenu* posMenu = CCMenu::create(menu1,menu2,menu3,NULL);
	posMenu->alignItemsHorizontally();
	posMenu->setPosition(ccp(380,40));
	//info
	map2 = CCSprite::create("mapinfo/map.png");
	map2->setAnchorPoint(CCPointZero);
	map2->setPosition(ccp(110,100));
	this->addChild(map2);
	this->addChild(posMenu);
	pointImg = CCSprite::create("mapinfo/point.png");
	pointImg->setPosition(ccp(120,500));
	this->addChild(pointImg,3);

	return true;
}

unsigned int Gallery::numberOfCellsInTableView(CCTableView *table)
{

	return 10;


}

CCTableViewCell* Gallery::tableCellAtIndex(CCTableView *table, unsigned int idx)
{

	CCLOG("%d",idx);
	CCString *nameString=CCString::createWithFormat("mapinfo/icon_%d.png",idx+1);
	CCTableViewCell *cell = table->dequeueCell();

	if (!cell) {

		cell = new CCTableViewCell();

		cell->autorelease();
		CCSprite *bgSprite = CCSprite::create("mapinfo/cell.png");
		bgSprite->setAnchorPoint(CCPointZero);
		bgSprite->setPosition(CCPointZero);
		bgSprite->setTag(789);
		cell->addChild(bgSprite);


		CCSprite *iconSprite = CCSprite::create(nameString->getCString());
		iconSprite->setScale(0.6);
		iconSprite->setAnchorPoint(CCPointZero);
		iconSprite->setPosition(ccp(25, 10));
		iconSprite->setTag(123);
		cell->addChild(iconSprite);



	}
	else
	{

		//创建了就不需要再重新创建了，不然你会发现图片跟文字都不对
		CCTexture2D *aTexture=CCTextureCache::sharedTextureCache()->addImage(nameString->getCString());

		CCSprite *pSprite=(CCSprite *)cell->getChildByTag(123);

		pSprite->setTexture(aTexture);


		//CCLabelTTF *pLabel = (CCLabelTTF*)cell->getChildByTag(456);
		//pLabel->setString(nameString->getCString());



		// this->scrollBar(table);

	}


	return cell;


}


CCSize Gallery::cellSizeForTable(CCTableView *table)
{


	//CCSize visibSize=CCDirector::sharedDirector()->getVisibleSize();

	return CCSizeMake(100, 50);


}

void Gallery::tableCellHighlight(CCTableView *table, CCTableViewCell *cell)
{

	CCLOG("wwww");

	CCTexture2D *aTexture=CCTextureCache::sharedTextureCache()->addImage("mapinfo/cell_selected.png");

	CCSprite *pSprite=(CCSprite *)cell->getChildByTag(789);

	pSprite->setTexture(aTexture);


}

void Gallery::tableCellUnhighlight(CCTableView *table, CCTableViewCell *cell)
{


	CCLOG("dddd");


	CCTexture2D *aTexture=CCTextureCache::sharedTextureCache()->addImage("mapinfo/cell.png");

	CCSprite *pSprite=(CCSprite *)cell->getChildByTag(789);

	pSprite->setTexture(aTexture);



}


void Gallery::tableCellTouched(CCTableView *table, CCTableViewCell *cell)
{

	menuEnable=true;
	CCPoint pos,mapPos;
	mapPos = map2->getPosition();
	switch(cell->getIdx()+1)
	{
	case 1:pos.x=mapPos.x+104;pos.y=mapPos.y+(300-203);break;
	case 2:pos.x=mapPos.x+194;pos.y=mapPos.y+(300-188);break;
	case 3:pos.x=mapPos.x+264;pos.y=mapPos.y+(300-207);break;
	case 4:pos.x=mapPos.x+310;pos.y=mapPos.y+(300-160);break;
	case 5:pos.x=mapPos.x+104;pos.y=mapPos.y+(300-203);break;
	case 6:pos.x=mapPos.x+104;pos.y=mapPos.y+(300-203);break;
	case 7:pos.x=mapPos.x+104;pos.y=mapPos.y+(300-203);break;
	case 8:pos.x=mapPos.x+104;pos.y=mapPos.y+(300-203);break;
	case 9:pos.x=mapPos.x+104;pos.y=mapPos.y+(300-203);break;
	case 10:pos.x=mapPos.x+104;pos.y=mapPos.y+(300-203);break;

	}


	CCMoveTo* moveTo = CCMoveTo::create(1,pos);
	pointImg->runAction(moveTo);
	if (count!=0)
	{
		this->removeChild(img);
		//img->release();
	}

	CCString *nameString=CCString::createWithFormat("mapinfo/img_%d.jpg",cell->getIdx()+1);
	CCLog("cell touched at index: %i", cell->getIdx());
	img = CCSprite::create(nameString->getCString());
	img->setAnchorPoint(CCPointZero);
	img->setPosition(ccp(130,70));
	this->addChild(img);
	if (menuNum==0)
	{
		img->setVisible(false);
	}
	else
	{
		map2->setVisible(false);
	}
	count++;
}
void Gallery::scrollViewDidScroll(CCScrollView* view){

}
void Gallery::scrollViewDidZoom(CCScrollView* view){

}

void Gallery::menu1CallBack(CCObject* pSender){
	CCLOG("menu1");
	if (menuEnable==true)
	{
		pointImg->setVisible(true);
		img->setVisible(false);
		map2->setVisible(true);
		menuNum=0;
	}

}
void Gallery::menu2CallBack(CCObject* pSender){
	CCLOG("menu2");
	if (menuEnable==true)
	{
		pointImg->setVisible(false);
		img->setVisible(true);
		map2->setVisible(false);
		menuNum=1;
	}

}
void Gallery::menu3CallBack(CCObject* pSender){
	CCLOG("menu3");
	CCDirector::sharedDirector()->popScene();
}