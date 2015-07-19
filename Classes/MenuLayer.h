#ifndef __MenuLayer_H__
#define __MenuLayer_H__

#include "cocos2d.h"
using namespace cocos2d;

class MenuLayer : public cocos2d::CCLayer
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::CCScene* scene();
    
    // a selector callback
    void menuCloseCallback(CCObject* pSender);
    
    // implement the "static node()" method manually
    CREATE_FUNC(MenuLayer);

	//回调函数，响应交互
	bool ccTouchBegan(CCTouch *pTouch,CCEvent *pEvent);
	void ccTouchEnded(CCTouch *pTouch,CCEvent *pEvent);
	void ccTouchMoved(CCTouch *pTouch,CCEvent *pEcent);
};

#endif // __MenuLayer_H__
