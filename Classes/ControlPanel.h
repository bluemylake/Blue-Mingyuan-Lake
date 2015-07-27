#ifndef __CONTROL_PANEL_H__
#define __CONTROL_PANEL_H__

#include "cocos2d.h"
#include "AppMacros.h"
#include "DirButton.h"
#include "ButtonA.h"
#include "TouchScreen.h"
#include "Menu.h"
#include "TimeUtil.h"
using namespace cocos2d;

//update£º2014-9-26 01:33:57

class ControlPanel : public CCLayer
{
public:
	CREATE_FUNC(ControlPanel);
	static ControlPanel* create(Map* map);
	bool init();
	void ccTouchesBegan(CCSet* pTouch, CCEvent *pEvent);
	void ccTouchesEnded(CCSet* pTouch, CCEvent *pEvent);
	void ccTouchesMoved(CCSet* pTouch, CCEvent *pEvent);
	void setMap(Map* map);
private:
	void initControllerListeners();
	void initControllers();
	void initNightBg();
public:
	Hero* hero;
	Button* dirButton;
	ButtonA* buttonA;
	TouchScreen* touchScreen;
	Map* map;
	PlacenameWindow* plcnwindow;
	DiaWindow* diawindow;
	BigWindow* bigwindow;
};

#endif
