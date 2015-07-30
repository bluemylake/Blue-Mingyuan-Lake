#include "CombatAnimation.h"

void CombatAnimation::fireParticle(int direction)
{
	CCParticleSystemQuad *m_emitter=new CCParticleSystemQuad();
	m_emitter->initWithTotalParticles(40);//900个粒子对象
	//设置图片
	m_emitter->setTexture(CCTextureCache::sharedTextureCache()->addImage("particleFire.png"));
	//设置发射粒子的持续时间-1表示一直发射，0没有意义，其他值表示持续时间
	m_emitter->setDuration(3);



	/*
	//设置中心方向,这个店是相对发射点，x正方向为右，y正方向为上
	m_emitter->setGravity(CCPoint(0,-240));


	//设置角度，角度的变化率
	m_emitter->setAngle(90);
	m_emitter->setAngleVar(360);


	//设置径向加速度，径向加速度的变化率
	m_emitter->setRadialAccel(50);
	m_emitter->setRadialAccelVar(0);

	//设置粒子的切向加速度，切向加速度的变化率
	m_emitter->setTangentialAccel(30);
	m_emitter->setTangentialAccelVar(0);


	//设置粒子的位置，位置的变化率
	m_emitter->setPosition(CCPoint(400,500));
	m_emitter->setPosVar(CCPoint(400,0));

	//设置粒子声明，生命的变化率
	m_emitter->setLife(4);
	m_emitter->setLifeVar(2);


	//设置粒子开始的自旋转速度，开始自旋转速度的变化率
	m_emitter->setStartSpin(30);
	m_emitter->setStartSpinVar(60);

	//设置结束的时候的自旋转以及自旋转的变化率
	m_emitter->setEndSpin(60);
	m_emitter->setEndSpinVar(60);

	ccColor4F cc;
	cc.a=1.0f;
	cc.b=255.0f;
	cc.g=255.0f;
	cc.r=255.0f;
	ccColor4F cc2;
	cc2.a=0;
	cc2.b=0;
	cc2.g=0;
	cc2.r=0;
	//设置开始的时候的颜色以及颜色的变化率
	m_emitter->setStartColor(cc);
	m_emitter->setStartColorVar(cc2);



	//设置结束的时候的颜色以及颜色的变化率
	m_emitter->setEndColor(cc);
	m_emitter->setEndColorVar(cc2);

	//设置开始时候粒子的大小，以及大小的变化率
	m_emitter->setStartSize(30);
	m_emitter->setStartSizeVar(0);


	//设置粒子结束的时候的大小，以及大小的变化率
	m_emitter->setEndSize(20.0f);
	m_emitter->setEndSizeVar(0);

	//设置每秒钟产生粒子的数目
	m_emitter->setEmissionRate(100);

	*/

	this->addChild(m_emitter);
}