#ifndef _BAG_ITEM_H_
#define _BAG_ITEM_H_
#include "cocos2d.h"
#include "Entity.h"
using namespace cocos2d;

class BagItem: public Entity
{
public:
   int ID;
   CCString name;
   CCString description;
   int category;
   int type;
   int effectValue;
   bool consumptive;
};
//Selling should be in later versions
//int sellPrice;
//int buyPrice;
#endif
