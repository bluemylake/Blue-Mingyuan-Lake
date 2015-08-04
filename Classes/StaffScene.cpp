#include "StaffScene.h"

USING_NS_CC_EXT;
using namespace cocos2d;


CCScene * Staff::scene()
{
	CCScene * scene = NULL;
	do 
	{
		// 'scene' is an autorelease object
		scene = CCScene::create();
		CC_BREAK_IF(! scene);

		// 'layer' is an autorelease object
		Staff *layer = Staff::create();
		CC_BREAK_IF(! layer);
		//	CCLayerColor *layer2 = CCLayerColor::create(ccc4(222,222,221,90));
		// add layer as a child to scene
		scene->addChild(layer);

	} while (0);

	// return the scene
	return scene;
}

bool Staff::init()
{
	//////////////////////////////
	// 1. super init first
	if ( !CCLayer::init() )
	{
		return false;
	}
	//load csv
	CsvUtil::sharedCsvUtil()->loadFile(STAFF_CSV_PATH);
	CCSize visibSize=CCDirector::sharedDirector()->getVisibleSize();
	CCTableView *tableView=CCTableView::create(this, CCSizeMake(visibSize.width, visibSize.height));
	tableView->setDirection(kCCScrollViewDirectionVertical);
	tableView->setPosition(CCPointZero);
	// tableView->setAnchorPoint(ccp(0, 0));
	tableView->setDelegate(this);
	tableView->setVerticalFillOrder(kCCTableViewFillTopDown);
	this->addChild(tableView,1);
	tableView->reloadData();

	CCMenuItemImage *backToWelcome = CCMenuItemImage::create(BUTTONB_PATH,BUTTONBD_PATH,
		this,menu_selector(Staff::menuCloseCallback));
	backToWelcome->setPosition(ccp(672-50,50));
	CCMenu* menu = CCMenu::create(backToWelcome,NULL);
	menu->setPosition(CCPointZero);
	this->addChild(menu,10);

	return true;
}

unsigned int Staff::numberOfCellsInTableView(CCTableView *table)
{
	CCSize csvSize;
	csvSize = CsvUtil::sharedCsvUtil()->getFileRowColNum(STAFF_CSV_PATH);
	CCLOG("row:%d",csvSize.width);
	return csvSize.width;
}

CCTableViewCell* Staff::tableCellAtIndex(CCTableView *table, unsigned int idx)
{

	CCLOG("%d",idx);
	
	const char *nameString;
	nameString = CsvUtil::sharedCsvUtil()->get(idx,0,STAFF_CSV_PATH);

	CCTableViewCell *cell = table->dequeueCell();

	if (!cell) {

		cell = new CCTableViewCell();

		cell->autorelease();
// 		CCSprite *bgSprite = CCSprite::create("cell.png");
// 		bgSprite->setAnchorPoint(CCPointZero);
// 		bgSprite->setPosition(CCPointZero);
// 		bgSprite->setTag(789);
// 		cell->addChild(bgSprite);


// 		CCSprite *iconSprite = CCSprite::create(nameString->getCString());
// 		iconSprite->setScale(0.6);
// 		iconSprite->setAnchorPoint(CCPointZero);
// 		iconSprite->setPosition(ccp(25, 10));
// 		iconSprite->setTag(123);
// 		cell->addChild(iconSprite);
		
		CCLabelTTF *pLabel = CCLabelTTF::create(nameString, "Arial", 30.0);
		pLabel->setPosition(ccp(200, 10));
		pLabel->setTag(456);
		pLabel->setAnchorPoint(CCPointZero);
		cell->addChild(pLabel);
	}
	else
	{

		//创建了就不需要再重新创建了，不然你会发现图片跟文字都不对
		//CCTexture2D *aTexture=CCTextureCache::sharedTextureCache()->addImage(nameString->getCString());

		//CCSprite *pSprite=(CCSprite *)cell->getChildByTag(123);

		//pSprite->setTexture(aTexture);


		CCLabelTTF *pLabel = (CCLabelTTF*)cell->getChildByTag(456);
		pLabel->setString(nameString);


		// this->scrollBar(table);

	}


	return cell;


}


CCSize Staff::cellSizeForTable(CCTableView *table)
{
	CCSize visibSize=CCDirector::sharedDirector()->getVisibleSize();
	return CCSizeMake(visibSize.width, 84);
}

void Staff::tableCellHighlight(CCTableView *table, CCTableViewCell *cell)
{
	CCLOG("wwww");
}

void Staff::tableCellUnhighlight(CCTableView *table, CCTableViewCell *cell)
{
	CCLOG("dddd");
}


void Staff::tableCellTouched(CCTableView *table, CCTableViewCell *cell)
{
CCLog("cell touched at index: %i", cell->getIdx());
}

void Staff::scrollViewDidScroll(CCScrollView* view){

}
void Staff::scrollViewDidZoom(CCScrollView* view){

}
void Staff::menuCloseCallback(CCObject* pSender)
{
	CCDirector::sharedDirector()->popScene();
}