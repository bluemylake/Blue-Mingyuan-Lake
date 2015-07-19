#ifndef _ITEM_MANAGER_H_
#define _ITEM_MANAGER_H_
class ItemManager
{
public:
    void load();
    BagItem* findItemById(int id);
    ~ItemManager();
public:
    CCArray* Items;
};
typedef Singleton<ItemManager> sItemManager;
#define iManager sItemManager::instance()
#endif
