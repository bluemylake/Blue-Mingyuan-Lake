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
	mSystem->initWithFile(FIRE_PLIST_IMG_PATH);//plist�ļ�����ͨ�����ӱ༭�����
	mSystem->setTextureWithRect(CCTextureCache::sharedTextureCache()->addImage(FIRE_PNG_IMG_PATH)
		,CCRectMake(0,0,64,64));//����ͼƬ����һ�������������ڶ���������ѡ��ͼƬ�ϵ�λ��
	mSystem->setBlendAdditive(true);//������ñز�����
	//mSystem->setPosition(ccp(200,200));//����λ��	
}

void Particles::setWaterParticle()
{
	mSystem->initWithFile(WATER_PLIST_IMG_PATH);//plist�ļ�����ͨ�����ӱ༭�����
	mSystem->setTextureWithRect(CCTextureCache::sharedTextureCache()->addImage(WATER_PNG_IMG_PATH)
		,CCRectMake(0,0,64,64));//����ͼƬ����һ�������������ڶ���������ѡ��ͼƬ�ϵ�λ��
	mSystem->setBlendAdditive(true);//������ñز�����
	//mSystem->setPosition(ccp(200,200));//����λ��
}

void Particles::setWoodParticle()
{
	mSystem->initWithFile(WOOD_PLIST_IMG_PATH);//plist�ļ�����ͨ�����ӱ༭�����
	mSystem->setTextureWithRect(CCTextureCache::sharedTextureCache()->addImage(WOOD_PNG_IMG_PATH)
		,CCRectMake(0,0,64,64));//����ͼƬ����һ�������������ڶ���������ѡ��ͼƬ�ϵ�λ��
	mSystem->setBlendAdditive(true);//������ñز�����
	//mSystem->setPosition(ccp(200,200));//����λ��
}

void Particles::playerAttack()
{
	//mSystem->setAngle(180);
	mSystem->setPosition(ccp(200,240));//����λ��
}

void Particles::monsterAttack()
{
	mSystem->setAngle(180);
	mSystem->setPosition(ccp(470,240));//����λ��
}

void Particles::setParticleDuration(float dt)
{
	mSystem->setDuration(dt);
}
void Particles::setParticleLife(float dt)
{
	mSystem->setLife(dt);
}
