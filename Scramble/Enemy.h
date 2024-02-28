#pragma once
#include <iostream>
#include "Entity.h"


class Enemy: public Entity
{
public:
	Enemy();
	~Enemy();
	virtual void move(sf::Clock&);
	virtual int getPoints();
	virtual void print(sf::RenderWindow&);
	virtual void changeSprite(sf::Clock&, sf::Sprite&);

protected:
	int points;
	bool destroyable = true;
};

