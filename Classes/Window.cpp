#include "Window.h"

//update:2014-10-1 16:32:15

bool Window::init()
{
	initSprite();
	return true;
}

CCPoint Window::convertCoord(CCNode* obj)
{
	CCSize diff=dialogBox->getContentSize()-obj->getContentSize();
	return CCPoint(diff.width/2,diff.height/2);
}

void Window::respond()
{
}

void Window::load(CCTMXTiledMap* map,CCDictionary *properties)
{
	this->map=map;
	this->properties=properties;
}

void Window::nextMove()
{
}

void Window::respond(int dir)
{
	respond();
}