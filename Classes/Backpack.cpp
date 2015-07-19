#include "Backpack.h"

bool Backpack::addItem(BagItem* item)    
{
    if(sGlobal->bagRecord->addItemToRecord(item->id))
    {
	bagItemList->addObject(item);
	return true;
    }
    return false;
}

bool Backpack::useItem(BagItem* item)
{
    int state=sGlobal->bagRecord->useItemToRecord(item->id,item->consumptive);
    if(state==ITEM_REMOVE)
	bagItemList->removeObject(item);
    return state==ALREADY_EQUIPPED?false:true;
}

std::vector<int> Backpack::getItemNumList()
{
    return sGlobal->bagRecord->itemNumList;
}

std::vector<bool> Backpack::getItemUseList()
{
    return sGlobal->bagRecord->itemUseList;
}
