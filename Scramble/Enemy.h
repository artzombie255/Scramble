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
	void setDestroyed(bool);
	bool getDestroyed();

protected:
	int points, boomNum = -1;
	bool destroyable = true, destroyed = false;
	sf::Sprite sprite;
	sf::Texture image;
	sf::Clock spriteClock, boomClock;
	std::string name;
};

