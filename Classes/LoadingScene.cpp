#include "LoadingScene.h"
#include "GlobalPath.h"
#include "HelloWorldScene.h"
#define LOAD CCTextureCache::sharedTextureCache()->addImageAsync
#define CALL_BACK callfuncO_selector(LoadingScene::loadedCallBack)
#define NUM_TO_LOAD 19

bool LoadingScene::init()
{
	haveLoaded=0;
	this->initTTFs();
	this->load();
	return true;
}

CCScene* LoadingScene::scene()
{
	CCScene *scene = CCScene::create();
	LoadingScene* layer = LoadingScene::create();
	scene->addChild(layer);
	return scene;
}




void LoadingScene::initTTFs()
{
	CCSize size=CCDirector::sharedDirector()->getWinSize();
	ttf=CCLabelTTF::create("0%", "Arial", 20); 
	ttf->setPosition(ccp(size.width/3, size.height/2));

	CCLabelTTF *havettf=CCLabelTTF::create("Loading", "Arial", 20);
	havettf->setPosition(ccp(size.width/2*1.2, size.height/2));

	this->addChild(ttf);
	this->addChild(havettf);
}

void LoadingScene::load()
{
	char* bg_num[18]={"000","010","030","100","200","204","300","400","500"
		,"600","700","701","717","725","732","800","900","final"};
	char bg_name[30]="";

	for (int i=0;i<18;i++)
	{
		sprintf(bg_name, BGNAME_IMG_PATH, bg_num[i]);
		LOAD(bg_name,this,CALL_BACK);
		if(i==1) LOAD(VDRAWING_IMG_PATH, this, CALL_BACK);
	}
}

void LoadingScene::loadedCallBack(CCObject* nothing)
{
    haveLoaded++;
    this->runAction(CCDelayTime::create(15)); // ??

    char tmp[10];
    sprintf(tmp, "%d%%",(int)((float)haveLoaded/NUM_TO_LOAD*100));
    ttf->setString(tmp);  

    if (haveLoaded==NUM_TO_LOAD)
    {
        this->removeChild(ttf, true);   
        CCScene *newscne=HelloWorld::scene();
        CCDirector::sharedDirector()->replaceScene(newscne); 
    }
}
