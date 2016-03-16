#ifndef _HUMAN_ENTITY_H_
#define _HUMAN_ENTITY_H_
#include "cocos2d.h"
#include "Entity.h"
#include "ControllerListener.h"
#include "AppMacros.h"
#define PIC_MAX 110
using namespace cocos2d;

//All Human has an ID
//All Human knows the direction it's facing
//HumanEntity is an Entity with a sprite
//The sprite holds a large texture, showing only a part
//Human Entity can init its sprite
class HumanEntity : public Entity, public ControllerListener
{
public:
	virtual void initSprite();
	virtual void setFaceDirection(int dir);
	virtual void goWalking(float dt);
	virtual void respond(int dir);
	void setID(int id);
	static void IntToAddrForPNG(char addr[],int len,int n);
public:
	int id;
	int dir;
	const int MAN_WIDTH;
	const int MAN_HEIGHT;
};

//初始化id
//自动initSprite和Animation和Anim
//goWalking定义了NPC的正常（初始）运动状态
//picNo决定用哪张图

#endif
