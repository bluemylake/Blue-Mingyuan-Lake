//
//  AudioPlayer.cpp
//  BlowMyLake
//
//  Created by Ring King on 8/24/15.
//
//

#include "AudioPlayer.h"

USING_NS_CC;

void AudioPlayer::PlayDayBGM() {
  switchBGM("audio/day.mp3");
}

void AudioPlayer::PlayNightBGM() {
  switchBGM("audio/night.mp3");
}

void AudioPlayer::PlayCombatBGM() {
  switchBGM("audio/combat.mp3");
}

void AudioPlayer::switchBGM(char* filename) {
  if (CocosDenshion::SimpleAudioEngine::sharedEngine()->isBackgroundMusicPlaying()) {
    CocosDenshion::SimpleAudioEngine::sharedEngine()->stopBackgroundMusic(true);
  }
  CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic(CCFileUtils::sharedFileUtils()->fullPathForFilename(filename).c_str());
  CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic(CCFileUtils::sharedFileUtils()->fullPathForFilename(filename).c_str(), true);
}

void AudioPlayer::playEffect(char* filename) {
  CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadEffect(CCFileUtils::sharedFileUtils()->fullPathForFilename(filename).c_str());
  CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect(CCFileUtils::sharedFileUtils()->fullPathForFilename(filename).c_str());
}