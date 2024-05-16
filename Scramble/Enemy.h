#pragma once
#include <iostream>
#include "Entity.h"


class Enemy: public Entity
{
public:
	Enemy();
	~Enemy();
	virtual void move(sf::Clock&, sf::View);
	virtual int getPoints();
	virtual int getFuel();
	virtual bool getDestroyable();
	virtual void print(sf::RenderWindow&);
	virtual void changeSprite(int);
	virtual bool isBase();

protected:
	int points;
	bool destroyable = true;
	sf::Sprite sprite;
	sf::Texture image;
	sf::Clock spriteClock;
	std::string name;
};

