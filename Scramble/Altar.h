#pragma once
#include "Enemy.h"


class Altar : public Enemy
{
public:
	Altar();
	Altar(int, int);
	~Altar();
	void print(sf::RenderWindow&);
	void changeSprite(int);
	int getPoints();

};

