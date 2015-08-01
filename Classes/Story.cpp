#include "Story.h"

USING_NS_CC;
//update: 2015-7-26 13:44:52

CCScene* StoryWorld::scene() {
  CCScene *scene = CCScene::create();
  StoryWorld *layer = StoryWorld::create();
  layer->setTag(1);
  scene->addChild(layer);
  return scene;
}

bool StoryWorld::init() {
  if ( !CCLayer::init() ) {
    return false;
  }
  char theName[10][11]={"","穆婧:", "子轩:", "少杰:", "建国", "路人A:", "路人B:", "路人C:", "老爷爷:", "江姐:"};
  char play[20] = SCRIPT_PATH;
  current=sGlobal->mapState->storyCnt+'0';//stay
  play[SCRIPT_PATH_LEN] = current;
  reader.ReadFileWithFullPath(CCFileUtils::sharedFileUtils()->fullPathForFilename(play));
  this->setTouchEnabled(true);
  CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
  CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();
  CCMenuItemImage *pCloseItem = CCMenuItemImage::create(CLOSEN_IMG_PATH, CLOSES_IMG_PATH, this, menu_selector(StoryWorld::menuCloseCallback));
  
  pCloseItem->setPosition(ccp(origin.x + visibleSize.width - pCloseItem->getContentSize().width/2 , origin.y + pCloseItem->getContentSize().height/2));
  
  CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
  pMenu->setPosition(CCPointZero);
  addChild(pMenu, 2);
  
  char bg_name[30] = "" ;
  char bg_num[4]="";
  sprintf(bg_num, "%c00", current);
  sprintf(bg_name, BGNAME_IMG_PATH, bg_num);
  CCSprite* pBackground = CCSprite::create(bg_name);
  pBackground->setPosition(ccp(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
  pBackground->setScale(1);
  pBackground->setTag(108);
  addChild(pBackground, 0);
  
  CCSprite* dialogBox = CCSprite::create(DUIHUAKUANG_IMG_PATH);
  dialogBox->setPosition(ccp(visibleSize.width/2, dialogBox->getContentSize().height/2));
  dialogBox->setOpacity(220);
  addChild(dialogBox,1);
  
  CCLabelTTF* pName = CCLabelTTF::create(theName[0], "Heiti SC", 40);
  pName->setTag(101);
  pName->setPosition(ccp(pName->getContentSize().width/2, dialogBox->getContentSize().height - 2 * pName->getContentSize().height));
  pName->setAnchorPoint(CCPointZero);
  addChild(pName, 1);
  
  
  CCLabelTTF* pLabel = CCLabelTTF::create("Click to Start", "Heiti SC", 40);
  pLabel->setTag(100);
  pLabel->setPosition(ccp(40, origin.y + dialogBox->getContentSize().height - 3.4 * pLabel->getContentSize().height));
  pLabel->setAnchorPoint(CCPointZero);
  pLabel->setDimensions(CCSizeMake(1100, 0));
  pLabel->setHorizontalAlignment(kCCTextAlignmentLeft);
  addChild(pLabel, 1);
  
  
    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile(PLIST_IMG_PATH);
	CCSpriteBatchNode *spriteBatch = CCSpriteBatchNode::createWithTexture(CCTextureCache::sharedTextureCache()->textureForKey(VDRAWING_IMG_PATH));
  spriteBatch->setTag(102);
  addChild(spriteBatch, 0);
  spriteBatch->setPosition(CCPointZero);
  
  CCSprite *leftSprite=CCSprite::createWithSpriteFrameName("me_1.png");
  leftSprite->setScale(0.8);
  leftSprite->setPosition(ccp(leftSprite->getContentSize().width*0.8, leftSprite->getContentSize().height/2 *0.8));
  leftSprite->setTag(1);
  leftSprite->setOpacity(0);
  spriteBatch->addChild(leftSprite, 0);
  
  CCSprite *rightSprite=CCSprite::createWithSpriteFrameName("blank.png");
  //rightSprite->setScale(0.8);
  rightSprite->setPosition(ccp(800, 130));
  rightSprite->setTag(2);
  rightSprite->setOpacity(0);
  spriteBatch->addChild(rightSprite, 0);
  
  avgGame();
  return true;
}

void StoryWorld::registerWithTouchDispatcher(void)
{
	CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
}

bool StoryWorld::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
	return true;
}

void StoryWorld::ccTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent){
  avgGame();
}

