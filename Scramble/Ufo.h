#pragma once
#include "Enemy.h"


class Ufo : public Enemy
{
public:
	Ufo();
	Ufo(int, int);
	~Ufo();
	void move(sf::Clock&, sf::View);
	void print(sf::RenderWindow&);
	void changeSprite(int);


private:
	int start, moveDir;
};

