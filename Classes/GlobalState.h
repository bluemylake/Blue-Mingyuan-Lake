#ifndef _GLOBAL_STATE_H_
#define _GLOBAL_STATE_H_
#include "cocos2d.h"
#include "AppMacros.h"
#include "Singleton.hpp"
#include "MapState.h"
#include "SuperPower.h"
#include "CombatUnit.h"
#include "BagRecord.h"
using namespace cocos2d;

//Record of the state of the game in the memory
//contains pointer to playerState of Player
//and pointer to bagRecord of Backpack
class GlobalState: public Singleton<GlobalState>
{
public:
    MapState* mapState;
    SuperPower* superPower;
    CombatUnit* playerState;
    BagRecord* bagRecord;
    bool doneList[MAX_DONE_LIST];
public:
    void load();
    void save();
    void newr();
    ~GlobalState();
private:
    void loadMapState();
    void loadSuperPower();
    void loadDoneList();
    void loadPlayerState();
	void saveDoneList();
};
#define sGlobal GlobalState::instance()
#endif