void StoryWorld::avgGame(void) {
  CCLabelTTF* myDialog = (CCLabelTTF *)getChildByTag(100);
  CCLabelTTF* myName = (CCLabelTTF *)getChildByTag(101);
  CCSpriteBatchNode *spriteBatch = (CCSpriteBatchNode *)getChildByTag(102);
  CCSprite *myLeftSprite = (CCSprite *)spriteBatch->getChildByTag(1);
  CCSprite *myRightSprite = (CCSprite *)spriteBatch->getChildByTag(2);
  
  strcpy(dialog, reader.GetNextDialog().c_str());
  
  char theName[10][11]={"","穆婧:", "子轩:", "少杰:", "建国", "路人A:", "路人B:", "路人C:", "老爷爷:", "江姐:"};
  
  myName->setString(theName[dialog[0]-48]);
  characterPasterSwitchCase(dialog[0]);
  
  switch (dialog[2]) {
    case '1': {
      setTouchEnabled(false);
      CCSprite *back = CCSprite::create(LANDSCAPE_IMG_PATH);
      back->setPosition(ccp(CCDirector::sharedDirector()->getVisibleSize().width/2, CCDirector::sharedDirector()->getVisibleSize().height/2));
      back->setOpacity(150);
      back->setTag(3);
      addChild(back, 3);
      switch (current) {
        case '3': {
          CCLabelTTF *Label1 = CCLabelTTF::create("Yes", "Heiti SC", 40);
          CCLabelTTF *Label2 = CCLabelTTF::create("No", "Heiti SC", 40);
          CCMenuItemLabel *firstChoice = CCMenuItemLabel::create(Label1, this, menu_selector(StoryWorld::leafletChoiceHandler));
          CCMenuItemLabel *secondChoice = CCMenuItemLabel::create(Label2, this, menu_selector(StoryWorld::leafletChoiceHandler));
          firstChoice->setTag(fChoice);
          secondChoice->setTag(sChoice);
          firstChoice->setPosition(ccp(CCDirector::sharedDirector()->getVisibleSize().width/2, CCDirector::sharedDirector()->getVisibleSize().height/5 * 4.1));
          secondChoice->setPosition(ccp(CCDirector::sharedDirector()->getVisibleSize().width/2, CCDirector::sharedDirector()->getVisibleSize().height/5 * 2.9));
          CCMenu *menu = CCMenu::create(firstChoice, secondChoice, NULL);
          menu->setPosition(CCPointZero);
          menu->setTag(2);
          addChild(menu, 3);
          return;
        }
          break;
        case '9': {
          CCLabelTTF *Label1 = CCLabelTTF::create("子轩", "Heiti SC", 40);
          CCLabelTTF *Label2 = CCLabelTTF::create("少杰", "Heiti SC", 40);
          CCLabelTTF *Label3 = CCLabelTTF::create("建国", "Heiti SC", 40);
          CCMenuItemLabel *firstChoice = CCMenuItemLabel::create(Label1, this, menu_selector(StoryWorld::theFinalChoiceHandler));
          CCMenuItemLabel *secondChoice = CCMenuItemLabel::create(Label2, this, menu_selector(StoryWorld::theFinalChoiceHandler));
          CCMenuItemLabel *thirdChoice = CCMenuItemLabel::create(Label3, this, menu_selector(StoryWorld::theFinalChoiceHandler));
          
          firstChoice->setTag(fChoice);
          secondChoice->setTag(sChoice);
          thirdChoice->setTag(tChoice);
          
          firstChoice->setPosition(ccp(CCDirector::sharedDirector()->getVisibleSize().width/2, CCDirector::sharedDirector()->getVisibleSize().height/5 * 4.1));
          secondChoice->setPosition(ccp(CCDirector::sharedDirector()->getVisibleSize().width/2, CCDirector::sharedDirector()->getVisibleSize().height/5 * 2.9));
          thirdChoice->setPosition(ccp(CCDirector::sharedDirector()->getVisibleSize().width/2, CCDirector::sharedDirector()->getVisibleSize().height/5 * 1.8));
          
          CCMenu *menu = CCMenu::create(firstChoice, secondChoice, thirdChoice, NULL);
          menu->setPosition(CCPointZero);
          menu->setTag(2);
          addChild(menu, 3);
          return;
        }
          break;
          
        default:
          break;
      }
    }
      break;
    case '2': {
    }
      break;
    case '3': {
      if (myLeftSprite->getOpacity() == 0)
        myLeftSprite->setOpacity(255);
      else
        myLeftSprite->runAction(CCFadeOut::create(1));
    }
      break;
    case '4': {
      if (myRightSprite->getOpacity() == 0)
        myRightSprite->setOpacity(255);
      else
        myRightSprite->runAction(CCFadeOut::create(1));
    }
      break;
    case '5': {
      if (myRightSprite->getOpacity()==0 && myLeftSprite->getOpacity()==0) {
        myLeftSprite->setOpacity(255);
        myRightSprite->setOpacity(255);
      } else if (myRightSprite->getOpacity()!=0 && myLeftSprite->getOpacity()!=0) {
        myLeftSprite->runAction(CCFadeOut::create(1));
        myRightSprite->runAction(CCFadeOut::create(1));
      }
    }
      break;
    default:
      break;
  }
  
  specialPartSwitchCase(dialog[3]);
  
  audioSwitchCase(dialog[4]);

  
  char all_bg[8][4] = {"010", "030", "204", "701", "717", "725", "732"};
  char bg_num[4]="000";
  int curLine = reader.getCurLine();
  sprintf(bg_num, "%c%02d", current, curLine);
  if (curLine == 0) {
    CCSprite *Background = (CCSprite *)getChildByTag(108);
    char bg_name[30]=BGNAME_IMG_PATH;
    bg_name[BGNAME_PATH_LEN] = current;
    Background->setTexture(CCTextureCache::sharedTextureCache()->addImage(bg_name));
  } else {
    for (int i =0; i<8; i++) {
      if (strcmp(all_bg[i], bg_num)==0) {
        CCSprite *Background = (CCSprite *)getChildByTag(108);
        char bg_name[30]="";
        sprintf(bg_name, BGNAME_IMG_PATH, bg_num);
        Background->setTexture(CCTextureCache::sharedTextureCache()->addImage(bg_name));
      }
    }
  }
  
  myDialog->setString(dialog+5);
}

