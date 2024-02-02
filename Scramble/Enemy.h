#pragma once
#include "Player.h"


class Enemy
{
public:
	int getPoints();
	void hit(Player);
protected:
	int points;
	bool destroyable = true;
};

