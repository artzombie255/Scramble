#pragma once
#include <iostream>


class Enemy
{
public:
	Enemy();
	~Enemy();
	int getPoints();
protected:
	int points;
	bool destroyable = true;
};

