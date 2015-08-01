#include "GlobalPath.h"
#include "Particles.h"

bool Particles::init()
{
	mSystem = new CCParticleSystemQuad();
	
	this->addChild(mSystem);
	return true;
}

void Particles::setFireParticle()
{
	mSystem->initWithFile(FIRE_PLIST_IMG_PATH);//plist文件可以通过例子编辑器获得
	mSystem->setTextureWithRect(CCTextureCache::sharedTextureCache()->addImage(FIRE_PNG_IMG_PATH)
		,CCRectMake(0,0,64,64));//加载图片，第一个参数是纹理，第二个参数是选择图片上的位置
	mSystem->setBlendAdditive(true);//这个调用必不可少
	//mSystem->setPosition(ccp(200,200));//设置位置	
}

void Particles::setWaterParticle()
{
	mSystem->initWithFile(WATER_PLIST_IMG_PATH);//plist文件可以通过例子编辑器获得
	mSystem->setTextureWithRect(CCTextureCache::sharedTextureCache()->addImage(WATER_PNG_IMG_PATH)
		,CCRectMake(0,0,64,64));//加载图片，第一个参数是纹理，第二个参数是选择图片上的位置
	mSystem->setBlendAdditive(true);//这个调用必不可少
	//mSystem->setPosition(ccp(200,200));//设置位置
}

void Particles::setWoodParticle()
{
	mSystem->initWithFile(WOOD_PLIST_IMG_PATH);//plist文件可以通过例子编辑器获得
	mSystem->setTextureWithRect(CCTextureCache::sharedTextureCache()->addImage(WOOD_PNG_IMG_PATH)
		,CCRectMake(0,0,64,64));//加载图片，第一个参数是纹理，第二个参数是选择图片上的位置
	mSystem->setBlendAdditive(true);//这个调用必不可少
	//mSystem->setPosition(ccp(200,200));//设置位置
}

void Particles::playerAttack()
{
	//mSystem->setAngle(180);
	mSystem->setPosition(ccp(200,240));//设置位置
}

void Particles::monsterAttack()
{
	mSystem->setAngle(180);
	mSystem->setPosition(ccp(470,240));//设置位置
}

void Particles::setParticleDuration(float dt)
{
	mSystem->setDuration(dt);
}
void Particles::setParticleLife(float dt)
{
	mSystem->setLife(dt);
}
