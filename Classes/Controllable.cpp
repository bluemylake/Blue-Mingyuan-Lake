#include "Controllable.h"
#include "Controller.h"

void Controllable::setController( Controller* controller ) {
    this->controller = controller;
    controller->setControllerListener(this);
}

void Controllable::respond(int dir)
{
}

void Controllable::endRespond()
{
}