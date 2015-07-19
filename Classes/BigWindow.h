#ifndef __BIG_WINDOW_H__
#define __BIG_WINDOW_H__
#include "cocos2d.h"
#include "Window.h"
using namespace cocos2d;

//update:2014-9-27 14:29:59

class BigWindow:public Window
{
public:
	CREATE_FUNC(BigWindow);
	void initSprite();
	void appear();
	void nextMove();
	void disappear();
	void load(CCTMXTiledMap* map,CCDictionary *properties);
	void respond(CCTMXTiledMap* map,CCDictionary *properties);
};

#endif
