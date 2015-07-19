#include "SceneChEvent.h"

void SceneChEvent::happen()
{
    CCInteger* intg=(CCInteger*)args->objectAtIndex(SCENE_ID_INDEX);
    int sceneId=intg->getValue();
    CCScene* pScene;
    switch(sceneId)
    {
	case 0:break;
	//create scene according to id
	default:break;
    }
    CCDirector::sharedDirector()->pushScene(pScene);
}
