//
//  PlayReader.cpp
//  血色明远湖
//
//  Created by Ring King on 14-4-5.
//
//

#include "PlayReader.h"

PlayReader::PlayReader() {
  lineNum=0;
  curLine=0;
  //saver = *cocos2d::CCUserDefault::sharedUserDefault();
}

PlayReader::PlayReader(string filePath) {
  ReadFileWithFullPath(filePath);
}

void PlayReader::ReadFileWithFullPath(cocos2d::CCString filePath) {
  unsigned char *buffer;
  unsigned long bufSize;
  buffer = cocos2d::CCFileUtils::sharedFileUtils()->getFileData(filePath.getCString(), "r", &bufSize);
  split((char *)buffer, "\n", &dialogs);
  lineNum = dialogs.size();
  curLine = 0;
}

vector<string> PlayReader::PlayerNames() {
  unsigned char *buffer;
  unsigned long bufSize;
  vector<string> names;
  std::string fullPath = cocos2d::CCFileUtils::sharedFileUtils()->fullPathForFilename("names.txt");
  buffer = cocos2d::CCFileUtils::sharedFileUtils()->getFileData(fullPath.c_str(), "r", &bufSize);
  split((char *)buffer, "\n", &names);
  return names;
}

string PlayReader::GetNextDialog() {
  assert(curLine<=lineNum);
  return dialogs[curLine++];
}

void PlayReader::ChangeFile(cocos2d::CCString filePath) {
  dialogs.clear();
  ReadFileWithFullPath(filePath);
}

void PlayReader::split(const char * str,const char * deli, vector<string> *list) {
  char buff[200000];
  strcpy(buff,str);
  char * gg;
  char *p = strtok_r(buff, deli, &gg);
  
  list->clear();
  while(p !=NULL && gg!=NULL)
  {
    list->push_back(p);
    p = strtok_r(NULL, deli, &gg);
  };
}

int PlayReader::getCurLine() {
  return (int)curLine;
}


ProcessSaver::ProcessSaver() {
  // Read the save
  if (cocos2d::CCUserDefault::sharedUserDefault()->getBoolForKey("FisrtSave", true)) {
    cocos2d::CCUserDefault::sharedUserDefault()->setBoolForKey("FisrtSave", false);
    cocos2d::CCUserDefault::sharedUserDefault()->setIntegerForKey("PositionX", 0);
    cocos2d::CCUserDefault::sharedUserDefault()->setIntegerForKey("PositionY", 0);
    cocos2d::CCUserDefault::sharedUserDefault()->setIntegerForKey("MapProcess", 0);
    cocos2d::CCUserDefault::sharedUserDefault()->setIntegerForKey("Process", '0');
    cocos2d::CCUserDefault::sharedUserDefault()->flush();
  } else {
    _x = cocos2d::CCUserDefault::sharedUserDefault()->getIntegerForKey("PositionX");
    _y = cocos2d::CCUserDefault::sharedUserDefault()->getIntegerForKey("PositionY");
    _mapProcess = cocos2d::CCUserDefault::sharedUserDefault()->getIntegerForKey("MapProcess");
    _process = cocos2d::CCUserDefault::sharedUserDefault()->getIntegerForKey("Process");
  }
}

void ProcessSaver::save(int x, int y, int mapProcess) {
  _x = x; _y = y; _mapProcess = mapProcess;
  cocos2d::CCUserDefault::sharedUserDefault()->setIntegerForKey("PositionX", _x);
  cocos2d::CCUserDefault::sharedUserDefault()->setIntegerForKey("PositionY", _y);
  cocos2d::CCUserDefault::sharedUserDefault()->setIntegerForKey("MapProcess", _mapProcess);
  cocos2d::CCUserDefault::sharedUserDefault()->flush();
}

void ProcessSaver::savePosition(int x, int y) {
  _x = x; _y = y;
  cocos2d::CCUserDefault::sharedUserDefault()->setIntegerForKey("PositionX", _x);
  cocos2d::CCUserDefault::sharedUserDefault()->setIntegerForKey("PositionY", _y);
  cocos2d::CCUserDefault::sharedUserDefault()->flush();
}

void ProcessSaver::saveMapProcess(int mapProcess) {
  _mapProcess = mapProcess;
  cocos2d::CCUserDefault::sharedUserDefault()->setIntegerForKey("MapProcess", _mapProcess);
  cocos2d::CCUserDefault::sharedUserDefault()->flush();
}

void ProcessSaver::saveProcess(int process) {
  _process = process;
  cocos2d::CCUserDefault::sharedUserDefault()->setIntegerForKey("Process", process);
  cocos2d::CCUserDefault::sharedUserDefault()->flush();
}

int ProcessSaver::getPositionX() {
  return _x;
}

int ProcessSaver::getPositionY() {
  return _y;
}

int ProcessSaver::getMapProcess() {
  return _mapProcess;
}

int ProcessSaver::getProcess() {
  return _process;
}
