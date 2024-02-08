#pragma once
#include <SFML/Graphics.hpp>

class Entity: public sf::RectangleShape
{
public:
	Entity();
	~Entity();
	int getY();
	int getX();
protected:
	int Y, X;
};

