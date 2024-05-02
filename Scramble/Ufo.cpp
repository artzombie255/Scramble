#include "Ufo.h"


Ufo::Ufo()
{
	points = 100;
	setSize(sf::Vector2f(48, 48));
	setOrigin(0, 0);
	setPosition((rand() % 5000 + 300), 500);
	start = getPosition().y;
	moveDir = -5;
	image.loadFromFile("./sprites/Ufo.png");
	sprite.setTexture(image);
	sprite.setScale(3, 3);
}

Ufo::Ufo(int x, int y)
{
	points = 100;
	setSize(sf::Vector2f(48, 48));
	setOrigin(0, 0);
	setPosition(x, y);
	start = getPosition().y;
	moveDir = -5;
	image.loadFromFile("./sprites/Ufo.png");
	sprite.setTexture(image);
	sprite.setScale(3, 3);
}


Ufo::~Ufo()
{

}


void Ufo::move(sf::Clock &clock, sf::View viewport)
{
	//if (getPosition().x < 800)
		sf::RectangleShape::move(0, moveDir);

	if (getPosition().y >= start)
		moveDir = -5;
	else if (getPosition().y <= start - 200)
		moveDir = 5;
}


void Ufo::print(sf::RenderWindow& window)
{
	sprite.setPosition(getPosition().x, getPosition().y);
	window.draw(sprite);
}


void Ufo::changeSprite(int palette)
{
}

int Ufo::getPoints()
{
	return 100;
}

