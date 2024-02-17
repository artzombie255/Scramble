#pragma once
#include "Enemy.h"


class Ufo : public Enemy
{
public:
	Ufo();
	~Ufo();
	void move(sf::Clock);
	void print(sf::RenderWindow&);
private:
	int start, moveDir;
};

