#ifndef _BAG_H_
#define _BAG_H_
#include <vector>
#include "cocos2d.h"
using namespace cocos2d;
#define BAG_ITEM_MAX 100
#define ITEM_REMOVE 0
#define ITEM_REMAIN 1
#define ALREADY_EQUIPPED 2

class BagRecord
{
public:
   int totalItem;
   std::vector<int> itemIDList;
   std::vector<int> itemNumList;
   std::vector<bool> itemUseList;
public:
   bool addItemToRecord(int id);
   int useItemToRecord(int id);
};
#endif
