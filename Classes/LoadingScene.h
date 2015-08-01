#ifndef __LOADING_SCENE_H__
#define __LOADING_SCENE_H__
#include "cocos2d.h"
using namespace cocos2d;

class LoadingScene: public CCLayer
{
public:
	CREATE_FUNC(LoadingScene);
	bool init();
    static CCScene* scene();
	CCArray* fileNames;
private:
	void initTTFs();
	void load();
	void loadedCallBack(CCObject* nothing);

	int haveLoaded;
	CCLabelTTF* ttf;
};
#endif
