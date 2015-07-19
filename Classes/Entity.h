#ifndef _Entity_H_
#define _Entity_H_

#include "cocos2d.h"
using namespace cocos2d;

//Entity is a class of object that is represented by a certain picture
//it contains a sprite
class Entity: public CCNode
{
public:
    virtual void initSprite();
protected:
    CCSprite* sprite;
    int picNo;
};
//picNo decides the picture choice for an object
#endif
