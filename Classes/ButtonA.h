#ifndef __BUTTONA_H__
#define __BUTTONA_H__
#include "cocos2d.h"
#include "DiaWindow.h"
#include "Button.h"
using namespace cocos2d;

//update:2014-9-26 02:05:34

class ButtonA: public Button
{
public:
	CREATE_FUNC(ButtonA);
	virtual bool init();
	virtual void initSprite();
	bool ccTouchBegan(CCTouch* pTouch, CCEvent *pEvent);
	void ccTouchEnded(CCTouch* pTouch, CCEvent *pEvent);
	void setPointers(Hero* hero,DiaWindow* diawindow,BigWindow* bigwindow);
	void disableDirButton();
public:
	Hero* hero;
	DiaWindow* diawindow;
	BigWindow* bigwindow;
private:
	void enableDirButton();
	void trigEvent();
};

#endif
