#include "Meteors.h"


Meteors::Meteors()
{
	setSize(sf::Vector2f(48, 48));
	setOrigin(0, 0);
	setPosition((rand() % 2000 + 300), 500);
	name = "meteor.png";
}


Meteors::~Meteors()
{
}


void Meteors::move()
{
	//unfinished
}

//displays meteors
void Meteors::print(sf::RenderWindow& window)
{
	sprite.setPosition(getPosition().x, getPosition().y);
	//window.draw(*this);
	window.draw(sprite);
}

//useless
void Meteors::changeSprite(int palette)
{
	Enemy::changeSprite(palette);
}
