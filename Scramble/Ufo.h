#pragma once
#include "Enemy.h"


class Ufo : public Enemy
{
public:
	Ufo();
	~Ufo();
	void move(sf::Clock&);
	void print(sf::RenderWindow&);
	void changeSprite(sf::Clock&, sf::Sprite&);


private:
	int start, moveDir;
};

