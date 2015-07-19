
#include "Ability.h"
using namespace cocos2d;

bool Ability::init()
{
	//CsvUtil::sharedCsvUtil()->loadFile(A_CSV_PATH);
	return true;
}

Ability* Ability::create(int type,int hurt,int stability,int lvlBuff,int hitRate,CCString description,int giveHurtActID,int receiveHurtActID)
{
	Ability *abl = Ability::create();
	abl->type = type;
	abl->hurt = hurt;
	abl->stability = stability;
	abl->lvlBuff = lvlBuff;
	abl->hitRate = hitRate;
	abl->description = description;
	abl->giveHurtActID = giveHurtActID;
	abl->recvHurtActID = receiveHurtActID;
	return abl;
}

