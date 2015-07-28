#ifndef __PARTICLES_H__
#define __PARTICLES_H__
#include "cocos2d.h"
#include "cocos-ext.h"
using namespace cocos2d;
USING_NS_CC_EXT; 
class Particles:public CCNode
{
public:
	CREATE_FUNC(Particles);
public:
    virtual bool init();
	void setFireParticle();
	void setWaterParticle();
	void setWoodParticle();
	void playerAttack();
	void monsterAttack();
private:
	CCParticleSystemQuad *m_emitter;
	CCParticleSystemQuad* mSystem;
};
#endif 