//#ifndef _ENEMY_H_
//#define _ENEMY_H_

#include "Character.h"

class Enemy : public Character
{
public:
	Enemy() {}
	~Enemy() {}

private:
	int m_attackRate;
};

//#endif
