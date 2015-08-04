#ifndef __MENU_H__
#define __MENU_H__
#include "cocos2d.h"
#include "GlobalPath.h"
#include "GlobalRes.h"
#include "GalleryScene.h"
#include "Button.h"
using namespace cocos2d;

class Menu:public CCLayer
{
public:
	CREATE_FUNC(Menu);
	bool init();
	void setHero(Hero* hero);
	void ret(CCObject *sender);
private:
	void save(CCObject *sender);
	void quit(CCObject *sender);
	void show(CCObject* sender);
	void info(CCObject* sender);
public:
	CCMenu* menu;
	CCMenu* menuButton;
	Hero* hero;
};

#endif
