#ifndef _BUTTON_H_
#define _BUTTON_H_
#include "cocos2d.h"
#include "Controller.h"
#include "Hero.h"
using namespace cocos2d;

//2014-9-26 16:00:05

class Button: public Controller,public CCLayer
{
public:
	virtual bool init();
	virtual void initSprite();
	virtual void ccTouchesBegan(CCSet* pTouch, CCEvent *pEvent);
	virtual void ccTouchesEnded(CCSet* pTouch, CCEvent *pEvent);
	virtual void ccTouchesMoved(CCSet* pTouch, CCEvent *pEvent);
	int getDisaDistr();
	CCRect getBoundingBox();
	CCSprite* getSprite();
	CCPoint getTouchPos(CCSet* pTouches);
public:
	CCSprite* buttonImg;
	bool enable;
	int disaDistr;
};
	
#endif