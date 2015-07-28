#include "CombatAnimation.h"

void CombatAnimation::fireParticle(int direction)
{
	CCParticleSystemQuad *m_emitter=new CCParticleSystemQuad();
	m_emitter->initWithTotalParticles(40);//900�����Ӷ���
	//����ͼƬ
	m_emitter->setTexture(CCTextureCache::sharedTextureCache()->addImage("particleFire.png"));
	//���÷������ӵĳ���ʱ��-1��ʾһֱ���䣬0û�����壬����ֵ��ʾ����ʱ��
	m_emitter->setDuration(3);



	/*
	//�������ķ���,���������Է���㣬x������Ϊ�ң�y������Ϊ��
	m_emitter->setGravity(CCPoint(0,-240));


	//���ýǶȣ��Ƕȵı仯��
	m_emitter->setAngle(90);
	m_emitter->setAngleVar(360);


	//���þ�����ٶȣ�������ٶȵı仯��
	m_emitter->setRadialAccel(50);
	m_emitter->setRadialAccelVar(0);

	//�������ӵ�������ٶȣ�������ٶȵı仯��
	m_emitter->setTangentialAccel(30);
	m_emitter->setTangentialAccelVar(0);


	//�������ӵ�λ�ã�λ�õı仯��
	m_emitter->setPosition(CCPoint(400,500));
	m_emitter->setPosVar(CCPoint(400,0));

	//�������������������ı仯��
	m_emitter->setLife(4);
	m_emitter->setLifeVar(2);


	//�������ӿ�ʼ������ת�ٶȣ���ʼ����ת�ٶȵı仯��
	m_emitter->setStartSpin(30);
	m_emitter->setStartSpinVar(60);

	//���ý�����ʱ�������ת�Լ�����ת�ı仯��
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
	//���ÿ�ʼ��ʱ�����ɫ�Լ���ɫ�ı仯��
	m_emitter->setStartColor(cc);
	m_emitter->setStartColorVar(cc2);



	//���ý�����ʱ�����ɫ�Լ���ɫ�ı仯��
	m_emitter->setEndColor(cc);
	m_emitter->setEndColorVar(cc2);

	//���ÿ�ʼʱ�����ӵĴ�С���Լ���С�ı仯��
	m_emitter->setStartSize(30);
	m_emitter->setStartSizeVar(0);


	//�������ӽ�����ʱ��Ĵ�С���Լ���С�ı仯��
	m_emitter->setEndSize(20.0f);
	m_emitter->setEndSizeVar(0);

	//����ÿ���Ӳ������ӵ���Ŀ
	m_emitter->setEmissionRate(100);

	*/

	this->addChild(m_emitter);
}