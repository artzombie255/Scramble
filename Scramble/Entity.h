#pragma once
#include <SFML/Graphics.hpp>

class Entity: public sf::RectangleShape
{
public:
	Entity();
	~Entity();
	int getY();
	int getX();
	virtual void changeSprite(sf::Clock&, sf::Sprite&);

protected:
	int Y, X;
	const int TOTAL_BULLETS = 4;
};

