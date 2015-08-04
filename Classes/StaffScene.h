#include "cocos2d.h"
#include "GlobalPath.h"
#include "SimpleAudioEngine.h"
#include "cocos-ext.h"
#include "CsvUtil.h"
#define STAFF_CSV_PATH "csv/staff.csv"
#define GALLERY_CSV_X_COL 0
#define GALLERY_CSV_Y_COL 1

USING_NS_CC_EXT;


class Staff : public cocos2d::CCLayer,public cocos2d::extension::CCTableViewDelegate,cocos2d::extension::CCTableViewDataSource
{
public:
	// Method 'init' in cocos2d-x returns bool, instead of 'id' in cocos2d-iphone (an object pointer)
	virtual bool init();
	// there's no 'id' in cpp, so we recommend to return the class instance pointer
	static cocos2d::CCScene* scene();
	// a selector callback
	void menuCloseCallback(CCObject* pSender);
	// preprocessor macro for "static create()" constructor ( node() deprecated )
	CREATE_FUNC(Staff);
public:
	

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
};