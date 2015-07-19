#ifndef _BACKPACK_H_
#define _BACKPACK_H_
#include "cocos2d.h"
#include "BagItem.h"
#include "BagRecord.h"
using namespace cocos2d;

class Backpack
{
public:   
    CCArray* bagItemList;
public:
    void addItem(BagItem* item);
    bool useItem(BagItem* item);
    std::vector<int> getItemNumList();
    std::vector<bool> getItemUseList();
};
#endif
