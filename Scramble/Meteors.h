#pragma once
#include "Enemy.h"


class Meteors : public Enemy
{
public:
	Meteors();
	~Meteors();
	void move();
	void print(sf::RenderWindow&);
	void changeSprite(sf::Clock&, sf::Sprite&);

};

