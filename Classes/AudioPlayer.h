//
//  AudioPlayer.hpp
//  BlowMyLake
//
//  Created by Ring King on 8/24/15.
//
//

#ifndef AudioPlayer_h
#define AudioPlayer_h

#include <stdio.h>
#include <string>
#include "cocos2d.h"
#include "SimpleAudioEngine.h"

class AudioPlayer {
public:
  AudioPlayer();
  AudioPlayer(std::string filePath);
  static void PlayDayBGM();
  static void PlayNightBGM();
  static void PlayCombatBGM();
  
  static void switchBGM(char* filename);
  static void playEffect(char* filename);
};
#endif /* AudioPlayer_hpp */
