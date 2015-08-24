#ifndef __StoryWorld_SCENE_H__
#define __StoryWorld_SCENE_H__

#include "cocos2d.h"
#include "AppMacros.h"
#include "PlayReader.h"
#include "SimpleAudioEngine.h"
#include "AudioPlayer.h"
#include "Welcome.h"
#include <vector>
using namespace cocos2d;

class StoryWorld : public cocos2d::CCLayer
{
public:
  virtual bool init();
  
  static cocos2d::CCScene* scene();
  
  CREATE_FUNC(StoryWorld);
protected:
  enum allChoice {fChoice = 10, sChoice, tChoice};
  void registerWithTouchDispatcher(void);
  bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
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
  void ccTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
  char current;
  char dialog[512];
  PlayReader reader;
};

#endif // __StoryWorld_SCENE_H__
