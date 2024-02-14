#include "Rockets.h"


Rockets::Rockets()
{
	setSize(sf::Vector2f(30, 50));
	setOrigin(0, 0);
	setPosition((rand() % 5000 + 300), 500);
}


Rockets::~Rockets()
{

}


void Rockets::move(sf::Clock clock)
{
	sf::RectangleShape::move(-1, 0);
	if (grounded == false)
		sf::RectangleShape::move(0, -2);
	if (clock.getElapsedTime().asSeconds() >= 1 && getPosition().x < 450)
	{
		clock.restart();
		takeoff();
	}
	return;
}


void Rockets::takeoff()
{
	grounded = false;
	return;
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
