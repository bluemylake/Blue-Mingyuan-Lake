#ifndef __TOUCH_SCREEN_H__
#define __TOUCH_SCREEN_H__

#include "cocos2d.h"
#include "AppMacros.h"
#include "Button.h"
#include "GlobalRes.h"
#include "AnimLib.h"

using namespace cocos2d;

class TouchScreen: public Button
{
public:
	CREATE_FUNC(TouchScreen);
	bool init();
	void ccTouchesBegan(CCSet* pTouch, CCEvent *pEvent);
	void ccTouchesEnded(CCSet* pTouch, CCEvent *pEvent);
	void ccTouchesMoved(CCSet* pTouch, CCEvent *pEvent);	
	void setPointers(Hero* hero,Button* buttonA, Button* dirButton);
private:
	void zoomStroke(CCSet* pTouch, CCEvent *pEvent);
	void teleportTo(CCSet* pTouch, CCEvent *pEvent);
private:
	bool doShrink;
	Hero* hero;
	Button* buttonA;
	Button* dirButton;
};

#endif
