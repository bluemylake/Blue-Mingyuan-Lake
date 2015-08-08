#ifndef __Gallery_H__
#define __Gallery_H__

#include "cocos2d.h"

#include "SimpleAudioEngine.h"
#include "GpsScene.h"
#include "cocos-ext.h"
#include "CsvUtil.h"
#define GALLERY_CSV_PATH "csv/gallery.csv"
#define GALLERY_CSV_X_COL 0
#define GALLERY_CSV_Y_COL 1

USING_NS_CC_EXT;

class Gallery : public cocos2d::CCLayer,public cocos2d::extension::CCTableViewDelegate,cocos2d::extension::CCTableViewDataSource  
{  
public:  
	// Method 'init' in cocos2d-x returns bool, instead of 'id' in cocos2d-iphone (an object pointer)  
	virtual bool init();  

	// there's no 'id' in cpp, so we recommend to return the class instance pointer  
	static cocos2d::CCScene* scene();  

	// a selector callback  
	void menuCloseCallback(CCObject* pSender);  
	void menu1CallBack(CCObject* pSender);  
	void menu2CallBack(CCObject* pSender);  
	void menu3CallBack(CCObject* pSender);  

	// preprocessor macro for "static create()" constructor ( node() deprecated )  
	CREATE_FUNC(Gallery);  

	virtual void scrollViewDidScroll(CCScrollView* view);
	virtual void scrollViewDidZoom(CCScrollView* view);

	//event
	virtual void tableCellTouched(cocos2d::extension::CCTableView* table, cocos2d::extension::CCTableViewCell* cell);  
	//size
	virtual cocos2d::CCSize cellSizeForTable(cocos2d::extension::CCTableView *table);
	
	virtual cocos2d::extension::CCTableViewCell* tableCellAtIndex(cocos2d::extension::CCTableView *table, unsigned int idx);  
	
	//cell num
	virtual unsigned int numberOfCellsInTableView(cocos2d::extension::CCTableView *table);  
	//
	virtual void tableCellHighlight(cocos2d::extension::CCTableView* table, cocos2d::extension::CCTableViewCell* cell);  
	virtual void tableCellUnhighlight(cocos2d::extension::CCTableView* table, cocos2d::extension::CCTableViewCell* cell);  

	void scrollBar(cocos2d::extension::CCTableView* table);  
	void menu4CallBack(CCObject* pSender);
private:
	void delayedPush();
	int count;
	int menuNum;
	bool menuEnable;
	cocos2d::CCSprite* map2;
	cocos2d::CCSprite* pointImg;
	cocos2d::CCSprite *img;
};  
#endif  // __Gallery_SCENE_H__
