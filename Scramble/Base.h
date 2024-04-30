#pragma once
#include "Enemy.h"


class Base : public Enemy
{
public:
	Base();
	~Base();
	void print(sf::RenderWindow&);
	void changeSprite(int);
	int getPoints();

};

