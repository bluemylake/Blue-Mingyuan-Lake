#include "SuperPower.h"

SuperPower::SuperPower()
{
	this->speed=1.0f;
	this->flash=false;
	this->stealth=false;
	this->teleport=false;
	this->surf=false;
}

SuperPower::SuperPower(float sp,bool tl,bool st,bool sf,bool fl)
{
	this->speed=sp,this->teleport=tl,this->stealth=st,this->surf=sf,this->flash=fl;
}