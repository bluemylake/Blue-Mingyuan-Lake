#ifndef __HELP_SCENE_H__
#define __HELP_SCENE_H__

#include "cocos2d.h"
#include "cocos-ext.h"
#include "SimpleAudioEngine.h"
#include "AppMacros.h"
#include "GlobalPath.h"

USING_NS_CC;
USING_NS_CC_EXT;


class HelpScene : public cocos2d::CCLayer ,public CCScrollViewDelegate
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

    // there's no 'id' in cpp, so we recommand to return the exactly class pointer
    static cocos2d::CCScene* scene();
    CREATE_FUNC(HelpScene);
    // a selector callback
    void menuCloseCallback(CCObject* pSender);
public:
	void scrollViewDidScroll(CCScrollView* view);
	void scrollViewDidZoom(CCScrollView* view);
public:
	virtual void onEnter();
	virtual void onExit();

	virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
	virtual void ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent);
	virtual void ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent);
	virtual void ccTouchCancelled(CCTouch *pTouch, CCEvent *pEvent);

private:
	 void adjustScrollView(float offset);
	 CCScrollView *  scrollView;
	 CCPoint touchPoint;
	 int page;
};

#endif  // __HELLOWORLD_SCENE_H__