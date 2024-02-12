#pragma once
#include "Enemy.h"


class Ufo : public Enemy
{
public:
	Ufo();
	~Ufo();
	void print(sf::RenderWindow&);
};

