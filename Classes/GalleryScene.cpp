#include "GalleryScene.h"

USING_NS_CC_EXT;
using namespace cocos2d;

CCScene* Gallery::scene()
{
	CCScene * scene = NULL;
	do 
	{
		scene = CCScene::create();
		CC_BREAK_IF(! scene);
		Gallery *layer = Gallery::create();
		CC_BREAK_IF(! layer);
		scene->addChild(layer);
	} while (0);
	return scene;
}

bool Gallery::init()
{
	if ( !CCLayer::init() )		return false;
	count = 0, menuNum = 0, menuEnable = false;
	//@
	CsvUtil::sharedCsvUtil()->loadFile(GALLERY_CSV_PATH);

	CCSize visibSize=CCDirector::sharedDirector()->getVisibleSize();

	CCTableView *tableView=CCTableView::create(this, CCSizeMake(visibSize.width, visibSize.height));
	tableView->setDirection(kCCScrollViewDirectionVertical);
	tableView->setPosition(CCPointZero);
	tableView->setDelegate(this);
	tableView->setVerticalFillOrder(kCCTableViewFillTopDown);
	this->addChild(tableView,1);
	tableView->reloadData();

	//选择菜单
	CCSprite* m11 = CCSprite::create("mapinfo/menu1.png");
	CCSprite* m12 = CCSprite::create("mapinfo/menu1_select.png");
	CCSprite* m13 = CCSprite::create("mapinfo/menu1.png");
	CCMenuItemSprite* menu1= CCMenuItemSprite::create(m11,m12,m13,this,menu_selector(Gallery::menu1CallBack));

	CCSprite* m21 = CCSprite::create("mapinfo/menu2.png");
	CCSprite* m22 = CCSprite::create("mapinfo/menu2_select.png");
	CCSprite* m23 = CCSprite::create("mapinfo/menu2.png");
	CCMenuItemSprite* menu2= CCMenuItemSprite::create(m21,m22,m23,this,menu_selector(Gallery::menu2CallBack));
	CCSprite* m41 = CCSprite::create("mapinfo/menu4.png");
	CCSprite* m42 = CCSprite::create("mapinfo/menu4_select.png");
	CCSprite* m43 = CCSprite::create("mapinfo/menu4.png");
	CCMenuItemSprite* menu4= CCMenuItemSprite::create(m41,m42,m43,this,menu_selector(Gallery::menu4CallBack));
	CCSprite* m31 = CCSprite::create("mapinfo/menu3.png");
	CCSprite* m32 = CCSprite::create("mapinfo/menu3_select.png");
	CCSprite* m33 = CCSprite::create("mapinfo/menu3.png");
	CCMenuItemSprite* menu3= CCMenuItemSprite::create(m31,m32,m33,this,menu_selector(Gallery::menu3CallBack));
	CCMenu* posMenu = CCMenu::create(menu1,menu2,menu4,menu3,NULL);
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
	return 35;
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
	CCTexture2D *aTexture=CCTextureCache::sharedTextureCache()->addImage("mapinfo/cell_selected.png");
	CCSprite *pSprite=(CCSprite *)cell->getChildByTag(789);
	pSprite->setTexture(aTexture);
}
void Gallery::tableCellUnhighlight(CCTableView *table, CCTableViewCell *cell)
{
	CCTexture2D *aTexture=CCTextureCache::sharedTextureCache()->addImage("mapinfo/cell.png");
	CCSprite *pSprite=(CCSprite *)cell->getChildByTag(789);
	pSprite->setTexture(aTexture);
}

void Gallery::tableCellTouched(CCTableView *table, CCTableViewCell *cell)
{
	menuEnable=true;
	CCPoint pos,mapPos;
	mapPos = map2->getPosition();
	//@
	pos.x=CsvUtil::sharedCsvUtil()->getFloat(cell->getIdx(),GALLERY_CSV_X_COL,GALLERY_CSV_PATH)/670*550;
	pos.y=CsvUtil::sharedCsvUtil()->getFloat(cell->getIdx(),GALLERY_CSV_Y_COL,GALLERY_CSV_PATH)/446*300;
	pos=pos+mapPos+ccp(5,pointImg->getContentSize().height/2);

	CCMoveTo* moveTo = CCMoveTo::create(0.2,pos);
	pointImg->runAction(moveTo);
	if (count!=0)	this->removeChild(img);

	CCString *nameString=CCString::createWithFormat("mapinfo/img_%d.png",cell->getIdx()+1);
	CCLog("cell touched at index: %i", cell->getIdx());
	img = CCSprite::create(nameString->getCString());
	img->setAnchorPoint(CCPointZero);img->setPosition(ccp(130,70));
	this->addChild(img);
	if (menuNum==0)		img->setVisible(false);
	else		map2->setVisible(false);
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

void Gallery::menu4CallBack(CCObject* pSender){
	CCLOG("menu4");
	map2->setZOrder(100);
	CCSprite* whole=CCSprite::create(WHOLE_MAP_MAP_PATH);
	float scaleX=whole->getContentSize().width/map2->getContentSize().width;
	float scaleY=whole->getContentSize().height/map2->getContentSize().height;
	CCActionInterval* seq=CCSequence::create(
			CCScaleTo::create(0.5f,scaleX,scaleY),
			CCCallFunc::create(this,callfunc_selector(Gallery::delayedPush)),
			NULL);
	CCSpawn* conc=CCSpawn::create(seq,CCMoveTo::create(0.5f,ccp(0,0)),NULL);
	map2->runAction(conc);
}

void Gallery::delayedPush()
{
	CCScene *pScene = Gps::scene();
	CCDirector::sharedDirector()->pushScene(pScene);
	map2->setZOrder(0);
	map2->setScale(1.0f);
	map2->setPosition(ccp(110, 100));
}

void Gallery::menu3CallBack(CCObject* pSender){
	CCLOG("menu3");
	CCDirector::sharedDirector()->popScene();
}
