#ifndef __WALKING_MAN_H__
#define __WALKING_MAN_H__
#include "cocos2d.h"
#include "HumanEntity.h"
#include "Controller.h"
#include "GlobalRes.h"
#include "VectorLoader.h"
using namespace cocos2d;
#define STD_WALK_DURATION 0.32f

class WalkingMan:public HumanEntity
{
public:
    CREATE_FUNC(WalkingMan);
    static WalkingMan* create(int picNo,int id);
    void respond(int dir);
    void endRespond();
    void setRoute(std::vector<CCPoint> route);
    void walk(CCArray* theRoute);
protected:
    bool init();
    void initAnimation();
    virtual CCAnimation* createAnimationForDirection(int dirc);
    CCActionInterval* initAnim(std::vector<CCPoint> route);
    virtual void goWalking(float dt);
    FaceDirection getDirection(CCPoint vect);
    void beforeStep();
    void go();
    void afterStep();
public:
    CCFiniteTimeAction* forever;
    CCFiniteTimeAction* manWalk;
    cocos2d::CCAnimation** walkAnimations;
    std::vector<CCPoint> route;
    bool isWalking;
    int cnt;
};
#endif
