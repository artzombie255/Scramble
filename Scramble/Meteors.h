#pragma once
#include "Enemy.h"


class Meteors : public Enemy
{
public:
	Meteors();
	Meteors(sf::View);
	~Meteors();
	void move();
	void print(sf::RenderWindow&);
	void changeSprite(int);

};

