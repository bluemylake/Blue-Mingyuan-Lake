#ifndef _ABILITIES_H_
#define _ABILITIES_H_
#include "cocos2d.h"
#include "CsvUtil.h"
#include "GlobalPath.h"

using namespace cocos2d;

#define COMABL 0
#define SPEABL 1

class HurtAbl
{
public:
	int hurt;
	int type;
};

class BuffAbl
{
public:
	int buffValue;
	float buffRate;
	int buffType;
};

class PeriodicAbl
{
public:
	int cycle;
	int cycStability;
};

class Ability:public CCObject,public HurtAbl,public BuffAbl,public PeriodicAbl
{
public:
	virtual bool init(); 
	CREATE_FUNC(Ability);
	int ID;
	CCString name;
	CCString description;
	int magicPower;
	float hitRate;
	float stability;
	float lvlBuff;
	unsigned char ablType;
	int giveHurtActID;
	int recvHurtActID;

public:
	static Ability* create(int type,int hurt,int stability,int lvlBuff,int hitRate,CCString description,int giveHurtActID,int receiveHurtActID);
};
#endif 