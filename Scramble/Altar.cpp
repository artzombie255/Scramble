#include "Altar.h"


Altar::Altar()
{
	setSize(sf::Vector2f(48, 48));
	setOrigin(0, 0);
	setPosition((rand() % 2000 + 300), 500);
	points = 100 * (rand() % 3 + 1);
	name = "altar.png";
}


Altar::~Altar()
{
}


void Altar::print(sf::RenderWindow& window)
{
	sprite.setPosition(getPosition().x, getPosition().y);
	//window.draw(*this);
	window.draw(sprite);
}


void Altar::changeSprite(int palette)
{
	Enemy::changeSprite(palette);
}

int Altar::getPoints()
{
	srand(time(NULL));

	return (rand() % 3 + 1) * 100;
}
