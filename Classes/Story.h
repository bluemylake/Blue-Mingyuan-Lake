#ifndef __StoryWorld_SCENE_H__
#define __StoryWorld_SCENE_H__

#include "cocos2d.h"
#include "AppMacros.h"
#include "PlayReader.h"
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
  void leafletChoiceHandler(CCObject *sender);
  void theFinalChoiceHandler(CCObject *sender);
  void confirmButtonHandler(CCObject *sender);
  void menuLeafletsCloseCallback(CCObject* sender);
  
  void avgGame(void);
  void characterPasterSwitchCase(int code);
  void specialPartSwitchCase(int code);
  void audioSwitchCase(int code);
  
  void saveProcessAndPopOut();
  void gameOverAndBackToWelcome();
  char current;
  char dialog[512];
  PlayReader reader;
};

#endif // __StoryWorld_SCENE_H__
