#pragma once
#include "Enemy.h"


class Altar : public Enemy
{
public:
	Altar();
	~Altar();
	void print(sf::RenderWindow&);
	void changeSprite(int);

};

