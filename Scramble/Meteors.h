#pragma once
#include "Enemy.h"


class Meteors : public Enemy
{
public:
	Meteors();
	~Meteors();
	void print(sf::RenderWindow&);
};

