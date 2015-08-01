#include "LoadingScene.h"
#include "GlobalPath.h"
#include "HelloWorldScene.h"
#define LOAD CCTextureCache::sharedTextureCache()->addImageAsync
#define CALL_BACK callfuncO_selector(LoadingScene::loadedCallBack)
#define NUM_TO_LOAD 1

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
	ttf=CCLabelTTF::create("%0", "Arial", 12); 
	ttf->setPosition(ccp(size.width/3, size.height/2));

	CCLabelTTF *havettf=CCLabelTTF::create("Loading", "Arial", 12);
	havettf->setPosition(ccp(size.width/2, size.height/2));

	this->addChild(ttf);
	this->addChild(havettf);
}

void LoadingScene::load()
{
	//for(int i=0;i<fileNames->count();i++)
	//{
		//CCString* str=(CCString*)fileNames->objectAtIndex(i);
		//LOAD(str.getCString(), this, callfuncO_selector(CALL_BACK));
	//}
    LOAD(VDRAWING_IMG_PATH, this, CALL_BACK);
    //LOAD(IMG_PATH_HERE , this, callfuncO_selector(CALL_BACK));
}

void LoadingScene::loadedCallBack(CCObject* nothing)
{
    haveLoaded++;
    this->runAction(CCDelayTime::create(15)); // ??

    char tmp[10];
    sprintf(tmp, "%%%d",(int)((float)haveLoaded/NUM_TO_LOAD*100));
    ttf->setString(tmp);  

    if (haveLoaded==NUM_TO_LOAD)
    {
        this->removeChild(ttf, true);   
        CCScene *newscne=HelloWorld::scene();
        CCDirector::sharedDirector()->replaceScene(newscne); 
    }
}