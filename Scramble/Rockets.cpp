#include "Rockets.h"


Rockets::Rockets()
{
	setSize(sf::Vector2f(30, 50));
	setOrigin(0, 0);
	setPosition(500, 300);
}


Rockets::~Rockets()
{

}


void Rockets::move()
{

}


void Rockets::takeoff()
{

}


int Rockets::getPoints()
{
	if (grounded == true)
		return 50;
	else
		return 80;
}


void Rockets::print(sf::RenderWindow& window)
{
	window.draw(*this);
}
