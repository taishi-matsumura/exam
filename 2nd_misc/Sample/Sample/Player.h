//#ifndef _PLAYER_H_
//#define _PLAYER_H_

#include "Character.h"

class Player : public Character
{
public:
	Player() {}
	~Player() {}

private:
	int m_skillLevel;
};

//#endif
