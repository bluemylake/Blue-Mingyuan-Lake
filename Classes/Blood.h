#ifndef __BLOOD_H__
#define __BLOOD_H__
#include "cocos2d.h"
#include "cocos-ext.h"
using namespace cocos2d;
USING_NS_CC_EXT; 

class Blood : public CCNode
{
public:
	CREATE_FUNC(Blood);
public:
	virtual bool init();
    void setBloodSlider();
	void setSliderPosition(CCPoint pos);
	void setTotalBlood(float total);
	void setCurrentBlood(float currentHp);
private:
	CCControlSlider* bloodSlider;
};

#endif
