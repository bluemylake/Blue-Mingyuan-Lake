#ifndef _Controller_H_
#define _Controller_H_

#include "cocos2d.h"
#include "ControllerListener.h"

using namespace cocos2d;

class Controller{
public:
    void setControllerListener(ControllerListener* controllerListener);

protected:
    ControllerListener* controllerListener;
};

#endif