#include "RestorationEvent.h"

void RestorationEvent::happen()
{
    CCInteger* intg=(CCInteger*)args->objectAtIndex(NUM_ATTALT_INDEX);
    PlayerState* player=sGlobal->playerState;
    for(int i=0;i<intg->getValue();i++)
    {
	int index=NUM_ATTALT_INDEX+2*i;
	CCInteger* altIdObj=(CCInteger*)args->objectAtIndex(index);
	int altId=altIdObj->getValue();

	CCInteger* altValueIObj=(CCInteger*)args->objectAtIndex(index+1);
	int altValue=altValueIObj->getValue();
	CCFloat* altValueFObj=(CCFloat*)args->objectAtIndex(index+1);
	float altRatio=altValueFObj->getValue();

	switch(altId)
	{
	    case RESTHP_FIXED_ID:
		player->remainHp+=altValue;
		if(altValue==0)player->remainHp=player->Hp;
		if(player->remainHp>player->Hp)player->remainHp=player->Hp;
		break;
	    /*case RESTMP_FIXED_ID:
		player->remainMp+=altValue;
		if(altValue==0)player->remainMp=player->Mp;
		if(player->remainMp>player->Mp)player->remainMp=player->Mp;
		break;*/
	    case INCRXP_FIXED_ID:
		//player->xp+=altValue;
		break;
	    default:break;
	}
    }
}
//restore by ratio can wait for later versions
