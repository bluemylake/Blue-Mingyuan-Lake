#ifndef __StoryWorld_SCENE_H__
#define __StoryWorld_SCENE_H__

#include "cocos2d.h"
#include "AppMacros.h"
#include "PlayReader.h"
#include "CombatScene.h"
#include "SimpleAudioEngine.h"
#include "Welcome.h"
#include <vector>

class StoryWorld : public cocos2d::CCLayer
{
public:
    virtual bool init();  

    static cocos2d::CCScene* scene();
    
    CREATE_FUNC(StoryWorld);
protected:
    enum allChoice {fChoice = 10, sChoice, tChoice};
    void menuCloseCallback(CCObject* pSender);
    void ccTouchesEnded(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent);
    void makeAChoice(CCObject *sender);
    void menuLeafletsCloseCallback(CCObject* sender);
    void avgGame(void);
    void saveProcess();
    void over() ;
    char current;
    char dialog[256];
//    char theName[10][11]={"","穆婧:", "子轩:", "少杰:", "建国", "路人A:", "路人B:", "路人C:", "老爷爷:", "江姐:"};
//	char theName[10][11];
	//std::vector<string> theName; 
	PlayReader reader;
//    ProcessSaver saver;
};

#endif // __StoryWorld_SCENE_H__
