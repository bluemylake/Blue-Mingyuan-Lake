#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "AppMacros.h"
#include "GlobalState.h"
#include "ControlPanel.h"
using namespace cocos2d;

//update:20140926.0114

class HelloWorld : public cocos2d::CCLayer
{
public:
    virtual bool init();  
    static cocos2d::CCScene* scene();
    CREATE_FUNC(HelloWorld);

private:
	Map* initMap();
	void initControlPanel(Map* map);
};

#endif // __HELLOWORLD_SCENE_H__
