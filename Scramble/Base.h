#pragma once
#include "Enemy.h"


class Base : public Enemy
{
public:
	Base();
	Base(int, int);
	~Base();
	void print(sf::RenderWindow&);
	void changeSprite(int);
	int getPoints();
	bool isBase();

private:
	sf::Clock spriteClock;
	int spriteNum = 0;
};

