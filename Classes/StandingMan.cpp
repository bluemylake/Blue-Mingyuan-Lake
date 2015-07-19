#include "StandingMan.h"

//update: 20140926.0009
bool StandingMan::init()
{
	dir=0;
	return true;
}

StandingMan* StandingMan::create(int picNo,int id)
{
	StandingMan* man=StandingMan::create();
	man->picNo=picNo;
	man->setID(id);
	man->initSprite();
	return man;
}

void StandingMan::respond(int direction)
{
	setFaceDirection(direction);
}

void StandingMan::endRespond()
{
	goWalking(0);
}




void StandingMan::goWalking(float dt)
{
	setFaceDirection(this->dir);
}
