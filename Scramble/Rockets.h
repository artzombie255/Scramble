#pragma once
#include "Enemy.h"


class Rockets : public Enemy
{
public:
	Rockets();
	~Rockets();
	void move(sf::Clock &clock);
	void takeoff();
	int getPoints();
	void print(sf::RenderWindow&);
	void changeSprite(int);


private:
	bool grounded = true;
	int spriteNum = 0;
};