void StoryWorld::characterPasterSwitchCase(int code) {
  CCSpriteBatchNode *spriteBatch = (CCSpriteBatchNode *)getChildByTag(102);
  CCSprite *myLeftSprite = (CCSprite *)spriteBatch->getChildByTag(1);
  CCSprite *myRightSprite = (CCSprite *)spriteBatch->getChildByTag(2);
  
  switch (dialog[0]) {
    case '0': {   //无人
      char b[10]="me_ .png";
      b[3] = dialog[1]+1;
      myLeftSprite->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(b));
    }
      break;
      
    case '1': {   //ME
      char b[10]="me_ .png";
      b[3] = dialog[1]+1;
      myLeftSprite->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(b));
    }
      break;
    case '2': {   //子轩
      char b[10]="zx_ .png";
      b[3] = dialog[1]+1;
      myRightSprite->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(b));
    }
      break;
    case '3': {   //少杰
      char b[10]="sj_ .png";
      b[3] = dialog[1];
      myRightSprite->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(b));
    }
      break;
    case '4': {   //建国
      char b[10]="jg_ .png";
      b[3] = dialog[1];
      myRightSprite->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(b));
    }
      break;
    case '5': {
      char b[10]="la_ .png";
      b[3] = dialog[1];
      myRightSprite->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(b));
    }
      break;
    case '6': {
      char b[10]="lb_ .png";
      b[3] = dialog[1];
      myRightSprite->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(b));
    }
      break;
    case '7': {
      char b[10]="lc_ .png";
      b[3] = dialog[1];
      myRightSprite->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(b));
    }
      break;
    case '8': {
      char b[10]="yy_ .png";
      b[3] = dialog[1];
      myRightSprite->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(b));
    }
      break;
    case '9': {
      char b[10]="jj_ .png";
      b[3] = dialog[1];
      myRightSprite->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(b));
    }
      break;
      
    default:
      break;
  }
}

