#ifndef __PLACENAME_WINDOW_H__
#define __PLACENAME_WINDOW_H__
#include "cocos2d.h"
#include "Window.h"
using namespace cocos2d;

//update:2014-9-26 17:36:10

class PlacenameWindow:public Window
{
public:
	CREATE_FUNC(PlacenameWindow);
	void initSprite();
	void load(CCTMXTiledMap* map,CCDictionary *properties);
	void respond(int curPlaceID);
	void appear();
	void nextMove();
	void disappear();
public:
	int prevPlaceID;
};

#endif
