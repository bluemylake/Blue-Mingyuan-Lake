#ifndef _WINDOW_H_
#define _WINDOW_H_
#include "cocos2d.h"
#include "ControllerListener.h"
using namespace cocos2d;

//update:2014-10-1 16:30:51

class Window: public CCNode,public ControllerListener
{
public:
	bool init();
	static void IntToAddrForPNG(char addr[],int len,int n);

	virtual void initSprite()=0;
	virtual void respond(int dir);
	virtual void respond();
	virtual void load(CCTMXTiledMap* map,CCDictionary *properties);
	virtual void appear()=0;
	virtual void nextMove();
	virtual void disappear()=0;
protected:
	CCSprite* dialogBox;
	CCSprite* picture;
	CCLabelTTF* label;
	CCLabelTTF* content;
	CCTMXTiledMap* map;
	CCDictionary *properties;
public:
	CCPoint convertCoord(CCNode* obj);
};

#endif
