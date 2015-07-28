#include "Particles.h"

bool Particles::init()
{
	mSystem = new CCParticleSystemQuad();
	
	this->addChild(mSystem);
	return true;
}

void Particles::setFireParticle()
{
	mSystem->initWithFile("FireParticle.plist");//plist�ļ�����ͨ�����ӱ༭�����
	mSystem->setTextureWithRect(CCTextureCache::sharedTextureCache()->addImage("particleFire.png")
		,CCRectMake(0,0,64,64));//����ͼƬ����һ�������������ڶ���������ѡ��ͼƬ�ϵ�λ��
	mSystem->setBlendAdditive(true);//������ñز�����
	//mSystem->setPosition(ccp(200,200));//����λ��	
}

void Particles::setWaterParticle()
{
	mSystem->initWithFile("WaterParticle.plist");//plist�ļ�����ͨ�����ӱ༭�����
	mSystem->setTextureWithRect(CCTextureCache::sharedTextureCache()->addImage("particleNapalm.png")
		,CCRectMake(0,0,64,64));//����ͼƬ����һ�������������ڶ���������ѡ��ͼƬ�ϵ�λ��
	mSystem->setBlendAdditive(true);//������ñز�����
	//mSystem->setPosition(ccp(200,200));//����λ��
}

void Particles::setWoodParticle()
{
	mSystem->initWithFile("WoodParticle.plist");//plist�ļ�����ͨ�����ӱ༭�����
	mSystem->setTextureWithRect(CCTextureCache::sharedTextureCache()->addImage("leave.png")
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