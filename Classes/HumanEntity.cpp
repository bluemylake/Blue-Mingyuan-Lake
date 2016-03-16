#include "HumanEntity.h"

const int HumanEntity::MAN_WIDTH = 32;
const int HumanEntity::MAN_HEIGHT = 48;

void HumanEntity::setFaceDirection(int dirc)
{
	if(dirc>Up)dirc = Down;
	sprite->setTextureRect(CCRectMake(0,48*dirc,32,48));
}

void HumanEntity::initSprite()
{
	string path = MAN_IMG_PATH;
	IntToAddrForPNG(path, MAN_PATH_LEN, picNo);
	CCTexture2D* HumanEntityTexture = CCTextureCache::
		sharedTextureCache()->addImage( path );
	
	const int downStatic = 0;//macro
	sprite = CCSprite::createWithTexture(HumanEntityTexture);
	sprite->setTextureRect( //Use first rect
			CCRectMake(0, MAN_WIDTH * downStatic, MAN_WIDTH, MAN_HEIGHT));
	sprite->setTag(IMGSP);
	addChild(sprite);
}

void HumanEntity::setID(int id)
{
	this->id = id;
}




void HumanEntity::IntToAddrForPNG(char addr[], int len, int n)
{
    if(n<0||n>PIC_MAX) CCLog("Invalid picNo '%d'! ",n);
	if(n>9) addr[len++] = n/10+'0';
	addr[len++] = n%10+'0'; addr[len++] = '.';
	addr[len++] = 'p'; addr[len++] = 'n';
	addr[len++] = 'g'; addr[len++] = '\0';
}

void HumanEntity::goWalking(float dt)
{
}

void HumanEntity::respond(int dir)
{
}
