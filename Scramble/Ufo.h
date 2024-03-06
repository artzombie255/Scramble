#pragma once
#include "Enemy.h"


class Ufo : public Enemy
{
public:
	Ufo();
	~Ufo();
	void move(sf::Clock&);
	void print(sf::RenderWindow&);
	void changeSprite(int);


private:
	int start, moveDir;
};

