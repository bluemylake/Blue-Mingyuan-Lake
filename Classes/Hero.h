#ifndef __HERO_H__
#define __HERO_H__
#include "Map.h"
#include "BigWindow.h"
#include "PlacenameWindow.h"
#include "Story.h"
#include "AppMacros.h"

//respond to call from dirButton
//provide interface for collision and event dealing for other means of transport
//remember to set move by calling initAction(dir) afterwards
class Hero : public WalkingMan
{
public:
    CREATE_FUNC(Hero);
    void gotFocusT();

    void respond(int dir);
    void endRespond();

    CollisionType checkCollision(CCPoint tileCoord);
    void stepDown();
    CCPoint getHeroTilePos();
public:
    Map* map;
    CCPoint move;
private:
    bool init();
    void initAction(int dir);
    void letsGo(float dt);
    void stepUp();
    void walkEnd();
    CollisionType checkEvent(CCPoint tileCoord);
    void doEvent(CCPoint heroPosition);
    cocos2d::CCAction* moveMap;
    cocos2d::CCAction* moveLegs;
    int touchEnded;
    bool focus;
};
#endif
