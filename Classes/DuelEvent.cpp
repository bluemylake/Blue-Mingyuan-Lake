#include "DuelEvent.h"

void DuelEvent::happen()
{
	CCScene* pScene = Combat::scene();
	Combat* pLayer = (Combat*)pScene->getChildByTag(COMBATLAYER);
	//pass args(defined in CSV) here 
	CCInteger* intg = (CCInteger*) this->args->lastObject();
	if(intg!=NULL && pLayer!=NULL) 
		pLayer->monsterType = intg->getValue();
	else if(intg==NULL && pLayer!=NULL)
		pLayer->monsterType = 1;
	else
		CCLog("Combat Layer get fail. ");

	CCTransitionFade *scenetrans = CCTransitionFade::create(0.7, pScene);
	CCDirector::sharedDirector()->pushScene(scenetrans);
}