void StoryWorld::specialPartSwitchCase(int code) {
  switch (code) {
    case '1':{
      setTouchEnabled(false);
      CCSprite *back = CCSprite::create(CONFIRM_BACKGROUND_IMG_PATH);
      back->setPosition(ccp(CCDirector::sharedDirector()->getVisibleSize().width/2, CCDirector::sharedDirector()->getVisibleSize().height/2));
      back->setTag(3);
      addChild(back, 3);

      CCLabelTTF *nextPlaceName = CCLabelTTF::create("", "Heiti SC", 48);
      nextPlaceName->setString(dialog+5);
      nextPlaceName->setPosition(ccp(CCDirector::sharedDirector()->getVisibleSize().width/2, CCDirector::sharedDirector()->getVisibleSize().height/5 * 3.1));
      back->addChild(nextPlaceName);
      
      CCMenuItemImage *confirmBtn = CCMenuItemImage::create(CONFIRM_BUTTOM_IMG_PATH, CONFIRM_BUTTOM_IMG_PATH, this, menu_selector(StoryWorld::confirmButtonHandler));
      confirmBtn->setPosition(ccp(CCDirector::sharedDirector()->getVisibleSize().width/2, CCDirector::sharedDirector()->getVisibleSize().height/5 * 2));
      CCMenu *menu = CCMenu::create(confirmBtn, NULL);
      menu->setPosition(CCPointZero);
      menu->setTag(2);
      addChild(menu, 3);
    }
      break;
    case '2':{    
      CCSprite* staff_bg = CCSprite::create(STAFFBG_IMG_PATH);
      staff_bg->setPosition(ccp(CCDirector::sharedDirector()->getVisibleSize().width/2 + CCDirector::sharedDirector()->getVisibleOrigin().x, CCDirector::sharedDirector()->getVisibleSize().height/2 + CCDirector::sharedDirector()->getVisibleOrigin().y));
      addChild(staff_bg, 4);
      
      CCSprite* staff = CCSprite::create(STAFF_IMG_PATH);
      staff->setPosition(ccp(CCDirector::sharedDirector()->getVisibleSize().width/2, -CCDirector::sharedDirector()->getVisibleSize().height/2));
      addChild(staff, 5);
      
      CCActionInterval * moveTo = CCMoveTo::create(20,ccp(CCDirector::sharedDirector()->getVisibleSize().width/2, CCDirector::sharedDirector()->getVisibleSize().height*3/2));
      CCFiniteTimeAction*  sequneceAction = CCSequence::create(moveTo, CCCallFunc::create(this, callfunc_selector(StoryWorld::gameOverAndBackToWelcome)), NULL);
      
      staff->runAction(sequneceAction);
    }
      break;
    case '3':{
      CCSprite *black = CCSprite::create(BLACK_IMG_PATH);
      black->setPosition(ccp(CCDirector::sharedDirector()->getVisibleSize().width/2, CCDirector::sharedDirector()->getVisibleSize().height/2));
      black->setOpacity(0);
      addChild(black, 4);
      black->runAction(CCSequence::create(CCFadeIn::create(0.5), CCFadeOut::create(0.5), NULL));
    }
      break;
    default:
      break;
  }
}


