#include "HumanEntity.h"

//英雄静止朝向
void HumanEntity::setFaceDirection(int dirc)
{
	if(dirc>Up)dirc=Down;
	sprite->setTextureRect(CCRectMake(0,48*dirc,32,48));
}

void HumanEntity::initSprite()
{
	char addr[20]=MAN_IMG_PATH;
	IntToAddrForPNG(addr,MAN_PATH_LEN,picNo);
	CCTexture2D* HumanEntityTexture=CCTextureCache::sharedTextureCache()->addImage(addr);
	
	//人物静止图像设置
	const int downStatic=0;//macro
	sprite=CCSprite::createWithTexture(HumanEntityTexture);
	sprite->setTextureRect(CCRectMake(0,32*downStatic,32,48));//初始静止图片！
	sprite->setTag(IMGSP);
	addChild(sprite);
}

void HumanEntity::setID(int id)
{
	this->id=id;
}




void HumanEntity::IntToAddrForPNG(char addr[],int len,int n)
{
    if(n<0||n>PIC_MAX)CCLog("Invalid picNo '%d'! ",n);
	if(n>9)
	    addr[len++]=n/10+'0';
	addr[len++]=n%10+'0'; addr[len++]='.';
	addr[len++]='p'; addr[len++]='n';
	addr[len++]='g'; addr[len++]='\0';
}

void HumanEntity::goWalking(float dt)
{
}

void HumanEntity::respond(int dir)
{
}
