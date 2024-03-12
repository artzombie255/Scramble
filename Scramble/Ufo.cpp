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


Ufo::~Ufo()
{

}


void Ufo::move(sf::Clock &clock)
{
	sf::RectangleShape::move(-1, 0);
	if (getPosition().x < 800)
		sf::RectangleShape::move(0, moveDir);

	if (getPosition().y >= start)
		moveDir = -5;
	else if (getPosition().y <= start - 200)
		moveDir = 5;
}


void Ufo::print(sf::RenderWindow& window)
{
	sprite.setPosition(getPosition().x, getPosition().y);
	//window.draw(*this);
	window.draw(sprite);
}


void Ufo::changeSprite(int palette)
{
}