void StoryWorld::audioSwitchCase(int code) {
  switch (code) {
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':{
      char musicName[7] = " .mp3";
      musicName[0] = dialog[4];
      if (CocosDenshion::SimpleAudioEngine::sharedEngine()->isBackgroundMusicPlaying()) {
        CocosDenshion::SimpleAudioEngine::sharedEngine()->stopBackgroundMusic(true);
      }
      CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic(CCFileUtils::sharedFileUtils()->fullPathForFilename(musicName).c_str());
      CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic(CCFileUtils::sharedFileUtils()->fullPathForFilename(musicName).c_str(), true);
    }
      break;
    case '7': {
      CocosDenshion::SimpleAudioEngine::sharedEngine()->stopBackgroundMusic(true);
    }
      break;
    case '8':
    case '9':
    case 'A':
    case 'B':
    case 'C':
    case 'D':
    case 'G':{
      char effectName[7] = " .wav";
      effectName[0] = dialog[4];
      
      CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadEffect(CCFileUtils::sharedFileUtils()->fullPathForFilename(effectName).c_str());
      CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect(CCFileUtils::sharedFileUtils()->fullPathForFilename(effectName).c_str());
    }
      break;
    case 'E':
    case 'F':
    case 'H':{
      char effectName[7] = " .mp3";
      effectName[0] = dialog[4];
      
      CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadEffect(CCFileUtils::sharedFileUtils()->fullPathForFilename(effectName).c_str());
      CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect(CCFileUtils::sharedFileUtils()->fullPathForFilename(effectName).c_str());
    }
      break;
      
    default:
      break;
  }
}

//
void StoryWorld::theFinalChoiceHandler(CCObject *sender) {
  int choice = ((CCNode *)sender)->getTag();
  char fileName[FINAL_SCRIPT_PATH_LEN*2] = FINAL_SCRIPT_PATH;
  switch (choice) {
    case fChoice:
      fileName[FINAL_SCRIPT_PATH_LEN]='1';
      break;
    case sChoice:
      fileName[FINAL_SCRIPT_PATH_LEN]='2';
      break;
    case tChoice:
      fileName[FINAL_SCRIPT_PATH_LEN]='3';
      break;
    default:
      break;
  }
  reader.ChangeFile(cocos2d::CCFileUtils::sharedFileUtils()->fullPathForFilename(fileName));
  
  removeChildByTag(2);
  removeChildByTag(3);
  setTouchEnabled(true);
  
  avgGame();
}


void StoryWorld::leafletChoiceHandler(CCObject *sender) {
  int choice = ((CCNode *)sender)->getTag();
  switch (choice) {
    case fChoice: {
      removeChildByTag(2);
      removeChildByTag(3);
      
      CCSprite *blackBG = CCSprite::create(LEAFLET_IMG_PATH);
      blackBG->setPosition(ccp(CCDirector::sharedDirector()->getVisibleSize().width/2, CCDirector::sharedDirector()->getVisibleSize().height/2));
      blackBG->setScale(1);
      blackBG->setTag(21);
      addChild(blackBG, 2);
      
       CCMenuItemImage *start = CCMenuItemImage::create(LEAFLET_CLOSE_IMG_PATH, LEAFLET_CLOSE_IMG_PATH, this, menu_selector(StoryWorld::menuLeafletsCloseCallback));
      
      start->setPosition(ccp(CCDirector::sharedDirector()->getVisibleSize().width-40, CCDirector::sharedDirector()->getVisibleSize().height-40));
      
      
      CCMenu* pMenu = CCMenu::create(start, NULL);
      pMenu->setPosition(CCPointZero);
      pMenu->setTag(23);
      addChild(pMenu, 4);
    }
      return;
    case sChoice:
    default:{
      specialPartSwitchCase('1');
    }
      return;
  }
}


// 
void StoryWorld::gameOverAndBackToWelcome() {
  CCScene *welcome = Welcome::scene();
  CCTransitionCrossFade *backToWelcome = CCTransitionCrossFade::create(0.7, welcome);
  CCDirector::sharedDirector()->replaceScene(backToWelcome);
}


//
void StoryWorld::saveProcessAndPopOut() {
  current+=1;
  CCUserDefault::sharedUserDefault()->setIntegerForKey("Process", current-'0');
  CCUserDefault::sharedUserDefault()->flush();
  CCEGLView::sharedOpenGLView()->setDesignResolutionSize(672, 448, kResolutionExactFit);
  
  CCDirector::sharedDirector()->popScene();
}

//
void StoryWorld::menuLeafletsCloseCallback(CCObject* sender) {
  removeChildByTag(21);
  removeChildByTag(22);
  removeChildByTag(23);
  setTouchEnabled(true);
  //
  specialPartSwitchCase('1');
}

void StoryWorld::confirmButtonHandler(CCObject *sender) {
  saveProcessAndPopOut();
}

//
void StoryWorld::menuCloseCallback(CCObject* pSender) {

}
