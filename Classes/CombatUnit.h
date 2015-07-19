#ifndef _COMBAT_UNIT_H_
#define _COMBAT_UNIT_H_
#include "cocos2d.h"
using namespace cocos2d;

class CombatUnit
{
public:
   CCString name;
   int Hp;
   int remainHp;
   int level;
   int attack;
   int defence;
   int speAtt;
   int speDef;
   int speed;
   CCArray* abilities;
};
#endif
