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
	virtual void changeSprite(int);

protected:
	int points;
	bool destroyable = true;
	sf::Sprite sprite;
	sf::Texture image;
	sf::Clock spriteClock;
	std::string name;
};

