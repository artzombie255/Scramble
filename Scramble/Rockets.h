#pragma once
#include "Enemy.h"


class Rockets : public Enemy
{
public:
	Rockets();
	Rockets(int x, int y);
	~Rockets();
	void move(sf::Clock &clock, sf::View);
	void takeoff();
	int getPoints();
	void print(sf::RenderWindow&);
	void changeSprite(int);


private:
	bool grounded = true;
	int spriteNum = 0;
};

