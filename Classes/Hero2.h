#ifndef _HERO_H_
#define _HERO_H_


//description of the class here
class Hero: public HumanEntity
{
public:
    CREATE_FUNC(Hero);
	bool init();
public:
	CCPoint move;
	int dir;
};
#endif
