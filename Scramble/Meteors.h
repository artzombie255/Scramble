#pragma once
#include "Enemy.h"


class Meteors : public Enemy
{
public:
	Meteors();
	Meteors(sf::View);
	~Meteors();
	void move(sf::Clock&, sf::View);
	void print(sf::RenderWindow&);
	void changeSprite(int);

private:
	int spriteNum = 0;
};

