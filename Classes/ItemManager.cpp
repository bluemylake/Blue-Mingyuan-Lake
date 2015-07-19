#include "ItemManager.h"

void ItemManager::load()
{

}

BagItem* ItemManager::findItemById(int id)
{
	for(int i=0;i<(items->count());i++)
	{
	    BagItem* item=(BagItem*)items->objectAtIndex(i);
		if(item->id==id)
			return item;
	}
	return NULL;
}

ItemManager::~ItemManager()
{
    items->release();
}
