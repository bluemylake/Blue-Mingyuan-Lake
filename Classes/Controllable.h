#ifndef _Controllable_H_
#define _Controllable_H_

#include "cocos2d.h"
#include "ControllerListener.h"
#include "Entity.h"
using namespace cocos2d;

class Controller;
class Controllable:public ControllerListener {
public:
    void setController(Controller* controller);
	virtual void respond(int dir);
	virtual void endRespond();

protected:
    Controller* controller;
};

#endif